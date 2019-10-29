#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
using namespace std;

void proc_attr_outt(pid_t pid, char *pname) {
	cout << endl << "\tProcess \"" << pname << "\" info:" << endl << endl;
	cout << "Process ID: " << pid << endl;
	cout << "Parent ID: " << getppid() << endl;
	cout << "Session ID: " << getsid(pid) << endl;
	cout << "Group ID: " << getpgid(pid) << endl;
	cout << "Real User ID: " << getuid() << endl;
	cout << "Effective User ID: " << geteuid() << endl;
	cout << "Real User Group ID: " << getgid() << endl;
	cout << "Effective User Group ID: " << getegid() << endl;
	
	return;
}

void proc_attr_out(pid_t pid, FILE  *fp, char *pname) {
	fprintf(fp, "\n\tProcess \"%s\" info:\n\n", pname);
	fprintf(fp, "Process ID: %d\n", (int) pid);
	fprintf(fp, "Parent ID: %d\n", (int) getppid());
	fprintf(fp, "Session ID: %d\n", (int) getsid(pid));
	fprintf(fp, "Group ID: %d\n", (int) getpgid(pid));
	fprintf(fp, "Real User ID: %d\n", (int) getuid());
	fprintf(fp, "Effective User ID: %d\n", (int) geteuid());
	fprintf(fp, "Real User Group ID: %d\n", (int) getgid());
	fprintf(fp, "Effective User Group ID: %d\n", (int) getegid());
	
	return;
}
