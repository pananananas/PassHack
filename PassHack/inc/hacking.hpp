#pragma once
#include "data.hpp"
#include "md5.hpp"
extern mutex mutex;

void producer0(data &Data);      // one word with smol numeric pre and postfix
void producer1(data &Data);      // one word with first uppercase numeric pre and postfix
void producer2(data &Data);      // one word with upper numeric pre and postfix
void producer3(data &Data);      // one word with smol special char pre and postfix

void producer4(data &Data);      // two words not separated
void producer5(data &Data);      // two words separated by space
void producer6(data &Data);      // two words separated by special char

void producer7(data &Data);      // three words separated by space

bool isPassCracked(data &Data, string word);            // check if passed word is password
bool saveCrackedPass(data &Data, string word, int i);   // saving cracked pass in passVector, returns true if succeeded
