#ifndef DT018G_STATS_H
#define DT018G_STATS_H

#include <string>
#include <vector>

typedef unsigned long long long_type;

struct Stats {  /*  Datastruktur för stats, objekt som ska hålla koll på
                    diverse stats från fibonacciTimer.*/
    std::string type; // Håller reda på olika typerna iteration/recursion
    std::vector<long_type> values; // Lagrar värden från iteration/recursion
    long_type nanosec=0, microsec=0, millisec=0; /* Lagrar tidsåtgången från
 *              de olika funktionerna, mer specifikt iteration/recursion. */
    double sec=0; // Samma som ovan fast per sekund, behandlas som en double.
};

#endif //DT018G_STATS_H
