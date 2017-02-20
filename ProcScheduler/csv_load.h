#pragma once
#include <string>
#include <vector>
using namespace std;
class csv_load
{
public:
	csv_load(string filename);
	~csv_load();
	vector<string> csv_get_pid();
	vector<int> csv_get_tstart();
	vector<int> csv_get_tend();
	///0-2 elements containing ID,Start,CyclesToFinish
	vector<int> csv_getNextOp();
};

