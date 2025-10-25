#include <iostream>

using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex() : real(0), imag(0) {}
    Complex(double r, double i) : real(r), imag(i) {}

    void lire() {
        cout << "  Partie reelle : ";
        cin >> real;
        cout << "  Partie imaginaire : ";
        cin >> imag;
    }

    void afficher() const {
        cout << "Resultat : " << real;
        if (imag >= 0) {
            cout << " + " << imag << "i" << endl;
        } else {
            cout << " - " << -imag << "i" << endl;
        }
    }

    double getReal() const { return real; }
    double getImag() const { return imag; }

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) const {
        double r = real * other.real - imag * other.imag;
        double i = real * other.imag + imag * other.real;
        return Complex(r, i);
    }

    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        if (denominator == 0) {
            cout << "Erreur : Division par zero !" << endl;
            return Complex(); 
        }
        double r = (real * other.real + imag * other.imag) / denominator;
        double i = (imag * other.real - real * other.imag) / denominator;
        return Complex(r, i);
    }

    bool operator==(const Complex& other) const {
        return (real == other.real) && (imag == other.imag);
    }
};

int main() {
    Complex c1, c2, resultat;
    int choix;

    cout << "Entrez le premier nombre complexe (c1) :" << endl;
    c1.lire();
    cout << "\nEntrez le deuxieme nombre complexe (c2) :" << endl;
    c2.lire();

    do {
        cout << "\n--- Menu des Operations ---" << endl;
        cout << "1. Addition (c1 + c2)" << endl;
        cout << "2. Soustraction (c1 - c2)" << endl;
        cout << "3. Multiplication (c1 * c2)" << endl;
        cout << "4. Division (c1 / c2)" << endl;
        cout << "5. Egalite (c1 == c2)" << endl;
        cout << "6. Quitter" << endl;
        cout << "Votre choix : ";
        cin >> choix;

        switch (choix) {
            case 1:
                resultat = c1 + c2;
                resultat.afficher();
                break;
            case 2:
                resultat = c1 - c2;
                resultat.afficher();
                break;
            case 3:
                resultat = c1 * c2;
                resultat.afficher();
                break;
            case 4:
                resultat = c1 / c2;
                resultat.afficher();
                break;
            case 5:
                if (c1 == c2) {
                    cout << "Resultat : Les nombres sont egaux." << endl;
                } else {
                    cout << "Resultat : Les nombres ne sont pas egaux." << endl;
                }
                break;
            case 6:
                cout << "Au revoir !" << endl;
                break;
            default:
                cout << "Choix invalide. Veuillez reessayer." << endl;
        }
    } while (choix != 6);

    return 0;
}