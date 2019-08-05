#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>

#include "CircularLinkedList.h"
#include "NodeType.h"
#include "ItemType.h"

/**
 * Prints the menu for main
 * Written by Mary Claire Hodge
 */
void printMenu(){
    std::cout << "insert (i), delete (d), length (l), print (p), quit (q)" << std::endl;
}//printMenu

//Written by Mary Claire Hodge
int main(int argc, char ** argv){
    CircularLinkedList list;
    ItemType item;
    bool shouldQuit = false;

    int input;
    std::fstream fs;
    fs.open(argv[1], std::fstream::in);

    if(fs.is_open()){
        fs >> input;

        while(!fs.eof()) {
            item.initialize(input);
            list.insertItem(item);
            fs >> input;
        }//while

        }//if
        else {
            std::cout << "Failed to open the input file" << std::endl;
            return 0;
        }//else
    
    printMenu();
    
    while(shouldQuit == false){
        int num;
        
        std::cout << "Enter a command: " << std::endl;
        std::string command;
        std::string extra = "";
        std::getline(std::cin, command);
        
        if((strcmp(command.c_str(), "i")) == 0){ //insert
            std::cout <<"Enter a number to insert" << std::endl;
            list.print();
            
            std::cin >> num;
            std::getline(std::cin, extra); //gets extra /n character
            item.initialize(num);
            list.insertItem(item);
            
        }//if
        
        else if((strcmp(command.c_str(), "d")) == 0){ //delete
            std::cout <<"Enter a number to delete" << std::endl;
            list.print();
            
            std::cin >> num;
            std::getline(std::cin, extra); //gets extra /n character
            item.initialize(num);
            list.deleteItem(item);
            
        }//else if
        
        else if((strcmp(command.c_str(), "l")) == 0) { //length
            std::cout << list.lengthIs() << std::endl;
        }//else if
        
        else if((strcmp(command.c_str(), "p")) == 0) { //print
            list.print();
        }//else if
        
        else if((strcmp(command.c_str(), "q")) == 0){ //quit
            std::cout << "Quitting..." << std::endl;
            shouldQuit = true;
        }//else if
        
        else { //error checking
            std::cout << "Invalid Input. Try again." << std::endl;
        }//else
        
    }//while
    
}//main

