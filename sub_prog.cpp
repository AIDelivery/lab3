#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>

#include </home/dan/Desktop/sub_prog.h>
using namespace std;

int main(int argv, char *argc[]) {

	// argc == {"Descendant #2", filename, delay}
	sleep(atoi(argc[2]));
	
	FILE *fn = fopen(argc[1], "a");
	
	proc_attr_outt(getpid(), argc[0]);
	proc_attr_out(getpid(), fn, argc[0]);
	
	fclose(fn);
	exit(EXIT_SUCCESS);
}


