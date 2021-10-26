# Project Assignment
Av: Marcus Roos
Uppgift: Project - Database
Datum: 2020-01-19
Program description: Allows the user to enter persons to a vector belonging to a
struct known as constants, their first name, last name as well as height will be entered.
The user will be able to save this vector to a file, as well as load in a file to fill the vector,
the user is able to search for people in the database by signature and able to sort it. 
Deleting someone from the database is possible as well.

## Environment & Tools
Windows 10 64bit.
IDE: CLion.
Environment: MinGW 5.2
CMake: mingw32 make 3.15.3
C++ compiler: g++
Debugger: MinGW GDB 7.6.1
Git: Git 2.23.0.windows.1

## Purpose
The purpose of this project is to prove our understanding of how several things work,
we have done three laborations prior to this one which included small bits of everything.
In this project all these bits collide and we're forced to use all of them to create
the program demanded. We'll be able to prove our understanding primarily regarding:
*Strings
*Vectors
*Functions
*Enumerations
*Data structures
*Input/Output operations as well as file handling
*How to have a well structed program code
*Maintaining a good file structure
*As well as documentation

For this project we will be constructing a database. The database will have 
several different functions which we will need to tend to using previous
stated methods. First off the user should be able to add a person to the database,
the user should be stored in a vector of a struct called vector, this struct
shall contain a datatype for each of the inputs as well as a signature which will
be created from parts of the first and last names. 

This will all be stored in a  vector, and this vector will be used for several different things. First off the user
should be able to save this vector onto a textfile with a name of their choice, they
should also be able to open a file with a name of their choice and read its contents
into the very same vector. The user should be able to search persons by entering
their signature, as well as deleting entries from the vector. The user should be
able to sort the vector by different methods including by signature, height, and
last name, if last names happen to be the same, it should sort by first name instead.

In the end, the program should work as a full-fledged database although a bit 
rough as there won't be any interface apart from console windows. But the crucial
parts should be there, adding, sorting, removing, searching, saving and loading database.

## Procedures 
Nothing but a function call should be placed in the main(); therefore a function
to be called from main needs to be created. For this I chose the function name `void mainProgram()`
of the void type, its task is to call functions, store the database in a vector called "person", the users menu choices,
and it will also contain a vector of the type int which will be used to call the menu. The 
mainProgram will also show how big the current database is, this is simply done by
printing the size of the previously mentioned database vector as so: `person.size()`.

The database "person" should be of the datatype "constants" which will be a custom made
datatype, to achieve this I added a header file called "constants.h" within here I declared
a struct called "constants" and declared the following types as string: firstName, lastName, signature
as well as something to keep track of a persons height, a float called: height.

The program will also need said menu which will be the very first function called within mainProgram.
This menu called `int mainMenu(std::vector<int> menu)` accepts a vector as parameter and returns an int, 
the menu prints a menu on the screen asking what the user would like to do, there are 7
different options to choose from. The user will select the appropriate alternative
by typing the corresponding number next to each alternative. This number will be validated
to make sure its within the menu range, as well as an integer, if not, the menu will
keep printing and asking the user for a valid input. Once a valid input has been
entered, the vector used as a parameter will be called in a push_back function to store
the integer as its entry. Once done, the validation iteration will break and return
the selected value as an integer to the mainProgram. 

The mainProgram will use the returned value from the menu and put it into a switch statement, find 
the corresponding case and call the relevant functions attached to it. The first `case 1:` will be the
option to add a person to the database. For this I decided to create a function called `constants inPerson();`
inPerson is a function declared by the structure of constants, meaning firstName, lastName, height and signature
will be accessible from here. Within the function inPerson the user is prompted to first enter
the persons first name, then if successful, enter the last name, if successful, enter the height, once the height
has been entered the program will start the process of adding these to a struct of constants called "person".

During the process of adding the names there have to be a few validations, there is no
person called "St35f93an" (Stefan) for instance, to solve this I created another function which
will make sure only letters as well as spaces are allowed to be put in for the names,
for the height only numbers will be accepted. If any of these return an error the program will
enter an iteration until the user gives it a valid input. I also took the liberty to uppercase
the first letter of every name seeing as all names start with a capitalized letter.

When adding the data to the struct the first name will be added to a person.firstName, the last name
will be added to person.lastName, height will be added to person.height. The signature should consists of the first 3
letters of the first name together with the 3 first letters of the last name, if either is smaller than 3
an 'x' should be added as a filling character. To achieve this I created two different substrings
from both the first and lastname, if either is smaller than 3 I will add an x until the size is equal to 3.
Once both substrings consists of 3 characters they will be added together to form the final signature. 

A copy of the struct person will be returned from the function, in this case it will be returned
to the function which called it, meaning our mainProgram. To fill up the vector in the mainProgram
I simply called the inPerson function within an emplace function, meaning whatever the inPerson function
returns will be stored in a new element of the vector declared in the mainProgram. This is how the
database will be filled up.

`Next case 2: ` will be calling a function to print the database on the screen, named `void printDatabase(const std::vector<constants>& print )` 
of type void, the function will return nothing but require a vector of struct constants as parameter. 
this needs to be done with a specific formatting. To achieve this I created another function called
`void formattingText(const std::vector<constants>& format)` which will accept a vector as argument, the vector called from
mainProgram will be sent into the formatting function and print out text on the screen. This is done to reduce
verbosity in the printDatabase program. Once called it clears the console of current text, and prints out formatting text
displaying what different values mean such as "IndexNumber, Signature, Name, Height", this should only be
called once per page so it felt fitting to create a separate function for it and call it as many times
as its needed, its a constant value and its not expected to change. 

The printDatabase function will use its vector and print it out in columns one at a time, once it reaches the height it will
create a new row and print the next person. A maximum of 20 members should be shown at a time, to achieve this I declared a counter
which will increase 1 for every person printed, once 20 is reached another function called `void pauseFunction(const std::string&)` will
be called, it accepts a text input as to be used in different future functions in case a pause is required. 
Once this pause function is called it will pause the printing, inform the user there is another page of members, and tells the
user to press any key to go to next page, this will also reset the counter to 0 and it will start counting up to 20 once more.
If counter does not reach 20 that means there are less than 20 people left, the program will instead inform the user
that the end of the database has been reached. Once the printing is finished, the console will be cleared as its returning to the mainProgram
which will once again call the mainMenu.

`Next case 3:` will be calling a function to search for a person within the database, that is, the vector, this
function will also be able to delete entries from the vector if the user so wishes. This function is defined
as `std::vector<constants> searchPerson(const std::vector<constants>& search);`. It requires a 
vector of the struct constants as argument, and returns a vector of the struct constants. Difference being
argument is a constant while the return is not, it is simply using the parameter as a reference to
search for the target. The parameter is being copied into another vector of the struct constants to use within the function. 
The user will be prompted to enter the signature of the person they wish to lookup, the input here will be a string, there is no
validation done here as it doesn't really matter exactly what the user types in, even if we know signatures never contain for instance numbers in this case.
If there is no match for what the user entered the function will simply inform the user that no such signature could be found within the database.

The searchTerm that the user entered earlier will be compared to the copy of the vector the function earlier initialized, every 
entry of signature within the vector will be compared to the search term, and if there is a match it will print all the full name, height as well
as the signature relevant to that person. There is also a header included to easier distinguish what value means what. When this match has been
found and the information have been printed it will ask the person if he/she wishes to remove the entry from the database. The choices will be made by entering
either 'Y' or 'N', lowercase will be changed to uppercase, and nothing but y/n or Y/n will be accepted, it will simply initiate a loop until the input is correct. 
If the user press 'N' the program will inform the user that the person was not removed from the database, and tell the user to press any key to continue. If 'Y' is however
pressed, the user will be removed from the database, if more than 1 person have the same signature it will also be removed, this is to remove duplicates in case there are any. 
This function will use bools to make sure the header is only printed once, as well as to make sure a match is found. If the header has been printed once, the
bool will be set to not print again, if there is no match for the searchterm, that bool will also change and inform the user that no match could be found.

Removing a person from the vector is a function itself declared as `void removeEntry(std::vector<constants> & persons, std::string searchTerm);`
it will return nothing, but accept both the entire vector, and the search term used when searching. The function will match the searchTerm to the signature
and if it is a match it will be erased using the erase() function, it will work its way through the beginning of the element to the end of the element. Once the element has been
finished it will continue to the next element, if there is no match for the search term it will do nothing. I used the pauseFunction from earlier several times in here as well
to pause the program at several points to signal the user that an action has been performed. Once this function has finished, the clear screen function will be called once 
more to make it neat and clean, the new vector will be returned to the mainProgram which will override the current vector, effectively saving any deletions made, no none are made,
the returned vector will just be an untouched vector of the one passed in as argument.

`Next case 4:` will call a function to sort the vector in a few different ways. To keep track of which sorting method to use, the function
will use an enumeration declared within constants.h header file. So first off it has to be declared, I decided to name it sortEnum and give it 4 different
values, those being: name, signature, height and random, which are the 4 different ways we will sort the vector by. To solve this the sort(); function found
within the algorithm library will be used, to sort randomly all I had to do was include the random library and call this within the sort() function. 

For the other 3 I had to create sorting algorithms myself, I made one for name, one for signature and one for height. Three simple bool functions were made,
the names will be sorted by lastNames, and if they are equal, it will sort by firstName, this function is declared as `bool sortName(const constants &a, const constants &b)`
it will be referencing to two constant values of the struct constants and simply use these as a means to reference when comparing size. The function will compare the size
between the lastNames, and if equal, compare firstNames, it will then return either lastName or firstName respectively in ascending order. The same is done for both sorting
by signature and height, except height will be sorted by descending order, and in case of height and signature there is no reason to make any exception
in case two of them match. 

To choose which method to use a submenu will first be called which is declared as `void sortMenu (std::vector<constants>& sortMenu)`, it will accept the vector 
to use as a means of going through the database to be able to sort it. This submenu will ask the user to choose what method to use, defined by numbers within 1-5 range,
it will use the users input into a switch to determine what approach the user chose. If 1, 2, 3 or 4 is entered it will sort by corresponding method, 
if 5 is pressed it will instead not sort and return to the main menu. If any other is selected the appropriate case will be chosen within the switch statement, and within here
the function sortPerson will be called, declared as `void sortPerson (std::vector<constants>& sort, enum sortEnum choice);`. It will return nothing but require the vector as argument
as well as the enumeration choice , provided by the switch statement correlating to it. Within the sortPerson function the choice will go through a switch statement and 
depending on its value it will either call the sort() function by the sorting algorithms. For instance shoosing "Sort by name" within the submenu will set the enum to name, call the sortPerson
function with "enum sortEnum name" as argument then use the sort() function and use sortName as sorting algorithm to sort by name. The same is done for signature, height and in random order.
Once done, the console will clear of any debris and return to the mainProgram once more, the sorted vector will now be loaded into the vector within mainProgram.

For `case 5:` and `case 6:` the vector consisting of persons will either be saved (case 5:) or a text file will be loaded into the vector (case 6:). I decided to explain these two
together as I think they have a lot in common, albeit vastly different method of implementation. Of course another function will be called from the mainProgram to handle this, the 
function for saving a file is declared as `void saveToFile(const std::vector<constants>& write)` and the function to save is declared as `std::vector<constants> loadFromFile()`
as seen in those two functions they are pretty much inverted. The save function won't return anything but require the databases vector as an argument, while the
load function don't require any argument, but will return a vector of the struct constants. This is because the save function won't have to return anything to store within
the database vector, while the load function won't require any input but will have to return a vector to be stored in the database. In both these cases the user should be 
able to both define the file name of the .txt file, as well as request a specific file to load into the database. 

I started with the save function, the user is asked what the saved file should be called, so a string was declared and the users input would be stored within. If its valid it will
continue, however there are several limitations regarding file names and for this a separate function has been created called validateFileName, it will make sure the file name
follows proper naming conventions. Together with the user input for fileName it will create a .txt file in the _Resources directory, the _Resources directory will be 2 steps
higher than the .exe file itself within my environment, so I added ../../ to go up 2 directories, then down _Resources directory and store the file there. Once the file has been
created it will be opened and input stream will be appending. A validation is made whether the file could successfully be opened if not, if it can't be opened it will inform the user of this and return to the main program.
If the file can be opened however, an iteration will begin going through the entire vector element by element and writing to the file. It will be written in order of name, height and lastly signature,
once signature has been written a new line will form and the iteration will begin anew, this will ensure one element per line, once an entry has been made a DELIM '|' will be 
added to separate the firstname, lastname, height and signature from eachother, this delim is declared within the constants.h header file. Once iteration is done, the file will close
and the user will be informed of the save file and its' name, the console will be cleaned of debris.

The load function will work backwords, it will need to open the same file the save function created, but load those values properly into a vector of the struct constants, and
return this vector to the main program. This is why we have the delims separating the different values. First off a structure of constants is declared, then a vector of the struct constants,
A string is created and the user is once more asked to enter the name of the file they wish to open, if the file cannot be found the user will be informed, and the
function will return to main menu. If the file can be found an instream will be established to allow reading, to easier load in the file to a vector I decided to replace any EOL
with delims, I did this by loading the entire file into a new string, then iterated through this string until an EOL was found, if found, I replaced it with a delim. I used the
replace() function found without algorithm for this, for every EOL found a counter would increase by 1 to keep track of how many persons were in the file.

Once done two pointers were created for iterating the string, those pointers will start by both pointing at the start of the new string, 
an iteration is done for the  entire length of the full string, for every string iterated pointer 2 will follow while pointer 1 remain. 
Once a delim is found a substring will be created consisting of the text between pointer 1 and pointer 2, pointer 1 will then assume pointer 2's position but 1 step ahead to skip the delim.
This will go on for the entire string until the end, each time a substring is created it will be loaded into a struct of constants in the same order as the file was saved to ensure
it will all be in correct places. Once the signature has been loaded in the struct of constants, the vector earlier declared within this function will emplace to open a new element
for writing, load in the substrings into the vector, the index for the vector will then increase by 1 to make sure no data is overwritten. This will go on as long as the vectors index (i)
is less than the counter previously counting amount of EOL before replacing them with delims. Once all iterations are done, the pause function will inform the user of
the success of loading the file, clear the screen and return the new vector to the mainProgram. This new vector will then be loaded into the database declared within the mainProgram.

For `case 7:` no function is actually called, case 7 breaks the switch statement and terminates the program.

For this program I have used several help functions, I used different functions to validate user input and called them appropriately as described above. I used
a console clearing function which will clear the console depending on which OS you are using, for windows it will call the SYSTEM("CLS") function, for unix, mach or apple it will
output "\033[2J\033[1;1H" which will clear the console, for any other system it will simply print 100 \n's to simulate a clean console, a crude method but it always works and its not
OS dependant. I used a pause function which accepts a string as an argument, whenever a pause is needed in the program this function can be called and text can be provided
as such "Pausing program, press key to continue". This function will clear the cin stream and wait for the user to press any key before it continues, the text it provides is
as stated determined by case-to-case which allows for much for freedom than having a standard message whenever called for. I used this function many times within the program
and I think it looks clean and sturdy.

Overall this project was fun, it had several obstacles but most of the solutions were nearby as we have worked with such problems earlier.

## Discussion
The programs intent were to act as a database, I would say the end result is a working database. It is plausible for the user if he so wish to add people
to the database, it is possible to remove them, sorting by several different pre-determined methods, the user may search for users within the database.
In addition to this, it is also possible to save the database as a .txt file as well as load a .txt file into the database and store its contents within the program.
This allows the user to have several separate databases saved locally as a txt file and load them into the database as they please.

Every step proved a challenge, from the menu, to the sorting, from the search functions to the file handling functions. These challenges were overcome albeit
relatively easy I would say, that is due to previous exercises preparing me for just this project. Several parts during both earlier exercises as well as laborations 
have had me wondering what the purpose of such methods would be, however during the project the past experiences proved valuable. It would have been way harder and taken
a long time to get this database program finished in time if it wasn't for the previous laborations and exercises, many implementations became clear as I had seen problems
alike them earlier in the course. 

I have learned a great deal especially regarding enumerations, sort() function, as well as reading in from a file. These were three parts I had either very little
experience in (enumerations) or something I hadn't done before (sort and read from file) at all. I am sure there are way more efficient implementation methods to solve this
project, but all in all I am contempt with it, I used a lot of extra functions to get the work done and have a cleaner program. If I had to do something more than once I made sure to add
it to either a function or an iteration so there shouldn't be any redundancies, at least not any obvious ones. I had a hard time reading contents from a file while 
being certain they were being read in the correct order and stored accordingly, it wasn't before I removed all the new lines and replaced them with a delim '|', it feels
like a very crude approach to the problem, but a solution it is nonetheless. I have tried breaking my program several times, sent it out to fellow classmates, my friends and family
they have tested the program and so far no-one have reported anything being broken. However I did not implement uniqueness of the signatures which is definitely something
I should have done as it would have made the program much prettier and more sturdy, for instance, the function to remove someone from the database will first search a person
by its signature, then delete any names attached to this signature, this means any person which accidentally have the same signature as someone else will have their entry deleted
from the database. ~~It is not the biggest issue in a small testing environment as this one, but in a more serious environment it would be a huge flaw, if I had just one extra day
I would tackle this issue next. My method of implementation would be to create a copy of the original database and store it in a vector in a separate function, every time something is
to happen with the database, be it write to file, read from file, print on screen, search or whatnot, this function would accept a vector as argument and within the function
it would iterate through the vector, if a match is made between 2 signatures, the first signature would be given the value of an integer predetermined to "02" and increase this
integer by one, pointers would increase and the iteration would continue. As soon as the inPerson have added a person and stored it in the database, a function right below it would run which would
check the entire vector once more, whenever it found a signature shorter than 6 long (meaning no numbers are attached to it), it would add 01~~

While typing this I definitely changed my mind regarding the above implementation. For the signatures uniqueness I would create a vector within the inPerson()
function and store every value added through this function in here. As there would be not other way to add something to the database except editing text files, those
should however be encrypted in the future which would prevent that method. Adding signatures directly when adding a person would work I believe, an iteration would go through
the currently existing vector and if the signature about to be added already exists, its counter would increase by 1 (from 01 to 02 for instance). This also means an issue
will occur if the user at a later stage determine they want to search, and delete an entry from the database, to circumvent this problem I would need to store the newly created vector
after the deletion was made, within the inPerson() function as well. Which is why the inPerson would need to accept a vector as an argument, I am not entirely sure exactly
how I would implement this method but it is certainly something I will think about and try to circumvent as the idea of uniqueness intrigues me. 

I definitely struggled a bit with read from file and I feel like there is verbosity as well as redundancies within it, this is something I intend to change but I also
had a tough time comprehending how to read from the file if I didn't do what I did. Also for the save to file I had to create a function to block certain characters and make sure you
couldn't save a file as one of the reserved names within the windows OS. I probably didn't have to enter each one individually as I assume there is a library gathered with all
these restrictions, I could not find such a library so it might not exist however. 

Overall this assignment have definitely fulfilled its purpose, when I first started the project I felt like I had no idea where to start, it took me way too long to get going
on the first part of the program, I started off with the mainmenu and got it rolling, afterwards I went through each of the switches and added functions accordingly to one another,
I am actually pleased with the result and to achieve my result I had to have understanding and knowledge of the points listed under purpose, I can safely say everything
listed under purpose had to be used to achieve the result this projects aim to accomplish.