/*cat.cpp                                                                                                                                                           
 *Program takes in input from the user in the from '-' or a file. It concatenates the files in order of input
 *treating '-' as a "file" that just contains whatever is input from standard input. The program returns
 *the concatenated files to standard output
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
using std::cout;
using std::cin;
using std::endl;
using std::string;

#define BUFFSIZE 16

/*                                                                                                  
 * Driveer class to test the concatenation of files/input                                             
 */

int main(const int argc, const char * pathname[]){
  //variables                                                                                         
  int fd;
  char buff [BUFFSIZE];                                                                       
  char inputA [BUFFSIZE];                                                                            
  string input;
  int n;
  //for loop to determine how to proceed with cat function                                            
  for(int i = 1; i < argc; i++){
    char buff [BUFFSIZE];
    char inputA [BUFFSIZE];
    //condition for no input in the cat parameters                                                    
    if(argc == 1){
      while((n = read(STDIN_FILENO, inputA, BUFFSIZE)) > 0){
        for(int i = 0; i < n; i++){
          if(inputA[i] == 'EOF'){
            n = -1;
          }//if                                                                                       
        }//for                                                                                        
      }//while                                                                                        
    }//if                                                                                                 //condition for cat parameter being a file 
    else if(*pathname[i] != '-'){
      //getting file descriptor                                                               
      fd = open(pathname[i], O_RDONLY);
	  //reading file                                                                          
	  while (((n = read(fd, buff, BUFFSIZE)) > 0)){
	        //printing file contents                                                              
	        /*      for(int j = 0; j < n; j++){                                                   
			cout << buff[j];                                                                    
			}//for                                                                                
	        */
	        write(STDOUT_FILENO, buff, n);
	      }//while                                                                                
    }//else if                                                                                
    //condition for cat parameter being a hyphen                                              
    else{
      while((n = read(STDIN_FILENO, inputA, BUFFSIZE)) > 0){//how would you do this to where buff varies in length to store variable input values?                                                  
	for(int i= 0; i < n; i++){
	  if(inputA[i] == 'EOF'){
	    n = -1;
	  }//if                                                                               
	}//for                                                                                
      }//while                                                                            
    }//else                                                                                   
  }//for                                                                                           
}//main
