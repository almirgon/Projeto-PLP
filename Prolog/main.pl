:- initialization main.

:- include('carta.pl').

selecionaCarta(X) :- random(1, 6, X).

insere(X, L, [X|L]).

deck(1, X):- random(1,6,Y), get_carta(Y,X).
deck(A, L):- A > 1, random(1,6,Y), get_carta(Y,C), B is A-1, deck(B, P), insere(C, P, L).

ataque(CartaAtaque, CartaDefesa, CartaResultado):-
    get_ataque(CartaAtaque, AtaqueCarta),
    get_vida(CartaDefesa, VidaCarta),
    VidaResultante is (VidaCarta - AtaqueCarta),
    get_nome(CartaDefesa, Nome),
    get_tipo(CartaDefesa, Tipo),
    get_ataque(CartaDefesa, Ataque),
    get_num(CartaDefesa, Numero),
    build_carta(Nome,Tipo,Ataque,VidaResultante,Numero,CartaResultado).

main :-
    selecionaCarta(Z),
    selecionaCarta(Y),
    get_carta(Y, R),
    get_carta(Z, R2),
    ataque(R, R2, CartaResult),
    toString(R),
    toString(R2),
    toString(CartaResult),
    halt(0).