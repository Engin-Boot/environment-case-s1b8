
#include<iostream>
#include <string>
#include <sstream>

#include "pch.h"
#include "../Receiver/alertWithNotification.h"

using namespace std;

TEST(Alertwithnotification, Erroralert) {
	iAlerter* alertWithNotificationObj = new(nothrow) alertWithNotification;
	string paramName = "Temperature";
	float currentValue = 32.00000;
	float errorLowLimit = 0.000000;
	float errorHighLimit = 90.000000;
	std::string expectedMessage = "ErrorNotification: The current " + paramName + " is "+ std::to_string(currentValue) + ", but the sustainable range is " + std::to_string(errorLowLimit) + " - " + std::to_string(errorHighLimit) + "\n";
	stringstream buffer;

	streambuf* prevcoutbuf = cout.rdbuf(buffer.rdbuf()); 

	alertWithNotificationObj->errorAlert(paramName,currentValue,errorHighLimit,errorLowLimit);
	string callOutput = buffer.str();

	delete alertWithNotificationObj;
	cout.rdbuf(prevcoutbuf);

	ASSERT_EQ(expectedMessage, callOutput);
	
}

TEST(Alertwithnotification, Warningalert) {
	iAlerter* alertWithNotificationObj = new(nothrow) alertWithNotification;
	string paramName = "Temperature";
	float currentValue = 32.000000;
	float warningLowLimit = 0.000000;
	float warningHighLimit = 90.000000;
	std::string expectedMessage = "WarningNotification: The current " + paramName + " is "+ std::to_string(currentValue) + ", but the sustainable range is " + std::to_string(warningLowLimit) + " - " + std::to_string(warningHighLimit) + "\n";
	stringstream buffer;

	streambuf* prevcoutbuf = cout.rdbuf(buffer.rdbuf());

	alertWithNotificationObj->warningAlert(paramName, currentValue, warningHighLimit, warningLowLimit);
	string callOutput = buffer.str();

	delete alertWithNotificationObj;
	cout.rdbuf(prevcoutbuf);

	ASSERT_EQ(expectedMessage, callOutput);

}

