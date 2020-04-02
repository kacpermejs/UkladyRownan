#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>
#include <cassert>
#include <cmath>


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Wektor {

    double Tab[ROZMIAR]; //4 tablica statyczna

    public:

    Wektor();
    Wektor(double x,double y, double z);
    Wektor(double tablica[]);

    Wektor & operator += (const Wektor & W2); //W1 += W2  , W1 += W3 += W4
    Wektor & operator -= (const Wektor & W2);
    Wektor & operator *= (double l);
    Wektor & operator /= (double l);

    double operator * (const Wektor & W2) const; //skalarnie

    inline const Wektor & operator + (const Wektor & W2) const { return Wektor(*this)+=W2; } //W1 + W2
    inline const Wektor & operator - (const Wektor & W2) const { return Wektor(*this)-=W2; }
    inline const Wektor & operator * (double l) const { return Wektor(*this)*=l; } // W1 * 2
    inline const Wektor & operator / (double l) const { return Wektor(*this)/=l; } // W1 / 2

    double dlugosc() const; //modul

    bool operator == (const Wektor & W2) const;
    bool operator != (const Wektor & W2) const;
    //1 propozycja, x, y, z
    //double zwroc_x();
    //void zmien_x(double nx);

    inline const double & operator[] (int index) const { return this->Tab[index]; }
    inline double & operator[] (int index) { assert(index>=0); return this->Tab[index]; }
};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
std::istream& operator >> (std::istream &Strm, Wektor &Wek);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
std::ostream& operator << (std::ostream &Strm, const Wektor &Wek);

#endif
