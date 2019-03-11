#include "Header.h"

std::ifstream in;
std::ofstream out;

void DuomenuKurimas()
{
	int n = 100;
	int Skaicius2 = 0;
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 mt(rd());
	std::uniform_real_distribution<> Skaicius(1, 11);

	//std::uniform_int_distribution<> Pazymiams(2, 10);

	for (int i = 0; i < 5; i++)
	{
		auto start = std::chrono::system_clock::now();

		out.open("kursiokai" + std::to_string(i) + ".txt");

		out << "Pavarde Vardas ";
		for (int y = 0; y < 7; y++)
		{
			out << "ND" + std::to_string(y + 1) << " ";
		}
		out << "Egzaminas" << endl;
		for (int y = 0; y < n; y++)
		{
			out << "Pavarde" + std::to_string(y + 1) << " " << "Vardas" + std::to_string(y + 1) << " ";
			for (int y = 0; y < 8; y++)
			{
				Skaicius2 = Skaicius(mt);
				out << " " << Skaicius2;
			}
			out << endl;
		}

		n *= 10;
		auto end = std::chrono::system_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start) * 0.001;
		std::cout << "Kurimas: " << setprecision(4) << elapsed.count() << '\n';
		out.close();
	}

}

void Skaitymas(list<Universitetas>& Studentas, int & n, int Med_Vid, int TekstinioFailoNr)
{
	auto start = std::chrono::system_clock::now();

	string duomuo;
	int e = 0;
	int pazymiu_sk = 0;

	std::ifstream in("kursiokai" + std::to_string(TekstinioFailoNr) + ".txt");

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

	in.ignore(80, '\n');

	string tmp;
	string s1;

	string Vardas;
	string Pavarde;
	int PazymiuSk;
	list<double>Pazymiai;
	double Egzaminas;
	double Galutinis;

	while (in.peek() != EOF)
	{
		getline(in, s1);
		std::istringstream eil(s1);

		eil >> Vardas;
		eil >> Pavarde;


		//VardasPavarde(Studentas, n);
		for (int e = 0; eil.peek() != EOF; e++)
		{
			eil >> tmp;

			if (std::stoi(tmp) >= 0 && std::stoi(tmp) <= 10)
			{
				Pazymiai.push_back(std::stoi(tmp));
			}
			else
			{
				cout << "Klaida duomenu faile. Mokinio pazymys yra raide!" << endl;
				std::exit;
				break;
			}
			PazymiuSk = e;
		}

		if (PazymiuSk == 1) cout << "Mokinys turi tik viena pazymi ir del to jo vidurkis nebus skaicuojamas" << endl;
		if (PazymiuSk > 0 && PazymiuSk != 1)
		{
			Egzaminas = Pazymiai.back();
			Pazymiai.pop_back();
			Generavimas(Pazymiai, Med_Vid, Galutinis, PazymiuSk, Egzaminas);

			//void Generavimas(vector<int>& Pazymiai, int Med_Vid, double& Galutinis, int& PazymiuSk, int &Egzaminas)
			Studentas.push_back({ Vardas, Pavarde, Pazymiai, Egzaminas, Galutinis, PazymiuSk });
			n++;
		}
		else
		{
			std::exit;
		}


	}


	in.close();
	auto end = std::chrono::system_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start) * 0.001;
	std::cout << "Visi veiksmai: " << setprecision(4) << elapsed.count() << '\n';

}



bool Tikrinimas(int i)
{
	std::ifstream in;
	in.open("kursiokai" + std::to_string(i) + ".txt");

	try
	{
		if (!in) throw "Duomenu failo nera!";
		return true;
	}
	catch (const char* cstr)
	{

		std::cerr << cstr << '\n';
		return false;
	}
	in.close();
}

bool is_alpha(const std::string &str)
{
	return std::all_of(str.begin(), str.end(), ::isalpha);
}

void Ilgiausias(list<Universitetas>& B, int n, int &Vardas, int &Pavarde) // Funkcija ilgiausiam vardui ar pavardei rasti
{
	int MAX_V = 0;
	int MAX_PV = 0;
	int ilgis1 = 0;
	int ilgis2 = 0;
	for (Universitetas A:B)
	{
		ilgis1 = A.Vardas.length();
		MAX_V = max(ilgis1, MAX_V);

		ilgis2 = A.Pavarde.length();
		MAX_PV = max(ilgis2, MAX_PV);
	}
	Vardas = MAX_V;
	Pavarde = MAX_PV;
}

bool Ivedimas()
{
	cout << "Skaiciuoti pagal mediana ar vidurki? (0 - Mediana, 1 - Vidurkis)" << endl;
	string trap;
	getline(cin, trap);
	while (cin.fail() || (trap != "0" && trap != "1")) {
		cout << "Klaida ivedime! Iveskite 0 arba 1." << endl;
		getline(cin, trap);
	}
	if (trap == "0")
	{
		return true;
	}
	else
	{
		return false;
	}

}

double Mediana(list<double> &Pazymiai, int e)
{
	double median = 0;
	auto itr = Pazymiai.begin();

	if (e != 0)
	{
		if (e % 2 == 0) //Tikrinam ar lyginis skaicius elementu ar ne
		{
			for (unsigned int i = 0; i < Pazymiai.size() / 2; i++) {
				itr++;
			}

			median = ((double)*itr + *--itr) / 2;
		}
		else
		{
			for (unsigned int i = 0; i < Pazymiai.size() / 2; i++) {
				itr++;
			}

			median = *itr;
		}
	}

	return median;
}

double Vidurkis(list<double> &Pazymiai, int e)
{
	double vid = 0;

	if (e != 0)
	{
		for (double x : Pazymiai)
			vid += x;

		vid = vid / e;
	}

	return vid;
}

/*
void VardasPavarde(list<Universitetas> &A, int i) // Vartotojas netgi turi galimybe istaisyti neteisinga varda tekstiniame faile :O
{

	while (!(is_alpha(A[i].Vardas))) //Prasoma stringo
	{
		std::cin.clear();
		cout << "Klaida tekstiniame faile! Pataisykite mokinio varda" << endl;
		cin >> A[i].Vardas;
	}

	while (!(is_alpha(A[i].Pavarde))) //Prasoma stringo
	{
		std::cin.clear();
		cout << "Klaida tekstiniame faile! Pataisykite mokinio pavarde" << endl;
		cin >> A[i].Pavarde;
	}
}
*/


bool RikiavimasPagalRaide(Universitetas &stud1, Universitetas& stud2)
{
	if (stud1.Vardas < stud2.Vardas || (stud1.Vardas == stud2.Vardas && stud1.Pavarde < stud2.Pavarde))
		return 1;
	else
		return 0;
}

bool RikiavimasPagalSkaiciu(Universitetas &stud1, Universitetas& stud2)
{
	return stud1.Galutinis > stud2.Galutinis;
}

void geriBlogiMokiniai(list<Universitetas>& Studentas, int n, int Ilgiausias_Vardas, int Ilgiausia_Pavarde, int TekstinioFailoNr)
{
	auto start = std::chrono::system_clock::now();

	std::ofstream out1("AtsiverciantysKnygaMokiniai" + std::to_string(TekstinioFailoNr) + ".txt");
	std::ofstream out2("Nelaimeliai" + std::to_string(TekstinioFailoNr) + ".txt");


	auto slenkstis = Studentas.begin();
	int i = 0;
	for (Universitetas A:Studentas)
	{
		if (A.Galutinis < 5)
		{
			break;
			//out2 << left << setw(Ilgiausias_Vardas) << Studentas[i].Vardas << " " << left << setw(Ilgiausia_Pavarde) << Studentas[i].Pavarde << fixed << setprecision(2) << "  " << Studentas[i].Galutinis << endl;
			//blogi.push_back(Studentas[i]);
		}
		slenkstis++;
	}

	//auto slenkstis1 = Studentas.begin() + slenkstis
	list<Universitetas> geri( Studentas.begin(), slenkstis );
	list<Universitetas> blogi( slenkstis, Studentas.end() );


	for (Universitetas A : geri)
		out1 << left << setw(Ilgiausias_Vardas) << A.Vardas << " " << left << setw(Ilgiausia_Pavarde) << A.Pavarde << fixed << setprecision(2) << "  " << A.Galutinis << endl;

	for (Universitetas A : blogi)
		out2 << left << setw(Ilgiausias_Vardas) << A.Vardas << " " << left << setw(Ilgiausia_Pavarde) << A.Pavarde << fixed << setprecision(2) << "  " << A.Galutinis << endl;

	auto end = std::chrono::system_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start) * 0.001;
	std::cout << "Veiksmai su gerais, blogais mokiniais(isvedimas): " << setprecision(4) << elapsed.count() << '\n';
}

void Isvedimas(list<Universitetas>& Studentas, int Med_Vid, int n, int TekstinioFailoNr)
{
	auto start = std::chrono::system_clock::now();
	std::ofstream out("rezultatas" + std::to_string(TekstinioFailoNr) + ".txt");

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

	Studentas.sort(RikiavimasPagalSkaiciu);

	//sort(Studentas.begin(), Studentas.end(), RikiavimasPagalSkaiciu);

	geriBlogiMokiniai(Studentas, n, Ilgiausias_Vardas, Ilgiausia_Pavarde, TekstinioFailoNr);

	auto end = std::chrono::system_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start) * 0.001;
	std::cout << setprecision(4) << "Isvedimas: " << elapsed.count() << '\n';

	for(Universitetas A:Studentas)                    //for (int i = 0; i < n; i++)
	{
		out << left << setw(Ilgiausias_Vardas) << A.Vardas << " " << left << setw(Ilgiausia_Pavarde) << A.Pavarde << fixed << setprecision(2) << "  " << A.Galutinis << endl;
	}

	out.close();
	Studentas.clear();

	//auto end = std::chrono::system_clock::now();
	//auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start) * 0.001;
	//std::cout << setprecision(4) << "Isvedimas: "<< elapsed.count() << '\n';
}

void Generavimas(list<double>& Pazymiai, int Med_Vid, double & Galutinis, int & PazymiuSk, double & Egzaminas)
{
	if (Med_Vid)// Mediana
	{
		Pazymiai.sort();
		//sort(Pazymiai.begin(), Pazymiai.end());
		Galutinis = Mediana(Pazymiai, PazymiuSk);
	}
	else		//Vidurkis
		Galutinis = Vidurkis(Pazymiai, PazymiuSk);

	Galutinis = Galutinis * 0.4 + 0.6 * Egzaminas;
	Pazymiai.erase(Pazymiai.begin(), Pazymiai.end());

}



