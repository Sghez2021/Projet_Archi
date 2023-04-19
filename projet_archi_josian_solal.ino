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
  
  const unsigned long vitesseone = 1000;
  const unsigned long vitessetwo =950;
  unsigned long vitessethree = 1015;


   unsigned long previousMillisvit = 0;
  unsigned long previousMillisvit2 = 0;
  unsigned long previousMillisvit3 = 0;

int b = NUMPIXELS-1;
int a = NUMPIXELS-1;
int c = NUMPIXELS-1;
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


  Serial.begin(9600);
 
}


void loop() {
  Serial.println(analogRead(joysticky));
    unsigned long currentMillis = millis();


   if(currentMillis - previousMillisvit2 >= vitessetwo){
    previousMillisvit2 = currentMillis;
      a= looptwo(a);
  }
genereSecond();

  if(currentMillis - previousMillisvit >= vitesseone){
    previousMillisvit = currentMillis;
   b=looptwo(b);
   
  }

   if(currentMillis - previousMillisvit3>= vitessethree){
    previousMillisvit3 = currentMillis;
  c=looptwo(c);
  }
 

  if(currentMillis - previousMillis2 >= dpH){
    previousMillis2 = currentMillis;

  depH();
  }
  
  loop1();
  pixels.clear();
pixels2.clear();
pixels1.clear();

if((hauteur == b && analogRead(joystickx) > 510) || (hauteur == c && analogRead(joystickx) > 500 && analogRead(joystickx) < 510) || (hauteur == a && analogRead(joystickx) < 500)) {
  exit(0);
}
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


void genereSecond(){
    if(b == -1  ){
  b=NUMPIXELS-1;

}

   if( a == -1 ){
  a=NUMPIXELS-1;
}


    if( c == -1){
  c=NUMPIXELS-1;
}
pixels.setPixelColor(b, 0, 255, 0);
pixels.show(); // Affichage
pixels2.setPixelColor(c, 0, 0, 255);
pixels2.show(); // Affichage

pixels1.setPixelColor(a, 150, 150, 200);
pixels1.show(); // Affichage
}

void loopone () {
   b--;

pixels.clear();
pixels2.clear();
pixels1.clear();
   
}

int looptwo(int e){  
    e--;
  pixels.clear();
pixels2.clear();
pixels1.clear();
return e;
}

void loopthree(){
  
    c--;  
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


void bandeauOne(){
  
}

void bandeauTwo(){
  
}

void bandeauThree(){
  
}

void progression(){
   unsigned long currentMillis = millis();
}