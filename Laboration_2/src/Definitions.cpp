#include "Prototypes.h"
using std::string;
using std::stringstream;
using std::cout;
using std::endl;

using namespace std;

string mainArgumentParser(int argc, char * argv[]) {
    if (argc < 3)
        return "fail";
    stringstream ss;
    ss << argv[1] << "," << argv[2];
    return ss.str();
}

bool authenticateUser(string value) {
    const string USERNAME = "Kalle";
    const string PASSWORD = "i0J0u0j0u0J0Zys0r0{";
    bool authPassed = false;
    string username, password;

    password = value.substr(value.find(',') + 1); // särar på lösenordet och användarnamnet, lagrar i substrings.
    username = value.erase(value.find(',')), password.length(); // särar på lösenordet och användarnamnet, lagrar i substring.
    string pass = decryptPassword(password); // kallar funktionen decryptPassword med lagrade värdet av password.

    if (pass == PASSWORD && username == USERNAME) { // om decryptPassword funktionens returvärde stämmer överens, ge autoPassed sant.
        authPassed = true;
    }
    cout << endl << pass << endl;
    return authPassed;
}

string decryptPassword(string pass) {
    const int ROT7 = 7,
            ROT9 = 9;
    const string VOWELS = "AEIOUYaeiouy";
    string decrypt, password, decrypted;
    password = pass;
    decrypt = pass;

    int encryptIndex = 0;
    for (int i = 0; i < password.length(); i++, encryptIndex++) { // använder index för att gå igenom hela lösenordets längd.
        for (char j: VOWELS) {
            /* använder nested for-loop för att gå igenom varje karaktär
             * lagrad i VOWELS, söker igenom varje karaktär i lösenordet.*/
            if (password[i] == j) {
                decrypt.insert(encryptIndex, 1, '0');
                decrypt.insert(encryptIndex + 2, +1, '0');
                encryptIndex += 2; // Lägger till två i indexet då 2 nollor har lagts till, annars går den inte igenom hela lösenordet.
                break;
            }
        }
    }
    int j = 0;
    for (int i = 0; i < pass.length(); i++) { // Iteration så länge i är mindre är lösenordets längd.
        int k = 0, l = 0;
        if ((decrypt[j] + ROT7) % 2 == 0) { // Om nuvarande karaktär i lösenordet +7 rotation är jämt, använd ROT7.
            decrypted += decrypt[j] + ROT7;
            j++;
        } else {
                if (decrypt[j] == '0') { // Om en nolla uppstår, hoppa över genom att öka j med ett.
                    decrypted += (decrypt[j]);
                    j++;
                }
            while (k < 1) { // Använd ROT7 en gång, fortsätt sedan till ROT9.
                decrypted += (decrypt[j] + ROT7);
                j++;
                k++;
            }
                if (decrypt[j] == '0') { // Om en nolla uppstår, hoppa över genom att öka j med ett.
                    decrypted += (decrypt[j]);
                    j++;
                }
            while (l < 1) {
                decrypted += (decrypt[j] + ROT9); // Använd ROT9 en gång, fortsätt sedan till ROT7.
                j++;
                l++;
            }
            i++;
        }
    }
    decrypted.erase(decrypted.size() - 1); // Tar bort en whitespace, hittar ingen snyggare lösning... än.
    return decrypted;
}