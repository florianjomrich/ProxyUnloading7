//
// Generated file, do not edit! Created by opp_msgc 4.4 from ../obsolete/rsvp_te/RSVPResvMsg.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "RSVPResvMsg_m.h"

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




RSVPResvMsg_Base::RSVPResvMsg_Base(const char *name, int kind) : ::RSVPPacket(name,kind)
{
    this->refreshTime_var = 0;
    this->style_var = 0;
}

RSVPResvMsg_Base::RSVPResvMsg_Base(const RSVPResvMsg_Base& other) : ::RSVPPacket(other)
{
    copy(other);
}

RSVPResvMsg_Base::~RSVPResvMsg_Base()
{
}

RSVPResvMsg_Base& RSVPResvMsg_Base::operator=(const RSVPResvMsg_Base& other)
{
    if (this==&other) return *this;
    ::RSVPPacket::operator=(other);
    copy(other);
    return *this;
}

void RSVPResvMsg_Base::copy(const RSVPResvMsg_Base& other)
{
    this->hop_var = other.hop_var;
    this->refreshTime_var = other.refreshTime_var;
    this->style_var = other.style_var;
    for (unsigned int i=0; i<InLIST_SIZE; i++)
        this->flow_descriptor_list_var[i] = other.flow_descriptor_list_var[i];
}

void RSVPResvMsg_Base::parsimPack(cCommBuffer *b)
{
    ::RSVPPacket::parsimPack(b);
    doPacking(b,this->hop_var);
    doPacking(b,this->refreshTime_var);
    doPacking(b,this->style_var);
    doPacking(b,this->flow_descriptor_list_var,InLIST_SIZE);
}

void RSVPResvMsg_Base::parsimUnpack(cCommBuffer *b)
{
    ::RSVPPacket::parsimUnpack(b);
    doUnpacking(b,this->hop_var);
    doUnpacking(b,this->refreshTime_var);
    doUnpacking(b,this->style_var);
    doUnpacking(b,this->flow_descriptor_list_var,InLIST_SIZE);
}

RsvpHopObj_t& RSVPResvMsg_Base::getHop()
{
    return hop_var;
}

void RSVPResvMsg_Base::setHop(const RsvpHopObj_t& hop)
{
    this->hop_var = hop;
}

double RSVPResvMsg_Base::getRefreshTime() const
{
    return refreshTime_var;
}

void RSVPResvMsg_Base::setRefreshTime(double refreshTime)
{
    this->refreshTime_var = refreshTime;
}

int RSVPResvMsg_Base::getStyle() const
{
    return style_var;
}

void RSVPResvMsg_Base::setStyle(int style)
{
    this->style_var = style;
}

unsigned int RSVPResvMsg_Base::getFlow_descriptor_listArraySize() const
{
    return InLIST_SIZE;
}

FlowDescriptor_t& RSVPResvMsg_Base::getFlow_descriptor_list(unsigned int k)
{
    if (k>=InLIST_SIZE) throw cRuntimeError("Array of size InLIST_SIZE indexed by %lu", (unsigned long)k);
    return flow_descriptor_list_var[k];
}

void RSVPResvMsg_Base::setFlow_descriptor_list(unsigned int k, const FlowDescriptor_t& flow_descriptor_list)
{
    if (k>=InLIST_SIZE) throw cRuntimeError("Array of size InLIST_SIZE indexed by %lu", (unsigned long)k);
    this->flow_descriptor_list_var[k] = flow_descriptor_list;
}

class RSVPResvMsgDescriptor : public cClassDescriptor
{
  public:
    RSVPResvMsgDescriptor();
    virtual ~RSVPResvMsgDescriptor();

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

Register_ClassDescriptor(RSVPResvMsgDescriptor);

RSVPResvMsgDescriptor::RSVPResvMsgDescriptor() : cClassDescriptor("RSVPResvMsg", "RSVPPacket")
{
}

RSVPResvMsgDescriptor::~RSVPResvMsgDescriptor()
{
}

bool RSVPResvMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<RSVPResvMsg_Base *>(obj)!=NULL;
}

const char *RSVPResvMsgDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"customize")) return "true";
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int RSVPResvMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount(object) : 4;
}

unsigned int RSVPResvMsgDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *RSVPResvMsgDescriptor::getFieldName(void *object, int field) const
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
        "style",
        "flow_descriptor_list",
    };
    return (field>=0 && field<4) ? fieldNames[field] : NULL;
}

int RSVPResvMsgDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='h' && strcmp(fieldName, "hop")==0) return base+0;
    if (fieldName[0]=='r' && strcmp(fieldName, "refreshTime")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "style")==0) return base+2;
    if (fieldName[0]=='f' && strcmp(fieldName, "flow_descriptor_list")==0) return base+3;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *RSVPResvMsgDescriptor::getFieldTypeString(void *object, int field) const
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
        "int",
        "FlowDescriptor_t",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : NULL;
}

const char *RSVPResvMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int RSVPResvMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    RSVPResvMsg_Base *pp = (RSVPResvMsg_Base *)object; (void)pp;
    switch (field) {
        case 3: return InLIST_SIZE;
        default: return 0;
    }
}

std::string RSVPResvMsgDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    RSVPResvMsg_Base *pp = (RSVPResvMsg_Base *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getHop(); return out.str();}
        case 1: return double2string(pp->getRefreshTime());
        case 2: return long2string(pp->getStyle());
        case 3: {std::stringstream out; out << pp->getFlow_descriptor_list(i); return out.str();}
        default: return "";
    }
}

bool RSVPResvMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    RSVPResvMsg_Base *pp = (RSVPResvMsg_Base *)object; (void)pp;
    switch (field) {
        case 1: pp->setRefreshTime(string2double(value)); return true;
        case 2: pp->setStyle(string2long(value)); return true;
        default: return false;
    }
}

const char *RSVPResvMsgDescriptor::getFieldStructName(void *object, int field) const
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
        NULL,
        "FlowDescriptor_t",
    };
    return (field>=0 && field<4) ? fieldStructNames[field] : NULL;
}

void *RSVPResvMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    RSVPResvMsg_Base *pp = (RSVPResvMsg_Base *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getHop()); break;
        case 3: return (void *)(&pp->getFlow_descriptor_list(i)); break;
        default: return NULL;
    }
}

RSVPResvTear_Base::RSVPResvTear_Base(const char *name, int kind) : ::RSVPPacket(name,kind)
{
}

RSVPResvTear_Base::RSVPResvTear_Base(const RSVPResvTear_Base& other) : ::RSVPPacket(other)
{
    copy(other);
}

RSVPResvTear_Base::~RSVPResvTear_Base()
{
}

RSVPResvTear_Base& RSVPResvTear_Base::operator=(const RSVPResvTear_Base& other)
{
    if (this==&other) return *this;
    ::RSVPPacket::operator=(other);
    copy(other);
    return *this;
}

void RSVPResvTear_Base::copy(const RSVPResvTear_Base& other)
{
    this->hop_var = other.hop_var;
    for (unsigned int i=0; i<InLIST_SIZE; i++)
        this->flow_descriptor_list_var[i] = other.flow_descriptor_list_var[i];
}

void RSVPResvTear_Base::parsimPack(cCommBuffer *b)
{
    ::RSVPPacket::parsimPack(b);
    doPacking(b,this->hop_var);
    doPacking(b,this->flow_descriptor_list_var,InLIST_SIZE);
}

void RSVPResvTear_Base::parsimUnpack(cCommBuffer *b)
{
    ::RSVPPacket::parsimUnpack(b);
    doUnpacking(b,this->hop_var);
    doUnpacking(b,this->flow_descriptor_list_var,InLIST_SIZE);
}

RsvpHopObj_t& RSVPResvTear_Base::getHop()
{
    return hop_var;
}

void RSVPResvTear_Base::setHop(const RsvpHopObj_t& hop)
{
    this->hop_var = hop;
}

unsigned int RSVPResvTear_Base::getFlow_descriptor_listArraySize() const
{
    return InLIST_SIZE;
}

FlowDescriptor_t& RSVPResvTear_Base::getFlow_descriptor_list(unsigned int k)
{
    if (k>=InLIST_SIZE) throw cRuntimeError("Array of size InLIST_SIZE indexed by %lu", (unsigned long)k);
    return flow_descriptor_list_var[k];
}

void RSVPResvTear_Base::setFlow_descriptor_list(unsigned int k, const FlowDescriptor_t& flow_descriptor_list)
{
    if (k>=InLIST_SIZE) throw cRuntimeError("Array of size InLIST_SIZE indexed by %lu", (unsigned long)k);
    this->flow_descriptor_list_var[k] = flow_descriptor_list;
}

class RSVPResvTearDescriptor : public cClassDescriptor
{
  public:
    RSVPResvTearDescriptor();
    virtual ~RSVPResvTearDescriptor();

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

Register_ClassDescriptor(RSVPResvTearDescriptor);

RSVPResvTearDescriptor::RSVPResvTearDescriptor() : cClassDescriptor("RSVPResvTear", "RSVPPacket")
{
}

RSVPResvTearDescriptor::~RSVPResvTearDescriptor()
{
}

bool RSVPResvTearDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<RSVPResvTear_Base *>(obj)!=NULL;
}

const char *RSVPResvTearDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"customize")) return "true";
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int RSVPResvTearDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int RSVPResvTearDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *RSVPResvTearDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "hop",
        "flow_descriptor_list",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int RSVPResvTearDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='h' && strcmp(fieldName, "hop")==0) return base+0;
    if (fieldName[0]=='f' && strcmp(fieldName, "flow_descriptor_list")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *RSVPResvTearDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "RsvpHopObj_t",
        "FlowDescriptor_t",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *RSVPResvTearDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int RSVPResvTearDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    RSVPResvTear_Base *pp = (RSVPResvTear_Base *)object; (void)pp;
    switch (field) {
        case 1: return InLIST_SIZE;
        default: return 0;
    }
}

std::string RSVPResvTearDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    RSVPResvTear_Base *pp = (RSVPResvTear_Base *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getHop(); return out.str();}
        case 1: {std::stringstream out; out << pp->getFlow_descriptor_list(i); return out.str();}
        default: return "";
    }
}

bool RSVPResvTearDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    RSVPResvTear_Base *pp = (RSVPResvTear_Base *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *RSVPResvTearDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        "RsvpHopObj_t",
        "FlowDescriptor_t",
    };
    return (field>=0 && field<2) ? fieldStructNames[field] : NULL;
}

void *RSVPResvTearDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    RSVPResvTear_Base *pp = (RSVPResvTear_Base *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getHop()); break;
        case 1: return (void *)(&pp->getFlow_descriptor_list(i)); break;
        default: return NULL;
    }
}

RSVPResvError_Base::RSVPResvError_Base(const char *name, int kind) : ::RSVPPacket(name,kind)
{
    this->errorCode_var = 0;
}

RSVPResvError_Base::RSVPResvError_Base(const RSVPResvError_Base& other) : ::RSVPPacket(other)
{
    copy(other);
}

RSVPResvError_Base::~RSVPResvError_Base()
{
}

RSVPResvError_Base& RSVPResvError_Base::operator=(const RSVPResvError_Base& other)
{
    if (this==&other) return *this;
    ::RSVPPacket::operator=(other);
    copy(other);
    return *this;
}

void RSVPResvError_Base::copy(const RSVPResvError_Base& other)
{
    this->hop_var = other.hop_var;
    this->errorNode_var = other.errorNode_var;
    this->errorCode_var = other.errorCode_var;
}

void RSVPResvError_Base::parsimPack(cCommBuffer *b)
{
    ::RSVPPacket::parsimPack(b);
    doPacking(b,this->hop_var);
    doPacking(b,this->errorNode_var);
    doPacking(b,this->errorCode_var);
}

void RSVPResvError_Base::parsimUnpack(cCommBuffer *b)
{
    ::RSVPPacket::parsimUnpack(b);
    doUnpacking(b,this->hop_var);
    doUnpacking(b,this->errorNode_var);
    doUnpacking(b,this->errorCode_var);
}

RsvpHopObj_t& RSVPResvError_Base::getHop()
{
    return hop_var;
}

void RSVPResvError_Base::setHop(const RsvpHopObj_t& hop)
{
    this->hop_var = hop;
}

IPADDR& RSVPResvError_Base::getErrorNode()
{
    return errorNode_var;
}

void RSVPResvError_Base::setErrorNode(const IPADDR& errorNode)
{
    this->errorNode_var = errorNode;
}

int RSVPResvError_Base::getErrorCode() const
{
    return errorCode_var;
}

void RSVPResvError_Base::setErrorCode(int errorCode)
{
    this->errorCode_var = errorCode;
}

class RSVPResvErrorDescriptor : public cClassDescriptor
{
  public:
    RSVPResvErrorDescriptor();
    virtual ~RSVPResvErrorDescriptor();

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

Register_ClassDescriptor(RSVPResvErrorDescriptor);

RSVPResvErrorDescriptor::RSVPResvErrorDescriptor() : cClassDescriptor("RSVPResvError", "RSVPPacket")
{
}

RSVPResvErrorDescriptor::~RSVPResvErrorDescriptor()
{
}

bool RSVPResvErrorDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<RSVPResvError_Base *>(obj)!=NULL;
}

const char *RSVPResvErrorDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"customize")) return "true";
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int RSVPResvErrorDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int RSVPResvErrorDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *RSVPResvErrorDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "hop",
        "errorNode",
        "errorCode",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int RSVPResvErrorDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='h' && strcmp(fieldName, "hop")==0) return base+0;
    if (fieldName[0]=='e' && strcmp(fieldName, "errorNode")==0) return base+1;
    if (fieldName[0]=='e' && strcmp(fieldName, "errorCode")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *RSVPResvErrorDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "RsvpHopObj_t",
        "IPADDR",
        "int",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *RSVPResvErrorDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int RSVPResvErrorDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    RSVPResvError_Base *pp = (RSVPResvError_Base *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string RSVPResvErrorDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    RSVPResvError_Base *pp = (RSVPResvError_Base *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getHop(); return out.str();}
        case 1: {std::stringstream out; out << pp->getErrorNode(); return out.str();}
        case 2: return long2string(pp->getErrorCode());
        default: return "";
    }
}

bool RSVPResvErrorDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    RSVPResvError_Base *pp = (RSVPResvError_Base *)object; (void)pp;
    switch (field) {
        case 2: pp->setErrorCode(string2long(value)); return true;
        default: return false;
    }
}

const char *RSVPResvErrorDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        "RsvpHopObj_t",
        "IPADDR",
        NULL,
    };
    return (field>=0 && field<3) ? fieldStructNames[field] : NULL;
}

void *RSVPResvErrorDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    RSVPResvError_Base *pp = (RSVPResvError_Base *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getHop()); break;
        case 1: return (void *)(&pp->getErrorNode()); break;
        default: return NULL;
    }
}


