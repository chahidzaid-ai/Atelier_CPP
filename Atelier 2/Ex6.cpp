#include<iostream>
using namespace std;

void incrementer(int* x){
    (*x)++;
}
void permuter(int*a,int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void incrementer_ref(int& x){
    x++;
}
void permuter_ref(int& a,int& b){
    int temp = a;
    a = b;
    b = temp;
}
int main(){
    int a =5;
    int b = 8;
    cout<< "avant : a="<< a <<", b = "<< b << endl;//avec les pointeurs
    incrementer(&a);
    incrementer(&b);
    permuter(&a,&b);
    cout<< "apres  : a="<< a <<", b = "<< b <<endl;

    a =5; b =8;
    cout<< "avant : a="<< a <<", b = "<< b << endl;//avec les references
    incrementer_ref(a);
    incrementer_ref(b);
    permuter_ref(a,b);
    cout<< "apres  : a="<< a <<", b = "<< b <<endl;
    return 0;
}