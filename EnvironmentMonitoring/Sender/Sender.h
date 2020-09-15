#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "iReaderAndParser.h"
#include "iConverter.h"
#include "iDispatcher.h"
#include "errorLogger.h"
#include "environmentParameter.h"
#include "enums.h"

class Sender
{
private:
	iReaderAndParser* iReaderAndParserObj;
	iConverter* iConverterObj;
	iDispatcher* iDispatcherObj;
	errorLogger errorLoggerObj;

	void logCorrespondingError(errorList error) {
		switch (error) {
		case no_data_found: errorLoggerObj.logError("No Data Found", "No Data source was found while trying to read"); break;
		case missing_data: errorLoggerObj.logError("Missing Data", "One or more required parameters are missing while trying to parse"); break;
		default: break;
		}
	}

	vector<EnvironmentParameter> ReadAndParseInfo() 
	{	
		vector<EnvironmentParameter> paramObjects;
		try {
			iReaderAndParserObj->readAndSetFileName();
			paramObjects = iReaderAndParserObj->readAndParse();
		}
		catch (errorList error)
		{
			logCorrespondingError(error);
		}
		return paramObjects;
	}

public:
	Sender(const Sender& ob) : iReaderAndParserObj(ob.iReaderAndParserObj), iConverterObj(ob.iConverterObj), iDispatcherObj(ob.iDispatcherObj), errorLoggerObj(ob.errorLoggerObj) {}
	
	Sender(iReaderAndParser* irp, iConverter* ic, iDispatcher* id) : iReaderAndParserObj(irp), iConverterObj(ic), iDispatcherObj(id) {}
	
	Sender& operator =(const Sender& ob) {
		iReaderAndParserObj = ob.iReaderAndParserObj;
		iConverterObj = ob.iConverterObj;
		iDispatcherObj = ob.iDispatcherObj;
		errorLoggerObj = ob.errorLoggerObj;
		return *this;
	}

	~Sender() {
		delete iReaderAndParserObj;
		delete iConverterObj;
		delete iDispatcherObj;
	}

	void sendInfoToReceiver() {
		std::vector<EnvironmentParameter> paramObjects;
		string result;
		paramObjects = ReadAndParseInfo();
		result = iConverterObj->convert(paramObjects);
		iDispatcherObj->sendData(result);
	}
};