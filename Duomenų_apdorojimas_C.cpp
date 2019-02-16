#include <iostream>

using std::cout;
using std::cin;
using std::string;

int main()
{
int n;

cout<<"Kiek bus mokiniu: ";
cin>>n;

string Vardas[n];
string Pavarde[n];

int Egzaminas;
int* Pazymiai = new int[1];
int tmp; //Pazymys
int e = 0;
for(int i = 0; i<n; i++)
{
    cout<<"Iveskite "<< i <<"-ojo mokinio varda: ";
    cin>>Vardas[i];

    cout<<"Iveskite "<< i <<"-ojo mokinio pavarde: ";
    cin>>Pavarde[i];

    cout<<"Iveskite "<< i <<"-ojo mokinio pazymius";
    e = 0;
        do
        {
            cin>>tmp


            if(tmp > 0 && tmp < 11)
            {
            int* tmp1 = new int[e+1];

                for(int y = 0; y<e; y++)
                {
                    tmp1[y] = Pazymiai[y];
                }
                tmp1[e] = tmp;
                delete []Pazymiai;
                Pazymiai = tmp1;
                e++;
            }


        }while(tmp>0 && tmp<11)


}



cout<<"Iveskite egzamino pazymi: ";
cin>>Egzaminas;


}
