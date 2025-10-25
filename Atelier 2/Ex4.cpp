#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "entrez la taille de tableau:";
    cin>> n;

    int* tab = new int[n];

     cout << "Entrez " << n << " entiers :" << endl;
    for (int i = 0; i < n; i++) {
        cout << "tab[" << i << "] = ";
        cin >> tab[i];
    }
      int* carre = new int[n];
    for (int i = 0; i < n; i++) {
        carre[i] = tab[i] * tab[i];
    }
  delete[] tab;
    tab = nullptr;

      cout << "\nTableau des carres :" << endl;
    for (int i = 0; i < n; i++) {
        cout << "carre[" << i << "] = " << carre[i] << endl;
    }
       delete[] carre;
    carre = nullptr;

    return 0;
}