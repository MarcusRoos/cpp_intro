#ifndef DT018G_DATABASE_H
#define DT018G_DATABASE_H

#include <string> // Strings for the struct constants.

struct constants { /* Struct to keep track of persons first name, last name,
* signature as well as their height */
    std::string firstName, lastName, signature;
    float height=0;
};

enum sortEnum {name, signature, height, random}; /*Enumeration for sorting
 * functions, will use whatever value the person chose*/

const char DELIM='|'; // Constant delim '|' assigned

#endif //DT018G_DATABASE_H
