#include "Prototypes.h"

long_type fibonacciIteration(size_t nthNumber) {
    size_t x = 0, y = 1, z = 0;
    for (size_t i = 0; i < nthNumber; i++) {
        z = x + y;
        x = y;
        y = z;
    }
    return x;
}

long_type fibonacciRecursion(size_t nthNumber) {
    if (nthNumber <= 1)
        return nthNumber;
    return fibonacciRecursion(nthNumber - 1) + fibonacciRecursion(nthNumber - 2);
}

void mainMenu() {
    bool igen = true;
    do {
        char input;
        cout << endl;
        cout << "FIBONACCI SEQUENCE MEASUREMENTS" << endl;
        cout << "===============================" << endl;
        cout << " 1. Run Measurements" << endl;
        cout << " 2. Exit" << endl;
        cout << "===============================" << endl;
        cout << "Your input: " << endl;
        cin >> input;
        switch (input) {
            case '1':
                subMenu();
                break;
            case '2':
                igen = false;
                break;
        }
        if (input != '1' && input != '2')
            cout << "fel input" << endl;

    } while (igen);
}

size_t subMenu(){
    bool igen = false;
    int nth=0;
    do {

        cout << endl;
        cout << "Select n'th number to find (integer): " << endl;
        cin >> nth;
        if (cin.fail()) {
            cout << "not an int" << endl;
            igen = true;
        }

    } while (igen);
    return nth;
}

vector<Stats> fibonacciTimer(size_t nthNumber){

}

void printStats(const std::vector<Stats>& stats){

}

void writeToFile(const Stats& stats){

}