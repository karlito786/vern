// razred Skup sa statickom memorijom
// 5.4.: dodano korisnicko sucelje
// 12.4.: nadgradjeni operatori
// 10.5.: operatori ispisa i unosa
#include<iostream>
using namespace std;

#include "kompleksni.h"

const int MAX = 100;	// max velicina skupa (velicina niza)
//typedef int Podatak;	// Podatak je drugo ime za int 
// (a kasnije moze biti bilo koji drugi tip)
#include<string>
//typedef string Podatak;
typedef Kompleksni Podatak;	// !

class Skup
{
private:
	Podatak elementi[MAX];	// elementi skupa u nizu
	int broj;	// trenutni broj elemenata
public:
	Skup()	// inicijalizacija praznog skupa
	{
		broj = 0;
	}
	// vraca redni broj elm-a ako ga nadje (1, 2, ...), inace 0
	int clan(Podatak elm)
	{
		for (int i = 0; i < broj; i++)	// za sve elemente
			if (elementi[i] == elm)	// ako je i-ti jednak elm
				return i + 1;		// vrati redni broj
		return 0;	// ako ga nema, vrati 0
	}
	// dodaje novi element uz provjeru postoji li vec
	// vraca novi broj elemenata ili 0
	int dodaj(Podatak novi)
	{
		if (clan(novi))	// ima li ga vec?
			return 0;
		elementi[broj] = novi;	// novi na prvo slobodno mjesto!
		broj++;	// povecaj broj
		return broj;
	}
	void ispis()
	{
		cout << "{ ";
		for (int i = 0; i < broj; i++)
			cout << elementi[i] << " ";
		cout << "}" << endl;
	}
	int obrisi(Podatak elm)
	{
		int rbr = clan(elm);	// redni broj onoga za brisanje
		if (rbr == 0)		// ako ga nema, onda nista
			return 0;
		// za svaki element IZA obrisanoga:
		for (int i = rbr; i < broj; i++)
			elementi[i - 1] = elementi[i];	// premjesti "ulijevo"
		broj--;
		return broj;
	}
	void unija(Skup prvi, Skup drugi)
	{
		//broj = 0;	// 'brisanje' postojecih
		//for (int i = 0; i < prvi.broj; i++) // sve elemente skupa prvi
		//	dodaj(prvi.elementi[i]);	// dodamo ih sebi

		// mi jednaki skupu prvi:
		*this = prvi;
		// pokazivac this pokazuje na objekt unutar kojega se 
		// nalazimo (nas)
		this->broj; // isto kao samo "broj"

		for (int i = 0; i < drugi.broj; i++) // isto za skup drugi!
			this->dodaj(drugi.elementi[i]);	// uz this->
	}
	// nadgradjeni operatori:
	int operator+=(Podatak novi)
	{	// samo pozovemo postojecu funkciju:
		return dodaj(novi);
	}
	void operator-=(Podatak nesretnik)
	{
		obrisi(nesretnik);
	}
	Skup operator+(Skup desni)
	{
		Skup rez;
		rez.unija(*this, desni);
		return rez;
	}
	bool operator==(Skup drugi)
	{	// jednaki ako imamo isti broj elemenata
		// i ako je svaki moj element clan drugog
		if (broj != drugi.broj)	// ako nisu jednaki, nista
			return false;
		for (int i = 0; i < broj; i++)
			if (!drugi.clan(elementi[i]))
				return false;
		return true;	// ovdje znamo da su jednaki
	}
	// operator indeksiranja:
	Podatak operator[](int indeks)
	{
		// TODO: provjeriti je li indeks dobar!
		if (indeks < 0 || indeks >= broj) {
			cout << "ne valja indeks!" << endl;
			exit(1);
		}
		return elementi[indeks];	// vracamo trazeni element
	}
	// operator ispisa proglasimo prijateljem razreda:
	friend ostream& operator<<(ostream& tok, Skup& S);
};

// nadgradjeni operator ispisa:
ostream& operator<<(ostream& tok, Skup& S)
{
	tok << "{ ";
	for (int i = 0; i < S.broj; i++)
		tok << S.elementi[i] << " ";
	tok << "}";
	return tok;
}

// glavni program sa "suceljem"
int main()
{
	Skup S;
	while (1) {
		S.ispis();	// ispis na pocetku
		cout << "1 - dodaj, 2 - brisi, 3 - reset: ";
		int izbor; cin >> izbor;
		switch (izbor) {
		case 1: { // dodavanje
			Podatak novi;
			cout << "unesi novi podatak: ";
			cin >> novi;
			S.dodaj(novi);
			break;	// obvezatno!
		}
		case 2: { // brisanje
			Podatak nesretnik;
			cout << "koji odlazi: ";
			cin >> nesretnik;
			S.obrisi(nesretnik);
			break;
		}
		case 3: {
			Skup prazni;
			S = prazni;
			break;
		}
		default: // ako nijedan nije prepoznat
			cout << "nije implementirano!" << endl;
		} // switch
	} // while
	return 0;
}

/*
int main()
{
	Skup S;
	S += 4; S += 5; S += 2; S += 7; S += 3;
	cout << "S: " << S << endl;
	cout << "kojeg oces da obrisem: ";
	Podatak nesretnik; cin >> nesretnik;
	if (!S.clan(nesretnik))
		cout << "nema takvoga!" << endl;
	S -= nesretnik; // S.obrisi(nesretnik);
	cout << S << endl;
	Skup S2;
	S2 += 2; S2 += 5; S2 += 4; S2 += 7; S2 += 3;
	cout << "S2: " << S2 << endl;
	Skup R;
	R = S + S2; // R.unija(S, S2);
	cout << "unija: " << R << endl;

	if (S == S2)	// jednakost skupova S.operator==(S2)
		cout << "jednaki!" << endl;
	else
		cout << "nisu jednaki!" << endl;

	cout << "kojeg oces ispisati: ";
	int indeks; cin >> indeks;
	// poziv operatora indeksiranja:
	cout << "evo ga: " << S[indeks] << endl;

	return 0;
}
*/