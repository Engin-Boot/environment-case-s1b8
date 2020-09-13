#include "stringInputParser.h"

int main()
{
	string message = "Temperature{CurrentValue:32.199028,ErrorHighLimit:40.000000,ErrorLowLimit:0.000000,WarningHighLimit:37.000000,WarningLowLimit:4.000000};Humidity{CurrentValue:33.000000,ErrorHighLimit:90.000000,ErrorLowLimit:0.000000,WarningHighLimit:70.000000,WarningLowLimit:0.000000};";
	stringInputParser stringInputParserObj;
	stringInputParserObj.parseInputMessage(message);
}