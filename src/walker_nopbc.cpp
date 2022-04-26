#include "walker_nopbc.h"
#include "tools.h"

#include <vector>
#include <iostream>
#include <random>

WalkerNOPBC::WalkerNOPBC( int length ): Walker(length) {}

WalkerNOPBC::~WalkerNOPBC() {}

void WalkerNOPBC::run( int steps ) {    	
    count = 0;

    std::cout << count << " (" << X << ", " << Y << ")" << std::endl;

    std::random_device rd;
    std::mt19937 gen(rd() + time(0));
	
    while (steps > 0) {
	// decide direction: 0 = horizontal, 1 = vertical
	int direction = (next_rand_val(gen) > 0.5) ? 1 : 0;
	// foward or backward: 1 = forward, -1 = backward
	int fb = (next_rand_val(gen) > 0.5) ? 1 : -1;

	if (direction == 0) {
	    X += fb;
	} else {
	    Y += fb;
	}

	// bounced back at boundaries
	if (X > L/2) {
	    X -= 2;
	}
	if (X < -L/2) {
	    X += 2;
	}
	if (Y > L/2) {
	    Y -= 2;
	}
	if (Y < -L/2) {
	    Y += 2;
	}

	count += 1;
	std::cout << count << " (" << X << ", " << Y << ")" << std::endl;
	trajectory.push_back(std::vector<int> {X, Y});

	steps -= 1;
    }
}

