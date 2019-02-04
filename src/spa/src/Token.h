#pragma once

#include <string>

using std::string;

enum class TokenType
{
	Constant,
	Identifier,
	If,
	Then,
	Else,
	Print,
	Procedure,
	Read,
	While,
	Separator,
	OpenParenthesis,
	CloseParenthesis,
	Plus,
	Minus,
	Multiply,
	Divide,
	Mod,
	Greater,
	GreaterThanOrEqual,
	Lesser,
	LesserThanOrEqual,
	Equal,
	NotEqual,
	ExclamationMark,
	And,
	Or
};

class Token {
public:
	Token(TokenType, string, int);
	~Token();
	TokenType getType();
	string getName();
	int getStatementNumber();

private:
	TokenType type;
	string name;
	int statementNumber;
};