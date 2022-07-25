#lang scheme

; Para conveniencia, este sera el arbol que usaremos para experimentar
; (nodo hizo-izq hizo-der)
(define mi-arbol
  '(28 (16 (5 () (12 () ())) (19 (17 () ()) (21 () ()))) (30 (29 () ()) (32 () ())))
 )



; Para obtener el valor del nodo
(define valor
  (lambda (nodo)
    (if (null? nodo)
      ; Si la lista esta vacia...
      '()

      ; Si no...
      (first nodo)
      ; (   >[ nodo ]<   hijo-izq   hijo-der  )
     )
   )
 )



; Para obtener el nodo derecho
(define der
  (lambda (nodo)
    (if (null? nodo)
      ; Si la lista esta vacia...
      '()

      ; Si no...
      (first (rest (rest nodo)))
      ; (  nodo [  hijo-izq  >[ hijo-der ]<  ]  )
     )
   )
 )



; Para obtener el nodo izquierdo
(define izq
  (lambda (nodo)
    (if (null? nodo)
      ; Si la lista esta vacia...
      '()
       
      ; Si no...
      (first (rest nodo))
      ; (  nodo [  >[ hijo-izq ]<  hijo-der  ]  )
     )
   )
 )



; Funcion principal (con recursion simple)
(define in-order
  (lambda (arbol)
    (if (null? arbol)
      ; Caso base: si el arbol esta vacio, terminar
      '()

      ; Si aun nos queda por recorrer...
      (append
        ; Hay que concatenar las listas que se nos generaran.
        (in-order (izq arbol)) ; Recorrer el subarbol izquierdo en in-orden
        (list (valor arbol))   ; Visitar nodo. Obtener valor
        (in-order (der arbol)) ; Recorrer el subarbol derecho en in-orden
       )
     )
   )
 )