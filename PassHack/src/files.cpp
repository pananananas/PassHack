#include "files.hpp"

bool files::openDictFile() {
    std::ifstream dict_file(dictFilePath1);
    if (!dict_file.is_open()) {
        std::cerr << "Nie udało się otworzyć pliku dict!" << std::endl;
        return 1;
    }
    return 0;
}

bool files::openPassFile() {
    std::ifstream pass_file(passFilePath1);
    if (!pass_file.is_open()) {
        std::cerr << "Nie udało się otworzyć pliku pass!" << std::endl;
        return 1;
    }
    return 0;
}

bool files::loadFiles() {
    if (openPassFile()) return 1;
    if (openDictFile()) return 1;
    return 0;
}

void files::closePassFile() {
    fclose(pass_file);
}

void files::closeDictFile() {
    fclose(dict_file);
}

void files::closeFiles() {
    fclose(dict_file);
    fclose(pass_file);
}
