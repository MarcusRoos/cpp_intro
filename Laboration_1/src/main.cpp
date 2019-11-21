//Av: Marcus Roos
//Uppgift: Laboration 1 - Palindrom
//Datum: 2019-11-13
/*Beskrivning av programmet: Programmet kommer att be användaren mata in ett fem siffrigt tal, sedan kommer detta tal att kastas om och räknas upp bakifrån, om talet
 * är detsamma framifrån som bakifrån så är det ett palindrom vilket är programmets uppgift. För att lösa detta används modulo operatorn för att släppa loss
 * den sista siffran i talet som skrivs in. Användaren har även möjlighet att upprepa programmet tills den så väljer att avsluta det genom att skriva N eller n.*/ 

#include <iostream>
#include <limits>

using namespace std;

int main() {
    int InNum, RevNum = 0, Number, NumStorage;
    char val = 'Y', val2 = '\0';
    bool loop = true;
    cout << "Laboration 1!" << endl;

    while (val == 'y' || val == 'Y') { //Början av programmet.

        cout << "Det har programmet kollar om ett femsiffrigt tal ar ett palindrom eller ej." << endl << //Berättar vad användaren ska göra, samt vad programmet gör.
             "Skriv in ett positivt heltal, fem siffror: " << endl;
        cin >> InNum;

        while (cin.fail()) { //While loopar för att bekräfta att input stämmer.
            cin.clear();
            cin.ignore(numeric_limits < streamsize > ::max(), '\n');
            cout << "Skriv in ett tal, mellan 10000 och 99999" << endl;
            cin >> InNum;

        }
        while (InNum < 10000 || InNum > 99999) {
            cout << "Talet skall vara mellan 10000 och 99999." << endl;
            cin.clear();
            cin.ignore(numeric_limits < streamsize > ::max(), '\n');
            cin >> InNum;
        }

        NumStorage = InNum;
        while (InNum != 0) { //Räknar om input omvänt, lagras i RevNum.
            Number = InNum % 10;
            InNum = InNum / 10;
            RevNum = RevNum * 10 + Number;

        }

        if (NumStorage == 10000) { //Extra säkerhet då användaren inleder med 10000, annars skrivs endast 1 ut och det såg fult ut.
            cout << "Talet som du skrev in: 10000" << endl;
            cout << "Detta talet bakifran blir: 00001 (1)" << endl;

        } else { //Echo vad användaren skrev in, samt vad det blir baklänges.
            cout << "Talet som du skrev in: " << NumStorage << endl;
            cout << "Detta talet bakifran blir: " << RevNum << endl;
        }
        if (NumStorage != RevNum) //Visar om input är en palindrom eller ej.
            cout << RevNum << " blir inte en palindrom" << endl;
        else
            cout << RevNum << " blir en palindrom" << endl;

        RevNum = 0;
        cout << endl << "Vill du testa igen? (Y/N)" << endl; //Frågar om användaren vill köra om programmet.
        cin >> val;
        if (val != 'N' && val != 'n' && val != 'Y' && val != 'y') //Om inte Y, y, eller N, n matas in så kommer en flagga sättas till sant så att programmet fastnar i nästa while-loop.
            loop = true;
        else if (val == 'N' || val == 'n' || val == 'Y' || val == 'y') //Om input stämmer med Y,n eller N,n så kommer flaggan sättas till falskt, då kommer inte programmet fasta i while-loopen.
            loop = false;
        cin.sync(); //Endast första bokstaven som matades in läses.

        while (loop) { //Loop för att bekräfta ett endast Y eller N har använts, om inte, kör loopen tills användaren matar in y eller n.
            cout << "Endast Y eller N accepteras! Vill du testa igen? (Y/N)" << endl;
            cin >> val2;
            cin.sync(); //Utan sync så kommer loopen köras så många gånger som antal tecken man matade in, t.ex. om man matar in "eee" så kommer cout skrivas 3 gånger.
            loop = true; //Flaggan är sann om input inte är Y, N.

            if (val2 == 'N' || val2 == 'n' || val2 == 'Y' || val2 == 'y') {
                loop = false; //Flaggan är falsk om input är Y eller N.
                val = val2;
                break; //Då bryts loopen, om Y har matats in så körs programmet om då det alltid körs så länge val = y eller Y. Om N eller n har matats in så stängs programmet av.
            }
        }

    } //Slutet av programmet

    return 0;
}