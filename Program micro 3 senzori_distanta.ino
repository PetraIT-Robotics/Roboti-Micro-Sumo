int MotorSF = 9;   //motor stanga fata
int MotorSS = 6;   //motor stanga spate
int MotorDF = 5;   //motor dreapta fata
int MotorDS = 3;   //motor dreapta spate

int pwm=120; //putere totala
int pwr=50;  //puterea rotirii

int s=0;     //starea butonului pentru start cu rotire spre stanga
int d=0;     //starea butonului pentru start cu rotire spre dreapta
int bs=10;   //butonul pentru start cu rotire spre stanga definit pe digital 10
int bd=11;   //butonul pentru start cu rotire spre dreapta definit pe digital 11

int Sfs=8;   //senzorul de distanta din fata stanga definit pe digital 8
    int vfs;     //variabila in care se salveaza valorile senzorului de distana din fata stanga
int Sfd=4;   //senzorul de distanta din fata dreapta definit pe digital 4
    int vfd;     //variabila in care se salveaza valorile senzorului de distanta din fata dreapta
int Ss=7;    //senzorul de distanta din spate definit pe digital 7
    int vs;      //variabila in care se salveaza valorile senzorului de distanta din spate

#define Sjos A3     //senzorul de linie definit pe analog 0
    int vjos;   //variabila in care se salveaza valorile senzorului de linie
    
int minjos=100;    //valoarea minima a senzorului de linie pentru a nu atinge banda alba

void setup() 
{
  pinMode(MotorSF, OUTPUT);
  pinMode(MotorSS, OUTPUT);
  pinMode(MotorDF, OUTPUT);
  pinMode(MotorDS, OUTPUT);
  pinMode(bs,  INPUT);
  pinMode(bd,  INPUT);
  pinMode(Sfs, INPUT);
  pinMode(Sfd, INPUT);
  pinMode(Ss,  INPUT);
  pinMode(Sjos, INPUT);
  while(s==0 && d==0)             //cat timp niciun buton dintre cele doua nu este apasat, robotul nu face nicio miscare
  {
    if(digitalRead(bs) == HIGH)   //daca este apasat butonul din stanga se va termina asteptarea, robotul va porni peste 5 secunde iar acesta se va roti inspre stanga cand cauta inamicul
      s=1;
    else
      if(digitalRead(bd) == HIGH) //daca este apasat butonul din dreapta se va termina asteptarea, robotul va porni peste 5 secunde iar acesta se va roti inspre dreapta cand cauta inamicul
        d=1;
  }
  delay(5000);    //timpul in care persoanele se indeparteaza de ring
}

void loop() 
{
 citire();      
 if(vjos < minjos)          //daca robotul se afla pe linia alba,acesta porneste in spate 
  {
    mergi_spate(pwm);
    delay(300);
  }
 else if(vs==0)      //altfel daca senzorul din spate vede un inamic, robotul se opreste din orice alta deplasare si porneste in atac, in cazul acesta in spate
  {
    stopp();
    mergi_spate(pwm);
    delay(100);
  }
  else if(vfs==0 && vfd==0)    //altfel daca senzorii din fata vad un inamic, robotul se opreste din orice alta deplasare si porneste in atac, in cazul acesta in fata
  {
      stopp();
      mergi_fata(pwm);
      delay(100);  
  }
   else if(s==1)        //altfel daca senzorii de distanta nu observa niciun inamic si butonul din stanga a fost apasat la inceput, acesta se roteste inspre stanga in cautarea inamicului
        rotStanga(pwr);
   else if(d==1)        //altfel daca senzorii de distanta nu observa niciun inamic si butonul din dreapta a fost apasat la inceput, acesta se roteste inspre dreapta in cautarea inamicului
        rotDreapta(pwr);
}

void citire()     //citeste valorile tuturor senzorilor
{
  vfs=digitalRead(Sfs);
  vfd=digitalRead(Sfd);
  vs=digitalRead(Ss);
  vjos=analogRead(Sjos);
}

void mergi_fata(int viteza)      //trimite semnal driverului pentru a da putere rotirii in fata a motoarelor 
{
  analogWrite(MotorSF, viteza);
  analogWrite(MotorSS, 0);
  analogWrite(MotorDF, viteza);
  analogWrite(MotorDS, 0);
}

void rotStanga(int viteza)      //trimite semnal driverului pentru a da putere rotirii in fata a motorului din dreapta si in spate a motorului din stanga
{
  analogWrite(MotorSF, 0);
  analogWrite(MotorSS, viteza);
  analogWrite(MotorDF, viteza);
  analogWrite(MotorDS, 0);
}

void rotDreapta(int viteza)   //trimite semnal driverului pentru a da putere rotirii in fata a motorului din stanga si in spate a motorului din dreapta
{
  analogWrite(MotorSF, viteza);
  analogWrite(MotorSS, 0);
  analogWrite(MotorDF, 0);
  analogWrite(MotorDS, viteza);
}

void mergi_spate(int viteza)    //trimite semnal driverului pentru a da putere rotirii in spate a motoarelor 
{
  analogWrite(MotorSF, 0);
  analogWrite(MotorSS, viteza);
  analogWrite(MotorDF, 0);
  analogWrite(MotorDS, viteza);
}

void stopp()
{
  analogWrite(MotorSF, 0);
  analogWrite(MotorSS, 0);
  analogWrite(MotorDF, 0);
  analogWrite(MotorDS, 0);
}
