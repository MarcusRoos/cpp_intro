#ifndef DT018G_PROTOTYPES_H
#define DT018G_PROTOTYPES_H

#include "Stats.h"
#include <iostream>
#include <chrono>
#include <limits>
#include <iomanip>
#include <fstream>

using namespace std;

long_type fibonacciIteration(size_t nthNumber);
long_type fibonacciRecursion(size_t nthNumber);
std::vector<Stats> fibonacciTimer(size_t nthNumber);

void printStats(const std::vector<Stats>& stats);
void writeToFile(const Stats& stats);

void mainMenu();
size_t subMenu();
void textMenu();

#endif //DT018G_PROTOTYPES_H
