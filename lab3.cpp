#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

#include </home/dan/Desktop/sub_prog.h>
using namespace std;

/*
void custom_sleep(int sec) {
	for(int i = 0; i < sec; ++i) {
		cout << '.';
		sleep(1);
		cout << '.';
	}
	
	cout << endl;
}
*/

int main(int argv, char *argc[]) {
    int pid1, pid2, status;
    char filename[FILENAME_MAX];
    int del_sec[] = {atoi(argc[1]), atoi(argc[2]), atoi(argc[3])};
    
    cout << "Input log file name: ";
	cin >> filename;
    FILE *fn = fopen(filename, "w");
    fclose(fn);
    
    pid1 = fork();
    cout << endl << "FORK ENTER" << endl;
    if(pid1 > 0) {
		cout << endl << "VFORK ENTER" << endl;
		pid2 = vfork();
	}

    if(pid1 < 0 || pid2 < 0) {
		cout << "ERROR" << endl;
		return 0;
	}
    else if(pid1 == 0 && pid2 != 0) {
		cout << endl << "PID1 HERE!" << pid2 << endl;
		sleep(del_sec[1]);
		cout << endl << "PID1 IS READY!" << pid2 << endl;
		fn = fopen(filename, "a");
		proc_attr_out(getpid(), fn, (char*) "Descendant #1");
		proc_attr_outt(getpid(), (char*) "Descendant #1");
		fclose(fn);
		exit(EXIT_SUCCESS);
	}
	else if(pid2 == 0) {
		cout << endl << "PID2 HERE!" << pid1 << endl;
		sleep(del_sec[2]);
		cout << endl << "PID2 IS READY!" << pid2 << endl;
		fn = fopen(filename, "a");
		execl("/home/dan/Desktop/sub_prog", "Descendant #2", filename, (char*) 0);
		fclose(fn);
		exit(EXIT_SUCCESS);
	}
	else if(pid1 > 0 && pid2 > 0) {
		cout << endl << "PAPA IS HERE!" << pid1 << pid2 << endl;
		sleep(del_sec[0]);
		cout << endl << "PAPA IS READY!" << pid1 << pid2 << endl;
		fn = fopen(filename, "a");
		proc_attr_out(getpid(), fn, (char*) "Ancesor (main process)");
		proc_attr_outt(getpid(), (char*) "Ancesor (main process)");
		fclose(fn);
	}
	
	// waitpid(pid1, &status, 0);
	return 0;
}
