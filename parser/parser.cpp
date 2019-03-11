#include "parser.h"
#include <regex>
#include <string>

//#define DEBUG

#ifdef DEBUG
#include <iostream>
#endif

/* NMEA-Strings:

Pressure information send every second, float 1 decimal place
negativ values are possible and indicate a detected leakage
"LABEL,Date,Time,P0,P1,P2,P3,P4,P5,P6"
"LABEL,Date,Time,10.2,10.3,10.4,10.5,10.6,10.7,10.8"

Request to clear all data
"CLEARDATA"

Request to send time, d row number
"CELL,GET,FROMSHEET,Settings,A,%d"

Request to send pressure, d row number
"CELL,GET,FROMSHEET,Settings,B,%d"
   
example spreadsheet layout:
   d    A	  B
   0
   1		   
   2    0	10000
   3    30	15000
   4	60      20000
   5	90      25000
   6    120	 -1	

d is always starting with 2, the controller always requests
"CELL,GET,FROMSHEET,Settings,A,%d+1"
"CELL,GET,FROMSHEET,Settings,B,%d"
this is necessary to know when it is time to move to the next point 
in the pressure curve

Above example: The controller requests A3 and B2, when 30 seconds since 
measurement start are gone it will iterare by 1 to A4 und B3 and so on.

empty cells have a -1 as return value, as soon as the controller gets a negativ value back
it will end the measurement programm (set pressure regulator to 0 and open all
pressure releasing vents).

*/

using namespace std;

string delimiter = ",";

regex sensordata("LABEL,Date,Time,-?[[:digit:]]+.[[:digit:]],-?[[:digit:]]+.[[:digit:]],-?[[:digit:]]+.[[:digit:]],-?[[:digit:]]+.[[:digit:]],-?[[:digit:]]+.[[:digit:]],-?[[:digit:]]+.[[:digit:]],-?[[:digit:]]+.[[:digit:]]");

regex cleardata("CLEARDATA");
regex req_time("CELL,GET,FROMSHEET,Settings,A,[[:digit:]]+");
regex req_pressure("CELL,GET,FROMSHEET,Settings,B,[[:digit:]]+");

parser::parser()
{
	for(int i=0; i<PRESSURE_N; i++) {
 		p[i] = 0.0;
	}
	time_row = 0.0;
	pressure_row = 0.0;
}

parser::~parser()
{
  
}

int parser::parse_string(string input)
{
  if(regex_match(input,sensordata)) {
		string token;
		size_t pos = 0;
		int i=0;
		while ((pos = input.find(delimiter)) != string::npos) {
			token = input.substr(0, pos);
			try {
				p[i] = stof(token);
#ifdef DEBUG
				cout << p[i] << endl;
#endif
				i++;
				if(i>PRESSURE_N-1) return 0;
			}
			catch (...) {
			}
			input.erase(0, pos + delimiter.length());
		}
		try {
			p[i] = stof(input);
#ifdef DEBUG
			cout << p[i] << endl;
#endif
		}
		catch (...) {
			return 0;
		}
                if(i==PRESSURE_N-1) {
			return SENSOR_DATA_RECEIVED;
		}
	}
	else if(regex_match(input,cleardata)) {
		// clear data
		return CLEARDATA;
#ifdef DEBUG
		cout << "Clear Data!" << endl;
#endif
	}
	else if(regex_match(input,req_time)) {
		string token;
		size_t pos = 0;
		while ((pos = input.find(delimiter)) != string::npos) {
			input.erase(0, pos + delimiter.length());
		}
		try {
			time_row = stoi(input);
#ifdef DEBUG
			cout << "Send time row ";
			cout << time_row << endl;
#endif
			return SEND_TIME;
		}
		catch (...) {
			return 0;
		}
	}
	else if(regex_match(input,req_pressure)) {
		string token;
		size_t pos = 0;
		while ((pos = input.find(delimiter)) != string::npos) {
			input.erase(0, pos + delimiter.length());
		}
		try {
			pressure_row = stoi(input);
#ifdef DEBUG
			cout << "Send pressure row ";
			cout << pressure_row << endl;
#endif
			return SEND_PRESSURE;
		}
		catch (...) {
			return 0;
		}
	}
	else {
		//Invalid expression
#ifdef DEBUG
		cout << "Invalid expression!" << endl;
#endif
		return 0;
	}
	return 0;
}

int parser::get_time_row()
{
	return time_row;
}

int parser::get_pressure_row()
{
	return pressure_row;
}

float parser::get_pressure(int i)
{
	if(i<PRESSURE_N) return p[i];
	else return 0;
}

