#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include "Wektor.hh"
#include <iostream>
#include <cmath>

enum metoda
{
LAPLACE,
GAUSS,
SARRUS
};
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

    double wyznacznikLaplace();// rozwiniecje laplace'a, gaussa, sarrusa
    double wyznacznikGauss();
    double wyznacznikSarrus();
    double wyznacznik(metoda met);

    int rzad();

    const MacierzKw & transponowana() const;
    void transponuj();

    const MacierzKw & odwroc() const;
    void odwroc();

    MacierzKw & operator*=(const MacierzKw & M2);
    MacierzKw & operator+=(const MacierzKw & M2);
    MacierzKw & operator-=(const MacierzKw & M2);
    MacierzKw & operator*=(double l);

    inline const MacierzKw operator*(const MacierzKw & M2) { return MacierzKw(*this)*=M2; }
    inline const MacierzKw operator+(const MacierzKw & M2) { return MacierzKw(*this)+=M2; }
    inline const MacierzKw operator-(const MacierzKw & M2) { return MacierzKw(*this)-=M2; }
    inline const MacierzKw operator*(double l) { return MacierzKw(*this)*=l; }

    Wektor operator*(const Wektor & W2);

    const Wektor & operator[] (int index) const { return this->Tab[index]; }
    Wektor & operator[] (int index) { assert(index>=0); return this->Tab[index]; }
    const double & operator() (int ind1, int ind2) const {return this->Tab[ind2][ind1]; }
    double & operator() (int ind1, int ind2) { assert(ind1>=0 && ind2>=0); return this->Tab[ind2][ind1]; }

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
