// Just checking fork() abilities

#include <sys/types.h>
#include <unistd.h>
#include <iostream>
using namespace std;

int main(int argv, char *argc[]) {
    int pid1, pid2;
    pid1 = fork();
    pid2 = fork();
    
    cout << "PIDs: " << pid1 << "-" << pid2 << endl;
    
    return 0;
}
