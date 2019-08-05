//dirlist.cpp
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

/**
 * Utilizes a struct to open and read files from current working
 * directory and to print out the names of each file.
 */
int main(int argc, char * argv[]){
  //variables
  struct dirent * direntptr;
  DIR* dirptr;

  //opening dir
  dirptr = opendir(".");
  //checking for nullptr
  if(dirptr == nullptr) {
    perror("error opening dir");
    exit(1);
  }//if
  //reading dir from dirptr
  direntptr = readdir(dirptr);
  //printing files in dir in format required by document
  while(direntptr != nullptr) {
    cout << direntptr->d_name << endl;
    //reading next file
    direntptr = readdir(dirptr);
  }//while
}//main
