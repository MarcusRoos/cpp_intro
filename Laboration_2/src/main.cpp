/*Av: Marcus Roos
Uppgift: Laboration 2 - Spies'R Us
Datum: 2019-12-04
Beskrivning av programmet: Programmet kommer ta två in-argument, sedan verifiera
om dessa stämmer överens med det förlagrade användarnamnet och lösenordet och sedan
ge användaren tillgång till programmet. Det är ett lösenord skyddat och använder sig
av krypteringsnycklarna ROT7 & ROT9 samt nollor vid varje versal.
*/
#include "Prototypes.h"
using std::string;
using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
    string value = mainArgumentParser(argc, argv);

    if (value == "fail")
        cout << "Not enough arguments. Program exits..." << endl;
    else if(authenticateUser(value))
        cout << "Authentication successful, user may now access the system!" << endl;
    else
        cout << "Authentication failed. Program exits..." << endl;

    return 0;
}

