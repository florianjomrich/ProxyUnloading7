//
// Generated file, do not edit! Created by opp_msgc 4.4 from applications/mcoa/VoIP/MCOAVoIPMsg.msg.
//

#ifndef _MCOAVOIPMSG_M_H_
#define _MCOAVOIPMSG_M_H_

#include <omnetpp.h>

// opp_msgc version check
#define MSGC_VERSION 0x0404
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgc: 'make clean' should help.
#endif

// cplusplus {{
#include "INETDefs.h"
// }}



/**
 * Class generated from <tt>applications/mcoa/VoIP/MCOAVoIPMsg.msg</tt> by opp_msgc.
 * <pre>
 * packet MCoAVoIPMsg
 * {
 *     bool isRequest = true;
 *     int curSeq; 
 *     double curTime; 
 * }
 * </pre>
 */
class MCoAVoIPMsg : public ::cPacket
{
  protected:
    bool isRequest_var;
    int curSeq_var;
    double curTime_var;

  private:
    void copy(const MCoAVoIPMsg& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const MCoAVoIPMsg&);

  public:
    MCoAVoIPMsg(const char *name=NULL, int kind=0);
    MCoAVoIPMsg(const MCoAVoIPMsg& other);
    virtual ~MCoAVoIPMsg();
    MCoAVoIPMsg& operator=(const MCoAVoIPMsg& other);
    virtual MCoAVoIPMsg *dup() const {return new MCoAVoIPMsg(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual bool getIsRequest() const;
    virtual void setIsRequest(bool isRequest);
    virtual int getCurSeq() const;
    virtual void setCurSeq(int curSeq);
    virtual double getCurTime() const;
    virtual void setCurTime(double curTime);
};

inline void doPacking(cCommBuffer *b, MCoAVoIPMsg& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, MCoAVoIPMsg& obj) {obj.parsimUnpack(b);}


#endif // _MCOAVOIPMSG_M_H_
