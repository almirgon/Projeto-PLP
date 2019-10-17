import System.IO
import qualified Cards as Cards
import System.Console.ANSI
import Control.Concurrent

--METODO CRIADO SO PRA TESTE, PODE APAGAR
criaCarta::Cards.Carta
criaCarta = Cards.Carta{
    Cards.nome = "pikachu   ",
    Cards.tipo = "ELECTRIC  ",
    Cards.ataque = 90,
    Cards.vida = 100,
    Cards.num= 1}

main::IO()
main = do
    menuOpcao "0" 
    let mao1 = mao
    let mao2 = mao
    jogo mao mao 0
    
setup:: Bool ->IO()
setup True = do
    let mao1 = mao 
    let mao2 = mao
    putStrLn "a"
    threadDelay 2000000
    putStrLn "a"
setup False = do
    let mao1 = mao 
    let mao2 = mao
    putStrLn "b"
    threadDelay 2000000
    putStrLn "b"

--METODO CRIADO SO PRA TESTE, PODE APAGAR 
mao:: [Cards.Carta]
mao = [criaCarta, criaCarta , criaCarta, criaCarta, criaCarta]

--Imprime as cartas do jogador, 
--AJEITAR FORMATACAO DA FUNCAO
imprimeCartas:: [Cards.Carta] -> Int -> String
imprimeCartas [] b = ""
imprimeCartas (a:as) 0 = imprimeAtributos (a:as) 0 ++ "\n" ++ imprimeCartas(a:as) 1
imprimeCartas (a:as) 1 = imprimeAtributos (a:as) 1 ++ "\n" ++ imprimeCartas(a:as) 2
imprimeCartas (a:as) 2 = imprimeAtributos (a:as) 2 ++ "\n" ++ imprimeCartas(a:as) 3
imprimeCartas (a:as) 3 = imprimeAtributos (a:as) 3 ++ "\n" ++ imprimeCartas(a:as) 4
imprimeCartas (a:as) 4 = imprimeAtributos (a:as) 4 

imprimeAtributos:: [Cards.Carta] -> Int -> String
imprimeAtributos [] b = ""
imprimeAtributos (a:as) 0 = Cards.nome a ++ imprimeAtributos as 0
imprimeAtributos (a:as) 1 = Cards.tipo a ++ imprimeAtributos as 1
imprimeAtributos (a:as) 2 = show(Cards.ataque a) ++ imprimeAtributos as 2
imprimeAtributos (a:as) 3 = show(Cards.vida a) ++ imprimeAtributos as 3
imprimeAtributos (a:as) 4 = show(Cards.num a) ++ imprimeAtributos as 4

--Recebe um array de cartas e elimina do array a carta que tiver com 0 de vida
remove:: [Cards.Carta] -> [Cards.Carta]
remove [] = []
remove (a:as) = do
    if (Cards.vida a) <= 0 then
        remove as
    else 
        [a] ++ remove as

-- Verifica se a carta existe dentro do Array, 
aCartaExiste:: Int -> [Cards.Carta] -> Bool
aCartaExiste num [] = False
aCartaExiste num (a:as) = do
    if (Cards.num a)==num then
        True
    else
        aCartaExiste num as

-- Metodo responsavel por retorno um bool ao comparar se o num do carta existe dentro do array(uso de compressão para pegar apenas os numeros) de cartas 
--cartaExiste:: Int -> [Cards.Carta] -> Bool
--cartaExiste num lista = num `elem` [x.num | x <- lista]

selectCarta:: Int -> [Cards.Carta] -> Cards.Carta
selectCarta num (a:as) = do
    if(Cards.num a)==num then
        a
    else
        selectCarta num as

-- Metodo que primeiro verifica se a carta existe, se sim, retorna o primeiro elemento da lista(Função head) contendo a carta
-- Se não retorna a função null(deve haver um tratamento no refatoramento do código para o susuario escolher outra carta ao tentar selecionar uma que n existe)
-- select:: Int -> [Cards.Carta] -> Cards.Carta
-- select numero lista
--  |cartaExiste numero lista = saida
--  |otherwise = null
--  where saida = head ([x| x <- lista, x.num = numero])

--Recebe duas cartas, uma carta recebera o ataque e a outra vai realizar o ataque, retornando a nova carta
--com a vida alterada
ataque:: Cards.Carta -> Cards.Carta -> Cards.Carta 
ataque carta1 carta2= Cards.Carta{
    Cards.nome = Cards.nome carta2,
    Cards.tipo = Cards.tipo carta2,
    Cards.ataque = Cards.ataque carta2,
    Cards.vida = validaAtaque (Cards.vida carta2) (Cards.ataque carta1) (vantagem (Cards.tipo carta1) (Cards.tipo carta2)), 
    Cards.num = Cards.num carta2}

vantagem:: String -> String -> Bool
vantagem carta1 carta2= do
    if(carta1 =="GRASS     ")&&(carta2=="WATER     " || carta2=="ELECTRIC  " || carta2=="GRASS     " || carta2=="GROUND    ") then
        True
    else if(carta1 =="FIRE      ")&&(carta2=="FIRE      " || carta2=="BUG       " || carta2=="GRASS     ") then
        True
    else if(carta1 =="WATER     ")&&(carta2=="FIRE      " || carta2=="GROUND    " || carta2=="WATER     ") then
        True
    else if(carta1 =="POISON    ")&&(carta2=="FAIRY     " || carta2=="GRASS     " || carta2=="BUG       ") then
        True
    else if(carta1 =="BUG       ")&&(carta2=="PSYCHIC   " || carta2=="GRASS     " || carta2=="GROUND    ") then
        True
    else if(carta1 =="PSYCHIC   ")&&(carta2=="POISON    ") then
        True
    else if(carta1 =="ELECTRIC  ")&&(carta2=="FLY       " || carta2=="WATER     ")then
        True
    else if(carta1 =="GROUND    ")&&(carta2=="FIRE      " || carta2=="NORMAL    " || carta2=="FLY       " || carta2=="POISON    " || carta2=="BUG       ") then
        True
    else if(carta1 =="FLY       ")&&(carta2=="GRASS     " || carta2=="BUG       ") then
        True
    else if(carta1 =="FAIRY     ")&&(carta2=="BUG       ") then
        True
    else
        False
        
--Impede que a carta atacada tenha pontos de vida negativos ao sofrer um ataque maior que sua defesa
validaAtaque:: Int -> Int -> Bool -> Int 
validaAtaque a b c = do
    if(c)then
        if(a-b-10<0)then
            0
        else 
            a-b-10
    else if(a-b<0) then
            0
        else
            a-b

--Recebe uma carta e um array de cartas, esse metodo retorna o array com a carta modificada
atualizaArray:: Cards.Carta -> [Cards.Carta] -> [Cards.Carta]
atualizaArray carta (a:as) = do
    if(Cards.nome a)==(Cards.nome carta) then
        [carta] ++ as
    else do
        [a] ++ atualizaArray carta as

-- funcao princial, executa o loop do jogo até que um jogador perca suas cartas
jogo:: [Cards.Carta] -> [Cards.Carta] -> Int -> IO()
jogo [] b c = do
    putStrLn ("JOGADOR 2 venceu")
jogo a [] c = do
    putStrLn ("JOGADOR 1 venceu")
jogo a b c = do
    clearScreen
    putStrLn("PLAYER 1")
    putStrLn(imprimeCartas a 0)
    putStrLn("PLAYER 2")
    putStrLn(imprimeCartas b 0)
    if (mod c 2 ==0) then do
        putStrLn $ ("Player 1 ATK / Player 2 DEF")
        putStrLn $ ("PLAYER 1| [NUM] Selecione uma carta: ")
        cartaAtaca <- getLine
        let num1 = (read cartaAtaca:: Int)
        putStrLn $ ("PLAYER 2| [NUM] Selecione uma carta: ")
        cartaDefende <- getLine
        let num2 = (read cartaDefende:: Int)

        if(aCartaExiste num1 a)&&(aCartaExiste num2 b) then do
            let carta1 = selectCarta num1 a
            let carta2 = selectCarta num2 b
            let ataq = ataque carta1 carta2
            let array = atualizaArray ataq b
            jogo a (remove array) (c+1)
        else do
            clearScreen
            putStrLn("Erro ao selecionar a carta, tente novamente")
            w <- getLine
            jogo a (remove b) (c)
    else do
        putStrLn $ ("Player 2 ATK / Player 1 DEF")
        putStrLn $ ("PLAYER 2| [NUM] Selecione uma carta: ")
        cartaAtaca <- getLine
        putStrLn $ ("PLAYER 1| [NUM] Selecione uma carta: ")
        cartaDefende <- getLine
        jogo (remove a) b (c+1)
        -- FAZER TODO O PROCESSO DO IF AQUI DENTRO

creditos:: IO()
creditos = do
    clearScreen
    putStrLn "DESENVOLVIDO POR: " 
    putStrLn "Pablwo Araujo" 
    putStrLn "Natan Ataide" 
    putStrLn "Luiz Boas" 
    putStrLn "Almir Crispiniano" 
    putStrLn "Walisson Farias" 
    threadDelay 2000000
    voltar

voltar:: IO()
voltar = do
    putStrLn ""
    putStrLn "Digite alguma coisa para voltar"
    a<- getLine
    putStrLn ""
    menuOpcao "0"


menuOpcao:: String-> IO()
menuOpcao "2" = selecionaModo 
menuOpcao "3" = instrucoes
menuOpcao "4" = creditos
menuOpcao n = do
    clearScreen
    putStrLn "----------------------------------------------------------------------------------" 
    putStrLn "[1] - INICIAR JOGO " 
    putStrLn "[2] - MODO DE JOGO " 
    putStrLn "[3] - INSTRUCOES   " 
    putStrLn "[4] - CREDITOS     " 
    putStrLn "----------------------------------------------------------------------------------" 
    opcao <- getLine
    menuOpcao opcao 

-- Funcao que exibe o modo de jogo, se o usuario digita 1 = singleplayer, se 2 = multiplayer
selecionaModo :: IO()
selecionaModo = do
    clearScreen
    putStrLn("--------------------");
    putStrLn(" [1] - SINGLEPLAYER ");
    putStrLn(" [2] - MULTIPLAYER  ");
    putStrLn("--------------------");
    putStrLn("Escolha uma opcao:  ");
    opcao <- getLine
    if (opcao=="1" ) then do
        setup True
    else if (opcao == "2") then do
        setup False
        else 
            selecionaModo

instrucoes :: IO()
instrucoes = do
    clearScreen
    putStrLn "INSTRUÇOES:                                                                                           " 
    putStrLn "                                                                                                      " 
    putStrLn "CADA JOGADOR INICIA COM 5 CARTAS, ESSAS CARTAS SAO ESCOLHIDAS ALEATORIAMENTE DE UM DECK COM 34 CARTAS " 
    putStrLn "DIFERENTES, APOS A FORMACAO DOS DERKS DE CADA JOGADOR, O JOGO E INICIADO E O PLAYER 1 SELECIONA       " 
    putStrLn "UMA CARTA DISPONIVEL EM SUA MAO A PARTIR DO [NUM] PARA ATACAR O OPONENTE, QUE PODE SER O PLAYER 2 OU  " 
    putStrLn "O COMP QUE POR SUA VEZ FAZ O MESMO PROCESSO ESCOLHENDO A CARTA PARA RECEBER O ATAQUE. DANDO INICIO    " 
    putStrLn "A BATTLE FASE, CADA POKEMON TEM UM [TIPO] ASSOCIADO QUE INTERFERE DIRETAMENTE NO ATAQUE, UMA VEZ QUE  " 
    putStrLn "CERTOS TIPOS TEM VANTAGENS SOBRE OUTROS, FAZENDO COM QUE O [ATK] DA CARTA TENHA UM BUFFER ADCIONAL,   " 
    putStrLn "ALEM DAS CARTAS O ATAQUE PARA SER EFETIVADO DEPENDE DA SORTE DE CADA JOGADOR, O POKEMON A RECEBER     " 
    putStrLn "O ATAQUE TEM 50% DE CHANCE DE DESVIAR. NO FINAL DA BATTLE FASE SE A CARTA TIVER SOFRIDO UM DANO QUE   " 
    putStrLn "REDUZA SEU HP A 0, A CARTA É REMOVIDA DO JOGO. GANHA QUEM ELEMINAR TODAS AS CARTAS DE SEU OPONENTE.   " 
    putStrLn "                                                                                                      " 
    putStrLn "|----------------------------------------------------------------------------------------------------|" 
    putStrLn "|                                    VANTAGENS D0 TIPO D0 POKEMON:                                   |"
    putStrLn "|----------------------------------------------------------------------------------------------------|" 
    putStrLn "|                  TIPO                          |                       VANTAGENS                   |" 
    putStrLn "|------------------------------------------------|---------------------------------------------------|" 
    putStrLn "|                 GRASS                          |            WATER, ELETRIC, GROUND, GRASS          |" 
    putStrLn "|                 WATER                          |                  FIRE, GROND, WATER               |" 
    putStrLn "|                 FAIRY                          |                         BUG                       |" 
    putStrLn "|                 POISON                         |                  FAIRY, GRASS, BUG                |" 
    putStrLn "|                 BUG                            |                PSYCHIC, GRASS, GROUND             |" 
    putStrLn "|                 PSYCHIC                        |                        POISON                     |" 
    putStrLn "|                 ELETRIC                        |                      FLY, WATER                   |" 
    putStrLn "|                 GROUND                         |            FIRE, NORMAL, FLY, POISON, BUG         |" 
    putStrLn "|                 FLY                            |                       BUG, GRASS                  |" 
    putStrLn "|                 FIRE                           |                    FIRE, BUG, GRASS               |" 
    putStrLn "|                 NORMAL                         |                    NENHUMA VANTAGEM               |" 
    putStrLn "|----------------------------------------------------------------------------------------------------|" 
    voltar