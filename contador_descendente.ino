const int leds[] = {2, 4, 7, 8}; 
const int numLeds = 4;
int waitDelay = 500;

void setup() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  for (int contador = 15; contador >= 0; contador--) {
    mostrarBinario(contador);
    delay(waitDelay);
  }
}

void mostrarBinario(int numero) {
  for (int i = 0; i < numLeds; i++) {
    int estadoBit = bitRead(numero, i);
    digitalWrite(leds[i], estadoBit);
  }
}