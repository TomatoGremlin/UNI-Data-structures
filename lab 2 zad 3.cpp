#include <iostream>
using namespace std;
// 3. Factoriel via recursion
int counter;
int Factorial(int n) {
    unsigned number;
    counter++;
    // ----
    if ( n > 1) {
        cout << "n =" << n << endl;
        //return 1;
        number = n * Factorial(n - 1);
        cout << "n =" << number << endl;
        return number;
    }
    else {
        cout << "- Bottom of the recursion reached -" << endl << endl;
        cout << "n= " << n << endl;
        number = 1;
        return number;
    }
}

int main(){
    int n;
    cin >> n;
    cout << "Factorial of " << n << " = " << Factorial(n);
    cout << endl;
    return 0;
}


    /*
    if (n == 0 || n ==1)
    {
        cout << " n =" << n << endl;
        //return 1;
           cout << "n" << Factorial(n) << endl;
    }
    else // n > 1
    {
        cout << "Bottom" << endl << " n= " << n << endl;
        return n * Factorial(n - 1);
        number
    }*/
