//size.cpp
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
using std::cout;
using std::cin;
using std::endl;
using std::string;

#define BUFFSIZE 1

/**
 * Utilizes fstat() size method to get the size of entered
 * files.  Loops through the files and prints the size of
 * each and then prints the total size of all files.
 * Prints the toal length of standard input if no files
 * are specified.
 */
int main(int argc, char * argv[]){
  char input[BUFFSIZE];
  struct stat buff;
  int size = 0;
  int totalSize = 0;
  int n = 0;
  int fd = 0;
  int count = 1;
  int fileCount = 1;
  //for standard input condition
  if(argc == 1){
    //reading from standard input and incrementing size appropriately
    while((n = read(STDIN_FILENO, input, BUFFSIZE)) > 0){
      size = size + n;
    }//while
    //printing size of standard input
    cout << "Size of standard input = " << size << endl;
    n = -1;
  }//if
  //condition for files being entered
  else{
    //loop to get files
    for(int i = count; i < argc; i++){
      size = 0;
      fd = open(argv[i], O_RDONLY);
      //using fstat() to obtain size method
      fstat(fd, &buff);
      //incrementing size and totalSize appropriately
      size = size + buff.st_size;
      totalSize = totalSize + size;
      //printing size of files
      cout << "Size of file " << fileCount << " = " << size << endl;
      fileCount++;
      //closing file
      close(fd);
    }//for
    //printing total size of all files
    cout << "Total size of files = " << totalSize << endl;
  }//else
}//main

  
