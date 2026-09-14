Contador Binario de 4 Bits con Arduino
## 1. Descripción del proyecto

Para este parcial hice un contador binario de 4 bits usando Arduino. La idea es que con 4 LEDs se puedan representar todos los números del 0 al 15 en binario, prendiendo y apagando los LEDs según corresponda. Cada LED representa un bit, desde el menos importante hasta el más importante. Además del contador básico, hice 5 variaciones (retos) que le cambian la velocidad, el sentido de conteo, la forma en que avanza y le agregan un LED extra.

## 2. Materiales utilizados

- Arduino UNO (lo hice en simulación con Tinkercad)
- Protoboard
- 5 LEDs (4 para el contador y 1 que uso como indicador)
- 5 resistencias de 220 Ω
- 1 pulsador
- Cables jumper


## 3. Explicación del circuito

Cada uno de los 4 LEDs del contador va conectado a un pin digital (2, 4, 7 y 8) a través de una resistencia de 220 Ω, para que no les llegue demasiada corriente. El cátodo de cada LED (la pata corta) lo conecté a la línea negativa del protoboard, y esa línea la uní con un solo cable al GND del Arduino.

El pulsador lo conecté con una pata al pin 12 y la otra a la misma línea de GND. Usé `INPUT_PULLUP` en el código, así que no tuve que ponerle una resistencia aparte: cuando no está presionado el pin lee HIGH, y cuando lo presiono lee LOW.

El quinto LED (el indicador) lo conecté igual que los otros 4, con su resistencia y su cátodo a GND, pero al pin 13.

## 4. Funcionamiento del contador binario

Con 4 LEDs se pueden formar 16 combinaciones distintas (2 elevado a la 4), que son justo los números del 0 al 15. Cada LED vale una potencia de 2 (1, 2, 4 y 8), y combinando cuáles están prendidos y cuáles apagados se puede armar cualquier número binario de 4 bits. Por ejemplo:

Decimal  Binario  LEDs 
0       0000      Todos apagados 
1       0001      Solo el primero prendido 
2       0010      Solo el segundo prendido 
3       0011      Los dos primeros prendidos 
15      1111      Todos prendidos 

## 5. Explicación del código

- **`setup()`:** es lo primero que corre el programa, una sola vez. Ahí configuro los pines que voy a usar.
- **`loop()`:** es la parte que se repite todo el tiempo mientras el Arduino esté prendido, ahí va la lógica del contador.
- **`pinMode()`:** sirve para decirle a un pin si va a ser entrada o salida.
- **`digitalWrite()`:** con esto prendo o apago un LED, mandándole HIGH o LOW a un pin.
- **`digitalRead()`:** con esto leo si el botón está presionado o no.
- **`delay()`:** pausa el programa el tiempo que yo le diga, lo uso para controlar cada cuánto cambia el número.
- **Arreglos (`leds[]`):** los usé para guardar los 4 pines de los LEDs en una sola variable, así puedo recorrerlos con un ciclo en vez de escribir 4 líneas repetidas.
- **Ciclos `for`:** los uso para recorrer los 4 LEDs uno por uno.
- **Operador `%`:** es el residuo de una división. Lo pude usar para saber si un número es par (si el residuo de dividirlo entre 2 da 0).
- **Operadores bitwise (`bitRead`, `&`, `<<`):** estos me sirven para revisar bit por bit un número. `bitRead(numero, i)` me dice si el bit en la posición i es 0 o 1, y con eso decido si un LED va prendido o no.

## 6. Desarrollo de los cinco retos

### Reto 1 — Velocidad del contador
Tenía que hacer que el contador cambiara cada 500 ms, pero usando una variable en vez de escribir el número directo. Agregué `int waitDelay = 500;` y cambié el `delay(1000)` por `delay(waitDelay)`. Con eso el contador ahora cambia dos veces más rápido que antes.

### Reto 2 — Contador descendente
Tenía que hacer que contara al revés, de 15 a 0, y que al llegar a 0 volviera a empezar. Cambié el `for` para que empezara en 15, siguiera mientras fuera mayor o igual a 0, y en vez de sumar restara 1 (`contador--`). Como el `for` está dentro del `loop()`, cuando termina se repite solo y vuelve a arrancar desde 15.

### Reto 3 — Control mediante botón
Este fue el que más cambié. Ya no podía usar un `for` que avanzara solo, así que hice una variable `contador` normal que solo sube cuando detecto que se presionó el botón (comparando el estado actual contra el anterior, para que no sume de más si dejo el dedo apretado). Cuando pasa de 15 vuelve a 0.

### Reto 4 — Mostrar solamente números pares
Tenía que mostrar solo los pares (0, 2, 4... 14). En vez de sumar de 1 en 1 en el `for`, lo cambié para que sumara de 2 en 2 (`contador += 2`), así se salta directo los impares.

### Reto 5 — LED indicador
Tenía que agregar un quinto LED que se prendiera solo cuando el contador llegara a 15. Agregué el pin del nuevo LED, lo configuré como salida, y adentro del `loop()` puse un `if` que revisa: si el contador es 15, prende ese LED, si no, lo mantiene apagado.

## 7. Evidencias
<img width="401" height="494" alt="evidencia" src="https://github.com/user-attachments/assets/d0bebfa7-d4e6-49ab-a15d-37570c21523c" />

## 8. Evidencia audiovisual
En este video se muestra el funcionamiento del contador con los 5 retos: velocidad, descendente, botón, pares y LED indicador.
https://drive.google.com/file/d/105TUt32LofyveukB71ow3UjB8RhaiRLe/view?usp=drivesdk

