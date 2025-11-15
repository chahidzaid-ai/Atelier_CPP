#include<iostream>
#include<exception>
using namespace std;
class test{
    public:
    static int tableau[];
    public:
    static int division(int indice, int diviseur){
         if (indice < 0 || indice >= 10)
            throw out_of_range("Indice hors limites !");

        if (diviseur == 0)
            throw runtime_error("Division par zero !");
        return tableau[indice]/diviseur;
    }
};
int test::tableau[]={17, 12, 15, 38, 29, 157, 89, -22, 0, 5};
 int main(){
    while(true){
        try{
            int x, y;
              cout << "Entrez l'indice de l'entier a diviser : " << endl;
            cin >> x;

            cout << "Entrez le diviseur : " << endl;
            cin >> y;

            cout << "Le resultat de la division est : " << endl;
            cout << test::division(x, y) << endl;
            break;
        }
        catch (exception &e) {
            cout << "Erreur : " << e.what() << endl;
            cout << "Arret du programme." << endl;
            return 1; 
    }
 }
 return 0;
 }