#include<iostream>
using namespace std;


void remplir(int* arr, int n){
    for(int i=0 ; i< n ; i++){ 
        cout << "arr[" << i << "] = ";
        cin >> *(arr + i);
    }
}
void afficher(const int* arr, int n){
    cout<< "[";
    for(int i=0 ; i<n ; i++ ){
        cout<< *(arr + i)<< " ";
    }
    cout<<"]"<<endl;

}

int& trouverMax (int* arr, int n){
    int* max = arr;
    for(int i=1 ; i<n ; i++){
        if(*(arr + i) > *max){
            max = (arr + i);
        }
    }
    return *max;
}
void inverser(int* arr, int n){ // inversion sans tablleau
    for( int i=0 ; i<n/2 ; i++){
        int* left = arr + i;
        int* right = arr + n - 1 - i;
        int tmp = *left;
        *left = *right;
        *right = tmp;
    }
}
void inverser2(int* arr, int n){// inversion avec tableau temporaire
    int *temp = new int[n];
    for( int i = 0 ; i<n ; i++)
        *(temp + i) = *(arr + n - 1 - i );

    for( int i = 0 ; i<n ; i++)
    *(arr + i)=*(temp+i);
    delete[] temp;

}
int main(){
    cout<< "donner la taille de tableau :";
    int n ;
    cin>> n;
    int* arr = new int[n];

    remplir(arr, n);
    cout<<" le tableau est :";
    afficher(arr, n);

    int& max = trouverMax(arr, n);
    cout<<" le max est :"<<max<<endl;
    cout<<"choisir une nouvelle valeur pou le max :";
    cin>> max;
    cout<<" le tableau apres modification est :";
    afficher(arr, n);

    inverser(arr, n);// inversion sans tableau 
    cout<<" le tableau apres inversion est :";
    afficher(arr, n);
     
    inverser2(arr, n); // inversion avec tableau 
    cout<<" le tableau apres inversion avec tableau temporaire est :";  
    afficher(arr, n);   
     
    delete[] arr;// liberation de memoire
    return 0;
}