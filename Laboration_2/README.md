# Laboration 2
Av: Marcus Roos
Uppgift: Laboration 2 - Spies'R Us
Datum: 2019-12-04
Beskrivning av programmet: Programmet kommer ta två in-argument, sedan verifiera
om dessa stämmer överens med det förlagrade användarnamnet och lösenordet och sedan
ge användaren tillgång till programmet. Det är ett lösenord skyddat och använder sig
av krypteringsnycklarna ROT7 & ROT9 samt nollor vid varje versal. Användarnamnet ska
vara "Kalle" och lösenordet ska vara "bAnanASplit".

## Environment & Tools
Windows 10 64bitars.
IDE: CLion.
Miljö: MinGW 5.2
CMake: mingw32 make 3.15.3
C++ compiler: g++
Debugger: MinGW GDB 7.6.1
Git: Git 2.23.0.windows.1

## Purpose
Laborationen grundar sig i tidigare kunskaper som vi har lärt oss från övningsuppgifterna
samt de olika lektionerna. Vi ska här tillämpa dessa i en verklig miljö och bygga
ett inloggningssystem. Säkerhet är väldigt viktigt för många program och företag
och vi får tack vare den här uppgiften en insyn i hur det kan fungera. 

## Procedures
Argumenten som matas in är "Kalle" och "bAnanASplit", användarnamnet som är lagrat
under krypteringen är detsamma som "Kalle" däremot så är lösenordet något helt
annorlunda. Och för att kunna verifiera att lösenordet stämmer överens så måste
en kryptering av lösenordet göras. Vi ska då skjuta in en "0" så fort en versal
dyker upp i "bAnanASplit", sedan ska krypteringsnycklarna ROT7 och ROT9 användas.
ROT7 om karaktären är jämt, annars används ROT9. Om den är jämn eller ej beror
på vilken ASCII-kod den har. "b" är t.ex. jämt då "b" har ASCII-koden 98. 

Uppgiften bygger på olika funktioner och strängar, och enda sättet att föra data 
mellan de olika funktionerna är via "return" i slutet av varje funktion. Således
måste värdet från ena funktionen skickas vidare till nästa, processeras, och sedan
skickas tillbaka för att bekräfta att rätt inloggningsinformation har angivits.

## Discussion
Ibörjan av uppgiften så visste jag inte riktigt hur jag skulle lösa krypteringen. 
Jag tänkte att själva krypteringen med de olika nycklarna blir relativt simpel,
och för att få in nollorna så använder jag mig av ett index. Jag tänkte då
först utföra krypteringen för ROT7 och ROT9, sedan för att lokalisera vokalerna
från "bAnanASplit" så tänkte jag helt enkelt ta bort ROT7 eller ROT9 från varje
karaktär och se om det resulterade i en vokal men jag fick det aldrig att fungera.

Jag ändrade strategi och bestämde mig istället för att sätta in nollorna på
en gång och sedan göra själva krypteringen. För att åstadkomma det så valde jag
att ignorera så fort en nolla fanns, jag visste ju då att den inte ska ändras. Därefter
hoppar programmet över ett steg och går vidare till nästa bokstav och utför sedan krypteringen.

Jag hade problem med whitespace men löste det genom att ta bort sista karaktären från
den krypterade strängen. Jag ska försöka förfina programmet, men just nu fungerar
det som det ska. Jag tyckte det var svårt att få krypteringen att fungera på 
ett efterfrågat sätt och det tog mycket innan jag väl lyckades. Det var
däremot väldigt givande att mötas av något som var ordentligt svårt. Jag fick
kolla efter andra lösningar för att få det att fungera korrekt. Koden är
som sagt bökig just nu men jag ska försöka förfina den innan deadlinen.