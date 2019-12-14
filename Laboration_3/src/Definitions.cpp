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
                size_t nth;
                nth = subMenu();
                fibonacciTimer(nth);
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
    bool igen = true;
    size_t nth=0;
    do {
        cout << "Select n'th number to find (integer): " << endl;
        cin >> nth;
        if (cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "not an int" << endl;
        }
        else
            igen = false;
    }while (igen);

    return nth;
}

vector<Stats> fibonacciTimer(size_t nthNumber){
    int recursion=0, iteration=0;
        recursion = fibonacciRecursion(nthNumber);
        iteration = fibonacciIteration(nthNumber);
        cout << "Iteration:" << iteration<< " Duration: " << endl;
        cout << "Recursion:" << recursion<< " Duration: " << endl;
        mainMenu();

}

void printStats(const std::vector<Stats>& stats){

}

void writeToFile(const Stats& stats){

}

