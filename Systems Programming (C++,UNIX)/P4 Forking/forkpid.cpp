//forkpid.cpp
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>

using std::cout;
using std::endl;
/*
 *Forkpid prints it's process id, the process id of it's parent,
 *forks a child process, prints its process id and then prints
 *the process id of it's parent.
 */
int main() {
  //variables
  pid_t pid;
  
  //output section for the process' characteristics before any "forking" occurs
  cout << "Before fork: " << endl;
  cout << "Process ID before forking: " << getpid() <<  endl;
  cout << "Process ID of my parent (before forking): " << getppid() << endl;

  //checking for an error in the forking process
  if ((pid = fork()) == -1) { // error
    perror("FORK ERROR");
  } else if (pid == 0) {    // in child process
    cout << endl << "***Inside of Child process***" << endl;
    cout << "Process ID in child: " << getpid() << " My parent has a pid of: " << getppid() << endl;
  } else {                  // in parent process
    sleep(3);
    cout << endl << "***Inside of Parent process***" << endl;
    cout << "Process ID in parent: " << getpid() << endl;
  } // if

  //output section after forking is done
  cout << endl;
  cout << "After fork: " << endl;
  cout << "Process ID after forking: " << getpid() << endl;
  
  return EXIT_SUCCESS;

} // main

