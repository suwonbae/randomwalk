#ifndef WALKER_H
#define WALKER_H

#include <vector>

// define class
class Walker {
public:
    Walker( int length );

    virtual ~Walker();

    // run random walk process for given steps
    virtual void run( int ) {}

    // set boundary by providing L
    void setBoundary( int length );

    // accessor function that prints out the current position and steps required to get to the origin
    void printPosition();

protected:
    int count; // count walking steps
    int X, Y; // X and Y coordinates
    int L; // length
    std::vector<std::vector<int>> trajectory; // trajectory array
};

#endif
