#include "hacking.hpp"

int main() {
    
    data D(1);
    
    D.loadAllData();
    
    producer0(D);
//    producer1(D);
//    producer2(D);
//    producer3(D);
    
    
    D.printCrackedPassData();
//    D.printAllData();
    
    D.freeData();
    
    return 0;
}
//