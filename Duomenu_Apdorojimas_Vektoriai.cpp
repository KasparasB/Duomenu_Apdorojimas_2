#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <random>
#include <vector>

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

int main()
{
	int n = 0;
	cout << "Kiek bus mokiniu: ";
	cin >> n;

	vector<Universitetas> Studentas(n);	//Universitetas* Studentas = new Universitetas[n];


	bool Med_Vid = false;
	cout << "Skaiciuoti pagal mediana ar vidurki? (1 - Mediana, 0 - Vidurkis)" << endl;
	cin >> Med_Vid;

	int Egzaminas = 0;
	int tmp = 0; //Pazymys
	int e = 0;

	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<> Skaicius(1, 10);
	std::uniform_int_distribution<> pazym_sk(3, 10); // naudojamas pazymiu skaiciui sugeneruot

	for (int i = 0; i < n; i++)
	{
		cout << "Iveskite " << i + 1 << "-ojo mokinio varda: ";
		cin >> Studentas[i].Vardas;          //(Studentas + i)->Vardas;

		cout << "Iveskite " << i + 1 << "-ojo mokinio pavarde: ";
		cin >> Studentas[i].Pavarde; // (Studentas + i)->Pavarde;

		e = 0;
		Studentas[i].Pazymiu_Skaicius = pazym_sk(gen); // Sugeneruoja pazymiu skaiciu (3-10)

		Studentas[i].Pazymiai.reserve(Studentas[i].Pazymiu_Skaicius); // paskiriam vieta pazymiams
		do
		{
			tmp = Skaicius(gen);
			Studentas[i].Pazymiai.push_back(tmp);
			e++;
			/*
			int* tmp1 = new int[e + 1];
			for (int k = 0; k < e; k++) tmp1[k] = Studentas[i].Pazymiai[k];
			e++;
			delete[](Studentas + i)->Pazymiai;
			(Studentas + i)->Pazymiai = tmp1;
			(Studentas + i)->Pazymiai[e - 1] = tmp;
			*/
		} while (e != Studentas[i].Pazymiu_Skaicius);
		sort(Studentas[i].Pazymiai.begin(), Studentas[i].Pazymiai.end()); // Surikiuojam pazymius

		Studentas[i].Egzaminas = Skaicius(gen); // Sugeneruojam random egzamino pazymi



		if (Med_Vid)// Mediana
		{

			if (e % 2 == 0) //Tikrinam ar lyginis skaicius elementu ar ne
			{
				Studentas[i].Galutinis = ((double)Studentas[i].Pazymiai[e / 2] + Studentas[i].Pazymiai[(e / 2) - 1]) / 2;
			}
			else
			{
				Studentas[i].Galutinis = Studentas[i].Pazymiai[e / 2];
			}
		}
		else //Vidurkis
		{
			for (int x = 0; x < e; x++)
				Studentas[i].Galutinis += Studentas[i].Pazymiai[x];

			Studentas[i].Galutinis = Studentas[i].Galutinis / e;
		}

		Studentas[i].Galutinis = Studentas[i].Galutinis * 0.4 + 0.6 * Studentas[i].Egzaminas;

	}

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

	system("PAUSE");
}
