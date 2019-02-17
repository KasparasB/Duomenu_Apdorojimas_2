#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <random>
#include <vector>
#include <ctype.h>
#include <cctype>
#include <fstream>

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

std::ifstream in("kursiokai.txt");
std::ofstream out("rezultatai.txt");


struct Universitetas {
	string Vardas;
	string Pavarde;
	vector<int> Pazymiai;                    
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


void Ivedimas(int &n, int &Med_Vid)
{

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

double Mediana(vector<Universitetas> &A, int e, int i)
{
	double med = 0;
	if (e % 2 == 0) //Tikrinam ar lyginis skaicius elementu ar ne
	{
		med = ((double)A[i].Pazymiai[e / 2] + A[i].Pazymiai[(e / 2) - 1]) / 2;
	}
	else
	{
		med =(double)A[i].Pazymiai[e / 2];
	}

	return med;
}


double Vidurkis(vector<Universitetas> A, int e, int i)
{
	double vid = 0;
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

	while (!(is_alpha(A[i].Vardas))) //Prasoma stringo
	{
		std::cin.clear();
		std::cin.ignore(256, '\n');
		cout << "Klaida tekstiniame faile! Pataisykite mokinio varda" << endl;
		cin >> A[i].Vardas;
	}

	while (!(is_alpha(A[i].Pavarde))) //Prasoma stringo
	{
		std::cin.clear();
		std::cin.ignore(256, '\n');
		cout << "Klaida tekstiniame faile! Pataisykite mokinio pavarde" << endl;
		cin >> A[i].Pavarde;
	}
}

void PazymiuGeneravimas(vector<Universitetas> &Studentas, int i)
{

	sort(Studentas[i].Pazymiai.begin(), Studentas[i].Pazymiai.end()); // Surikiuojam pazymius

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
	out << left << setw(Ilgiausias_Vardas) << "Vardas" << left << setw(Ilgiausia_Pavarde) << " Pavarde" << left << "  " << gal << endl;
	for (int i = 0; i < Ilgis; i++) out << "_";
	out << endl;

	for (int i = 0; i < n; i++)
	{
		out << left << setw(Ilgiausias_Vardas) << Studentas[i].Vardas << " " << left << setw(Ilgiausia_Pavarde) << Studentas[i].Pavarde << fixed << setprecision(2) << "  " << Studentas[i].Galutinis << endl;
	}
}

void Generavimas(vector<Universitetas> &Studentas, int Med_Vid, int i)
{

		VardasPavarde(Studentas, i);

		PazymiuGeneravimas(Studentas, i);

		if (Med_Vid)// Mediana
			Studentas[i].Galutinis = Mediana(Studentas, Studentas[i].Pazymiu_Skaicius, i);
		else //Vidurkis
			Studentas[i].Galutinis = Vidurkis(Studentas, Studentas[i].Pazymiu_Skaicius, i);

		Studentas[i].Galutinis = Studentas[i].Galutinis * 0.4 + 0.6 * Studentas[i].Egzaminas;
		Studentas[i].Pazymiai.erase(Studentas[i].Pazymiai.begin(), Studentas[i].Pazymiai.end() - 1);
}

void Skaitymas(vector<Universitetas> &Studentas, int &n, int Med_Vid)
{
	string duomuo;
	int e = 0;
	int pazymiu_sk = 0;
	while (true) // true  in.peek() != EOF
	{
		do
		{
			in >> duomuo;

			if (duomuo != "Pavarde" && e == 0)
			{
				cout << "Klaidingas duomenu failas" << endl;
				break;
			}
			if (duomuo != "Vardas" && e == 1)
			{
				cout << "Klaidingas duomenu failas" << endl;
				break;
			}
			e++;
		} while (e != 2);

		

		do
		{
			in >> duomuo;
			if (duomuo[0] != 'N' && duomuo[1] != 'D' && duomuo != "Egzaminas")
			{
				cout << "Klaidingas duomenu failas" << endl;
			}
			pazymiu_sk++;
		} while (duomuo != "Egzaminas");
		pazymiu_sk--;
		break;
	}
	
	int tmp;
	int egzaminas;




	while (in.peek() != EOF)
	{
		in >> Studentas[n].Vardas;
		in >> Studentas[n].Pavarde;
		Studentas[n].Pazymiu_Skaicius = pazymiu_sk;
		VardasPavarde(Studentas, n);

		for (int i = 0; i < pazymiu_sk; i++)
		{
			in >> tmp;
			Studentas[n].Pazymiai.push_back(tmp);
		}

		in >> Studentas[n].Egzaminas;
		
		Generavimas(Studentas, Med_Vid, n);
		Studentas.push_back({ Studentas[n].Vardas, Studentas[n].Pavarde, Studentas[n].Pazymiai, Studentas[n].Egzaminas, Studentas[n].Galutinis, Studentas[n].Pazymiu_Skaicius });
		

		n++;
	}

}

int main()
{
	int n = 0;
	int Med_Vid = 0;

	Ivedimas(n, Med_Vid);
	vector<Universitetas> Studentas(1);	
	Skaitymas(Studentas, n, Med_Vid);
	Isvedimas(Studentas, Med_Vid,n);

	system("PAUSE");
}
