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

	string getName() const;
	string getSurname() const;
	double getExam() const;
	double getScore() const;
	Universitetas();
	~Universitetas();
	Universitetas(const Universitetas& v)
	{
		m_Exam = v.m_Exam;
		m_Name = v.m_Name;
		m_Surname = v.m_Surname;
		m_Score = v.m_Score;
	}

	// Using friend functions because I think it will be easier to access members of class.
	friend std::ostream& operator<<(std::ostream& out,const Universitetas &a); // Prints out a desired student
	friend std::istream& operator>>(std::istream& in, Universitetas &a); // Changes data of student
	Universitetas& operator=(const Universitetas& v);
	Universitetas(Universitetas&& s) : // move c-tor
		m_Name{ s.m_Name },
		m_Surname{ s.m_Surname},
		m_Exam{ s.m_Exam },
		m_Score{ s.m_Score}
		// s yra vardinė r-value nuoroda, todėl l-value
		// nd_{ std::move(s.nd_) } // be std::move kviestų copy c-tor
	{
	}
};

struct Stopwatch {
	std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
	std::chrono::duration<float> duration;

	void Start();
	void End(string operation);
};

void createData(int noFiles);
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





