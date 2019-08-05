/*env.cpp                                                                           *Program prints out all the enviorment variables associated with the
 *file that is inputted by the user.
 */  
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

#define BUFFSIZE 1
/**                                                                                    
 * Driver class for env.  Writes all environmental                                     
 * variables to standard output                                                        
 */
int main(int argc, char** argv, char** envp) {
  //variables                                                                          
  int i = 0;
  int j = 0;
  int temp = 0;
  char buff[BUFFSIZE];
  //checking for initial nullptr in envp[i]                                            
  while(envp[i] != nullptr) {
    //resetting j                                                                      
    j = 0;
    //writing what is in envp to buff and writing to standard output                   
    while(envp[i][j] != '\0'){
      buff[0] = envp[i][j];
      write(STDOUT_FILENO, buff, BUFFSIZE);
      j++;
    }//while                                                                           
    //endline for formatting                                                           
    cout << endl;
    i++;
  }//while                                                                             
}//main                                                                                

