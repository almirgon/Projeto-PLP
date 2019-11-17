:- include('carta.pl').

iniciar_cartas(Cards) :-
    open('pokemon.txt', read, Str),
    read_file(Str,Cartas),
    random(0,32,Index_Trunfo),
    map(Index_Trunfo,map_card,Cartas,Cards),
    close(Str). 
    
map(Index,FunctionName,[H|T],[NH|NT]):-
   Function=..[FunctionName,H,NH],
   call(Function),
   map(Index,FunctionName,T,NT).
map(_,_,[],[]).

read_file(Stream,[]) :-
    at_end_of_stream(Stream).

read_file(Stream,[X|L]) :-
    \+ at_end_of_stream(Stream),
    read_line_to_string(Stream, String),
    atomic_list_concat(X,' ', String),
    read_file(Stream,L), !.

map_card(List_String,Card) :-
        nth0(0, List_String, String),
        split_string(String, ',', ',', List),
        nth0(0, List, Tipo),
        nth0(1, List, Nome),
        nth0(2, List, Ataque),
        nth0(3, List, Vida),
        nth0(4, List, Num),
        build_carta(Tipo,Nome,Ataque,Vida,Num,Card).