int cont1= 0;
int cont2 = 0;

unsigned long tPrevioCont1 = 0;
unsigned long tPrevioCont2 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long tActual = micros();

  if (tActual - tPrevioCont1 >= 100000){
      tPrevioCont1 = tActual;
      cont1++;

    Serial.print("C1: ");
    Serial.print(cont1);
    Serial.print(" C2: ");
    Serial.println(cont2);
  }

  if (tActual - tPrevioCont2 >= 2000000){
      tPrevioCont2 = tActual;
      cont2++;
      cont1 -= cont2;

    Serial.print("C1: ");
    Serial.print(cont1);
    Serial.print(" C2: ");
    Serial.println(cont2);
  }
}

