// Pruba dla bluetooth i aplikacji dla androida
/* T - Wskaznik pozomy
 * i - gałka lewa
 * k - gałka prawa
 * a - slaider obrotowt ograniczony
 * A - slaider(sówak) obtotowy
 * D - wskaznik obrotowy
 * C/c - Przycisk bistabilny
 * R/r - Przyci sk monostabilny 
 * G/g - Przycisk monostabilny
 * B/b - przycisk monostabilny
 * S - slaider poziomy
 * L/l - Przycisk bistabilny
 * P/p - Przycisk bistabilny
 * w/e/y - Swiatelka po lewej
 * z/x/q - Swiatelka po prawej
 */
#include<SoftwareSerial.h>
SoftwareSerial serial(2,3);


 
byte Przycisk_zasilania, Przycisk_czerwony, Przycisk_zielony, Przycisk_niebieski, Przelacznik_lewy, Przelacznik_prawy, Galka_prawax, Galka_praway, Galka_lewax, Galka_leway, Suwak_prawy, Suwak_lewy, Suwak_srodek, Wskaznik_gora, Wskaznik_srodek;
char dane;
String Swiatlo;
char tab[100];
char cmd[100];
byte cmdIndex;
boolean SC=false; //SC --> Suma kontrolna


void setup() {
Serial.begin(9600);
delay(500);
serial.begin(9600);
proba();
}
void proba(){
  serial.print("Proba");
for(int u=0; u!=101; u++){
  serial.print("*D");
  serial.println(u);
  serial.print("*T");
  serial.println(u);
  serial.print("*zR255G255B");
  serial.print(u*2);
  serial.println("*");
  serial.print("*xR255G");
  serial.print(u*2);
  serial.println("B255*");
  serial.print("*qR");
  serial.print(u*2);
  serial.println("G255B255*");
  serial.print("*wR255G255B");
  serial.print(u*2);
  serial.println("*");
  serial.print("*eR255G");
  serial.print(u*2);
  serial.println("B255*");
  serial.print("*yR");
  serial.print(u*2);
  serial.println("G255B255*");
  delay(500);
  }
  serial.println("*S0*");
  serial.println("*A0*");
  serial.println("*a0*");
  serial.print("*D");
  serial.println("0*");// Zerowanie gornego wskaznika
  serial.print("*T");
  serial.println("0*");// Zerowanie srodkowego wskaznika
  serial.print("*zR0G0B0*");// Zerowanie lampek
  serial.print("*xR0G0B0*");
  serial.print("*qR0G0B0*");
  serial.print("*wR0G0B0*");
  serial.print("*eR0G0B0*");
  serial.print("*yR0G0B0*");

  }

void Czytanie_danych(){  
  if(dane == 'L')
  ;
  if(dane == 'l')
  ;
  if(dane == 'C')
  ;
  if(dane == 'c')
  ;
  if(dane == 'P')
  ;
  if(dane == 'p')
  ;
  if(dane == 'R')
  ;
  if(dane == 'r')
  ;
  if(dane == 'G')
  ;
  if(dane == 'g')
  ;
  if(dane == 'B')
  ;
  if(dane == 'b')
  ;
  if(dane=='S'){
    Suwak_srodek=serial.parseInt();
  }
  if(dane=='A'){
    Suwak_lewy=serial.parseInt();
  }
  if(dane=='a'){
    Suwak_prawy=serial.parseInt();
  }
  if(dane=='i'){
    while(true){
      if(serial.available()){
        dane=serial.read();
        if(dane=='X') Galka_lewax=serial.parseInt();
        if(dane=='Y') Galka_leway=serial.parseInt();
        if(dane=='Y') break;
        }
      }
    }

    if(dane=='k'){
    while(true){
      if(serial.available()){
        dane=serial.read();
        if(dane=='X') Galka_prawax=serial.parseInt();
        if(dane=='Y') Galka_praway=serial.parseInt();
        if(dane=='Y') break;
        }
      }
    }
}
void loop(){
  if (serial.available()){
  dane=serial.read();
 // Czytanie_danych();
  }

  
  }
