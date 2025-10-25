#include<iostream>
#include<string>
using namespace std;

class Voiture
{
private:
    string marque;
    string modele;
    int annee;
    float kilometrage;
    float vitesse;

   
public:
    
    Voiture(); // Constructeur par défaut
    
    Voiture(string m, string mod, int a, float km, float v);// Constructeur avec paramètres
    
    ~Voiture(); // Destructeur
  
    void accelerer(float valeur);//  Méthode accelerer
   
    void freiner(float valeur); // Méthode freiner
    
    void afficherInfo();// Méthode afficherInfo
   
    void avancer(float distance); //  Méthode avancer
};
Voiture::Voiture():marque("inconnue"), modele("inconnu"), annee(0), kilometrage(0.0f), vitesse(0.0f)
{
    cout << "constracteur par defaut appele"<< endl;
}
Voiture::Voiture(string m, string mod, int a, float km, float v)
    : marque(m), modele(mod), annee(a), kilometrage(km), vitesse(v)
{
    cout << "constracteur avec parametre appele" << endl;
}
void Voiture::accelerer(float valeur)
{
    if(valeur > 0){
    vitesse += valeur;
   
      cout << "La voiture a accelere de " << valeur << " km/h. Vitesse actuelle: " << vitesse << " km/h." << endl;
    }
} 
void Voiture::freiner(float valeur)
{
    if(valeur > 0)
    {
        vitesse -= valeur;
        if (vitesse < 0.0f)
        {
           vitesse = 0.0f;
        }
       cout << "Freinage. Vitesse actuelle : " << vitesse << " km/h" << endl; 
    }
}
void Voiture::afficherInfo()
{
    cout << "\n--- INFO VOITURE ---" << endl;
    cout << "Marque: " << marque << endl;
    cout << "Modèle: " << modele << endl;
    cout << "Année: " << annee << endl;
    cout << "Kilométrage: " << kilometrage << " km" << endl;
    cout << "Vitesse: " << vitesse << " km/h" << endl;
}
void Voiture::avancer(float distance)
{
    if (distance > 0 && vitesse > 0)
    {
      kilometrage += distance;
      cout<< " la voiture a avance de "<< distance << "km"<< endl;
      cout<<" nouveau kilometrage est "<< kilometrage << "km"<<endl;
    }
    else if ( distance > 0 && vitesse<= 0)
    {
        cout<< " la voiture reste immobile. Vitesse nulle"<< endl;
    }
    
}
Voiture::~Voiture() {
    cout << "Destruction de la voiture : " << marque << " " << modele <<endl;
}
 
int main()
{
    Voiture mavoiture("Dacia" , "Duster", 2018, 98320.0f,0.0f);
    mavoiture.afficherInfo();
    mavoiture.accelerer(50.0f);
    mavoiture.avancer(70.0f);
    mavoiture.freiner(25.0f);

    mavoiture.afficherInfo();
    mavoiture.freiner(35.0f);
    mavoiture.avancer(15.0f);

    Voiture voitureParDefaut;
    voitureParDefaut.afficherInfo();

cout << "\nFin du programme main." << endl;

    return 0;
}