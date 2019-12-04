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

