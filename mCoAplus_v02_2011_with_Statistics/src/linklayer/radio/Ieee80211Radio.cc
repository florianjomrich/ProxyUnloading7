//
// Copyright (C) 2006 Andras Varga, Levente Meszaros
// Based on the Mobility Framework's SnrEval by Marc Loebbers
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

#include "Ieee80211Radio.h"

//PROXY UNLOADING
using std::cout;
#include "IPv6NeighbourDiscovery.h"
#include "SignalUpdate_m.h"

Define_Module(Ieee80211Radio);



void Ieee80211Radio::sendUp(AirFrameExtended *airframe){



    //PROXY UNLOADING FJ

    cPacket *frame = airframe->dup()->decapsulate();

       if (!strcmp(airframe->getName(), "RApacket")) {
          //  //cout << "VOM WIFI MODUL ABEGRIFFENES PAKET:" << airframe->getName()
              //     << " SNR of it: " << airframe->getSnr() << " SENDING Position: "
              //     << airframe->getSenderPos() << endl;
           // //cout <<" Ieee80211Frame: "<<frame2->getName()<<endl;

           //VERY IMPORTANT TO MAKE A COPY !!!
           cPacket* frame2 = frame->dup();
           cPacket* packet1 = check_and_cast<cPacket*>(frame2->decapsulate());

           cPacket* packet2 = check_and_cast<cPacket*>(packet1->decapsulate());

          //  //cout << "Packet 1: " << packet1->getName() << endl;
           // cPacket* packet2 = packet1->decapsulate();
       //    if (dynamic_cast<ICMPv6Message *>(packet1)) {
            //    //cout <<" HALLO WELT"<<endl;


        //   }
           if (dynamic_cast<IPv6RouterAdvertisement*>(packet2)) {
               IPv6RouterAdvertisement* advertisement = check_and_cast<
                       IPv6RouterAdvertisement*>(packet2);

              //  //cout << advertisement->getSourceLinkLayerAddress()<<endl;

               // //cout << "Es ist ein RA Paket !!!" << endl;

               /*IPv6ControlInfo *ctrlInfo = check_and_cast<IPv6ControlInfo*>(
                                             packet1->getControlInfo());
                                      //cout << "SourceAddresse:" << ctrlInfo->getSrcAddr() << endl;*/

               SignalUpdate* newSignalReceived = new SignalUpdate();
               newSignalReceived->setValueOfSNR(airframe->getSnr());
               newSignalReceived->setAccessPoint(advertisement->getSourceLinkLayerAddress().str().c_str());
               newSignalReceived->setName("SignalUpdate To ProxyApp");

              send(newSignalReceived->dup(),"signalUpdateChannelToProxyControlApp");

           }

       }

       //##################


       //old stuff:
          AbstractRadioExtended::sendUp(airframe);
}
