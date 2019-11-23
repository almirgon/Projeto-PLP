/* classe onde inicializaremos e mantemos a estrutura das cartas*/

build_carta(Nome,Tipo,Ataque,Vida,Num,carta(Nome,Tipo,Ataque,Vida,Num)).

get_nome(carta(Nome,_,_,_,_),Nome).
get_tipo(carta(_,Tipo,_,_,_),Tipo).
get_ataque(carta(_,_,Ataque,_,_),Ataque).
get_vida(carta(_,_,_,Vida,_),Vida).
get_num(carta(_,_,_,_,Num),Num).

toString(Carta):- get_nome(Carta, Nome_),string_concat('|Nome: ', Nome_, Nome),string_concat(Nome,' | ', NomeF),writeln(NomeF),
get_tipo(Carta, Tipo_),string_concat('|Tipo: ', Tipo_, Tipo),string_concat(Tipo,' | ' , TipoF),writeln(TipoF),
get_ataque(Carta, Ataque_),string_concat('|ATK : ', Ataque_, Ataque),string_concat(Ataque,'         | ' , AtaqueF),writeln(AtaqueF),
get_vida(Carta, Defesa_),string_concat('|DEF : ', Defesa_, Defesa),string_concat(Defesa,'         | ' , DefesaF),writeln(DefesaF),
get_num(Carta, Num_),string_concat('|NUM : ', Num_, Num),string_concat(Num,'         | ' , NumF),writeln(NumF).

get_carta(1, carta('Bulbasaur', 'GRASS', 30, 60, 1)).
get_carta(2, carta('Venusaur', 'GRASS', 50, 800, 2)).
get_carta(3, carta('Charmander', 'FIRE', 2, 50, 3)).
get_carta(4, carta('Charizard', 'FIRE', 70, 70, 4)).
get_carta(5, carta('Bulbasaur', 'GRASS', 38, 4, 5)).

printCarta(1):-
    writeln('                                          ▄▓▓▓                                        '),
    writeln('                                        ▐▓▓▓▓▌                                        '),
    writeln('                                        ▓▓▓▓▓                                         '),
    writeln('                                        ▓▓▓▓▓                                         '),
    writeln('                                        ▓▓▓▓                                          '),
    writeln('                                        ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▄▄       ▄▄▄▄▄▒▓▓▓▓▒            '),
    writeln('                                        ▄▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▀              '),
    writeln('                      ▄▄▄▓▓▓▓          ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▀▀▓▀▀▀▀▀                 '),
    writeln('               ▄▄▒▓▓▓▓▓▓▓▓▓▓          ▓▓▓▀▐▄▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌                        '),
    writeln('         ▄▄▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓ ▄▒▄▌     ▄▓▓▓  ▀ ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌                        '),
    writeln('     ▄▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓ ▓▓▓▓▓▓▓▄ ▐▒▒▀▓▓▄▄▓▓▓▓▓▓▀▓▓▓▓▀█▌▐▓▓                         '),
    writeln('    ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓ ▐▓▓▓▓▓▓▓▌░░░░▐▓▓▓▓▓▀▀▀▀▀▓▓▓▓▄  ▄▓▌                         '),
    writeln('     ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌  ▓▓▓▓▓▓▓▓░░░░▄▓▓▓▓▌░░░░░░░▀▓▓▓▓▓▀                          '),
    writeln('     ▐▓▓▓▓▓▓▓▓▓▓▓▀  ▓▓▓▓▌    ▓▓▓▓▓▓▓▓▒▓▓▓▓▓▓▓▌▓▓▓▓▓▄░▓▓▓▓▌░▓░ ▄▄▄▄▄                   '),
    writeln('      ▐▓▓▓▓▓▓▀      ▓▓▓▓    ▄▐▓▓▓▓▓▓▓▓▒▓▓▓▓▓▓▓▒▓▓▓▀▄▓▓▓▓▓░▌░▓▓▓▓▓▓▓▓▌                 '),
    writeln('       ▀▓▓▓▀       ▐▓▓▓▓▄▄▓▓▓▓▐▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▄▒▒▄▓▓▓▓▓▓▀▒▓▓▓▓▓▓▓▓▓                   '),
    writeln('        ▀          ▓▓▓▓▓▓▓▓▓▓   ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▀                     '),
    writeln('                   ▓▌▀   ▐▓▒    ▄▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌▀                        '),
    writeln('                         ░░░ ░░▄▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▀▀                             '),
    writeln('                         ░░░ ░▄▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                               '),
    writeln('                             ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                               '),
    writeln('                           ▄▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                              '),
    writeln('                          ▐▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌                            '),
    writeln('                          ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌                           '),
    writeln('                           ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░                           '),
    writeln('                           ▄▒▓▒▀▓▓▓▓▀▀▀▀▀   ░▒▓▓▓▓▓▓▓▓▓▓▓▀                            '),
    writeln('                         ░▒▌▀▀                     ░▒▓▓▓▓▓▒                           '),
    halt(0).