#pragma once
#include "data.hpp"
#include "md5.hpp"

// one word
void producer0(data &Data);      // smol numeric pre and postfix
void producer1(data &Data);      // first uppercase numeric pre and postfix
void producer2(data &Data);      // upper numeric pre and postfix
void producer3(data &Data);      // smol special char pre and postfix

// two words
void producer4(data &Data);      // smol numeric pre and postfix                                    TODO
void producer5(data &Data);      // first uppercase numeric pre and postfix                         TODO
void producer6(data &Data);      // upper numeric pre and postfix                                   TODO


bool isPassCracked(data &Data, string word);            // check if passed word is password
bool passCrakced(data &Data, string word, int i);       // if password is cracked, always returns 1
void saveCrackedPass(data &Data, string word, int i);   // saving cracked pass in passVector
void printCrackedPass(data Data, string word, int i);   // cout userdata whos pass was cracked
