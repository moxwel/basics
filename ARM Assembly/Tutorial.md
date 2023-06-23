# Tutorial de ARM Assembly

Este tutorial esta basado en el libro [Introducción a la arquitectura de computadores con QtARMSim y Arduino](http://lorca.act.uji.es/libro/introARM/introARM_2020.pdf). Lo hice especificamente para usarse con el simulador [QtARMSim](https://pypi.org/project/qtarmsim/).

# Estructura basica

- Los comentarios de linea se hacen con `@`, y los de bloque con `/*...*/`.

- El codigo para ensamblar comienza en `.text` y termina en `.end`.

- La instruccion para detener el ensamblaje es `wfi` _(wait for interrupt)_ y debe estar antes de `.end`.

- Los literales comienzan con `#`. `#123` para numeros en decimal, `#0xFF` para hexadecimal, `#042` para octal, `#'A'` para caracteres ASCII.

```arm
.text

/* Codigo aqui... */

wfi
.end
```

# Registros

- Los registros se nombran con `r` seguido de un numero entre 0 y 15. `r0` es el registro 0, `r1` es el registro 1, etc.

  - Los registros `r0` a `r12` son de proposito general.

  - `r13` es el registro de pila (SP, _Stack Pointer_).<br>_Usado para guardar direccion de memoria de la RAM._

  - `r14` es el registro de enlace (LR, _Link Register_).<br>_Usado por la instruccion `bl` para guardar la direccion de retorno._

  - `r15` es el registro de programa (PC, _Program Counter_).<br>_Usado para guardar la direccion de la siguiente instruccion a ejecutar._

# Directivas

- `.data` define la seccion de datos para la RAM.

- `.text` define la seccion de codigo para la ROM.

- `.end` termina el ensamblaje.

## Constantes

Se pueden definir constantes dentro de la seccion `.data` con las directivas `.equ` y `.eqv`. Esto ayuda a definir literales con nombres. Por lo tanto, se debe usar `#` para referirse a la constante.

- `.equ` define una constante.

- `.eqv` define una constante **si no existe** (es mas seguro).

```arm
.data

.equ Lunes, 1    @ Lunes = 1
.equ Martes, 2   @ Martes = 2

.text

mov r0, #Lunes   @ r0 = 1
mov r1, #Martes  @ r1 = 2

/* Mas codigo... */

wfi
.end
```

## Datos en RAM

Se pueden definir datos en RAM dentro de la seccion `.data`.

- `.word` define una palabra de 32 bits.

- `.hword` define una palabra de 16 bits.

- `.byte` define un byte de 8 bits.

- `.asciz` define un string terminado en cero (usado para imprimir en el LCD).

Antes de compilar, el ensamblador guarda los datos en memoria RAM, y si dichas directivas poseen etiquetas, estas se reemplazan por la direccion de memoria donde se guardaron los datos. De esta forma, se puede acceder a los datos usando la etiqueta.

Para obtener la direccion de memoria de una etiqueta, se debe usar la instruccion `ldr` (load register), el registro donde guardar la direccion, y la etiqueta precedida por `=`.

```arm
              .data

mi_variable:  .word 0x1234

              .text

              ldr r0, =mi_variable  @ r0 = Dirección de memoria de 'mi_variable'

              ldr r0, [r0]          @ r0 = 0x1234

              wfi
              .end
```

# Firmware

En memoria 0x00190000 se encuentra el Firmware. Este posee varias subrutinas que permiten manipular el LCD, imprimir resutltados, etc.

Para usar las subrutinas, se debe usar la instruccion `bl` (branch and link) con el nombre de la subrutina o funcion, por ejemplo `bl printString`.

Los argumentos de las funciones se definen segun valores de los registros.

## Funciones

- **sdivide**: Divide dos numeros.

  - `r0`: el dividendo

  - `r1`: el divisor

> Luego de la division, el cociente se guarda en `r0` y el resto en `r1`, mientras que `r2` y `r3` quedan con valores intermedios.

```arm
.text

mov r0, #33
mov r1, #5

bl sdivide   @ Realizar division: 33 / 5

@ r0 ahora contiene 6 (cociente)
@ r1 ahora contiene 3 (resto)

wfi
.end
```

## LCD

El LCD posee 40 columnas y 6 filas, numeradas desde el 0.

- **printString**: Imprime una cadena de texto.

  - `r0` y `r1`: coordenada (columna, fila) donde comenzar a escribir.

  - `r2`: la dirección de memoria en RAM donde está almacenada la cadena a escribir. La cadena debe estar terminada en cero.

  > Luego de ejecutarse, en `r0` queda guardada la longitud del string impreso, mientras que `r1`, `r2` y `r3` quedan con valores intermedios.

  ```arm
              .data

  mi_string:  .asciz "Hola mundo"

              .text

              mov r0, #0
              mov r1, #0          @ Comenzar a escribir en (0,0)

              ldr r2, =mi_string  @ r2 = Direccion de memoria de 'mi_string'

              bl printString

              @ r0 ahora contiene 10 (longitud de 'Hola mundo')

              wfi
              .end
  ```

- **printInt**: Imprimir un numero por pantalla.

  - `r0` y `r1`: coordenada (columna, fila) donde comenzar a escribir.

  - `r2`: el numero a imprimir (se imprime en decimal).

  > Luego de ejecutarse, en `r0` queda guardada la longitud del string impreso, mientras que `r1`, `r2` y `r3` quedan con valores intermedios.

  ```arm
  .text

  mov r0, #0
  mov r1, #0    @ Comenzar a escribir en (0,0)

  mov r2, #0xF  @ r2 = 15

  bl printInt

  @ r0 ahora contiene 2 (longitud de '15')

  wfi
  .end
  ```

- **printf**: Imprime un string con formato.

  - `r0` y `r1`: coordenada (columna, fila) donde comenzar a escribir.

  - `r2`: la dirección de memoria en RAM donde está almacenada la cadena a escribir. La cadena debe estar terminada en cero.

  - `r3`: primer argumento de placeholder.

  - `r13` (`sp`): dirección en la RAM donde están los siguientes `n` placeholders.

  > Luego de ejecutarse, en `r0` queda guardada la longitud del string impreso, mientras que `r1`, `r2` y `r3` quedan con valores intermedios.

  > Los placeholders se definen con `%d` para enteros, `%s` para strings, `%x` para hexadecimales, etc.

  ```arm
              .data

  mi_string:  .asciz "Primero: %d, Segunudo: %d, Tercero %d"

              .text

              mov r0, #0
              mov r1, #0         @ Comenzar a escribir en (0,0)

              ldr r2, =mi_string @ r2 = Direccion de memoria de 'mi_string'

              mov r3, #11        @ Primer numero
              mov r4, #22        @ Segundo numero
              mov r5, #33        @ Tercer numero

              str r4, [sp]       @ Guardar segundo numero en la RAM (segun sp)
              str r5, [sp, #4]   @ Guardar tercer numero en la RAM (4 bytes despues)

              bl printf

              @ r0 ahora contiene 37 (longitud de 'Primero: 11, Segundo: 22, Tercero: 33')

              wfi
              .end
  ```
