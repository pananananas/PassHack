#include "hacking.hpp"
std::mutex mutex;


void producer0(data &Data) {
    string word, wPostfix, wPrefix;
    
    for (const dictdata& dict : Data.dictVector) {

        word = dict.word;
        isPassCracked(Data, word);
        
        for (int i = 0; i < NumLimit; ++i) {
            
            wPostfix = word + to_string(i);
            wPrefix  = to_string(i) + word;
            
            for (int j = 0; j < NumLimit; ++j)
                
                isPassCracked(Data, to_string(j) + wPostfix);
                
            isPassCracked(Data, wPrefix);
            isPassCracked(Data, wPostfix);
        }
    }
}

void producer1(data &Data) {
    string word, wPostfix, wPrefix;
    
    for (const dictdata& dict : Data.dictVector) {
        
        word = dict.word;
        word[0] = toupper(word[0]);
        isPassCracked(Data, word);
        
        for (int i = 0; i < NumLimit; ++i) {
            
            wPostfix = word + to_string(i);
            wPrefix  = to_string(i) + word;
            
            for (int j = 0; j < NumLimit; ++j)
                isPassCracked(Data, to_string(j) + wPostfix);
    
            isPassCracked(Data, wPrefix);
            isPassCracked(Data, wPostfix);
        }
    }
}

void producer2(data &Data) {
    string word, wPostfix, wPrefix;
    
    for (const dictdata& dict : Data.dictVector) {

        word = dict.word;
        for (size_t i = 0; i < word.size(); ++i)
            word[i] = toupper(word[i]);
        isPassCracked(Data, word);
        
        for (int i = 0; i < NumLimit; ++i) {
            
            wPostfix = word + to_string(i);
            wPrefix  = to_string(i) + word;
            
            for (int j = 0; j < NumLimit; ++j)
                isPassCracked(Data, to_string(j) + wPostfix);
                
            isPassCracked(Data, wPrefix);
            isPassCracked(Data, wPostfix);
        }
    }
}

void producer3(data &Data) {
    string specialChar = "~`!@#$%^&*()_+-={}\\|;:'\",<.>/?";
    string word, wPostfix, wPrefix;
    
    for (const dictdata& dict : Data.dictVector) {
        
        word = dict.word;
        
        for (int i = 0; i < specialChar.length(); ++i) {
            
            wPostfix = word + specialChar[i];
            wPrefix  = specialChar[i] + word;
            
            for (int j = 0; j < specialChar.length(); ++j)
                isPassCracked(Data, specialChar[j] + wPostfix);
            
            isPassCracked(Data, wPrefix);
            isPassCracked(Data, wPostfix);
        }
    }
}

void producer4(data &Data) {
    
    for (const dictdata& d1 : Data.dictVector)
        for (const dictdata& d2 : Data.dictVector)
            isPassCracked(Data, d1.word + d2.word);
}

void producer5(data &Data) {
    
    for (const dictdata& d1 : Data.dictVector)
        for (const dictdata& d2 : Data.dictVector)
            isPassCracked(Data, d1.word + " " + d2.word);
}

void producer6(data &Data) {
    string specialChar = "~`!@#$%^&*()_+-={}\\|;:'\",<.>/?";
    
    for (const dictdata& d1 : Data.dictVector)
        for (const dictdata& d2 : Data.dictVector)
            for (int i = 0; i < specialChar.length(); ++i)
                isPassCracked(Data, d1.word + specialChar[i] + d2.word);
}

void producer7(data &Data) {
    
    for (const dictdata& d1 : Data.dictVector)
        for (const dictdata& d2 : Data.dictVector)
            for (const dictdata& d3 : Data.dictVector)
                isPassCracked(Data, d1.word + " " + d2.word + " " + d3.word);
}

bool isPassCracked(data &Data, string phrase) {
    int i = 0;
    string wordhash = md5(phrase);
    for (const passdata& pass : Data.passVector) {
        if (pass.hash == wordhash)
            return saveCrackedPass(Data, phrase, i);
        ++i;
    }
    return 0;
}

bool saveCrackedPass(data &Data, string phrase, int i) {
    
    passdata p = Data.passVector[i];
    p.crackedPass = phrase;
    
    mutex.lock();
    Data.passVector[i] = p;       // Zapis złamanego hasła w passVector
    mutex.unlock();
    
    if (Data.passVector[i].crackedPass != phrase) {
        cerr << " SAVING DATA ERROR! \n";
        return 0;
    }
    return 1;
}
