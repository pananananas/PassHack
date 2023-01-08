#include "hacking.hpp"

int main() {
    
    data D(6);
    D.loadAllData();

    array <thread, 9> T;
    
    T[0] = thread ( producer0, ref(D) );
    T[1] = thread ( producer1, ref(D) );
    T[2] = thread ( producer2, ref(D) );
    T[3] = thread ( producer3, ref(D) );
    T[4] = thread ( producer4, ref(D) );
    T[5] = thread ( producer5, ref(D) );
    T[6] = thread ( producer6, ref(D) );
    T[7] = thread ( producer7, ref(D) );

    T[8] = thread ( [&]() {
        while ( T[0].joinable() || T[1].joinable() || T[2].joinable() || T[3].joinable() ||
                T[4].joinable() || T[5].joinable() || T[6].joinable() || T[7].joinable() )
            D.printCrackedPassOnline(); });
    
    for ( thread& t : T )  t.join();
    
    D.freeData();
    return 0;
}
