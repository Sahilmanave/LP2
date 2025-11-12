#include <iostream>
using namespace std;

int main() {
    int nterms, n1 = 0, n2 = 1, count = 0;

    cout << "Enter number of terms: ";
    cin >> nterms;

    if (nterms <= 0) {
        cout << "Please enter a positive integer" << endl;
    }
    else if (nterms == 1) {
        cout << "Fibonacci sequence up to " << nterms << " : " << endl;
        cout << n1 << endl;
    }
    else {
        cout << "Fibonacci sequence: " << endl;
        while (count < nterms) {
            cout << n1 << " ";
            int nth = n1 + n2;
            n1 = n2;
            n2 = nth;
            count++;
            cout << endl;
        }
        
    }

    return 0;
}

#include <iostream>
using namespace std;

// Recursive function to find Fibonacci number
int fibonacci(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    cout << "Enter number of terms: ";
    cin >> n;

    cout << "Fibonacci sequence:" << endl;
    for (int i = 0; i < n; i++) {
        cout << fibonacci(i) << " ";
    }
    cout << endl;

    return 0;
}