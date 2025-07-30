#ifndef EXERCITIICUALOCARE_H
#define EXERCITIICUALOCARE_H
#include <iostream>
using namespace std;

///BASIC
/*int main() {
     //Alocarea unui singur elem.
     int *ptr = new int;
     *ptr = 42;
     cout << "Valoarea: " << *ptr << endl;
     delete ptr;

     //Alocarea cu initializare
     int *ptr2 = new int(100);
     cout << "Valoarea initializata: " << *ptr2 << endl;
     delete ptr2;

     //Alocarea cu array
     int n;
     cin >> n;

     int *arr = new int[n];

     for (int i = 0; i < n; i++) {
         arr[i] = i;
         cout << "arr[" << i << "] = " << arr[i] << endl;
     }

     delete[] arr;

    //Alocarea unei matrici

    int*  * mat = new int*[3];   //vector de 3 pointeri

    mat[0] = new int[4];

    mat[1] = new int[2];

    mat[2] = new int[3];


   for(int i=0;i<4;i++) {

       mat[0][i]=i;
   }

    for(int i=0;i<2;i++) {

       mat[1][i]=i-1;

    }

     for(int i=0;i<3;i++) {

        mat[2][i]=i-2;

    }
    cout<<mat[0][0]<<endl;

    delete[] mat;
}*/

//================= Functii de utilitate =================
void afiseaza_vector(const int* arr, int n) {
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";
}

int** aloca_matrice(int rows, int cols, int start = 0, int step = 1) {
    int** m = new int*[rows];
    for (int i = 0; i < rows; ++i) m[i] = new int[cols];
    int val = start;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j, val += step) m[i][j] = val;
    return m;
}

void dealoca_matrice(int** m, int rows) {
    for (int i = 0; i < rows; ++i) delete[] m[i];
    delete[] m;
}

void afiseaza_matrice(int** m, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) cout << m[i][j] << " ";
        cout << "\n";
    }
}

//================= Algoritmi pe vectori =================
void interschimba_elemente(int *arr, int *poz1, int *poz2, int n) {
    if (*poz1 < n && *poz2 < n) {
        int temp = *(arr + *poz1);
        *(arr + *poz1) = *(arr + *poz2);
        *(arr + *poz2) = temp;
    }
}

void gaseste_min_max(int *arr, int n, int **min, int **max) {
    *min = arr;
    *max = arr;
    for (int i = 1; i < n; ++i) {
        if (*(arr + i) < **min) *min = arr + i;
        if (*(arr + i) > **max) *max = arr + i;
    }
}

void roteste_stanga(int *arr, int n, int *k) {
    *k %= n;
    for (int i = 0; i < *k; ++i) {
        int temp = *arr;
        for (int j = 0; j < n - 1; ++j) *(arr + j) = *(arr + j + 1);
        *(arr + n - 1) = temp;
    }
}

void aduna_vectori(int *arr1, int *arr2, int *rezultat, int n) {
    for (int i = 0; i < n; ++i) *(rezultat + i) = *(arr1 + i) + *(arr2 + i);
}

void sorteaza_selectie(int *arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        int *min = arr + i;
        for (int j = i + 1; j < n; ++j)
            if (*(arr + j) < *min) min = arr + j;
        if (min != arr + i) {
            int temp = *(arr + i);
            *(arr + i) = *min;
            *min = temp;
        }
    }
}

int filtreaza_pare(int *sursa, int n, int *destinatie) {
    int *dest_ptr = destinatie;
    for (int i = 0; i < n; ++i)
        if (*(sursa + i) % 2 == 0) *dest_ptr++ = *(sursa + i);
    return dest_ptr - destinatie;
}

void inverseaza_portiune(int *arr, int *start_idx, int *end_idx) {
    int *start = arr + *start_idx;
    int *end   = arr + *end_idx;
    while (start < end) {
        int temp = *start;
        *start   = *end;
        *end     = temp;
        ++start; --end;
    }
}

void calculeaza_statistici(int *arr, int n, double *medie, int *suma, int *minim, int *maxim) {
    *suma = 0;
    *minim = *maxim = *arr;
    for (int i = 0; i < n; ++i) {
        *suma += *(arr + i);
        if (*(arr + i) < *minim) *minim = *(arr + i);
        if (*(arr + i) > *maxim) *maxim = *(arr + i);
    }
    *medie = static_cast<double>(*suma) / n;
}

void interclaseaza(int *arr, int *temp, int stanga, int mijloc, int dreapta) {
    int i = stanga, j = mijloc + 1, k = stanga;
    while (i <= mijloc && j <= dreapta) {
        if (*(arr + i) <= *(arr + j)) *(temp + k++) = *(arr + i++);
        else                           *(temp + k++) = *(arr + j++);
    }
    while (i <= mijloc)  *(temp + k++) = *(arr + i++);
    while (j <= dreapta) *(temp + k++) = *(arr + j++);
    for (i = stanga; i <= dreapta; ++i) *(arr + i) = *(temp + i);
}

int* cautare_binara(int *arr, int n, int *valoare) {
    int *stanga = arr, *dreapta = arr + n - 1;
    while (stanga <= dreapta) {
        int *mijloc = stanga + (dreapta - stanga) / 2;
        if (*mijloc == *valoare) return mijloc;
        if (*mijloc < *valoare)  stanga = mijloc + 1;
        else                     dreapta = mijloc - 1;
    }
    return nullptr;
}

int   elimina_duplicate(int *arr, int n) {
    if (n <= 1) return n;
    int *scrie = arr + 1;
    for (int *cit = arr + 1; cit < arr + n; ++cit) {
        if (*cit != *(cit - 1)) *scrie++ = *cit;
    }
    return scrie - arr;
}

int* partitioneaza(int *arr, int *stanga, int *dreapta) {
    int pivot = *dreapta;
    int *i = stanga - 1;
    for (int *j = stanga; j < dreapta; ++j)
        if (*j <= pivot) {
            ++i; int temp = *i; *i = *j; *j = temp;
        }
    ++i; int temp = *i; *i = *dreapta; *dreapta = temp;
    return i;
}

void aplica_operatie(int *start, int *end, char op, int *valoare) {
    while (start <= end) {
        switch (op) {
            case '+': *start += *valoare; break;
            case '-': *start -= *valoare; break;
            case '*': *start *= *valoare; break;
            case '/': if (*valoare) *start /= *valoare; break;
        }
        ++start;
    }
}

bool este_palindrom(int *arr, int n) {
    int *st = arr, *dr = arr + n - 1;
    while (st < dr) if (*st++ != *dr--) return false;
    return true;
}

void reorganizeaza_par_impar(int *arr, int n) {
    int *st = arr, *dr = arr + n - 1;
    while (st < dr) {
        while (st < dr && *st % 2 == 0) ++st;
        while (st < dr && *dr % 2 == 1) --dr;
        if (st < dr) { int tmp = *st; *st = *dr; *dr = tmp; ++st; --dr; }
    }
}

//================= Exercitii cu alocare dinamica =================
inline void exercitiu1() {
    cout << "\n=== Ex.1: Interschimbare cu new/delete ===\n";
    int n = 6; int* arr = new int[n]{10,20,30,40,50,60};
    int p1 = 1, p2 = 4;
    cout << "Vector initial: "; afiseaza_vector(arr,n); cout << '\n';
    interschimba_elemente(arr,&p1,&p2,n);
    cout << "Dupa interschimbare: "; afiseaza_vector(arr,n); cout << '\n';
    delete[] arr;
}

inline void exercitiu2() {
    cout << "\n=== Ex.2: Min & Max cu new/delete ===\n";
    int n = 7; int* arr = new int[n]{45,12,78,3,56,89,23};
    int *min,*max; gaseste_min_max(arr,n,&min,&max);
    cout << "Min: " << *min << " la poz " << (min-arr) << '\n';
    cout << "Max: " << *max << " la poz " << (max-arr) << '\n';
    delete[] arr;
}

inline void exercitiu3() {
    cout << "\n=== Ex.3: Rotire stanga dinamic ===\n";
    int n=6; int* arr=new int[n]{1,2,3,4,5,6}; int k=2;
    cout << "Initial: "; afiseaza_vector(arr,n); cout << '\n';
    roteste_stanga(arr,n,&k);
    cout << "Dupa rotire: "; afiseaza_vector(arr,n); cout << '\n';
    delete[] arr;
}

inline void exercitiu4() {
    cout << "\n=== Ex.4: Adunare vectori dinamic ===\n";
    int n=5; int* a=new int[n]{1,2,3,4,5}; int* b=new int[n]{10,20,30,40,50}; int* rez=new int[n];
    aduna_vectori(a,b,rez,n);
    cout << "a + b = "; afiseaza_vector(rez,n); cout << '\n';
    delete[] a; delete[] b; delete[] rez;
}

inline void exercitiu5() {
    cout << "\n=== Ex.5: Sortare selectie dinamic ===\n";
    int n=8; int* arr=new int[n]{64,25,12,22,11,90,45,33};
    cout << "Nesortat: "; afiseaza_vector(arr,n); cout << '\n';
    sorteaza_selectie(arr,n);
    cout << "Sortat: "; afiseaza_vector(arr,n); cout << '\n';
    delete[] arr;
}

inline void exercitiu6() {
    cout << "\n=== Ex.6: Filtrare pare dinamic ===\n";
    int n=10; int* arr=new int[n]{1,2,3,4,5,6,7,8,9,10}; int* rez=new int[n];
    int np=filtreaza_pare(arr,n,rez);
    cout << "Pare: "; afiseaza_vector(rez,np); cout << "  (total="<<np<<")\n";
    delete[] arr; delete[] rez;
}

inline void exercitiu7() {
    cout << "\n=== Ex.7: Inversare portiune dinamic ===\n";
    int n=8; int* arr=new int[n]{10,20,30,40,50,60,70,80}; int s=2,e=5;
    cout << "Initial: "; afiseaza_vector(arr,n); cout << '\n';
    inverseaza_portiune(arr,&s,&e);
    cout << "Dupa inversare: "; afiseaza_vector(arr,n); cout << '\n';
    delete[] arr;
}

inline void exercitiu8() {
    cout << "\n=== Ex.8: Statistici dinamic ===\n";
    int n=6; int* arr=new int[n]{15,27,33,41,19,25}; double medie; int suma,minim,maxim;
    calculeaza_statistici(arr,n,&medie,&suma,&minim,&maxim);
    cout << "Suma="<<suma<<" Medie="<<medie<<" Min="<<minim<<" Max="<<maxim<<"\n";
    delete[] arr;
}

inline void exercitiu9() {
    cout << "\n=== Ex.9: Interclasare dinamic ===\n";
    int n=8; int* arr=new int[n]{10,30,50,70,20,40,60,80}; int* temp=new int[n];
    cout << "Initial: "; afiseaza_vector(arr,n); cout << '\n';
    interclaseaza(arr,temp,0,3,7);
    cout << "Interclasat: "; afiseaza_vector(arr,n); cout << '\n';
    delete[] arr; delete[] temp;
}

inline void exercitiu10() {
    cout << "\n=== Ex.10: Cautare binara dinamic ===\n";
    int n=8; int* arr=new int[n]{10,20,30,40,50,60,70,80}; int val=50;
    int* gasit=cautare_binara(arr,n,&val);
    if(gasit) cout << "Valoarea " << val << " gasita la poz " << (gasit-arr) << '\n';
    else      cout << "Valoarea " << val << " nu a fost gasita\n";
    delete[] arr;
}

void exercitiu11() {
    cout << "\n=== Ex.11: Eliminare duplicate dinamic ===\n";
    int n=10; int* arr=new int[n]{1,1,2,2,2,3,4,4,5,5};
    int nou=elimina_duplicate(arr,n);
    cout << "Fara duplicate: "; afiseaza_vector(arr,nou); cout << " (n="<<nou<<")\n";
    delete[] arr;
}

void exercitiu12() {
    cout << "\n=== Ex.12: Partitionare dinamic ===\n";
    int n=8; int* arr=new int[n]{64,25,12,22,11,90,45,33};
    int* pivot=partitioneaza(arr,arr,arr+n-1);
    cout << "Dupa pivot("<<*pivot<<"): "; afiseaza_vector(arr,n); cout << "\nPoz pivot="<<(pivot-arr) << '\n';
    delete[] arr;
}

inline void exercitiu13() {
    cout << "\n=== Ex.13: Operatii pe subvector dinamic ===\n";
    int n=8; int* arr=new int[n]{10,20,30,40,50,60,70,80}; int val=5;
    aplica_operatie(arr+2,arr+5,'+',&val);
    cout << "Rezultat: "; afiseaza_vector(arr,n); cout << '\n';
    delete[] arr;
}

inline void exercitiu14() {
    cout << "\n=== Ex.14: Palindrom dinamic ===\n";
    int v1[7]={1,2,3,4,3,2,1}; int v2[6]={1,2,3,3,2,1}; int v3[5]={1,2,3,4,5};
    cout << "v1 palindrom: " << (este_palindrom(v1,7)?"DA":"NU") << '\n';
    cout << "v2 palindrom: " << (este_palindrom(v2,6)?"DA":"NU") << '\n';
    cout << "v3 palindrom: " << (este_palindrom(v3,5)?"DA":"NU") << '\n';
}

inline void exercitiu15() {
    cout << "\n=== Ex.15: Reorganizare par/impar dinamic ===\n";
    int n=10; int* arr=new int[n]{1,2,3,4,5,6,7,8,9,10};
    reorganizeaza_par_impar(arr,n);
    cout << "Rezultat: "; afiseaza_vector(arr,n); cout << '\n';
    delete[] arr;
}

//================= Exercitiu suplimentar pe matrice =================
int** aduna_matrici(int** a,int** b,int rows,int cols){
    int** c=new int*[rows];
    for(int i=0;i<rows;++i){
        c[i]=new int[cols];
        for(int j=0;j<cols;++j) c[i][j]=a[i][j]+b[i][j];
    }
    return c;
}

void exercitiu16() {
    cout << "\n=== Ex.16: Adunare matrice dinamice ===\n";
    int rows=3,cols=4;
    int** A=aloca_matrice(rows,cols,1);
    int** B=aloca_matrice(rows,cols,10);
    cout << "Matrice A:\n"; afiseaza_matrice(A,rows,cols);
    cout << "Matrice B:\n"; afiseaza_matrice(B,rows,cols);
    int** C=aduna_matrici(A,B,rows,cols);
    cout << "A + B =\n"; afiseaza_matrice(C,rows,cols);
    dealoca_matrice(A,rows); dealoca_matrice(B,rows); dealoca_matrice(C,rows);
}

#endif //EXERCITIICUALOCARE_H
