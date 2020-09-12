#pragma once

#ifndef IDISPATCHER_H
#define IDISPATCHER_H

#include <iostream>

class iDispatcher
{
public:
	virtual void sendData(std::string) = 0;
};

#endif // !IDISPATCHER_H