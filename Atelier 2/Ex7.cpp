#include<iostream>
using namespace std;

void permutation(char chaine[],int start , int end){
    if(start == end ){
        cout<< chaine <<endl;
    }else{
        for(int i = start ; i<= end ; i++){
            char temp = chaine[start];
            chaine[start] = chaine[i];
            chaine[i] = temp;
            permutation(chaine , start+1 , end);

            temp = chaine[start];
            chaine[start] = chaine[i];
            chaine[i] = temp;
        }
    }
}
int main(){
    char chaine[] = "ZAID";
    int n = 0 ;
    while (chaine[n] !='\0')
    {
        n++;
    }
    cout<<"Les permutations de la chaine "<< chaine <<" sont : "<< endl;
    permutation(chaine , 0 , n-1);
    return 0;
}