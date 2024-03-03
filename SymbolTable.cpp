#include "SymbolTable.h"
#include "CompositeConcrete.h"
SymbolTable g_symbolTable;
Symbol* SymbolTable::GetSymbol(string textKey) {
	Symbol* symbol;
	ValueStruct empty{0, 0, false};
	map<string, Symbol*>::iterator it;
	it = m_symbolTable->find(textKey);
	if (it == m_symbolTable->end()) {
		symbol = new Symbol{ textKey, empty, new CIDENTIFIER(textKey.c_str()) };
		(*m_symbolTable)[textKey] = symbol;
		return symbol;
	}
	else {
		return (*m_symbolTable)[textKey];
	}
}