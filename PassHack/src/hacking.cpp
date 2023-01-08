#include "hacking.hpp"

void producer0(data &Data) {
    
    for (const dictdata& dict : Data.dictVector) {
        
        string word = dict.word;
        
        for (int i = 0; i < NumLimit; ++i) {
            
            string wPostfix = word + to_string(i);
            string wPrefix  = to_string(i) + word;
            for (int j = 0; j < NumLimit; ++j) {
                
                string wPreNPostFix = to_string(j) + wPostfix;
                
                isPassCracked(Data, wPreNPostFix);
            }
            isPassCracked(Data, wPrefix);
            isPassCracked(Data, wPostfix);
        }
    }
}

void producer1(data &Data) {
    
    for (const dictdata& dict : Data.dictVector) {
        
        string word = dict.word;
        
        word[0] = toupper(word[0]);
        
        for (size_t i = 1; i < word.size(); ++i)
            word[i] = tolower(word[i]);
        
        for (int i = 0; i < NumLimit; ++i) {
            
            string wPostfix = word + to_string(i);
            string wPrefix  = to_string(i) + word;
            
            for (int j = 0; j < NumLimit; ++j) {
                
                string wPreNPostFix = to_string(j) + wPostfix;
                
                isPassCracked(Data, wPreNPostFix);
            }
            isPassCracked(Data, wPrefix);
            isPassCracked(Data, wPostfix);
        }
    }
}

void producer2(data &Data) {
    
    for (const dictdata& dict : Data.dictVector) {
        
        string word = dict.word;
        
        for (size_t i = 0; i < word.size(); ++i)
            word[i] = toupper(word[i]);
        
        for (int i = 0; i < NumLimit; ++i) {
            
            string wPostfix = word + to_string(i);
            string wPrefix  = to_string(i) + word;
            
            for (int j = 0; j < NumLimit; ++j) {
                
                string wPreNPostFix = to_string(j) + wPostfix;
                
                isPassCracked(Data, wPreNPostFix);
            }
            isPassCracked(Data, wPrefix);
            isPassCracked(Data, wPostfix);
        }
    }
}

void producer3(data &Data) {
    string specialChar = "~`!@#$%^&*()_+-={}\\|; :'\",<.>/?";
    
    for (const dictdata& dict : Data.dictVector) {
        
        string word = dict.word;
        
        for (int i = 0; i < specialChar.length(); ++i) {
            
            string wPostfix = word + specialChar[i];
            string wPrefix  = specialChar[i] + word;
            
            for (int j = 0; j < specialChar.length(); ++j) {
                
                string wPreNPostFix = specialChar[j] + wPostfix;
                isPassCracked(Data, wPreNPostFix);
            }
            isPassCracked(Data, wPrefix);
            isPassCracked(Data, wPostfix);
        }
    }
}


bool isPassCracked(data &Data, string word) {
    int i = 0;
    for (const passdata& pass : Data.passVector) {
        if (pass.hash == md5(word))
            return passCrakced(Data, word, i);
        ++i;
    }
    return 0;
}

bool passCrakced(data &Data, string word, int i) {
    
    printCrackedPass(Data, word, i);
    saveCrackedPass(Data, word, i);

    return 1;
}

void saveCrackedPass(data &Data, string word, int i) {
    passdata& p = Data.passVector[i];       // Zapis złamanego hasła w passVector
    p.crackedPass = word;
    Data.passVector[i] = p;
}

void printCrackedPass(data Data, string word, int i) {
    cout << " Hasło " << Data.passVector[i].username
         << " złamane.\t Hasło: " << word
         << ",\t hasz: " << Data.passVector[i].hash << endl;
}
