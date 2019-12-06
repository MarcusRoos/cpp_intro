#include "Prototypes.h"
using std::string;
using std::stringstream;
using std::cout;
using std::endl;


using namespace std;

string mainArgumentParser(int argc, char* argv[]) {
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

    password = value.substr(value.find(',') + 1);
    username = value.erase(value.find(',')), password.length();
    string pass = decryptPassword(password);

    authPassed = pass == PASSWORD && username == USERNAME;

    return authPassed;
}

string decryptPassword(string pass) {
    const int ROT7 = 7, ROT9 = 9;
    const string VOWELS = "AEIOUYaeiouy";
    string decrypt, password, decrypted;
    password = pass;
    decrypt = pass;

    int encryptIndex = 0;
    for (int i = 0; i < password.length(); i++, encryptIndex++){
        for (char j : VOWELS){
            if (password[i] == j){
                decrypt.insert(encryptIndex, 1, '0');
                decrypt.insert(encryptIndex + 2, +1, '0');
                encryptIndex += 2;
                break;
            }
        }
    }

    int j=0;
    for (int i=0; i<pass.length(); i++){
        if((decrypt[j]+ROT7) %2==0) {
            decrypted += decrypt[j] + ROT7;
            j++;
            goto here;
        }
        else{
            if (decrypt[j] == '0'){
                decrypted += int(decrypt[j]);
                j++;
            }
            for (int k=0; k < 1; k++) {
                decrypted += int(decrypt[j] + ROT7);
                j++;
            }
            if (decrypt[j] == '0'){
                decrypted += int(decrypt[j]);
                j++;
            }
            here:
            for (int k=0; k < 1; k++) {
                decrypted += int(decrypt[j] + ROT9);
                j++;
            }
            i++;
        }
    }
    decrypted.erase(decrypted.size()-1); //Tar bort en whitespace, hittar ingen snyggare lösning... än.
    return decrypted;

}