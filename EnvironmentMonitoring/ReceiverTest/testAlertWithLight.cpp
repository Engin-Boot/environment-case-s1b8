
#include<iostream>
#include <string>
#include <sstream>

#include "pch.h"
#include "../Receiver/alertWithLight.h"

using namespace std;

TEST(Alertwithlight, Erroralert) {
	iAlerter* alertWithLightObj = new(nothrow) alertWithLight;
	string paramName = "Temperature";
	float currentValue = 32.00000;
	float errorLowLimit = 0.000000;
	float errorHighLimit = 90.000000;
	std::string expectedMessage = " YELLOW LIGHT \nErrorNotificationWithLight: The current " + paramName + " is " + std::to_string(currentValue) + ", but the sustainable range is " + std::to_string(errorLowLimit) + " - " + std::to_string(errorHighLimit) + "\n";
	stringstream buffer;

	streambuf* prevcoutbuf = cout.rdbuf(buffer.rdbuf());

	alertWithLightObj->errorAlert(paramName, currentValue, errorHighLimit, errorLowLimit);
	string callOutput = buffer.str();

	delete alertWithLightObj;
	cout.rdbuf(prevcoutbuf);

	ASSERT_EQ(expectedMessage, callOutput);

}

TEST(Alertwithlight, Warningalert) {
	iAlerter* alertWithLightObj = new(nothrow) alertWithLight;
	string paramName = "Temperature";
	float currentValue = 32.000000;
	float warningLowLimit = 0.000000;
	float warningHighLimit = 90.000000;
	std::string expectedMessage = " RED LIGHT \nWarningNotificationWithLight: The current " + paramName + " is " + std::to_string(currentValue) + ", but the sustainable range is " + std::to_string(warningLowLimit) + " - " + std::to_string(warningHighLimit) + "\n";
	stringstream buffer;

	streambuf* prevcoutbuf = cout.rdbuf(buffer.rdbuf());

	alertWithLightObj->warningAlert(paramName, currentValue, warningHighLimit, warningLowLimit);
	string callOutput = buffer.str();

	delete alertWithLightObj;
	cout.rdbuf(prevcoutbuf);

	ASSERT_EQ(expectedMessage, callOutput);

}

