#pragma once
#include <string>
using namespace std;
class Convertidor
{
public:
	Convertidor();
	~Convertidor();
	string aBinario(unsigned long);
	string binario(unsigned long);
	string aHexadecimal(unsigned long);
};

