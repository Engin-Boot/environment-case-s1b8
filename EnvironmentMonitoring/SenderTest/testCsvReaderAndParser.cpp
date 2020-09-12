#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include "pch.h"
#include "../Sender/csvReaderAndParser.h"

using namespace std;

string createAndSetDummyConfig(iReaderAndParser* iReaderAndParserObj) {
	string dummyConfigFileName = "SenderDummy.config";
	string dummySourceFileName = "dummy_data.csv";
	iReaderAndParserObj->setConfigFileName(dummyConfigFileName);

	fstream file;
	file.open(dummyConfigFileName, ios::out);
	if (file) {
		file << dummySourceFileName << "\n";
		file.close();
	}
	return dummySourceFileName;
}

void fillSourceWithTempData(string fileName) {
	fstream file;
	file.open(fileName, ios::out);
	if (file) {
		file << "S.No,Temperature,TemperatureErrorHighLimit,TemperatureErrorLowLimit,TemperatureWarningHighLimit,TemperatureWarningLowLimit,Humidity(%),HumidityErrorHighLimit,HumiditiyErrorLowLimit,HumidityWarningHighLimit,HumidityWarningLowLimit\n";
		file << "1,16.743954450909143,40,0,37,4,62,90,0,70,0\n";
		file.close();
	}
}

vector<EnvironmentParameter> generateExpectedVector() {
	vector<EnvironmentParameter> v;
	v.push_back(EnvironmentParameter("Temperature", 16.743954450909143, 40, 0, 37, 4));
	v.push_back(EnvironmentParameter("Humidity", 62, 90, 0, 70, 0));
	return v;
}

TEST(CsvReaderAndParser, ReadAndSetFileName) {
	iReaderAndParser* iReaderAndParserObj = new(nothrow) csvReaderAndParser;

	string dummySourceFileName = createAndSetDummyConfig(iReaderAndParserObj);

	iReaderAndParserObj->readAndSetFileName();

	string outputDataSourceFileName = iReaderAndParserObj->getDataSourceFileName();

	delete iReaderAndParserObj;

	ASSERT_EQ(outputDataSourceFileName, dummySourceFileName);
}

TEST(CsvReaderAndParser, ReadAndParse) {
	vector <EnvironmentParameter> outputVector, expectedVector;
	iReaderAndParser* iReaderAndParserObj = new(nothrow) csvReaderAndParser;
	string dummySourceFileName = createAndSetDummyConfig(iReaderAndParserObj);
	iReaderAndParserObj->readAndSetFileName();

	fillSourceWithTempData(dummySourceFileName);
	
	outputVector = iReaderAndParserObj->readAndParse();

	expectedVector = generateExpectedVector();

	ASSERT_EQ(2, expectedVector.size());
	ASSERT_TRUE(outputVector[0].isEqual(expectedVector[0]));
	ASSERT_TRUE(outputVector[1].isEqual(expectedVector[1]));
	ASSERT_FALSE(outputVector[0].isEqual(expectedVector[1]));
}
