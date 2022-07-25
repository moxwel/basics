#lang scheme

; Funcion que calcule el cubo de un numero
(define cubo
  (lambda (n)
    (* n n n)
   )
 )



; Utilizar recursion de cola
(define sumar-cubos
  (lambda (lista)
    (let recursion
      ; Parametros
      ((l lista) ; Lista
       (suma 0) ; Guardar resultados
       )

      ; Funcion
      (if (null? l)
          ; Caso base: Si la lista esta vacia...
          ; ¿Que queremos retornar?
          ; Retornar la suma total
          suma 

          ; Si no es vacia...
          (recursion
            (rest l)                  ; l
            (+ suma (cubo (first l))) ; suma
           )
          ; Volver a aplicar la funcion, pero al resto de la lista
          ; Ademas, guardar en la variable 'suma' el valor del
          ; cubo del primer elemento de la lista.
       )
     )
   )
 )