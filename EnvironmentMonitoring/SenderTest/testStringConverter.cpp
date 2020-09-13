#include <string>
#include <iostream>
#include "pch.h"
#include "../Sender/stringConverter.h"
using namespace std;

TEST(StringConverter, Convert) {
	vector<EnvironmentParameter> v;
	v.push_back(EnvironmentParameter("Temperature", 32.199028, 40, 0, 37, 4));
	v.push_back(EnvironmentParameter("Humidity", 33, 90, 0, 70, 0));
	string expectedOutput = "Temperature{CurrentValue:32.199028,ErrorHighLimit:40.000000,ErrorLowLimit:0.000000,WarningHighLimit:37.000000,WarningLowLimit:4.000000};Humidity{CurrentValue:33.000000,ErrorHighLimit:90.000000,ErrorLowLimit:0.000000,WarningHighLimit:70.000000,WarningLowLimit:0.000000};";

	iConverter* ConverterObj = new(nothrow) stringConverter;

	string output = ConverterObj->convert(v);

	ASSERT_EQ(output, expectedOutput);
}