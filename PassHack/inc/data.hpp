#pragma once
#include "files.hpp"

struct passdata {       // each row from pass data file
    string ID;
    string hash;
    string email;
    string username;
    string crackedPass;
    bool   printed;     // flag to check if data was printed before
};

struct dictdata {       // each row from dict data file
    string word;
};

class data {
    string passPath;    // path to file with pass data
    string dictPath;    // path to file with dict data

public:
    vector<passdata> passVector;    // vector with pass data
    vector<dictdata> dictVector;    // vector with dict data
    
    int dataConfiguration;          // ID of data configuration
    
    data(int dataConfig);           // initializing data, you set a data configuration
    bool loadPassData();            // loading pass data from chosen data configuration
    bool loadDictData();            // loading dict data from chosen data configuration
    void loadAllData();             // loading all data needed
    void printPassData();           // cout all pass data
    void printCrackedPassData();    // cout all cracked passwords
    void printCrackedPassOnline();  // cout cracked passwords on the fly
    void printDictData();           // cout all dict data
    void printAllData();            // cout all data
    void freeData();                // free memory
};
