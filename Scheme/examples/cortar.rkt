#lang scheme

(define cortar
  (lambda (n lista)  ; 'n' sera el numero a verificar en la lista
    (let recursion
      ; Parametros
      ((l lista)     ; Lista que se va a analizar
       (menores '()) ; Lista de numeros menores
       (iguales '()) ; Lista de numeros iguales
       (mayores '()) ; Lista de numeros mayores
       )
      ; En esas 3 ultimas listas, vamos a ir guardando los numeros correspondientes

      
      (if (null? l)
        ; Caso base: Lista analizable nula
        ; Que queremos retornar?
        ; Una lista con las 3 sublistas correspondientes
        (append
          (list menores)
          (list iguales)
          (list mayores)
         )
        
        ; Si no es vacia, hay que seguir explorando
        ; Hay que ver los valores de las listas y
        ; clasificarlos
        (cond
          
          ; El primer elemento de la lista es menor al numero dado a la funcion
          ((< (first l) n)
            ; Llamar a la recursion, añadiendo el numero a la lista 'menores'
            ; y continuar analizando el resto de la lista
            (recursion
              (rest l) ; l
              (append menores (list (first l))) ; menores
              iguales ; iguales
              mayores ; mayores
             )  
           )


          
          ; El primer elemento de la lista es igual al numero dado a la funcion
          ((= (first l) n)
           
            ; Llamar a la recursion, añadiendo el numero a la lista 'iguales'
            ; y continuar analizando el resto de la lista
            (recursion
              (rest l) ; l
              menores ; menores
              (append iguales (list (first l))) ; iguales
              mayores ; mayores
             )
           )


          
          ; El primer elemento de la lista es mayor al numero dado a la funcion
          ((> (first l) n)
            ; Llamar a la recursion, añadiendo el numero a la lista 'mayores'
            ; y continuar analizando el resto de la lista
            (recursion
              (rest l) ; l
              menores ; menores
              iguales ; iguales
              (append mayores (list (first l))) ; mayores
             )
           )
         )
       )
     )
   )
 )

(cortar 6 '(1 2 4 6 4 8 6 2 1 7 4 5 1))
(cortar 2 '(1 2 4 6 4 8 6 2 1 7 4 5 1))
(cortar 4 '(1 2 4 6 4 8 6 2 1 7 4 5 1))
(cortar 1 '(1 2 4 6 4 8 6 2 1 7 4 5 1))
(cortar 5 '(1 2 4 6 4 8 6 2 1 7 4 5 1))
