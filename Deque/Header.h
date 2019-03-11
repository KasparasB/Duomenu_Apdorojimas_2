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
#include <deque>

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
using std::deque;

struct Universitetas {
	string Vardas;
	string Pavarde;
	deque<double> Pazymiai;
	double Egzaminas;
	double Galutinis;
	int Pazymiu_Skaicius;
};

void DuomenuKurimas();
void Ilgiausias(deque<Universitetas>&A, int n, int &Vardas, int &Pavarde);
bool Ivedimas();
double Mediana(deque<double> &Pazymiai, int e);
double Vidurkis(deque<double> &Pazymiai, int e);
bool is_alpha(const std::string &str);
void VardasPavarde(deque<Universitetas> &A, int i);
bool Rikiavimas(Universitetas &stud1, Universitetas &stud2);
void Isvedimas(deque<Universitetas> &Studentas, int Med_Vid, int n, int TekstinioFailoNr);
void Generavimas(deque<double>& Pazymiai, int Med_Vid, double& Galutinis, int& PazymiuSk, double &Egzaminas);
void Skaitymas(deque<Universitetas> &Studentas, int &n, int Med_Vid, int TekstinioFailoNr);
bool Tikrinimas(int i);
void geriBlogiMokiniai(deque<Universitetas>& Studentas, int n, int Ilgiausias_Vardas, int Ilgiausia_Pavarde, int TekstinioFailoNr);




