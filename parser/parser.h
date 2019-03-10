#ifndef PARSER_H
#define PARSER_H

#define SENSOR_DATA_SAVED 7
#define TIME_SEND 1
#define PRESSURE_SEND 2

#define PRESSURE_N 7

using namespace std;

#include <regex>
#include <string>

extern float p[PRESSURE_N];
extern int time_row;
extern int pressure_row;

int parse_string(string input);

#endif
