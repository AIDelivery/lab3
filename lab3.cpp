// add killing lagging process
// check memory division

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

#include "./sub_prog.h"
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

int main(int argc, char *argv[]) {
    int pid1, pid2;
    int status;
    char filename[255], *childarg = new char[20];
    int del_sec[3];

		try {
			if(argc < 3) { childarg = (char*) "3\n"; }
			else { childarg = argv[3]; }
	    if(argc < 3) { del_sec[1] = 3; }
			else { del_sec[1] = atoi(argv[2]); }
			if(argc < 2) { del_sec[0] = 1; }
			else { del_sec[0] = atoi(argv[1]); }
		}
		catch(const exception& e) { cout << "ERROR. " << e.what(); exit(EXIT_FAILURE); }

    cout << "Input log file name: ";
		cin >> filename;
    FILE *fn = fopen(filename, "w");
    fclose(fn);

    pid1 = fork();
    if(pid1 > 0) {
			pid2 = vfork();
			if(pid2 == 0) {
				execl("./sub_prog", "Descendant #2", filename, childarg, (char*) 0);
			}
		}

    if(pid1 < 0 || pid2 < 0) {
			cout << "ERROR" << endl;
			return 1;
		}
    else if(pid1 == 0) {
			sleep(del_sec[1]);
			fn = fopen(filename, "a");
			proc_attr_out(getpid(), fn, (char*) "Descendant #1");
			proc_attr_outt(getpid(), (char*) "Descendant #1");
			fclose(fn);
			exit(EXIT_SUCCESS);
		}
	else if(pid1 > 0 && pid2 > 0) {
		sleep(del_sec[0]);
		fn = fopen(filename, "a");
		proc_attr_out(getpid(), fn, (char*) "Ancesor (main process)");
		proc_attr_outt(getpid(), (char*) "Ancesor (main process)");
		fclose(fn);
	}

	waitpid(pid1, &status, 0);
	fclose(fn);
	// delete[] childarg;
	exit(EXIT_SUCCESS);
}
