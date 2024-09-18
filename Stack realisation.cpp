/*Dešimtainio skaičiaus vertimas i dvejetaine panaudojant steką.
Spendimo algoritmo žingsniai:
a) Nuskaitome sveikąjį dešimtainį skaičių.
b) Sukuriame steko duomenų struktūrą.
c) Dedame sveikąjį dešimtaini skaičių i ciklą ir vykdome cikle tokius veiksmus, kol mūsų skaičius bus nelygus nuliui:
- Daliname skaičių iš 2 ir išsaugome liekaną (% operacija).
- Dedame liekaną į steką (push operacija).
- Dalmenį priskiriame skaičiui ir kartojame ciklą (/, t. y. sveikaskaitinė dalyba).
d) Aprašome ciklą, kurio operatoriai paima po vieną elementą iš steko ir atspausdina galutinį dvejetaini skaičių (pop operacija).*/

#include <iostream>
using namespace std;

// Steko klasės aprašymas
#define DEFAULT_SIZE 10

class Stack {
private:
    int size;   // Steko dydis
    int top;    // Viršutinio elemento indeksas
    int* values; // Dinaminis masyvas steko elementams saugoti

public:
    // Konstruktorius
    Stack(int size = DEFAULT_SIZE) : size(size), top(-1) {
        values = new int[size];  // Sukuriame dinaminį masyvą
    }

    // Destruktorius
    ~Stack() {
        delete[] values;  // Išlaisviname dinaminę atmintį
    }

    // Patikriname, ar stekas pilnas
    bool isFull() {
        return top == size - 1;
    }

    // Patikriname, ar stekas tuščias
    bool isEmpty() {
        return top == -1;
    }

    // Įdėti elementą į steką
    void push(int x) {
        if (!isFull()) {
            top++;
            values[top] = x;
        }
        else {
            cout << "Stekas pilnas, negalima pridėti elemento!" << endl;
        }
    }

    // Išimti elementą iš steko
    int pop() {
        if (!isEmpty()) {
            return values[top--];
        }
        else {
            cout << "Stekas tuščias, nėra ką išimti!" << endl;
            return -1; // Indikuojame klaidą, jei stekas tuščias
        }
    }
};

// Funkcija dešimtainio skaičiaus vertimui į dvejetainį, naudojant steką
void decimalToBinary(int number) {
    Stack stack;  // Sukuriame steko objektą su numatytuoju dydžiu

    // Įdėti liekanas į steką
    while (number > 0) {
        int remainder = number % 2;
        stack.push(remainder);  // Dedame liekaną į steką
        number /= 2;  // Daliname skaičių iš 2
    }

    // Išimame ir atspausdiname elementus iš steko
    cout << "Dvejetainis skaičius: ";
    while (!stack.isEmpty()) {
        cout << stack.pop();
    }
    cout << endl;
}

int main() {
    int number;
    cout << "Įveskite sveikąjį dešimtainį skaičių: ";
    cin >> number;

    if (number >= 0) {
        decimalToBinary(number);  // Konvertuojame dešimtainį skaičių į dvejetainį
    }
    else {
        cout << "Skaičius turi būti teigiamas." << endl;
    }

    return 0;
}
