#include "Wektor.hh"


Wektor::Wektor()
{
    for(double &ElemTab : Tab)
        ElemTab=0;
}


std::istream& operator >> (std::istream &Strm, Wektor &Wek)
{
    for(int i=0; i<ROZMIAR; i++)
        Strm >> Wek[i];
    return Strm;
}

std::ostream& operator << (std::ostream &Strm, const Wektor &Wek)
{
    for(int i=0; i<ROZMIAR; i++)
        Strm << Wek[i] << std::endl;
    return Strm;
}