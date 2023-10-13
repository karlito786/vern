#pragma once
// primjer razreda Kompleksni
// 29.3.: dodani konstruktori
// 12.4.: dodani nadgradjeni operatori
// 10.5.: dodani operatori unosa i ispisa
#include<iostream>
using namespace std;

// definicija razreda:
class Kompleksni
{
public:
	// podaci razreda:
	double Re, Im;	// realni i imaginarni dio
	// funkcije (metode) razreda:
	void ispis();
	void unos();
	void zbroj(Kompleksni prvi, Kompleksni drugi);
	void razlika(Kompleksni prvi, Kompleksni drugi);
	double modul();
	Kompleksni konjugirani();
	bool jednak(Kompleksni drugi);
	// konstruktor 3 u 1:
	Kompleksni(double _Re = 0, double _Im = 0)
	{
		Re = _Re;
		Im = _Im;
	}
	// nadgradjeni operatori:
	Kompleksni operator+(Kompleksni desni);
	Kompleksni operator-(const Kompleksni& desni);
	// unarni operator ! za modul:
	double operator~();
	Kompleksni operator!();
	bool operator==(Kompleksni desni);
};	// obvezatno ; na kraju!

// nadgradjeni operator ispisa:
ostream& operator<<(ostream& tok, Kompleksni& k);
// operator unosa:
istream& operator>>(istream& tok, Kompleksni& k);
