#include <iostream>
using namespace std;
// zad 2 Euclid via recursion with fibonacci numbers
int answer;
int counter = 0;

void Euclid(int a, int b) {
    cout << "Recursion Copy #" << counter << endl << "a= " << a << " b= " << b << " Drowning" << endl;
    counter++;

    if (a % b > 0) { // ðåêóðñèÿ
        Euclid(b, a % b);
        counter--;
        cout << "Recursion Copy #" << counter << endl << "a= " << a << " b= " << b << " Coming up" << endl;
    }
    else { // äúíî
        cout << "- Bottom of the recursion reached -" << endl << endl;
        answer = b;
    }
}

int main() {
    int n1, n2;
    cin >> n1 >> n2;
    Euclid(n1, n2);
    cout << endl << "Greatest common divisor of " << n1 << " and " << n2 << " is " << answer << endl;
    return 0;
}


