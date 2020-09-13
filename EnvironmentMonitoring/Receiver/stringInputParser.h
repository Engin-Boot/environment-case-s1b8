#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "environmentParameter.h"
#include "iInputParser.h"

using namespace std;

class stringInputParser: public iInputParser 
{
private:
	string parseAttribute(string attribute) {
		// CurrentValue:32.199028

		string value;
		stringstream s(attribute);
		while (getline(s, value, ':')) {}
		return value;
	}

	vector<float> parseContents(string contents) {
		// CurrentValue:32.199028,ErrorHighLimit:40.000000,ErrorLowLimit:0.000000,WarningHighLimit:37.000000,WarningLowLimit:4.000000

		vector<string> attributes;
		vector<float> values;
		string attribute;
		stringstream s(contents);
		while (getline(s, attribute, ',')) {
			attributes.push_back(attribute);
		}

		for (int i = 0; i < attributes.size(); i++) {
			values.push_back(stof(parseAttribute(attributes[i])));
		}
		return values;
	}

	EnvironmentParameter parseParam(string param) {
		// Temperature{CurrentValue:32.199028,ErrorHighLimit:40.000000,ErrorLowLimit:0.000000,WarningHighLimit:37.000000,WarningLowLimit:4.000000}

		string paramName;
		string contents;
		int i;
		for (i = 0; param[i] != '{'; i++) {
			paramName += param[i];
		}

		contents = param.substr(i+1, param.length()-i-2);
		vector<float> attributeValues = parseContents(contents);
		return EnvironmentParameter(paramName, attributeValues[0], attributeValues[1], attributeValues[2], attributeValues[3], attributeValues[4]);
	}

public:

	vector<EnvironmentParameter> parseInputMessage(string message) override
	{
		vector<EnvironmentParameter> v;
		// string message = "Temperature{CurrentValue:32.199028,ErrorHighLimit:40.000000,ErrorLowLimit:0.000000,WarningHighLimit:37.000000,WarningLowLimit:4.000000};Humidity{CurrentValue:33.000000,ErrorHighLimit:90.000000,ErrorLowLimit:0.000000,WarningHighLimit:70.000000,WarningLowLimit:0.000000}";
		
		vector<string> inputParams;
		string param;
		stringstream s(message);
		while (getline(s, param, ';')) {
			inputParams.push_back(param);
		}
		
		for (int i = 0; i < inputParams.size(); i++) {
			v.push_back(parseParam(inputParams[i]));
		}

		for (int i = 0; i < inputParams.size(); i++) {
			cout << v[i].toString() << endl;
		}

		return v;
	}
};