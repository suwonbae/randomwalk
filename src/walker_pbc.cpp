#include "walker_pbc.h"
#include "tools.h"

#include <vector>
#include <random>

WalkerPBC::WalkerPBC( int length ): Walker(length) {}

WalkerPBC::~WalkerPBC() {}

void WalkerPBC::run( int steps ) {    	

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

	// travel beyond boundaries
	if (X > L/2) {
	    X = X % (L/2) + (-L/2);
	}
	if (X < -L/2) {
	    X = X % (L/2) + L/2;
	}
	if (Y > L/2) {
	    Y = Y % (L/2) + (-L/2);
	}
	if (Y < -L/2) {
	    Y = Y % (L/2) + L/2;
	}

	trajectory.push_back(std::vector<int> {X, Y});

	steps -= 1;
    }
}
