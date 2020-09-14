#pragma once

#ifndef ENVIRONMENTPARAMETER_H
#define ENVIRONMENTPARAMETER_H

#include <string>
class EnvironmentParameter
{
private:
	std::string parameterName;
	float warningHighLimit;
	float warningLowLimit;
	float errorHighLimit;
	float errorLowLimit;
	float currentValue;

	bool isCurrentValueEqual(float cv1, float cv2) {
		if (cv1 == cv2) {
			return true;
		}
		return false;
	}

	bool isErrorRangeEqual(float ehl1, float ell1, float ehl2, float ell2) {
		if (ehl1 == ehl2 && ell1 == ell2) {
			return true;
		}
		return false;
	}

	bool isWarningRangeEqual(float whl1, float wll1, float whl2, float wll2) {
		if (whl1 == whl2 && wll1 == wll2) {
			return true;
		}
		return false;
	}



public:
	EnvironmentParameter(const std::string& name, float value, float ehl, float ell, float whl, float wll) : parameterName(name), currentValue(value), errorHighLimit(ehl), errorLowLimit(ell), warningHighLimit(whl), warningLowLimit(wll) {}

	std::string getParameterName() {
		return this->parameterName;
	}

	float getWarningHighLimit() {
		return this->warningHighLimit;
	}

	float getWarningLowLimit() {
		return this->warningLowLimit;
	}

	float getErrorHighLimit() {
		return this->errorHighLimit;
	}

	float getErrorLowLimit() {
		return this->errorLowLimit;
	}

	float getCurrentValue() {
		return this->currentValue;
	}

	std::string toString() {
		std::string res = parameterName + "{CurrentValue:" + std::to_string(this->currentValue) + ",ErrorHighLimit:" + std::to_string(this->errorHighLimit) + ",ErrorLowLimit:" + std::to_string(this->errorLowLimit) + ",WarningHighLimit:" + std::to_string(this->warningHighLimit) + ",WarningLowLimit:" + std::to_string(this->warningLowLimit) + "}";
		return res;
	}

	bool isEqual(EnvironmentParameter& obj) {
		return isCurrentValueEqual(this->currentValue, obj.getCurrentValue()) && isWarningRangeEqual(this->warningHighLimit, this->warningLowLimit, obj.getWarningHighLimit(), obj.getWarningLowLimit()) && isErrorRangeEqual(this->errorHighLimit, this->errorLowLimit, obj.getErrorHighLimit(), obj.getErrorLowLimit());
	}
};

#endif // !ENVIRONMENTPARAMETER_H