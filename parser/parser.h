#ifndef PARSER_H
#define PARSER_H

// Return Values
#define SENSOR_DATA_RECEIVED 7
#define SEND_TIME 1
#define SEND_PRESSURE 2
#define CLEARDATA 3

#define PRESSURE_N 7

using namespace std;

#include <regex>
#include <string>

class parser
{
	public:
		parser();
		~parser();
		int parse_string(string input);
		float get_pressure(int i);
		int get_time_row();
		int get_pressure_row();
		
		
	private:
		float p[PRESSURE_N];
		int time_row;
		int pressure_row;
};

#endif
