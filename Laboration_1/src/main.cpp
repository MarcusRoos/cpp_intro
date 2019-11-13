//Av: Marcus Roos
//Uppgift: Laboration 1 - Palindrom
//Datum: 2019-11-13

#include <iostream>
#include <limits>

using namespace std;

int main() {
    int InNum, RevNum = 0, Number, NumStorage;
    char val;
    bool sant = true;
    cout << "Laboration 1!" << endl;
    loop:
    while (sant) {
        cout << "Det har programmet kollar om ett femsiffrigt tal ar ett palindrom eller ej." << endl << "Skriv in ett positivt heltal, fem siffror: " << endl;
        cin >> InNum;

        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits < streamsize > ::max(), '\n');
            cout << " Skriv in ett tal, mellan 10000 och 99999" << endl;
            cin >> InNum;

        }
        while (InNum < 10000 || InNum > 99999) {
            cout << " Talet skall vara mellan 10000 och 99999." << endl;
            cin.clear();
            cin.ignore(numeric_limits < streamsize > ::max(), '\n');
            cin >> InNum;
        }

        NumStorage = InNum;
        while (InNum != 0) {
            Number = InNum % 10;
            InNum = InNum / 10;
            RevNum = RevNum * 10 + Number;

        }

        if (NumStorage == 10000) {
            cout << " Talet som du skrev in: 10000" << endl;
            cout << " Detta talet bakifran blir: 00001 (1)" << endl;
            cout << " Det blir inte en palindrom" << endl;
            goto igen;
        } else {
            cout << " Talet som du skrev in: " << NumStorage << endl;
            cout << " Detta talet bakifran blir: " << RevNum << endl;
            if (NumStorage != RevNum)
                cout << RevNum << " blir inte en palindrom" << endl;
            else
                cout << RevNum << " blir en palindrom" << endl;

            igen:
            cout << endl << "Vill du testa igen? (Y/N)" << endl;
            cin >> val;
            cin.sync();
            if (val == 'N' || val == 'n') {
                sant = false;
            }
            if (val == 'Y' || val == 'y') {
                RevNum = 0, InNum = 0;
                goto loop;
            } else if (val != 'N' && val != 'n' && val != 'Y' && val != 'y') {
                cout << endl << "Vanligen anvand Y eller N." << endl;
                goto igen;
            }
        }
    }

    return 0;
}