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

    // särar på lösenordet och användarnamnet, lagrar i substrings.
    password = value.substr(value.find(',') + 1);
    // särar på lösenordet och användarnamnet, lagrar i substring.
    username = value.erase(value.find(',')), password.length();
    // kallar funktionen decryptPassword med lagrade värdet av password.
    string pass = decryptPassword(password);

    // om funktionens returvärde stämmer överens, ge autoPassed sant.
    if (pass == PASSWORD && username == USERNAME) {
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
    // använder index för att gå igenom hela lösenordets längd.
    for (int i = 0; i < password.length(); i++, encryptIndex++) {
 /* använder nested for-loop för att gå igenom varje karaktär
 * lagrad i VOWELS, söker igenom varje karaktär i lösenordet.*/
        for (char j: VOWELS) {
            if (password[i] == j) {
                decrypt.insert(encryptIndex, 1, '0');
                decrypt.insert(encryptIndex + 2, +1, '0');
                /* Lägger till två i indexet då 2 nollor har lagts till, annars
                 * går den inte igenom hela lösenordet. */
                encryptIndex += 2;
                break;
            }
        }
    }
    int j = 0;
    // Iteration så länge i är mindre är lösenordets längd.
    for (int i = 0; i < pass.length(); i++) {
        int k = 0, l = 0;
        // Om nuvarande karaktär i lösenordet +7 rotation är jämt, använd ROT7.
        if ((decrypt[j] + ROT7) % 2 == 0) {
            decrypted += decrypt[j] + ROT7;
            j++;
        } else {
            // Om en nolla uppstår, hoppa över genom att öka j med ett.
                if (decrypt[j] == '0') {
                    decrypted += (decrypt[j]);
                    j++;
                }
            // Använd ROT7 en gång, fortsätt sedan till ROT9.
            while (k < 1) {
                decrypted += (decrypt[j] + ROT7);
                j++;
                k++;
            }
            // Om en nolla uppstår, hoppa över genom att öka j med ett.
                if (decrypt[j] == '0') {
                    decrypted += (decrypt[j]);
                    j++;
                }
            while (l < 1) {
                // Använd ROT9 en gång, fortsätt sedan till ROT7.
                decrypted += (decrypt[j] + ROT9);
                j++;
                l++;
            }
            i++;
        }
    }
    // Tar bort en whitespace, hittar ingen snyggare lösning... än.
    decrypted.erase(decrypted.size() - 1);
    return decrypted;
}