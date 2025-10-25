#include<iostream>
using namespace std;

int main() {
    int tab[10];
    int *p;          
    int *fin = tab + 10;  

    cout << "Entrez 10 entiers : " << endl;
    for (p = tab; p < fin; p++) {
        cout << "Nombre " << (p - tab) + 1 << " : ";
        cin >> *p;
    }

    int max = *tab;
    int min = *tab;

    for (p = tab + 1; p < fin; p++) {
        if (*p > max)
            max = *p;
        if (*p < min)
            min = *p;
    }

    cout << "Le max est: " << max << endl;
    cout << "Le min est: " << min << endl;

    return 0;
}