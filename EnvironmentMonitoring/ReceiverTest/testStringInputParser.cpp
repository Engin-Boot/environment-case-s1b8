
#include "pch.h"
#include<iostream>
#include<vector>
#include "../Receiver/stringInputParser.h"


TEST(StringInputParser,ParseInputMessage) {
	std::string message = "Temperature{CurrentValue:32.199028,ErrorHighLimit:40.000000,ErrorLowLimit:0.000000,WarningHighLimit:37.000000,WarningLowLimit:4.000000};Humidity{CurrentValue:33.000000,ErrorHighLimit:90.000000,ErrorLowLimit:0.000000,WarningHighLimit:70.000000,WarningLowLimit:0.000000}";
	stringInputParser stringInputParserObj;
	vector<EnvironmentParameter> output= stringInputParserObj.parseInputMessage(message);
	vector<EnvironmentParameter> expectedOutput;
	EnvironmentParameter environmentParameterObj1("Temperature", 32.199028, 40.000000, 0.0000000, 37.000000, 4.000000);
	EnvironmentParameter environmentParameterObj2("Humidity", 33.000000, 90.000000,0.000000, 70.000000, 0.000000);
	expectedOutput.push_back(environmentParameterObj1);
	expectedOutput.push_back(environmentParameterObj2);
	
	ASSERT_TRUE(output[0].isEqual(expectedOutput[0]));
	ASSERT_TRUE(output[1].isEqual(expectedOutput[1]));
	
	

}