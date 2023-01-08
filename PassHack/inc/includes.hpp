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
#include <mutex>
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
#define dictFilePath2  "data/slownik.txt"
#define passFilePath3  "data/hasla3.txt"
#define dictFilePath3  "data/slownik.txt"
#define passFilePath4  "data/hasla4.txt"
#define dictFilePath4  "data/slownik4.txt"
#define passFilePath5  "data/hasla5.txt"
#define dictFilePath5  "data/slownik5.txt"
#define passFilePath6  "data/hasla6.txt"
#define dictFilePath6  "data/slownik.txt"


#define NumLimit 100        // limit of numbers in pre and postfix

//pthread_mutex_t mutex;
//pthread_cond_t cond;
