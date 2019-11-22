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

inicializa :-
    deck(5,Deck1),
    deck(5,Deck2),
    writeln(Deck1),
    writeln(Deck2).

imprimeCartas([],_,"").
imprimeCartas([H|T], N, Resultado):-
    N == 0, Resultado is string_concat('         ', imprimeAtributos(H|T, 0, Y), Resultado0), string_concat(Resultado0, '-\n', Resultado1), string_concat(Resultado1, imprimeCartas([H|T], 1, X), Resultado2),
    N == 1, Resultado is string_concat('         ', imprimeAtributos(H|T, 1, Y), Resultado3), string_concat(Resultado3, '|\n', Resultado4), string_concat(Resultado4, imprimeCartas([H|T], 2, X), Resultado5),
    N == 2, Resultado is string_concat('         ', imprimeAtributos(H|T, 2, Y), Resultado6), string_concat(Resultado6, '|\n', Resultado7), string_concat(Resultado7, imprimeCartas([H|T], 3, X), Resultado8),
    N == 3, Resultado is string_concat('         ', imprimeAtributos(H|T, 3, Y), Resultado9), string_concat(Resultado9, '|\n', Resultado10), string_concat(Resultado10, imprimeCartas([H|T], 4, X), Resultado11),
    N == 4, Resultado is string_concat('         ', imprimeAtributos(H|T, 4, Y), Resultado12), string_concat(Resultado12, '|\n', Resultado13), string_concat(Resultado13, imprimeCartas([H|T], 5, X), Resultado14),
    N == 5, Resultado is string_concat('         ', imprimeAtributos(H|T, 5, Y), Resultado15), string_concat(Resultado15, '|\n', Resultado16), string_concat(Resultado16, imprimeCartas([H|T], 6, X), Resultado17),
    N == 6, Resultado is string_concat('         ', imprimeAtributos(H|T, 6, Y), Resultado18), string_concat(Resultado18, '-').

imprimeAtributos([],_,"").
imprimeAtributos([H|T], N, Resultado):-
    N == 0, Resultado is string_concat('-----------------', imprimeAtributos(T, 0, X),
    N == 1, Resultado is get_nome(H, Nome_),string_concat('|Nome: ', Nome_, Nome),string_concat(Nome,' | ', NomeF),writeln(NomeF), imprimeAtributos(T, 1, X),
    N == 2, Resultado is get_tipo(H, Tipo_),string_concat('|Tipo: ', Tipo_, Tipo),string_concat(Tipo,' | ' , TipoF),writeln(TipoF), imprimeAtributos(T, 2, X),
    N == 3, Resultado is get_ataque(H, Ataque_),string_concat('|ATK : ', Ataque_, Ataque),string_concat(Ataque,'         | ' , AtaqueF),writeln(AtaqueF), imprimeAtributos(T, 3, X),
    N == 4, Resultado is get_vida(H, Defesa_),string_concat('|DEF : ', Defesa_, Defesa),string_concat(Defesa,'         | ' , DefesaF),writeln(DefesaF),imprimeAtributos(T, 4, X),
    N == 5, Resultado is get_num(H, Num_),string_concat('|NUM : ', Num_, Num),string_concat(Num,'         | ' , NumF),writeln(NumF), imprimeAtributos(T, 5, X),
    N == 6, Resultado is string_concat('-----------------', imprimeAtributos(T, 6, X).

% jogo(a, [], c, '1 ganhou').
% jogo([], b, c, '2 ganhou').
% jogo(Deck1, Deck2, Num, String):-
%     X is mod(Num,2), X==0,
%     shell(clear),
%     write('\n -------------------------------------------VS------------------------------------------- \n'),
%     writeln('Player 1 ATK / Player 2 DEF'),
%     writeln('PLAYER 1| [NUM] Selecione uma carta: '),
%     read(CartaAtaca),
%     writeln('PLAYER 2| [NUM] Selecione uma carta: '),
%     read(CartaDefende),

% menuOpcao(1):- setup(1).
% menuOpcao(2):- selecionaModo().

creditos():-
    shell(clear),
    writeln('DESENVOLVIDO POR: '),
    writeln('Pablwo Araujo'),
    writeln('Natan Ataide'), 
    writeln('Luiz Boas'), 
    writeln('Almir Crispiniano'), 
    writeln('Walisson Farias'),
    read(Saida),
    menuOpcao(5).

instrucoes():-
    shell(clear),
    writeln('INSTRUÇOES:                                                                                           '), 
    writeln('                                                                                                      '), 
    writeln('CADA JOGADOR INICIA COM 5 CARTAS, ESSAS CARTAS SAO ESCOLHIDAS ALEATORIAMENTE DE UM DECK COM 34 CARTAS '), 
    writeln('DIFERENTES, APOS A FORMACAO DOS DERKS DE CADA JOGADOR, O JOGO E INICIADO E O PLAYER 1 SELECIONA       '), 
    writeln('UMA CARTA DISPONIVEL EM SUA MAO A PARTIR DO [NUM] PARA ATACAR O OPONENTE, QUE PODE SER O PLAYER 2 OU  '), 
    writeln('O COMP QUE POR SUA VEZ FAZ O MESMO PROCESSO ESCOLHENDO A CARTA PARA RECEBER O ATAQUE. DANDO INICIO    '), 
    writeln('A BATTLE FASE, CADA POKEMON TEM UM [TIPO] ASSOCIADO QUE INTERFERE DIRETAMENTE NO ATAQUE, UMA VEZ QUE  '), 
    writeln('CERTOS TIPOS TEM VANTAGENS SOBRE OUTROS, FAZENDO COM QUE O [ATK] DA CARTA TENHA UM BUFFER ADCIONAL,   '), 
    writeln('ALEM DAS CARTAS O ATAQUE PARA SER EFETIVADO DEPENDE DA SORTE DE CADA JOGADOR, O POKEMON A RECEBER     '), 
    writeln('O ATAQUE TEM 50% DE CHANCE DE DESVIAR. NO FINAL DA BATTLE FASE SE A CARTA TIVER SOFRIDO UM DANO QUE   '), 
    writeln('REDUZA SEU HP A 0, A CARTA É REMOVIDA DO JOGO. GANHA QUEM ELEMINAR TODAS AS CARTAS DE SEU OPONENTE.   '), 
    writeln('                                                                                                      '), 
    writeln('|----------------------------------------------------------------------------------------------------|'), 
    writeln('|                                    VANTAGENS D0 TIPO D0 POKEMON:                                   |'),
    writeln('|----------------------------------------------------------------------------------------------------|'), 
    writeln('|                  TIPO                          |                       VANTAGENS                   |'), 
    writeln('|------------------------------------------------|---------------------------------------------------|'), 
    writeln('|                 GRASS                          |            WATER, ELETRIC, GROUND, GRASS          |'), 
    writeln('|                 WATER                          |                  FIRE, GROND, WATER               |'), 
    writeln('|                 FAIRY                          |                         BUG                       |'), 
    writeln('|                 POISON                         |                  FAIRY, GRASS, BUG                |'), 
    writeln('|                 BUG                            |                PSYCHIC, GRASS, GROUND             |'), 
    writeln('|                 PSYCHIC                        |                        POISON                     |'), 
    writeln('|                 ELETRIC                        |                      FLY, WATER                   |'), 
    writeln('|                 GROUND                         |            FIRE, NORMAL, FLY, POISON, BUG         |'), 
    writeln('|                 FLY                            |                       BUG, GRASS                  |'), 
    writeln('|                 FIRE                           |                    FIRE, BUG, GRASS               |'), 
    writeln('|                 NORMAL                         |                    NENHUMA VANTAGEM               |'), 
    writeln('|----------------------------------------------------------------------------------------------------|'), 
    read(Saida),
    menuOpcao(5).

menuOpcao(2):- selecionaModo().
menuOpcao(3):- instrucoes().
menuOpcao(4):- creditos().
menuOpcao(_):-
    shell(clear),
    writeln('----------------------------------------------------------------------------------'),
    writeln('[1] - INICIAR JOGO '),
    writeln('[2] - MODO DE JOGO '),
    writeln('[3] - INSTRUCOES   '),
    writeln('[4] - CREDITOS     '), 
    writeln('----------------------------------------------------------------------------------'),
    read(Opcao),
    menuOpcao(Opcao).


main:-
    menuOpcao(5).