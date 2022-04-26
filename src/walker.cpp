#include "walker.h"
#include "tools.h"

#include <vector>
#include <iostream>
#include <random>
#include <stdio.h>
#include <cmath>
#include <stdexcept>
#include <fstream>

Walker::Walker( int length ): L(length) {
    X = 0;
    Y = 0;
    trajectory.push_back(std::vector<int> {X, Y});
}

Walker::~Walker() {}

void Walker::setBoundary( int length ) {
    L = length;
}

void Walker::printPosition() {
    std::cout << "Now located at ("<< X << ", " << Y << ")" << std::endl;
    
    // print out steps required if the position is not the origin
    if ( (X != 0) && (Y != 0) )
        std::cout << "It take " << abs(X) + abs(Y) << " steps to return to the origin" << std::endl;
}

