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
    string password, username, pass;

    password = value.substr(value.find(',') + 1);
    username = value.erase(value.find(',')), password.length();
    pass = decryptPassword(password);

    authPassed = pass == PASSWORD && username == USERNAME;
    cout << pass << endl;


    return authPassed;
}

string decryptPassword(string pass) {
    const int ROT7 = 7, ROT9 = 9;
    const string VOWELS = "AEIOUYaeiouy";
    string decrypted, password;
    int j=0;
    for (int i=0; i<pass.length(); i++){


        if((pass[j]+ROT7) %2==0) {
            decrypted += pass[j] + ROT7;
            j++;
            goto here;
        }
        else{
        for (int k=0; k < 1; k++) {
                decrypted += int(pass[j] + ROT7);
                j++;
            }
        here:
        for (int p=0; p< 1; p++) {
            decrypted += int(pass[j] + ROT9);
            j++;
        }
            i++;
        }
    }
    j = 0;
    string decryptedTemp = decrypted;



    return decrypted;

}