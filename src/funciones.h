#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <Arduino.h>
#include <Nextion.h>
#include <RF24.h>
#include <RF24Network.h>
#include <SPI.h>

uint32_t volumenRepro = 10;
uint32_t umbral = 0;

extern int CurrentPage = 0;

RF24 radio (8, 53); //CE, CSN
RF24Network red(radio);

const uint16_t control = 00;        //Direccion de este nodo Micro, pantalla
const uint16_t reproductor = 01;    //Direccion del módulo mp3
const uint16_t luces = 02;          //Dirección del módulo de luces

char data[6] = {1, 2, 3, 4, 5, 6};  //Buffer envio de datos por radio
byte parada = 255;
byte inicio = 33;

void envioRadio(char);

//Inicialización del sistema de Radio
void iniciarRadio(){
    SPI.begin();

    radio.begin();
    red.begin(90, control);
    radio.setDataRate(RF24_2MBPS);
}

//////////////////////////////////////////////////////////////////////
//Lectura y escritura RADIO
void lecturaRadio(){
  red.update();

  //====Receiving====//
  while(red.available()){
    unsigned long incomingData;
    RF24NetworkHeader header;
    red.read(header, &incomingData, sizeof(incomingData));
  } 
}

////FUNCIONES DE LLAMADAS A LOS ELEMENTOS DE LA PANTALLA/////////////
//página 0
void page0PushCallback(void *ptr)
{
    //Serial.println("entrando 0");
    CurrentPage = 0;
}

//Página 1 Menu
void page1PushCallback(void *ptr)
{
    //Serial.println("entrando 1");
    CurrentPage = 1;
}

//Página 2 Ajustes
void page2PushCallback(void *ptr)
{
    //Serial.println("Entrando 2");
    CurrentPage = 2;
}

void h0_2PopCallback(void *ptr)
{
    h0_2.getValue(&umbral);

    if(umbral == 0){
        h0_2.getValue(&umbral);
    }

    if(umbral == 0){
        h0_2.getValue(&umbral);
    }

    if(umbral == 0){
        h0_2.getValue(&umbral);
    }

    if(umbral == 0){
        h0_2.getValue(&umbral);
    }

    if(umbral == 0){
        h0_2.getValue(&umbral);
    }

    if(umbral == 0){
        h0_2.getValue(&umbral);
    }
}

//Pagina 3 Reproductor
void page3PushCallback(void *ptr)
{
    //Serial.println("entrando 3");
    CurrentPage = 3;
}

//Botones Reproductor
//Boton 1
void b1_3PopCallBack(void *ptr)
{   
    RF24NetworkHeader header2(reproductor);
    red.write(header2, &data[0], sizeof(data[0])); 
    Serial.println("boton1");   
}

//Botón 2
void b2_3PopCallBack(void *ptr)
{
    RF24NetworkHeader header2(reproductor);
    red.write(header2, &data[1], sizeof(data[1]));
    Serial.println("boton2");
    
}

//Botón 3
void b3_3PopCallBack(void *ptr)
{
    RF24NetworkHeader header2(reproductor);
    red.write(header2, &data[2], sizeof(data[2]));
    Serial.println("boton3");   
}

//Botón 4
void b4_3PopCallBack(void *ptr)
{
    RF24NetworkHeader header2(reproductor);
    red.write(header2, &data[3], sizeof(data[3]));
    Serial.println("boton4");
   
}

//Botón 5
void b5_3PopCallBack(void *ptr)
{
    RF24NetworkHeader header2(reproductor);
    red.write(header2, &data[4], sizeof(data[4]));
    Serial.println("boton5");
 
}

//Botón 6
void b6_3PopCallBack(void *ptr)
{
    RF24NetworkHeader header2(reproductor);
    red.write(header2, &data[5], sizeof(data[5]));
    Serial.println("boton6");
    
}

//Botón STOP
void b7_3PopCallBack(void *ptr)
{
    RF24NetworkHeader header2(reproductor);
    red.write(header2, &parada, sizeof(parada));
    Serial.println("STOP");
  
}

//////////////////////////////////////////////////
//Volumen Reproductor
void h0_3PopCallback(void *ptr)
{
    h0_3.getValue(&volumenRepro);

    if(volumenRepro == 0){
        h0_3.getValue(&volumenRepro);
    }

    if(volumenRepro == 0){
        h0_3.getValue(&volumenRepro);
    }

    if(volumenRepro == 0){
        h0_3.getValue(&volumenRepro);
    }

    if(volumenRepro == 0){
        h0_3.getValue(&volumenRepro);
    }

    if(volumenRepro == 0){
        h0_3.getValue(&volumenRepro);
    }

    if(volumenRepro == 0){
        h0_3.getValue(&volumenRepro);
    }

    if(volumenRepro == 0){
        h0_3.getValue(&volumenRepro);
    }

    if(volumenRepro == 0){
        h0_3.getValue(&volumenRepro);
    }
    RF24NetworkHeader header2(reproductor);
    red.write(header2, &volumenRepro, sizeof(volumenRepro));
}

//Página 4 Micrófono
void page4PushCallback(void *ptr){
    //Serial.println("entrando 4");
    CurrentPage = 4;
}

#endif
