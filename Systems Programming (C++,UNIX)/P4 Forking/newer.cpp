//newer.cpp
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
 * Comparing access, modification, and change times of two files.
 * Prints the most recent time that is specified by the "-c",
 * "-m", or "-c" parameter.
 */
int main(int argc, char * argv[]){
  //variables
  struct stat buff;
  int fd = 0;
  int file1 = 0;
  int file2 = 0;

  //-a condition
  if(strcasecmp(argv[1], "-a") == 0){
    //opening file
    fd = open(argv[2], O_RDONLY);
    fstat(fd, &buff);
    //setting access time
    file1 = buff.st_atime;
    cout << "Time of last access: " << ctime(&buff.st_atim.tv_sec) << endl;
    //closing file
    close(fd);
    //file 2
    //opening file
    fd = open(argv[3], O_RDONLY);
    fstat(fd, &buff);
    //setting access time
    file2 = buff.st_atime;
    cout << "Time of last access: " << ctime(&buff.st_atim.tv_sec) << endl;
    //closing file
    close(fd);
    //comparing access times and printing appropriate file name
    if(file1 > file2){
      cout << argv[2] << endl;
    }//if
    else if(file2 > file1){
      cout << argv[3] << endl;
    }//elseif
  }//if

  //-m condition
  if(strcasecmp(argv[1], "-m") == 0){
    //opening file
    fd = open(argv[2], O_RDONLY);
    fstat(fd, &buff);
    //setting modification time
    file1 = buff.st_mtime;
    cout << "Time of last modification: " << ctime(&buff.st_mtim.tv_sec) << endl;
    //closing file
    close(fd);
    //file 2
    //opening file
    fd = open(argv[3], O_RDONLY);
    fstat(fd, &buff);
    //setting modification time
    file2 = buff.st_mtime;
    cout << "Time of last modification: " << ctime(&buff.st_mtim.tv_sec) << endl;
    //closing file
    close(fd);
    //comparing files and printing appropriate file name
    if(file1 > file2){
      cout << argv[2] << endl;
    }//if
    else if(file2 > file1){
      cout << argv[3] << endl;
    }//elseif
  }//if

  //-c condition
  if(strcasecmp(argv[1], "-c") == 0){
    //opening file
    fd = open(argv[2], O_RDONLY);
    fstat(fd, &buff);
    //setting change time
    file1 = buff.st_ctime;
    cout << "Time of last change: " << ctime(&buff.st_ctim.tv_sec) << endl;
    //closing file
    close(fd);
    //file 2
    //opening file                                                            
    fd = open(argv[3], O_RDONLY);
    fstat(fd, &buff);
    //setting change time
    file2 = buff.st_ctime;
    cout << "Time of last change: " << ctime(&buff.st_ctim.tv_sec) << endl;
    //closing file
    close(fd);
    //comparing files and printing appropriate file name
    if(file1 > file2){
      cout << argv[2] << endl;
    }//if                                                                   
    else if(file2 > file1){
      cout << argv[3] << endl;
    }//elseif                                                                 
  }//if
}//main

