#ifndef IREADERANDPARSER_H
#define IREADERANDPARSER_H

#include <vector>
#include "environmentParameter.h"

class iReaderAndParser
{
public:
	virtual void readAndSetFileName() = 0;
	virtual void setConfigFileName(const std::string&) = 0;
	virtual std::string getDataSourceFileName() = 0;
	virtual std::vector<EnvironmentParameter> readAndParse() = 0;
};

#endif // !IREADERANDPARSER_H