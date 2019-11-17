:- initialization main.

:- include('carta.pl').
:- include('utils.pl').

main:-
    iniciar_cartas(Cartas),
    random_permutation(Cartas, Cartas_Embaralhas),
    writeln(Cartas_Embaralhas).