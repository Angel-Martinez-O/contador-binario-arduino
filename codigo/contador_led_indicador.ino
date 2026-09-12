const int leds[] = {2, 4, 7, 8}; 
const int numLeds = 4;
int waitDelay = 500;
const int ledIndicador = 13;   // <-- quinto LED

void setup() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(ledIndicador, OUTPUT);   // <-- lo configuramos también
}

void loop() {
  for (int contador = 0; contador < 16; contador++) {
    mostrarBinario(contador);

    if (contador == 15) {
      digitalWrite(ledIndicador, HIGH);   // <-- se enciende en 15
    } else {
      digitalWrite(ledIndicador, LOW);    // <-- apagado en cualquier otro número
    }

    delay(waitDelay);
  }
}

void mostrarBinario(int numero) {
  for (int i = 0; i < numLeds; i++) {
    int estadoBit = bitRead(numero, i);
    digitalWrite(leds[i], estadoBit);
  }
}
