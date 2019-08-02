#include "pch.h"
#include "Convertidor.h"
#include <iostream>

Convertidor::Convertidor()
{
}

Convertidor::~Convertidor()
{
}

string Convertidor::aBinario(unsigned long numerofibonacci)
{
	string numeroconvertido;
	unsigned long dividendo;
	unsigned long resto;
	int divisor = 2;

	dividendo = numerofibonacci;
	while (dividendo >= divisor) {
		resto = dividendo % 2;
		numeroconvertido = binario(resto) + numeroconvertido;
		dividendo = dividendo / divisor;
	}
	numeroconvertido = binario(dividendo) + numeroconvertido;
	return numeroconvertido;
}

string Convertidor::binario(unsigned long resto)
{
	if (resto == 1)
		return "1";
	return "0";
}

string Convertidor::aHexadecimal(unsigned long numerofibonacci)
{
	unsigned long dec_num, r;
	string numeroconvertido = "";
	char hex[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };

	while (numerofibonacci > 0)
	{
		r = numerofibonacci % 16;
		numeroconvertido = hex[r] + numeroconvertido;
		numerofibonacci = numerofibonacci / 16;
	}

	return numeroconvertido;
}