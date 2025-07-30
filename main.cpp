#include "List.h"

/*void persoane() {
    Persoana *a = new Persoana();

    a->greutate = 60;
    a->inaltime = 155;
    a->varsta = 15;
    strcpy(a->nume, "Popescu");
    strcpy(a->prenume, "Stefan");

    Persoana *b = new Persoana();

    b->greutate = 30;
    b->inaltime = 107;
    b->varsta = 10;
    strcpy(b->nume, "Ana");
    strcpy(b->prenume, "Maria");

    Persoana *c = new Persoana();

    c->greutate = 45;
    c->inaltime = 145;
    c->varsta = 14;
    strcpy(c->nume, "Barbulescu");
    strcpy(c->prenume, "Sebastian");
}*/

int main() {
    nrList *list = new nrList;

    list->addTail(15);
    list->addTail(115);
    list->addTail(28);
    list->addTail(0);
    list->addTail(7);
    list->addTail(33);
    list->addTail(6);

    list->afisare();


    list->afisare();
}