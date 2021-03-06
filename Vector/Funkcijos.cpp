#include "Header.h"

std::ifstream in;
std::ofstream out;

void Stopwatch::Start() {
	start = std::chrono::high_resolution_clock::now();
}

void Stopwatch::End(string action) {
	end = std::chrono::high_resolution_clock::now();
	duration = end - start;
	cout << action <<std::fixed<< std::setprecision(3) << duration.count() << "s" <<endl;
}

void Universitetas::putInfo(string name, string surname, double exam, double score)
{
	m_Name = name;
	m_Surname = surname;
	m_Exam = exam;
	m_Score = score;
}

void Universitetas::putName()
{
	cin >> m_Name;
}

void Universitetas::putSurname()
{
	cin >> m_Surname;
}

string Universitetas::getName()
{
	return m_Name;
}

string Universitetas::getSurname()
{
	return m_Surname;
}

double Universitetas::getExam()
{
	return m_Exam;
}

double Universitetas::getScore()
{
	return m_Score;
}

Universitetas::Universitetas()
{
	m_Exam = 0;
	m_Score = 0;
	m_Name = "";
	m_Surname = "";
}

Universitetas::~Universitetas()
{
}

bool compareLetter(Universitetas &stud1, Universitetas& stud2)
{
	if (stud1.getName() < stud2.getName() || (stud1.getName() == stud2.getName() && stud1.getSurname() < stud2.getSurname()))
		return 1;
	else
		return 0;
}

bool compareNumber(Universitetas &stud1, Universitetas& stud2)
{
	return stud1.getScore() > stud2.getScore();
}

bool compareNameLength(Universitetas &stud1, Universitetas& stud2)
{
	return stud1.getName().length() < stud2.getName().length();
}

bool compareSurnameLength(Universitetas &stud1, Universitetas& stud2)
{
	return stud1.getSurname().length() < stud2.getSurname().length();
}

void createData(int noFiles)
{
	Stopwatch a;
	int n = 100;
	int Skaicius2 = 0;
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 mt(rd());
	std::uniform_real_distribution<> Skaicius(1, 11);


	for (int i = 0; i < noFiles; i++)
	{
		a.Start();

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
		a.End("Duomenu kurimas:");
		out.close();
	}

}

void Read(vector<Universitetas>& Studentas, int & n, int Med_Vid, int TekstinioFailoNr)
{
	Stopwatch a;
	a.Start();

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

	Universitetas Tmp;
	
	string Vardas;
	string Pavarde;
	vector<double>Pazymiai;
	double Egzaminas;
	double Galutinis;

	while (in.peek() != EOF)
	{
		getline(in, s1);
		std::istringstream eil(s1);

		eil >> Vardas;
		eil >> Pavarde;


		//nameCheck(Studentas, n);
		for (int e = 0; eil.peek() != EOF; e++)
		{
			eil >> tmp;
			Pazymiai.reserve(10);
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
		}

		if (Pazymiai.size() == 1) cout << "Mokinys turi tik viena pazymi ir del to jo vidurkis nebus skaicuojamas" << endl;
		if (Pazymiai.size() > 0 && Pazymiai.size() != 1)
		{
			Egzaminas = Pazymiai[Pazymiai.size() - 1];
			Pazymiai.erase(Pazymiai.begin() + Pazymiai.size() - 1);
			calculation(Pazymiai, Med_Vid, Galutinis, Egzaminas);
			Tmp.putInfo(Vardas, Pavarde, Egzaminas, Galutinis);
			Studentas.push_back(Tmp);
			n++;
		}
		else
		{
			std::exit;
		}


	}

	in.close();
	a.End("Visi veiksmai: ");

}



bool checkFile(int i)
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

bool findScore(Universitetas& stud2)
{
	return stud2.getScore() < 5; // pasibandyt su >
}

bool Input()
{
	cin.ignore(80, '\n');
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

double Median(vector<double> &Pazymiai)
{
	double med = 0;
	if (Pazymiai.size() != 0)
	{
		if (Pazymiai.size() % 2 == 0) //Tikrinam ar lyginis skaicius elementu ar ne
		{
			med = ((double)Pazymiai[Pazymiai.size() / 2] + Pazymiai[(Pazymiai.size() / 2) - 1]) / 2;
		}
		else
		{
			med = (double)Pazymiai[Pazymiai.size() / 2];
		}
	}

	return med;
}

double Average(vector<double> &Pazymiai)
{
	double vid = 0;

	if (Pazymiai.size() != 0)
	{
		for (int x = 0; x < Pazymiai.size(); x++)
			vid += Pazymiai[x];

		vid = vid / Pazymiai.size();
	}

	return vid;
}
//PERDARYT SU KLASEM
void nameCheck(vector<Universitetas> &A, int i) // Vartotojas netgi turi galimybe istaisyti neteisinga varda tekstiniame faile :O
{
	while (!(is_alpha(A[i].getName()))) //Prasoma stringo
	{
		std::cin.clear();
		cout << "Klaida tekstiniame faile! Pataisykite mokinio varda" << endl;
		A[i].putName();
	}

	while (!(is_alpha(A[i].getSurname()))) //Prasoma stringo
	{
		std::cin.clear();
		cout << "Klaida tekstiniame faile! Pataisykite mokinio pavarde" << endl;
		A[i].putSurname();
	}
}
// PERDARYT SU KLASEM


void printing(std::ostream& out, vector<Universitetas>& Studentas, int Ilgiausia_Pavarde, int Ilgiausias_Vardas)
{
	for (int i = 0; i < Studentas.size(); i++)
		out << left << setw(Ilgiausias_Vardas) << Studentas[i].getName() << " " << left << setw(Ilgiausia_Pavarde) << Studentas[i].getSurname() << fixed << setprecision(2) << "  " << Studentas[i].getScore() << endl;
}

void geriBlogiMokiniai(vector<Universitetas>& Studentas, int n, int Ilgiausias_Vardas, int Ilgiausia_Pavarde, int TekstinioFailoNr,int Med_Vid)
{
	Stopwatch a;
	a.Start();
	std::ofstream out1("AtsiverciantysKnygaMokiniai" + std::to_string(TekstinioFailoNr) + ".txt");
	std::ofstream out2("Nelaimeliai" + std::to_string(TekstinioFailoNr) + ".txt");

	auto search = std::find_if(Studentas.begin(), Studentas.end(), findScore);

	vector<Universitetas> blogi(search, Studentas.end());
	Studentas.erase(search, Studentas.end());
	Studentas.shrink_to_fit();

	box(out1,Med_Vid,Ilgiausias_Vardas,Ilgiausia_Pavarde);
	box(out2, Med_Vid, Ilgiausias_Vardas, Ilgiausia_Pavarde);

	printing(out1, Studentas, Ilgiausia_Pavarde, Ilgiausias_Vardas);
	printing(out2, blogi, Ilgiausia_Pavarde, Ilgiausias_Vardas);

	blogi.clear();
	blogi.shrink_to_fit();

	a.End("Veiksmai su gerais, blogais mokiniais(isvedimas): ");
}

void box(std::ostream& out, int Med_Vid, int Ilgiausias_Vardas, int Ilgiausia_Pavarde)
{
	//Del lygiavimo atlieku siuos pakeitimus
	if (Ilgiausias_Vardas < 6) Ilgiausias_Vardas = 6;
	if (Ilgiausia_Pavarde < 7) Ilgiausia_Pavarde = 7;

	string gal;
	if (Med_Vid) gal = "Galutinis (Med.)";
	else gal = "Galutinis (Vid.)";
	int Ilgis = Ilgiausias_Vardas + Ilgiausia_Pavarde + 19; // Nustatom kiek reikes padeti bruksneliu
	out << left << setw(Ilgiausias_Vardas) << "Vardas" << left << setw(Ilgiausia_Pavarde) << " Pavarde" << left << "  " << gal << endl;
	for (int i = 0; i < Ilgis; i++) out << "_";
	out << endl;
}

void Isvedimas(vector<Universitetas>& Studentas, int Med_Vid, int n, int TekstinioFailoNr)
{
	Stopwatch a;
	a.Start();

	std::sort(Studentas.begin(), Studentas.end(), compareNumber);

	auto longest_name = std::max_element(Studentas.begin(), Studentas.end(), compareNameLength); // randama kur yra ilgiausias vardas bei pavarde
	auto longest_surname = std::max_element(Studentas.begin(), Studentas.end(), compareSurnameLength);

	int Ilgiausias_Vardas = longest_name->getName().length();  
	int Ilgiausia_Pavarde = longest_surname->getName().length();

	geriBlogiMokiniai(Studentas, n, Ilgiausias_Vardas, Ilgiausia_Pavarde, TekstinioFailoNr,Med_Vid);


	a.End("Isvedimas");

	Studentas.clear();
	Studentas.shrink_to_fit();
}

void calculation(vector<double>& Pazymiai, int Med_Vid, double & Galutinis, double & Egzaminas)
{
	if (Med_Vid)// Mediana
	{
		sort(Pazymiai.begin(), Pazymiai.end());
		Galutinis = Median(Pazymiai);
	}
	else		//Vidurkis
		Galutinis = Average(Pazymiai);

	Galutinis = Galutinis * 0.4 + 0.6 * Egzaminas;
	Pazymiai.erase(Pazymiai.begin(), Pazymiai.end());
	Pazymiai.shrink_to_fit();
}



