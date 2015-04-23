//
// Generated file, do not edit! Created by opp_msgc 4.4 from applications/mcoa/proxy_enhanced/messages/app_messages/VideoMessage.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "VideoMessage_m.h"

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




Register_Class(VideoMessage);

VideoMessage::VideoMessage(const char *name, int kind) : ::cPacket(name,kind)
{
    this->sequenceNumber_var = 0;
    this->someField_var = 0;
    this->anotherField_var = 0;
    arrayField1_arraysize = 0;
    this->arrayField1_var = 0;
    for (unsigned int i=0; i<10; i++)
        this->arrayField2_var[i] = 0;
}

VideoMessage::VideoMessage(const VideoMessage& other) : ::cPacket(other)
{
    arrayField1_arraysize = 0;
    this->arrayField1_var = 0;
    copy(other);
}

VideoMessage::~VideoMessage()
{
    delete [] arrayField1_var;
}

VideoMessage& VideoMessage::operator=(const VideoMessage& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void VideoMessage::copy(const VideoMessage& other)
{
    this->sequenceNumber_var = other.sequenceNumber_var;
    this->someField_var = other.someField_var;
    this->anotherField_var = other.anotherField_var;
    delete [] this->arrayField1_var;
    this->arrayField1_var = (other.arrayField1_arraysize==0) ? NULL : new double[other.arrayField1_arraysize];
    arrayField1_arraysize = other.arrayField1_arraysize;
    for (unsigned int i=0; i<arrayField1_arraysize; i++)
        this->arrayField1_var[i] = other.arrayField1_var[i];
    for (unsigned int i=0; i<10; i++)
        this->arrayField2_var[i] = other.arrayField2_var[i];
}

void VideoMessage::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->sequenceNumber_var);
    doPacking(b,this->someField_var);
    doPacking(b,this->anotherField_var);
    b->pack(arrayField1_arraysize);
    doPacking(b,this->arrayField1_var,arrayField1_arraysize);
    doPacking(b,this->arrayField2_var,10);
}

void VideoMessage::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->sequenceNumber_var);
    doUnpacking(b,this->someField_var);
    doUnpacking(b,this->anotherField_var);
    delete [] this->arrayField1_var;
    b->unpack(arrayField1_arraysize);
    if (arrayField1_arraysize==0) {
        this->arrayField1_var = 0;
    } else {
        this->arrayField1_var = new double[arrayField1_arraysize];
        doUnpacking(b,this->arrayField1_var,arrayField1_arraysize);
    }
    doUnpacking(b,this->arrayField2_var,10);
}

int VideoMessage::getSequenceNumber() const
{
    return sequenceNumber_var;
}

void VideoMessage::setSequenceNumber(int sequenceNumber)
{
    this->sequenceNumber_var = sequenceNumber;
}

int VideoMessage::getSomeField() const
{
    return someField_var;
}

void VideoMessage::setSomeField(int someField)
{
    this->someField_var = someField;
}

const char * VideoMessage::getAnotherField() const
{
    return anotherField_var.c_str();
}

void VideoMessage::setAnotherField(const char * anotherField)
{
    this->anotherField_var = anotherField;
}

void VideoMessage::setArrayField1ArraySize(unsigned int size)
{
    double *arrayField1_var2 = (size==0) ? NULL : new double[size];
    unsigned int sz = arrayField1_arraysize < size ? arrayField1_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        arrayField1_var2[i] = this->arrayField1_var[i];
    for (unsigned int i=sz; i<size; i++)
        arrayField1_var2[i] = 0;
    arrayField1_arraysize = size;
    delete [] this->arrayField1_var;
    this->arrayField1_var = arrayField1_var2;
}

unsigned int VideoMessage::getArrayField1ArraySize() const
{
    return arrayField1_arraysize;
}

double VideoMessage::getArrayField1(unsigned int k) const
{
    if (k>=arrayField1_arraysize) throw cRuntimeError("Array of size %d indexed by %d", arrayField1_arraysize, k);
    return arrayField1_var[k];
}

void VideoMessage::setArrayField1(unsigned int k, double arrayField1)
{
    if (k>=arrayField1_arraysize) throw cRuntimeError("Array of size %d indexed by %d", arrayField1_arraysize, k);
    this->arrayField1_var[k] = arrayField1;
}

unsigned int VideoMessage::getArrayField2ArraySize() const
{
    return 10;
}

double VideoMessage::getArrayField2(unsigned int k) const
{
    if (k>=10) throw cRuntimeError("Array of size 10 indexed by %lu", (unsigned long)k);
    return arrayField2_var[k];
}

void VideoMessage::setArrayField2(unsigned int k, double arrayField2)
{
    if (k>=10) throw cRuntimeError("Array of size 10 indexed by %lu", (unsigned long)k);
    this->arrayField2_var[k] = arrayField2;
}

class VideoMessageDescriptor : public cClassDescriptor
{
  public:
    VideoMessageDescriptor();
    virtual ~VideoMessageDescriptor();

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

Register_ClassDescriptor(VideoMessageDescriptor);

VideoMessageDescriptor::VideoMessageDescriptor() : cClassDescriptor("VideoMessage", "cPacket")
{
}

VideoMessageDescriptor::~VideoMessageDescriptor()
{
}

bool VideoMessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<VideoMessage *>(obj)!=NULL;
}

const char *VideoMessageDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int VideoMessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount(object) : 5;
}

unsigned int VideoMessageDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *VideoMessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "sequenceNumber",
        "someField",
        "anotherField",
        "arrayField1",
        "arrayField2",
    };
    return (field>=0 && field<5) ? fieldNames[field] : NULL;
}

int VideoMessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sequenceNumber")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "someField")==0) return base+1;
    if (fieldName[0]=='a' && strcmp(fieldName, "anotherField")==0) return base+2;
    if (fieldName[0]=='a' && strcmp(fieldName, "arrayField1")==0) return base+3;
    if (fieldName[0]=='a' && strcmp(fieldName, "arrayField2")==0) return base+4;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *VideoMessageDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "string",
        "double",
        "double",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : NULL;
}

const char *VideoMessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int VideoMessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    VideoMessage *pp = (VideoMessage *)object; (void)pp;
    switch (field) {
        case 3: return pp->getArrayField1ArraySize();
        case 4: return 10;
        default: return 0;
    }
}

std::string VideoMessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    VideoMessage *pp = (VideoMessage *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getSequenceNumber());
        case 1: return long2string(pp->getSomeField());
        case 2: return oppstring2string(pp->getAnotherField());
        case 3: return double2string(pp->getArrayField1(i));
        case 4: return double2string(pp->getArrayField2(i));
        default: return "";
    }
}

bool VideoMessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    VideoMessage *pp = (VideoMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setSequenceNumber(string2long(value)); return true;
        case 1: pp->setSomeField(string2long(value)); return true;
        case 2: pp->setAnotherField((value)); return true;
        case 3: pp->setArrayField1(i,string2double(value)); return true;
        case 4: pp->setArrayField2(i,string2double(value)); return true;
        default: return false;
    }
}

const char *VideoMessageDescriptor::getFieldStructName(void *object, int field) const
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
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<5) ? fieldStructNames[field] : NULL;
}

void *VideoMessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    VideoMessage *pp = (VideoMessage *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


