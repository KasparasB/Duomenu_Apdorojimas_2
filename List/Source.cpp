#include "Header.h"

int main()
{

	int n = 0; // mokiniu skaicius
	bool Med_Vid = 0;// mediana ar vidurkis // tikrinimui ar yra duomenu failas
	int DuomenuFailai = 0;

	cout << "Kiek duomenu failu sukurti? "; cin >> DuomenuFailai;

	if (cin.fail() != 1 && DuomenuFailai > 0 && DuomenuFailai < 6)
	{
		DuomenuKurimas(DuomenuFailai);

		Med_Vid = Ivedimas();
		int Skaicius = 100;
		for (int i = 0; i < DuomenuFailai; i++)
		{
			auto start = std::chrono::system_clock::now();
			if (Tikrinimas(i))
			{
				n = 0;
				list<Universitetas> Studentas;
				//Studentas.reserve(Skaicius);
				Skaitymas(Studentas, n, Med_Vid, i);
				Isvedimas(Studentas, Med_Vid, n, i);

			}
			auto end = std::chrono::system_clock::now();
			auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start) * 0.001;
			std::cout << "Visas laikas" << setprecision(4) << elapsed.count() << '\n';
			Skaicius *= 10;
		}
		system("PAUSE");
	}
	else
		cout << "Pasirinktas klaidingas kuriamu failu kiekis" << endl;
}
