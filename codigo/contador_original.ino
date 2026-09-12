const int leds[] = {2, 4, 7, 8}; 
const int numLeds = 4;

void setup() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  for (int contador = 0; contador < 16; contador++) {
    mostrarBinario(contador);
    delay(1000);
  }
}

void mostrarBinario(int numero) {
  for (int i = 0; i < numLeds; i++) {
    int estadoBit = bitRead(numero, i);
    digitalWrite(leds[i], estadoBit);
  }
}
