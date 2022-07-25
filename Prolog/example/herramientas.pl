% Si 'S' es una sublista de 'L':

% Deben existir dos listas L1 y L2 tal que al concatenarlas se forme L.
% Y con la sublista S que estamos verificando, se deberia concatenar con
% otra sublista L3, de tal forma que forma L2.

sublist(S, L) :- append(L1, L2, L), append(S, L3, L2).





% Permutar los elementos de una lista.
% permutation(<Lista>, <Resutlado>)

permutation([], []).
permutation([X|Rest], L) :-
    permute(Rest, L1),
    select(X, L, L1).





% Maximo comun divisor
% mcd(<Numero>, <Numero>, <Resultado>)

% El maximo comun divisor entre dos numeros iguales, es el mismo numero.
mcd(X, X, X).

% Si Y es mayor que X, se resta Y-X, y se evalua nuevamente el MCD con el nuevo Y.
mcd(X, Y, D) :-
	X < Y,
	Y1 is Y - X,
	mcd(X, Y1, D).

% Si X es mayor a Y, se evalua MCD con los valores intercambiados.
mcd(X, Y, D) :-
	Y < X,
	mcd(Y, X, D).