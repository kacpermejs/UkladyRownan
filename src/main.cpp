#include <iostream>
#include <fstream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"
#include "rozmiar.h"





/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */


int main()
{
using namespace std;

    UkladRownanLiniowych<ROZMIAR>   UklRown();   // To tylko przykladowe definicje zmiennej

    MacierzKw<ROZMIAR> Mac1;
    Wektor<ROZMIAR> Wek1;
    UklRown.zmien_macierz(Mac1);

}




