#include <iostream>
#include "String.h"

int main()
{
	TString str("test");
	TString str4('y', 4);
	TString str1(str);
	TString str2;
	TString str5("stroke");
	TString str6("just drink some juice");
	str4.Print();
	str.Print();
	str1.Print();
	str2 = str + str1;
	str2.Print();
	if (str == str2)
		std::cout << "Compare!" << std::endl;
	else
		std::cout << "NOT Compare!" << std::endl;
	char q;
	q = str1[2];
	std::cout << q << std::endl;
	std::cout << str2;
	str5.FindWord("tr");
	str.FindLetter('s');
	str5.Duplication(3);
	TString* p = 0;
	int size = 0;
	str6.Split(p, size, ' ');
	for (int i = 0; i < size; i++)
		std::cout << p[i] << '\t';
	//char** d = str6.Split(' ');
	//for (int i = 0; i<100; i++)
	//  std::cout << d[i] << std::endl;

	return 0;
}