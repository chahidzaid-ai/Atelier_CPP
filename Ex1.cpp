#include<iostream>
#include<vector>
#include<set>
#include<list>
#include<string>
using namespace std;

bool rechercher(const set<int>& s, int valeur){
    return s.find(valeur) != s.end();
}

bool rechercherIT(set<int>::iterator debut, set<int>::iterator fin,int valeur){
    for(auto it = debut; it != fin; ++it){
        if(*it == valeur)  return true;
    }
      return false;
}

template<typename IT, typename T>
bool rechercherGen(IT debut, IT fin, const T& valeur){
    for(auto it = debut; it != fin; ++it){
        if(*it == valeur) return true;
    }
    return false;
}

int main(){
    set<int> s;
   for(int i = 1;i<=100; i++){
    s.insert(i);
   } 
   cout<<"search in set:"<< rechercherIT(s.begin(),s.end(),67)<<endl;

vector<string> name = {"Zaid","Youssef", "Anass"};

 cout <<"search in vector<string>:"<<rechercherGen(name.begin(), name.end(),string("Zaid"))<<endl;

 list<int> lst = {10, 20, 30, 40};
    cout << "Search in list<int>: " << rechercherGen(lst.begin(), lst.end(), 20) << endl; 
    
    float tab[] = {1.2f, 2.4f, 3.5f, 4.1f};
    int n = 4;

    cout << "Search in float array: "<< rechercherGen(tab, tab + n, 3.5f) << endl; 
        
    return 0;
}

