#include<iostream>
using namespace std;

int main(){
    int tab[10];
    int i,max,min;

    cout<< "donner 10 entiers:"<< endl;
    for(i=0 ; i<10 ; i++){
        cout<<"nombre"<<i+1<<":";
        cin>> tab[i];
    }
    max = tab[0];
    min = tab[0];

    for(i=0;i<10;i++){
        if (tab[i]>max)
        max = tab[i];
        if (tab[i]<min)
        min = tab[i];
    }
    cout<<"le maximum est :"<< max << endl;
    cout<<"le minimum est :"<< min << endl; 
    return 0;
}
