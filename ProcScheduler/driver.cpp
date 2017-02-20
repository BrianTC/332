#ifdef _WIN32{
	const bool pause = true;

#else
	const bool pause = false;
#endif // _WIN32

#include "csv_load.h"
#include <iostream>
using namespace std;
int main() {
	try {
		csv_load("Text.csv");
	}
	catch (const exception &e) {
		cout << "Check Input File"<<endl;
	}
	if (pause) {
		system("pause");
	}
	return 0;
}