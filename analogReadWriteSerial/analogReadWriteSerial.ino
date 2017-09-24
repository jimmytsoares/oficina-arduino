/*
 * @author: Jimmy Soares
 * Conectar um potenciometro com os pinos de
 * 'fora' no 5V e no GND. O pino do meio no A0.
 * O potênciometro é um divisor de tensão que
 * irá variar o valor analógico lido em A0, 
 * variando a intensidade do LED por
 * PWM.
 */
float x;
int y;
int ledPin = 9;
void setup() {
  pinMode(ledPin, OUTPUT); 
  Serial.begin(9600); //inicia o monitor serial
}

void loop() {
  x = analogRead(A0); //x recebe o valor analógico lido em A0
  x = x/1023; //divide por 1023 para ter valor de 0 a 1
  y = x*255; //multiplica por 255 para o PWM (que aceita de 0 a 255)
  Serial.print("Entrada de ");
  Serial.print(x*5); //imprime tensão entrada
  Serial.print(" gera ");
  Serial.print(x*100); //imprime % do duty cycle
  Serial.print("% Duty Cycle = analogWrite ");
  Serial.println(y); //imprime y e pula linha
  analogWrite(ledPin, y); //saída PWM no pino 13
}
