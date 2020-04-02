#include "Macierz.hh"

MacierzKw::MacierzKw()
{
    for(Wektor &ElemTab : Tab)
        ElemTab=0;
}
MacierzKw::MacierzKw(const Wektor tablica[])
{
    for(int i=0; i<ROZMIAR; i++)
        this->Tab[i]=tablica[i];
}
MacierzKw::MacierzKw(Wektor A, Wektor B, Wektor C)
{
    this->Tab[0] = A;
    this->Tab[1] = B;
    this->Tab[2] = C;
}

std::istream& operator >> (std::istream &Strm, MacierzKw &Mac)
{
    for(int i=0; i<ROZMIAR; i++)
    {
        for(int j=0; j<ROZMIAR; j++)
        {
            Strm >> Mac[j][i];
        }
    }
    return Strm;
}

std::ostream& operator << (std::ostream &Strm, const MacierzKw &Mac)
{
    for(int i=0; i<ROZMIAR; i++)
    {
        for(int j=0; j<ROZMIAR; j++)
        {
            Strm << Mac[j][i] << "\t";
        }
        Strm << "\n";
    }
    return Strm;
}
