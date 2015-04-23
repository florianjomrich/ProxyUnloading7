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

#ifndef FLOWBINDINGENTRY_H_
#define FLOWBINDINGENTRY_H_

class FlowBindingEntry {
public:
    int srcPort;
    int destPort;
    const char* srcAddress;
    const char* destAddress;
    int localHostIdentifier;
    bool isActive;
    bool forThisConncectionCNisCapable;
    int channelNumber;

    FlowBindingEntry();
    FlowBindingEntry(int srcPort, int destPort,const char* srcAddress,const char* destAddress,int localHostIdentifier, bool isActive,bool forThisConncectionCNisCapable,int channelNumber);
    virtual ~FlowBindingEntry();

    const char* getDestAddress() const {
        return destAddress;
    }

    void setDestAddress(const char* destAddress) {
        this->destAddress = destAddress;
    }

    int getDestPort() const {
        return destPort;
    }

    void setDestPort(int destPort) {
        this->destPort = destPort;
    }

    const char* getSrcAddress() const {
        return srcAddress;
    }

    void setSrcAddress(const char* srcAddress) {
        this->srcAddress = srcAddress;
    }


   int getSrcPort() const {
        return srcPort;
    }

    void setSrcPort(int srcPort) {
        this->srcPort = srcPort;
    }

    void setLocalHostIdentifier(int localHostIdentifier){
        this->localHostIdentifier = localHostIdentifier;
    }

   int getLocalHostIdentifier() const {
        return localHostIdentifier;
    }

    bool getIsActive() const {
         return isActive;
     }

     void setIsActive(bool isActive) {
         this->isActive = isActive;
     }


      bool getForThisConncectionCNisCapable(){
          return forThisConncectionCNisCapable;
      }

      void setForThisConncectionCNisCapable(bool status){
          this->forThisConncectionCNisCapable = status;
      }

      int getChannelNumber(){
          return channelNumber;
      }

      void setChannelNumber(int status){
          this->channelNumber = status;
      }
};

#endif /* FLOWBINDINGENTRY_H_ */
