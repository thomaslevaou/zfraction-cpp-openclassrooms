# TP de la ZFraction du cours en ligne OpenClassrooms

TP de la "ZFraction", réalisé dans le cadre de la formation en C++ proposée par le
site OpenClassrooms, à l'adresse suivante : https://openclassrooms.com/fr/courses/1894236-programmez-avec-le-langage-c/1898069-tp-la-poo-en-pratique-avec-zfraction

A l'exécution du programme dans une fenêtre de commande, le résultat suivant est affiché :
```
2/-5 + 2/1 = -8/-5
2/-5 * 2/1 = 4/-5
a est plus grand que b.
```
Pour afficher ce résultat, le code crée des instances d'une classe intitulée "ZFraction",
qui permet de calculer des fractions selon les règles standard de calcul des fractions.
Chaque fraction est automatiquement simplifiée à partir d'un calcul de PGCD.

Après avoir cloné ce projet, le programme peut être exécuté en entrant les commandes suivantes
à sa racine (le compilateur g++ doit être installé):
```
make
./resultat
```
