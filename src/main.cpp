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

    Wektor W1={2,2,0};
    Wektor W2={2,2,0};

    std::cout << W1;



    std::cout << (W1!=W2);

}
