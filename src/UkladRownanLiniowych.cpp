#ifndef UKLADROWNANLINIOWYCH_CPP
#define UKLADROWNANLINIOWYCH_CPP

#include "UkladRownanLiniowych.hh"

template <unsigned int Rozmiar>
UkladRownanLiniowych<Rozmiar>::UkladRownanLiniowych(MacierzKw<Rozmiar> AA, Wektor<Rozmiar> BB)
{
    this->A=AA;
    this->B=BB;
}

template <unsigned int Rozmiar>
Wektor<Rozmiar> UkladRownanLiniowych<Rozmiar>::oblicz()
{
    Wektor<Rozmiar> Wynik;

    MacierzKw<Rozmiar> Temp=this->A;

    double det=this->A.wyznacznik(GAUSS);
    double detx[Rozmiar];

    if(det+EPSILON!=0 && det+EPSILON!=0)
    {
        for(unsigned int i=0; i<Rozmiar; i++)
        {
            Temp[i]=this->B;
            detx[i]=Temp.wyznacznik(GAUSS);
            Wynik[i]=detx/det;
        }
    }
    return Wynik;
}


template <unsigned int Rozmiar>
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych<Rozmiar> &UklRown)
{
    Strm >> UklRown->macierz() >> UklRown->wektor();
    return Strm;
}

template <unsigned int Rozmiar>
std::ostream& operator << ( std::ostream                  &Strm,
                            const UkladRownanLiniowych<Rozmiar>    &UklRown
                          )
{
    Strm << UklRown->macierz() << std::endl << UklRown->wektor() << std::endl;
    return Strm;
}

#endif
