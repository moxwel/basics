padre(maria, pedro).
padre(juan, pedro).
padre(juan, carola).
padre(pedro, ana).
padre(pedro, paty).
padre(paty, aldo).

% Si:
%     X es padre de Y
% entonces:
%     X es antepasado de Y
antepasado(X, Y) :- padre(X, Y).

% Si:
%     X es padre de Y
%     Y es antepasado de Z
% entonces:
%     X es antepasado de Z
antepasado(X, Z) :- padre(X, Y), antepasado(Y, Z).




