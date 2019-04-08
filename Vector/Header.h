#pragma once

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <random>
#include <vector>
#include <ctype.h>
#include <cctype>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <chrono>
#include <list>
#include <iterator>

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
using std::getline;
using std::list;

class Universitetas {
private:
	string m_Name;
	string m_Surname;
	double m_Exam;
	double m_Score;
public:

	void putInfo(string, string, double, double);
	void putName();
	void putSurname();

	string getName();
	string getSurname();
	double getExam();
	double getScore();
	Universitetas();
	~Universitetas();

};

struct Stopwatch {
	std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
	std::chrono::duration<float> duration;

	void Start();
	void End(string operation);
};

void createData(int noFiles);
//void Ilgiausias(vector<Universitetas>&A, int n, int &Vardas, int &Pavarde);
bool Input();
double Median(vector<double> &Pazymiai);
double Average(vector<double> &Pazymiai);
bool is_alpha(const std::string &str);
void nameCheck(vector<Universitetas> &A, int i);
bool compareLetter(Universitetas &stud1, Universitetas& stud2);
bool compareNumber(Universitetas &stud1, Universitetas& stud2);
bool compareNameLength(Universitetas &stud1, Universitetas& stud2);
bool compareSurnameLength(Universitetas &stud1, Universitetas& stud2);
void Isvedimas(vector<Universitetas> &Studentas, int Med_Vid, int n, int TekstinioFailoNr);
void calculation(vector<double>& Pazymiai, int Med_Vid, double& Galutinis, double &Egzaminas); // skaiciuojami vidurkiai ar medianos
void Read(vector<Universitetas> &Studentas, int &n, int Med_Vid, int TekstinioFailoNr); // nuskaitymas
bool checkFile(int i); // tikrina ar yra duomenu failas
bool findScore(Universitetas& stud2); // randa kur prasideda blogi mokiniai
void geriBlogiMokiniai(vector<Universitetas>& Studentas, int n, int Ilgiausias_Vardas, int Ilgiausia_Pavarde, int TekstinioFailoNr,int Med_Vid);
void box(std::ostream& out, int Med_Vid, int Ilgiausias_Vardas, int Ilgiausia_Pavarde); // lentele kuriama geriem ir blogiem studentam kur vardas ir pavarde
void printing(std::ostream& out, vector<Universitetas>& Studentas, int Ilgiausia_Pavarde, int Ilgiausias_Vardas); // spausdinimas





