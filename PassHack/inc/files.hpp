#pragma once
#include "includes.hpp"

class files {

public:
    FILE *dict_file;
    FILE *pass_file;

    bool openDictFile();
    bool openPassFile();
    bool loadFiles();
    void closeDictFile();
    void closePassFile();
    void closeFiles();
};
