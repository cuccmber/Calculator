#pragma once
#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction {

	bool sign;
	int intNumber;
	int numerator;
	int denominator;



public:

	Fraction(bool sig = 1, int integer = 0, int num = 0, int den = 1);


	int GetGCF(int a, int b);  //greatest common factor
	int GetLCM(int a, int b);  //least common multiple
	
	void GetIntNumber();
	void Cancellation();
	void CommonFraction();
	friend Fraction ToCommonDenominator(Fraction &fractionOne, Fraction &fractionTwo);
	friend Fraction IntToFraction(Fraction &fractionOne, int intValue);

	friend Fraction operator+(Fraction &fractionOne, Fraction &fractionTwo);
	friend Fraction operator+(Fraction &fractionOne, int intValue);
	Fraction& operator+=(Fraction &fractionOne);
	Fraction& operator+=(int intValue);

	friend Fraction operator-(Fraction &fractionOne, Fraction &fractionTwo);
	friend Fraction operator-(Fraction &fractionOne, int intValue);
	Fraction& operator-=(Fraction &fractionOne);
	Fraction& operator-=(int intValue);

	friend Fraction operator*(Fraction &fractionOne, Fraction &fractionTwo);
	friend Fraction operator*(Fraction &fractionOne, int intValue);
	Fraction& operator*=(Fraction &fractionOne);
	Fraction& operator*=(int intValue);

	friend Fraction operator/(Fraction &fractionOne, Fraction &fractionTwo);
	friend Fraction operator/(Fraction &fractionOne, int intValue);
	Fraction& operator/=(Fraction &fractionOne);
	Fraction& operator/=(int intValue);

	friend bool operator>(Fraction &fractionOne, Fraction &fractionTwo);
	friend bool operator>(Fraction &fractionOne, int intValue);
	friend bool operator<(Fraction &fractionOne, Fraction &fractionTwo);
	friend bool operator<(Fraction &fractionOne, int intValue);
	friend bool operator==(Fraction &fractionOne, Fraction &fractionTwo);
	friend bool operator==(Fraction &fractionOne, int intValue);
	friend bool operator>=(Fraction &fractionOne, Fraction &fractionTwo);
	friend bool operator>=(Fraction &fractionOne, int intValue);
	friend bool operator<=(Fraction &fractionOne, Fraction &fractionTwo);
	friend bool operator<=(Fraction &fractionOne, int intValue);


	Fraction& operator++();  //preincrement
	Fraction& operator--();  //predecrement
	Fraction& operator++(int intvalue);  //postincrement
	Fraction& operator--(int intValue);  //postdecrement

	double ToDouble();

	friend void PrintFraction(Fraction &result, std::string exp);





	void print();

};

#endif FRACTION_H