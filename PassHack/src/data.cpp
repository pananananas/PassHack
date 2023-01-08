#include "data.hpp"


data:: data(int dataConfig) {
    dataConfiguration = dataConfig;
    
    if (dataConfiguration == 2) {
        passPath = passFilePath2;
        dictPath = dictFilePath2;
    } else {
        passPath = passFilePath1;
        dictPath = dictFilePath1;
    }
}


bool data::loadPassData() {
    
    std::ifstream pass_file(passPath);
    string line;
    
    while (getline(pass_file, line)) {
        
        // Tworzymy strumień dla aktualnej linii
        std::istringstream iss(line);
        
        // Wczytujemy dane z kolumn do zmiennych
        string col1, col2, col3;
        iss >> col1 >> col2 >> col3;
        
        // Pobieramy resztę linii po wczytaniu poprzednich kolumn
        string col4;
        getline(iss, col4);
        
        passdata data;
        data.ID = col1;
        data.hash = col2;
        data.email = col3;
        data.username = col4;
        data.crackedPass = "---";
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
    for (const passdata& data : passVector)
        cout << " ID: "       << data.ID
             << ",\t hash: "  << data.hash
             << ",\t email: " << data.email
             << ",\t uname: " << data.username
             << ",\t crackedPass: " << data.crackedPass
             << std::endl;
}


void data:: printCrackedPassData() {
    
//    cout << "\n Cracked pass data: \n\n";
    for (const passdata& data : passVector)
        if (data.crackedPass != "---")
        cout << " ID: "       << data.ID
             << ",\t hash: "  << data.hash
             << ",\t email: " << data.email
             << ",\t uname: " << data.username
             << ",\t crackedPass: " << data.crackedPass
             << std::endl;
}


void data:: printDictData() {
    cout << "\n Dict data: \n\n";
    for (const dictdata& data : dictVector)
        cout << " word: " << data.word << std::endl;
}


void data:: printAllData() {
    cout << "\n Pass data: \n\n";
    for (const passdata& data : passVector)
        cout << " ID: "       << data.ID
             << ",\t hash: "  << data.hash
             << ",\t email: " << data.email
             << ",\t uname: " << data.username
             << std::endl;
    cout << "\n Dict data: \n\n";
    for (const dictdata& data : dictVector)
        cout << " word: " << data.word << std::endl;
}


void data:: freeData() {
    passVector.clear();
    passVector.shrink_to_fit();
    
    dictVector.clear();
    dictVector.shrink_to_fit();
}
