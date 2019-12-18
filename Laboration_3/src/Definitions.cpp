#include <iterator>
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
    bool loop = true, sant=true;
    size_t nth = 0;
    char c;
    vector<Stats> stats;
    while (sant) {
    do {
        textMenu();
        int input = 0;
        cin >> input;
        switch (input) {
            case 1:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                nth = subMenu();
                stats = fibonacciTimer(nth);
                cout << endl
                     << "Duration of running fibonacci sequences through  "
                     << nth << " to " << "0" << endl;
                printStats(stats);
                //writeToFile(stats);
                cout << "Do you want to measure again? (Y/N)" << endl;
                do {
                    cin >> c;
                    c=toupper(c);
                    if (c == 'Y')
                        sant = true;
                    else if(c == 'N') {
                        sant = false;
                        loop = false;
                    }
                    else
                        cout << "Wrong input. Y(Yes) or N(No) only " << endl;
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }while(c!='N' && c!='Y');
                break;
            case 2:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                loop = false;
                break;
        }
        if (input != 1 && input != 2) {
            cout << "fel input" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            input = 0;
        }
    } while (loop);
}



}

size_t subMenu(){
    bool igen;
    int nth=0;
    cout << "WARNING: Large numbers may take a long time to process." << endl;
    cout << "Select n'th number to find (integer): " << endl;
    do {
        cin >> nth;
        while (nth<0){
            nth='n';
            cout << "Cannot process negative integers, please enter a positive number. " << endl;
            cin >> nth;
        }

            if (cin.fail()) {
                cout << "You did not enter an int, please enter an integer."
                     << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                igen = true;
            } else
                igen = false;

    }while (igen);

    return nth;
}

std::vector<Stats>fibonacciTimer(size_t nthNumber){
    Stats recursion=Stats(), iteration=Stats();
    size_t nthTemp = nthNumber, nth=0;
    auto timeStartR = std::chrono::high_resolution_clock::now();
    int i=5;
    do{
        nth = fibonacciRecursion(nthTemp);
        recursion.type="Recursion";
        recursion.values.push_back(nth);
        if (i==5){
            cout << setw(5) << left << "Recursions " << nthTemp << "'th value: " << setw(10) << right << nth << endl;
            i=0;
        }
        nthTemp--, i++;
    }while(nth!=0);
    auto timeEndR = std::chrono::high_resolution_clock::now();
    long_type durationR = std::chrono::duration_cast<std::chrono::microseconds>(timeEndR - timeStartR ).count();
    recursion.nanosec = durationR*1000;
    recursion.microsec = durationR;
    recursion.millisec = durationR/1000;
    recursion.sec = (double)durationR/1000000;
    cout << endl;
    nthTemp=nthNumber;
    auto timeStartI = std::chrono::high_resolution_clock::now();
    i=5;
    do{
        nth = fibonacciIteration(nthTemp);
        iteration.type="Iteration";
        iteration.values.push_back(nth);
        if (i==5){
            cout << setw(5) << left << "Iterations " << nthTemp << "'th value: " << setw(10) << right << nth << endl;
            i=0;
        }
        nthTemp--, i++;
    }while(nth!=0);
    auto timeEndI = std::chrono::high_resolution_clock::now();
    long_type durationI = std::chrono::duration_cast<std::chrono::microseconds>(timeEndI - timeStartI ).count();
    iteration.nanosec = durationI*1000;
    iteration.microsec = durationI;
    iteration.millisec = durationI/1000;
    iteration.sec = (double)durationI/1000000;

    return {recursion, iteration};
}

void printStats(const std::vector<Stats>& stats) {
    cout << "==========================================================================================" << endl;
    cout << right << setw(25) << "Nanosecs" << setw(15) << "Microsecs" << setw(15) << "Millisecs" << setw(15) << "Seconds" << endl;
    for (const Stats &stat : stats) {
        cout << stat.type <<":"<< right << setw(15) << stat.nanosec << setw(15) << stat.microsec << setw(15) << stat.millisec << setw(15) << stat.sec << endl;
    }
    cout << "==========================================================================================" << endl <<endl;
}

void writeToFile(const Stats& stats) {
    fstream randFile;
    string fileName = "Iteration.txt";
    randFile.open(fileName, ios::out);
    if (randFile.is_open()) {
        for (size_t i = 0; i < stats.values.size(); i++) {
            randFile << stats.values[i];
            if (i < (stats.values.size() - 1))
                randFile << endl;
        }

    }
}
void textMenu(){
    cout << "FIBONACCI SEQUENCE MEASUREMENTS" << endl;
    cout << "===============================" << endl;
    cout << " 1. Run Measurements" << endl;
    cout << " 2. Exit" << endl;
    cout << "===============================" << endl;
    cout << "Your input: " << endl;
}
