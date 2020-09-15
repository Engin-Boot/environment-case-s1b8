#pragma once

#ifndef CSVREADERANDPARSER_H
#define CSVREADERANDPARSER_H

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>

#include "iReaderAndParser.h"
#include "enums.h"

using namespace std;

class csvReaderAndParser : public iReaderAndParser
{
private:
	string configFileName = "Sender.config";
	string dataSourceFileName;

	vector<string> parseCsVLine(stringstream& s) {
		string word;
		vector<string> row;
		while (getline(s, word, ',')) {
			row.push_back(word);
		}
		return row;
	}

	vector<EnvironmentParameter> checkAndPopulateVector(vector<string>& row) {
		vector<EnvironmentParameter> v;
		if (row.size() == 11) {
			// temperature
			v.push_back(EnvironmentParameter("Temperature", stof(row[1]), stof(row[2]), stof(row[3]), stof(row[4]), stof(row[5])));

			// humidity
			v.push_back(EnvironmentParameter("Humidity", stof(row[6]), stof(row[7]), stof(row[8]), stof(row[9]), stof(row[10])));
		}
		else {
			throw missing_data;
		}
		return v;
	}
	int coutNoOflines(const string& fileName) {
		fstream file;
		file.open(fileName, ios::in);
		int i = 0;
		string content;
		if (file)
		{
			while (getline(file, content)) {
				i++;
			}
		}
		return i-1;
	}

public:
	void readAndSetFileName() override
	{
		string text;
		fstream file;
		file.open(configFileName, ios::in);
		if (file) {
			getline(file, text);
			dataSourceFileName = text;
		}
	}

	string getDataSourceFileName() override
	{
		return dataSourceFileName;
	}

	void setConfigFileName(const string& newConfigFileName) override
	{
		configFileName = newConfigFileName;
	}
	vector<EnvironmentParameter> readAndParse() override
	{
		vector<EnvironmentParameter> v;
		fstream file;
		string text;
		vector<string> row;
		srand((unsigned int)time(NULL));
		int totalNoOfLines = coutNoOflines(dataSourceFileName);
		int lineNumber = (rand() % totalNoOfLines);

		file.open(dataSourceFileName, ios::in);
		if (file)
		{
			int i = 0;
			getline(file, text); // headers
			while (i<=lineNumber) {
				getline(file, text);
				row.clear();

				stringstream s(text);

				row = parseCsVLine(s);
				i++;
			}
			v = checkAndPopulateVector(row);
		}
		else {
			throw no_data_found;
		}
		return v;
	}
};

#endif // !CSVREADERANDPARSER_H