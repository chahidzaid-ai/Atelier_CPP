#include <iostream>
#include <cmath>

using namespace std;

class vecteur3d {
public:
    float x, y, z;

    // 1. Constructeur
    vecteur3d(float x_val = 0.0f, float y_val = 0.0f, float z_val = 0.0f)
        : x(x_val), y(y_val), z(z_val) {}

    // 2. Fonction d'affichage
    void affiche() const {
        cout << "(" << x << ", " << y << ", " << z << ")";
    }

    // 3. Somme de 2 vecteurs
    vecteur3d somme(const vecteur3d& v) const {
        return vecteur3d(this->x + v.x, this->y + v.y, this->z + v.z);
    }

    // 4. Produit scalaire
    float produit_scalaire(const vecteur3d& v) const {
        return (this->x * v.x) + (this->y * v.y) + (this->z * v.z);
    }

    // 5. Coincidence
    bool coincide(const vecteur3d& v) const {
        return (this->x == v.x) && (this->y == v.y) && (this->z == v.z);
    }

    // 6. Norme
    float norme() const {
        return sqrt(this->produit_scalaire(*this));
    }

    // 7. Normax
    
    // (a) Résultat renvoyé par valeur
    vecteur3d normax_val(const vecteur3d& v) const {
        if (this->norme() >= v.norme()) {
            return *this;
        } else {
            return v;
        }
    }

    // (b) Résultat renvoyé par adresse, argument par adresse
    vecteur3d* normax_ptr(vecteur3d* v) {
        if (this->norme() >= v->norme()) {
            return this;
        } else {
            return v;
        }
    }

    // (c) Résultat renvoyé par référence, argument par référence
    vecteur3d& normax_ref(vecteur3d& v) {
        if (this->norme() >= v.norme()) {
            return *this;
        } else {
            return v;
        }
    }
};

int main() {
    cout << "--- Demonstration de la classe vecteur3d ---" << endl;

    vecteur3d v1(1.0f, 2.0f, 2.0f); 
    vecteur3d v2(3.0f, 4.0f, 0.0f); 
    vecteur3d v_zero;

    cout << "Vecteur v1: "; v1.affiche(); cout << " (Norme: " << v1.norme() << ")" << endl;
    cout << "Vecteur v2: "; v2.affiche(); cout << " (Norme: " << v2.norme() << ")" << endl;
    cout << "Vecteur v_zero: "; v_zero.affiche(); cout << endl;

    cout << "\n--- Tests des fonctions ---" << endl;

    vecteur3d v_somme = v1.somme(v2);
    cout << "Somme v1 + v2: "; v_somme.affiche(); cout << endl;

    float ps = v1.produit_scalaire(v2);
    cout << "Produit scalaire v1 . v2: " << ps << endl;

    vecteur3d v1_bis(1.0f, 2.0f, 2.0f);
    cout << "v1 coincide avec v2 ? " << (v1.coincide(v2) ? "Oui" : "Non") << endl;
    
    cout << "\n--- Tests Normax  ---" << endl;

    vecteur3d v_max_val = v1.normax_val(v2);
    cout << "Normax (valeur): "; v_max_val.affiche(); cout << endl;
    
   
    cout << "\nNormax (pointeur):" << endl;
    vecteur3d* p_max = v1.normax_ptr(&v2);
    cout << "  -> Vecteur max (via ptr): "; p_max->affiche(); cout << endl;

    
   
    cout << "\nNormax (reference):" << endl;
    vecteur3d& ref_max = v1.normax_ref(v2);
    cout << "  -> Vecteur max (via ref): "; ref_max.affiche(); cout << endl;
    
    
    return 0;
}