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
#include <array>

using std :: to_string;
using std :: string;
using std :: vector;
using std :: thread;
using std :: mutex;
using std :: array;
using std :: cout;
using std :: endl;
using std :: cerr;
using std :: ref;

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




//
//int main() {
//
//    data D(6);
//    D.loadAllData();
//
//    thread t0( producer0, std::ref(D) );
//    ////    thread t1( producer1, &D );
//    ////    thread t2( producer2, &D );
//    ////    thread t3( producer3, &D );
//    ////    thread t4( producer4, &D );
//    ////    thread t5( producer5, &D );
//    ////    thread t6( producer6, &D );
//    ////    thread t7( producer7, &D );
//
//
//
//
//    vector<thread> threads;
//
//    threads.emplace_back( [&]() { producer0(D); } );
//    threads.emplace_back( [&]() { producer1(D); } );
//    threads.emplace_back( [&]() { producer2(D); } );
//    threads.emplace_back( [&]() { producer3(D); } );
//    threads.emplace_back( [&]() { producer4(D); } );
//    threads.emplace_back( [&]() { producer5(D); } );
//    threads.emplace_back( [&]() { producer6(D); } );
//    threads.emplace_back( [&]() { producer7(D); } );
//    threads.emplace_back( [&]() {
//        while (threads[0].joinable() || threads[1].joinable() ||
//               threads[2].joinable() || threads[3].joinable() ||
//               threads[4].joinable() || threads[5].joinable() ||
//               threads[6].joinable() || threads[7].joinable())
//            D.printCrackedPassOnline();
//    });
//
//    for (thread& t : threads)
//        t.join();
//    threads.clear();
//    threads.shrink_to_fit();
//
//    D.freeData();
//
//    return 0;
//}
