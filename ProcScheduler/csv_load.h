#pragma once
#include <string>
#include <vector>
using namespace std;
class csv_load{
	public:
		csv_load(string filename);
		~csv_load();
		struct proc {
			int t_start;
			int t_run;
			string pid;
		};
		vector<string> csv_get_pid();
		vector<int> csv_get_tstart();
		vector<int> csv_get_trun();
		///list of proc types
		vector<proc> csv_getProcList();


};

