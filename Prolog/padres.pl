% Hechos:

% padre(X, Y) -> X es padre de Y
padre(maria, pedro).
padre(juan, pedro).
padre(juan, carola).
padre(pedro, ana).
padre(pedro, paty).
padre(paty, aldo).

% fem(X) -> X es femenina
fem(maria).
fem(carola).
fem(ana).
fem(paty).

% msc(X) -> X es masculino
msc(juan).
msc(pedro).
msc(aldo).

% ----------

% Reglas:

% Si:
%     X es padre de Y
% entonces:
%     Y es hijo de X
hijo(Y, X) :- padre(X, Y).

% Si:
%     X es padre de Y
%     Y es padre de Z
% entonces:
%     X es abuelo de Z
abuelo(X, Z) :- padre(X, Y), padre(Y, Z).

% Si:
%     X es padre de Y
%     X es padre de Z
%     Y es diferente de Z
% entonces:
%     Y y Z son hermanos
hermano(Y, Z) :- padre(X, Y), padre(X, Z), diff(Y, Z).

% Si:
%     X es padre de Y
%     X es masculino
% entonces:
%     X es papa de Y
papa(X, Y) :- padre(X, Y), msc(X).

% Si:
%     X es padre de Y
%     X es femenina
% entonces:
%     X es mama de Y
mama(X, Y) :- padre(X, Y), fem(X).

% Si:
%     X es diferente de Y
% entonces:
%     X es diferente de Y
diff(X, Y) :- X \= Y.

