#include <iostream>
#include <map>
#include <string>
#include <stdlib.h>

#include "walker_style.h"
#include "walker.h"

typedef Walker *(*WalkerCreator)(int);
typedef std::map<std::string, WalkerCreator> WalkerCreatorMap;

template <typename T> static Walker *walker_creator(int);

int main(int argc, char *argv[]) {

    if (argc < 3) std::cout << "3 args required; style L steps" << std::endl;

    char *pbc = argv[1];
    int L = atoi(argv[2]);
    int steps = atoi(argv[3]);

    Walker *walker;

    WalkerCreatorMap *walker_map;
    walker_map = new WalkerCreatorMap();

#define WALKER_CLASS
#define WalkerStyle(key,Class) \
  (*walker_map)[#key] = &walker_creator<Class>;
#include "walker_style.h"
#undef WalkerStyle
#undef WALKER_CLASS

    // declare walker
    WalkerCreator &walker_creator = (*walker_map)[pbc];
    walker = walker_creator(L);

    // set boundary length
    //walker->setBoundary(10);

    // print out current poisition before starting a randam walk process
    //walker->printPosition();

    // run a random walk process for the given steps
    walker->run(steps);

    // print out current position
    // and steps required to get back to the origin if the current position is not origin
    walker->printPosition();

    if (walker) delete walker;

    return 0;
}

template <typename T>
Walker *walker_creator( int length ) {
  return new T(length);
}
