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

    Wektor Wek1={1,2,3};
    Wektor Wek2={4,5,6};
    Wektor Wek3={7,8,9};

    MacierzKw Mac1(Wek1 ,Wek2, Wek3);

    std::cout << Mac1 << std::endl;

    std::cout << Mac1[0][1];

}
