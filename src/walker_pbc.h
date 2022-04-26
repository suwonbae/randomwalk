#ifdef WALKER_CLASS

WalkerStyle(pbc,WalkerPBC)

#else

#ifndef WALKER_PBC_H
#define	WALKER_PBC_H

#include "walker.h"

class WalkerPBC: public Walker {
public:
    WalkerPBC( int length );

    virtual ~WalkerPBC();

    void run( int step );
};

#endif
#endif
