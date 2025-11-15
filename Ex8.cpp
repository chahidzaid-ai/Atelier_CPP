#include <iostream>
#include <exception>
using namespace std;

class Stack {
private:
    int* data;        
    int capacity;     
    int top;          

    
    Stack& operator=(const Stack&) {
        cerr << "Affectation entre piles interdite !" << endl;
        exit(EXIT_FAILURE);
    }

public:
    
    Stack(int size = 20) : capacity(size), top(-1) {
        if (size <= 0) throw invalid_argument("Taille de pile invalide !");
        data = new int[capacity];
    }

    
    Stack(const Stack& s) : capacity(s.capacity), top(s.top) {
        data = new int[capacity];
        for (int i = 0; i <= top; ++i)
            data[i] = s.data[i];
    }

  
    ~Stack() {
        delete[] data;
    }

   
    Stack& operator<<(int n) {
        if (top < capacity - 1) {
            data[++top] = n;
        }
        return *this;
    }

    
    Stack& operator>>(int& n) {
        if (top >= 0) {
            n = data[top--];
        }
        return *this;
    }

    int operator++() {
        return (top >= capacity - 1) ? 1 : 0;
    }

    int operator--() {
        return (top < 0) ? 1 : 0;
    }

    void print() const {
        cout << "Pile : ";
        for (int i = 0; i <= top; ++i)
            cout << data[i] << " ";
        cout << endl;
    }
};


int main() {
    try {
        Stack p(5);      
        int x, y;

        p << 10 << 20 << 30;  
        p.print();

        p >> x >> y;           
        cout << "x=" << x << ", y=" << y << endl;
        p.print();

        cout << "Pile pleine? " << ++p << endl;
        cout << "Pile vide? " <<--p << endl;

        
        Stack p2 = p;          
        p2.print();


    } catch (const exception& e) {
        cerr << "Erreur : " << e.what() << endl;
    }
    return 0;
}
