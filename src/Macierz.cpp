#include "Macierz.hh"

MacierzKw::MacierzKw()
{
    for(Wektor &ElemTab : Tab)
        ElemTab=Wektor();
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

double MacierzKw::wyznacznikSarrus()
{
    double Wynik;

    return Wynik=(*this)(0,0) * (*this)(1,1) * (*this)(2,2)
                +(*this)(0,1) * (*this)(1,2) * (*this)(2,0)
                +(*this)(0,2) * (*this)(1,0) * (*this)(2,1)

                -(*this)(2,0) * (*this)(1,1) * (*this)(0,2)
                -(*this)(2,1) * (*this)(1,2) * (*this)(0,0)
                -(*this)(2,2) * (*this)(1,0) * (*this)(0,1);

}

const MacierzKw & MacierzKw::transponowana() const
{
    MacierzKw Temp=(*this);

    Temp.transponuj();

    MacierzKw & refTemp=Temp;

    return refTemp;
}

void MacierzKw::transponuj()
{
    MacierzKw Temp=(*this);

    (*this)(0,0)=Temp(0,0);
    (*this)(1,0)=Temp(0,1);
    (*this)(2,0)=Temp(0,2);
    (*this)(0,1)=Temp(1,0);
    (*this)(1,1)=Temp(1,1);
    (*this)(2,1)=Temp(1,2);
    (*this)(0,2)=Temp(2,0);
    (*this)(1,2)=Temp(2,1);
    (*this)(2,2)=Temp(2,2);

}

MacierzKw & MacierzKw::operator*=(const MacierzKw & M2)
{
    MacierzKw Temp;
    for(int i=0; i<ROZMIAR; i++)
        for(int j=0; j<ROZMIAR; j++)
            for(int k=0; k<ROZMIAR; k++)
                Temp(i,j)+=(*this)(i,k)*M2(k,j);
    *this=Temp;
    return *this;
}
MacierzKw & MacierzKw::operator+=(const MacierzKw & M2)
{
    for(int i=0; i<ROZMIAR; i++)
        (*this)[i]+=M2[i];
    return *this;
}
MacierzKw & MacierzKw::operator-=(const MacierzKw & M2)
{
    for(int i=0; i<ROZMIAR; i++)
        (*this)[i]-=M2[i];
    return *this;
}
MacierzKw & MacierzKw::operator*=(double l)
{
    for(int i=0; i<ROZMIAR; i++)
        (*this)[i]*=l;
    return *this;
}
Wektor MacierzKw::operator*(const Wektor & W2)
{
    Wektor Wynik;

    for(int i=0; i<ROZMIAR; i++)
        for(int k=0; k<ROZMIAR; k++)
            Wynik[i]+=(*this)(i,k)*W2[i];
    return Wynik;
}

//================================================================================

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
