/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: osixan
 *
 * Created on December 4, 2015, 5:13 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>

#define MAXLENGTH 320

using namespace std;
string map;

/*
 * 
 */

void next_word( string* line ) {
    
    int end = 0;
    line->at(0);
    while( line->at(0) ==  ' ' || line->at(0) == '\n' || line->at(0) == '\t') *line = line->substr(1,line->size());
    while( line->at(end) !=  ' ' || line->at(end) != '\n' || line->at(end) != '\t') ++end;
    map.append( line->substr(0,end-1) + '\n' );
    *line = line->substr(end,line->size());
    
}

void mapper( string* line )
{

    while(!line->empty()) next_word(line);
    
}

int import_file(string filename, string* lines)
{
    ifstream file;
    file.open(filename.c_str());
    int a = 0;
    if(file.is_open())
    {
        while( getline(file,lines[a]) )
        {
            ++a;
        }
        file.close();
    }
    else cout << "Could Not Open File";
    return a;
}

int main(int argc, char** argv) {
    
    string* lines = new string[MAXLENGTH];
    int b = import_file("test.txt",&lines[0]);
    
    //DONE import file IDIOT maybe seperate function
    int a = 0;
    while( a < 1 ) {
        mapper(&lines[a]);
    }
    
    return 0;
    
    cout << map;
}

