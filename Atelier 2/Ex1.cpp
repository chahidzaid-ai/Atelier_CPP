#include <iostream>
using namespace std;

void compteurAppels() {
    static int compteur = 0;
    compteur++;
    cout << "nombre d'appel :" << compteur << endl;
}

int main() {
    compteurAppels();
    compteurAppels();
    compteurAppels();
    compteurAppels();

    return 0;
}