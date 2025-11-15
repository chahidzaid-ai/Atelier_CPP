#include<iostream>

using namespace std;

template <typename T>

T carre(T valeur){
    return valeur*valeur;
}
int main(){
    int a = 7;
    cout<<"carre de "<< a<<" est "<< carre(a)<<endl;

    float b = 2;
    cout<<"carre de "<< b <<" est "<< carre(b)<<endl;

    return 0;
}