#include "Prototypes.h"

/**The programs heart, binds all the functions together and make relevant
 * function calls depending on the integer returned from the mainMenu function.
 * **/
void mainProgram(){
    std::vector<constants> person;
    std::vector<int> choice{1,2,3,4,5,6,7};
    int k;
    do {
        k = mainMenu(choice);
        // Switch to handle different menu choices.
        switch (k) {
            case 1: // Add person
                person.emplace_back(inPerson());
                break;
            case 2: // Print database
                printDatabase(person);
                break;
            case 3: // Search or remove from database
                person = searchPerson(person);
                break;
            case 4: // Sort database
                sortMenu(person);
                break;
            case 5: // Save database to file
                saveToFile(person);
                break;
            case 6: // Load database from file
                person = loadFromFile();
                break;
            case 7: //Exit program
                default:
                break;
        }
    }while(k!=7);

}

/**The programs mainMenu, requires the user to input an integer, and will keep
 * asking until the input is a valid integer between 1 and 7, nothing else
 * will be accepted. Once the integer has been validation the value will return
 * as an integer, in this case to the main program so the correct switch
 * can be activated and relevant functions called.**/
int mainMenu(std::vector<int> menu) {
    using namespace std;
    size_t input =0;
    clearScreen(); // Clear console to make it cleaner
        bool loop;
        do {
            cout << "Welcome! What would you like to do?" << "\n";
            cout << menu[0]<< ". Add a person to the database." << "\n";
            cout << menu[1]<< ". Print the database of persons." << "\n";
            cout << menu[2]<< ". Search or remove a person from the database." << "\n";
            cout << menu[3]<< ". Sort by name, signature, height and randomized order."
                 << "\n";
            cout << menu[4]<< ". Save the database to file." << "\n";
            cout << menu[5]<< ". Load database from file." << "\n";
            cout << menu[6]<< ". Quit." << "\n";
            cout << "Please enter your option: ";

            cin >> input;
            if (input < 1 || input > 7) { // Validates if input is valid.
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                input = 0;
                loop = true;
                cout << "Invalid option." << "\n";
            }
            else { // If input valid, add to vector and break loop
                menu.push_back(input);
                loop = false;
            }
        }while(loop); // As long as nothing is added to vector, iterate

    return input; // Returns integer from vector
}

/**Called from the first case statement of the main program, will ask
 * the user to input a persons first name, last name as well as height.
 * If all inputs are valid a signature will be formed dependant on the
 * first and last name, once done with signature the values will be
 * stored in a struct of constants and returned to where it was called, in
 * this case the main Program, it will be stored in a vector within the
 * main program.**/
constants inPerson() {
    clearScreen(); // Call clearscreen to empty console.

    // Prompt user to insert first name of the person
    std::string firstName;
    std::cout << "Enter the persons first name." << "\n";
    firstName = validate(firstName); // Calls validate(); to validate input.
    firstName[0] = toupper(firstName[0]); // All names start with uppercase.

    // Prompt user to insert last name of the person
    std::string lastName;
    std::cout << "Enter the persons last name." << "\n";
    lastName = validate(lastName); // Calls validate(); to validate input.
    lastName[0] = toupper(lastName[0]); // All names start with uppercase.

    //Input for float, only accepts positive floats.
    std::cout << "Enter the persons height in m (ex: 1.9)" << "\n";
    float height=0;
    std::cin >> height;
    bool loop = false;
        if (height<=0)
            loop = true;
        while (loop) { // Loop to validate input.
                std::cin.clear();
                std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
                std::cout << "Wrong input\n";
                std::cin >> height;
                    if (height>0)
                        loop = false;
        }

    // After input is done, add to vector database, return to mainprogram.
    constants person = constants();
        person.firstName = firstName;
        std::string signatureFirst = person.firstName.substr(0, 3);
        while (signatureFirst.length()<3)// If signature shorter than 3 add x
            signatureFirst += 'x';

        person.lastName = lastName;
        std::string signatureLast = person.lastName.substr(0, 3);
        while (signatureLast.length()<3)// If signature shorter than 3 add x.
        signatureLast += 'x';

        person.height = height;
        person.signature = signatureFirst + signatureLast; /* Adds the two
        * signatures together.*/
        // Turns the string into all lower case
        std::for_each(person.signature.begin(), person.signature.end(),
                [](char & c){
            c = tolower(c);
        });

        pauseFunction("Successfully added " + person.firstName + " " +
        person.lastName +" to the database.\nPress any key to continue.");
        clearScreen();

        return {person}; // Returns vector person.
}

/**This function will print the vector provided as an argument with correct
 * formatting, only a maximum of 20 results will be shown per page, if there
 * are more than 20 elements in the vector the function will pause and await
 * any user input to continue. If end of vector has been reached, the pause
 * function will once again be called and inform the user that the end of
 * the database has been reached, awaiting user input before returning.**/
void printDatabase(const std::vector<constants>& print){
    using namespace std;

    formattingText(print); // Prints text as to not clog up this function

    size_t index=0, counter=0; /* Sets index and counter for printing,
 * index to print a subsequential number next to each member. Counter to
 * only show 20 people per page maximum*/
    for (auto &i : print) {
        if (counter > 20) { // Only show 20 per page.
            pauseFunction("Press any key to show the next page."); /*Use
 * pause function to tell user to press a key before showing next page*/
            counter=0; // Reset counter for next page
            formattingText(print); // Format text output
        }
    index++, counter++;

    // Prints database in columnwise with 2 decimal precision
    cout << setw(2) << right << index;
    cout << setw(6) << left << ".";
    cout << setw(10) << left << i.signature;
    string tempName = i.firstName + " " + i.lastName;
    cout << setw(30) << left << tempName;
    cout << setw(10) << right << std::setprecision(2)<< fixed << i.height << "\n";
        // Prints database in columnwise with 2 decimal precision
    }

    pauseFunction("End of database, press any key to return to main menu.");
    // Pause function to prompt user to return to main menu
    clearScreen(); // Clear console window
};

/**This function will search within the provided vector for the entered
 * search term, the search term shall be a signature and the user will
 * be asked to enter this search term once the function has been called.
 * If no matches are found the user will be informed, function will pause and
 * await user input before returning. If a match is found all the information
 * relevant to the element will be printed out on the screen, the user will
 * then be asked if they wish to keep or remove this person from the database.
 * The function will return a vector in case the user decide to remove the
 * person from the database, to later be stored in the database within the
 * main program.**/
std::vector<constants> searchPerson(const std::vector<constants> &search) {
    using namespace std;
    vector<constants> sign = search; // Declare and initialize vector of struct

    clearScreen(); // Clear console to make it cleaner
    string searchTerm; // Creates string, prompts user to enter search term
    cout << "Enter signature of the person you wish you lookup." << "\n";
    cin >> searchTerm;

    bool missing = true, header=true; /* Bools to show header and make sure the
    signature matched an entry */
    for (size_t i=0; i<sign.size(); i++) { // Goes through entire size of sign
        if (sign[i].signature == searchTerm) { // If a hit, print
            if (header){ // Prints header once if a match is found
                cout  << setw(10) << left << "Sign" << setw(30) << left
                      << "Name" << setw(10) << left << "Length [m]" << endl;
                header = false; // If printed once, change to false
            }

            // Prints information belonging to person(s) found
            cout << setw(10) << left << sign[i].signature;
            string tmpName = sign[i].firstName + " " + sign[i].lastName;
            cout << setw(30) << left << tmpName;
            cout << setw(10) << right << std::setprecision(2) << fixed
                 << sign[i].height << "\n";
            missing = false; // Changes bool to false as a match was found

            cout << "Do you wish to delete this entry from the database? (Y/N)"
            << "\n";
            bool wrongInput = true; // Bool for validation
            char c=0;
            do{ // Loop for validation and asking if user wish to remove person
                cin >> c;
                c = toupper(c);
                if (c!='Y' && c!='N') { // If input is not valid, run
                    cin.clear(); // Clear cin buffer
                    cin.ignore(
                            reinterpret_cast<streamsize>
                            (numeric_limits<streamsize>::max), '\n');
                    // Ignore cin stream
                    cout << "Invalid input\n";
                }
                if (c == 'Y' || c == 'N') { // If input is valid, run
                    wrongInput = false; // Change bool to false
                }
            }while(wrongInput); // End of iteration if bool is false

            if (c == 'Y') { // If user entered 'Y', run
                pauseFunction("Successfully deleted " + sign[i].firstName +
                              " " + sign[i].lastName + " from the database. "
                              "\nPress any key to continue."); // Pause function
                removeEntry(sign, searchTerm); // Remove from database
            }
            else if (c == 'N') { // If user entered 'N', run
                pauseFunction(sign[i].firstName + " " + sign[i].lastName +
                              " was not deleted from the database.\n"
                              "Press any key to continue.");
                // Pause function, does not delete from database
                break;
            }
        }
    }
    if (missing) { // If person cannot be found, above iteration would not run
        pauseFunction("No results found for " + searchTerm + ".\n"
        "Press any key to continue."); // Pause function
    }
    clearScreen(); // Clears console to make it cleaner
    return {sign}; // Returns new vector
}

/**The sortMenu will print several alternatives for the user to be used
 * with sorting. The user need to insert a number between 1 and 5, until input
 * is valid an error will be returned and the user will be prompted to reenter.
 * Once input is valid the input will go into a switch which will determine which
 * choice to use for sorting the vector.**/
void sortMenu (std::vector<constants>& sortMenu) {

    clearScreen(); // Clears console to make it cleaner

    std::cout << "Choose how to sort the database." << "\n";
    std::cout << "1. By Name." << "\n";
    std::cout << "2. By Signature." << "\n";
    std::cout << "3. By Height." << "\n";
    std::cout << "4. Surprise me! (Random)." << "\n";
    std::cout << "5. Don't sort and quit." << "\n";

    int menu=0;
    std::cin >> menu;
    while(menu<=0 || menu>5){ // Loop for sub menu known as sortMenu
        // if invalid, run iteration until input is valid
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                '\n');
        menu = 0;
        std::cout << "Invalid option." << "\n";
        std::cin >> menu;
    }// Break when valid is accepted

    switch (menu){ // Use value from user input as switch argument
        case 1:
            sortPerson(sortMenu, name); // Call sortMenu
            clearScreen();
            pauseFunction("Sorted by name.\nPress any key to return.");
            break;
        case 2:
            sortPerson(sortMenu, signature);// Call sortMenu
            clearScreen();
            pauseFunction("Sorted by signature.\n"
                          "Press any key to return.");
            break;
        case 3 :
            sortPerson(sortMenu, height); // Call sortMenu
            clearScreen();
            pauseFunction("Sorted by height.\nPress any key to return.");
            break;
        case 4 :
            sortPerson(sortMenu, random); // Call sortMenu
            clearScreen();
            pauseFunction("Sorted randomly.\nPress any key to return.");
            break;
        case 5 :
        default:
            pauseFunction("Vector was not sorted."
                          "\nPress any key to return.");
            clearScreen();
            return;
    }
    clearScreen();
}

/**This function is called from the sortMenu, it will use the provided vector
 * and enum to determine which switch to activate, it will activate the
 * switch relative to the choice from the sortMenu and execute a sort function
 * to sort the vector in a correct way, the sorting algorithms are all placed
 * at the end of the definitions source file.**/
void sortPerson (std::vector<constants>& sort, enum sortEnum choice) {

    switch (choice) {
            case name : {
            std::sort(sort.begin(), sort.end(), sortName); // Sort by name
            break;
            case signature :
                std::sort(sort.begin(), sort.end(), sortSignature); /* Sort by
 * signature*/
            break;
            case height :
                std::sort(sort.begin(), sort.end(), sortHeight); /* Sort by
 * height*/
            break;
            case random :
                std::shuffle(sort.begin(), sort.end(),
                std::mt19937(std::random_device()()));// Sort randomly
            break;
        }
    }
}

/**This function will write the vector to a file, the file name will be
 * determined by the user as they are asked for an input. There are a few
 * restricted characters as well as restricted file names for text type files.
 * A separate function is created to handle these restrictions. This
 * save function will read the entire vector and write it down to the text file
 * whose name is determined by the user, it will iterate through the vector
 * until the end as long as the file is open. If the file cant be created the
 * user will be informed, if it can be created the writing will begin.**/
void saveToFile(const std::vector<constants>& write){
    using namespace std;
    string fileName;

    clearScreen(); // Clear console
    cout << "Please insert a name for the file." << "\n";
    fileName = validateFileName(fileName);
    //std::getline(std::cin >> std::ws, fileName);
    // User inputs name for file
    ofstream outFile; // Establishes an out stream
    string writeFile = ("../../_Resources/" + fileName + ".txt");
    //create textfile according to user input
    outFile.open(writeFile, ios::app); /* Opens file to write to, append not to
 *  write over file incase it already exists*/
    if (!outFile.is_open()) { // Checks if file is open
        pauseFunction("File could not be created."); // If not open
    }
   if (outFile.is_open()) { // Checks if file is open
        for (const auto & k : write){ // If open, write to file
            outFile << k.firstName + DELIM + k.lastName;
            outFile << DELIM << std::setprecision(2)<< fixed << k.height;
            outFile << DELIM << k.signature << "\n";
        }
       outFile.close();
    }

    pauseFunction("Saved file as \"" +
    fileName+"\".txt. \nPress any key to return to main menu.");
   // Informs the user the file was successfully saved, and its name
    clearScreen(); // Clear console to make it cleaner
}

/**Same as the save function except this will read from the file instead of
 * writing to file. I loaded the entire text file into a single string, replaced
 * any EOL with the DELIM constant to make it easier to read in. The filename
 * to read from will be determined by user input, if the file cannot be
 * found the user will be informed, if it can be found the user will
 * be informed of that the file was successfully loaded, the string will be
 * split into substrings and stored in the vector until the end of the string.
 * **/
std::vector<constants> loadFromFile(){
    using namespace std;
    constants personData = constants(); // Declares struct of constants
    vector<constants>load; // Declare vector of struct constants as load

    clearScreen(); // Clear console to make it cleaner
    cout << "Enter name of the file to load in." << "\n";
    string tmpName; // Create tmp string to store file name
    std::getline(std::cin >> std::ws, tmpName);
    string fileName = "../../_Resources/" + tmpName + ".txt"; //Try to open file
    ifstream file(fileName.c_str()); // creates input stream

    if(!file.is_open()){ // If file cant be opened, return error
        pauseFunction("File \"" +
        tmpName +".txt" + "\" does not exist. Press any key to "
                          "return to main menu.");
    }

    if(file.is_open()){ // If file can be opened, continue
        stringstream inStream; // In stream to read from file
        inStream << file.rdbuf(); // Pointer for stream buffer
        string wholeFile = inStream.str(); // Load entire file into string

        size_t counter = 0; // Counter
        for (char i : wholeFile) // Loop to go through all chars in wholeFile
            if (i == '\n')
                counter++; // If a new line is found, add one to counter to skip
        // Replace every new line entry with a delim '|' to easier read file.
        replace(wholeFile.begin(), wholeFile.end(), '\n', DELIM);
        //Replace every entry of new line with a delim '|' to easier to read in
        size_t pos1 = 0, pos2, i = 0, p = 0; /* Declare size_t to act as
 * pointers when going through file, also to work as index and counters. */
        while (p < counter) { // While loop to go through entire file.
            //Read in firstname to constants
            pos2 = wholeFile.find(DELIM, pos1);
            personData.firstName = wholeFile.substr(pos1, (pos2 - pos1));
            pos1 = pos2 + 1;
            // Read in lastname to constants
            pos2 = wholeFile.find(DELIM, pos1);
            personData.lastName = wholeFile.substr(pos1, (pos2 - pos1));
            pos1 = pos2 + 1;
            /* Read in height to constants. Stores as string to easier create
            substring */
            string strTemp;
            pos2 = wholeFile.find(DELIM, pos1);
            strTemp = wholeFile.substr(pos1, (pos2 - pos1));
            size_t k = 0;
            // Transform string strTemp to float value to store in constants
            personData.height = stof(strTemp, &k); // Use k as reference value
            pos1 = pos2 + 1;
            // Read in signature to constants
            pos2 = wholeFile.find(DELIM, pos1);
            personData.signature = wholeFile.substr(pos1, (pos2 - pos1));
            pos1 = pos2 + 1;

            // Load vector with assigned values, emplace to push back vector
            load.emplace_back();
            load[i].firstName = personData.firstName;
            load[i].lastName = personData.lastName;
            load[i].height = personData.height;
            load[i].signature = personData.signature;
            i++, p++; // Add one to iterations for vector and counter
        }
        // Pause function to inform user of successfully opening the file
        pauseFunction("Successfully loaded file \"" +
        tmpName + "\".txt. \nPress any key to return to main menu.");
    }

    clearScreen(); // Clear console to make it cleaner

return {load}; // Return vector load

}

/** Help functions, either to reduce verbosity or to shorten down the functions.
 * These are also functions not being called from the mainProgram or short
 * functions being called several times.**/
bool sortName(const constants &a, const constants &b)
{ // Bool, used as sorting rules by names
    if (a.lastName == b.lastName){ // If first names are equal, run
        return a.firstName < b.firstName; // Return first names, ascending
    }
    else{ // If first names are not equal
        return a.lastName < b.lastName; // Return last names, ascending
    }
}
bool sortSignature(const constants &a, const constants &b)
{ // Bool used as sorting rules by signature
    return a.signature < b.signature; // return signatures in ascending order
}
bool sortHeight(const constants &a, const constants &b)
{ // Bool used as sorting rules by height
    return a.height > b.height; // Return height in descending order
}

void pauseFunction(const std::string& text){ /* Function used when program
 * should wait for user input before it continues */
    std::cout << text; // Prints function parameter on screen
    std::cin.clear(); // Clear stream
    std::cin.sync(); // Synchronizes the input stream
    std::cin.get(); // Waits for user input before it continues
    std::cin.clear(); // Clear stream once again to remove leftovers
    std::cin.sync(); // Synchronizes the input stream
}

void formattingText(const std::vector<constants>& format){/*Formats text, takes
 * vector as parameter and prints accordingly*/
    using namespace std;
    clearScreen(); // Clears console whenever this function is called
    cout << "*******NAME LIST*******" << "\n";
    cout << "Number of persons in list:" << format.size() << "\n\n";
    cout << setw(8) << left << "Nr" << setw(10) << left << "Sign"
    << setw(30) << left
         << "Name" << setw(10) << left << "Length [m]" << endl;
}

/*Taken from anders-jens Urstad, depending on OS it will use three different
 * methods of clearing the console window.*/
void clearScreen()
{
#if defined (__unix__) || (defined (__APPLE__) && defined (__MACH__))/*If user
 * is on unix system, apple system or mach, use this method*/
    std::cout << "\033[2J\033[1;1H" << std::endl;
#elif _WIN32 // If user is on windows, use this method
    system("cls");
#else // If OS is unknown, print 100 \n's
    std::cout << std::string(100, '\n') << std::endl;
#endif
}

void removeEntry(std::vector<constants> & persons, std::string searchTerm) {
    persons.erase( // remove person from database, iterates through vector
            std::remove_if(persons.begin(), persons.end(),
                    [&](constants const & person) {
                return person.signature == searchTerm; // returns when equal
            }),
            persons.end());// End of erase
}

std::string validate(std::string input){ // Validate input
    bool valid;
    do {
        std::getline(std::cin >> std::ws, input);
        valid = true;
        for (std::size_t i{}; i < input.length() && valid; ++i) { /*Iterates
 * through inputs length, checks if input is either a letter or a space,
 * anything else is considered invalid*/
            if (!(std::isalpha(static_cast<unsigned char>(input[i])) ||
                  std::isspace(static_cast<unsigned char>(input[i])))) {
                valid = false;
                std::cout << "Invalid input\n";
            }
        }
    } while (!valid);
    return input;
}

std::string validateFileName(std::string input){ // Validate input
    bool valid;
    do {
        valid = true;
        std::getline(std::cin >> std::ws, input);
        if (input=="COM1" || input=="COM2" || input=="COM3" || input=="COM4"
            || input=="COM5" || input=="COM6" || input=="COM7" || input=="COM8"
            || input=="COM9" ||input=="LPT1" || input=="LPT2" || input=="LPT3"
            || input=="LPT4" || input=="LPT5" || input=="LPT6" || input=="LPT7"
            || input=="LPT8" || input=="LPT9" || input=="CON" || input=="PRN"
            || input=="AUX" || input=="NUL"){ // Reserved file names
            valid = false;
            std::cout << "Invalid input\n";
        }
        for (std::size_t i{}; i < input.length() && valid; ++i) { /*Iterates
 * through inputs length, checks if input is valid, will not accept follow
 * characters due to being forbidden in both windows and unix systems.*/
            if (input[i]=='<' || input[i]=='>' || input[i]=='"' || input[i]=='/'
            || input[i]=='\\' || input[i]=='*' || input[i]==':' || input[i]=='?'
            || input[i]=='|') { // Forbidden characters
                valid = false;
                std::cout << "Invalid input\n";
            }
        }
    } while (!valid);
    return input;
}