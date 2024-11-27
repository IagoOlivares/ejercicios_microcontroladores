int contador= 0;
unsigned long tiempoPrevio = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long tiempoActual = millis();

  if (tiempoActual - tiempoPrevio >= 1000){
    tiempoPrevio = tiempoActual;
    contador++;

    Serial.print("Contador: ");
    Serial.println(contador);
  }
}
