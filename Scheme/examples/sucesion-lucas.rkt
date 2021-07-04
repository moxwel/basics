#lang scheme

; Utilizando recursion simple
(define lucas-simple
  (lambda (numero)
    (cond
      ; Si el numero ingresado es 0, retorna 2
      ((= numero 0)
       2
       )

      ; Si el numero ingresado es 1, retorna 1
      ((= numero 1)
       1
       )

      ; Si el numero ingresado es mayor a 1, entonces se llama
      ; a la sucesion de forma recursiva:
      ((> numero 1)
       (+ (lucas-simple (- numero 1)) (lucas-simple (- numero 2)))
       )

      ; Si el numero es negativo, entonces que retorne 0
      (else
       0
       )
     )
   )
 )



; Utilizando recursion de cola
(define lucas-cola
  (lambda (numero)
    (cond
      ; Si el numero ingresado es 0, retorna 2
      ((= numero 0)
       2
       )

      ; Si el numero ingresado es 1, retorna 1
      ((= numero 1)
       1
       )

      ; Si el numero ingresado es mayor a 1, entonces se llama
      ; a la sucesion de forma recursiva.
      ; Pero como es de cola, vamos a definir un procedimiento
      ((> numero 1)

        (let recursion
          ; Parametros
          ((n numero) ; 'n' sera el numero que se ingresa
           (n0 2)
           (n1 1)
           (result 0) ; Aqui vamos a guardar el resultado
           )

          ; Funcion
          (if (= n 1)
            ; Caso base: n es igual a 1
            ; ¿Que queremos retornar?
            ; Retornamos el resultado
            result
            
            ; Si no, paso recursivo:
            (recursion
              (- n 1)   ; n
              n1        ; n0
              (+ n0 n1) ; n1
              (+ n0 n1) ; result
             )
           )
         )
       )

      ; Si el numero es negativo, entonces que retorne 0
      (else
       0
       )
     )
   )
 )



; Notese la velocidad al intentar ejecutar ambas funciones.