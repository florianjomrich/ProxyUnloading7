//
// Generated file, do not edit! Created by opp_msgc 4.4 from applications/mcoa/proxy_enhanced/messages/control_messages/ACK_SetAddressActive.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "ACK_SetAddressActive_m.h"

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




Register_Class(ACK_SetAddressActive);

ACK_SetAddressActive::ACK_SetAddressActive(const char *name, int kind) : ::cPacket(name,kind)
{
    this->sourceName_var = 0;
}

ACK_SetAddressActive::ACK_SetAddressActive(const ACK_SetAddressActive& other) : ::cPacket(other)
{
    copy(other);
}

ACK_SetAddressActive::~ACK_SetAddressActive()
{
}

ACK_SetAddressActive& ACK_SetAddressActive::operator=(const ACK_SetAddressActive& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void ACK_SetAddressActive::copy(const ACK_SetAddressActive& other)
{
    this->sourceName_var = other.sourceName_var;
}

void ACK_SetAddressActive::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->sourceName_var);
}

void ACK_SetAddressActive::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->sourceName_var);
}

const char * ACK_SetAddressActive::getSourceName() const
{
    return sourceName_var.c_str();
}

void ACK_SetAddressActive::setSourceName(const char * sourceName)
{
    this->sourceName_var = sourceName;
}

class ACK_SetAddressActiveDescriptor : public cClassDescriptor
{
  public:
    ACK_SetAddressActiveDescriptor();
    virtual ~ACK_SetAddressActiveDescriptor();

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

Register_ClassDescriptor(ACK_SetAddressActiveDescriptor);

ACK_SetAddressActiveDescriptor::ACK_SetAddressActiveDescriptor() : cClassDescriptor("ACK_SetAddressActive", "cPacket")
{
}

ACK_SetAddressActiveDescriptor::~ACK_SetAddressActiveDescriptor()
{
}

bool ACK_SetAddressActiveDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<ACK_SetAddressActive *>(obj)!=NULL;
}

const char *ACK_SetAddressActiveDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int ACK_SetAddressActiveDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int ACK_SetAddressActiveDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *ACK_SetAddressActiveDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "sourceName",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int ACK_SetAddressActiveDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceName")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *ACK_SetAddressActiveDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "string",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *ACK_SetAddressActiveDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int ACK_SetAddressActiveDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    ACK_SetAddressActive *pp = (ACK_SetAddressActive *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string ACK_SetAddressActiveDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    ACK_SetAddressActive *pp = (ACK_SetAddressActive *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getSourceName());
        default: return "";
    }
}

bool ACK_SetAddressActiveDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    ACK_SetAddressActive *pp = (ACK_SetAddressActive *)object; (void)pp;
    switch (field) {
        case 0: pp->setSourceName((value)); return true;
        default: return false;
    }
}

const char *ACK_SetAddressActiveDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
    };
    return (field>=0 && field<1) ? fieldStructNames[field] : NULL;
}

void *ACK_SetAddressActiveDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    ACK_SetAddressActive *pp = (ACK_SetAddressActive *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


