#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <random>
#include <vector>
#include <ctype.h>
#include <cctype>


using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::setw;
using std::left;
using std::sort;
using std::max;
using std::right;
using std::setprecision;
using std::fixed;
using std::vector;


struct Universitetas {
	string Vardas;
	string Pavarde;
	vector<int> Pazymiai;                    //int* Pazymiai = new int[1];
	int Egzaminas;
	double Galutinis;
	int Pazymiu_Skaicius;
};

void Ilgiausias(vector<Universitetas> A, int n, int &Vardas, int &Pavarde) // Funkcija ilgiausiam vardui ar pavardei rasti
{
	int MAX_V = 0;
	int MAX_PV = 0;
	int ilgis1 = 0;
	int ilgis2 = 0;
	for (int i = 0; i < n; i++)
	{
		ilgis1 = A[i].Vardas.length();
		MAX_V = max(ilgis1, MAX_V);

		ilgis2 = A[i].Pavarde.length();
		MAX_PV = max(ilgis2, MAX_PV);
	}
	Vardas = MAX_V;
	Pavarde = MAX_PV;
}


void Ivedimas(int &n, int Med_Vid)
{
	cout << "Kiek bus mokiniu: ";
	cin >> n;

	while (cin.fail()) //Prasoma skaiciaus
	{
		std::cin.clear();
		std::cin.ignore(256, '\n');
		cout << "Klaida ivedant duomenis. Iveskite SKAICIU! " << endl;
		cin >> n;
	}


	cout << "Skaiciuoti pagal mediana ar vidurki? (1 - Mediana, 0 - Vidurkis)" << endl;
	cin >> Med_Vid;

	while (cin.fail() || (Med_Vid<0 || Med_Vid>1)) //Prasoma skaiciaus
	{
		std::cin.clear();
		std::cin.ignore(256, '\n');
		cout << "Klaida ivedant duomenis. Iveskite 1 ARBA 0! " << endl;
		cin >> Med_Vid;
	}

}

double Mediana(vector<Universitetas> A, int e, int i)
{
    int med = 0;
	if (e % 2 == 0) //Tikrinam ar lyginis skaicius elementu ar ne
	{
		med = ((double)A[i].Pazymiai[e / 2] + A[i].Pazymiai[(e / 2) - 1]) / 2;
	}
	else
	{
		med = (double)A[i].Pazymiai[e / 2];
	}

	return med;
}


double Vidurkis(vector<Universitetas> A, int e, int i)
{
    int vid = 0;
	for (int x = 0; x < e; x++)
		vid += A[i].Pazymiai[x];

	vid = vid / e;

	return vid;
}

bool is_alpha(const std::string &str)
{
	return std::all_of(str.begin(), str.end(), ::isalpha);
}

void VardasPavarde(vector<Universitetas> &A, int i)
{
	cout << "Iveskite " << i + 1 << "-ojo mokinio varda: ";
	cin >> A[i].Vardas;          //(Studentas + i)->Vardas;

	while (!(is_alpha(A[i].Vardas))) //Prasoma stringo
	{
		std::cin.clear();
		std::cin.ignore(256, '\n');
		cout << "Klaida ivedant duomenis. Iveskite varda!" << endl;
		cin >> A[i].Vardas;
	}


	cout << "Iveskite " << i + 1 << "-ojo mokinio pavarde: ";
	cin >> A[i].Pavarde; // (Studentas + i)->Pavarde;

	while (!(is_alpha(A[i].Pavarde))) //Prasoma stringo
	{
		std::cin.clear();
		std::cin.ignore(256, '\n');
		cout << "Klaida ivedant duomenis. Iveskite pavarde!" << endl;
		cin >> A[i].Pavarde;
	}
}

void PazymiuGeneravimas(vector<Universitetas> &Studentas, int i)
{
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<> Skaicius(1, 10);
	std::uniform_int_distribution<> pazym_sk(3, 10); // naudojamas pazymiu skaiciui sugeneruot

	int tmp = 0;
	int e = 0;
	Studentas[i].Pazymiu_Skaicius = pazym_sk(gen); // Sugeneruoja pazymiu skaiciu (3-10)

	Studentas[i].Pazymiai.reserve(Studentas[i].Pazymiu_Skaicius); // paskiriam vieta pazymiams
	do
	{
		tmp = Skaicius(gen);
		Studentas[i].Pazymiai.push_back(tmp);
		e++;

	} while (e != Studentas[i].Pazymiu_Skaicius);
	sort(Studentas[i].Pazymiai.begin(), Studentas[i].Pazymiai.end()); // Surikiuojam pazymius

	Studentas[i].Egzaminas = Skaicius(gen); // Sugeneruojam random egzamino pazymi
}

void Isvedimas(vector<Universitetas> &Studentas, int Med_Vid, int n)
{
	string gal = " "; //Susikuriu stringa, kad galeciau ji naudoti apacioje

	int Ilgiausias_Vardas; //Sukuriami intai, kad pagelbetu teksto lygiavime
	int Ilgiausia_Pavarde;

	Ilgiausias(Studentas, n, Ilgiausias_Vardas, Ilgiausia_Pavarde);

	//Del lygiavimo atlieku siuos pakeitimus
	if (Ilgiausias_Vardas < 6) Ilgiausias_Vardas = 6;
	if (Ilgiausia_Pavarde < 7) Ilgiausia_Pavarde = 7;

	if (Med_Vid) gal = "Galutinis (Med.)";
	else gal = "Galutinis (Vid.)";
	int Ilgis = Ilgiausias_Vardas + Ilgiausia_Pavarde + 19; // Nustatom kiek reikes padeti bruksneliu
	cout << left << setw(Ilgiausias_Vardas) << "Vardas" << left << setw(Ilgiausia_Pavarde) << " Pavarde" << left << "  " << gal << endl;
	for (int i = 0; i < Ilgis; i++) cout << "_";
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		cout << left << setw(Ilgiausias_Vardas) << Studentas[i].Vardas << " " << left << setw(Ilgiausia_Pavarde) << Studentas[i].Pavarde << fixed << setprecision(2) << "  " << Studentas[i].Galutinis << endl;
	}
}

void Generavimas(vector<Universitetas> &Studentas, int Med_Vid, int n)
{
	for (int i = 0; i < n; i++)
	{
		VardasPavarde(Studentas, i);

		PazymiuGeneravimas(Studentas, i);

		if (Med_Vid)// Mediana
			Mediana(Studentas, Studentas[i].Pazymiu_Skaicius, i);
		else //Vidurkis
			Mediana(Studentas, Studentas[i].Pazymiu_Skaicius, i);

		Studentas[i].Galutinis = Studentas[i].Galutinis * 0.4 + 0.6 * Studentas[i].Egzaminas;

	}
}

int main()
{
	int n = 0;
	int Med_Vid = 0;

	Ivedimas(n, Med_Vid);
	vector<Universitetas> Studentas(n);
	Generavimas(Studentas, Med_Vid, n);
	Isvedimas(Studentas, Med_Vid,n);

	system("PAUSE");
}
