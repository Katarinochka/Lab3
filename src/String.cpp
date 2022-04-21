#include "String.h"
#include <iostream>

int strlen(char* str) {
	if (str == 0)
		return -1;
	int i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}

TString::TString()
{
	str = nullptr;
}

TString::TString(char h, int l)
{
	str = new char[l + 1];
	for (int i = 0; i < l; i++)
		str[i] = h;
	str[l] = '\0';
}

TString::TString(int _lenght) {
	int lenght;
	if (_lenght > 0)
		lenght = _lenght;
	else
		throw "lenght < 1";
	str = new char[lenght + 1];
	for (int i = 0; i < lenght; i++) {
		str[i] = ' ';
	}
	str[lenght] = '\0';
}

TString::TString(char* tmp)
{
	int len;
	len = strlen(tmp);
	str = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		str[i] = tmp[i];
	}
	str[len] = '\0';

}

TString::TString(const TString& tmp)
{
	int len;
	len = strlen(tmp.str);
	str = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		this->str[i] = tmp.str[i];
	}
	this->str[len] = '\0';
}

TString::~TString()
{
	delete[] this->str;
}

void TString::Print()
{
	std::cout << this->str << std::endl;
}

TString& TString::operator=(const TString& tmp)
{
	if (this->str != nullptr)
		delete[] this->str;
	int len;
	len = strlen(tmp.str);
	str = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		this->str[i] = tmp.str[i];
	}
	this->str[len] = '\0';
	return *this;
}

TString TString::operator+(const TString& tmp)
{
	TString result;
	int initlen, addlen, len, i = 0;
	initlen = strlen(this->str);
	addlen = strlen(tmp.str);
	len = initlen + addlen;
	result.str = new char[len + 1];
	for (i; i < initlen; i++)
	{
		result.str[i] = this->str[i];
	}
	for (int j = 0; j < addlen; j++, i++)
	{
		result.str[i] = tmp.str[j];
	}
	result.str[len] = '\0';
	return result;
}

bool TString::operator==(const TString& tmp)
{
	int initlen, addlen;
	initlen = strlen(this->str);
	addlen = strlen(tmp.str);
	if (initlen = addlen)
		for (int i = 0; i < addlen; i++)
			if (this->str[i] != tmp.str[i])
				return false;
	return true;
}

bool TString::operator<(const TString& tmp)
{
	int initlen, addlen;
	initlen = strlen(this->str);
	addlen = strlen(tmp.str);
	if (initlen < addlen)
		return true;
	return false;
}

bool TString::operator>(const TString& tmp)
{
	int initlen, addlen;
	initlen = strlen(this->str);
	addlen = strlen(tmp.str);
	if (initlen > addlen)
		return true;
	return false;
}

char TString::operator[](int a)
{
	int len;
	char q;
	len = strlen(this->str);
	if (a < len)
		q = this->str[a];
	return q;
}

int TString::FindWord(char* s)
{
	int f = 0;
	if (s == 0)
		throw"Error - empty word";
	int len = strlen(this->str);
	for (int i = 0; i < len; i++)
	{
		if (this->str[i] == s[0])
		{
			for (int j = 0; j < len; j++)
				if (this->str[i + j] == s[j])
					f = i;
		}
	}
	std::cout << f << std::endl;
	return f;
}

int TString::FindLetter(char s)
{
	int f = 0;
	int len = strlen(this->str);
	for (int i = 0; i < len; i++)
		if (this->str[i] == s)
		{
			f = i + 1;
			std::cout << f << std::endl;
			break;
		}
	if (f == 0)
		std::cout << "Haven't this letter in string " << std::endl;
	return f;
}

void TString::Split(TString*& p, int& counter, char c) {
	if (p != 0) {
		delete[] p;
		p = 0;
	}
	int lenght = strlen(str);
	int count = 0, pointer = 0, k, e;
	char* v = 0;
	for (int i = 0; i < lenght; i++) {
		if (str[i] == c)
			count++;
	}

	if (count == 0) {
		p = new TString(*this);
	}
	p = new TString[count + 1];
	counter = count + 1;
	std::cout << counter << std::endl;
	for (int i = 0; i < counter; i++) {
		k = pointer;
		while (str[pointer] != c && str[pointer] != '\0')
		{
			pointer++;
			std::cout << pointer << std::endl;
		}


		//p[i]
		v = new char[pointer - k + 1];
		e = 0;
		for (int j = k; j < pointer; j++) {
			v[e] = str[j];
			e++;
		}
		v[pointer - k] = '\0';
		//std:: cout<< v << '\n';
		p[i] = v;
		if (v != 0) {
			delete[] v;
			v = 0;
		}
		pointer++;

	}
}

TString TString::Duplication(int k)
{
	TString result;
	int len = strlen(this->str);
	int lenres = k * len;
	result = new char[lenres];
	int i = 0;
	for (i; i < k; i++)
	{
		for (int j = 0; j < len; j++)
			result.str[i * len + j] = this->str[j];
	}
	result.str[lenres] = '\0';
	result.Print();
	return result;
}

std::ostream& operator<<(std::ostream& out, const TString& tmp)
{
	if (tmp.str != nullptr)
		out << "string = " << tmp.str << std::endl;
	return out;
}

std::istream& operator>>(std::istream& input, TString& tmp)
{
	input >> tmp.str;
	return input;
}
