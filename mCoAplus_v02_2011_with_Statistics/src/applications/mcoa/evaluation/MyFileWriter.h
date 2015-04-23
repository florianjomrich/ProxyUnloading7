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

#ifndef MYFILEWRITER_H_
#define MYFILEWRITER_H_

#include <omnetpp.h>

class MyFileWriter {
public:
    MyFileWriter();
    virtual ~MyFileWriter();
    virtual void printOutStringToFile(const char* name,char* explanationText, int seqNumber, const char* simTime );
    virtual void printOutPackageLossCounter(const char* name,char* explanationText,int packagesSentCounter, int packagesReceivedCounter, const char* simTime );
    virtual void printOutFBUs(const char* CoA, const char* simTime );
    virtual void printOutBindingUpdates(const char* HoAofMN,const char* newCoA ,const char* destAddress , const char* simTime );
};

#endif /* MYFILEWRITER_H_ */
