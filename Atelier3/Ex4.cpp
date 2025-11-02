#include <iostream>
#include <string>

using namespace std;

// ==================== Classe Client ====================
class Client {
private:
    int id;
    string nom;
    string prenom;

public:
    // Constructeur par défaut
    Client() : id(0), nom(""), prenom("") {
        cout << "Constructeur par defaut appele" << endl;
    }

    // Constructeur avec paramètres
    Client(int id, string nom, string prenom)
        : id(id), nom(nom), prenom(prenom) {
        cout << "Constructeur avec parametres appele" << endl;
    }

    // Constructeur de copie
    Client(const Client &autre)
        : id(autre.id), nom(autre.nom), prenom(autre.prenom) {
        cout << "Constructeur de copie appele" << endl;
    }

    // Destructeur
    ~Client() {
        cout << "Destructeur appele pour Mr. " << nom << endl;
    }

    // Méthode d'affichage
    void afficher() const {
        cout << "ID: " << id << ", Nom: " << nom << ", Prenom: " << prenom << endl;
    }
};


class Compte {
private:
    int numero;
    float solde;
    Client* client;             
    static int totalcomptes;   

public:
    // Constructeur par défaut
    Compte() : numero(0), solde(0.0f), client(nullptr) {
        totalcomptes++;
        cout << "Constructeur par defaut appele" << endl;
    }

    // Constructeur avec paramètres
    Compte(int numero, float solde, const Client &c)
        : numero(numero), solde(solde) {
        client = new Client(c); // copie profonde
        totalcomptes++;
        cout << "Constructeur avec parametres appele" << endl;
    }

    // Constructeur de copie
    Compte(const Compte &autre)
        : numero(autre.numero), solde(autre.solde) {
        if (autre.client != nullptr)
            client = new Client(*autre.client);
        else
            client = nullptr;
        totalcomptes++;
        cout << "Constructeur de copie appele" << endl;
    }

    // Destructeur
    ~Compte() {
        delete client;
        totalcomptes--;
        cout << "Destructeur appele pour le compte n°" << numero << endl;
    }

    // Méthode d'affichage
    void Afficher() const {
        cout << "Compte [Numero: " << numero
             << ", Solde: " << solde << " €]" << endl;
        if (client)
            client->afficher();
        else
            cout << "Aucun client associe." << endl;
    }

    // Méthode statique pour afficher le total
    static void Totalcomptes() {
        cout << "Nombre total de comptes existants : " << totalcomptes << endl;
    }

    // Accesseurs
    float getSolde() const { return solde; }
    void setSolde(float s) { solde = s; }
};

// Initialisation du membre statique
int Compte::totalcomptes = 0;

// fonction pour calculer l'interet
inline float calculinteret(float solde, float taux) {
    return solde + solde * taux / 100.0f;
}


int main() {
    // Création de plusieurs clients
    Client c1(1, "Subroza", "Yassine");
    Client c2(2, "Zemmerman", "Marc");
    Client c3(3, "Ngo", "Ryan");

    // Création de plusieurs comptes
    Compte compte1(1, 2300.0f, c1);
    Compte compte2(2, 300.0f, c2);
    Compte compte3(3, 1300.0f, c3);

    Compte::Totalcomptes();

    // Copie de compte
    Compte compte4(compte1);
    cout << "\n>>> Copie du compte1 dans compte4 effectuee" << endl;
    Compte::Totalcomptes();

    cout << "\n=== Affichage des comptes ===" << endl;
    compte1.Afficher();
    compte2.Afficher();
    compte3.Afficher();
    compte4.Afficher();

    cout << "\n=== Application des interets ===" << endl;
    float taux = 5.0f; // 5 %
    compte1.setSolde(calculinteret(compte1.getSolde(), taux));
    compte3.setSolde(calculinteret(compte3.getSolde(), taux));

    cout << ">>> Interets appliques (taux = " << taux << "%)" << endl;
    compte1.Afficher();
    compte3.Afficher();

    cout << "\n=== Suppression d'un compte temporaire ===" << endl;
    {
        Compte temp(compte2); // création temporaire
        temp.Afficher();
        Compte::Totalcomptes();
    } // temp est détruit ici

    cout << ">>> Les objets locaux seront detruits à la fin du programme" << endl;

    Compte::Totalcomptes();
    return 0;
}

