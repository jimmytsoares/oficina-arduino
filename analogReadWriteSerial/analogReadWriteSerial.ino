/*
 * @author: Jimmy Soares
 * Conectar um potenciometro com os pinos de
 * 'fora' no 5V e no GND. O pino do meio no A0.
 * O potênciometro é um divisor de tensão que
 * irá variar o valor analógico lido em A0, 
 * variando a intensidade do LED da placa por
 * PWM.
 */
float x;
int y;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT); //LED_BUILTIN = pino 13
  Serial.begin(9600); //inicia o monitor serial
}

void loop() {
  x = analogRead(A0); //x recebe o valor analógico lido em A0
  x = x/1023; //divide por 1023 para ter valor de 0 a 1
  y = x*255; //multiplica por 255 para o PWM (que aceita de 0 a 255)
  Serial.print(x*100); //imprime x
  Serial.print("% Duty Cycle = analogWrite ");
  Serial.println(y); //imprime y e pula linha
  analogWrite(LED_BUILTIN, y); //saída PWM no pino 13
}