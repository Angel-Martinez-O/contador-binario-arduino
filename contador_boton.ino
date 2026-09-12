const int leds[] = {2, 4, 7, 8}; 
const int numLeds = 4;
const int boton = 12;

int contador = 0;
int estadoAnteriorBoton = HIGH;   // con INPUT_PULLUP, sin presionar = HIGH

void setup() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(boton, INPUT_PULLUP);   // no necesita resistencia externa
  mostrarBinario(contador);       // muestra el 0 inicial
}

void loop() {
  int estadoActualBoton = digitalRead(boton);

  // Detecta el momento exacto en que se presiona (pasa de HIGH a LOW)
  if (estadoActualBoton == LOW && estadoAnteriorBoton == HIGH) {
    contador++;
    if (contador > 15) {
      contador = 0;   // si se pasa de 15, reinicia en 0
    }
    mostrarBinario(contador);
    delay(50);   // pequeña pausa para evitar rebote del botón
  }

  estadoAnteriorBoton = estadoActualBoton;
}

void mostrarBinario(int numero) {
  for (int i = 0; i < numLeds; i++) {
    int estadoBit = bitRead(numero, i);
    digitalWrite(leds[i], estadoBit);
  }
}