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
    size_t nth=0;
    vector <Stats> stats;
    do {
        int input=0;
        cout << endl;
        cout << "FIBONACCI SEQUENCE MEASUREMENTS" << endl;
        cout << "===============================" << endl;
        cout << " 1. Run Measurements" << endl;
        cout << " 2. Exit" << endl;
        cout << "===============================" << endl;
        cout << "Your input: " << endl;
        cin >> input;
        switch (input) {
            case 1:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                nth = subMenu();
                stats=fibonacciTimer(nth);
                printStats(stats);
                break;
            case 2:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                igen = false;
                break;
        }
        if (input != 1 && input != 2)
            cout << "fel input" << endl;
        input = 0;

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
            igen = true;
        }
        else
            igen = false;
    }while (igen);

    return nth;
}

std::vector<Stats>fibonacciTimer(size_t nthNumber){
    Stats recursion, iteration;
    size_t nthTemp = nthNumber, nth=0;
    string type;
    auto timeStartR = std::chrono::high_resolution_clock::now();
    int i=5;
    do{
        nth = fibonacciRecursion(nthTemp);
        recursion.values.push_back(nth);
        recursion.type="recursion";
        if (i==5){
            cout << setw(5) << left << "Recursions " << nthTemp << "'th value: " << setw(10) << right << nth << endl;
            i=0;
        }
        nthTemp--, i++;
    }while(nth!=0);
    auto timeEndR = std::chrono::high_resolution_clock::now();
    recursion.millisec = std::chrono::duration_cast<std::chrono::milliseconds>(timeEndR - timeStartR ).count();
    nthTemp=nthNumber;
    auto timeStartI = std::chrono::high_resolution_clock::now();
    i=5;
    do{
        nth = fibonacciIteration(nthTemp);
        recursion.values.push_back(nth);
        recursion.type="recursion";
        if (i==5){
            cout << setw(5) << left << "Iterations " << nthTemp << "'th value: " << setw(10) << right << nth << endl;
            i=0;
        }
        nthTemp--, i++;
    }while(nth!=0);
    auto timeEndI = std::chrono::high_resolution_clock::now();
    iteration.millisec = std::chrono::duration_cast<std::chrono::milliseconds>(timeEndI - timeStartI ).count();
    cout << "Recursion took: " << recursion.millisec << " Milliseconds" << endl;
    cout << "Iteration took: " << iteration.millisec << " Milliseconds" << endl;

    return {iteration, recursion};
}

void printStats(const std::vector<Stats>& stats){

}

void writeToFile(const Stats& stats){

}

