#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "iConverter.h"

using namespace std;

class stringConverter : public iConverter
{
public:
	virtual string convert(vector<EnvironmentParameter>& v) override {
		string result;
		for (unsigned i = 0; i < v.size(); i++) {
			result += v[i].toString() + ";";
		}
		return result;
	}
};