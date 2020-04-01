#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"



/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */


int main()
{
    //UkladRownanLiniowych   UklRown();   // To tylko przykladowe definicje zmiennej

    Wektor W1;

    W1[0]=14;

    std::cout << std::endl << " Start programu " << W1[0] << std::endl << std::endl;
    
    std::cout << "Podaj wspolrzedne wektora: ";
    std::cin >> W1

    std::cout << W1;

}
