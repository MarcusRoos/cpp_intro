#ifndef DT018G_PROTOTYPES_H
#define DT018G_PROTOTYPES_H

#include "constants.h" // Include constants.h header
#include <iostream> // cin, cout, left, right
#include <iomanip> // setprecision, setw
#include <fstream> // is_open, close, ofstream, ifstream
#include <limits> // numeric_limits
#include <vector> // vectors, begin, end, push_back, erase, emplace_back
#include <string> // strings, length, erase, insert, find, substr
#include <algorithm> // for_each, shuffle, replace, sort
#include <sstream> // stringstream, rdbuf
#include <cstdlib> // stof, SYSTEM("CLS")
#include <cctype> //toupper, tolower
#include <random> //random_device

void mainProgram();
/**
 The main program, stores database, calls the main menu.
 @param void
 @return void
 */
void printDatabase(const std::vector<constants>& database);
/**
 Prints database from vector database of the struct constants.
 @param constant vector of constants
 @return void
 */
void saveToFile(const std::vector<constants>& write);
/**
 Saves database to file using a constant vector of struct constants.
 @param constant vector of constants
 @return void
 */
void sortMenu (std::vector<constants>& sortMenu);
/**
 Sub menu to sort database using a vector of struct constants.
 @param vector of constants
 @return void
 */
void sortPerson (std::vector<constants>& sort, enum sortEnum choice);
/**
 Sorts database using a constant vector of struct constants and the enum
 sortEnum.
 @param vector of constants
 @param enum sortEnum
 @return void
 */
void pauseFunction(const std::string&);
/**
 Pauses program, waits for user input in form of a constant string, prints text.
 @param String
 @return void
 */
void formattingText(const std::vector<constants>& format);
/**
 Formats text, accepts a constant vector of the struct constants.
 @param vector of constants
 @return void
 */
void clearScreen();
/**
 Clears screen, if windows use system CLS, if anything else, prints 100 \n's.
 @param vector of constants
 @return void
 */
void removeEntry(std::vector<constants> & persons, std::string searchTerm);
/**
 Remove entry from database, using vector of structs constants, and a string.
 @param vector of constants
 @param string filled with the search term of the person to be removed
 @return void
 */

bool sortName(const constants &a, const constants &b);
/**
 Sorts database by lastname, if lastnames are equal, by firstname in ascending
 order
 @param Two const values of struct constants, loaded into a for comparison
 @param Two const values of struct constants, loaded into b for comparison
 @return first or lastname in ascending order. lastName by default, firstName
 if lastnames are equal
 */
bool sortSignature(const constants &a, const constants &b);
/**
 Sorts database by signature in ascending order
 @param Two const values of struct constants, loaded into a for comparison
 @param Two const values of struct constants, loaded into b for comparison
 @return signature by size in ascending order
 */
bool sortHeight(const constants &a, const constants &b);
/**
 Sorts database by height in descending order
 @param Two const values of struct constants, loaded into a for comparison
 @param Two const values of struct constants, loaded into b for comparison
 @return signature by size in descending order
 */

std::string validate(std::string input);
/**
 Validates user input when adding names to database, loops until input is valid
 @param A string with the user input
 @return The user input once it's deemed valid.
 */

std::string validateFileName(std::string input);
/**
 Validates user input when trying to save text file
 @param A string with the user input
 @return The user input once it's deemed valid.
 */

std::vector<constants> searchPerson(const std::vector<constants>& search);
/**
 Searches for a person in the database by signature
 @param The database in form of a constant vector of the struct constants
 @return The database will return the result of the searched person.
 */

std::vector<constants> loadFromFile();
/**
 Loads a file into the database in form of a vector
 @param None.
 @return Returns database as a vector.
 */

constants inPerson();
/**
 Adds a person for in the database
 @param None.
 @return Returns one entry of the struct constants.
 */

int mainMenu(std::vector<int> menu);
/**
 Prints the main menu, allows user to choose what to do with the program
 @param Vector of type iconst nt
 @return Retu&rns the int value of the choice inside the mainmenu
 */

#endif //DT01const 8G_PROTOTYP&ES_H
