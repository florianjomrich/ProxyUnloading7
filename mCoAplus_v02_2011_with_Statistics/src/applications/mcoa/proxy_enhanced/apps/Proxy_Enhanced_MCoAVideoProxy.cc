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

#include "Proxy_Enhanced_MCoAVideoProxy.h"
#include "IPAddressResolver.h"
#include "IPv6ControlInfo.h"

#define PROXY_ENHANCED_BU_MESSAGE  42

using std::cout;

Define_Module(Proxy_Enhanced_MCoAVideoProxy);


void Proxy_Enhanced_MCoAVideoProxy::initialize()
{
    //PROXY UNLOADING FJ
    cout<<"Initializing Proxy_Enhanced_MCoAVideoPROXY module"<<endl;
    startTime = par("startTime");


	MCoAUDPBase::startMCoAUDPBase();

	PktRcv.setName("MCOA VIDEO Packet Rcv");
	PktLost.setName("MCOA VIDEO Packet Lost");
	PktDelay.setName("MCOA VIDEO Delay");

    lastSeq=0;

    int localPort = par("localPort");
    //cout<<"LOCAL PORT:"<<localPort <<endl;
    bindToPort(localPort);



}

void Proxy_Enhanced_MCoAVideoProxy::finish()
{
	//Delete StatsPkt
	StatsPkt.clear();

}

void Proxy_Enhanced_MCoAVideoProxy::handleMessage(cMessage* msg)
{

    	cout<<"HA PROXY APP HAT erhalten:"<< msg->getName() <<endl;

}




