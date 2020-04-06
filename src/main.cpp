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

    MacierzKw Mac1={{1,2,3},{4,5,6},{7,8,9}};
    Wektor Wek2={2,2,2};
    Wektor Wynik;

    std::cout << Mac1 <<std::endl << Wek2 << std::endl;

    Wynik=Mac1*Wek2;

    std::cout << Wynik;

}
