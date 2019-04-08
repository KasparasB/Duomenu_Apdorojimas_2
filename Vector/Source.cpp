#include "Header.h"

int main()
{
	Stopwatch a;
	int n = 0; // mokiniu skaicius
	bool Med_Vid = 0;// mediana ar vidurkis // tikrinimui ar yra duomenu failas
	int noFiles = 0; // failu skaicius
	cout << "Kiek duomenu failu sukurti? "; cin >> noFiles;
	
	if (noFiles > 0 && noFiles < 6)
	{
		createData(noFiles); // kuriami duomenys
		Med_Vid = Input();
		int Skaicius = 100;
		for (int i = 0; i < noFiles; i++)
		{
			a.Start();
			if (checkFile(i))
			{
				n = 0;
				vector<Universitetas> Studentas;
				Studentas.reserve(Skaicius);
				Read(Studentas, n, Med_Vid, i);
				Isvedimas(Studentas, Med_Vid, n, i);
			}
			a.End("Visas veikimas");
			Skaicius *= 10;
		}
		system("PAUSE");
	}
}
