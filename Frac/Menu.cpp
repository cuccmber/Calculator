#include <iostream>
#include "Menu.h"
#include "Fraction.h"

std::ifstream fin;
std::ofstream fout;

void Menu::GetExpression() {

	strCounter = 0;

	fin.open("Expression.txt");

	while (!fin.eof()) {
		getline(fin, strExp);
		expression.push_back(strExp);
		strCounter++;
	}

	fin.close();

	for (int i = 0; i < strCounter - 1; i++)
		ExpressionAnalysis(expression[i], strCounter);

}


void  Menu::ExpressionAnalysis(std::string exp, int strCounter) {

	/*----------Fraction1----------*/


	unary = false;
	pre = false;

	std::string strIntNumber1;
	std::string strNumerator1;
	std::string strDenominator1;
	operationSign = "00000000000";
	intValue = -999999999;

	int strHead = 3;

	if (exp[1] == '+') {
		unary = true;
		pre = true;
		operationSign = "++";
	}

	if (exp[1] == '-') {
		unary = true;
		pre = true;
		operationSign = "--";
	}

	if (exp[strHead] == '+') {
		sign1 = 1;
	}
	else {
		sign1 = 0;
	}

	strHead++;
	int strPosition = 0;

	if (exp[strHead] == ' ') {
		strHead++;
	}
	else {

		while (exp[strHead] != ' ') {
			strIntNumber1 += exp[strHead];
			strHead++;
		}

		intNumber1 = stoi(strIntNumber1);

	}

	strHead++;

	while (exp[strHead] != '/') {
		strNumerator1 += exp[strHead];
		strHead++;
	}

	numerator1 = stoi(strNumerator1);
	strHead++;

	strPosition = 0;

	while (exp[strHead] != ' ' && exp[strHead] != '\n') {
		strDenominator1 += exp[strHead];
		strHead++;
	}

	denominator1 = stoi(strDenominator1);

	if (denominator1 == 0) {
		std::cout << "Error!" << std::endl;

	}

	strPosition = 0;
	strHead++;

	/*----------Fraction1----------*/

	if (unary != true) {

		/*----------Operation sign----------*/


		if (exp[strHead + 1] != ' ') {
			operationSign[0] = exp[strHead];
			operationSign[1] = exp[strHead + 1];

			if ((exp[strHead + 1] == '+') || (exp[strHead + 1] == '-') || (exp[strHead + 1] == 'd')) {
				unary = true;
			}
			strHead += 3;
		}
		else {
			operationSign[0] = exp[strHead];
			strHead += 2;
		}

		/*----------Operation sign----------*/

		if (unary != true) {



			/*----------Fraction2----------*/

			std::string strIntNumber2;
			std::string strNumerator2;
			std::string strDenominator2;

			if (exp[strHead] == '+') {
				sign2 = 1;
			}
			else {
				sign2 = 0;
			}

			strHead++;

			if (exp[strHead] == ' ') {
				strHead++;
			}
			else {

				while (exp[strHead] != ' ') {
					strIntNumber2 += exp[strHead];
					strHead++;
				}

				intNumber2 = stoi(strIntNumber2);

			}

			strHead++;

			if (exp[strHead] == ' ') {
				if (sign2 == 1)
					intValue = intNumber2;
				else
					intValue = -intNumber2;
			}
			else {

				while (exp[strHead] != '/') {
					strNumerator2 += exp[strHead];
					strHead++;
					strPosition++;
				}

				numerator2 = stoi(strNumerator2);

				strPosition = 0;
				strHead++;

				while (exp[strHead] != ' ') {
					strDenominator2 += exp[strHead];
					strHead++;
				}

				denominator2 = stoi(strDenominator2);

				if (denominator1 == 0) {
					std::cout << "Error!" << std::endl;

				}

			}
			/*----------Fraction2----------*/

		}
	}

	operations(exp);

}


void Menu::operations(std::string exp) {

	Fraction fractionOne(sign1, intNumber1, numerator1, denominator1);
	Fraction fractionTwo;
	if (unary != true && intValue == -999999999) {
		Fraction a(sign2, intNumber2, numerator2, denominator2);
		fractionTwo = a;
	}

	if (operationSign[0] == 't') {
		fout.open("OUTPUT.txt", std::ofstream::app);

		fout << exp << " " << "=" << " " << fractionOne.ToDouble() << std::endl;

		fout.close();
	}
	else {

		if (intValue == -999999999) {
			if (operationSign[0] == '+') {
				if (operationSign[1] == '+') {
					if (pre == true) {
						result = ++fractionOne;
					}
					else {
						result = fractionOne++;
						resForIncrement = fractionOne;
					}
				}
				else if (operationSign[1] == '=') {
					result = (fractionOne += fractionTwo);
				}
				else {
					result = fractionOne + fractionTwo;
				}
			}

			if (operationSign[0] == '-') {
				if (operationSign[1] == '-') {
					if (pre == true) {
						result = --fractionOne;
					}
					else {
						result = fractionOne--;
						resForIncrement = fractionOne;
					}
				}
				else if (operationSign[1] == '=') {
					result = (fractionOne -= fractionTwo);
				}
				else {
					result = fractionOne - fractionTwo;
				}
			}

			if (operationSign[0] == '*') {
				if (operationSign[1] == '=') {
					result = (fractionOne *= fractionTwo);
				}
				else {
					result = fractionOne * fractionTwo;
				}
			}

			if (operationSign[0] == '/') {
				if (operationSign[1] == '=') {
					result = (fractionOne /= fractionTwo);
				}
				else {
					result = fractionOne / fractionTwo;
				}
			}

			if (operationSign[0] == '>') {
				if (operationSign[1] == '=') {
					if ((fractionOne >= fractionTwo) == 1) {
						boolResult = "true";
					}
					else {
						boolResult = "false";
					}
				}
				else {
					if ((fractionOne > fractionTwo) == 1) {
						boolResult = "true";
					}
					else {
						boolResult = "false";
					}
				}
			}

			if (operationSign[0] == '<') {
				if (operationSign[1] == '=') {
					if ((fractionOne <= fractionTwo) == 1) {
						boolResult = "true";
					}
					else {
						boolResult = "false";
					}
				}
				else {
					if ((fractionOne < fractionTwo) == 1) {
						boolResult = "true";
					}
					else {
						boolResult = "false";
					}
				}
			}
		}
		else {
			if (operationSign[0] == '+') {
				if (operationSign[1] == '=') {
					result = (fractionOne += intValue);
				}
				else {
					result = fractionOne + intValue;
				}
			}

			if (operationSign[0] == '-') {
				if (operationSign[1] == '=') {
					result = (fractionOne -= intValue);
				}
				else {
					result = fractionOne - intValue;
				}
			}

			if (operationSign[0] == '*') {
				if (operationSign[1] == '=') {
					result = (fractionOne *= intValue);
				}
				else {
					result = fractionOne * intValue;
				}
			}

			if (operationSign[0] == '/') {
				if (operationSign[1] == '=') {
					result = (fractionOne /= intValue);
				}
				else {
					result = fractionOne / intValue;
				}
			}

			if (operationSign[0] == '>') {
				if (operationSign[1] == '=') {
					if ((fractionOne >= intValue) == 1) {
						boolResult = "true";
					}
					else {
						boolResult = "false";
					}
				}
				else {
					if ((fractionOne > intValue) == 1) {
						boolResult = "true";
					}
					else {
						boolResult = "false";
					}
				}
			}

			if (operationSign[0] == '<') {
				if (operationSign[1] == '=') {
					if ((fractionOne <= intValue) == 1) {
						boolResult = "true";
					}
					else {
						boolResult = "false";
					}
				}
				else {
					if ((fractionOne < intValue) == 1) {
						boolResult = "true";
					}
					else {
						boolResult = "false";
					}
				}
			}
		}

		if ((operationSign[0] != '<') && (operationSign[0] != '>')) {
			PrintFraction(result, exp, unary, pre, resForIncrement);
		}
		else {
			fout.open("OUTPUT.txt", std::ofstream::app);

			fout << exp << " " << "=" << " " << boolResult << std::endl;;

			fout.close();
		}
	}

}


void PrintFraction(Fraction &result, std::string exp, bool unary, bool pre, Fraction &resForIncrement) {

	std::string strResult;
	std::string sign;
	std::string signForInc;

	fout.open("OUTPUT.txt", std::ofstream::app);

	if (result.sign == 1) {
		sign = "+";
	}
	else {
		sign = "-";
	}
	if (unary == true && pre == false) {
		if (resForIncrement.sign == 1) {
			signForInc = "+";
		}
		else {
			signForInc = "-";
		}
		if (resForIncrement.numerator == 0) {
			strResult = " = " + sign + std::to_string(result.intNumber) + "; Fraction = " + signForInc + std::to_string(resForIncrement.intNumber);
		}
		else {
			strResult = " = " + sign + std::to_string(result.intNumber) + ' ' + std::to_string(result.numerator) + '/' + std::to_string(result.denominator) + "; Fraction = " + signForInc + std::to_string(resForIncrement.intNumber) + ' ' + std::to_string(resForIncrement.numerator) + '/' + std::to_string(resForIncrement.denominator);
		}
	}
	else {
		if (result.numerator == 0) {
			strResult = " = " + sign + std::to_string(result.intNumber);
		}
		else {
			strResult = " = " + sign + std::to_string(result.intNumber) + ' ' + std::to_string(result.numerator) + '/' + std::to_string(result.denominator);
		}
	}

	fout << exp << strResult << std::endl;

	fout.close();

	std::cout << "Mission Complete!" << std::endl;
}


