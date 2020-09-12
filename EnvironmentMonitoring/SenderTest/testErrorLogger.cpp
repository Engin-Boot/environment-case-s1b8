#include <iostream>
#include <string>

using namespace std;

#include "pch.h"
#include "../Sender/errorLogger.h"

TEST(ErrorLogger, WriteToLogFile) {
	ostringstream ss;
	errorLogger::writeToLogFile(ss, "TestError", "This is for testing the logging functionality");
	string expectedString = "TestError: This is for testing the logging functionality\n";
	ASSERT_EQ(ss.str(), expectedString);
}