#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Fraction.h"

class Menu {

	std::string strExp;
	int strCounter;
	Fraction result;

	bool unary;
	bool pre;

	std::vector<std::string> expression;
	bool sign1;
	int intNumber1;
	int numerator1;
	int denominator1;
	std::string operationSign;
	int sign2;
	int intNumber2;
	int numerator2;
	int denominator2;
	int intValue;
	std::string boolResult;



public:
	void GetExpression();
	void ExpressionAnalysis(std::string exp, int strCounter);
	void operations(std::string exp);
	friend void PrintFraction(Fraction &result, std::string exp);
};