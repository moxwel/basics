#lang scheme

; La funcion debe aplicar "dos funciones" sobre "un valor".

; Si "el valor" es IMPAR, entonces:
; se evaluara DOS VECES en la PRIMERA funcion, y al resultado, se le
; suma con lo obtenido al evaluar UNA VEZ con la SEGUNDA funcion.

; Si "el valor" es PAR, entonces:
; se evaluara DOS VECES en la SEGUNDA funcion, y al resultado, se le
; suma con lo obtenido al evaluar UNA VEZ con la PRIMERA funcion.

(define aplicar
  (lambda (func1 func2 valor)
    (if (odd? valor)
      ; Si el valor es IMPAR...
      (+ (func1 (func1 valor)) (func2 valor))

      ; Si no es IMPAR (es decir, es PAR)...
      (+ (func2 (func2 valor)) (func1 valor))
     )
   )
 )

(aplicar (lambda (x) (* x x)) (lambda (x) (* 2 x)) 3)
(aplicar (lambda (x) (* x x)) (lambda (x) (* 2 x)) 2)