#include <iostream>
#include "Fraction.h"

Fraction::Fraction(bool sig, int integer, int num, int den) {
	sign = sig;
	intNumber = integer;
	numerator = num;
	//if (den == 0) {
	//	denominator = 1;
	//}
	//else {
		denominator = den;
	//}


	GetIntNumber();
	Cancellation();
}




void Fraction::print() {
	if (sign == 1) {
		std::cout << "+";
	}
	else { 
		std::cout << "-";
	}
	std::cout << intNumber << " " << numerator << "/" << denominator << std::endl;
}





int Fraction::GetGCF(int a, int b) {  //Euclid's algorithm


	if (a == b) {
		return a;
	}
	if (a > b) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	return GetGCF(a, b - a);

}

int Fraction::GetLCM(int a, int b) {
	return a * b / GetGCF(a, b);
}

void Fraction::GetIntNumber() {
	int intCount;
	if (numerator >= denominator) {
		intCount = numerator / denominator;
		intNumber += intCount;

		if (numerator == 0) {
			denominator = 1;
		}
		else {
			numerator -= intCount * denominator;
		}
	}

}

void Fraction::Cancellation() {
	if (numerator != 0) {
		int temp = numerator;
		numerator /= GetGCF(numerator, denominator);
		denominator /= GetGCF(temp, denominator);
	}
}

void Fraction::CommonFraction() {
	numerator = intNumber * denominator + numerator;
	intNumber = 0;
}

Fraction ToCommonDenominator(Fraction &fractionOne, Fraction &fractionTwo) {
	Fraction resFraction = fractionOne;
	int resDenominator = fractionOne.GetLCM(fractionOne.denominator, fractionTwo.denominator);
	resFraction.numerator *= resDenominator / fractionOne.denominator;
	resFraction.denominator = resDenominator;

	return resFraction;

}

Fraction IntToFraction(Fraction &fractionOne, int intValue) {
	Fraction res(1, abs(intValue), 0, fractionOne.denominator);
	if (intValue < 0) {
		res.sign = 0;
	}

	return res;

}





bool  operator>(Fraction &fractionOne, Fraction &fractionTwo) {

	bool res = false;
	if (fractionOne.sign != fractionTwo.sign) {
		if (fractionOne.sign == 1) {
			res = true;
			return res;
		}
		else {
			return res;
		}
	}

	if (fractionOne.sign == fractionTwo.sign && fractionOne.sign == 1) {
		if (fractionOne.intNumber > fractionTwo.intNumber) {
			res = true;
			return res;
		}

		if (ToCommonDenominator(fractionOne, fractionTwo).numerator > ToCommonDenominator(fractionTwo, fractionOne).numerator) {
			res = true;
		}
	}

	else if (fractionOne.sign == fractionTwo.sign && fractionTwo.sign == 0) {
		if (fractionOne.intNumber < fractionTwo.intNumber) {
			res = true;
			return res;
		}

		if (ToCommonDenominator(fractionOne, fractionTwo).numerator < ToCommonDenominator(fractionTwo, fractionOne).numerator) {
			res = true;
		}
		

	}

	return res;

}

bool  operator<(Fraction &fractionOne, Fraction &fractionTwo) {
	bool res = true;
	if (fractionOne > fractionTwo) {
		res = false;
	}
	return res;
}

bool operator==(Fraction &fractionOne, Fraction &fractionTwo) {
	bool res = false;
	if (fractionOne.sign == fractionTwo.sign && fractionOne.intNumber == fractionTwo.intNumber && fractionOne.numerator == fractionTwo.numerator && fractionOne.denominator == fractionTwo.denominator) {
		res = true;
			
	}
	return res;
}

bool operator>=(Fraction &fractionOne, Fraction &fractionTwo) {
	bool res = false;
	if (fractionOne > fractionTwo || fractionOne == fractionTwo) {
		res = true;
	}
	return res;
}

bool operator<=(Fraction &fractionOne, Fraction &fractionTwo) {
	bool res = false;
	if (fractionOne < fractionTwo || fractionOne == fractionTwo) {
		res = true;
	}
	return res;
}
//TEST
bool operator>(Fraction &fractionOne, int intValue) {
	bool res = false;
	Fraction intValueFraction = IntToFraction(fractionOne, intValue);
	if (fractionOne > intValueFraction) {
		res = true;
	}

	return res;
}

bool operator<(Fraction &fractionOne, int intValue) {
	bool res = false;
	Fraction intValueFraction = IntToFraction(fractionOne, intValue);
	if (fractionOne < intValueFraction) {
		res = true;
	}

	return res;
}

bool operator>=(Fraction &fractionOne, int intValue) {
	bool res = false;
	Fraction intValueFraction = IntToFraction(fractionOne, intValue);
	if (fractionOne > intValueFraction || fractionOne == intValueFraction) {
		res = true;
	}
	return res;
}
bool operator<=(Fraction &fractionOne, int intValue) {
	bool res = false;
	Fraction intValueFraction = IntToFraction(fractionOne, intValue);
	if (fractionOne < intValueFraction || fractionOne == intValueFraction) {
		res = true;
	}
	return res;
}

bool operator==(Fraction &fractionOne, int intValue) {
	bool res = false;
	Fraction intValueFraction = IntToFraction(fractionOne, intValue);
	if (fractionOne == intValueFraction) {
		res = true;
	}
	return res;
}





Fraction operator+(Fraction &fractionOne, Fraction &fractionTwo) {
	Fraction res, summandOne, summandTwo;
	summandOne = fractionOne;
	summandOne.CommonFraction();
	summandTwo = fractionTwo;
	summandTwo.CommonFraction();
	bool signOne = 0, signTwo = 0;

	if (summandOne.denominator != summandTwo.denominator) {
		summandOne = ToCommonDenominator(summandOne, summandTwo);
		summandTwo = ToCommonDenominator(summandTwo, summandOne);
	}

	if (summandOne.sign == summandTwo.sign) {
		res.numerator = summandOne.numerator + summandTwo.numerator;
		res.denominator = summandOne.denominator;

		if (summandOne.sign == 1) {
			res.sign = 1;
		}
		else {
			res.sign = 0;
		}
	}

	if (summandOne.sign != summandTwo.sign) {

		res.numerator = abs(summandOne.numerator - summandTwo.numerator);
		res.denominator = summandOne.denominator;

		if (summandOne.sign == 1) {
			signOne = 1;
		}
		if(summandTwo.sign == 1){
			signTwo = 1;
		}
		summandOne.sign = 1;
		summandTwo.sign = 1;

		if (summandOne > summandTwo) {
			res.sign = signOne;
		}
		else {
			res.sign = signTwo;
		}

	}

	res.GetIntNumber();
	res.Cancellation();

	return res;
}

Fraction operator+(Fraction &fractionOne, int intValue) {
	Fraction intvalueFraction = IntToFraction(fractionOne, intValue);

	return fractionOne + intvalueFraction;
}

Fraction& Fraction::operator+=(Fraction &fractionOne) {
	*this = *this + fractionOne;
	return *this;

}

Fraction& Fraction::operator+=(int intValue) {
	*this = *this + intValue;
	return *this;

}

Fraction operator-(Fraction &fractionOne, Fraction &fractionTwo) {
	Fraction minued = fractionOne;
	Fraction subtrahend = fractionTwo;
	Fraction res;

	if (subtrahend.sign == 0) {
		subtrahend.sign = 1;
	}
	else {
		subtrahend.sign = 0;
	}
	res = minued + subtrahend;
	return res;
}

Fraction operator-(Fraction &fractionOne, int intValue) {
	Fraction res = fractionOne;
	intValue *= -1;
	res = res + intValue;
	return res;
}

Fraction& Fraction::operator-=(Fraction &fractionOne) {
	*this = *this - fractionOne;
	return *this;

}

Fraction& Fraction::operator-=(int intValue) {
	*this = *this - intValue;
	return *this;

}

Fraction operator*(Fraction &fractionOne, Fraction &fractionTwo) {
	Fraction facientOne = fractionOne;
	Fraction facientTwo = fractionTwo;
	Fraction res;
	facientOne.CommonFraction();
	facientTwo.CommonFraction();
	res.numerator = facientOne.numerator * facientTwo.numerator;
	res.denominator = facientOne.denominator * facientTwo.denominator;

	if (facientOne.sign == facientTwo.sign) {
		res.sign = 1;
	}
	else {
		res.sign = 0;
	}

	res.GetIntNumber();
	res.Cancellation();

	return res;

}

Fraction operator*(Fraction &fractionOne, int intValue) {
	int tempSign;
	if (intValue > 0) {
		tempSign = 1;
	}
	else {
		tempSign = 0;
	}
	intValue = abs(intValue);
	Fraction res = fractionOne;
	res.CommonFraction();

	if ((intValue > 0 && res.sign == 1) || (intValue < 0 && res.sign == 0)) {
		res.sign = 1;
	}
	else {
		res.sign = 0;
	}
	res.numerator *= intValue;
	if (tempSign == 0) {
		if (res.sign == 1) {
			res.sign = 0;
		}
		else {
			res.sign = 1;
		}
	}

	res.GetIntNumber();
	res.Cancellation();

	return res;

}

Fraction& Fraction::operator*=(Fraction &fractionOne) {
	*this = *this * fractionOne;
	return *this;

}

Fraction& Fraction::operator*=(int intValue) {
	*this = *this * intValue;
	return *this;

}

Fraction operator/(Fraction &fractionOne, Fraction &fractionTwo) {

	Fraction dividend = fractionOne;
	dividend.CommonFraction();
	Fraction divider = fractionTwo;
	divider.CommonFraction();
	Fraction res;

	int temp = divider.numerator;
	divider.numerator = divider.denominator;
	divider.denominator = temp;

	res = dividend * divider;

	return res;

}

Fraction operator/(Fraction &fractionOne, int intValue) {
	int tempSign;
	if (intValue > 0) {
		tempSign = 1;
	}
	else {
		tempSign = 0;
	}
	intValue = abs(intValue);
	Fraction res = fractionOne;
	res.CommonFraction();
	res.denominator *= intValue;
	if (tempSign == 0) {
		if (res.sign == 1) {
			res.sign = 0;
		}
		else {
			res.sign = 1;
		}
	}

	res.GetIntNumber();
	res.Cancellation();

	return res;

}

Fraction& Fraction::operator/=(Fraction &fractionOne) {
	*this = *this / fractionOne;
	return *this;

}

Fraction& Fraction::operator/=(int intValue) {
	*this = *this / intValue;
	return *this;

}
double Fraction::ToDouble() {
	double res = intNumber;

	res += (numerator * 1.0) / (denominator * 1.0);

	if (sign == 0) {
		res *= -1;
	}

	return res;

}

Fraction& Fraction::operator++() {
	(*this) += 1;

	return *this;
}


Fraction& Fraction::operator--() {
	(*this) -= 1;

	return (*this);
}

Fraction& Fraction::operator++(int intValue) {
	Fraction temp(*this);

	(*this)+=1;

	return temp;
}


Fraction& Fraction::operator--(int intValue) {
	Fraction temp(*this);

	(*this) -= 1;

	return temp;
}