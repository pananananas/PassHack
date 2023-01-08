#include "hacking.hpp"

int main() {
    
    data D(6);
    D.loadAllData();

    thread t0([&]() {   producer0(D);   });
    thread t1([&]() {   producer1(D);   });
    thread t2([&]() {   producer2(D);   });
    thread t3([&]() {   producer3(D);   });
    thread t4([&]() {   producer4(D);   });
    thread t5([&]() {   producer5(D);   });
    thread t6([&]() {   producer6(D);   });
    thread t7([&]() {   producer7(D);   });
    thread t8([&]() {
        while (t0.joinable() || t1.joinable() ||
               t2.joinable() || t3.joinable() ||
               t4.joinable() || t5.joinable() ||
               t6.joinable() || t7.joinable()) {
                D.printCrackedPassOnline();
//            std::this_thread::sleep_for(std::chrono::seconds(1));     // Odśwież dane co 1 sekundę
        }
    });

    t0.join();
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();
    
    D.freeData();
    return 0;
}

/*  Wymagania:
 
    - przez cały czas działania programu program ma czytać stdin, gdzie można wpisać nazwe nowego pliku z hasłami. wtedy cały program ma reset i zarówno producenci i konsumenci skupiają się na nowych danych
    - dodatkowo, program powinien obsługiwać ,,przerwanie'' od użytkownika. Po otrzymaniu sygnału SIGHUP przez program, wątek konsumenta powinien wyświetlić jednolinijkowe podsumowanie osiągniętych wyników dla bieżącego pliku haseł.
 
    - każdy konsument ma działać jako osobny wątek. w momencie złamania hasła przez jednego z producentów powinien on poinformować pozostałe wątki wpisując złamane hasło do wspóldzielonej struktury danych, poprawnie zabezpieczonej muteksem. Pozostali producenci, którzy w tym czasie pracowali nad tym samym hasłem, powinni je porzucić, i przejść do następnego.
    - wątek konsumenta - wyświetlanie na ekranie znalezionych złamanych haseł, gdy otrzymuje je od producentów
*/
