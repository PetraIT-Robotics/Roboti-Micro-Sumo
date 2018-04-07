#define MdrFata 5   //Motor dreapta fata
#define MsgFata 3   //Motor stanga fata
#define MdrSpa  11  //Motor dreapta spate
#define MsgSpa  10  //Motor stanga spate

#define Sjos A3      // Senzor de linie

int Enemy=7;         //Senzorul de distanta digital

int  putere_totala=200;  //putere totala
int  puterea_rotirii=45; //puterea rotirii
int  sw=150;             //valoare minima a senzorilor de linie

int f1;    //variabila in care se citeste valoarea senzorului de distanta
int j1;    //variabila in care se citeste valoarea senzorului de linie
void setup() {
 pinMode (MdrFata, OUTPUT);
 pinMode (MsgFata, OUTPUT);
 pinMode (MdrSpa,  OUTPUT);
 pinMode (MsgSpa,  OUTPUT);
 pinMode (13,      OUTPUT);
 pinMode (Enemy,  INPUT);
 pinMode (Sjos,   INPUT);
 digitalWrite(13,HIGH);     //se aprinde led-ul integrat de pe pinul 13 pentru a anunta ca peste 5 secunde robotul va porni

delay(5000);      //cele 5 secunde sunt pentru a lasa timp persoanelor sa se indeparteze de ring
 digitalWrite(13,LOW);      //se inchide led-ul pentru a economisi energie    
}

void loop() 
{
  citire();        //apeleaza functia citire
  if(f1==0)        //daca senzorul de distana are valoarea 0, inseamna ca vede un inamic
  {
      mergi_fata();   //rorbotul ataca
      delay(70);      /* delay-ul este pentru a nu se duce foarte mult in fata, putin cate putin, altfel
                         riscand sa paraseasca ringul   */
  }
  else             //daca senzorul de distana nu are valoarea 0, inseamna ca nu vede un inamic
    Rot_Stanga();     //robotul se roteste inspre stanga lasand senzorii sa gaseasca inamicul in urmatoarea executate a loop-ului


  if(j1<sw)      //daca senzorul de linie are valoarea mai mica decat 150, inseamna ca robotul se afla pe linia alba, deci trebuie sa mearga cu spatele pentru a nu iesi din ring
    {
      mergi_spate();
      delay(300);
    }
}

void citire()      //subprogram ce citeste in valorile f1,j1 valoarea senzorului de distana, respectiv a celui de linie
{
 f1=digitalRead(Enemy);
 j1=analogRead(Sjos);
}

void mergi_fata()  //subprogram ce trimite semnal driverului pentru a da putere rotirii in fata a fiecarui dintre cele doua motoare
{
  analogWrite(MsgSpa,0);
  analogWrite(MdrFata, putere_totala);
  analogWrite(MdrSpa,0);
  analogWrite(MsgFata, putere_totala);
  return ;
}

void mergi_spate() //subprogram ce trimite semnal driverului pentru a da putere rotirii in spate a fiecarui dintre cele doua motoare
{
  analogWrite(MsgSpa, putere_totala);
  analogWrite(MdrFata,0);
  analogWrite(MdrSpa, putere_totala);
  analogWrite(MsgFata,0);
}

void Rot_Stanga() //subprogram de trimite semnal driverului pentru a da putere rotirii in fata a motorului din partea dreapta si in spate a motorului din partea stanga
{
  analogWrite(MsgSpa,  puterea_rotirii);
  analogWrite(MsgFata,0);
  analogWrite(MdrFata, puterea_rotirii);
  analogWrite(MdrSpa, 0);
  
  return ;
}

void Rot_Dreapta() //subprogram de trimite semnal driverului pentru a da putere rotirii in spate a motorului din partea dreapta si in fata a motorului din partea stanga
{
  analogWrite(MsgSpa, 0);
  analogWrite(MdrFata,0);
  analogWrite(MdrSpa,  puterea_rotirii);
  analogWrite(MsgFata, puterea_rotirii);
  return ;
}
