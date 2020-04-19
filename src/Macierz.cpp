#ifndef MACIERZ_CPP
#define MACIERZ_CPP

#include <cassert>
#include "Macierz.hh"

template<unsigned int Rozmiar>
MacierzKw<Rozmiar>::MacierzKw()
{
    for(Wektor<Rozmiar> &ElemTab : Tab)
        ElemTab=Wektor<Rozmiar>();
}
template<unsigned int Rozmiar>
MacierzKw<Rozmiar>::MacierzKw(const Wektor<Rozmiar> tablica[])
{
    for(unsigned int i=0; i<Rozmiar; i++)
        this->Tab[i]=tablica[i];
}
template<unsigned int Rozmiar>
MacierzKw<Rozmiar>::MacierzKw(Wektor<Rozmiar> A, Wektor<Rozmiar> B, Wektor<Rozmiar> C)
{
    this->Tab[0] = A;
    this->Tab[1] = B;
    this->Tab[2] = C;
}
template<unsigned int Rozmiar>
double MacierzKw<Rozmiar>::wyznacznikSarrus() //tylko dla 3x3
{
    assert(Rozmiar==3);
    double Wynik;

    return Wynik=(*this)(0,0) * (*this)(1,1) * (*this)(2,2)
                +(*this)(0,1) * (*this)(1,2) * (*this)(2,0)
                +(*this)(0,2) * (*this)(1,0) * (*this)(2,1)

                -(*this)(2,0) * (*this)(1,1) * (*this)(0,2)
                -(*this)(2,1) * (*this)(1,2) * (*this)(0,0)
                -(*this)(2,2) * (*this)(1,0) * (*this)(0,1);


}

template<unsigned int Rozmiar>
double MacierzKw<Rozmiar>::wyznacznikLaplace()
{
    return 0; //nie działa bo nie działa rekurencja Proba implementacji na dole w komentarzu
}

template<unsigned int Rozmiar>
double MacierzKw<Rozmiar>::wyznacznikGauss()
{
    double det = 1;

    for (unsigned int i = 0; i < Rozmiar; ++i) {

        double pivotElement = (*this)[i][i];
        unsigned int pivotRow = i;
        for (unsigned int row = i + 1; row < Rozmiar; ++row) {
            if (std::abs((*this)[row][i]) > std::abs(pivotElement)) {
                pivotElement = (*this)[row][i];
                pivotRow = row;
            }
        }
        if (pivotElement == 0.0) {
            return 0.0;
        }
        if (pivotRow != i) {
            std::swap((*this)[i],(*this)[pivotRow]);
            det *= -1.0;
        }
        det *= pivotElement;

        for (unsigned int row = i + 1; row < Rozmiar; ++row) {
            for (unsigned int col = i + 1; col < Rozmiar; ++col) {
                (*this)[row][col] -= (*this)[row][i] * (*this)[i][col] / pivotElement;
            }
        }
    }

    return det;
}

template<unsigned int Rozmiar>
double MacierzKw<Rozmiar>::wyznacznik(metoda met)
{
    switch(met)
    {
    case LAPLACE:
    {
        return this->wyznacznikLaplace();
        break;
    }
    case GAUSS:
    {
        return this->wyznacznikGauss();
        break;
    }
    case SARRUS:
    {
        return this->wyznacznikSarrus();
        break;
    }
    default:
    {
    return 0;
    break;
    }
    }
}

template<unsigned int Rozmiar>
const MacierzKw<Rozmiar> MacierzKw<Rozmiar>::transponowana() const
{
    MacierzKw<Rozmiar> Temp=(*this);

    Temp.transponuj();

    return Temp;
}

template<unsigned int Rozmiar>
void MacierzKw<Rozmiar>::transponuj()
{
    MacierzKw<Rozmiar> Temp=(*this);

    for(unsigned int i=0; i<Rozmiar; i++)
        for(unsigned int j=0; j<Rozmiar; j++)
            (*this)(j,i)=Temp(i,j);

}

template<unsigned int Rozmiar>
MacierzKw<Rozmiar> & MacierzKw<Rozmiar>::operator*=(const MacierzKw<Rozmiar> & M2)
{
    MacierzKw<Rozmiar> Temp;
    for(unsigned int i=0; i<Rozmiar; i++)
        for(unsigned int j=0; j<Rozmiar; j++)
            for(unsigned int k=0; k<Rozmiar; k++)
                Temp(i,j)+=(*this)(i,k)*M2(k,j);
    *this=Temp;
    return *this;
}

template<unsigned int Rozmiar>
MacierzKw<Rozmiar> & MacierzKw<Rozmiar>::operator+=(const MacierzKw<Rozmiar> & M2)
{
    for(unsigned int i=0; i<Rozmiar; i++)
        (*this)[i]+=M2[i];
    return *this;
}

template<unsigned int Rozmiar>
MacierzKw<Rozmiar> & MacierzKw<Rozmiar>::operator-=(const MacierzKw<Rozmiar> & M2)
{
    for(unsigned int i=0; i<Rozmiar; i++)
        (*this)[i]-=M2[i];
    return *this;
}

template<unsigned int Rozmiar>
MacierzKw<Rozmiar> & MacierzKw<Rozmiar>::operator*=(double l)
{
    for(unsigned int i=0; i<Rozmiar; i++)
        (*this)[i]*=l;
    return *this;
}

template<unsigned int Rozmiar>
Wektor<Rozmiar> MacierzKw<Rozmiar>::operator*(const Wektor<Rozmiar> & W2)
{
    Wektor<Rozmiar> Wynik;

    for(unsigned int i=0; i<Rozmiar; i++)
        for(unsigned int k=0; k<Rozmiar; k++)
            Wynik[i]+=(*this)(i,k)*W2[i];
    return Wynik;
}

//================================================================================

template<unsigned int Rozmiar>
std::istream& operator >> (std::istream &Strm, MacierzKw<Rozmiar> &Mac)
{
    for(unsigned int i=0; i<Rozmiar; i++)
    {
        for(unsigned int j=0; j<Rozmiar; j++)
        {
            Strm >> Mac[j][i];
        }
    }
    return Strm;
}

template<unsigned int Rozmiar>
std::ostream& operator << (std::ostream &Strm, const MacierzKw<Rozmiar> &Mac)
{
    for(unsigned int i=0; i<Rozmiar; i++)
    {
        for(unsigned int j=0; j<Rozmiar; j++)
        {
            Strm << Mac[j][i] << "\t";
        }
        Strm << "\n";
    }
    return Strm;
}

#endif // MACIERZ_CPP
/*

template<unsigned int Rozmiar>
double MacierzKw<Rozmiar>::wyznacznikLaplace()
{
    double Wynik=0;
    double m=1;
    unsigned int k;

    if(Rozmiar>6)
    {
        std::cerr << "Nie obslugiwana wielkosc" << std::endl;
        return 0;
    }

    MacierzKw<Rozmiar-1> Temp;

    if(Rozmiar==1)
        return (*this)(0,0);
    else if(Rozmiar>=2)
    {

        for(unsigned int i=0; i<Rozmiar; ++i)
        {
            k=0;
            for(unsigned int j=0; j<(Rozmiar-1); ++j)
            {
                if(k==i) k++;
                for(unsigned int l=0; l<(Rozmiar-1); ++l)
                    Temp(l,j)=(*this)(l,k++);
            }

            Wynik+=m*(*this)(0, i)*Temp.wyznacznikLaplace();
            m*=(-1);
        }

    }
    return Wynik;
}

*/
