#include "CompositeConcrete.h"
#include "Composite.h"
#include "SymbolTable.h"
void MapActualToFormalArguments();
CCompileUnit::CCompileUnit(CSTNode* arg1, CSTNode* arg2) : CSTNode(NT_COMPILEUNIT, 2, arg1, arg2) {}
CCompileUnit::CCompileUnit(CSTNode* arg1) :CSTNode(NT_COMPILEUNIT, 1, arg1) {}
CFunctionDefinition::CFunctionDefinition(CSTNode* id, CSTNode* fargs, CSTNode* compoundst) :CSTNode(NT_FUNCTIONDEFINITION, 3, id, fargs, compoundst) {}
CFunctionDefinition::CFunctionDefinition(CSTNode* id, CSTNode* compoundst) :CSTNode(NT_FUNCTIONDEFINITION, 3, id, new CFormalArgs(), compoundst) {}
CFormalArgs::CFormalArgs(CSTNode* fargs, CSTNode* id) :CSTNode(NT_FORMALARGS, 2, fargs, id) {}
CFormalArgs::CFormalArgs(CSTNode* id) :CSTNode(NT_FORMALARGS, 1, id) {}
CFormalArgs::CFormalArgs() :CSTNode(NT_FORMALARGS, 0) {}
CActualArgs::CActualArgs(CSTNode* actargs, CSTNode* expr) :CSTNode(NT_ACTUALARGS, 2, actargs, expr) {}
CActualArgs::CActualArgs(CSTNode* expr) :CSTNode(NT_ACTUALARGS, 1, expr) {}
CStatement::CStatement(NodeType tp, int children, CSTNode* arg) :CSTNode(tp, children, arg) {}
CStatement::CStatement(NodeType tp, int children) : CSTNode(tp, children) {}
CStatement::CStatement(NodeType tp, int children, CSTNode* arg1, CSTNode* arg2) : CSTNode(tp, children, arg1, arg2) {}
CStatement::CStatement(NodeType tp, int children, CSTNode* arg1, CSTNode* arg2, CSTNode* arg3) : CSTNode(tp, children, arg1, arg2, arg3) {}
CStatement::CStatement(NodeType tp) :CSTNode(tp, 0) {}
CExpressionStatement::CExpressionStatement(CSTNode* arg) :CStatement(NT_EXPRESSIONSTATEMENT, 1, arg) {}
CCompoundStatement::CCompoundStatement(CSTNode* arg) :CStatement(NT_COMPOUNDSTATEMENT, 1, arg) {}
CIfStatement::CIfStatement(CSTNode* cond, CSTNode* ifpath, CSTNode* elsepath) :CStatement(NT_IFSTATEMENT, 3, cond, ifpath, elsepath) {}
CIfStatement::CIfStatement(CSTNode* cond, CSTNode* ifpath) :CStatement(NT_IFSTATEMENT, 2, cond, ifpath) {}
CWhileStatement::CWhileStatement(CSTNode* cond, CSTNode* body) :CStatement(NT_WHILESTATEMENT, 2, cond, body) {}
CReturnStatement::CReturnStatement(CSTNode* expr) :CStatement(NT_RETURNSTATEMENT, 1, expr) {}
CBreakStatement::CBreakStatement() :CStatement(NT_BREAKSTATEMENT, 0) {}
CNullStatement::CNullStatement() : CStatement(NT_EXPRESSION_NUMBER, 0) {}
CStatementList::CStatementList(CSTNode* arg1, CSTNode* arg2) :CSTNode(NT_STATEMENTLIST, 2, arg1, arg2) {}
CStatementList::CStatementList(CSTNode* arg1) : CSTNode(NT_STATEMENTLIST, 1, arg1) {}
CExpression::CExpression(NodeType tp, int children, CSTNode* arg1, CSTNode* arg2) :CSTNode(tp, 2, arg1, arg2) {}
CExpression::CExpression(NodeType tp, int children, CSTNode* arg1) :CSTNode(tp, children, arg1) {}
CExpression::CExpression(NodeType tp) : CSTNode(tp, 0) {}
CExpressionNUMBER::CExpressionNUMBER(const char* text, double value, TypeEnum type) :CExpression(NT_EXPRESSION_NUMBER) {
	setType(GetTypeOfNumber(type));
	m_value = setValue(value);
	m_text = string(text);
}
CExpressionVariable::CExpressionVariable(CSTNode* id) : CExpression(NT_EXPRESSION_VARIABLE) {
	m_text = _strdup(((CIDENTIFIER*)id)->m_text.c_str());
}
CIDENTIFIER::CIDENTIFIER(const char* text) :CSTNode(NT_IDENTIFIER, 0) {
	m_text = _strdup(text);
}
CIDENTIFIER::~CIDENTIFIER() {}
CExpressionFCall::CExpressionFCall(CSTNode* id, CSTNode* actual) : CExpression(NT_EXPRESSION_FCALL, 2, id, actual) {}
CExpressionFCall::CExpressionFCall(CSTNode* id) : CExpression(NT_EXPRESSION_FCALL, 1, id) {}
CExpressionAdd::CExpressionAdd(CSTNode* arg1, CSTNode* arg2) : CExpression(NT_EXPRESSION_ADD, 2, arg1, arg2) {}
CExpressionMinus::CExpressionMinus(CSTNode* arg1, CSTNode* arg2) : CExpression(NT_EXPRESSION_MINUS, 2, arg1, arg2) {}
CExpressionMult::CExpressionMult(CSTNode* arg1, CSTNode* arg2) : CExpression(NT_EXPRESSION_MULT, 2, arg1, arg2) {}
CExpressionDiv::CExpressionDiv(CSTNode* arg1, CSTNode* arg2) : CExpression(NT_EXPRESSION_DIV, 2, arg1, arg2) {}
CExpressionUnaryPlus::CExpressionUnaryPlus(CSTNode* arg1) : CExpression(NT_EXPRESSION_UNARYPLUS, 1, arg1) {}
CExpressionUnaryMinus::CExpressionUnaryMinus(CSTNode* arg1) : CExpression(NT_EXPRESSION_UNARYMINUS, 1, arg1) {}
CExpressionAssign::CExpressionAssign(CSTNode* id, CSTNode* expr) : CExpression(NT_EXPRESSION_ASSIGN, 2, id, expr) {}
CExpressionAND::CExpressionAND(CSTNode* arg1, CSTNode* arg2) : CExpression(NT_EXPRESSION_AND, 2, arg1, arg2) {}
CExpressionOR::CExpressionOR(CSTNode* arg1, CSTNode* arg2) : CExpression(NT_EXPRESSION_OR, 2, arg1, arg2) {}
CExpressionNOT::CExpressionNOT(CSTNode* expr) : CExpression(NT_EXPRESSION_NOT, 1, expr) {}
CExpressionGT::CExpressionGT(CSTNode* arg1, CSTNode* arg2) : CExpression(NT_EXPRESSION_GT, 2, arg1, arg2) {}
CExpressionGTE::CExpressionGTE(CSTNode* arg1, CSTNode* arg2) : CExpression(NT_EXPRESSION_GTE, 2, arg1, arg2) {}
CExpressionLT::CExpressionLT(CSTNode* arg1, CSTNode* arg2) : CExpression(NT_EXPRESSION_LT, 2, arg1, arg2) {}
CExpressionLTE::CExpressionLTE(CSTNode* arg1, CSTNode* arg2) : CExpression(NT_EXPRESSION_LTE, 2, arg1, arg2) {}
CExpressionEQUAL::CExpressionEQUAL(CSTNode* arg1, CSTNode* arg2) : CExpression(NT_EXPRESSION_EQUAL, 2, arg1, arg2) {}
CExpressionNEQUAL::CExpressionNEQUAL(CSTNode* arg1, CSTNode* arg2) : CExpression(NT_EXPRESSION_NEQUAL, 2, arg1, arg2) {}

void CCompileUnit::PrintSyntaxTree(ofstream* dotfile, CSTNode* parent) {
	if (parent != nullptr) {
		(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	}
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CFunctionDefinition::PrintSyntaxTree(ofstream* dotfile, CSTNode* parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CFormalArgs::PrintSyntaxTree(ofstream* dotfile, CSTNode* parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CActualArgs::PrintSyntaxTree(ofstream* dotfile, CSTNode* parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CExpressionStatement::PrintSyntaxTree(ofstream* dotfile, CSTNode* parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CCompoundStatement::PrintSyntaxTree(ofstream* dotfile, CSTNode* parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CIfStatement::PrintSyntaxTree(ofstream* dotfile, CSTNode* parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CWhileStatement::PrintSyntaxTree(ofstream* dotfile, CSTNode* parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CReturnStatement::PrintSyntaxTree(ofstream* dotfile, CSTNode* parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CBreakStatement::PrintSyntaxTree(ofstream* dotfile, CSTNode* parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CNullStatement::PrintSyntaxTree(ofstream* dotfile, CSTNode* parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CStatementList::PrintSyntaxTree(ofstream* dotfile, CSTNode* parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CExpressionNUMBER::PrintSyntaxTree(ofstream* dotfile, CSTNode* parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "_" << m_text << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CExpressionVariable::PrintSyntaxTree(ofstream* dotfile, CSTNode* parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "_" << m_text<< "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CExpressionFCall::PrintSyntaxTree(ofstream* dotfile, CSTNode* parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CExpressionAdd::PrintSyntaxTree(ofstream* dotfile, CSTNode* parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CExpressionMinus::PrintSyntaxTree(ofstream* dotfile, CSTNode* parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CExpressionMult::PrintSyntaxTree(ofstream* dotfile, CSTNode* parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CExpressionDiv::PrintSyntaxTree(ofstream* dotfile, CSTNode* parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CExpressionUnaryPlus::PrintSyntaxTree(ofstream* dotfile, CSTNode* parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CExpressionUnaryMinus::PrintSyntaxTree(ofstream* dotfile, CSTNode* parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CExpressionAssign::PrintSyntaxTree(ofstream* dotfile, CSTNode* parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CExpressionAND::PrintSyntaxTree(ofstream* dotfile, CSTNode* parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CExpressionOR::PrintSyntaxTree(ofstream* dotfile, CSTNode* parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CExpressionNOT::PrintSyntaxTree(ofstream* dotfile, CSTNode* parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CExpressionGT::PrintSyntaxTree(ofstream* dotfile, CSTNode* parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CExpressionGTE::PrintSyntaxTree(ofstream* dotfile, CSTNode* parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CExpressionLT::PrintSyntaxTree(ofstream* dotfile, CSTNode* parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CExpressionLTE::PrintSyntaxTree(ofstream* dotfile, CSTNode* parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CExpressionEQUAL::PrintSyntaxTree(ofstream* dotfile, CSTNode* parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CExpressionNEQUAL::PrintSyntaxTree(ofstream* dotfile, CSTNode* parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CIDENTIFIER::PrintSyntaxTree(ofstream* dotfile, CSTNode* parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() <<"_" << m_text << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}

Type* CExpressionNUMBER::GetTypeOfNumber(TypeEnum type) {
	switch (type) {
		case INTEGER: return new Integer(INTEGER, sizeof(int));
		case FLOAT: return new Float(FLOAT, sizeof(float));
		default:
			return NULL;
	}
}

void CExpression::setType(Type* tp) {
	type = tp;
}

ValueStruct CExpression::setValue(double number) {
	if (dynamic_cast<Integer*>(getType()) != nullptr) {
		val.int_value = (int) number;
		val.isInt = true;
	}
	else if (dynamic_cast<Float*>(getType()) != nullptr) {
		val.float_value = (float) number; 
		val.isInt = false;
	}
	return val;
}

Type* CExpression::getType() {
	return type;
}

ValueStruct CExpression::getValue() {
	return val;
}

ValueStruct CExpressionNUMBER::Evaluate(CSTNode* parent) {
	return m_value;
}

ValueStruct CExpressionVariable::Evaluate(CSTNode* parent) {
	return g_symbolTable.GetSymbol(m_text)->value;
}

ValueStruct CIDENTIFIER::Evaluate(CSTNode* parent) {
	ValueStruct empty{0, 0, false};
	return empty;
}

ValueStruct CExpressionAssign::Evaluate(CSTNode* parent) {
	CIDENTIFIER* id = (CIDENTIFIER*)GetChild(0);
	Symbol* s = g_symbolTable.GetSymbol(id->m_text);
	s->value = GetChild(1)->Evaluate(this);
	if (s->value.isInt) {
		cout << s->m_text << "=" << s->value.int_value << endl;
	}
	else {
		cout << s->m_text << "=" << s->value.float_value << endl;
	}
	return s->value;
}

ValueStruct CExpressionAdd::Evaluate(CSTNode* parent) {
	ValueStruct result;
	if (GetChild(0)->Evaluate(this).isInt) {
		if (GetChild(1)->Evaluate(this).isInt) {
			result.int_value = (int) (GetChild(0)->Evaluate(this).int_value + GetChild(1)->Evaluate(this).int_value);
			result.isInt = true;
		}
		else {
			result.float_value = ((float) GetChild(0)->Evaluate(this).int_value) + GetChild(1)->Evaluate(this).float_value;
			result.isInt = false;
		}
	}
	else {
		if (GetChild(1)->Evaluate(this).isInt) {
			result.float_value = GetChild(0)->Evaluate(this).float_value + ((float) GetChild(1)->Evaluate(this).int_value);
			result.isInt = false;
		}
		else {
			result.float_value = (float) (GetChild(0)->Evaluate(this).float_value + GetChild(1)->Evaluate(this).float_value);
			result.isInt = false;
		}
	}
	return result;

}

ValueStruct CExpressionMinus::Evaluate(CSTNode* parent) {
	ValueStruct result;
	if (GetChild(0)->Evaluate(this).isInt) {
		if (GetChild(1)->Evaluate(this).isInt) {
			result.int_value = (int)(GetChild(0)->Evaluate(this).int_value - GetChild(1)->Evaluate(this).int_value);
			result.isInt = true;
		}
		else {
			result.float_value = ((float)GetChild(0)->Evaluate(this).int_value) - GetChild(1)->Evaluate(this).float_value;
			result.isInt = false;
		}
	}
	else {
		if (GetChild(1)->Evaluate(this).isInt) {
			result.float_value = GetChild(0)->Evaluate(this).float_value - ((float)GetChild(1)->Evaluate(this).int_value);
			result.isInt = false;
		}
		else {
			result.float_value = (float)(GetChild(0)->Evaluate(this).float_value - GetChild(1)->Evaluate(this).float_value);
			result.isInt = false;
		}
	}
	return result;
}

ValueStruct CExpressionMult::Evaluate(CSTNode* parent) {
	ValueStruct result;
	if (GetChild(0)->Evaluate(this).isInt) {
		if (GetChild(1)->Evaluate(this).isInt) {
			result.int_value = (int)(GetChild(0)->Evaluate(this).int_value * GetChild(1)->Evaluate(this).int_value);
			result.isInt = true;
		}
		else {
			result.float_value = ((float)GetChild(0)->Evaluate(this).int_value) * GetChild(1)->Evaluate(this).float_value;
			result.isInt = false;
		}
	}
	else {
		if (GetChild(1)->Evaluate(this).isInt) {
			result.float_value = GetChild(0)->Evaluate(this).float_value * ((float)GetChild(1)->Evaluate(this).int_value);
			result.isInt = false;
		}
		else {
			result.float_value = (float)(GetChild(0)->Evaluate(this).float_value * GetChild(1)->Evaluate(this).float_value);
			result.isInt = false;
		}
	}
	return result;
}

ValueStruct CExpressionDiv::Evaluate(CSTNode* parent) {
	ValueStruct denom, result;
	denom = GetChild(1)->Evaluate(this);
	if (denom.int_value == 0) {
		cout << "Division by zero" << endl;
		exit(1);
	}
	else {
		if (GetChild(0)->Evaluate(this).isInt) {
			if (denom.isInt) {
				result.int_value = (int)(GetChild(0)->Evaluate(this).int_value / denom.int_value);
				result.isInt = true;
			}
			else {
				result.float_value = ((float)GetChild(0)->Evaluate(this).int_value) / denom.float_value;
				result.isInt = false;
			}
		}
		else {
			if (denom.isInt) {
				result.float_value = GetChild(0)->Evaluate(this).float_value / ((float)denom.int_value);
				result.isInt = false;
			}
			else {
				result.float_value = (float)(GetChild(0)->Evaluate(this).float_value / denom.float_value);
				result.isInt = false;
			}
		}
	}
	return result;
}

ValueStruct CExpressionUnaryPlus::Evaluate(CSTNode* parent) {
	ValueStruct outcome;

	if (GetChild(0)->Evaluate(this).isInt) {
		outcome.int_value = +GetChild(0)->Evaluate(this).int_value;
		outcome.isInt = true;
	}
	else {
		outcome.float_value = +GetChild(0)->Evaluate(this).float_value;
		outcome.isInt = false;
	}
	return outcome;
}

ValueStruct CExpressionUnaryMinus::Evaluate(CSTNode* parent) {
	ValueStruct outcome;

	if (GetChild(0)->Evaluate(this).isInt) {
		outcome.int_value = -GetChild(0)->Evaluate(this).int_value;
		outcome.isInt = true;
	}
	else {
		outcome.float_value = -GetChild(0)->Evaluate(this).float_value;
		outcome.isInt = false;
	}
	return outcome;
}

ValueStruct CExpressionGT::Evaluate(CSTNode* parent) {
	ValueStruct outcome;
	if (GetChild(0)->Evaluate(this).isInt) {
		if (GetChild(1)->Evaluate(this).isInt) {
			outcome.int_value = (GetChild(0)->Evaluate(this).int_value) > (GetChild(1)->Evaluate(this).int_value);
		}
		else {
			outcome.int_value = ((float)GetChild(0)->Evaluate(this).int_value) > (GetChild(1)->Evaluate(this).float_value);
		}
	}
	else {
		if (GetChild(1)->Evaluate(this).isInt) {
			outcome.int_value = (GetChild(0)->Evaluate(this).float_value) > ((float)GetChild(1)->Evaluate(this).int_value);
		}
		else {
			outcome.int_value = ((float)(GetChild(0)->Evaluate(this).float_value)) > (GetChild(1)->Evaluate(this).float_value);
		}
	}
	return outcome;
}

ValueStruct CExpressionGTE::Evaluate(CSTNode* parent) {
	ValueStruct outcome;
	if (GetChild(0)->Evaluate(this).isInt) {
		if (GetChild(1)->Evaluate(this).isInt) {
			outcome.int_value = (GetChild(0)->Evaluate(this).int_value) >= (GetChild(1)->Evaluate(this).int_value);
		}
		else {
			outcome.int_value = ((float)GetChild(0)->Evaluate(this).int_value) >= (GetChild(1)->Evaluate(this).float_value);
		}
	}
	else {
		if (GetChild(1)->Evaluate(this).isInt) {
			outcome.int_value = (GetChild(0)->Evaluate(this).float_value) >= ((float)GetChild(1)->Evaluate(this).int_value);
		}
		else {
			outcome.int_value = ((float)(GetChild(0)->Evaluate(this).float_value)) >= (GetChild(1)->Evaluate(this).float_value);
		}
	}
	return outcome;
}

ValueStruct CExpressionLT::Evaluate(CSTNode* parent) {
	ValueStruct outcome;
	if (GetChild(0)->Evaluate(this).isInt) {
		if (GetChild(1)->Evaluate(this).isInt) {
			outcome.int_value = (GetChild(0)->Evaluate(this).int_value) < (GetChild(1)->Evaluate(this).int_value);
		}
		else {
			outcome.int_value = ((float)GetChild(0)->Evaluate(this).int_value) < (GetChild(1)->Evaluate(this).float_value);
		}
	}
	else {
		if (GetChild(1)->Evaluate(this).isInt) {
			outcome.int_value = (GetChild(0)->Evaluate(this).float_value) < ((float)GetChild(1)->Evaluate(this).int_value);
		}
		else {
			outcome.int_value = ((float)(GetChild(0)->Evaluate(this).float_value)) < (GetChild(1)->Evaluate(this).float_value);
		}
	}
	return outcome;
}

ValueStruct CExpressionLTE::Evaluate(CSTNode* parent) {
	ValueStruct outcome;
	if (GetChild(0)->Evaluate(this).isInt) {
		if (GetChild(1)->Evaluate(this).isInt) {
			outcome.int_value = (GetChild(0)->Evaluate(this).int_value) <= (GetChild(1)->Evaluate(this).int_value);
		}
		else {
			outcome.int_value = ((float)GetChild(0)->Evaluate(this).int_value) <= (GetChild(1)->Evaluate(this).float_value);
		}
	}
	else {
		if (GetChild(1)->Evaluate(this).isInt) {
			outcome.int_value = (GetChild(0)->Evaluate(this).float_value) <= ((float)GetChild(1)->Evaluate(this).int_value);
		}
		else {
			outcome.int_value = ((float)(GetChild(0)->Evaluate(this).float_value)) <= (GetChild(1)->Evaluate(this).float_value);
		}
	}
	return outcome;
}

ValueStruct CExpressionEQUAL::Evaluate(CSTNode* parent) {
	ValueStruct outcome;
	if (GetChild(0)->Evaluate(this).isInt) {
		if (GetChild(1)->Evaluate(this).isInt) {
			outcome.int_value = (GetChild(0)->Evaluate(this).int_value) == (GetChild(1)->Evaluate(this).int_value);
		}
		else {
			outcome.int_value = ((float)GetChild(0)->Evaluate(this).int_value) == (GetChild(1)->Evaluate(this).float_value);
		}
	}
	else {
		if (GetChild(1)->Evaluate(this).isInt) {
			outcome.int_value = (GetChild(0)->Evaluate(this).float_value) == ((float)GetChild(1)->Evaluate(this).int_value);
		}
		else {
			outcome.int_value = ((float)(GetChild(0)->Evaluate(this).float_value)) == (GetChild(1)->Evaluate(this).float_value);
		}
	}
	return outcome;
}

ValueStruct CExpressionNEQUAL::Evaluate(CSTNode* parent) {
	ValueStruct outcome;
	if (GetChild(0)->Evaluate(this).isInt) {
		if (GetChild(1)->Evaluate(this).isInt) {
			outcome.int_value = (GetChild(0)->Evaluate(this).int_value) != (GetChild(1)->Evaluate(this).int_value);
		}
		else {
			outcome.int_value = ((float)GetChild(0)->Evaluate(this).int_value) != (GetChild(1)->Evaluate(this).float_value);
		}
	}
	else {
		if (GetChild(1)->Evaluate(this).isInt) {
			outcome.int_value = (GetChild(0)->Evaluate(this).float_value) != ((float)GetChild(1)->Evaluate(this).int_value);
		}
		else {
			outcome.int_value = ((float)(GetChild(0)->Evaluate(this).float_value)) != (GetChild(1)->Evaluate(this).float_value);
		}
	}
	return outcome;
}

ValueStruct CExpressionAND::Evaluate(CSTNode* parent) {
	ValueStruct outcome;
	if (GetChild(0)->Evaluate(this).isInt) {
		if (GetChild(1)->Evaluate(this).isInt) {
			outcome.int_value = (GetChild(0)->Evaluate(this).int_value) && (GetChild(1)->Evaluate(this).int_value);
		}
		else {
			outcome.int_value = ((float)GetChild(0)->Evaluate(this).int_value) && (GetChild(1)->Evaluate(this).float_value);
		}
	}
	else {
		if (GetChild(1)->Evaluate(this).isInt) {
			outcome.int_value = (GetChild(0)->Evaluate(this).float_value) && ((float)GetChild(1)->Evaluate(this).int_value);
		}
		else {
			outcome.int_value = ((float)(GetChild(0)->Evaluate(this).float_value)) && (GetChild(1)->Evaluate(this).float_value);
		}
	}
	return outcome;
}

ValueStruct CExpressionOR::Evaluate(CSTNode* parent) {
	ValueStruct outcome;
	if (GetChild(0)->Evaluate(this).isInt) {
		if (GetChild(1)->Evaluate(this).isInt) {
			outcome.int_value = (GetChild(0)->Evaluate(this).int_value) || (GetChild(1)->Evaluate(this).int_value);
		}
		else {
			outcome.int_value = ((float)GetChild(0)->Evaluate(this).int_value) || (GetChild(1)->Evaluate(this).float_value);
		}
	}
	else {
		if (GetChild(1)->Evaluate(this).isInt) {
			outcome.int_value = (GetChild(0)->Evaluate(this).float_value) || ((float)GetChild(1)->Evaluate(this).int_value);
		}
		else {
			outcome.int_value = ((float)(GetChild(0)->Evaluate(this).float_value)) || (GetChild(1)->Evaluate(this).float_value);
		}
	}
	return outcome;
}

ValueStruct CExpressionNOT::Evaluate(CSTNode* parent) {
	ValueStruct outcome;
	if (GetChild(0)->Evaluate(this).isInt) {
		outcome.int_value = !(GetChild(0)->Evaluate(this).int_value);
	}
	else {
		outcome.float_value = !(GetChild(0)->Evaluate(this).float_value);
	}
	return outcome;
}

ValueStruct CExpressionStatement::Evaluate(CSTNode* parent) {
	ValueStruct empty;
	CExpression* child = (CExpression*)GetChild(0);
	ValueStruct result = child->Evaluate(this);

	if (result.isInt) {
		//result.int_value = child->Evaluate(this).int_value;
		if (child->GetNodeType() != NT_EXPRESSION_ASSIGN) {
			cout << ":" << result.int_value << endl;
		}
	}
	else {
		//result.float_value = child->Evaluate(this).float_value;
		if (child->GetNodeType() != NT_EXPRESSION_ASSIGN) {
			cout << ":" << result.float_value << endl;
		}
	}
	return empty;
}

ValueStruct CWhileStatement::Evaluate(CSTNode* parent) {
	ValueStruct empty, c0_outcome, c1_outcome;
	c0_outcome = GetChild(0)->Evaluate(this);
	c1_outcome = GetChild(1)->Evaluate(this);
	while (GetChild(0)->Evaluate(this).int_value) {
		if (c0_outcome.isInt) {
			GetChild(1)->Evaluate(this).int_value;
		}
		else if (!(c1_outcome.isInt)) {
			GetChild(1)->Evaluate(this).float_value;
		}
		if (m_breakVisit) {
			m_breakVisit = false;
			break;
		}
	}
	return empty;
}

ValueStruct CIfStatement::Evaluate(CSTNode* parent) {
	ValueStruct empty;
	ValueStruct child1Eval = GetChild(0)->Evaluate(this);
	ValueStruct child2Eval = GetChild(1)->Evaluate(this);

	switch (m_children->size()) {
		case 2:
			if (child1Eval.int_value) {
				if (child1Eval.isInt) {
					GetChild(1)->Evaluate(this).int_value;
				}
				else {
					GetChild(1)->Evaluate(this).float_value;
				}
			}
			break;
		case 3:
			if (child1Eval.int_value) {
				if (child1Eval.isInt) {
					GetChild(1)->Evaluate(this).int_value;
				}
				else {
					GetChild(1)->Evaluate(this).float_value;
				}
			}
			else {
				if (child2Eval.isInt) {
					GetChild(2)->Evaluate(this).int_value;
				}
				else {
					GetChild(2)->Evaluate(this).float_value;
				}
			}
			break;
		default:;
	}
	return empty;
}

ValueStruct CBreakStatement::Evaluate(CSTNode* parent) {
	ValueStruct empty {0, 0, false};
	m_breakVisit = true;
	return empty;
}

void GetFormalArguments(CSTNode* currentnode, list<CIDENTIFIER*>* arguments) {
	list<CSTNode*>::iterator it;

	if (dynamic_cast<CIDENTIFIER*>(currentnode) != nullptr) {
		arguments->push_back((CIDENTIFIER*)currentnode);
	}

	for (it = currentnode->m_children->begin(); it != currentnode->m_children->end(); it++) {
		GetFormalArguments((*it), arguments);
	}
}


void CExpressionFCall::MapActualToFormalArguments() {
	CIDENTIFIER* fid = (CIDENTIFIER*)GetChild(0);
	CActualArgs* aArgs = (CActualArgs*)GetChild(1);
	CFunctionDefinition* fundef = (CFunctionDefinition*)g_symbolTable.GetSymbol(fid->m_text)->syntaxNode;
	CFormalArgs* fargs = (CFormalArgs*)fundef->GetChild(1);
	list<CIDENTIFIER*>::iterator it;
	list<CExpression*>::iterator ite;
	m_actualArguments = new list<CExpression*>();
	m_formalArguments = new list<CIDENTIFIER*>();
	GetActualArguments(aArgs, m_actualArguments);
	GetFormalArguments(fargs, m_formalArguments);
	for (it = m_formalArguments->begin(), ite = m_actualArguments->begin(); it != m_formalArguments->end(); it++, ite++) {
		g_symbolTable.GetSymbol((*it)->m_text)->value = (*ite)->Evaluate(this);
	}
}

void GetActualArguments(CSTNode* currentnode, list<CExpression*>* arguments) {
	list<CSTNode*>::iterator it;

	if (dynamic_cast<CExpression*>(currentnode) != nullptr) {
		arguments->push_back((CExpression*)currentnode);
	}

	for (it = currentnode->m_children->begin(); it != currentnode->m_children->end(); it++) {
		GetActualArguments((*it), arguments);
	}
}

ValueStruct CExpressionFCall::GetActualArgument(int index) {
	CActualArgs* aArgs = (CActualArgs*)GetChild(1);
	list<CExpression*>::iterator it;
	if (m_actualArguments == nullptr) {
		m_actualArguments = new list<CExpression*>();
		GetActualArguments(aArgs, m_actualArguments);
	}
	it = m_actualArguments->begin();
	advance(it, index);
	return (*it)->Evaluate(this);
}

ValueStruct CReturnStatement::Evaluate(CSTNode* parent) {
	//1.Mark the end of function
	m_breakVisit = true;
	m_returnedValue = GetChild(0)->Evaluate(this);
	return m_returnedValue;
}

ValueStruct CExpressionFCall::Evaluate(CSTNode* parent) {
	ValueStruct result{0,0,false}, aArg0, aArg1;
	CIDENTIFIER* functionId = (CIDENTIFIER*)GetChild(0);
	CFunctionDefinition* fundef;

	if (!functionId->m_text.compare("sqrt")) {
		aArg0 = GetActualArgument(0);
		if (aArg0.isInt) {
			result.float_value = sqrt(GetActualArgument(0).int_value);
		}
		else {
			result.float_value = sqrt(GetActualArgument(0).float_value);
		}
	}
	else if (!functionId->m_text.compare("pow")) {
		aArg0 = GetActualArgument(0);
		aArg1 = GetActualArgument(1);
		if (aArg0.isInt && aArg1.isInt) {
			result.float_value = pow(GetActualArgument(0).int_value, GetActualArgument(1).int_value);
		}
		else if (!(aArg0.isInt) && !(aArg1.isInt)) {
			result.float_value = pow(GetActualArgument(0).float_value, GetActualArgument(1).float_value);
		}
		else if (!(aArg0.isInt) && aArg1.isInt) {
			result.float_value = pow(GetActualArgument(0).float_value, GetActualArgument(1).int_value);
		}
		else if (aArg0.isInt && !(aArg1.isInt)) {
			result.float_value = pow(GetActualArgument(0).int_value, GetActualArgument(1).float_value);
		}
	}
	else {
		// 1. Get access to the function definition object
		fundef = (CFunctionDefinition*)g_symbolTable.GetSymbol(functionId->m_text)->syntaxNode;
		// Map actual to formal arguments 
		MapActualToFormalArguments();
		// Evaluate
		fundef->GetChild(2)->Evaluate(this);
		// Return value
		result = m_returnedValue;
		//m_breakVisit = false;
	}

	return result;
}
ValueStruct CFunctionDefinition::Evaluate(CSTNode* parent) { 
	ValueStruct empty{0, 0, false}; return empty;
}