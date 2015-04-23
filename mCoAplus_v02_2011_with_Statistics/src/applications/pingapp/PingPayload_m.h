//
// Generated file, do not edit! Created by opp_msgc 4.4 from applications/pingapp/PingPayload.msg.
//

#ifndef _PINGPAYLOAD_M_H_
#define _PINGPAYLOAD_M_H_

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
 * Class generated from <tt>applications/pingapp/PingPayload.msg</tt> by opp_msgc.
 * <pre>
 * packet PingPayload
 * {
 *     long originatorId; 
 *     long seqNo; 
 *     unsigned char data[];
 * }
 * </pre>
 */
class PingPayload : public ::cPacket
{
  protected:
    long originatorId_var;
    long seqNo_var;
    unsigned char *data_var; // array ptr
    unsigned int data_arraysize;

  private:
    void copy(const PingPayload& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const PingPayload&);

  public:
    PingPayload(const char *name=NULL, int kind=0);
    PingPayload(const PingPayload& other);
    virtual ~PingPayload();
    PingPayload& operator=(const PingPayload& other);
    virtual PingPayload *dup() const {return new PingPayload(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual long getOriginatorId() const;
    virtual void setOriginatorId(long originatorId);
    virtual long getSeqNo() const;
    virtual void setSeqNo(long seqNo);
    virtual void setDataArraySize(unsigned int size);
    virtual unsigned int getDataArraySize() const;
    virtual unsigned char getData(unsigned int k) const;
    virtual void setData(unsigned int k, unsigned char data);
};

inline void doPacking(cCommBuffer *b, PingPayload& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, PingPayload& obj) {obj.parsimUnpack(b);}


#endif // _PINGPAYLOAD_M_H_
