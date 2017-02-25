#include "csv_load.h"
#include <fstream>
#include <cctype>
#include <iostream>
//csv_load::csv_load()
//{
//}
vector<string> pid;
vector<int> t_start, t_end;
vector<csv_load::proc> procList;
ifstream *file;
int index;
using namespace std;
//vector <int> strVecToInt(vector<string> &strVec ) {
//	vector<int> intVec;
//	for (int i = 0; i < strVec.size(); i++) {
//		intVec.push_back(stoi(strVec[i]));
//	}
//	return intVec;
//}
csv_load::csv_load(string filename)
{
	/*
	This is to open a csv file provided, and to process its contents into vectors
	to then be consumed by the scheduling processes. 
	*/
	file = new ifstream(filename);
	if (file->is_open()) {
		string line;
		int line_no = 1;
		while (getline(*file, line)) {
			string acc = "";
			vector<string> tmp;
			for (int i = 0; i < line.size(); i++) {
				if (line[i] != ',') {
					char bler = line[i];
					acc += line[i];
				}
				else {
					tmp.push_back(acc);
					acc = "";
				}
			}
			tmp.push_back(acc);
			//this is the initial loading of items into arrays
			if (tmp.size() == 3) {
				pid.push_back(tmp[0]);
				t_start.push_back(stoi(tmp[2]));
				t_end.push_back(stoi(tmp[1]));

				csv_load::proc tProc;
				tProc.pid = tmp[0];
				//cout << tProc.pid;
				tProc.t_start = stoi(tmp[2]);
				//cout << tProc.t_start;
				tProc.t_run = stoi(tmp[1]);
				//cout << tProc.t_end;
				procList.push_back(tProc);
			}
			else {
				cerr << "INPUT ERROR, File not in ID,S,E format on line: " << line_no << endl;
				throw
					exception("IoException");
			}
			line_no++;
		}
		//swap strings into integers
		file->close();
	}
	else
		cout << "Error File: " << filename << "not found, or could not be opened." << endl;

}
csv_load::~csv_load()
{
}
vector<string> csv_load::csv_get_pid() {
	return pid;
}
vector<int> csv_load::csv_get_tstart() {
	return t_start;
}
vector<int> csv_load::csv_get_trun() {
	return t_end;
}

vector<csv_load::proc> csv_load::csv_getProcList()
{
	return procList;
}
