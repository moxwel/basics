padre(maria, pedro).
padre(juan, pedro).
padre(juan, carola).
padre(pedro, ana).
padre(pedro, paty).
padre(paty, aldo).

% Si:
%     X es padre de "alguien"
% entonces:
%     X tiene hijo
tiene_hijo(X) :- padre(X, _).

% Si:
%     "alguien" es padre de X
% entonces:
%     X tiene padre
tiene_padre(X) :- padre(_, X).