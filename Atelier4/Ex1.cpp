#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Ressource {
private:
    int id;
    string titre;
    string auteur;
    int annee;

public:
    Ressource(int id, string titre, string auteur, int annee)
        : id(id), titre(titre), auteur(auteur), annee(annee) {}

    virtual ~Ressource() {}

    // Getters
    int getId() const { return id; }
    string getTitre() const { return titre; }
    string getAuteur() const { return auteur; }
    int getAnnee() const { return annee; }

    // Méthodes virtuelles
    virtual void afficherInfos() const {
        cout << "ID: " << id << " | Titre: " << titre
             << " | Auteur: " << auteur << " | Annee: " << annee << endl;
    }

    virtual void telecharger() const {
        cout << "Telechargement de la ressource generique..." << endl;
    }

    // Surcharge opérateur ==
    bool operator==(const Ressource &autre) const {
        return id == autre.id;
    }
};

class Telechargeable {
public:
    virtual void telecharger() const {
        cout << "Téléchargement en cours ..." << endl;
    }

    void afficherMessage() const {
        cout << "Cette ressource est telechargeable !" << endl;
    }

    virtual ~Telechargeable() {}
};

class Livre : public Ressource, public Telechargeable {
private:
    int nbPages;

public:
    Livre(int id, string titre, string auteur, int annee, int nbPages)
        : Ressource(id, titre, auteur, annee), nbPages(nbPages) {}

    void afficherInfos() const override {
        Ressource::afficherInfos();
        cout << "Type: Livre | Nombre de pages: " << nbPages << endl;
    }

    void telecharger() const override {
        cout << "Telechargement du livre en format PDF..." << endl;
    }
};

// ---- Magazine ----
class Magazine : public Ressource, public Telechargeable {
private:
    int numeroEdition;

public:
    Magazine(int id, string titre, string auteur, int annee, int numeroEdition)
        : Ressource(id, titre, auteur, annee), numeroEdition(numeroEdition) {}

    void afficherInfos() const override {
        Ressource::afficherInfos();
        cout << "Type: Magazine | Numero d'edition: " << numeroEdition << endl;
    }

    void telecharger() const override {
        cout << "Telechargement du magazine en format ePub..." << endl;
    }
};

// ---- Video ----
class Video : public Ressource, public Telechargeable {
private:
    double duree; 

public:
    Video(int id, string titre, string auteur, int annee, double duree)
        : Ressource(id, titre, auteur, annee), duree(duree) {}

    void afficherInfos() const override {
        Ressource::afficherInfos();
        cout << "Type: Video | Duree: " << duree << " min" << endl;
    }

    void telecharger() const override {
        cout << "Telechargement de la video en format MP4..." << endl;
    }
};

class Mediatheque {
private:
    vector<Ressource*> ressources;

public:
    ~Mediatheque() {
        for (auto r : ressources)
            delete r;
    }

    void ajouterRessource(Ressource* r) {
        ressources.push_back(r);
    }

    void afficherToutes() const {
        cout << "\n--- Liste des ressources ---" << endl;
        for (auto r : ressources) {
            r->afficherInfos();
            cout << "-----------------------------" << endl;
        }
    }

    // Surcharge de recherche
    Ressource* rechercher(const string& titre) const {
        for (auto r : ressources)
            if (r->getTitre() == titre)
                return r;
        return nullptr;
    }

    Ressource* rechercher(int annee) const {
        for (auto r : ressources)
            if (r->getAnnee() == annee)
                return r;
        return nullptr;
    }

    Ressource* rechercher(const string& auteur, int annee) const {
        for (auto r : ressources)
            if (r->getAuteur() == auteur && r->getAnnee() == annee)
                return r;
        return nullptr;
    }
};

int main() {
    Mediatheque med;

    // Création des ressources
    Livre* l1 = new Livre(1, "la boite a merveille", "Ahmed sefrioui", 1954, 184);
    Magazine* m1 = new Magazine(2, "Harry Potter", "J.K. Rowling", 1997, 380);
    Video* v1 = new Video(3, "Inception", "Christopher Nolan", 2010, 148.0);  

    // Ajout à la mediatheque
    med.ajouterRessource(l1);
    med.ajouterRessource(m1);
    med.ajouterRessource(v1);

    // Affichage de toutes les ressources
    med.afficherToutes();

    // Test de téléchargement
    cout << "\n--- Test de telechargement ---" << endl;
    l1->Telechargeable::afficherMessage(); 
    l1->telecharger();                     

    // Test de comparaison
    Livre l2(1, "Autre Livre", "Auteur Different", 2000, 150);
    cout << "\n--- Test de comparaison ---" << endl;
    if (*l1 == l2)
        cout << "Les deux ressources ont le meme ID !" << endl;
    else
        cout << "Les ressources sont differentes." << endl;

    // Test de recherche
    cout << "\n--- Test de recherche ---" << endl;
    Ressource* resultat = med.rechercher("Inception");
    if (resultat) {
        cout << "Ressource trouvee : ";
        resultat->afficherInfos();
    } else {
        cout << "Ressource non trouvee." << endl;
    }

    return 0;
}
