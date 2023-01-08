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

/*  Wymagania:
 
    - producenci jednowyrazowi, numeracyjne pre i postfix, znaki szczególne
    - producenci dwuwyrazowi, oddzielone znakami szczegolnymi, numeracyjne pre i postfix
    - łącznie min 6 producentów
    - przez cały czas działania programu program ma czytać stdin, gdzie można wpisać nazwe nowego pliku z hasłami. wtedy cały program ma reset i zarówno producenci i konsumenci skupiają się na nowych danych
    - dodatkowo, program powinien obsługiwać ,,przerwanie'' od użytkownika. Po otrzymaniu sygnału SIGHUP przez program, wątek konsumenta powinien wyświetlić jednolinijkowe podsumowanie osiągniętych wyników dla bieżącego pliku haseł.
    - każdy konsument ma działać jako osobny wątek. w momencie złamania hasła przez jednego z producentów powinien on poinformować pozostałe wątki wpisując złamane hasło do wspóldzielonej struktury danych, poprawnie zabezpieczonej muteksem. Pozostali producenci, którzy w tym czasie pracowali nad tym samym hasłem, powinni je porzucić, i przejść do następnego.
    - wątek konsumenta - wyświetlanie na ekranie znalezionych złamanych haseł, gdy otrzymuje je od producentów
    - 
 
 

*/
