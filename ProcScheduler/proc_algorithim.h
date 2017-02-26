#pragma once
#include "csv_load.h"
#include <sstream>
#include <iostream>
#include <iomanip>
class proc_algorithim{
	private:
		static const int IOWIDTH = 4;
	public:
		static ostringstream* HRRN(csv_load a);
		static ostringstream * roundRobin(csv_load a, unsigned int quanta);
		//Highest response ratio next
		static ostringstream* feedback(csv_load a);
		static ostringstream* shortestProcNext(csv_load a);
};

