
/* * $Id$
 *
 *                    L O S  A L A M O S
 *              Los Alamos National Laboratory
 *               Los Alamos, New Mexico 87545
 *
 *  Copyright, 1986, The Regents of the University of California.
 *
 *  Author: Jeff Hill
 */

#include "iocinf.h"

tcpSendWatchdog::tcpSendWatchdog 
    ( tcpiiu &iiuIn, double periodIn, epicsTimerQueue & queueIn ) :
    period ( periodIn ), timer ( queueIn.createTimer ( *this ) ),
    iiu ( iiuIn )
{
}

tcpSendWatchdog::~tcpSendWatchdog ()
{
    delete & this->timer;
}

epicsTimerNotify::expireStatus tcpSendWatchdog::expire ()
{
    char hostName[128];
    this->iiu.hostName ( hostName, sizeof ( hostName ) );
    ca_printf ( "Request not accepted by CA server %s for %g sec. Disconnecting.\n", 
        hostName, this->period );
    this->iiu.forcedShutdown ();
    return noRestart;
}

void tcpSendWatchdog::start ()
{
    this->timer.start ( this->period );
}

void tcpSendWatchdog::cancel ()
{
    this->timer.cancel ();
}

