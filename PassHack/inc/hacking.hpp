#pragma once
#include "data.hpp"
#include "md5.hpp"


void producer0(data &Data);      // one word with smol numeric pre and postfix
void producer1(data &Data);      // one word with first uppercase numeric pre and postfix
void producer2(data &Data);      // one word with upper numeric pre and postfix
void producer3(data &Data);      // one word with smol special char pre and postfix

void producer4(data &Data);      // two words not separated
void producer5(data &Data);      // two words separated with space
void producer6(data &Data);      // two words separated with special char

void producer7(data &Data);      // three words separated with space


bool isPassCracked(data &Data, string word);            // check if passed word is password
bool passCrakced(data &Data, string word, int i);       // if password is cracked, always returns 1
void saveCrackedPass(data &Data, string word, int i);   // saving cracked pass in passVector
void printCrackedPass(data Data, string word, int i);   // cout userdata whos pass was cracked
