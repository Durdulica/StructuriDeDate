#ifndef LISTA_H
#define LISTA_H
#include "modele.h"

/*struct List {
    Node *head = NULL;

    Node* addHead(Persoana persoana) {
        Node *node = new Node();
        node->data = persoana;
        if (head == NULL) {
            head = node;
        } else {
            node->next = head;
            head = node;
        }
        return node;
    }

    Node* addTail(Persoana persoana) {
        Node *node = new Node();
        node->data = persoana;
        Node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
        node->next = NULL;
        return node;
    }

    //todo: addPosition(Persoana ,int)

    Node* addPosition(Persoana persoana, int index) {
        if(index == 0) {
            addHead(persoana);
        }

        Node *node = new Node();
        node->data = persoana;
        Node *current = head;
        int position = 0;

        while(current != NULL) {
            if (position + 1  == index) {
                node->next = current->next;
                current->next = node;
                return node;
            }
            position++;
            current = current->next;
        }
        return node;
    }

    //todo: removePosition(int)

    Node* removeFirst() {
        Node *current = head;
        head = head->next;
        delete current;
        return current;
    }

    Node* removeLast() {
        Node *current = head;
        while (current->next->next != NULL) {
            current = current->next;
        }
        Node *temp = current->next;
        current->next = NULL;
        delete temp;
        return current;
    }

    Node* removePosition(int index) {

        if(index == 0) {
            return removeFirst();
        }

        Node *current = head;
        int position = 0;

        while(current != NULL) {
            if (position + 1 == index) {
                Node *node = current->next;
                current->next = current->next->next;
                delete node;
                return current;
            }
            current = current->next;
            position++;
        }

        return current;
    }
};*/

struct nrList {
    Node *head=nullptr;

    Node *addHead(int number) {
        Node *node = new Node();
        node->number = number;
        node->next = nullptr;
        if (head == nullptr) {
            head = node;
        } else {
            node->next = head;
            head = node;
        }

        return node;
    }

    Node *addTail(int number) {
        Node *current = head;
        Node *node = new Node();
        node->number = number;

        if (head == nullptr) {
            addHead(number);
            return node;
        }

        while(current->next != NULL) {
            current = current->next;
        }
        current->next = node;
        node->next = NULL;
        return node;
    }

    void afisare() {
        Node *current = head;
        while(current != NULL) {
            cout << current->number << " ";
            current = current->next;
        }
        cout << endl;
    }

    int ctNrPare() {
        int ctNr = 0;
        Node *current = head;
        while(current != NULL) {
            if(current->number % 2 == 0) {
                ctNr++;
            }
            current = current-> next;
        }
        return ctNr;
    }

    int ctNrImpare() {
        int ctNr = 0;
        Node *current = head;
        while(current != NULL) {
            if(current->number % 2 != 0) {
                ctNr++;
            }
            current = current-> next;
        }
        return ctNr;
    }

    int difPareImpare() {
        int par = ctNrPare();
        int imp = ctNrImpare();
        if (par > imp) {
            return par - imp;
        }
        return imp - par;
    }

    //todo: sa se stearga al k-lea elem. prim

    bool isPrim(Node *node) {
        for(int i = 2; i <= node->number/2; i++)
            if(node->number % i == 0) return false;
        return true;
    }

    Node *removeFirst() {
        Node *current = head;
        head = head->next;
        delete current;
        return current;
    }

    Node *removePosition(int index) {
        if(index == 0) return removeFirst();

        Node *current = head;
        int position = 0;

        while(current->next != nullptr) {
            if(position + 1 == index) {
                Node *temp = current->next;
                current->next = current->next->next;
                delete temp;
                return current;
            }
            current = current->next;
            position++;
        }

        return current;
    }

    Node *elimXPrim(int count) {
        int ind = 0, counter = 0;
        Node *current = head;

        while(current != nullptr) {
            if(isPrim(current)) {
                ind++;
                if(ind == count) {
                    removePosition(counter);
                    return current;
                }
            }
            current = current->next;
            counter++;
        }
        return current;
    }

    //todo:sa se stearga toate elem. cu prima cif. = cu ultima cif.

    int oglindit(int nr) {
        int o = 0;
        while(nr) {
            o = nr % 10 + o * 10;
            nr /= 10;
        }
        return o;
    }

    int elimPrimUltim() {
        Node *current = head;
        int counter = 0;
        while(current != NULL) {
            if(current->number % 10 == oglindit(current->number) % 10) {
                removePosition(counter);
                return 1;
            }
            current = current->next;
            counter++;
        }
        return 0;
    }

    //todo:sa se stearga nodurile cu 0 din lista

    int elim0() {
        Node *current = head;
        int counter = 0;

        while(current != NULL) {
            if(current->number % 10 == 0) {
                removePosition(counter);
                return 1;
            }
            current = current->next;
            counter++;
        }
        return 0;
    }

    //se citesc 2 nr. a si b todo:sa se stearga toate nr. din intervalul [a,b]

    int elimIntervalAsiB(int&low, int&high, int&ct) {
        if(low > high) swap(low, high);
        Node *current = head;
        int counter = 0;

        while(current != NULL) {
            if(counter >= low && counter <= high && ct <= high - low) {
                removePosition(counter);
                ct++;
                return 1;
            }
            current = current->next;
            counter++;
        }
        return 0;
    }

    void elimerIntervalAsiB(int low, int high) {
        int ct  = 0;
        while(elimIntervalAsiB(low,high,ct)) {
            elimIntervalAsiB(low,high,ct);
        }
    }

    //todo: sa se stearga toate elem. ce au cif. din mij patr. perf.

    bool ePatrPerf(int nr) {
        for(int i = 2; i <= nr/2; i++){}
    }
};
#endif //LISTA_H