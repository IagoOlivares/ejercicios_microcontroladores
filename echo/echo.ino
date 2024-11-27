void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Echo iniciado. Envía texto:");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    char letra = Serial.read(); 

    if (isUpperCase(letra)) {
      letra = toLowerCase(letra); 
    } else if (isLowerCase(letra)) {
      letra = toUpperCase(letra); 
    }

    Serial.print(letra);
  }
}

