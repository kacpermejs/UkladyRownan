#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include "Wektor.hh"
#include <iostream>


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class MacierzKw {
    Wektor Tab[ROZMIAR]; //2. propozycja, zalecana
public:
    MacierzKw();
    MacierzKw(const Wektor Tab[]);
    MacierzKw(Wektor A, Wektor B, Wektor C);

    double wyznacznik();// rozwiniecje laplace'a, gaussa, sarrusa
    // double wyznacznikGauss(); double wyznacznik(metoda met = Gauss) <- enum
    int rzad();

    const MacierzKw & transponuj() const;
    void transponuj();

    const MacierzKw & odwroc() const;
    void odwroc();

    const MacierzKw & operator*(const MacierzKw & M2);
    const MacierzKw & operator+(const MacierzKw & M2);
    const MacierzKw & operator-(const MacierzKw & M2);
    const MacierzKw & operator*(double l);
    const Wektor & operator*(const Wektor & W2);

    const Wektor & operator[] (int index) const { return this->Tab[index]; }
    Wektor & operator[] (int index) { assert(index>=0); return this->Tab[index]; }

};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
std::istream& operator >> (std::istream &Strm, MacierzKw &Mac);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
std::ostream& operator << (std::ostream &Strm, const MacierzKw &Mac);


#endif
