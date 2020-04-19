#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "Wektor.hh"
#include <iostream>
#include <cmath>
#include <utility>

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

template<unsigned int Rozmiar>
class MacierzKw {
    Wektor<Rozmiar> Tab[Rozmiar]; //2. propozycja, zalecana
public:
    MacierzKw();
    MacierzKw(const Wektor<Rozmiar> Tab[]);
    MacierzKw(Wektor<Rozmiar> A, Wektor<Rozmiar> B, Wektor<Rozmiar> C);

    double wyznacznikLaplace();// rozwiniecje laplace'a, gaussa, sarrusa
    double wyznacznikGauss();
    double wyznacznikSarrus();
    double wyznacznik(metoda met);

    const MacierzKw transponowana() const;
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

    Wektor<Rozmiar> operator*(const Wektor<Rozmiar> & W2);

    const Wektor<Rozmiar> & operator[] (unsigned int index) const { assert(index>=0 && index<Rozmiar); return this->Tab[index]; }
    Wektor<Rozmiar> & operator[] (unsigned int index) { assert(index>=0 && index<Rozmiar); return this->Tab[index]; }
    const double & operator() (unsigned int ind1, unsigned int ind2) const { return this->Tab[ind2][ind1]; }
    double & operator() (unsigned int ind1, unsigned int ind2) { return this->Tab[ind2][ind1]; }

};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
template<unsigned int Rozmiar>
std::istream& operator >> (std::istream &Strm, MacierzKw<Rozmiar> &Mac);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
template<unsigned int Rozmiar>
std::ostream& operator << (std::ostream &Strm, const MacierzKw<Rozmiar> &Mac);

template class MacierzKw<1>;
template class MacierzKw<2>;
template class MacierzKw<3>;
template class MacierzKw<4>;
template class MacierzKw<5>;
template class MacierzKw<6>;

#include "Macierz.cpp"

#endif
