#include "proc_algorithim.h"
ostringstream* proc_algorithim::shortestProcNext(csv_load a) {
	ostringstream *printOut=new ostringstream();
	*printOut << "ShortestProcessNext:\n";
	vector<csv_load::proc> procList = a.csv_getProcList();
	int clock = 0;
	vector<csv_load::proc> cProcList;
	while (procList.size() > 0 || cProcList.size() > 0) {
		//Queue processes ready to be run
		for (size_t i = 0; i < procList.size(); i++) {
			if (procList[i].t_start <= clock){
				cProcList.push_back(procList[i]);
				procList.erase(procList.begin() + i);
				i--;
			}
		}
		//cout << cProcList.size() << endl;
		//Process Shortest Process Next
		csv_load::proc shortestProcess;
		int shortestProcessLen,shortIndex;
		for (size_t i = 0; i < cProcList.size(); i++) {
			//initialize first value 
			if (i == 0){
				shortestProcess = cProcList[0];
				shortIndex = 0;
				shortestProcessLen = shortestProcess.t_run;
			}
			//find next shortest value
			if (cProcList[i].t_run < shortestProcessLen){
				shortestProcessLen = cProcList[i].t_run;
				shortestProcess = cProcList[i];
				shortIndex = i;
			}
		}
		if (cProcList.size()>0) {
			//std::cout << shortestProcess.pid;
			cProcList.erase(cProcList.begin() + shortIndex);
			for (int i = 0; i < shortestProcessLen; i++) {
				*printOut << "Cycle: " << setw(IOWIDTH) << clock << " PID: " << shortestProcess.pid << endl;
				clock++;
			}
		}
		else {
			*printOut << "Cycle: "  << setw(IOWIDTH) << clock << " EMPTY CYCLE" << endl;
			clock++;
		}

	}//END WHILE
	return printOut;
	//TODO;
	//roundRobinAlgorithim
}

ostringstream* proc_algorithim::HRRN(csv_load a) {

}
ostringstream* proc_algorithim::roundRobin(csv_load a) {

}
ostringstream* proc_algorithim::feedback(csv_load a) {

}