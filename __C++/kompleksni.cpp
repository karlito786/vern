#include "kompleksni.h"

// funkcije (metode) razreda:
void Kompleksni::ispis()
{	cout << Re;
	if (Im >= 0)	// dodajemo plus za pozitivni Im
		cout << "+";
	cout << Im << "i" << endl;
}
void Kompleksni::unos()
{
	char znak;	// pomocna varijabla za slovo i
	cin >> Re >> Im >> znak;
}
void Kompleksni::zbroj(Kompleksni prvi, Kompleksni drugi)
{
	// Re, Im - podaci objekta nad kojim je funkcija pozvana
	// (c = a + b, "self")
	// prvi.Re - podaci objekta "prvi"
	Re = prvi.Re + drugi.Re;
	Im = prvi.Im + drugi.Im;
}
void Kompleksni::razlika(Kompleksni prvi, Kompleksni drugi)
{
	Re = prvi.Re - drugi.Re;
	Im = prvi.Im - drugi.Im;
}
double Kompleksni::modul()
{
	return sqrt(Re * Re + Im * Im);
}
Kompleksni Kompleksni::konjugirani()
{
	Kompleksni rez;	// novi kompl broj, pomocna varijabla
	rez.Re = Re;	// jednako nasoj realnoj komp.
	rez.Im = -Im;	// a imaginarna invertirana
	return rez;
}
bool Kompleksni::jednak(Kompleksni drugi)
{
	if(Re = drugi.Re && Im == drugi.Im)
		return true;
	return false;
}
// nadgradjeni operatori:
Kompleksni Kompleksni::operator+(Kompleksni desni)
{
	Kompleksni rez;	// novi objekt za rezultat
	rez.Re = Re + desni.Re;
	rez.Im = Im + desni.Im;
	return rez;
}
Kompleksni Kompleksni::operator-(const Kompleksni& desni)
{
	Kompleksni rez;
	//rez.Re = Re - desni.Re;
	//rez.Im = Im - desni.Im;
	// ili iskoristimo postojecu funkciju:
	rez.razlika(*this, desni);
	return rez;
}
// unarni operator ! za modul:
double Kompleksni::operator~()
{	return sqrt(Re* Re + Im * Im);	}
Kompleksni Kompleksni::operator!()
{
	Kompleksni novi;
	novi.Re = Re;
	novi.Im = -Im;
	return novi;
}
bool Kompleksni::operator==(Kompleksni desni)
{
	if (Re == desni.Re && Im == desni.Im)
		return true;
	return false;
}


// nadgradjeni operator ispisa:
ostream& operator<<(ostream& tok, Kompleksni& k)
{
	tok << k.Re;
	if (k.Im >= 0)	// dodajemo plus za pozitivni Im
		tok << "+";
	tok << k.Im << "i";
	return tok;
}
// operator unosa:
istream& operator>>(istream& tok, Kompleksni& k)
{
	char znak;
	tok >> k.Re >> k.Im >> znak;
	return tok;
}


