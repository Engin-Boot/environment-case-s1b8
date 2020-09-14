#pragma once

#ifndef ERRORLOGGER_H
#define ERRORLOGGER_H

#include <iostream>
#include <fstream>
#include <ostream>

using namespace std;

class errorLogger
{
public:
	static void writeToLogFile(ostream& ofs, const string& errorType, const string& message) {
		ofs << errorType << ": " << message << "\n";
	}

	static void logError(const string& errorType, const string& message) {
		fstream logger("mylog.log", ios::out | ios::app);
		if (logger) {
			writeToLogFile(logger, errorType, message);
			logger.close();
		}
	}
};

#endif // !ERRORLOGGER_H