#include<iostream>

using namespace std;

struct element{
    int i ;
    element*next;
};
class Liste{
    private :

     element* head;

    public :
    Liste() : head(nullptr){}
    ~Liste(){
        while (head != nullptr)
        supprimer();
    }
    void ajouter(int val ){
        element*nouveau = new element ;
        nouveau->i = val;
        nouveau->next = head;
        head = nouveau;
    }
    void supprimer(){
        if (head != nullptr){
            element* temp = head;
            head = head-> next;
            delete temp;
        }
    }
    void afficher(){
        element* courant = head;
        while (courant != nullptr)
        {
            cout << courant->next <<"->";
            courant = courant->next;
        }
        cout << " NULL"<<endl;
        
    }
};
int main() {
    Liste maListe;

    maListe.ajouter(10);
    maListe.ajouter(20);
    maListe.ajouter(30);

    cout << "Contenu de la liste : ";
    maListe.afficher();

    maListe.supprimer();
    cout << "Apres suppression : ";
    maListe.afficher();

    return 0;
}