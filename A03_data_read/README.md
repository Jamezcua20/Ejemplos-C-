# Programación en C: Lectura de Datos (`scanf`)

## ¿Cómo recibe órdenes el microcontrolador?

En las secciones anteriores aprendimos a enviar texto y variables hacia la pantalla usando `printf`. Pero una comunicación de verdad va en ambos sentidos. ¿Qué pasa si quieres que el usuario escriba la velocidad del motor por la terminal? ¿O el tiempo de parpadeo de un LED? 

En C++ usaban `cin >> variable;`, que era hasta sencillo porque detectaba el tipo de dato por sí solo. En C puro y embebido, volvemos a parte de la optimización, esta vez usaremos la herramienta: `scanf()`. Su trabajo es quedarse esperando a que la terminal mande datos, traducirlos y guardarlos en la memoria RAM del chip.

---
## El peligro de `scanf("");` (El error del Ampersand)

La sintaxis de `scanf` se parece a la de `printf`, pero tiene una una diferencia que podría hacer que su código termine crasheando por completo.

Para que `scanf` pueda guardar lo que el usuario teclea, necesita saber la **dirección exacta de memoria** donde vive la variable. No basta con pasarle el nombre de la variable; hay que incluir el símbolo **`&`**. (Más adelante les explicaré el tema de punteros)

Mírenlo de esta forma: `printf` solo necesita una copia del valor para mostrarlo, pero `scanf` necesita la dirección de la variable para ir a guardar el valor.

Ejemplo básico de uso:

```c
int numero;
printf("Digite un numero: ");
scanf("%d", &numero); // ¡OJO con el & antes de la variable

printf("El numero que digito es %d\n", numero);
```

---

## Recomendaciones

scanf es una función vieja y tiene sus mañas. Si no las conocen, muy seguramente van a pasar horas diciendo "pero si mi código está bien y no jala".

* _El espacio en blanco (Limpieza del Buffer)_: 

Cuando ustedes escriben un número en la consola (por ejemplo, 15) y presionan Enter, en la memoria de la consola se guarda el 15 y también el salto de línea \n.

Si abajo tienen un scanf que lee un carácter (char), ese scanf no va a esperar a que tecleen nada; se va a comer el \n que se quedó flotando en el buffer y se va a saltar la lectura.

La solución: Pongan un espacio en blanco dentro del formato del scanf antes del porciento (ejemplo: " %c"). Ese espacio le dice al micro: "Ignora los saltos de línea y espacios viejos, espérate a que escriban algo nuevo".

```c
char opcion;
printf("¿Desea continuar? (s/n): ");
scanf(" %c", &opcion);
```

* _Con arreglos de texto (Strings) NO se usa el &_

Hace rato les dije que a todo se le pone &, excepto a una cosa: los arreglos de caracteres (char[]). Como un arreglo en C ya es, por definición, una dirección de memoria apuntando al inicio de la cadena, si le ponen el & van a romper el compilador.

Además, el %s normal deja de leer en cuanto encuentra un espacio. Si escriben "Hola Mundo", solo va a guardar "Hola".

```c
char nombre[20];
printf("Escribe tu primer nombre: ");
scanf("%s", nombre); // SIN ampersand, porque ya es un arreglo
```

 _¿Por qué casi no se usa scanf en la industria?_

Porque scanf es inseguro. Si tu variable es un uint8_t (que solo aguanta hasta 255) y un wey llega y le mete 999999 en la terminal, scanf va a intentar meter ese número gigante a la fuerza, desbordando la memoria RAM y corrompiendo las variables de los lados. En proyectos reales de firmware, se procura leer byte por byte directamente desde el registro de la UART o al menos tener válidadas las entradas. Pero para las prácticas de la escuela, el scanf sirve perfectamente.

---

## RESUMEN DE LECTURA

Para que tengan su acordeón listo antes de empezar a programar la comunicación serial, aquí tienen la estructura de cómo se lee cada cosa:

```
===================================================================
         GUÍA RÁPIDA DE LECTURA CON <stdio.h>
===================================================================
* Quiero leer un número entero común (int):
  int valor;
  scanf("%d", &valor);

* Quiero leer un entero pequeño de 8 bits (uint8_t):
  uint8_t estado;
  scanf("%hhu", &estado);

* Quiero leer un voltaje o decimal (float):
  float sensor;
  scanf("%f", &sensor);

* Quiero leer una sola letra sin que se salte por el Enter anterior:
  char letra;
  scanf(" %c", &letra); // Nota el espacio antes del %

* Quiero leer una palabra completa (sin espacios):
  char palabra[15];
  scanf("%s", palabra); // Nota que este NO lleva &
===================================================================

```


> Redactado por: **Amezcua**