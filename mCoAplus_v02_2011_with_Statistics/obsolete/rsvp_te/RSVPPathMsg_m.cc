//
// Generated file, do not edit! Created by opp_msgc 4.4 from ../obsolete/rsvp_te/RSVPPathMsg.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "RSVPPathMsg_m.h"

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




RSVPPathMsg_Base::RSVPPathMsg_Base(const char *name, int kind) : ::RSVPPacket(name,kind)
{
    this->refreshTime_var = 0;
    this->hasERO_var = 0;
}

RSVPPathMsg_Base::RSVPPathMsg_Base(const RSVPPathMsg_Base& other) : ::RSVPPacket(other)
{
    copy(other);
}

RSVPPathMsg_Base::~RSVPPathMsg_Base()
{
}

RSVPPathMsg_Base& RSVPPathMsg_Base::operator=(const RSVPPathMsg_Base& other)
{
    if (this==&other) return *this;
    ::RSVPPacket::operator=(other);
    copy(other);
    return *this;
}

void RSVPPathMsg_Base::copy(const RSVPPathMsg_Base& other)
{
    this->hop_var = other.hop_var;
    this->refreshTime_var = other.refreshTime_var;
    this->label_request_var = other.label_request_var;
    this->sender_descriptor_var = other.sender_descriptor_var;
    this->hasERO_var = other.hasERO_var;
    for (unsigned int i=0; i<MAX_ROUTE; i++)
        this->ERO_var[i] = other.ERO_var[i];
}

void RSVPPathMsg_Base::parsimPack(cCommBuffer *b)
{
    ::RSVPPacket::parsimPack(b);
    doPacking(b,this->hop_var);
    doPacking(b,this->refreshTime_var);
    doPacking(b,this->label_request_var);
    doPacking(b,this->sender_descriptor_var);
    doPacking(b,this->hasERO_var);
    doPacking(b,this->ERO_var,MAX_ROUTE);
}

void RSVPPathMsg_Base::parsimUnpack(cCommBuffer *b)
{
    ::RSVPPacket::parsimUnpack(b);
    doUnpacking(b,this->hop_var);
    doUnpacking(b,this->refreshTime_var);
    doUnpacking(b,this->label_request_var);
    doUnpacking(b,this->sender_descriptor_var);
    doUnpacking(b,this->hasERO_var);
    doUnpacking(b,this->ERO_var,MAX_ROUTE);
}

RsvpHopObj_t& RSVPPathMsg_Base::getHop()
{
    return hop_var;
}

void RSVPPathMsg_Base::setHop(const RsvpHopObj_t& hop)
{
    this->hop_var = hop;
}

double RSVPPathMsg_Base::getRefreshTime() const
{
    return refreshTime_var;
}

void RSVPPathMsg_Base::setRefreshTime(double refreshTime)
{
    this->refreshTime_var = refreshTime;
}

LabelRequestObj_t& RSVPPathMsg_Base::getLabel_request()
{
    return label_request_var;
}

void RSVPPathMsg_Base::setLabel_request(const LabelRequestObj_t& label_request)
{
    this->label_request_var = label_request;
}

SenderDescriptor_t& RSVPPathMsg_Base::getSender_descriptor()
{
    return sender_descriptor_var;
}

void RSVPPathMsg_Base::setSender_descriptor(const SenderDescriptor_t& sender_descriptor)
{
    this->sender_descriptor_var = sender_descriptor;
}

bool RSVPPathMsg_Base::getHasERO() const
{
    return hasERO_var;
}

void RSVPPathMsg_Base::setHasERO(bool hasERO)
{
    this->hasERO_var = hasERO;
}

unsigned int RSVPPathMsg_Base::getEROArraySize() const
{
    return MAX_ROUTE;
}

EroObj_t& RSVPPathMsg_Base::getERO(unsigned int k)
{
    if (k>=MAX_ROUTE) throw cRuntimeError("Array of size MAX_ROUTE indexed by %lu", (unsigned long)k);
    return ERO_var[k];
}

void RSVPPathMsg_Base::setERO(unsigned int k, const EroObj_t& ERO)
{
    if (k>=MAX_ROUTE) throw cRuntimeError("Array of size MAX_ROUTE indexed by %lu", (unsigned long)k);
    this->ERO_var[k] = ERO;
}

class RSVPPathMsgDescriptor : public cClassDescriptor
{
  public:
    RSVPPathMsgDescriptor();
    virtual ~RSVPPathMsgDescriptor();

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

Register_ClassDescriptor(RSVPPathMsgDescriptor);

RSVPPathMsgDescriptor::RSVPPathMsgDescriptor() : cClassDescriptor("RSVPPathMsg", "RSVPPacket")
{
}

RSVPPathMsgDescriptor::~RSVPPathMsgDescriptor()
{
}

bool RSVPPathMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<RSVPPathMsg_Base *>(obj)!=NULL;
}

const char *RSVPPathMsgDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"customize")) return "true";
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int RSVPPathMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount(object) : 6;
}

unsigned int RSVPPathMsgDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *RSVPPathMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "hop",
        "refreshTime",
        "label_request",
        "sender_descriptor",
        "hasERO",
        "ERO",
    };
    return (field>=0 && field<6) ? fieldNames[field] : NULL;
}

int RSVPPathMsgDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='h' && strcmp(fieldName, "hop")==0) return base+0;
    if (fieldName[0]=='r' && strcmp(fieldName, "refreshTime")==0) return base+1;
    if (fieldName[0]=='l' && strcmp(fieldName, "label_request")==0) return base+2;
    if (fieldName[0]=='s' && strcmp(fieldName, "sender_descriptor")==0) return base+3;
    if (fieldName[0]=='h' && strcmp(fieldName, "hasERO")==0) return base+4;
    if (fieldName[0]=='E' && strcmp(fieldName, "ERO")==0) return base+5;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *RSVPPathMsgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "RsvpHopObj_t",
        "double",
        "LabelRequestObj_t",
        "SenderDescriptor_t",
        "bool",
        "EroObj_t",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : NULL;
}

const char *RSVPPathMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int RSVPPathMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    RSVPPathMsg_Base *pp = (RSVPPathMsg_Base *)object; (void)pp;
    switch (field) {
        case 5: return MAX_ROUTE;
        default: return 0;
    }
}

std::string RSVPPathMsgDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    RSVPPathMsg_Base *pp = (RSVPPathMsg_Base *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getHop(); return out.str();}
        case 1: return double2string(pp->getRefreshTime());
        case 2: {std::stringstream out; out << pp->getLabel_request(); return out.str();}
        case 3: {std::stringstream out; out << pp->getSender_descriptor(); return out.str();}
        case 4: return bool2string(pp->getHasERO());
        case 5: {std::stringstream out; out << pp->getERO(i); return out.str();}
        default: return "";
    }
}

bool RSVPPathMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    RSVPPathMsg_Base *pp = (RSVPPathMsg_Base *)object; (void)pp;
    switch (field) {
        case 1: pp->setRefreshTime(string2double(value)); return true;
        case 4: pp->setHasERO(string2bool(value)); return true;
        default: return false;
    }
}

const char *RSVPPathMsgDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        "RsvpHopObj_t",
        NULL,
        "LabelRequestObj_t",
        "SenderDescriptor_t",
        NULL,
        "EroObj_t",
    };
    return (field>=0 && field<6) ? fieldStructNames[field] : NULL;
}

void *RSVPPathMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    RSVPPathMsg_Base *pp = (RSVPPathMsg_Base *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getHop()); break;
        case 2: return (void *)(&pp->getLabel_request()); break;
        case 3: return (void *)(&pp->getSender_descriptor()); break;
        case 5: return (void *)(&pp->getERO(i)); break;
        default: return NULL;
    }
}

RSVPPathTear_Base::RSVPPathTear_Base(const char *name, int kind) : ::RSVPPacket(name,kind)
{
}

RSVPPathTear_Base::RSVPPathTear_Base(const RSVPPathTear_Base& other) : ::RSVPPacket(other)
{
    copy(other);
}

RSVPPathTear_Base::~RSVPPathTear_Base()
{
}

RSVPPathTear_Base& RSVPPathTear_Base::operator=(const RSVPPathTear_Base& other)
{
    if (this==&other) return *this;
    ::RSVPPacket::operator=(other);
    copy(other);
    return *this;
}

void RSVPPathTear_Base::copy(const RSVPPathTear_Base& other)
{
    this->hop_var = other.hop_var;
    this->senderTemplate_var = other.senderTemplate_var;
}

void RSVPPathTear_Base::parsimPack(cCommBuffer *b)
{
    ::RSVPPacket::parsimPack(b);
    doPacking(b,this->hop_var);
    doPacking(b,this->senderTemplate_var);
}

void RSVPPathTear_Base::parsimUnpack(cCommBuffer *b)
{
    ::RSVPPacket::parsimUnpack(b);
    doUnpacking(b,this->hop_var);
    doUnpacking(b,this->senderTemplate_var);
}

RsvpHopObj_t& RSVPPathTear_Base::getHop()
{
    return hop_var;
}

void RSVPPathTear_Base::setHop(const RsvpHopObj_t& hop)
{
    this->hop_var = hop;
}

SenderTemplateObj_t& RSVPPathTear_Base::getSenderTemplate()
{
    return senderTemplate_var;
}

void RSVPPathTear_Base::setSenderTemplate(const SenderTemplateObj_t& senderTemplate)
{
    this->senderTemplate_var = senderTemplate;
}

class RSVPPathTearDescriptor : public cClassDescriptor
{
  public:
    RSVPPathTearDescriptor();
    virtual ~RSVPPathTearDescriptor();

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

Register_ClassDescriptor(RSVPPathTearDescriptor);

RSVPPathTearDescriptor::RSVPPathTearDescriptor() : cClassDescriptor("RSVPPathTear", "RSVPPacket")
{
}

RSVPPathTearDescriptor::~RSVPPathTearDescriptor()
{
}

bool RSVPPathTearDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<RSVPPathTear_Base *>(obj)!=NULL;
}

const char *RSVPPathTearDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"customize")) return "true";
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int RSVPPathTearDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int RSVPPathTearDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *RSVPPathTearDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "hop",
        "senderTemplate",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int RSVPPathTearDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='h' && strcmp(fieldName, "hop")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "senderTemplate")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *RSVPPathTearDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "RsvpHopObj_t",
        "SenderTemplateObj_t",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *RSVPPathTearDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int RSVPPathTearDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    RSVPPathTear_Base *pp = (RSVPPathTear_Base *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string RSVPPathTearDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    RSVPPathTear_Base *pp = (RSVPPathTear_Base *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getHop(); return out.str();}
        case 1: {std::stringstream out; out << pp->getSenderTemplate(); return out.str();}
        default: return "";
    }
}

bool RSVPPathTearDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    RSVPPathTear_Base *pp = (RSVPPathTear_Base *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *RSVPPathTearDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        "RsvpHopObj_t",
        "SenderTemplateObj_t",
    };
    return (field>=0 && field<2) ? fieldStructNames[field] : NULL;
}

void *RSVPPathTearDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    RSVPPathTear_Base *pp = (RSVPPathTear_Base *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getHop()); break;
        case 1: return (void *)(&pp->getSenderTemplate()); break;
        default: return NULL;
    }
}

RSVPPathError_Base::RSVPPathError_Base(const char *name, int kind) : ::RSVPPacket(name,kind)
{
    this->errorCode_var = 0;
}

RSVPPathError_Base::RSVPPathError_Base(const RSVPPathError_Base& other) : ::RSVPPacket(other)
{
    copy(other);
}

RSVPPathError_Base::~RSVPPathError_Base()
{
}

RSVPPathError_Base& RSVPPathError_Base::operator=(const RSVPPathError_Base& other)
{
    if (this==&other) return *this;
    ::RSVPPacket::operator=(other);
    copy(other);
    return *this;
}

void RSVPPathError_Base::copy(const RSVPPathError_Base& other)
{
    this->errorNode_var = other.errorNode_var;
    this->errorCode_var = other.errorCode_var;
    this->sender_descriptor_var = other.sender_descriptor_var;
}

void RSVPPathError_Base::parsimPack(cCommBuffer *b)
{
    ::RSVPPacket::parsimPack(b);
    doPacking(b,this->errorNode_var);
    doPacking(b,this->errorCode_var);
    doPacking(b,this->sender_descriptor_var);
}

void RSVPPathError_Base::parsimUnpack(cCommBuffer *b)
{
    ::RSVPPacket::parsimUnpack(b);
    doUnpacking(b,this->errorNode_var);
    doUnpacking(b,this->errorCode_var);
    doUnpacking(b,this->sender_descriptor_var);
}

IPADDR& RSVPPathError_Base::getErrorNode()
{
    return errorNode_var;
}

void RSVPPathError_Base::setErrorNode(const IPADDR& errorNode)
{
    this->errorNode_var = errorNode;
}

int RSVPPathError_Base::getErrorCode() const
{
    return errorCode_var;
}

void RSVPPathError_Base::setErrorCode(int errorCode)
{
    this->errorCode_var = errorCode;
}

SenderDescriptor_t& RSVPPathError_Base::getSender_descriptor()
{
    return sender_descriptor_var;
}

void RSVPPathError_Base::setSender_descriptor(const SenderDescriptor_t& sender_descriptor)
{
    this->sender_descriptor_var = sender_descriptor;
}

class RSVPPathErrorDescriptor : public cClassDescriptor
{
  public:
    RSVPPathErrorDescriptor();
    virtual ~RSVPPathErrorDescriptor();

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

Register_ClassDescriptor(RSVPPathErrorDescriptor);

RSVPPathErrorDescriptor::RSVPPathErrorDescriptor() : cClassDescriptor("RSVPPathError", "RSVPPacket")
{
}

RSVPPathErrorDescriptor::~RSVPPathErrorDescriptor()
{
}

bool RSVPPathErrorDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<RSVPPathError_Base *>(obj)!=NULL;
}

const char *RSVPPathErrorDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"customize")) return "true";
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int RSVPPathErrorDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int RSVPPathErrorDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *RSVPPathErrorDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "errorNode",
        "errorCode",
        "sender_descriptor",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int RSVPPathErrorDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='e' && strcmp(fieldName, "errorNode")==0) return base+0;
    if (fieldName[0]=='e' && strcmp(fieldName, "errorCode")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "sender_descriptor")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *RSVPPathErrorDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "IPADDR",
        "int",
        "SenderDescriptor_t",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *RSVPPathErrorDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int RSVPPathErrorDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    RSVPPathError_Base *pp = (RSVPPathError_Base *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string RSVPPathErrorDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    RSVPPathError_Base *pp = (RSVPPathError_Base *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getErrorNode(); return out.str();}
        case 1: return long2string(pp->getErrorCode());
        case 2: {std::stringstream out; out << pp->getSender_descriptor(); return out.str();}
        default: return "";
    }
}

bool RSVPPathErrorDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    RSVPPathError_Base *pp = (RSVPPathError_Base *)object; (void)pp;
    switch (field) {
        case 1: pp->setErrorCode(string2long(value)); return true;
        default: return false;
    }
}

const char *RSVPPathErrorDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        "IPADDR",
        NULL,
        "SenderDescriptor_t",
    };
    return (field>=0 && field<3) ? fieldStructNames[field] : NULL;
}

void *RSVPPathErrorDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    RSVPPathError_Base *pp = (RSVPPathError_Base *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getErrorNode()); break;
        case 2: return (void *)(&pp->getSender_descriptor()); break;
        default: return NULL;
    }
}


