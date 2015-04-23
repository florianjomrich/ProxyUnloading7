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

#include "Proxy_Enhanced_MCoAVideoCli.h"
#include "IPAddressResolver.h"
#include "IPv6ControlInfo.h"
#include "RequestVideoStream_m.h"
#include "VideoMessage_m.h"
#include "UDPControlInfo_m.h"

#define PROXY_ENHANCED_BU_MESSAGE  42
#define PROXY_CN_MESSAGE_TO_MOBILE_NODE 43
#define PROXY_MESSAGE_FROM_CN_TO_MN 51
#define REQUEST_FOR_NEW_VIDEO_PAKET 147

using std::cout;

Define_Module(Proxy_Enhanced_MCoAVideoCli);

void Proxy_Enhanced_MCoAVideoCli::initialize() {
    //PROXY UNLOADING FJ
    cout << "Initializing Proxy_Enhanced_MCoAVideoCli module" << endl;
    startTime = par("startTime");
    seq_number_counter = 0;
    waitInterval = &par("waitInterval");
    mobileNodeNumber = par("mobileNodeNumber");

    //for evaluation:
    fileWriter = MyFileWriter();
    packagesSendCounter = 0;
    packagesReceivedCounter = 0;

    MCoAUDPBase::startMCoAUDPBase();

    PktRcv.setName("MCOA VIDEO Packet Rcv");
    PktLost.setName("MCOA VIDEO Packet Lost");
    PktDelay.setName("MCOA VIDEO Delay");

    lastSeq = 0;

    int localPort = par("localPort");
    bindToPort(localPort);

    if (startTime >= 0) {
        cMessage *start_proxying_context = new cMessage(
                "Starting_Proxying_Context MCoAVideoCli");
        //timer->setContextPointer(d);
        start_proxying_context->setKind(PROXY_CONTEXT_START);
        scheduleAt(startTime, start_proxying_context);

    }

}

void Proxy_Enhanced_MCoAVideoCli::finish() {
    //Delete StatsPkt
    StatsPkt.clear();

}

void Proxy_Enhanced_MCoAVideoCli::handleMessage(cMessage* msg) {
    if (msg->isSelfMessage()) {
        if (msg->getKind() == MK_REMOVE_ADDRESS_PAIR) {
            MCoAUDPBase::treatMessage(msg);

            return; // and that's it!
        }
        if (msg->getKind() == PROXY_CONTEXT_START) {
            cout << "!! Proxying Context Started !!" << endl;
            sendControlData(msg);

        }
        if (msg->getKind() == REQUEST_FOR_NEW_VIDEO_PAKET) {

            sendControlData(msg);

        }

    } else {

        if (dynamic_cast<VideoMessage*>(msg)) {

            VideoMessage* currentVideoMessage = dynamic_cast<VideoMessage*>(msg);
            cout << "MCoAClient " << MCoAUDPBase::getHumanReadabelName()
                    << ": Video Message from Server ist eingegangen mit sequence number: "
                    << currentVideoMessage->getSequenceNumber() << endl;

            UDPControlInfo* myControllInfo = check_and_cast<UDPControlInfo*>(
                    msg->getControlInfo());
            IPvXAddress srcIPAdresse = myControllInfo->getSrcAddr();
            cout << "MCoAClient: Absender des Pakets war: " << srcIPAdresse
                    << endl;

            if (currentVideoMessage->getSequenceNumber()
                    >= seq_number_counter) {

                //#############################################
                //write log for evaluation:

                //write out the latencies
                simtime_t difference = simTime() - messageLastTimeWasSent;

                fileWriter.printOutStringToFile(
                        MCoAUDPBase::getHumanReadabelName(),
                        "Video Message erhalten: ", packagesReceivedCounter,
                        difference.str().c_str());

                //#############################################

                //#############################################
                //write log for evaluation:
                //a package is send over all the Wifi Modules that are available from MCoA and could be received therefore more often as well - so this is no package loss than
                //increase the packageLossCounter and decrease it with each received package:
                packagesReceivedCounter++;
                fileWriter.printOutPackageLossCounter(
                        MCoAUDPBase::getHumanReadabelName(),
                        "Momentanter Package Loss Counter: ",
                        packagesSendCounter, packagesReceivedCounter,
                        simTime().str().c_str());
                //#############################################

                seq_number_counter++;
                delete msg;
                return;
            }

            cout << "Sequenz Nummer war bereits zu klein" << endl;
            delete msg;

        }

        else {
            cout << "MCoAClient of " << MCoAUDPBase::getHumanReadabelName()
                    << " received unkown message: " << msg->getName() << endl;

        }
    }
}

void Proxy_Enhanced_MCoAVideoCli::sendControlData(cMessage* msg) {

    //choose one of the available CNs as a communication entity
    IPvXAddress cn;
    if ((mobileNodeNumber % 2) == 0) {
        cn = IPAddressResolver().resolve("CN[0]");
    } else {
        cn = IPAddressResolver().resolve("CN[1]");
    }

    RequestVideoStream* requestVideoStream = new RequestVideoStream();
    requestVideoStream->setName(
            "MCoACli (MN) requests Video Stream from MCoASrv (CN).");
    requestVideoStream->setSequenceNumber(seq_number_counter);

    sendToUDPMCOA(requestVideoStream, localPort, cn, 1000, true); //Port 1000 für Video - Port 2000 für Kontrolldaten

    //#############################################
    //write log for evaluation:
    // fileWriter.printOutStringToFile(MCoAUDPBase::getHumanReadabelName(),
    //       "Video Message gesendet: ", seq_number_counter,
    //       simTime().str().c_str());
    messageLastTimeWasSent = simTime();



    //#############################################

    //#############################################
    //write log for evaluation:
    //a package is send over all the Wifi Modules that are available from MCoA and could be received therefore more often as well - so this is no package loss than
    //increase the packageLossCounter and decrease it with each received package:
    packagesSendCounter++;
    fileWriter.printOutPackageLossCounter(MCoAUDPBase::getHumanReadabelName(),
            "Momentanter Package Loss Counter: ", packagesSendCounter,
            packagesReceivedCounter, simTime().str().c_str());
    //#############################################

    //request next video package
    cMessage *requestForNewVideoPaket = new cMessage(
            "Request for new Video Paket");
    requestForNewVideoPaket->setKind(REQUEST_FOR_NEW_VIDEO_PAKET);

    simtime_t interval = (*waitInterval);
    scheduleAt(simTime() + interval, requestForNewVideoPaket);

    delete msg;
}

