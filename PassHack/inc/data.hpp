#pragma once
#include "files.hpp"

struct passdata {
    string ID;
    string hash;
    string email;
    string username;
    string crackedPass;
};

struct dictdata {
    string word;
};

class data {
    string passPath;
    string dictPath;
    
public:
    
    vector<passdata> passVector;
    vector<dictdata> dictVector;
    
    int dataConfiguration;
    
    data(int dataConfig);
    bool loadPassData();
    bool loadDictData();
    void loadAllData();
    void printPassData();
    void printCrackedPassData();
    void printDictData();
    void printAllData();
    void freeData();
};
