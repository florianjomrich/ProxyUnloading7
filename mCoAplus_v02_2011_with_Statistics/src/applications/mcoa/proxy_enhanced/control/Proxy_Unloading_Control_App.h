//
// Copyright (C) 2010 Bruno Sousa
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program; if not, see <http://www.gnu.org/licenses/>.
//

//
// based on the video streaming app of the similar name by Johnny Lai
//

#ifndef __INET_UDPVIDEOCLI_H
#define __INET_UDPVIDEOCLI_H

#include <omnetpp.h>
#include "MCoAUDPBase.h"
#include "MCoAVideoStreaming_m.h"

//Messages for Proxy Unloading inculded:
#include "RequetConnectionToLegacyServer_m.h"
#include "FlowBindingUpdate_m.h"
#include "ACK_Request_m.h"
#include "SetAddressActive_m.h"
#include "ACK_FlowBinding_m.h"
#include "ACK_SetAddressActive_m.h"
#include "SignalUpdate_m.h"
#include "SetChannelActive_m.h"

/**
 * A "Realtime" VideoStream client application.
 *
 * Basic video stream application. Clients receive streams from server.
 * video back.
 */
class INET_API Proxy_Unloading_Control_App: public MCoAUDPBase {
protected:

    struct statPacketVIDEO {
        long seq;
        bool treated;
        long delay;
    };
    typedef std::map<long, statPacketVIDEO> SPkt;
    SPkt StatsPkt;

    // statistics
    cOutVector PktRcv;
    cOutVector PktLost;
    cOutVector PktDelay;

    long lastSeq;

    //For ProxyUnloading FJ
    bool isMN;
    bool isHA;
    bool isCN;
    bool isCapableCN;
    const char* humanReadableName;

    double greatestReceivedSignalStrengthSoFar;
    const char* AccessPointWithGreatestReceivedSignalStrengthSoFar;

    //for timing - and resending if no Ack was received
    std::vector<FlowBindingUpdate*> flowBindingUpdatesToSend;
    std::vector<RequetConnectionToLegacyServer*> requestForConnectionToSend;
    std::vector<SetAddressActive*> addresseToBeSetActive;

    //counts for the MN if it gets to 5 - MN assumes CN as not capable
    int requestForConnectionToSendCounter;

    double setActiveIPAddressTimeOut;
    double requestForConnectionTimeOut;
    double flowBindingUpdateTimeOut;
    double signalUpdateTimeOut;
    simtime_t startTime;

    //timing messages
    cMessage* flowBindingUpdatestimeOutMessage;
    cMessage* requestForConnectionTimeOutMessage;
    cMessage* setActiveIPAddressTimeOutMessage;
    cMessage* signalUpdateTimeOutMessage;

protected:
    ///@name Overridden cSimpleModule functions
    //@{
    virtual void initialize();
    virtual void finish();
    virtual void handleMessage(cMessage *msg);
    virtual void sendChangeDataFlowMessage(int corresPondentNodeToReceive);
    //@}

};

#endif

