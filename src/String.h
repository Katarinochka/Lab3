#pragma once
#include<iostream>

int strlen(char* str);
class TString
{
public:
	TString();
	TString(char h, int l);
	TString(int _lenght);
	TString(char* tmp);
	TString(const TString& tmp);
	~TString();
	void Print();
	TString& operator=(const TString& tmp);
	TString operator+(const TString& tmp);
	bool operator==(const TString& tmp);
	bool operator<(const TString& tmp);
	bool operator>(const TString& tmp);
	char operator[](int a);
	friend std::ostream& operator<<(std::ostream& out, const TString& tmp);
	friend std::istream& operator>>(std::istream& input, TString& tmp);
	int FindWord(char* s); //����� ����
	int FindLetter(char s);  // ����� �������
	void Split(TString*& p, int& counter, char c);
	//char** Division(char c); // ���������
	TString Duplication(int k); // ���
protected:
	char* str;
};

