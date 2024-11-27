unsigned long millisPrevios = 0;
int intervalo = 1000;
bool funcionando = false;
bool modoFijo = true;
int ultimoValor = 1;
int valorActual = 1;

void setup() {
  Serial.begin(9600);
  Serial.println("Aplicación de Línea de Comandos:");
}

void loop() {
  if (Serial.available() > 0) {
    String comando = Serial.readStringUntil('\n'); 

    comando.trim();  
    comandos(comando);
  }

  if (funcionando) {
    unsigned long millisActuales = millis();

    if (millisActuales - millisPrevios >= intervalo) {
      millisPrevios = millisActuales;

      if (modoFijo) {
        Serial.println(ultimoValor); 
      } else {
        valorActual = (valorActual == 1) ? 0 : 1; 
        Serial.println(valorActual);
      }
    }
  }
}

void comandos(String comando) {
  if (comando == "H" || comando == "h") {
    ayuda();
  } 
  else if (comando == "START" || comando == "start") {
    if (funcionando == false) {
      funcionando = true;  
      Serial.println("Publicación iniciada.");
    }else {
      Serial.println("Ya estaba iniciada.");
    }
    
  }
  else if (comando == "STOP" || comando == "stop") {
    if (funcionando == true) {
      funcionando = false;
      Serial.println("Publicación detenida.");
    }else {
      Serial.println("Ya estaba detenida.");
    }
    
  }
  else if (comando == "T" || comando == "t") {
    cambiarIntervalo();
  }
  else if (comando == "M" || comando == "m") {
    cambiarModo();
  }
  else {
    Serial.println("Comando no reconocido. Escriba 'h' para ayuda.");
  }
}

void ayuda() {
  Serial.println("Menu de ayuda:");
  Serial.println("H o h (help): Muestra este menu de ayuda.");
  Serial.println("START o start: Inicia la publicación del valor cada segundo.");
  Serial.println("STOP o stop: Detiene la publicación del valor.");
  Serial.println("T o t (time): Cambia el periodo de publicación (1 a 10 veces por segundo).");
  Serial.println("M o m (mode): Cambia el modo de fijo a alternativo.");
  Serial.println("Modo Fijo: Siempre se publica el mismo valor.");
  Serial.println("Modo Alternativo: Se alterna entre 0 y 1.");
}

void cambiarIntervalo() {
  Serial.println("Ingrese el intervalo de publicación (1-10 veces por segundo): ");
  
  while (Serial.available() == 0) {}

  int nuevoIntervalo = Serial.parseInt();

  if (nuevoIntervalo >= 1 && nuevoIntervalo <= 10) {
    intervalo = 1000 / nuevoIntervalo; 
    Serial.print("Nuevo intervalo: ");
    Serial.print(nuevoIntervalo);
    Serial.println(" veces por segundo.");
  } else {
    Serial.println("Valor fuera de rango. Ingrese un número entre 1 y 10.");
  }
}

void cambiarModo() {
  modoFijo = !modoFijo;

  if (modoFijo) {
    Serial.println("Modo fijo activado. El valor siempre será 1.");
    ultimoValor = 1;
  } else {
    Serial.println("Modo alternativo activado. El valor alternará entre 0 y 1.");
  }
}
