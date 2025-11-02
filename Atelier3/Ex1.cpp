#include<iostream>
#include<vector>

using namespace std;
        
class Pile{
    private:
     vector<int> elements ;
    public:
        Pile () {}
// Method to add an element to the pile
       void push(int element){
        elements.push_back(element);
       }
       //Method to remove and return the top element of the pile
 int pop(){
    if(!elements.empty()) {
       int element = elements.back();
       elements.pop_back();
       return element;
    }
    else { 
       cout << "Erreur : pile vide." << endl;
       return -1;
    }      
}
// Method to display the elements of the pile
void afficher() {
        cout << "Pile: ";
        for (size_t i = 0; i < elements.size(); ++i) {
            cout << elements[i] << " ";
        }
        cout << endl;
    }
    };
    
int main() {
    Pile p1, p2;

    // Empiler des éléments sur p1
    p1.push(5);
    p1.push(14);
    
    // Empiler des éléments sur p2
    p2.push(1);
    p2.push(18);

    // Afficher les piles
    cout << "Avant le depilage :" << endl;
    p1.afficher();
    p2.afficher();

    // Depiler et afficher les valeurs retirées
    cout << "Depilage de p1: " << p1.pop() << endl; // 30
    cout << "Depilage de p1: " << p1.pop() << endl; // 20

    cout << "Depilage de p2: " << p2.pop() << endl; // 15

    // Afficher les piles après depilage
    cout << "Apres le depilage :" << endl;
    p1.afficher();
    p2.afficher();

    return 0;
}  
