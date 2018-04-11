# Roboti-Micro-Sumo
 
 <iframe width="560" height="315" src="https://www.youtube.com/embed/25kcRJWkUBg" frameborder="0" allow="autoplay; encrypted-media" allowfullscreen></iframe>
 
 
		Capitolul I. Utilitate practică

•	Cei doi roboți sunt roboți micro-sumo. Aceștia se luptă într-un ring circular cu suprafața de culoare neagră, iar pe marginea ringului se află o bandă albă.

•	Cei doi roboți rezolvă in totalitate problema expusă: luptă;

•	Cei doi roboți sunt micro-sumo, având dimensiunea maximă de 5x5x5cm, iar ringul avănd diametrul de 35-40 cm. Pentru satisfacerea unei lupte cu roboți de dimensiune relativ mică altă metodă nu poate fi aplicată.



		Capitolul II. Mecanică
•	Ambii roboți sunt echipați cu câte 2 motoare pentru a putea efectua mișcări libere pe axele OX,OY și pentru a urmări inamicul. Turnulet are motoare de 1:30, iar Penseta 1:10.

•	 Singurele piese mobile ale roboților sunt roțile și motoarele. 

•	 Fiecare robot este echipat cu câte două celule Li-Po de 3.7 V si aproximativ 650 mAh. Cele 2 celule sunt  conectate în serie pentru a se ajunge la tensiunea minimă necesară funcționării plăcii Arduino de 5 V.

•	Roboții nu posedă o sursă regenerabilă de energie.



		Capitolul III. Electronică
•	ATmega328 este un cip microcontroler creat de către Atmel folosit de noi ca și “creierul” robotului. Atmega328 AVR 8-bit este un circuit integrat de înaltă performanță ce se bazează pe un microcontroler RISC, combinând 32 KB ISP flash, o memorie cu capacitatea de a citi-în-timp-ce-scrie, 1 KB de memorie EEPROM, 2 KB de SRAM, 23 linii E/S de uz general, 32 Înregistrari procese generale, trei cronometre /contoare flexibile cu funcție de comparație, întreruperi interne și externe, serial USART programabil, SPI port serial, 6-canale 10-bit Converter A/D (8-chanale în TQFP și QFN/MLF packages), "watchdog timer" programabil cu oscilator intern, și cinci moduri de economisire a energiei selectabile din soft. Dispozitivul funcționează între 1,8-5,5 volți. Prin executarea instrucțiunilor puternice într-un singur ciclu de ceas, aparatul realizează un răspuns de 1 MIPS. Pinii digitali îi folosim pentru senzorii de distanță, iar cei analogici pentru senzorul de linie. Avem de asemenea pinii pentru masă(GND) și pentru 5V(VCC). 

•	Driver-ul de motoare L293D este utilizat pentru controlul motoarelor de curent continuu folosind Arduino, pe Turnuleț. Arduino este capabil să scoată pe porturile lui o putere foarte mică, total insuficientă pentru a învârti un motor. Dacă vom conecta un motor electric direct la un port Arduino, cel mai probabil vom obține arderea procesorului din placa Arduino. Ca să nu se întample acest lucru, avem nevoie de un amplificator de putere, care să ia putere din sursa de alimentare (baterie, de exemplu), si să o transmita motoarelor așa cum îi comandă Arduino. Acest amplificator poartă numele generic de "driver de motoare". Pe al doilea robot, Pensetă, a fost nevoie de un alt driver mai mic, construit de asemenea de noi din smd-uri.

•	Cei doi roboți folosesc 2 tipuri de senzori. Un tip este senzorul de distanță ce returnează valoarea 0 daca un obiect se află in raza acestuia, respectiv 1 daca niciun obiect se află in raza senzorului (Sharp GP2Y0D810Z0F Digital Distance Sensor 10cm) Al doilea tip de senzor este cel de linie, de data aceasta analogic (valorile pot fi si altele, nu doar 0 și 1) , ce returnează valori mari daca vede culoarea neagră, valori mici daca vede culoarea albă (QTR-1A Reflectance Sensor).

•	Pe baza valorilor returnate de senzori, roboții acționează diferit (ex: Dacă senzorul de distanță digital returnează valoarea 0, robotul merge in față, înspre inamic; Dacă senzorul de linie returnează valori mici, robotul va merge in spate deoarece acesta se află pe linia albă, adică aproape de ieșirea din ring;)

•	Am ales senzori de distanță digitali, nu analogici, deoarece sunt de dimensiune mai redusă, iar noi a trebuit să ținem cont de acest aspect, roboții micro-sumo fiind maxim de doar 5x5x5cm .

•       Eu și cu Alex preferăm să construim roboții în totalitate. Turnulețul este unul dintre acei roboți la care toate piesele în afara de motoare și senzorul de distanță sharp sunt realizate de noi. Am reproiectat placa arduino UNO in așa fel încât driverul să poată fi pus direct pe aceasta fără fire suplimentare, am tras-o pe cablaj, am lipit fiecare piesă. Senzorul de linie este realizat tot de noi; am lipit smd-urile si senzorul în sine de cablaj. Acest lucru il considerăm  avantajul nostru, pentru că înțelegem cât se poate ce face fiecare componentă. Mulți preferă să cumpere kit-uri, le asamblează și gata, au un robot. Al doilea robot, Pensetă, este un experiment ceva mai nou. Este mult mai compact decât Turnuleț(Totusi dimensiunea ambilor roboți este mai mică sau egală decât 5x5x5 cm), iar asta a necesitat cumpararea unei plăci arudino pro micro. În rest, acesta este construit de noi prin multă muncă ,cu un driver diferit alcătuit din smd-uri. Scopul experimentului a fost de a vedea diferența dintre un robot construit în totalitate de noi și unul cu o placă arduino cumpărată. 

		Capitolul IV. Software
•	Programul celor 2 roboți este diferit deoarece unul dintre ei posedă un singur senzor de distanță digital amplasat în față, în timp ce al doilea robot are 3 senzori de distanță, 2 amplasați în față și unul în spate, ce returnează valoarea 0 daca un obiect se află in raza acestuia, respectiv 1 daca niciun obiect nu se află in raza senzorului. Programul este independent, utilizatorul neputând afecta execuția acestuia.Excepție face un robot ce poate porni cu o întoarcere spre stânga sau dreapta, în funcție de apăsarea unui buton înainte de startul luptei.

•	Structura este simplă, dacă robotul observă un inamic acesta atacă.Dacă robotul se află pe linia albă acesta va merge cu spatele până când va intra din nou pe suprafața de luptă(suprafața neagră), iar în rest robotul se va roti pentru a căuta inamicul.




	Profesori Coordonatori:
•	Prof. Liviu Maftean, Palatul Copiilor Suceava

•	Prof. Raluca Costineanu, Colegiul Național Ștefan cel Mare Suceava

•	Prof. Ovidiu Marcu, Colegiul Național Ștefan cel Mare Suceava




   	Echipa noastra:
•	Petracovici Tudor, Colegiul Național Ștefan cel Mare

•	Albu Alexandru, Colegiul Național Ștefan cel Mare

