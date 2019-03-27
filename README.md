# Duomenu Apdorojimas


## [v0.1](https://github.com/KasparasB/Duomenu_Apdorojimas/releases/tag/v0.1) papildymas

Programa nuskaito:
* Studento vardą ir pavardę
* Automatiškai sugeneruoja:
  * Namų darbų skaičių (3-10)
  * Namų darbų pažymius (1-10)
  * Egzamino pažymį

Galima pasirinkti 2 skirtingus galutinio balo skaičiavimo būdus t.y., pagal medianą arba vidurkį

Duomenų nuskaitymas:

```shell

Kiek bus mokiniu: 2
Skaiciuoti pagal mediana ar vidurki? (1 - Mediana, 0 - Vidurkis)
1
Iveskite 1-ojo mokinio varda: Kasparas
Iveskite 1-ojo mokinio pavarde: Brazenas
Iveskite 2-ojo mokinio varda: Matas
Iveskite 2-ojo mokinio pavarde: Cenys

```
Duomenų išvedimas

```shell
Vardas   Pavarde  Galutinis (Med.)
___________________________________
Kasparas Brazenas 7.00
Matas    Cenys    6.60
```

Įkeltos dvi versijos: 
1. Atlikta su C masyvu
2. Atlikta su vektoriais

Versija su vektoriais turi daugiau pataisymų ir neleidžia vartotojui įvesti neteisingų duomenų

## [v0.2](https://github.com/KasparasB/Duomenu_Apdorojimas/releases/tag/v0.2) papildymas

Pridėtas header failas
Ištaisytos kai kurios klaidos
Patobulintas įvedimas (mažiau galimybių "užlaužti programą"
* Pridėta klaidingo failo apsauga
* Tikrinami mokinių vardai ir pavardės
* Žiūrima, ar mokinys turi daugiau nei vieną pažymį
* Mokiniai gali turėti skirtingus kiekius pažymių

Programa atpažįsta tekstinį failą TIK jeigu jo pirma eilutė atrodo štai taip:
```shell
Pavarde Vardas ND1 ND2 ND3 ND4 Egzaminas
```

MINUSAI:
netvarkingas ir ne optimalus kodas

## [v0.3](https://github.com/KasparasB/Duomenu_Apdorojimas/releases/tag/v0.3) papildymas

1. Pataisytas header failas
2. Pridėtas funkcijų failas
3. Pridėtas tikrinimas, ar pažymys nėra raidė


## [v0.4](https://github.com/KasparasB/Duomenu_Apdorojimas/releases/tag/v0.4) papildymas

Programos metu yra sukuriami 5 .txt failai (sudaryti iš: 1000, 10000, 100000, 1000000, 10000000 įrašų). Nebenaudojama funkcija tikrinti vardus ir pavardes, nes kuriami šabloniniai vardai su skaičiais.

Tuomet paskaičiuojami studentų rezultatai ir vardai su pavardėmis išvedami į atskirus failus pavadinimu "rezultatas.txt". Taip pat išvedami skirtingi failai mokiniams, kurių galutinis balas yra mažesnis nei 5 ir kurių balas yra lygus 5 arba didesnis.

Studentai yra surūšiuojami pagal vardus ir pavardes.

Programos spartos analizė atlikta su release mode (paimti duomenys suapvalinti iš 5 testų):


|Funkcija                     |n = 1000   |n = 10000     |n = 100000    |n = 1000000   |n = 10000000 |
|-----------------------------|----------|------------|------------|------------|-----------|
|Duomenų sukūrimas |0.009 s|0.09 s|0.87 s|8.581 s|86.05 s|
|Išvedimas|0.015        s|0.109         s|1.126 s|10.9 s|107.6 s|
|Išvedimas į 2 atskirus failus|0.007        s|0.053        s|0.532 s|5.486 s|55.86 s|
|Visas veikimo laikas|0.021        s|0.149        s|1.456 s|14.59 s|150.7 s|

Galimi neatitikimai su visu programos veikimo laiku dėl duomenų apvalinimo arba dėl netinkamose vietose pradedamo matuoti laiko.

## [v0.5](https://github.com/KasparasB/Duomenu_Apdorojimas/releases/tag/v0.5) papildymas


### Vector

|Funkcija                     |n = 100    |n = 1000     |n = 10000    |n = 100000   |n = 1000000 |
|-----------------------------|----------|------------|------------|------------|-----------|
|Veiksmai atliekami su duomenimis|0 s|0.003 s|0.0037 s|0.038 s|3.81 s|
|Gerų, blogų mokinių išvedimas|0.001       s|0.006         s|0.049 s|0.497 s|5.047 s|
|Rezultato išvedimas |0.003        s|0.008        s|0.053 s|0.521 s|5.283 s|

### List

|Funkcija                     |n = 100    |n = 1000     |n = 10000    |n = 100000   |n = 1000000 |
|-----------------------------|----------|------------|------------|------------|-----------|
|Veiksmai atliekami su duomenimis|0 s|0.004 s|0.043 s|0.447 s|4.391 s|
|Gerų, blogų mokinių išvedimas|0.001       s|0.006         s|0.053 s|0.547 s|5.593 s|
|Rezultato išvedimas |0.023        s|0.008        s|0.058 s|0.593 s|6.32 s|

### Deque

|Funkcija                     |n = 100    |n = 1000     |n = 10000    |n = 100000   |n = 1000000 |
|-----------------------------|----------|------------|------------|------------|-----------|
|Veiksmai atliekami su duomenimis|0 s|0.004 s|0.0043 s|0.441 s|4.404 s|
|Gerų, blogų mokinių išvedimas|0.001       s|0.006         s|0.051 s|0.51 s|5.165 s|
|Rezultato išvedimas |0.003        s|0.008        s|0.059 s|0.585 s|5.95 s|

Duomenų faile nėra duomenų su 1 000 000 vardų ir pavardžių, nes didesnio nei 25MB failo github neleidžia įkelti.

## [v1.0](https://github.com/KasparasB/Duomenu_Apdorojimas/releases/tag/v1.0) papildymas

Pirmos strategijos rezultatai čia nepateikti, nes pasirodo, kad visos mano programos buvo parašytos su pirma strategija, todėl jos rezultatus galima pamatyti v0.5

## ANTRA STRATEGIJA

### Vector

|Funkcija                     |n = 100    |n = 1000     |n = 10000    |n = 100000   |n = 1000000 |
|-----------------------------|----------|------------|------------|------------|-----------|
|Veiksmai atliekami su duomenimis|0 s|0.003 s|0.0036 s|0.037 s|3.742 s|
|Gerų, blogų mokinių išvedimas|0.002       s|0.005         s|0.051 s|0.508 s|5.096 s|
|Rezultato išvedimas |0.003        s|0.007        s|0.054 s|0.525 s|5.252 s|

### List

|Funkcija                     |n = 100    |n = 1000     |n = 10000    |n = 100000   |n = 1000000 |
|-----------------------------|----------|------------|------------|------------|-----------|
|Veiksmai atliekami su duomenimis|0 s|0.004 s|0.041 s|0.418 s|4.286 s|
|Gerų, blogų mokinių išvedimas|0.001       s|0.005         s|0.052 s|0.549 s|5.552 s|
|Rezultato išvedimas |0.002        s|0.007        s|0.055 s|0.575 s|6.105 s|

### Deque

|Funkcija                     |n = 100    |n = 1000     |n = 10000    |n = 100000   |n = 1000000 |
|-----------------------------|----------|------------|------------|------------|-----------|
|Veiksmai atliekami su duomenimis|0 s|0.004 s|0.043 s|0.428 s|4.33 s|
|Gerų, blogų mokinių išvedimas|0.002       s|0.005         s|0.052 s|0.531 s|5.113 s|
|Rezultato išvedimas |0.003        s|0.007        s|0.058 s|0.588 s|5.749 s|

Logiška, jog su antra strategija programa veikia greičiau, nes kompiuteriui tenka susidoroti su mažesniais duomenų kiekiais, mažiau skaičiuoti ir išvedinėti.

Taip pat  panaudojau **std::search()** algoritmą, kuris padeda greičiau surasti narį, nuo kurio prasideda galutiniai įverčiai mažesni nei 5.

### Vector su std::search()

|Funkcija                     |n = 100    |n = 1000     |n = 10000    |n = 100000   |n = 1000000 |
|-----------------------------|----------|------------|------------|------------|-----------|
|Veiksmai atliekami su duomenimis|0 s|0.003 s|0.0036 s|0.0369 s|3.709 s|
|Gerų, blogų mokinių išvedimas|0.001       s|0.005         s|0.05 s|0.502 s|5.043 s|
|Rezultato išvedimas |0.002        s|0.007        s|0.053 s|0.519 s|5.201 s|


## Programos paleidimas

**v1.0 versiją galima pasileisti:**

1. Nusiklonavus repozitoriją
2. makefile įkėlus į norimą folderį (deque, vector, list)
3. Per cmd atsidarius tą folderį ir parašius **make** ir po to **./main**
4. Išvalyti visus duomenis su make **clean**


