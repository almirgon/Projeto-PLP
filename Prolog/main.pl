:- initialization main.

:- include('carta.pl').
:- dynamic jogoSingle/3.

selecionaCarta(X) :- random(1, 6, X).

insere(X, L, [X|L]).

parse_lista(X, Y):- insere(X, [], Y). 

deck(1, X):- random(1,6,Y), get_carta(Y,W), parse_lista(W, X).
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

imprimeCartas([],_,"").
imprimeCartas([H|T], 0, Resultado):- 
    imprimeAtributos([H|T], 0, R1), string_concat(R1, '- \n', R2),imprimeCartas([H|T], 1, R3), string_concat(R2, R3, Resultado).
imprimeCartas([H|T], 1, Resultado):-
    imprimeAtributos([H|T], 1, R1), string_concat(R1, '| \n', R2),imprimeCartas([H|T], 2, R3), string_concat(R2, R3, Resultado).
imprimeCartas([H|T], 2, Resultado):-
    imprimeAtributos([H|T], 2, R1), string_concat(R1, '| \n', R2), imprimeCartas([H|T], 3, R3), string_concat(R2, R3, Resultado).
imprimeCartas([H|T], 3, Resultado):-
    imprimeAtributos([H|T], 3, R1), string_concat(R1, '| \n', R2), imprimeCartas([H|T], 4, R3), string_concat(R2, R3, Resultado).
imprimeCartas([H|T], 4, Resultado):-
    imprimeAtributos([H|T], 4, R1), string_concat(R1, '| \n', R2), imprimeCartas([H|T], 5, R3), string_concat(R2, R3, Resultado).
imprimeCartas([H|T], 5, Resultado):-
    imprimeAtributos([H|T], 5, R1), string_concat(R1, '| \n', R2), imprimeCartas([H|T], 6, R3), string_concat(R2, R3, Resultado).
imprimeCartas([H|T], 6, Resultado):-
    imprimeAtributos([H|T], 6, R1), string_concat(R1, '-', Resultado).

setaPreencher(String, Resultado):-atom_length(String, Length), preencheLacunas(String, Length, Resultado).

preencheLacunas(String, 17, String).
preencheLacunas(String, Len, Saida):- string_concat(String,' ', X), NewLen is Len+1,preencheLacunas(X,NewLen, Saida).

imprimeAtributos([],_,"").
imprimeAtributos([H|T], 0, Resultado):-
    imprimeAtributos(T,0,R1), string_concat('-----------------', R1, Resultado).
imprimeAtributos([H|T], 1, Resultado):- 
    get_nome(H,Nome), string_concat('|Nome: ', Nome, Concatenacao), setaPreencher(Concatenacao, Y), imprimeAtributos(T, 1, R1), string_concat(Y, R1, Resultado).
imprimeAtributos([H|T], 2, Resultado):- 
    get_tipo(H,Nome), string_concat('|Tipo: ', Nome, Concatenacao), setaPreencher(Concatenacao, Y), imprimeAtributos(T, 2, R1), string_concat(Y, R1, Resultado).
imprimeAtributos([H|T], 3, Resultado):- 
    get_ataque(H,Nome), string_concat('|ATK : ', Nome, Concatenacao), setaPreencher(Concatenacao, Y), imprimeAtributos(T, 3, R1), string_concat(Y, R1, Resultado).
imprimeAtributos([H|T], 4, Resultado):- 
    get_vida(H,Nome), string_concat('|DEF : ', Nome, Concatenacao), setaPreencher(Concatenacao, Y), imprimeAtributos(T, 4, R1), string_concat(Y, R1, Resultado).
imprimeAtributos([H|T], 5, Resultado):- 
    get_num(H,Nome), string_concat('|NUM : ', Nome, Concatenacao), setaPreencher(Concatenacao, Y), imprimeAtributos(T, 5, R1), string_concat(Y, R1, Resultado).
imprimeAtributos([H|T], 6, Resultado):- 
    imprimeAtributos(T,6,R1), string_concat('-----------------', R1, Resultado).

% isso eu sei que funfa
duplica(X, X).

% isso eu sei que funfa
pegaCarta([], _, "").
pegaCarta([H|T], Num, Carta):-
    (get_num(H, X), X=:=Num-> duplica(H, Carta);
    pegaCarta(T, Num, Carta)).
    

% carta(Venusaur,GRASS,50,800,2)
% [carta(Bulbasaur,GRASS,38,4,54241),carta(Bulbasaur,GRASS,30,60,1),carta(Bulbasaur,GRASS,30,60,1),carta(Charizard,FIRE,70,70,4),carta(Venusaur,GRASS,50,800,2)]
% carta(Venusaur,GRASS,50,400,2)
% atualizaArray([carta(Bulbasaur,GRASS,38,4,54241),carta(Bulbasaur,GRASS,30,60,1),carta(Bulbasaur,GRASS,30,60,1),carta(Charizard,FIRE,70,70,4),carta(Venusaur,GRASS,50,800,2)],carta(Venusaur,GRASS,50,800,2),carta(Venusaur,GRASS,50,400,2),[], C).
%
atualizaArray([],_,_,_,B,C):-duplica(B,C).
atualizaArray([H|T],Carta1,CartaResultante,'false',B,C):-
    insere(H,B,X),atualizaArray(T,Carta1,CartaResultante,'false',X,C).
atualizaArray([H|T],Carta1,CartaResultante,'true',B, C):-
    (H==Carta1-> 
        insere(CartaResultante,B,X), atualizaArray(T, Carta1, CartaResultante,'false',X,C); 
        insere(H,B,X),atualizaArray(T, Carta1, CartaResultante,'true',X,C)).
        
        
realizaAtaque(A, Num1, B, Num2, C):-
    pegaCarta(A, Num1, Carta1), pegaCarta(B,Num2, Carta2), ataque(Carta1, Carta2, Carta), atualizaArray(B,Carta2,Carta,'true',[], C).

jogoMult(_,[],_).
jogoMult([],_,_).
jogoMult(A,B,C):-
    X is mod(C,2), X==0, 
    shell(clear),
    imprimeCartas(A,0,Resposta1),
    writeln(Resposta1),
    writeln('-----------------------------------------VS-------------------------------------------'),
    imprimeCartas(B,0,Resposta2),
    writeln(Resposta2),
    writeln('Player 1 ATK / Player 2 DEF'),
    writeln('PLAYER 1| [NUM] Selecione uma carta: '),
    read(CartaAtaca),
    writeln('PLAYER 2| [NUM] Selecione uma carta: '),
    read(CartaDefende),
    existeNoDeck(CartaDefende, B, ResultadoDefesa),
    existeNoDeck(CartaAtaca, A, ResultadoAtaque),
    (ResultadoAtaque =:= 1, ResultadoDefesa =:= 1->
    writeln('Carta de ataque/defesa validas, porem ainda precisamos terminar os metodos de ataque!'),
    realizaAtaque(A,CartaAtaca,B,CartaDefende,DeckResultante), jogoMult(A,DeckResultante,C); /*aqyu e a condicao ideal*/
    writeln('Carta Inválida, tente novamente!'),
    sleep(3),
    jogoMult(A,B,C)), /*aqui e a condicao de erro, dar o loop novamente*/
    writeln('entrara aqui independente'),halt(0). /*continua a execucao independente*/



existeNoDeck(_,[], 0).
existeNoDeck(A, [H|T], C):-
    get_num(H, Num),
    Num == A,
    C is 1;
    existeNoDeck(A, T, C).

setup(1):-
    deck(5,Deck1),
    deck(5,Deck2),
    jogoSingle(Deck1, Deck2, 0).
setup(2):-
    deck(5,Deck1),
    deck(5,Deck2),
    jogoMult(Deck1, Deck2, 0).
setup(_):-
    read(Opcao),
    setup(Opcao).

selecionaModo(1):-setup(1).
selecionaModo(2):-setup(2).
selecionaModo(_):-
    shell(clear),
    writeln('--------------------'),
    writeln(' [1] - SINGLEPLAYER '),
    writeln(' [2] - MULTIPLAYER  '),
    writeln('--------------------'),
    writeln('Escolha uma opcao:  '),
    read(Opcao),
    selecionaModo(Opcao).

creditos(_):-
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

menuOpcao(1):- setup(1).
menuOpcao(2):- selecionaModo(3).
menuOpcao(3):- instrucoes().
menuOpcao(4):- creditos(1).
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

    % Bateria de Testes/Nao apagar
    % X = [carta('Bulbasaur','GRASS',38,4,54241),carta('Venusaur','GRASS',50,800,2)], resultado ok
    % X = [carta('Bulbasaur','GRASS',38,4,54241)], resultado ok
    % X = [carta('Venusaur','GRASS',50,800,2), carta('Bulbasaur','GRASS',38,4,54241)], resultado ok
    % X = [carta(Bulbasaur,GRASS,38,4,54241),carta(Bulbasaur,GRASS,30,60,1),carta(Bulbasaur,GRASS,30,60,1),carta(Charizard,FIRE,70,70,4),carta(Venusaur,GRASS,50,800,2)], resultado ok
    % atualizaArray(X,carta('Venusaur','GRASS',50,800,2),carta('Venusaur','GRASS',50,400,2),'true',[], C),

    % atualizaArray([H|T],Carta1,CartaResultante,'true',B, C):-
    % atualizaArray([carta(Bulbasaur,GRASS,38,4,54241),carta(Bulbasaur,GRASS,30,60,1),carta(Bulbasaur,GRASS,30,60,1),carta(Charizard,FIRE,70,70,4),carta(Venusaur,GRASS,50,800,2)],carta(Venusaur,GRASS,50,800,2),carta(Venusaur,GRASS,50,400,2),[], C).
    % deck(5,X),
    % writeln(X),
    % pegaCarta(X, 2, Y),
    % writeln(Y).
    % shell(clear),
    % menuOpcao(5).