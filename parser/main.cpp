#include <iostream>
#include "parser.h"

using namespace std;

int main()
{	
	parser sp1;

	string input;
	while(true) {
		cin>>input;
		if(!cin) break;
		if(input=="q") break;
                int return_value = sp1.parse_string(input);
		switch(return_value) {
			case SEND_TIME: {
						cout << "SEND_TIME RECEIVED" << endl;
						// TODO: send value of sp1.get_time_row() to controller;
					}
				break;
			case SEND_PRESSURE: {
						cout << "SEND_PRESSURE RECEIVED" << endl;
						// TODO: send value of sp1.get_pressure_row() to controller;
					    }
				break;
			case CLEARDATA: {
						 cout << "CLEARDATA RECEIVED" << endl;
						// TODO: clear all data, new measurement startet
					}
				break;
			case SENSOR_DATA_RECEIVED: {
						cout << "SENSOR_DATA_RECEIVED" << endl;
						for(int i=0; i<PRESSURE_N; i++) {
 							// TODO: save values of sp1.get_pressure(i); 
							// to File or Database
						}
					}
				break;
			default:
				break;
		} 		
	}
}



