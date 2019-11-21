# Laboration 1
//Av: Marcus Roos
//Uppgift: Laboration 1 - Palindrom
//Datum: 2019-11-13
/*Beskrivning av programmet: Programmet kommer att be användaren mata in ett fem siffrigt tal, sedan kommer detta tal att kastas om och räknas upp bakifrån, om talet
 * är detsamma framifrån som bakifrån så är det ett palindrom vilket är programmets uppgift. För att lösa detta används modulo operatorn för att släppa loss
 * den sista siffran i talet som skrivs in. Användaren har även möjlighet att upprepa programmet tills den så väljer att avsluta det genom att skriva N eller n.*/

## Utvecklingsmiljö & Verktyg
Windows 10 64bitars.
IDE: CLion.
Miljö: MinGW 5.2
CMake: mingw32 make 3.15.3
C++ compiler: g++
Debugger: MinGW GDB 7.6.1
Git: Git 2.23.0.windows.1

## Syfte
Laborationen bygger på tidigare kunskaper som övningsuppgifterna har lagt en grund för. Även fast varje syntax är klar så är problemet i
programmering att lära sig överkomma hinder och lösa alla problem som hamnar i ens väg. För den här laborationen fanns det inget färdigt
verktyg som kunde vända på en input och skriva ut det bakvänt utan de mest grundläggande verktyget fick användas för att lösa problemet som uppstod.


## Genomförande
För att skriva ett tal baklänges i C++ så måste vi ta reda på vad det sista talet i ledet är och sedan arbeta oss mot början (slutet).
Då modulo ger resten av en division så kommer ett tal vars värde inte är delbart med hundra (Ett palindrom kan inte vara jämnt delbart med hundra),
så kommer resten att vara den sista siffran i ledet om modulo 10 används, t.ex. så ger 456 787 654 % 10 = 456 78 765.4, endast int används så detta tal kommer
att ignorera decimalen och avrundas till 456 787 65. Modulo ser däremot inte decimalen utan ser endast resten som ett heltal, och detta heltal lagras i en annan variabel.
Eftersom beräkningen fortskrider så kommer talet ha betats av från slutet till början och tillslut kommer det bakvända talet vara lagrat i en annan variabel (RevNum i mitt fall).
Om RevNum är samma som InNum (Numret som skrevs in ibörjan) så är talet ett paidrom, annars är det inte.

Problem uppstod då endast tal mellan 10000 och 99999 var accepterade, brukaren skulle få möjligheten att köra om programmet, samt att endast siffror fick matas in.
Hjälp gavs verifikation av siffror, men det andra fick lösas eftersom, jag hade gjort en while-loop till en början men upptäckte att det inte gick, eller var betydligt krångligare
att köra om programmet på det sättet, därför murade jag in allt i en do-while loop, deklarerade variabeln char och använde det för att verifiera om användaren ville köra om.
För att kolla hur stort talet var så använde jag ytterligare en while loop i den tidigare while-loopen. Jag har testat programmet grundligt och bett närstående testa det åt mig
och ingen har hittills hittat en bug.

10000 var ett speciellt fall, även om mitt program fungerade för att tolka det som 1 baklänges så ville jag ha kvar nollorna då det är tydligare när man använder programmet,
för att lösa det så använde jag mig av en if-sats. Det var egentligen inget problem utan att jag ville representera nollorna på något sätt.

## Diskussion
Jag lärde mig något enormt, jag har gjort övningsuppgifterna men då har det (på gott och ont), funnits andras material att kolla, jag har försökt att inte använda deras
material men det resulterar i att jag läser vad de har gjort och sedan implementerar mina egna lösningar. Det utvecklar min färdighet trots allt, på laborationen
fanns det inget annat material att kolla på så då fick jag lösa uppgifterna helt på egen hand. Även om det tog runt 8 timmar att få det att fungera så som jag vill så är det
inte alls för bedrövligt tycker jag. Jag lärde mig mycket om modulo, även om jag har vetat vad den gör och hur den fungera så byggs en annan uppfattning när man arbetar
med den så mycket som jag gjorde i denna uppgift, jag litade verkligen helt på modulo för att lösa uppgiften. Jag har svårt att få programmet att fungear så som jag vill,
if och else satser är bland de enklaste satserna men ändå är det där jag fastnade, jag la alldeles för mycket tid på att försöka upprepa koden genom att väljaren fick
skriva in sitt val i sista if/else-satsen. Övningarna är det som har fått mig att ens kunna göra den här uppgiften, jag var helt grön på programmering innan.
Jag tyckte om själva uppgiften, allt lades ut klart och det uppstod inga konstigheter över huvudtaget.

^Det blev en ändning på den där sista meningen. Jag visste från början inte att vi endast var begränsade till att använda sånt som vi har arbetat med tidigare, jag använde 
mig av "goto" för att strukturera upp mitt program, samt att jag ville ändra till string för att kontrollera input då programmet ska köras om eller avbrytas. detta behövde 
jag ändra vilket la till 10 extra rader med kod i mitt program. Sån information hade varit trevlig att få innan laborationen hann göras klart, däremot är det förståeligt då 
det nyligen blev uppdaterat och det är enkelt att missa. Sen är goto inte det bästa att använda då koden blir väldigt fram och tillbaka och otydlig, så det var snarare bättre 
än dåligt att vi blev begränsade. Jag hade väldigt svårt att begränsa input då programmet ska upprepas utan hjälp av strings men löste det med cin.clear, annars så loopades loopen
så pass många gånger som antal bokstäver man skrev in.

Överlag, en rolig uppgift, blev verkligen en problemlösning och det är sånt som är kul. Jag hoppas verkligen att programmet fungerar som det ska, jag har försökt att förstöra det 
men det finns alltid någonting man missar.
