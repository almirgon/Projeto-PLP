:- initialization main.

:- include('carta.pl').
:- include('util.pl').

% nem sei se to usando mas blz
selecionaCarta(X) :- random(1, 35, X).

% insere um elemento em uma lista
insere(X, L, [X|L]).

% auxilia o metodo deck(A,B)
parse_lista(X, Y):- insere(X, [], Y). 

% Gera o deck de forma randomica
deck(1, X):- random(1,35,Y), get_carta(Y,W), parse_lista(W, X).
deck(A, L):- A > 1, random(1,35,Y), get_carta(Y,C), B is A-1, deck(B, P), insere(C, P, L).

% retorna a carta apos sofrer o ataque
ataque(CartaAtaque, CartaDefesa, CartaResultado):-
    get_tipo(CartaAtaque, TipoCartaAtaque),
    get_ataque(CartaAtaque, AtaqueCarta),
    get_tipo(CartaDefesa, TipoCartaDefende),
    get_vida(CartaDefesa, VidaCarta),
    vantagem(TipoCartaAtaque, TipoCartaDefende, ResultadoVantagem),
    (ResultadoVantagem = 1 -> VidaResultante is (VidaCarta - AtaqueCarta - 10), shell(clear), imagens('superEfetivo'), sleep(3), shell(clear);
    VidaResultante is (VidaCarta - AtaqueCarta), shell(clear),  imagens('ataqueRealizado'), sleep(3), shell(clear)),
    (VidaResultante =< 0 -> X is 0; duplica(VidaResultante,X)),
    get_nome(CartaDefesa, Nome),
    get_tipo(CartaDefesa, Tipo),
    get_ataque(CartaDefesa, Ataque),
    get_num(CartaDefesa, Numero),
    build_carta(Nome,Tipo,Ataque,X,Numero,CartaResultado).

% imprime um baralho
imprimeCartas([],_,"").
imprimeCartas([H|T], 0, Resultado):- 
    imprimeAtributos([H|T], 0, R1),string_concat('           ', R1, R4), string_concat(R4, '- \n', R2),imprimeCartas([H|T], 1, R3), string_concat(R2, R3, Resultado).
imprimeCartas([H|T], 1, Resultado):-
    imprimeAtributos([H|T], 1, R1), string_concat('           ', R1, R4), string_concat(R4, '| \n', R2),imprimeCartas([H|T], 2, R3), string_concat(R2, R3, Resultado).
imprimeCartas([H|T], 2, Resultado):-
    imprimeAtributos([H|T], 2, R1), string_concat('           ', R1, R4), string_concat(R4, '| \n', R2), imprimeCartas([H|T], 3, R3), string_concat(R2, R3, Resultado).
imprimeCartas([H|T], 3, Resultado):-
    imprimeAtributos([H|T], 3, R1), string_concat('           ', R1, R4), string_concat(R4, '| \n', R2), imprimeCartas([H|T], 4, R3), string_concat(R2, R3, Resultado).
imprimeCartas([H|T], 4, Resultado):-
    imprimeAtributos([H|T], 4, R1), string_concat('           ', R1, R4), string_concat(R4, '| \n', R2), imprimeCartas([H|T], 5, R3), string_concat(R2, R3, Resultado).
imprimeCartas([H|T], 5, Resultado):-
    imprimeAtributos([H|T], 5, R1), string_concat('           ', R1, R4), string_concat(R4, '| \n', R2), imprimeCartas([H|T], 6, R3), string_concat(R2, R3, Resultado).
imprimeCartas([H|T], 6, Resultado):-
    imprimeAtributos([H|T], 6, R1), string_concat('           ', R1, R4), string_concat(R4, '-', Resultado).

% auxilia o metodo preencheLacunas
setaPreencher(String, Resultado):-atom_length(String, Length), preencheLacunas(String, Length, Resultado).

% preenche os espaços vazios da formatacao, pra sair tudo com a msm quantidade de caracteres no print
preencheLacunas(String, 17, String).
preencheLacunas(String, Len, Saida):- string_concat(String,' ', X), NewLen is Len+1,preencheLacunas(X,NewLen, Saida).

% imprime em linha os atributos 1 a 1 do array
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

% metodo auxiliar que ecebe X e Retorna X
duplica(X, X).

% metodo que verifica se a carta existe na lista
acartaexiste(X, [X|_]).
acartaexiste(X, [_|T]) :- acartaexiste(X, T).

% pega a carta de um baralho
pegaCarta([], _, "").
pegaCarta([H|T], Num, Carta):-
    (get_num(H, X), X=:=Num-> duplica(H, Carta);
    pegaCarta(T, Num, Carta)).
    
% recebe o baralho, a carta original, a carta dps da alteracao e adiciona a carta alterada no baralho, 
% infelizmente ele inverte o array mas nao e problema
atualizaArray([],_,_,_,B,C):-duplica(B,C).
atualizaArray([H|T],Carta1,CartaResultante,'false',B,C):-
    insereFim(H,B,X),atualizaArray(T,Carta1,CartaResultante,'false',X,C).
atualizaArray([H|T],Carta1,CartaResultante,'true',B, C):-
    (H==Carta1-> 
        insereFim(CartaResultante,B,X), atualizaArray(T, Carta1, CartaResultante,'false',X,C); 
        insereFim(H,B,X),atualizaArray(T, Carta1, CartaResultante,'true',X,C)).
        
% Recebe os 2 baralhos e os numeros das cartas envolvidas no ataque, C é o baralho resultante depois do ataque da carta Num1 em Num2 
realizaAtaque(A, Num1, B, Num2, C):-
    pegaCarta(A, Num1, Carta1), pegaCarta(B,Num2, Carta2), ataque(Carta1, Carta2, Carta), atualizaArray(B,Carta2,Carta,'true',[], C).

moeda(X):-random(0, 2, X).

% Modo de jogo player Vs player
jogoMult(_,[],_):- shell(clear), imagens('player1Wins').
jogoMult([],_,_):- shell(clear), imagens('player2Wins').
jogoMult(A,B,C):-
    shell(clear),
    X is mod(C,2),  
    (X =:=0-> 
        imagens('player1Atk'),
        writeln('-----------------------------------------VS-------------------------------------------'),
        imagens('player2Def'),
        sleep(3),
        shell(clear),
        writeln('PLAYER 1: '),
        imprimeCartas(A,0,Resposta1),
        writeln(Resposta1),
        writeln(''),
        writeln('PLAYER 2: '),
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
            mostraBatalha(CartaAtaca, CartaDefende),
            sleep(3),
            moeda(M), 
            Y is mod(M,2),
            (Y=:=0 ->
                realizaAtaque(A,CartaAtaca,B,CartaDefende,DeckResultante), D is C+1,
                % mostraBatalha(CartaAtaca, CartaDefende),
                % sleep(3),
                removeCartas(DeckResultante, [], NovoDeckB),
                jogoMult(A,NovoDeckB,D);
                D is C+1,
                shell(clear),
                imagens('desvio'),
                sleep(3),
                shell(clear),
                jogoMult(A,B,D)
            );
            writeln('Carta Inválida, tente novamente!'),                                                                    
            sleep(3),
            jogoMult(A,B,C)
        );
        imagens('player2Atk'),
        writeln('-----------------------------------------VS-------------------------------------------'),
        imagens('player1Def'),
        sleep(3),
        shell(clear),
        writeln('PLAYER 1: '),
        imprimeCartas(A,0,Resposta1),
        writeln(Resposta1),
        writeln(''),
        writeln('PLAYER 2: '),
        imprimeCartas(B,0,Resposta2),
        writeln(Resposta2),

        writeln('Player 2 ATK / Player 1 DEF'),
        writeln('PLAYER 2| [NUM] Selecione uma carta: '),
        read(CartaAtaca),
        writeln('PLAYER 1| [NUM] Selecione uma carta: '),
        read(CartaDefende),
        existeNoDeck(CartaDefende, A, ResultadoDefesa),
        existeNoDeck(CartaAtaca, B, ResultadoAtaque),
        (ResultadoAtaque =:= 1, ResultadoDefesa =:= 1->                                                                     
            mostraBatalha(CartaAtaca, CartaDefende),
            sleep(3),
            moeda(M), 
            Y is mod(M,2),
            (Y=:=0 -> 
                realizaAtaque(B,CartaAtaca,A,CartaDefende,DeckResultante), D is C+1,
                % mostraBatalha(CartaAtaca, CartaDefende),
                % sleep(3),
                removeCartas(DeckResultante, [], NovoDeckA),                                                                   
                jogoMult(NovoDeckA,B,D);
                D is C+1,
                shell(clear),
                imagens('desvio'),
                sleep(3),
                shell(clear),
                jogoMult(A,B,D) 
            );                                                                       
            writeln('Carta Inválida, tente novamente!'),                                                                    
            sleep(3),
            jogoMult(A,B,C))
        ), 
        halt(0).

/*seleciona o numero da carta com maior ataque*/
selecionaCartaAtaque([],A, _, A).
selecionaCartaAtaque([H|T], Num, Atk, Saida):- 
    get_ataque(H, Ataque),
    Ataque > Atk, get_num(H, Numero),
    selecionaCartaAtaque(T, Numero, Ataque, Saida); 
    selecionaCartaAtaque(T, Num, Atk, Saida).

/*seleciona o numero da carta com maior defesa*/
selecionaCartaDefende([],A, _, A).
selecionaCartaDefende([H|T], Num, Hp, Saida):- 
    get_vida(H, Vida),
    Vida > Hp, get_num(H, Numero),
    selecionaCartaDefende(T, Numero, Vida, Saida); 
    selecionaCartaDefende(T, Num, Hp, Saida).

mostraBatalha(Num1, Num2):-
    shell(clear),
    get_carta(Num1, Carta1), get_carta(Num2, Carta2),
    get_nome(Carta1, Nome1), get_nome(Carta2, Nome2),
    % get_vida(Carta1, Vida1), get_vida(Carta2, Vida2),
    % get_ataque(Carta1, Ataque1), get_ataque(Carta2, Ataque2),
    writeln(Nome1), 
    % write(' Ataque: '), write(Ataque1), write(' Vida: '), writeln(Vida1),
    imagens(Nome1),
    writeln('-----------------------------------------VS-------------------------------------------'),
    writeln(Nome2), 
    % write(' Ataque: '), write(Ataque2), write(' Vida: '), writeln(Vida2),
    imagens(Nome2).

/*Mode de jogo Player Vs Bot*/
jogoSingle([],_,_):- shell(clear), imagens('compWins').
jogoSingle(_,[],_):- shell(clear), imagens('player1Wins').
jogoSingle(A,B,C):-
    shell(clear),
    X is mod(C,2),  
    (X =:=0-> 
        imagens('player1Atk'),
        writeln('-----------------------------------------VS-------------------------------------------'),
        imagens('compDef'),
        sleep(3),
        shell(clear),
        writeln('PLAYER 1: '),
        imprimeCartas(A,0,Resposta1),
        writeln(Resposta1),
        writeln(''),
        writeln('COMP: '),
        imprimeCartas(B,0,Resposta2),
        writeln(Resposta2),

        writeln('Player 1 ATK / COMP DEF'),
        writeln('PLAYER 1| [NUM] Selecione uma carta: '),
        read(CartaAtaca),
        selecionaCartaDefende(B,0,0,CartaDefende),                                                                          
        existeNoDeck(CartaAtaca, A, ResultadoAtaque),
        (ResultadoAtaque =:= 1->                                                                                            
            mostraBatalha(CartaAtaca, CartaDefende),
            sleep(3),
            moeda(M), 
            Y is mod(M,2),
            (Y=:=0 ->
                realizaAtaque(A,CartaAtaca,B,CartaDefende,DeckResultante), D is C+1,
                % mostraBatalha(CartaAtaca, CartaDefende),
                % sleep(3),
                removeCartas(DeckResultante, [], NovoDeckB),
                jogoSingle(A,NovoDeckB,D);
                D is C+1,
                shell(clear),
                imagens('desvio'),
                sleep(3),
                shell(clear),
                jogoSingle(A,B,D)
            );
            writeln('Carta Inválida, tente novamente!'),                                                                    
            sleep(3),
            jogoSingle(A,B,C)
        );   
        imagens('compAtk'),
        writeln('-----------------------------------------VS-------------------------------------------'),
        imagens('player1Def'),
        sleep(3),
        shell(clear),
        writeln('PLAYER 1: '),
        imprimeCartas(A,0,Resposta1),
        writeln(Resposta1),
        writeln(''),
        writeln('COMP: '),
        imprimeCartas(B,0,Resposta2),
        writeln(Resposta2),

        writeln('BOT ATK / Player 1 DEF'),
        selecionaCartaAtaque(B,0,0,CartaAtaca),                                                                             
        writeln('PLAYER 1| [NUM] Selecione uma carta: '),
        read(CartaDefende),
        existeNoDeck(CartaDefende, A, ResultadoDefesa),
        (ResultadoDefesa =:= 1->                                                                                            
            mostraBatalha(CartaAtaca, CartaDefende),
            sleep(3),
            moeda(M), 
            Y is mod(M,2),
            (Y=:=0 -> 
                realizaAtaque(B,CartaAtaca,A,CartaDefende,DeckResultante), D is C+1,
                % mostraBatalha(CartaAtaca, CartaDefende),
                % sleep(3),
                removeCartas(DeckResultante, [], NovoDeckA),                                                                   
                jogoSingle(NovoDeckA,B,D);
                D is C+1,
                shell(clear),
                imagens('desvio'),
                sleep(3),
                shell(clear),
                jogoSingle(A,B,D) 
            );                                                                       
            writeln('Carta Inválida, tente novamente!'),                                                                    
            sleep(3),
            jogoSingle(A,B,C))
        ), 
        halt(0).

vantagem(TipoCartaAtaque, TipoCartaDefende, R):-
    TipoCartaAtaque = 'GRASS',
    TipoCartaDefende = 'WATER',
    R is 1;
    TipoCartaAtaque = 'GRASS',
    TipoCartaDefende = 'ELECTRIC',
    R is 1;
    TipoCartaAtaque = 'GRASS',
    TipoCartaDefende = 'GRASS',
    R is 1;
    TipoCartaAtaque = 'GRASS',
    TipoCartaDefende = 'GROUND',
    R is 1;
    TipoCartaAtaque = 'FIRE',
    TipoCartaDefende = 'FIRE',
    R is 1;
    TipoCartaAtaque = 'FIRE',
    TipoCartaDefende = 'BUG',
    R is 1;
    TipoCartaAtaque = 'FIRE',
    TipoCartaDefende = 'GRASS',
    R is 1;
    TipoCartaAtaque = 'WATER',
    TipoCartaDefende = 'FIRE',
    R is 1;
    TipoCartaAtaque = 'WATER',
    TipoCartaDefende = 'GROUND',
    R is 1;
    TipoCartaAtaque = 'WATER',
    TipoCartaDefende = 'WATER',
    R is 1;
    TipoCartaAtaque = 'POISON',
    TipoCartaDefende = 'FAIRY',
    R is 1;
    TipoCartaAtaque = 'POISON',
    TipoCartaDefende = 'GRASS',
    R is 1;
    TipoCartaAtaque = 'POISON',
    TipoCartaDefende = 'BUG',
    R is 1;
    TipoCartaAtaque = 'BUG',
    TipoCartaDefende = 'PSYCHIC',
    R is 1;
    TipoCartaAtaque = 'BUG',
    TipoCartaDefende = 'GRASS',
    R is 1;
    TipoCartaAtaque = 'BUG',
    TipoCartaDefende = 'GROUND',
    R is 1;
    TipoCartaAtaque = 'PSYCHIC',
    TipoCartaDefende = 'POISON',
    R is 1;
    TipoCartaAtaque = 'ELECTRIC',
    TipoCartaDefende = 'FLY',
    R is 1;
    TipoCartaAtaque = 'ELECTRIC',
    TipoCartaDefende = 'WATER',
    R is 1;
    TipoCartaAtaque = 'GROUND',
    TipoCartaDefende = 'FIRE',
    R is 1;
    TipoCartaAtaque = 'GROUND',
    TipoCartaDefende = 'NORMAL',
    R is 1;
    TipoCartaAtaque = 'GROUND',
    TipoCartaDefende = 'FLY',
    R is 1;
    TipoCartaAtaque = 'GROUND',
    TipoCartaDefende = 'POISON',
    R is 1;
    TipoCartaAtaque = 'GROUND',
    TipoCartaDefende = 'BUG',
    R is 1;
    TipoCartaAtaque = 'FLY',
    TipoCartaDefende = 'BUG',
    R is 1;
    TipoCartaAtaque = 'FLY',
    TipoCartaDefende = 'GRASS',
    R is 1;
    TipoCartaAtaque = 'FAIRY',
    TipoCartaDefende = 'BUG',
    R is 1;
    R is 0.
    

selecionaCartaAtaque([], A, _, A).
selecionaCartaAtaque([H|T], A, Atk, Saida):- 
    get_ataque(H, Ataque),
    Ataque > Atk,
    AtkNovo is Ataque,
    ANovo is H,
    selecionaCartaAtaque(T, ANovo, AtkNovo, Saida);
    selecionaCartaAtaque(T, A, Atk, Saida).

removeCartas([],X, X).
removeCartas([H|T], X, R):-
    get_vida(H, VidaCabeca),
    VidaCabeca > 0,
    insereFim(H, X, X1),
    removeCartas(T, X1, R);
    shell(clear),
    imagens('foraDeCombate'),
    sleep(3),
    shell(clear),
    removeCartas(T, X, R).

insereFim(N, [],[N]).
insereFim(N, [H|T], L):- insereFim(N, T, X),
insere(H, X, L).

% Ce se a carta A está no Array de Cartas, 0 para Nao e 1 para Sim
existeNoDeck(_,[], 0).
existeNoDeck(A, [H|T], C):-
    get_num(H, Num),
    Num == A,
    C is 1;
    existeNoDeck(A, T, C).

% Inicializa o jogo a partir da escolha do Usuario, falta implementar os metodos jogoSingle e jogoMult
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
    shell(clear),
    selecionaModo(Opcao).

creditos():-
    writeln(X),
    shell(clear),
    writeln('DESENVOLVIDO POR: '),
    writeln('Pablwo Araujo'),
    writeln('Natan Ataide'), 
    writeln('Luiz Boas'), 
    writeln('Almir Crispiniano'), 
    writeln('Walisson Farias'),
    writeln(''),
    writeln('Digite algo para voltar ao menu principal: '), 
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
    writeln(''),
    writeln('Digite algo para voltar ao menu principal: '), 
    read(Saida),
    menuOpcao(5).

% menu de opcaoes
menuOpcao(1):- setup(1).
menuOpcao(2):- selecionaModo(3).
menuOpcao(3):- instrucoes().
menuOpcao(4):- creditos().
menuOpcao(_):-
    shell(clear),
    imagens('banner'),
    sleep(3),
    writeln('----------------------------------------------------------------------------------'),
    writeln('[1] - INICIAR JOGO '),
    writeln('[2] - MODO DE JOGO '),
    writeln('[3] - INSTRUCOES   '),
    writeln('[4] - CREDITOS     '), 
    writeln('----------------------------------------------------------------------------------'),
    read(Opcao),
    menuOpcao(Opcao).

% chama o menu
main:-
    menuOpcao(5).

mostraCartas(Carta1,Carta2):- 
	get_nome(Carta1,Nome1),
	get_nome(Carta2,Nome2),
	imagens(Nome1),
	imagens(Nome2).