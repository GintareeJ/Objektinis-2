# V1.2

## Programos atnaujinimas

v1.2 versija yra išplėsta v1.1 versija, kurioje pagrindinis dėmesys skirtas:
- „Rule of Five“ realizacijai
- įvesties/išvesties operatorių perdengimui
- pilnam metodų testavimui

## „Rule of Five“ realizacija

Klasėje `Studentas` realizuoti visi būtini metodai:

- Konstruktorius
- Kopijavimo konstruktorius (copy)
- Perkėlimo konstruktorius (move)
- Kopijavimo priskyrimo operatorius (copy assigment operator)
- Perkėlimo priskyrimo operatorius (move assigment operator)
- Destruktorius

### Paskirtis

Ši realizacija užtikrina:
- saugų darbą su dinaminiu atminties valdymu
- efektyvų objektų kopijavimą
- greitesnį veikimą naudojant perkėlimą (move semantics)

## Įvesties / išvesties operatoriai

Klasėje `Studentas` perdengti operatoriai:
- `operator>>` – duomenų įvedimui
- `operator<<` – duomenų išvedimui

### Įvesties būdai:
- rankiniu būdu (per `cin`)
- nuskaitymas iš failo
- automatinis generavimas

### Išvesties būdai:
- į ekraną (`cout`)
- į failą

## Testavimas

Sukurtas atskiras testavimo failas (`testai.cpp`), kuriame tikrinami visi klasės metodai.
![Testas](test.png)

### Testuojami elementai:

- visi konstruktoriai
- kopijavimo operacijos
- perkėlimo (move) operacijos
- destruktorius
- įvesties/išvesties operatoriai

### Testavimo principas:

- sukuriami objektai skirtingais būdais
- tikrinama ar duomenys korektiškai kopijuojami
- tikrinama ar move operacijos perkelia duomenis
- tikrinamas išvedimo formatas


## Programos funkcionalumas

Programa:
- nuskaito studentų duomenis iš failo
- leidžia įvesti duomenis rankiniu būdu
- gali generuoti atsitiktinius studentus
- apskaičiuoja galutinį balą (vidurkis / mediana)
- rūšiuoja studentus
- skirsto į grupes pagal rezultatus
- leidžia naudoti skirtingus konteinerius:
  - `vector`
  - `list`
  - `deque`
- matuoja veikimo laikus


## Išvados

- „Rule of Five“ realizacija leidžia efektyviai valdyti atmintį
- move operacijos sumažina nereikalingą kopijavimą
- perdengti operatoriai supaprastina darbą su duomenimis
- klasė tampa universalesnė ir tinkama tolimesniam naudojimui
