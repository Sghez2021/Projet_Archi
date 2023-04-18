#include <SimpleTimer.h>
#include <Adafruit_NeoPixel.h>
#define PIN            5 // Pin de connexion du bandeau
#define PIN1  7
#define PIN2  6

#define NUMPIXELS      50 // Nombre de pixels du bandeau
#define NUMPIXELSgrand      60
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

Adafruit_NeoPixel pixels1 = Adafruit_NeoPixel(NUMPIXELSgrand, PIN1, NEO_GRB + NEO_KHZ800);

Adafruit_NeoPixel pixels2 = Adafruit_NeoPixel(NUMPIXELS, PIN2, NEO_GRB + NEO_KHZ800);

 unsigned long previousMillis = 0;
  unsigned long previousMillis2 = 0;
  unsigned long previousMillis3 = 0;
  const unsigned long interval = 100;
  const unsigned long dpH = 35;
  const unsigned long tpgenere = 2000;

int b = NUMPIXELS-1;
int hauteur = 0;
int joysticky = A0;
int joystickx = A1;
void setup() {
  pixels.begin(); // Initialisation du bandeau
  pixels.setBrightness(50); // Param de la luminosité

  //on commence par afficher une LED

  pixels1.begin(); // Initialisation du bandeau
  pixels1.setBrightness(50); // Param de la luminosité

  //on commence par afficher une LED
  pixels1.setPixelColor(11, 255, 0, 0);
 
  pixels1.show(); // Affichage

  pixels2.begin(); // Initialisation du bandeau
  pixels2.setBrightness(50); // Param de la luminosité

  //on commence par afficher une LED
  pixels2.setPixelColor(11, 255, 0, 0);
 
  pixels2.show(); // Affichage

 /* pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);*/
  Serial.begin(9600);
 
}

void loop() {
  Serial.println(analogRead(joysticky));
    unsigned long currentMillis = millis();

  if(currentMillis - previousMillis3 >= tpgenere){
    previousMillis3 = currentMillis;


   
  }
genere();

  if(currentMillis - previousMillis >= interval){
    previousMillis = currentMillis;
    loop2();
   
  }
 

  if(currentMillis - previousMillis2 >= dpH){
    previousMillis2 = currentMillis;

  depH();
  }
  
  loop1();
  pixels.clear();
pixels2.clear();
pixels1.clear();
}

void genere(){
    if(b == -1){
  b=NUMPIXELS-1;
}
pixels.setPixelColor(b, 0, 255, 0);
pixels.show(); // Affichage
pixels2.setPixelColor(b, 0, 0, 255);
pixels2.show(); // Affichage

pixels1.setPixelColor(b, 150, 150, 200);
pixels1.show(); // Affichage
}

void loop2 () {
   

 b--;
pixels.clear();
pixels2.clear();
pixels1.clear();
   
}


void loop1(){    
  
  if (analogRead(joystickx) > 510){
   pixels1.setPixelColor(hauteur,255,0,0);
   
    pixels1.show();
}else if(analogRead(joystickx) < 500){
  pixels.setPixelColor(hauteur,255,0,0);
    pixels.show();
}else if(analogRead(joystickx) > 500 && analogRead(joystickx) < 510){
  pixels2.setPixelColor(hauteur,255,0,0);
    pixels2.show();
}


}


void depH(){

  if (analogRead(joysticky) > 510){
 if (hauteur >0 ){
  hauteur --;
 }
}else if(analogRead(joysticky) < 450 ){
 if(hauteur < NUMPIXELS-1){
  hauteur ++;
  }
 
}
   
}
