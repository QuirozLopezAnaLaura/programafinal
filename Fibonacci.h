#pragma once
class Fibonacci
{
private:
	unsigned long valoractual;
	unsigned long previous;
	unsigned long numerovecesactualizado;
public:
	Fibonacci();
	~Fibonacci();
	void siguiente();
	void anterior();
	unsigned long getvalor();
};

