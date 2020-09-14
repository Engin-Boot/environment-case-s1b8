
#include<iostream>
#include<string>
#include<sstream>
#include "pch.h"
#include"../Receiver/rangeChecker.h"


class DummyAlert : public iAlerter {
	void errorAlert(const string& paramName, float cv, float high, float low) override
	{
		cout << "This is dummy error alert with input parameters, " + paramName + " "+ to_string(cv) + " , "  + to_string(high) + " , " + to_string(low) << endl;
			
	}
	void warningAlert(const string& paramName, float cv, float high, float low) override
	{
		cout << "This is dummy warning alert with input parameters, " + paramName +" "+ to_string(cv) + " , " + to_string(high) + " , " + to_string(low) << endl;

	}

};
string checkVector(vector<EnvironmentParameter>params)
{
	iAlerter* alertObj = new(nothrow) DummyAlert;
	rangeChecker rangeCheckerObj(alertObj);
	
	stringstream buffer;
	streambuf* prevcoutbuf = cout.rdbuf(buffer.rdbuf());
	rangeCheckerObj.checkForAlert(params);
	string callOutput = buffer.str();
	cout.rdbuf(prevcoutbuf);
	return callOutput;
}
TEST(rangechecker, checkForTempErrorHighAlert) {
	vector <EnvironmentParameter>params;
	EnvironmentParameter paramsObj1("Temperature", 42, 40, 0, 37, 4);
	EnvironmentParameter paramsObj2("Humidity", 40, 90, 0, 70, 0);
	params.push_back(paramsObj1);
	params.push_back(paramsObj2);
	string expectedMessage = "This is dummy error alert with input parameters, Temperature " + to_string(42.000000) + " , " + to_string(40.000000) + " , " + to_string(0.000000) + "\n";
	string callOutput = checkVector(params);

	ASSERT_EQ(expectedMessage, callOutput);

}
TEST(rangechecker, checkForTempErrorLowAlert) {
	vector <EnvironmentParameter>params;
	EnvironmentParameter paramsObj1("Temperature", -1, 40, 0, 37, 4);
	EnvironmentParameter paramsObj2("Humidity", 40, 90, 0, 70, 0);
	params.push_back(paramsObj1);
	params.push_back(paramsObj2);
	string expectedMessage = "This is dummy error alert with input parameters, Temperature " + to_string(-1.000000) + " , " + to_string(40.000000) + " , " + to_string(0.000000) + "\n";
	string callOutput = checkVector(params);

	ASSERT_EQ(expectedMessage, callOutput);

}

TEST(rangechecker, checkForTempWarningHighAlert) {
	vector <EnvironmentParameter>params;
	EnvironmentParameter paramsObj1("Temperature", 38, 40, 0, 37, 4);
	EnvironmentParameter paramsObj2("Humidity", 40, 90, 0, 70, 0);
	params.push_back(paramsObj1);
	params.push_back(paramsObj2);
	
	string expectedMessage = "This is dummy warning alert with input parameters, Temperature " + to_string(38.000000) + " , " + to_string(37.000000) + " , " + to_string(4.000000) + "\n";
	string callOutput = checkVector(params);

	ASSERT_EQ(expectedMessage, callOutput);

}
TEST(rangechecker, checkForTempWarningLowAlert) {
	vector <EnvironmentParameter>params;
	EnvironmentParameter paramsObj1("Temperature", 2, 40, 0, 37, 4);
	EnvironmentParameter paramsObj2("Humidity", 40, 90, 0, 70, 0);
	params.push_back(paramsObj1);
	params.push_back(paramsObj2);
	string expectedMessage = "This is dummy warning alert with input parameters, Temperature " + to_string(2.000000) + " , " + to_string(37.000000) + " , " + to_string(4.000000) + "\n";
	string callOutput = checkVector(params);

	ASSERT_EQ(expectedMessage, callOutput);

}
TEST(rangechecker, checkForhumidityErrorHighAlert) {
	vector <EnvironmentParameter>params;
	EnvironmentParameter paramsObj1("Temperature", 32, 40, 0, 37, 4);
	EnvironmentParameter paramsObj2("Humidity", 95, 90, 0, 70, 0);
	params.push_back(paramsObj1);
	params.push_back(paramsObj2);
	string expectedMessage = "This is dummy error alert with input parameters, Humidity " + to_string(95.000000) + " , " + to_string(90.000000) + " , " + to_string(0.000000) + "\n";
	string callOutput = checkVector(params);

	ASSERT_EQ(expectedMessage, callOutput);

}

TEST(rangechecker, checkForhumidityWarningHighAlert) {
	vector <EnvironmentParameter>params;
	EnvironmentParameter paramsObj1("Temperature", 32, 40, 0, 37, 4);
	EnvironmentParameter paramsObj2("Humidity", 75, 90,0,70,0);
	params.push_back(paramsObj1);
	params.push_back(paramsObj2);
	string expectedMessage = "This is dummy warning alert with input parameters, Humidity " + to_string(75.000000) + " , " + to_string(70.000000) + " , " + to_string(0.000000) + "\n";
	string callOutput = checkVector(params);

	ASSERT_EQ(expectedMessage, callOutput);

}
TEST(rangechecker, checkForboth1Alert) {
	//temp error high, humidity warning high
	vector <EnvironmentParameter>params;
	EnvironmentParameter paramsObj1("Temperature", 42, 40, 0, 37, 4);
	EnvironmentParameter paramsObj2("Humidity", 75, 90, 0, 70, 0);
	params.push_back(paramsObj1);
	params.push_back(paramsObj2);
	string expectedMessage = "This is dummy error alert with input parameters, Temperature " + to_string(42.000000) + " , " + to_string(40.000000) + " , " + to_string(0.000000) + "\n" + "This is dummy warning alert with input parameters, Humidity " + to_string(75.000000) + " , " + to_string(70.000000) + " , " + to_string(0.000000) + "\n";
	
	string callOutput = checkVector(params);

	ASSERT_EQ(expectedMessage, callOutput);

}
TEST(rangechecker, checkForboth2Alert) {
	//temp error low, humidity warning high
	vector <EnvironmentParameter>params;
	EnvironmentParameter paramsObj1("Temperature", -1, 40, 0, 37, 4);
	EnvironmentParameter paramsObj2("Humidity", 75, 90, 0, 70, 0);
	params.push_back(paramsObj1);
	params.push_back(paramsObj2);
	string expectedMessage = "This is dummy error alert with input parameters, Temperature " + to_string(-1.000000) + " , " + to_string(40.000000) + " , " + to_string(0.000000) + "\n" + "This is dummy warning alert with input parameters, Humidity " + to_string(75.000000) + " , " + to_string(70.000000) + " , " + to_string(0.000000) + "\n";
	string callOutput = checkVector(params);

	ASSERT_EQ(expectedMessage, callOutput);

}
TEST(rangechecker, checkForboth3Alert) {
	//temp warning low, humidity error high
	vector <EnvironmentParameter>params;
	EnvironmentParameter paramsObj1("Temperature", 3, 40, 0, 37, 4);
	EnvironmentParameter paramsObj2("Humidity", 95, 90, 0, 70, 0);
	params.push_back(paramsObj1);
	params.push_back(paramsObj2);
	string expectedMessage = "This is dummy warning alert with input parameters, Temperature " + to_string(3.000000) + " , " + to_string(37.000000) + " , " + to_string(4.000000) + "\n" + "This is dummy error alert with input parameters, Humidity " + to_string(95.000000) + " , " + to_string(90.000000) + " , " + to_string(0.000000) + "\n";
	string callOutput = checkVector(params);

	ASSERT_EQ(expectedMessage, callOutput);

}
TEST(rangechecker, checkForboth4Alert) {
	//temp warning high, humidity error high
	vector <EnvironmentParameter>params;
	EnvironmentParameter paramsObj1("Temperature", 39, 40, 0, 37, 4);
	EnvironmentParameter paramsObj2("Humidity", 75, 90, 0, 70, 0);
	params.push_back(paramsObj1);
	params.push_back(paramsObj2);
	string expectedMessage = "This is dummy warning alert with input parameters, Temperature " + to_string(39.000000) + " , " + to_string(37.000000) + " , " + to_string(4.000000) + "\n" + "This is dummy warning alert with input parameters, Humidity " + to_string(75.000000) + " , " + to_string(70.000000) + " , " + to_string(0.000000) + "\n";
	string callOutput = checkVector(params);

	ASSERT_EQ(expectedMessage, callOutput);

}

