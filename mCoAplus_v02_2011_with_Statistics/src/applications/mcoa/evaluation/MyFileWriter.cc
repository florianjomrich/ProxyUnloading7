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

#include <MyFileWriter.h>

#include <iostream>
#include <fstream>

using std::cout;


MyFileWriter::MyFileWriter() {
    // TODO Auto-generated constructor stub
    //delete the old data sets:
    std::remove("SendingAndRecevingTimesAlleKnotenZusammen.csv");
    std::remove("PackageLossAllTogether.csv");
}

MyFileWriter::~MyFileWriter() {
    // TODO Auto-generated destructor stub
}


void MyFileWriter::printOutStringToFile(const char* name,char* explanationText, int seqNumber, const char* simTime ){

 //cout<<"Print to file: "<<name<<" "<<explanationText<<"Sequenz-Nummer: "<<seqNumber<<" SimTime: "<<simTime<<endl;

    /*
 std::ofstream myfile;
 std::string sname = name;
 sname = "SendingAndRecevingTimes"+sname+".csv";
 myfile.open (sname.c_str(), std::ios::out | std::ios::app );
 myfile <<name<<","<<explanationText<<";"<<seqNumber<<";"<<simTime<<endl;
 myfile.close();*/


 std::ofstream myfileAllTogether;
 std::string sname2 = "SendingAndRecevingTimesAlleKnotenZusammen.csv";
 myfileAllTogether.open (sname2.c_str(), std::ios::out | std::ios::app );
 myfileAllTogether <<name<<","<<explanationText<<";"<<seqNumber<<";"<<simTime<<endl;
 myfileAllTogether.close();


}


void MyFileWriter::printOutPackageLossCounter(const char* name,char* explanationText,int packagesSentCounter, int packagesReceivedCounter, const char* simTime ){

 //cout<<"Print to file: "<<name<<" "<<explanationText<<"Sequenz-Nummer: "<<seqNumber<<" SimTime: "<<simTime<<endl;

    /*
 std::ofstream myfile;
 std::string sname = name;
 sname = "PackageLoss"+sname+".csv";
 myfile.open (sname.c_str(), std::ios::out | std::ios::app );
 myfile <<name<<","<<explanationText<<";"<<packagesSentCounter<<";"<<packagesReceivedCounter<<";"<<simTime<<endl;
 myfile.close();*/


 std::ofstream myfileALL;
 std::string sname2 = "PackageLossAllTogether.csv";
 myfileALL.open (sname2.c_str(), std::ios::out | std::ios::app );
 myfileALL <<name<<","<<explanationText<<";"<<packagesSentCounter<<";"<<packagesReceivedCounter<<";"<<simTime<<endl;
 myfileALL.close();




}



void MyFileWriter::printOutFBUs(const char* CoA, const char* simTime ){

 //cout<<"Print to file: "<<name<<" "<<explanationText<<"Sequenz-Nummer: "<<seqNumber<<" SimTime: "<<simTime<<endl;

 /*std::ofstream myfile;
 std::string sname = "FBUs.csv";
 myfile.open (sname.c_str(), std::ios::out | std::ios::app );
 myfile <<CoA<<";"<<simTime<<endl;
 myfile.close();*/
}


void MyFileWriter::printOutBindingUpdates(const char* HoAofMN,const char* newCoA ,const char* destAddress , const char* simTime ){

    //cout<<"Print to file: "<<name<<" "<<explanationText<<"Sequenz-Nummer: "<<seqNumber<<" SimTime: "<<simTime<<endl;

    /*std::ofstream myfile;
    std::string sname = "ClassicBindingUpdates.csv";
    myfile.open (sname.c_str(), std::ios::out | std::ios::app );
    myfile <<"Home Address of MN: "<<HoAofMN<<"; New Care of Address: " <<newCoA<<"; DestAddress: "<<destAddress<<"; SimTime: "<<simTime<<endl;
    myfile.close();*/
   }
