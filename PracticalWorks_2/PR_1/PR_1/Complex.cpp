#include "Complex.h"

using namespace std;

Complex::Complex(const double& real, const double& image, const bool& isAllSignsVisible)
{
	_real = real;
	_image = image;
	_isAllSignsVisible = isAllSignsVisible;
}
Complex::Complex(const Complex& a)
{
	_real = a._real;
	_image = a._image;
	_isAllSignsVisible = a._isAllSignsVisible;
}

ostream& operator << (ostream& stream, const Complex& a)
{
	double x = a._real, y = a._image;
	if (y == 0)
		return stream << x;
	else if (x == 0)
	{
		if (a._isAllSignsVisible)
			stream << y;
		else if (y == -1)
			stream << "-";
		else if (y != 1)
			stream << y;
	}
	else
	{
		double absY = abs(y);
		stream << x << (y < 0 ? " - " : " + ");
		if (absY != 1 || a._isAllSignsVisible)
			stream << absY;
	}
	return stream << (a._isAllSignsVisible ? " * i" : "i");
}
istream& operator >> (istream& stream, Complex a)
{
	stream >> a._real;
	stream >> a._image;
	return stream;
}

Complex operator + (const double& a, const Complex& b)
{
	return Complex
	(
		a + b._real,
		b._image
	);
}
Complex operator + (const Complex& a, const double &b)
{
	return b + a;
}
Complex operator + (const Complex& a, const Complex& b)
{
	return Complex
	(
		a._real + b._real,
		a._image + b._image
	);
}

Complex operator * (const double& a, const Complex& b)
{
	return Complex
	(
		a * b._real,
		a * b._image
	);
}
Complex operator * (const Complex& a, const double& b)
{
	return b * a;
}
Complex operator * (const Complex& a, const Complex& b)
{
	return Complex
	(
		a._real * a._real - b._image * b._image,
		a._real * b._image + a._image * a._real
	);
}

Complex Complex::operator -= (const double& a)
{
	_real -= a;
	return *this;
}
Complex Complex::operator -= (const Complex& a)
{
	_real -= a._real;
	_image -= a._image;
	return *this;
}
 
Complex operator / (const double& a, const Complex& b)
{
	double x2 = b._real, y2 = b._image;
	double d = x2 * x2 + y2 * y2;
	return Complex
	(
		(a * x2) / d,
		(-a * y2) / d
	);
}
Complex operator / (const Complex& a, const double& b)
{
	return a * (1 / b);
}
Complex operator / (const Complex& a, const Complex& b)
{
	double x1 = a._real, y1 = a._image;
	double x2 = b._real, y2 = b._image;
	double d = x2 * x2 + y2 * y2;
	return Complex
	(
		(x1 * x2 + y1 * y2) / d,
		(y1 * x2 - x1 * y2) / d
	);
}

bool operator >= (const Complex& a, const Complex& b)
{
	return a._real >= b._real && a._image >= b._image;
}

double Complex::GetReal()
{
	return _real;
}
double Complex::GetImage()
{
	return _image;
}
bool Complex::GetIsAllSignsVisible()
{
	return _isAllSignsVisible;
}

void Complex::SetIsAllSignsVisible(const bool& isAllSignsVisible)
{
	_isAllSignsVisible = isAllSignsVisible;
}

Complex Complex::Pow(int degree)
{
	if (degree == 0)
	{
		_real = 1;
		_image = 0;
	}
	else
	{
		Complex res(1);
		for (int i = 0, count = abs(degree); i < count; i++)
			res = res * *this;
		if (degree < 0)
		{
			res = 1 / res;
		}
		_real = res._real;
		_image = res._image;
	}
	return *this;
}
