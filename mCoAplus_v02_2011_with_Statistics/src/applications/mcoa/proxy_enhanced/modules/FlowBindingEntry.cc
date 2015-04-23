//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include <FlowBindingEntry.h>

FlowBindingEntry::FlowBindingEntry() {
    // TODO Auto-generated constructor stub

}

FlowBindingEntry::~FlowBindingEntry() {
    // TODO Auto-generated destructor stub
}

FlowBindingEntry::FlowBindingEntry(int srcPort, int destPort,const char* srcAddress,const char* destAddress,int localHostIdentifier, bool isActive,bool forThisConncectionCNisCapable,int channelNumber){
    this->srcPort=srcPort;
    this->destPort=destPort;
    this->srcAddress=srcAddress;
    this->destAddress=destAddress;

    this->localHostIdentifier=localHostIdentifier;
    this->isActive=isActive;
    this->forThisConncectionCNisCapable=forThisConncectionCNisCapable;
    this->channelNumber=channelNumber;
}
