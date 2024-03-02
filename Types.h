#pragma once
/*
*	enum for int and float 
*	
*	class type for types, enum types as member
*	
*	subclasses integer and float type from parent type
* 
*	size of integer and float ... as members
* 
*	union value with int and float 
*/

typedef struct ValueStruct {
	int int_value;
	float float_value;
    bool isInt;
} ValueStruct;

typedef enum TypeEnum {
	INTEGER, 
	FLOAT
} TypeEnum;

class Type;

class Type {
public:
    Type(TypeEnum, int);
    virtual ~Type();
    void SetType(TypeEnum);
    void SetByteSize(int);
    TypeEnum GetType();
    int GetByteSize();

protected:
    TypeEnum c_type;
    int c_byteSize;

};

class Integer : public Type {
public:
    Integer(TypeEnum, int);
};

class Float : public Type {
public:
    Float(TypeEnum, int);
};

