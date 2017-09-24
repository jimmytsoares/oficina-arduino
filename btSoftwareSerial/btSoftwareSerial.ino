/*
 * @author Jimmy Soares
 * Conectar um LED no pino 5
 * Conectar o módulo HC-05 assim:
 *    Vcc - 5V
 *    GND - GND
 *    TXD - Pino 10
 *    RXD - Pino 11
 * ATENÇÃO!!!
 * DEIXAR O MÓDULO COM O VCC DESLIGADO
 * AO MANDAR AO FAZER UPLOAD DO PROGRAMA!
 * LIGAR APÓS O UPLOAD ESTIVER COMPLETO
 * Recomandado utilizar com o app
 * Bluetooth Terminal HC-05 para Android
 * https://play.google.com/store/apps/details?id=project.bluetoothterminal&hl=en
 *
 */
 
//biblioteca para simular comunicação serial em outros pinos
#include <SoftwareSerial.h>

SoftwareSerial myBt(10, 11); // RX, TX
char BluetoothData;
int ledpin =  9;

void setup() {
  myBt.begin(9600);
  pinMode(ledpin,OUTPUT); //ledpin como saída
}

void loop() {
   if (myBt.available()){ //se tiver algo para ler
      BluetoothData=myBt.read(); //le e guarda
      if(BluetoothData=='1'){   
          digitalWrite(ledpin,1);
          myBt.println("LED on!"); // vai imprimir no terminal do app
      }
      else if (BluetoothData=='0'){
          digitalWrite(ledpin,0);
          myBt.println("LED off!");
      }

  }
delay(100);
}
