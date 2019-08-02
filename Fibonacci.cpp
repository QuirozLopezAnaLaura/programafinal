#include "pch.h"
#include "Fibonacci.h"
#include <iostream>
#include "Convertidor.h"
using namespace std;
Fibonacci::Fibonacci()
{
	numerovecesactualizado = 0;
	valoractual = 0;
	previous = 0;
}
Fibonacci::~Fibonacci()
{
}

void Fibonacci::siguiente()
{
	numerovecesactualizado++;
	if (numerovecesactualizado == 0) {
		valoractual = 0;
	}
	if (numerovecesactualizado == 1) {
		valoractual = 1;
		previous = 0;
	}
	if (numerovecesactualizado >= 2) {
		unsigned long int numbertmp = valoractual + previous;
		previous = valoractual;
		valoractual = numbertmp;
	}
}

void Fibonacci::anterior()
{
	numerovecesactualizado--;
	if (numerovecesactualizado < 0) {
	}
	if (numerovecesactualizado == 0) {
		valoractual = 0;
	}
	if (numerovecesactualizado == 1) {
		valoractual = 1;
		previous = 0;
	}
	if (numerovecesactualizado >= 2) {
		unsigned long int numbertmp = valoractual - previous;
		valoractual = previous;
		previous = numbertmp;
	}
}

unsigned long Fibonacci::getvalor()
{
	return valoractual;
}



