#include <iostream>

class Complex
{

private:
	double _real;
	double _image;
	bool _isAllSignsVisible;


public:
	Complex(const double& = 0, const double& = 0, const bool& = false);
	Complex(const Complex&);

	friend std::ostream& operator << (std::ostream&, const Complex&);
	friend std::istream& operator >> (std::istream&, Complex);

	friend Complex operator + (const double&, const Complex&);
	friend Complex operator + (const Complex&, const double&);
	friend Complex operator + (const Complex&, const Complex&);

	Complex operator -= (const double&);
    Complex operator -= (const Complex&);

	friend Complex operator * (const double&, const Complex&);
	friend Complex operator * (const Complex&, const double&);
	friend Complex operator * (const Complex&, const Complex&);

	friend Complex operator / (const double&, const Complex&);
	friend Complex operator / (const Complex&, const double&);
	friend Complex operator / (const Complex&, const Complex&);

	friend bool operator >= (const Complex&, const Complex&);

	double GetReal();
	double GetImage();
	bool GetIsAllSignsVisible();

	void SetIsAllSignsVisible(const bool&);

	Complex Pow(int);
};