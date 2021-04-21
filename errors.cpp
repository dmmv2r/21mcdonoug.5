//Donovan McDonough
//4/20/2021

#include "errors.h"
#include "sharedmemory.h"
#include <iostream>
#include <string>

using namespace std;

string raw;
string prefix;

void setup(string arg) {
   prefix = arg;
   raw = arg;
   prefix += ": Error";
}

void perrorandquit() {
   perror(prefix.c_str());
   ipccleanup();
   exit(-1);
}

void errquit(const char* error) {
   cerr << prefix << ": " << error << "\n";
   ipccleaup();
   exit(-1);
}

void errquit(string error) {
   errorquit(error.c_str());
}

void help(const char* error) {
   cerr << prefix << ": " << error << "\n";
   cerr << "run '" << raw;
   cerr << " -h' for more help" << endl;
   ipccleanup();
   exit(-1);
}

void help(string error) {
   help(error.c_str());
}

void pathperror() {
   errquit(string("INVALID PATH\n");
}
