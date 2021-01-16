#include "ZFraction.h"

using namespace std;

ZFraction::ZFraction(): m_numerateur(0), m_denominateur(1) {}

int valeurAbsolue (int a) {
  if (a < 0)
    return -a;
  return a;
}

int minimum(int a, int b) {
  if (a <= b)
    return a;
  else
    return b;
}

// pgcd de deux nombres relatifs
int calculePgcd(int a, int b) {
  int pgcd = minimum(valeurAbsolue(a), valeurAbsolue(b));
  while ((a%pgcd != 0) || (b%pgcd != 0)) {
    pgcd--;
  }
  return pgcd;
}

ZFraction::ZFraction(int numerateur, int denominateur) {
  // calcul du pgcd pour simplifier la fraction le plus possible
  int pgcd = calculePgcd(numerateur, denominateur);
  m_numerateur = numerateur/pgcd;
  m_denominateur = denominateur/pgcd;
}


void ZFraction::afficher(ostream &flux) const
{
    flux << m_numerateur << "/" << m_denominateur;
}

bool ZFraction::estEgal(ZFraction const& zf) const
{
    return (m_numerateur == zf.m_numerateur && m_denominateur == zf.m_denominateur);
}

// Rappel : pour comparer deux fractions, on multiplie les dénominateurs pour qu'ils soient communs
bool ZFraction::estPlusPetitQue(ZFraction const& zf) const
{
  return (m_numerateur * zf.m_denominateur) < (m_denominateur * zf.m_numerateur);
}

ZFraction& ZFraction::operator+=(ZFraction const& zf)
{

    int numerateurGauche = m_numerateur * zf.m_denominateur;
    int numerateurDroit = m_denominateur * zf.m_numerateur;
    int denominateurCommun = m_denominateur * zf.m_denominateur;
    int sommeNonSimplifiee = numerateurGauche + numerateurDroit;
    int pgcd = calculePgcd(sommeNonSimplifiee, denominateurCommun);
    m_numerateur = sommeNonSimplifiee/pgcd;
    m_denominateur = denominateurCommun/pgcd;

    return *this;
}

ZFraction& ZFraction::operator*=(ZFraction const& zf)
{
    m_numerateur *= zf.m_numerateur;
    m_denominateur *= zf.m_denominateur;
    return *this;
}

ostream& operator<<(ostream &flux, ZFraction const& fraction)
{
    fraction.afficher(flux);
    return flux;
}

bool operator==(ZFraction const& a, ZFraction const& b)
{
    return a.estEgal(b);
}

bool operator!=(ZFraction const& a, ZFraction const& b)
{
    return !(a==b); //On utilise l'opérateur == qu'on a défini précédemment !
}

bool operator<(ZFraction const &a, ZFraction const& b)
{
    return a.estPlusPetitQue(b);
}

bool operator>(ZFraction const &a, ZFraction const& b)
{
    return !(a<b) && !(a==b);
}

ZFraction operator+(ZFraction const& a, ZFraction const& b)
{
    // Une fois que += a été défini, on peut faire un + en utilisant un constructeur de copie et +=
    ZFraction copie(a);
    copie += b;
    return copie;
}

ZFraction operator*(ZFraction const& a, ZFraction const& b)
{
    // Une fois que += a été défini, on peut faire un + en utilisant un constructeur de copie et +=
    ZFraction copie(a);
    copie *= b;
    return copie;
}
