#include "Types.h"


Type::Type(TypeEnum type, int size) {
	c_type = type;
	c_byteSize = size;
}

Type::~Type() {}

void Type::SetType(TypeEnum type) {
	c_type = type;
}

void Type::SetByteSize(int byteSize) {
	c_byteSize = byteSize;
}

TypeEnum Type::GetType() {
	return c_type;
}

int Type::GetByteSize() {
	return c_byteSize;
}

Integer::Integer(TypeEnum type, int size) : Type(type, size) {}

Float::Float(TypeEnum type, int size) : Type(type, size) {}