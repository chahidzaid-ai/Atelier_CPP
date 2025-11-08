#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Client {
private:
    int id;
    string CIN;
    string nom;
public:
    Client(string nom, string CIN, int id)
        : nom(nom), CIN(CIN), id(id) {}

    void afficherInfos() const {
        cout << "Client: " << nom << " | CIN: " << CIN << " | ID: " << id << endl;
    }

    friend class CompteBancaire;
    friend class AgentBancaire;
    friend class Banque;
};

class CompteBancaire {
private:
    int numero;
    double solde;
    int codePIN;
    Client* proprietaire;
public:
    CompteBancaire(int numero, double solde, int codePIN, Client* c)
        : numero(numero), solde(solde), codePIN(codePIN), proprietaire(c) {}

    void deposer(double montant) {
        solde += montant;
    }

    void retirer(double montant) {
        if (montant > solde)
            cout << "Solde insuffisant !" << endl;
        else {
            solde -= montant;
            cout << "Retrait de " << montant << " effectue. Nouveau solde: " << solde << endl;
        }
    }

    void afficherCompte() const {
        cout << "Numero: " << numero << ", Solde: " << solde
             << " | Proprietaire: " << proprietaire->nom << endl;
    }

    friend class AgentBancaire;
    friend class Banque;
};

class AgentBancaire {
private:
    int idAgent;
    string nom;
public:
    AgentBancaire(int id, string nom)
        : idAgent(id), nom(nom) {}

    void consulterCodeSecret(const CompteBancaire& c) const {
        cout << "Agent " << nom << " consulte le code secret du compte #"
             << c.numero << ": " << c.codePIN << endl;
    }

    void transferer(CompteBancaire& source, CompteBancaire& destination, double montant) const {
        if (source.solde >= montant) {
            source.retirer(montant);
            destination.deposer(montant);
            cout << "Transfert de " << montant << " de compte #" << source.numero
                 << " à compte #" << destination.numero << " effectue avec succes." << endl;
        } else {
            cout << "Fonds insuffisants pour le transfert." << endl;
        }
    }
};

class Banque {
private:
    string nomBanque;
    vector<Client*> Clients;
    vector<CompteBancaire*> Comptes;
public:
    Banque(string nom)
        : nomBanque(nom) {}

    void ajouterClient(Client* c) {
        Clients.push_back(c);
    }

    void ajouterCompte(CompteBancaire* c) {
        Comptes.push_back(c);
    }

    void afficherAuditInterne() const {
        cout << "--- Audit Interne de la Banque: " << nomBanque << " ---" << endl;
        for (auto compte : Comptes) {
            cout << "Compte #" << compte->numero
                 << " | Client: " << compte->proprietaire->nom
                 << " | CIN: " << compte->proprietaire->CIN
                 << " | Solde: " << compte->solde
                 << " | Code secret: " << compte->codePIN
                 << endl;
        }
    }
};

int main() {
    Banque banque("Banque CIH");

    Client c1("Hamid", "A1234", 1);
    Client c2("Youssef", "B1234", 2);

    CompteBancaire compte1(1001, 5000.0, 1234, &c1);
    CompteBancaire compte2(1002, 2000.0, 5678, &c2);

    banque.ajouterClient(&c1);
    banque.ajouterClient(&c2);
    banque.ajouterCompte(&compte1);
    banque.ajouterCompte(&compte2);

    AgentBancaire agent(1, "Ryan");

    compte1.deposer(1000);
    compte2.retirer(500);

    agent.transferer(compte1, compte2, 2000);
    agent.consulterCodeSecret(compte2);

    banque.afficherAuditInterne();

    return 0;
}
