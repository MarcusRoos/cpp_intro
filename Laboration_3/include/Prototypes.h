#ifndef DT018G_PROTOTYPES_H
#define DT018G_PROTOTYPES_H

#include "Stats.h"
#include <iostream>
#include <chrono>
#include <limits>
#include <iomanip>
#include <fstream>

using namespace std;
/**
 BerÃ¤knar fibonacci sekvensen med hjÃ¤lp av iteration, anvÃ¤nder nth som param.
 @param nthNumber, bestÃ¤mmer hur mÃ¥nga gÃ¥nger funktionen ska kÃ¶ras.
 @return returnerar resultatet av iteration.
 */
long_type fibonacciIteration(size_t nthNumber);
/**
 BerÃ¤knar fibonacci sekvensen med hjÃ¤lp av recursion, anvÃ¤nder nth som param.
 @param nthNumber, bestÃ¤mmer hur mÃ¥nga gÃ¥nger funktionen ska kÃ¶ras.
  @return returnerar resultatet av recursion.
 */
long_type fibonacciRecursion(size_t nthNumber);

/**
 HÃ¤rifrÃ¥n exekveras funktionerna fibonacciIteration samt recursion, Ã¤ven
 tidsÃ¥tgÃ¥ngen fÃ¶r respektive metod kommer att lagras via denna funktion.
 @param nthNumber, fÃ¥r funktionen frÃ¥n huvudmenyn och passeras vidare till
 iteration och recursions respektive funktioner.
  @return returnerar en vektor dÃ¤r de olika metoderna Ã¤r lagrade i strukturen
  Stats.
 */
std::vector<Stats> fibonacciTimer(size_t nthNumber);

/**
 Skriver ut tidsÃ¥tgÃ¥ngen fÃ¶r respektive metod pÃ¥ skÃ¤rmen.
 @param & stats anvÃ¤nder Stats som referens, hela datastrukturen finns refererad
 till.
 @return void.
 */
void printStats(const std::vector<Stats>& stats);

/**
 Parametern anvÃ¤nds fÃ¶r att skriva Ã¶ver stats-strukturen pÃ¥ tvÃ¥ olika filer.
 @param Stats& stats, datastrukturen Stats passeras till denna funktion.
 @return void.
 */
void writeToFile(const Stats& stats);

/**
 Fungerar som huvudmeny, binder samman de olika funktionerna.
 @return void.
 */
void mainMenu();

/**
 Fungerar som submeny, anvÃ¤nds fÃ¶r att skriva in vÃ¤rdet nthNumber.
 @return returnerar nthNumber som skrivs in i submenyn.
 */
size_t subMenu();

/**
 Lagrad hÃ¥rdkodad text, fÃ¶r att minska verbositeten.
 @return void.
 */
void textMenu();


#endif //DT018G_PROTOTYPES_H
