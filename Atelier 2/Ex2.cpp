#include<iostream>
using namespace std;

int multiple2(int x){
    return (x % 2 ==0);
}
int multiple3(int x){
    return(x % 3 ==0);
}

int main(){
    int x;
    cout<<"donnez un entier :"<< endl;
    cin>> x;

    if(multiple2(x)){
        cout<< "il est pair"<< endl; 
    }

    if(multiple3(x)){
        cout<< "il est multiple de 3"<<endl;
    }

    if (multiple2(x) && multiple3(x)){
        cout<< "il est divisible par 6"<< endl;
    }

    return 0;
}