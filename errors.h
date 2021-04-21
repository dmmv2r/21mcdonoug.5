#ifndef ERRORS_H
#define ERRORS_H

#include <string>

using namespace std;

void setup(string arg);

void perrandquit();

void errquit(const char* error);
void errquit(string error);

void help(const char* error);
void help(string error);

void pathperror();

#endif
