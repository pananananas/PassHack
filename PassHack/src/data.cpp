#include "data.hpp"
extern mutex mutex;


data:: data(int dataConfig) {
    dataConfiguration = dataConfig;
    
    if (dataConfiguration == 2) {
        passPath = passFilePath2;
        dictPath = dictFilePath2;
    } else if (dataConfiguration == 3) {
        passPath = passFilePath3;
        dictPath = dictFilePath3;
    } else if (dataConfiguration == 4) {
        passPath = passFilePath4;
        dictPath = dictFilePath4;
    } else if (dataConfiguration == 5) {
        passPath = passFilePath5;
        dictPath = dictFilePath5;
    } else if (dataConfiguration == 6) {
        passPath = passFilePath6;
        dictPath = dictFilePath6;
    } else if (dataConfiguration == 7) {
        passPath = passFilePath7;
        dictPath = dictFilePath7;
    } else {
        passPath = passFilePath1;
        dictPath = dictFilePath1;
    }
}

bool data::loadPassData() {
    
    std::ifstream pass_file(passPath);
    string line;
    
    while (getline(pass_file, line)) {
        std::istringstream iss(line);
        
        // Wczytujemy dane z kolumn do zmiennych
        string col1, col2, col3, col4, rest;
        iss >> col1 >> col2 >> col3 >> col4;
        
        // Pobieramy resztę linii do rest po wczytaniu poprzednich kolumn
        getline(iss, rest);
        
        passdata data;
        data.ID = col1;
        data.hash = col2;
        data.email = col3;
        data.username = col4 + rest;    // i dodajemy resztę linii do początku username, który jest col4. a to wszystko aby obsługiwać username zawierające spację :>
        data.crackedPass = "---";
        data.printed = false;
        passVector.push_back(data);
    }
    pass_file.close();
    
    return 0;
}

bool data::loadDictData() {
    
    std::ifstream dict_file(dictPath);
    string line;
    
    while (getline(dict_file, line)) {
        
        dictdata data;
        std::stringstream ss(line);
        
        ss >> data.word;
        
        dictVector.push_back(data);
    }
    dict_file.close();
    return 0;
}

void data::loadAllData() {
    loadPassData();
    loadDictData();
}

void data:: printPassData() {
    cout << "\n Pass data: \n\n";
    for (const passdata& data : passVector) {
        mutex.lock();
        cout << " ID: "  << data.ID
             << ",\t hash: "  << data.hash
             << ",\t email: " << data.email
             << ",\t uname: " << data.username
             << ",\t crackedPass: " << data.crackedPass << endl;
        mutex.unlock();
    }
}

void data:: printCrackedPassData() {
    cout << "\n\n Done. \n Cracked pass data: \n\n";
    for (const passdata& data : passVector) {
        mutex.lock();
        if (data.crackedPass != "---" )
            cout << " ID: "  << data.ID
                 << ",\t hash: "  << data.hash
                 << ",\t email: " << data.email
                 << ",\t uname: " << data.username
                 << ",\t crackedPass: " << data.crackedPass << endl;
        mutex.unlock();
    }
}

void data:: printCrackedPassOnline() {
    int i = 0;
    for (const passdata& data : passVector) {
        mutex.lock();
        if ( !data.printed && data.crackedPass != "---" ) {
            passdata p = data;
            p.printed = true;
            passVector[i] = p;
            cout << " Hasło użytkownika: \"" << data.username
                 << "\" zostało złamane, \t hasło: " << data.crackedPass << endl;
        }
        ++i;
        mutex.unlock();
    }
}

void data:: printDictData() {
    cout << "\n Dict data: \n\n";
    for (const dictdata& data : dictVector)
        cout << " word: " << data.word << std::endl;
}

void data:: printAllData() {
    cout << "\n Pass data: \n\n";
    for (const passdata& data : passVector){
        mutex.lock();
        cout << " ID: "       << data.ID
             << ",\t hash: "  << data.hash
             << ",\t email: " << data.email
             << ",\t uname: " << data.username
             << ",\t crackedPass: " << data.crackedPass<< endl;
        mutex.unlock();
    }
    cout << "\n Dict data: \n\n";
    for (const dictdata& data : dictVector)
        cout << " word: " << data.word << endl;
}

void data::summariseNFreeData(){
    int i = 0;
    for (const passdata& data : passVector)
        if ( data.crackedPass != "---" )
            ++i;
    if (i > 0)
        cout << "\n Hacking passwords sucseeded. I guessed " << i << " passwords. \n\n";
    else if (i == 1)
        cout << "\n Hacking passwords sucseeded. I guessed " << i << " password. \n\n";
    else
        cout << "\n No passwords guessed. :c \n\n";
    freeData();
}

void data:: freeData() {
    passVector.clear();
    passVector.shrink_to_fit();
    dictVector.clear();
    dictVector.shrink_to_fit();
}

