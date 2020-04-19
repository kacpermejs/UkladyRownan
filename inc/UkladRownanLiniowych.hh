#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include <utility>
#include "Wektor.hh"
#include "Macierz.hh"
#include "rozmiar.h"


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
template<unsigned int Rozmiar>
class UkladRownanLiniowych {
    MacierzKw<Rozmiar> A;
    Wektor<Rozmiar> B;
public:
    UkladRownanLiniowych();
    UkladRownanLiniowych(MacierzKw<Rozmiar> AA, Wektor<Rozmiar> BB);

    MacierzKw<Rozmiar> & zworc_macierz() { return this->A; }
    const MacierzKw<Rozmiar> & zworc_macierz() const { return this->A; }
    void zmien_macierz(MacierzKw<Rozmiar> MM) { this->A=MM; }
    /*analogicznie dla wektora */
    Wektor<Rozmiar> & zwroc_wektor() { return this->B; }
    const Wektor<Rozmiar> & zwroc_wektor() const { return this->B; }
    void Zmien_wektor(Wektor<Rozmiar> WW) { this->B=WW; }

    Wektor<Rozmiar> oblicz();
};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
template<unsigned int Rozmiar>
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych<Rozmiar> &UklRown);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
template<unsigned int Rozmiar>
std::ostream& operator << ( std::ostream                  &Strm,
                            const UkladRownanLiniowych<Rozmiar>    &UklRown
                          );

#include "UkladRownanLiniowych.cpp"

#endif
