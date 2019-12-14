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
ROT7 om tecknet är jämt, annars används ROT9. Om den är jämn eller ej beror
på vilken ASCII-kod den har. "b" är t.ex. jämt då "b" har ASCII-koden 98. 

Uppgiften bygger på olika funktioner och strängar, och enda sättet att föra data 
mellan de olika funktionerna är via "return" i slutet av varje funktion. Således
måste värdet från ena funktionen skickas vidare till nästa, processeras, och sedan
skickas tillbaka för att bekräfta att rätt inloggningsinformation har angivits.

Main.cpp samt headern, prototypes.h innehöll nog information för att slutföra
uppgiften och skulle inte på något sätt modifieras. Det lämnar definitions.cpp
där alla funktioner finns kvar för editering. Även här existerade en funktion,
"mainArgumentParser" som inte skulle röras. De två funktionerna som saknade kod
var decryptPassword samt authenticateUser, authenticateUser har i uppgift att 
separera användarnamnet och lösenordet som skickades ner från mainArgumentParser
samt att jämföra argumenten mot dess lagrade konstanter, medan decryptPassword 
har i uppgift att kryptera lösenordet som skickades från authenticateUser när den
kallade på decryptPassword funktionen. 

Då main.cpp först anropar på mainArgumentParser för att verifiera att två argument
har angivits, om två har angivits så kommer authenticateUser att anropas. Den
första funktionen som får modifieras är authenticateUser, argumenten kommer till
denna funktion via Parsern som har satt ihop argumenten i formen 
"användarnamn,lösenord", dessa kommer att behöva separeras på. För att åstadkomma
det så valde jag att använda mig av två substrings, den första substringen
läser fram tills den hittar "," och skapar sedan en ny substräng av allt som finns
efter kommatecknet, det blir lösenordet. 
För att få ur användarnamnet så gjorde jag endast bakvänt och valde att skapa en
till substräng genom att kopiera originalsträngen till en ny substräng, och sedan
ta bort lösenordsträngens längd. Jag har då båda argumenten separerade.

Då användarnamnet alltid ska vara Kalle så behöver den inte krypteras, det räcker
då att jag kallar decryptPassword och skickar över den nya lösenordssträngar. För
att göra det kallar jag på decryptPassword med den nya lösenordssträngen.

Inne i decryptPassword finns tre konstanter, två är rotationsnycklarna 7 och 9, 
samt en konstant som innehåller alla vokaler i alfabetet. Från authenticateUser
har vi en konstant som lösenordet ska krypteras till "i0J0u0j0u0J0Zys0r0{", vi 
vet då att "bAnanASplit" på något sätt ska bli exakt samma.

Så fort en vokal hittas så ska en nolla skjutas in både före, och efter den,
sedan ska varje enskild karaktär i strängen roteras antingen 7 eller 9 varv 
som beskrevs tidigare. Problem uppstår om endast find() används, den kommer då 
hitta den första träffen av vokalen och trycka in en nolla, det finns två A i
lösenordet så det kommer inte att fungera. För att lösa detta la jag in ett
index som håller koll på var den senaste sökte ifrån, sedan efter varje vokalen så
kommer den fortsätta där den senast slutade, om en vokal upptäcks så måste index
öka med 3 istället för 1 då 2 extra tecken tillkommer (två nollor). Det här görs
i en nested for-loop som går igenom hela lösenordets längd för att hitta varje tecken.
En som arbetar utifrån lösenordets längd och går igenom hela lösenordet, 
och en som arbetar med indexet och går igenom varje vokal. På det sättet så
kommer hela lösenordet att läsas igenom, och inte påverkas av att nollor
sätts in. Den ursprungliga strängen innehåller nu nollor både före, och efter
varje vokal.

Därefter måste rotationsnycklarna ROT7 och ROT9 appliceras. För att lösa detta så
kommer återigen en for-loop att användas som går igenom hela strängar. Då
ROT7 och ROT9 ska appliceras på varannan karaktär förutom nollorna så blir det här
enkelt att lösa. De ligger i en for-loop efter varandra och indexet uppdateras
endast när loopen har gått ett varv, sedan jämförs indexet mot lösenordets längd
och om det inte är lika så fortsätter den. Om en nolla uppstår så finns en if-sats
före varje rotationsnyckel appliceras, om en nolla upptäcks så kommer indexet
som håller koll på vilken karaktär i strängen den för nuvarande pekar på öka 
med ett snäpp och på så sätt hoppa över nollan. Loopen löper igenom hela 
lösenordets längd och missar således ingen karaktär, två olika index används.
En för att varje karaktär i lösenordssträngen som passerade från authenticateUser
ska kollas igenom, och en som håller reda på vilken karaktär i dekrypteringssträngen
för närvarande pekas på. Det här behövs för att argumentet som angavs ska gå igenom
och inte den nya, manipulerade strängen som innehåller nollor. Det skrivs därför
över i en ny sträng så att inte for-loopen blir beroende av hur den nya 
strängen ser ut. 

I slutändan skapas ett whitespace som jag tar bort manuellt och jag vet inte
hur jag ska lösa det annars. Jag kan inte ta bort ett tecken från lösenordets
längd då den i så fall kommer skippa det sista tecknet, det är i den nya
strängen som probemet uppstår och det är där jag måste ta bort whitespacet.


## Discussion
Ibörjan av uppgiften så visste jag inte riktigt hur jag skulle lösa krypteringen. 
Jag tänkte att själva krypteringen med de olika nycklarna blir relativt simpel,
och för att få in nollorna så använder jag mig av ett index. Jag tänkte då
först utföra krypteringen för ROT7 och ROT9, sedan för att lokalisera vokalerna
från "bAnanASplit" så tänkte jag helt enkelt ta bort ROT7 eller ROT9 från varje
tecken och se om det resulterade i en vokal men jag fick det aldrig att fungera.

Jag ändrade strategi och bestämde mig istället för att sätta in nollorna på
en gång och sedan göra själva krypteringen. För att åstadkomma det så valde jag
att ignorera så fort en nolla fanns, jag visste ju då att den inte ska ändras. Därefter
hoppar programmet över ett steg och går vidare till nästa bokstav och utför sedan krypteringen.
 
Målet med laborationen är att lära sig hur strängar kan manipuleras och jämföras
med argument som ges vid running time. Just som ett inloggningssystem där ett
program existerar men tillgång inte ges förens dessa argument stämmer överens
med uppgifterna som finns i koden. Det räcker däremot inte med att endast skriva
in rätt argument, utan argumenten måste även krypteras och sedan jämföras mot
en konstant som existerar i koden. Det här fungerar som det ska eftersom
argumenten som ges, krypteras i korrekt ordning och jämförs med konstanten som
finns i koden. 

Vid en närmare titt på koden så syns det att krypteringen aldrig är
hårdkodad utan lösenordet som anges översätts med hjälp av krypteringsregler. 
Ett "if" statement hade kunnat användas för att lösa uppgiften men hade således
varit en slags hårdkodning, för att testa att det fungerar som det ska så räcker
det att ange de korrekta inloggningsuppgifterna som argumenten och sedan starta
programmet. Om något fel har uppstått i antingen användarnamn eller lösenord så
kommer inte programmet att godkänna dem, utan istället ge ett error och avslutas. 

