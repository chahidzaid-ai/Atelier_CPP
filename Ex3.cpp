#include <iostream>
using namespace std;

class vect {
protected:
    int nelem;  
    int* adr;   

public:
  
    vect(int n) : nelem(n) {
        adr = new int[nelem];
    }

    ~vect() {
        delete[] adr;
    }

  
    int& operator[](int i) {
        return adr[i];
    }
};


class vectok : public vect {
public:
   
    vectok(int n) : vect(n) {}

    
    vectok(const vectok& v) : vect(v.nelem) {
        for(int i = 0; i < nelem; i++)
            adr[i] = v.adr[i];
    }

   
    vectok& operator=(const vectok& v) {
        if(this != &v) {
            if(nelem != v.nelem) {
                delete[] adr;
                nelem = v.nelem;
                adr = new int[nelem];
            }
            for(int i = 0; i < nelem; i++)
                adr[i] = v.adr[i];
        }
        return *this;
    }

   
    int taille() const {
        return nelem;
    }
};


int main() {
    vectok v1(5);

    
    for(int i = 0; i < v1.taille(); i++)
        v1[i] = i * 10;

    vectok v2 = v1;

    v1[0] = 999;

    
    cout << "v1 : ";
    for(int i = 0; i < v1.taille(); i++) cout << v1[i] << " ";
    cout << endl;

    cout << "v2 : ";
    for(int i = 0; i < v2.taille(); i++) cout << v2[i] << " ";
    cout << endl;

    vectok v3(3);
    v3 = v1;

    cout << "v3 (apres affectation) : ";
    for(int i = 0; i < v3.taille(); i++) cout << v3[i] << " ";
    cout << endl;

    return 0;
}
