#include <Arduino.h>
#include <Nextion.h>
#include "declaraciones.h"
#include "funciones.h"

#define PinBusy 30
#define PinMicro A0
float lecturaMicro = 0;
const int sampleWindow = 50;
unsigned int sample;

unsigned int UmbralAmbiente;
float microfoPantalla;

int GaugeValue = 0;

void lecturaMicrofono();


void setup(){
  delay(500);   //Espera inicio Pantalla

  nexInit(115200);  //Puerto Nextion Serial 2 (16, 17 Tx, Rx)


  Serial.begin(9600);  // Puerto Depuración
  Serial.println("hola");
  pinMode(13, OUTPUT);

  Serial3.begin(9600); //Puerto comunicación módulo mp3 Serial 3 (14, 15 TX, Rx)
  delay(300);

  iniciarRadio();


  //registros asociados a aventos
  //Página 0
  page0.attachPush(page0PushCallback);

  //página 1 Menú
  page1.attachPush(page1PushCallback);

  //Página 2 Ajustes
  page2.attachPush(page2PushCallback);
  h0_2.attachPop(h0_2PopCallback);

  //página3 Reproductor
  page3.attachPush(page3PushCallback);
  h0_3.attachPop(h0_3PopCallback);
  b1_3.attachPop(b1_3PopCallBack);
  b2_3.attachPop(b2_3PopCallBack);
  b3_3.attachPop(b3_3PopCallBack);
  b4_3.attachPop(b4_3PopCallBack);
  b5_3.attachPop(b5_3PopCallBack);
  b6_3.attachPop(b6_3PopCallBack);
  b7_3.attachPop(b7_3PopCallBack);

  //Página4 Micrófono
  page4.attachPush(page4PushCallback);
}

void loop(){
  nexLoop(nex_listen_list);
  
  lecturaMicrofono();

  lecturaRadio();
}

//Lectura Micrófono
void lecturaMicrofono(){
  unsigned long startMillis = millis();
  float peakToPeak = 0;
  unsigned int signalMax = 0;
  unsigned int signalMin = 1024;

  while (millis() - startMillis < sampleWindow) {
    sample = analogRead(A0);
    if (sample < 1024) {
      if (sample > signalMax) {
        signalMax = sample;
      }
      else if (sample < signalMin) {
        signalMin = sample;
      }
    }
  }
  peakToPeak = signalMax - signalMin;
  double volts = ((peakToPeak * 3.3) /1024) * 0.707;
  double first = log10(volts/0.00631) * 20;
  double second = first + 94 - 44 - 25;
  //Serial.println(second);

  if(CurrentPage == 4){
    Serial2.print("n0.val=");
    Serial2.print(int(second));
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);

    //Evio al reloj
    GaugeValue = map(int(second), 22, 100, 0, 200);
    Serial2.print("va0.val=");
    Serial2.print(GaugeValue);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
  }
}