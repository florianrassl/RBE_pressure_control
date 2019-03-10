#include <iostream>
#include "parser.h"

using namespace std;

int main()
{	
	for(int i=0; i<PRESSURE_N; i++) {
		p[i]=0.0;
	}

	string input;
	while(true) {
		cin>>input;
		if(!cin) break;
		if(input=="q") break;
                parse_string(input); 		
	}

       	for(int i=0; i<PRESSURE_N; i++) {
 		cout << p[i] << endl;
	}	
}



