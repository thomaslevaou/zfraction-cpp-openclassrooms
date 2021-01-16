#ifndef DEF_ZFRACTION
#define DEF_ZFRACTION

#include <iostream>

class ZFraction
{
    public:
      ZFraction();
      ZFraction(int numerateur, int denominateur = 1); // Avec simplification
      void afficher(std::ostream &flux) const; // Pour afficher avec <<
      bool estEgal(ZFraction const& a) const;
      bool estPlusPetitQue(ZFraction const& a) const;
      ZFraction& operator+=(ZFraction const& a);
      ZFraction& operator*=(ZFraction const& a);

    private:
      int m_numerateur;
      int m_denominateur;
};

int valeurAbsolue(int a);
int minimum(int a, int b);
int calculePgcd(int a, int b);
bool operator==(ZFraction const& a, ZFraction const& b);
bool operator!=(ZFraction const& a, ZFraction const& b);
bool operator<(ZFraction const &a, ZFraction const& b);
bool operator>(ZFraction const &a, ZFraction const& b);
ZFraction operator+(ZFraction const& a, ZFraction const& b);
ZFraction operator*(ZFraction const& a, ZFraction const& b);
std::ostream& operator<<(std::ostream &flux, ZFraction const& duree);

#endif
