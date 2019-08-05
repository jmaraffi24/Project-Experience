/* wc.cpp
 * Program takes in user input in the form of either a '-' or a file
 * allows the user to choose which operation they would like to perform.
 * The user can choose from -c (returns number of bytes) -l (returns number
 * of lines) or -w (returns number of bytes).
 * @param: argc = number of input parameters
 * @param: pathname = char array with all inputs inside
 */  
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using std::cout;
using std::cin;
using std::endl;
using std::string;

#define BUFFSIZE 16

int main(const int argc, const char ** pathname){

  //variables                                                                        
  int fd;
  int n;
  int byteCount = 0;
  int lineCount = 0;
  int wordCount = 0;
  int fileCount = 0;
  int space = 0;
  int count = 2;
  int temp = 2;
  char buff [BUFFSIZE];
  char inputA [BUFFSIZE];

  while(temp < argc){
    //resetting all the counter variables
    lineCount = 0;
    byteCount = 0;
    wordCount = 0;
    if(argc > 2 && strcasecmp(pathname[temp], "-") != 0){
      //condition for if files are parameters                                        
      while(count < argc){
	fileCount++;
	
	//condition for -c parameter                                                   
	if(strcasecmp(pathname[1], "-c") == 0){
	  for(int i = 2; i <= argc; i++){
	    fd = open(pathname[i], O_RDONLY);
	    while(((n = read(fd, buff, BUFFSIZE)) > 0)){
	      byteCount = byteCount + n;
	    }//while                                                                   
	  }//for                                                                       
	  cout << "Byte count in file " << fileCount << "= " << byteCount << endl;
	  close(fd);
	}//if                                                                          
	
	//condition for -l parameter                                                  
	if(strcasecmp(pathname[1], "-l") == 0){
	  for(int i = 2; i <= argc; i++){
            fd = open(pathname[i], O_RDONLY);
	    while(((n = read(fd, buff, BUFFSIZE)) > 0)){
	      for(int j = 0; j < n; j++){
		if(buff[j] == '\n'){
		  //cout << "buff[" << j << "] = " << buff[j] << endl;
		  lineCount++;
		}//if                                                                
	      }//for                                                                 
	    }//while                                                                 
	  }//for                                                                     
	  cout << "Line count in file " << fileCount << "= " << lineCount << endl;
	  close(fd);
	}//if                                                                        

	//condition for -w                                                           
	if(strcasecmp(pathname[1], "-w") == 0){
	  for(int i = 2; i <= argc; i++){
	    fd = open(pathname[i], O_RDONLY);
	    while(((n = read(fd, buff, BUFFSIZE)) > 0)){
	      for(int j = 0; j < n; j++){
		//cout << "buff[" << j << "]: " << buff[j] << endl;
		if((buff[j] == ' ' || buff[j] == '\n' || buff[j] == '\t')){  
		  space = 1;
		}//if                                                               
		if((buff[j] != ' ' || buff[j] != '\n' || buff[j] != '\t') && space != 0){
		  wordCount++;
		  space = 0;
		}//if                                                                
	      }//for                                                                 
	    }//while                                                       
	  }//for                                                                     
	  cout << "Word count in file " << fileCount << "= " << wordCount << endl;
	}//if                                                                        
	count++;
	close(fd);
      }//while                                                                     
    }//if                                                                            
    
    else{ // -c byteCount, -l lineCount, -w wordCount if the "file" is a '-'
      
      //condition for -c passed as a parameter to '-'
      if(strcasecmp(pathname[1], "-c") == 0 ){
	while((n = read(STDIN_FILENO, inputA, BUFFSIZE)) > 0){
	  byteCount = byteCount + n;
	}//while
	cout << "Bytecount for standard input = " << byteCount << endl;
	n = -1;
      }//if
      
      //condition for -l passed as a parameter to '-'
      if(strcasecmp(pathname[1], "-l") == 0){
	while((n = read(STDIN_FILENO, inputA, BUFFSIZE)) > 0){
	  for(int i = 0; i < n; i++){
	    if(inputA[i] == '\n'){
	      lineCount++;
	    }//if
	  }//for
	}//while
	cout << "Line count from standard input = " << lineCount << endl;
	n = -1;
      }//if

      //condition for -w passed as a parameter to '-'
      if(strcasecmp(pathname[1] , "-w") == 0){
	while((n = read(STDIN_FILENO, inputA, BUFFSIZE)) > 0){
	  for(int i = 0; i < n; i++){
	    if((inputA[i] == ' ' || inputA[i] == '\n' || inputA[i] == '\t')){  
	      space = 1;
	    }//if                                                               
	    if((inputA[i] != ' ' || inputA[i] != '\n' || inputA[i] != '\t') && space != 0){
	      wordCount++;
	      space = 0;
	    }//if
	    if(inputA[i] == 'EOF'){
	      n = -1;
	      space = 0;
	    }//if
	  }//for
	}//while
	cout << "Word count from standard input = " << wordCount << endl;
      }//if
    }//else 
    temp++;
  }//while
}//main
