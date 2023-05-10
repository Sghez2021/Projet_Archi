#include <Adafruit_NeoPixel.h>
#define PIN            5 // Pin de connexion du bandeau
#define PIN1  7
#define PIN2  6

#define NUMPIXELS      50 // Nombre de pixels du bandeau
#define NUMPIXELSgrand      60
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

Adafruit_NeoPixel pixels1 = Adafruit_NeoPixel(NUMPIXELSgrand, PIN1, NEO_GRB + NEO_KHZ800);

Adafruit_NeoPixel pixels2 = Adafruit_NeoPixel(NUMPIXELS, PIN2, NEO_GRB + NEO_KHZ800);
bool play = true;
 unsigned long previousMillis = 0;
  unsigned long previousMillis2 = 0;
  unsigned long previousMillis3 = 0;
  const unsigned long interval = 100;
  const unsigned long dpH = 60;
  const unsigned long tpgenere = 2000;
  const unsigned long vitesseone = 2000;
  const unsigned long vitessetwo =950;
  unsigned long vitessethree = 1015;
   unsigned long vitessegauche[] = {0,0,0,0,0};
   unsigned long vitessemillieu[] = {0,0,0,0,0};
     unsigned long vitessedroite[] = {0,0,0,0,0};
unsigned long previousmilis = 0;
   unsigned long previousMillisvitdeuxsec = 0;
   unsigned long previousMillisvit[] = {0,0,0,0,0};
  unsigned long previousMillisvit2[] = {0,0,0,0,0};
  unsigned long previousMillisvit3[] = {0,0,0,0,0};
int gauche[]= {-1,-2,-2,-2,-2};
int milieu[]={-1,-2,-2,-2,-2};
int droite[]={-1,-2,-2,-2,-2};
int u = 0;
int b = 0;
int a = 0;
int c = 0;
int hauteur = 0;
int joysticky = A0;
int joystickx = A1;
int score = 0;
int scored = 0;

void setup() {
  randomSeed(analogRead(A3));
  pixels.begin(); // Initialisation du bandeau
  pixels.setBrightness(50); // Param de la luminosité
  milieu[0]= NUMPIXELS-1;
  gauche[0]= NUMPIXELS-1;
  droite[0]= NUMPIXELS-1;
  vitessedroite[0]=random(200,1200);
  vitessemillieu[0]=random(200,1200);
  vitessegauche[0]=random(200,1200);
  pixels1.begin(); // Initialisation du bandeau
  pixels1.setBrightness(50); // Param de la luminosité
  pixels1.show(); // Affichage
  pixels2.begin(); // Initialisation du bandeau
  pixels2.setBrightness(50); // Param de la luminosité
  pixels2.show(); // Affichage
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial2.begin(9600);
}
long fonctionpoursolalouninou(){
  return random(200,800);
}
void envoi() {
  Serial1.println(score);
}

void loop() {
unsigned long currentMilliss = millis();

  
  if(play) {
    envoi();
  if(currentMilliss - previousmilis >= 1000){
  previousmilis = currentMilliss;
  score+=100;
  }
    loop3();
  }
}

void loop3() {
 //Serial.println(analogRead(joystickx));
 
 unsigned long currentMillis = millis();
// analogWrite(score,scored + (currentMillis* 0.002) );
genereSecond();
if (u<5) {
if(currentMillis - previousMillisvitdeuxsec >= 10000){
    previousMillisvitdeuxsec = currentMillis;
        u++;
vitessegauche[u]=random(200,1200);
vitessedroite[u]=random(200,1200);
vitessemillieu[u]=random(200,1200);

    gauche[u]=NUMPIXELS-1;
    milieu[u]=NUMPIXELS-1;
    droite[u]=NUMPIXELS-1;


  }
}




for(int i=0; i<=u; i++ ) {
   if(currentMillis - previousMillisvit2[i] >= (vitessegauche[i] - (currentMillis * 0.002))){
    previousMillisvit2[i] = currentMillis;
      gauche[i]= looptwo(gauche[i]);
    }
  }
for(int i=0; i<=u; i++ ) {
  if(currentMillis - previousMillisvit[i] >= (vitessemillieu[i]  - (currentMillis * 0.002))){
    previousMillisvit[i] = currentMillis;
      milieu[i]= looptwo(milieu[i]);
    }   
  }

for(int i=0; i<=u; i++ ) {
   if(currentMillis - previousMillisvit3[i] >= (vitessedroite[i] - (currentMillis * 0.002))){
    previousMillisvit3[i] = currentMillis;
      droite[i]= looptwo(droite[i]);
    }  
    }
 

  if(currentMillis - previousMillis2 >= dpH){
    previousMillis2 = currentMillis;

  depH();
  }
  // Serial.println(vitessedroite[0]);
  loop1();
  pixels.clear();
pixels2.clear();
pixels1.clear();
if((presentdans(gauche,hauteur) && analogRead(joystickx) < 500) || (presentdans(milieu,hauteur) && analogRead(joystickx) > 500 && analogRead(joystickx) < 515) || (presentdans(droite,hauteur) && analogRead(joystickx) > 515)) {
  play=false;
  score=0;
}
}




void genereSecond(){
  
    if(presentdans(gauche,-1)){
      a = ouca(gauche, -1);
  gauche[a]=NUMPIXELS-1;
  vitessegauche[a]=random(200,1200);}



    if(presentdans(milieu,-1)){
      b = ouca(milieu, -1);
  milieu[b]=NUMPIXELS-1;
  vitessemillieu[b]=random(200,1200);}




     if(presentdans(droite,-1)){
      c = ouca(droite, -1);
  droite[c]=NUMPIXELS-1;
  vitessedroite[c]=random(200,1200);}




for (int i=0; i<5; i++) {
pixels.setPixelColor(gauche[i], 0, 255, 0);
pixels.show(); // Affichage
pixels2.setPixelColor(milieu[i], 0, 0, 255);
pixels2.show(); // Affichage
pixels1.setPixelColor(droite[i], 150, 150, 200);
pixels1.show();
}
}




int looptwo(int e){  
    e--;
  pixels.clear();
pixels2.clear();
pixels1.clear();
return e;
}



void loop1(){    
  
if (analogRead(joystickx) > 515){
 pixels1.setPixelColor(hauteur,255,0,0);
 pixels1.show();    
}else if(analogRead(joystickx) < 500){
  pixels.setPixelColor(hauteur,255,0,0);
    pixels.show();
}else if(analogRead(joystickx) > 500 && analogRead(joystickx) < 515){
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
 
} }

bool presentdans(int list[], int val) {
  for(int i = 0; i < 5; i++) {
        if(list[i] == val) {
            return true;}
    }
    return false;
}

int ouca(int list[], int val){
  for(int i =0; i<sizeof(list); i++) {
    if (list[i]== val) {
      return i;
    }
  }
  return -1;  
}


void progression(){
   unsigned long currentMillis = millis();
}