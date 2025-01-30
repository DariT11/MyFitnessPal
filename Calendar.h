#pragma once
#include<string>
#include <ctime>

/*string getTime()
{
	time_t t = time(0);
	//struct tm* now = localtime(&t);

	char buffer[80];
	//strftime(buffer, sizeof(buffer), "%Y-%m-%d", now);
	return string(buffer);
}*/

bool isItNewDay()
{
	return true;
}
