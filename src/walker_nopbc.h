#ifdef WALKER_CLASS

WalkerStyle(nopbc,WalkerNOPBC)

#else

#ifndef WALKER_NOPBC_H
#define WALKER_NOPBC_H

#include "walker.h"

class WalkerNOPBC: public Walker {
public:
    WalkerNOPBC( int length );

    virtual ~WalkerNOPBC();

    void run( int step );
};

#endif
#endif
