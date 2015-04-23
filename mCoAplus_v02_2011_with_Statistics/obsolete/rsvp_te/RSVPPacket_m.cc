//
// Generated file, do not edit! Created by opp_msgc 4.4 from ../obsolete/rsvp_te/RSVPPacket.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "RSVPPacket_m.h"

USING_NAMESPACE

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




RSVPPacket_Base::RSVPPacket_Base(const char *name, int kind) : ::cMessage(name,kind)
{
    this->checksumValid_var = true;
}

RSVPPacket_Base::RSVPPacket_Base(const RSVPPacket_Base& other) : ::cMessage(other)
{
    copy(other);
}

RSVPPacket_Base::~RSVPPacket_Base()
{
}

RSVPPacket_Base& RSVPPacket_Base::operator=(const RSVPPacket_Base& other)
{
    if (this==&other) return *this;
    ::cMessage::operator=(other);
    copy(other);
    return *this;
}

void RSVPPacket_Base::copy(const RSVPPacket_Base& other)
{
    this->session_var = other.session_var;
    this->checksumValid_var = other.checksumValid_var;
}

void RSVPPacket_Base::parsimPack(cCommBuffer *b)
{
    ::cMessage::parsimPack(b);
    doPacking(b,this->session_var);
    doPacking(b,this->checksumValid_var);
}

void RSVPPacket_Base::parsimUnpack(cCommBuffer *b)
{
    ::cMessage::parsimUnpack(b);
    doUnpacking(b,this->session_var);
    doUnpacking(b,this->checksumValid_var);
}

SessionObj_t& RSVPPacket_Base::getSession()
{
    return session_var;
}

void RSVPPacket_Base::setSession(const SessionObj_t& session)
{
    this->session_var = session;
}

bool RSVPPacket_Base::getChecksumValid() const
{
    return checksumValid_var;
}

void RSVPPacket_Base::setChecksumValid(bool checksumValid)
{
    this->checksumValid_var = checksumValid;
}

class RSVPPacketDescriptor : public cClassDescriptor
{
  public:
    RSVPPacketDescriptor();
    virtual ~RSVPPacketDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(RSVPPacketDescriptor);

RSVPPacketDescriptor::RSVPPacketDescriptor() : cClassDescriptor("RSVPPacket", "cMessage")
{
}

RSVPPacketDescriptor::~RSVPPacketDescriptor()
{
}

bool RSVPPacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<RSVPPacket_Base *>(obj)!=NULL;
}

const char *RSVPPacketDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"customize")) return "true";
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int RSVPPacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int RSVPPacketDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *RSVPPacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "session",
        "checksumValid",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int RSVPPacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "session")==0) return base+0;
    if (fieldName[0]=='c' && strcmp(fieldName, "checksumValid")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *RSVPPacketDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "SessionObj_t",
        "bool",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *RSVPPacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int RSVPPacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    RSVPPacket_Base *pp = (RSVPPacket_Base *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string RSVPPacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    RSVPPacket_Base *pp = (RSVPPacket_Base *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getSession(); return out.str();}
        case 1: return bool2string(pp->getChecksumValid());
        default: return "";
    }
}

bool RSVPPacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    RSVPPacket_Base *pp = (RSVPPacket_Base *)object; (void)pp;
    switch (field) {
        case 1: pp->setChecksumValid(string2bool(value)); return true;
        default: return false;
    }
}

const char *RSVPPacketDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        "SessionObj_t",
        NULL,
    };
    return (field>=0 && field<2) ? fieldStructNames[field] : NULL;
}

void *RSVPPacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    RSVPPacket_Base *pp = (RSVPPacket_Base *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getSession()); break;
        default: return NULL;
    }
}


