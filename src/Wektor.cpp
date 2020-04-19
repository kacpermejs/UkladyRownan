#ifndef WEKTOR_CPP
#define WEKTOR_CPP

#include "Wektor.hh"
#include "rozmiar.h"

template<unsigned int Rozmiar>
Wektor<Rozmiar>::Wektor()
{
    for(double &ElemTab : Tab)
        ElemTab=0;
}

template<unsigned int Rozmiar>
Wektor<Rozmiar>::Wektor(double x, double y, double z)
{
    this->Tab[0] = x;
    this->Tab[1] = y;
    this->Tab[2] = z;
}

template<unsigned int Rozmiar>
Wektor<Rozmiar>::Wektor(double tablica[])
{
    for(unsigned int i=0; i<Rozmiar; i++)
        this->Tab[i]=tablica[i];
}

template<unsigned int Rozmiar>
Wektor<Rozmiar> & Wektor<Rozmiar>::operator += (const Wektor<Rozmiar> & W2)
{
    for(unsigned int i=0; i<Rozmiar; i++)
        this->Tab[i]+=W2.Tab[i];

    return *this;
}

template<unsigned int Rozmiar>
Wektor<Rozmiar> & Wektor<Rozmiar>::operator -= (const Wektor<Rozmiar> & W2)
{
    for(unsigned int i=0; i<Rozmiar; i++)
        this->Tab[i]-=W2.Tab[i];

    return *this;
}

template<unsigned int Rozmiar>
Wektor<Rozmiar> & Wektor<Rozmiar>::operator *= (double l)
{
    for(unsigned int i=0; i<Rozmiar; i++)
        this->Tab[i]*=l;

    return *this;
}

template<unsigned int Rozmiar>
Wektor<Rozmiar> & Wektor<Rozmiar>::operator /= (double l)
{
    if(l==0)
    {
        std::cerr << "UWAGA: Dzielenie przez zero (zwracam bazowy wektor)\n";
        return *this;
    }
    for(unsigned int i=0; i<Rozmiar; i++)
        this->Tab[i]/=l;

    return *this;
}

template<unsigned int Rozmiar>
double Wektor<Rozmiar>::dlugosc() const //modul
{
    double Wynik=0;
    for(unsigned int i=0; i<Rozmiar; i++)
    {
        Wynik+=pow((*this)[i],2);
    }

    return sqrt(Wynik);
}

template<unsigned int Rozmiar>
bool Wektor<Rozmiar>::operator == (const Wektor<Rozmiar> & W2) const
{
    for(unsigned int i=0; i<Rozmiar; i++)
    {
        if((this->Tab[i]+EPSILON)!=W2.Tab[i]||(this->Tab[i]-EPSILON)!=W2.Tab[i])
            return false;
    }
    return true;
}

template<unsigned int Rozmiar>
bool Wektor<Rozmiar>::operator != (const Wektor<Rozmiar> & W2) const
{
    return !(*this==W2);
}

template<unsigned int Rozmiar>
std::istream& operator >> (std::istream &Strm, Wektor<Rozmiar> &Wek)
{
    for(unsigned int i=0; i<ROZMIAR; i++)
        Strm >> Wek[i];
    return Strm;
}

template<unsigned int Rozmiar>
std::ostream& operator << (std::ostream &Strm, const Wektor<Rozmiar> &Wek)
{
    for(unsigned int i=0; i<ROZMIAR; i++)
        Strm << Wek[i] << "\n";
    return Strm;
}

#endif
