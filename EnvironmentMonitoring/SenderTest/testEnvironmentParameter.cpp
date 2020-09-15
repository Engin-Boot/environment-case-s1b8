#include <iostream>
#include <string>
#include "pch.h"
#include "../Sender/environmentParameter.h"


TEST(EnvironmentParameters, ToString) {
	EnvironmentParameter EnvironmentParameterObj("Temperature", 16.5, 40, 0, 37, 4);

	std::string expectedString = "Temperature{CurrentValue:16.500000,ErrorHighLimit:40.000000,ErrorLowLimit:0.000000,WarningHighLimit:37.000000,WarningLowLimit:4.000000}";

	ASSERT_EQ(expectedString, EnvironmentParameterObj.toString());
}

TEST(EnvironmentParameters, IsEqual) {
	EnvironmentParameter EnvironmentParameterObj1("Temperature", 16.5, 40, 0, 37, 4);
	EnvironmentParameter EnvironmentParameterObj2("Temperature", 16.5, 40, 0, 37, 4);
	EnvironmentParameter EnvironmentParameterObj3("Temperature", 16.5, 40, 0, 47, 4);

	ASSERT_TRUE(EnvironmentParameterObj1.isEqual(EnvironmentParameterObj2));
	ASSERT_FALSE(EnvironmentParameterObj1.isEqual(EnvironmentParameterObj3));
}