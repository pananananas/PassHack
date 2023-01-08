#pragma once

#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <thread>
#include <ctime>


using std :: to_string;
using std :: string;
using std :: vector;
using std :: thread;
using std :: cout;
using std :: endl;

#define passFilePath1  "data/hasla.txt"
#define dictFilePath1  "data/slownik.txt"
#define passFilePath2  "data/hasla2.txt"
#define dictFilePath2  "data/slownik2.txt"

#define NumLimit 100        // limit of numbers in pre and postfix
