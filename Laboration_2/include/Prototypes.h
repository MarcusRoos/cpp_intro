#ifndef DT018G_PROTOTYPES_H
#define DT018G_PROTOTYPES_H

#include <iostream>
#include <string>
#include <sstream>

// Parser for main argument
std::string mainArgumentParser(int argc, char* argv[]);
bool authenticateUser(std::string value);
std::string decryptPassword(std::string pass);

#endif //DT018G_PROTOTYPES_H
