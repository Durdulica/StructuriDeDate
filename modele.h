#ifndef MODELE_H
#define MODELE_H
#include <iostream>
#include <cstring>
using namespace std;

struct Persoana {
    //proprietati
    char nume[20];
    char prenume[20];
    int inaltime;
    int varsta;
    int greutate;
    //metode

    void afisare() {

        cout << "Nume: " << nume << endl;
        cout << "Prenume: " << prenume << endl;
        cout << "inaltime: " << inaltime << endl;
        cout << "Varsta: " << varsta << endl;
        cout << "Greutate: " << greutate << endl << endl;
    }
};

struct Node {
    Node* next;
    Persoana data;
    int number;
};
#endif //MODELE_H
