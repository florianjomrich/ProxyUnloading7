//
// Generated file, do not edit! Created by opp_msgc 4.4 from applications/mcoa/proxy_enhanced/messages/control_messages/SignalUpdate.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "SignalUpdate_m.h"

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




Register_Class(SignalUpdate);

SignalUpdate::SignalUpdate(const char *name, int kind) : ::cPacket(name,kind)
{
    this->AccessPoint_var = 0;
    this->valueOfSNR_var = 0;
}

SignalUpdate::SignalUpdate(const SignalUpdate& other) : ::cPacket(other)
{
    copy(other);
}

SignalUpdate::~SignalUpdate()
{
}

SignalUpdate& SignalUpdate::operator=(const SignalUpdate& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void SignalUpdate::copy(const SignalUpdate& other)
{
    this->AccessPoint_var = other.AccessPoint_var;
    this->valueOfSNR_var = other.valueOfSNR_var;
}

void SignalUpdate::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->AccessPoint_var);
    doPacking(b,this->valueOfSNR_var);
}

void SignalUpdate::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->AccessPoint_var);
    doUnpacking(b,this->valueOfSNR_var);
}

const char * SignalUpdate::getAccessPoint() const
{
    return AccessPoint_var.c_str();
}

void SignalUpdate::setAccessPoint(const char * AccessPoint)
{
    this->AccessPoint_var = AccessPoint;
}

double SignalUpdate::getValueOfSNR() const
{
    return valueOfSNR_var;
}

void SignalUpdate::setValueOfSNR(double valueOfSNR)
{
    this->valueOfSNR_var = valueOfSNR;
}

class SignalUpdateDescriptor : public cClassDescriptor
{
  public:
    SignalUpdateDescriptor();
    virtual ~SignalUpdateDescriptor();

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

Register_ClassDescriptor(SignalUpdateDescriptor);

SignalUpdateDescriptor::SignalUpdateDescriptor() : cClassDescriptor("SignalUpdate", "cPacket")
{
}

SignalUpdateDescriptor::~SignalUpdateDescriptor()
{
}

bool SignalUpdateDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<SignalUpdate *>(obj)!=NULL;
}

const char *SignalUpdateDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int SignalUpdateDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int SignalUpdateDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *SignalUpdateDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "AccessPoint",
        "valueOfSNR",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int SignalUpdateDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='A' && strcmp(fieldName, "AccessPoint")==0) return base+0;
    if (fieldName[0]=='v' && strcmp(fieldName, "valueOfSNR")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *SignalUpdateDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "double",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *SignalUpdateDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int SignalUpdateDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    SignalUpdate *pp = (SignalUpdate *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string SignalUpdateDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    SignalUpdate *pp = (SignalUpdate *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getAccessPoint());
        case 1: return double2string(pp->getValueOfSNR());
        default: return "";
    }
}

bool SignalUpdateDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    SignalUpdate *pp = (SignalUpdate *)object; (void)pp;
    switch (field) {
        case 0: pp->setAccessPoint((value)); return true;
        case 1: pp->setValueOfSNR(string2double(value)); return true;
        default: return false;
    }
}

const char *SignalUpdateDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
    };
    return (field>=0 && field<2) ? fieldStructNames[field] : NULL;
}

void *SignalUpdateDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    SignalUpdate *pp = (SignalUpdate *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


