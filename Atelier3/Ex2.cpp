#include <iostream>

using namespace std;

class Fichier{
    private:
       char* P;//pointeur vers la zone memoire
       int longueur;//taille en octets
    public:
         //constracteur
    Fichier() : P(nullptr) , longueur(0){
        cout<< "constarcteur : Fichier cree."<< endl;
    }

    void creation(int taille){//methode creation
        longueur = taille;
        P=new char [longueur];
        cout<<"Memoire de "<< longueur << " octets allouee"<<endl;
    }

    void remplit(){//methode remplit
        if(P == nullptr){
            cout<<"Erreur : memoire non allouee !"<<endl;
            return;
        }
        for (int i = 0; i< longueur; i++)// remplissage arbitraire de la memoire
        P[i] = 'A'+ (i % 26);
        cout<<"Memoire remplie avec des valeur arbitraires."<<endl;
    }
    void Affiche()const{ //methode Affiche
        if (P == nullptr)
        {
            cout<<" Erreur : Memoire vide!"<<endl;
           return;
        }
        cout << "contenu memoire:"<<endl;
        for(int i = 0;i<longueur; i++)
           cout << P[i]<<endl;
    }
    //Destructeur
    ~Fichier(){
        delete[] P; // liberation de memoire
        cout << "Destracteur : Memoire liberee."<<endl;
    }
};

int main(){

    Fichier*fichier = new Fichier();

    fichier->creation(26);
    fichier->remplit();
    fichier->Affiche();

    delete fichier;

    return 0;
}