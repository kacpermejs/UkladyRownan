#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include <cassert>
#include <cmath>


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
template<unsigned int Rozmiar>
class Wektor {

    double Tab[Rozmiar]; //4 tablica statyczna

    public:

    Wektor();
    Wektor(double x,double y, double z);
    Wektor(double tablica[]);

    Wektor & operator += (const Wektor & W2); //W1 += W2  , W1 += W3 += W4
    Wektor & operator -= (const Wektor & W2);
    Wektor & operator *= (double l);
    Wektor & operator /= (double l);

    double operator * (const Wektor & W2) const; //skalarnie

    inline const Wektor operator + (const Wektor & W2) const { return Wektor(*this)+=W2; } //W1 + W2
    inline const Wektor operator - (const Wektor & W2) const { return Wektor(*this)-=W2; }
    inline const Wektor operator * (double l) const { return Wektor(*this)*=l; } // W1 * 2
    inline const Wektor operator / (double l) const { return Wektor(*this)/=l; } // W1 / 2

    double dlugosc() const; //modul

    bool operator == (const Wektor & W2) const;
    bool operator != (const Wektor & W2) const;
    //1 propozycja, x, y, z
    //double zwroc_x();
    //void zmien_x(double nx);

    inline const double & operator[] (unsigned int index) const { assert(index<Rozmiar); return this->Tab[index]; }
    inline double & operator[] (unsigned int index) { assert( index<Rozmiar); return this->Tab[index]; }
};
template <unsigned int Rozmiar>
inline Wektor<Rozmiar> operator *(double l, Wektor<Rozmiar> W2) { return Wektor<Rozmiar>(W2)*l; }
/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
template <unsigned int Rozmiar>
std::istream& operator >> (std::istream &Strm, Wektor<Rozmiar> &Wek);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
template <unsigned int Rozmiar>
std::ostream& operator << (std::ostream &Strm, const Wektor<Rozmiar> &Wek);
/*
template class Wektor<1>;
template class Wektor<2>;
template class Wektor<3>;
template class Wektor<4>;
template class Wektor<5>;
template class Wektor<6>;*/

#include "Wektor.cpp"

#endif
