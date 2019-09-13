#include <iostream>
#include <string>
#include <locale.h>
#include <stack>
#include <ctime>
#include <algorithm>
#include <chrono>
#include <thread>

using namespace std;

struct Carta
{
    string tipo;
    string nome;
    int ataque;
    int hp;
    int num;
    bool condicao;
};

Carta player1[5];   
Carta player2[5];   
Carta baralho[34];
int vez=2;
bool play1;
bool play2;

void chamaArt(string nome);
void whoWins(int player);
void whoAtk(int player);
void whoDef(int player);
void banner();
void select_numero_players();
void creditos();
void desvio();
void ataqueRealizado();
void superEfetivo();
void foraDeCombate();

void inicializar_players(){
    
    srand(time(0));
    int a = rand() % 34;
    int b = rand() % 34;
    int c = rand() % 34;
    int d = rand() % 34;
    int e = rand() % 34;
    int f = rand() % 34;
    int g = rand() % 34;
    int h = rand() % 34;
    int i = rand() % 34;
    int j = rand() % 34;

    player1[0]=baralho[a];
    player1[1]=baralho[b];
    player1[2]=baralho[c];
    player1[3]=baralho[d];
    player1[4]=baralho[e];

    player2[0]=baralho[f];
    player2[1]=baralho[g];
    player2[2]=baralho[h];
    player2[3]=baralho[i];
    player2[4]=baralho[j];

}

void inicializa_cartas()
{
    baralho[0].tipo = "GRASS     ";
    baralho[0].nome = "Bulbasaur ";
    baralho[0].ataque = 30;
    baralho[0].hp = 60;
    baralho[0].condicao= true;
    baralho[0].num=10;

    baralho[1].tipo = "GRASS     ";
    baralho[1].nome = "Venusaur  ";
    baralho[1].ataque = 50;
    baralho[1].hp = 80;
    baralho[1].condicao= true;
    baralho[1].num=11;

    baralho[2].tipo = "FIRE      ";
    baralho[2].nome = "Charmander";
    baralho[2].ataque = 31;
    baralho[2].hp = 50;
    baralho[2].condicao = true;
    baralho[2].num=12;

    baralho[3].tipo = "FIRE      ";
    baralho[3].nome = "Charizard ";
    baralho[3].ataque = 70;
    baralho[3].hp = 70;
    baralho[3].condicao = true;
    baralho[3].num=13;

    baralho[4].tipo = "WATER     ";
    baralho[4].nome = "Squirtle  ";
    baralho[4].ataque = 38;
    baralho[4].hp = 56;
    baralho[4].condicao = true;
    baralho[4].num=14;

    baralho[5].tipo = "WATER     ";
    baralho[5].nome = "Blastoise ";
    baralho[5].ataque = 50;
    baralho[5].hp = 80;
    baralho[5].condicao = true;
    baralho[5].num=15;

    baralho[6].tipo = "BUG       ";
    baralho[6].nome = "Caterpie  ";
    baralho[6].ataque = 30;
    baralho[6].hp = 40;
    baralho[6].condicao = true;
    baralho[6].num=16;

    baralho[7].tipo = "BUG       ";
    baralho[7].nome = "Weedle    ";
    baralho[7].ataque = 35;
    baralho[7].hp = 45;
    baralho[7].condicao = true;
    baralho[7].num=17;

    baralho[8].tipo = "FLY       ";
    baralho[8].nome = "Pidgey    ";
    baralho[8].ataque = 40;
    baralho[8].hp = 45;
    baralho[8].condicao = true;
    baralho[8].num=18;

    baralho[9].tipo = "NORMAL    ";
    baralho[9].nome = "Rattata   ";
    baralho[9].ataque = 25;
    baralho[9].hp = 40;
    baralho[9].condicao = true;
    baralho[9].num=19;

    baralho[10].tipo = "POISON    ";
    baralho[10].nome = "Ekans     ";
    baralho[10].ataque = 37;
    baralho[10].hp = 48;
    baralho[10].condicao = true;
    baralho[10].num=20;

    baralho[11].tipo = "ELECTRIC  ";
    baralho[11].nome = "Pikachu   ";
    baralho[11].ataque = 70;
    baralho[11].hp = 50;
    baralho[11].condicao = true;
    baralho[11].num=21;

    baralho[12].tipo = "POISON    ";
    baralho[12].nome = "Nidoran   ";
    baralho[12].ataque = 27;
    baralho[12].hp = 80;
    baralho[12].condicao = true;
    baralho[12].num=22;

    baralho[13].tipo = "FAIRY     ";
    baralho[13].nome = "Clefairy  ";
    baralho[13].ataque = 35;
    baralho[13].hp = 75;
    baralho[13].condicao = true;
    baralho[13].num=23;

    baralho[14].tipo = "NORMAL    ";
    baralho[14].nome = "Jigglypuff";
    baralho[14].ataque = 20;
    baralho[14].hp = 50;
    baralho[14].condicao = true;
    baralho[14].num=24;

    baralho[15].tipo = "FLY       ";
    baralho[15].nome = "Zubat     ";
    baralho[15].ataque = 20;
    baralho[15].hp = 30;
    baralho[15].condicao = true;
    baralho[15].num=25;

    baralho[16].tipo = "GRASS     ";
    baralho[16].nome = "Oddish    ";
    baralho[16].ataque = 35;
    baralho[16].hp = 60;
    baralho[16].condicao = true;
    baralho[16].num=26;

    baralho[17].tipo = "GROUND    ";
    baralho[17].nome = "Diglett   ";
    baralho[17].ataque = 30;
    baralho[17].hp = 20;
    baralho[17].condicao = true;
    baralho[17].num=27;

    baralho[18].tipo = "NORMAL    ";
    baralho[18].nome = "Meowth    ";
    baralho[18].ataque = 36;
    baralho[18].hp = 40;
    baralho[18].condicao = true;
    baralho[18].num=28;

    baralho[19].tipo = "WATER     ";
    baralho[19].nome = "Psyduck   ";
    baralho[19].ataque = 30;
    baralho[19].hp = 64;
    baralho[19].condicao = true;
    baralho[19].num=29;

    baralho[20].tipo = "FIRE      ";
    baralho[20].nome = "Growlithe ";
    baralho[20].ataque = 60;
    baralho[20].hp = 45;
    baralho[20].condicao = true;
    baralho[20].num=30;

    baralho[21].tipo = "WATER     ";
    baralho[21].nome = "Poliwag   ";
    baralho[21].ataque = 40;
    baralho[21].hp = 60;
    baralho[21].condicao = true;
    baralho[21].num=31;

    baralho[22].tipo = "GRASS     ";
    baralho[22].nome = "Weepinbell";
    baralho[22].ataque = 38;
    baralho[22].hp = 50;
    baralho[22].condicao= true;
    baralho[22].num=32;

    baralho[23].tipo = "GROUND    ";
    baralho[23].nome = "Geodude   ";
    baralho[23].ataque = 40;
    baralho[23].hp = 40;
    baralho[23].condicao = true;
    baralho[23].num=33;

    baralho[24].tipo = "ELECTRIC  ";
    baralho[24].nome = "Magnemite ";
    baralho[24].ataque = 35;
    baralho[24].hp = 30;
    baralho[24].condicao = true;
    baralho[24].num=34;

    baralho[25].tipo = "POISON    ";
    baralho[25].nome = "Grimer    ";
    baralho[25].ataque = 30;
    baralho[25].hp = 70;
    baralho[25].condicao = true;
    baralho[25].num=35;

    baralho[26].tipo = "ELECTRIC  ";
    baralho[26].nome = "Voltorb   ";
    baralho[26].ataque = 20;
    baralho[26].hp = 70;
    baralho[26].condicao = true;
    baralho[26].num=36;

    baralho[27].tipo = "GROUND    ";
    baralho[27].nome = "Cubone    ";
    baralho[27].ataque = 35;
    baralho[27].hp = 50;
    baralho[27].condicao = true;
    baralho[27].num=37;

    baralho[28].tipo = "PSYCHIC   ";
    baralho[28].nome = "Mew       ";
    baralho[28].ataque = 80;
    baralho[28].hp = 67;
    baralho[28].condicao = true;
    baralho[28].num=38;

    baralho[29].tipo = "NORMAL    ";
    baralho[29].nome = "Snorlax   ";
    baralho[29].ataque = 35;
    baralho[29].hp = 99;
    baralho[29].condicao = true;
    baralho[29].num=39;

    baralho[30].tipo = "WATER     ";
    baralho[30].nome = "Horsea    ";
    baralho[30].ataque = 43;
    baralho[30].hp = 30;
    baralho[30].condicao = true;
    baralho[30].num=40;

    baralho[31].tipo = "NORMAL    ";
    baralho[31].nome = "Eevee     ";
    baralho[31].ataque = 70;
    baralho[31].hp = 40;
    baralho[31].condicao = true;
    baralho[31].num=41;

    baralho[32].tipo = "PSYCHIC   ";
    baralho[32].nome = "Mewtwo    ";
    baralho[32].ataque = 99;
    baralho[32].hp = 99;
    baralho[32].condicao = true;
    baralho[32].num=42;

    baralho[33].tipo = "BUG       ";
    baralho[33].nome = "Venonat   ";
    baralho[33].ataque = 30;
    baralho[33].hp = 40;
    baralho[33].condicao = true;
    baralho[33].num=43;
}

void menu(){
    int opcao;
    banner();
    cout << "----------------------------------------------------------------------------------" << endl;
    cout << "[1] - INICIAR JOGO " << endl;
    cout << "[2] - MODO DE JOGO " << endl;
    cout << "[3] - INSTRUCOES   " << endl;
    cout << "[4] - CREDITOS     " << endl;
    cout << "----------------------------------------------------------------------------------" << endl;

    cout << "Opcao: ";
    cin >> opcao;
    
    if(opcao==1){
        play1 = true;
        play2 = false;
    }else if(opcao==2){
        system("clear");
        select_numero_players();
    }else if(opcao==3){
        string a;
        cout << "INSTRUÇOES:                                                                                           " << endl;
        cout << "                                                                                                      " << endl;
        cout << "CADA JOGADOR INICIA COM 5 CARTAS, ESSAS CARTAS SAO ESCOLHIDAS ALEATORIAMENTE DE UM DECK COM 34 CARTAS " << endl;
        cout << "DIFERENTES, APOS A FORMACAO DOS DERKS DE CADA JOGADOR, O JOGO E INICIADO E O PLAYER 1 SELECIONA       " << endl;
        cout << "UMA CARTA DISPONIVEL EM SUA MAO A PARTIR DO [NUM] PARA ATACAR O OPONENTE, QUE PODE SER O PLAYER 2 OU  " << endl;
        cout << "O COMP QUE POR SUA VEZ FAZ O MESMO PROCESSO ESCOLHENDO A CARTA PARA RECEBER O ATAQUE. DANDO INICIO    " << endl;
        cout << "A BATTLE FASE, CADA POKEMON TEM UM [TIPO] ASSOCIADO QUE INTERFERE DIRETAMENTE NO ATAQUE, UMA VEZ QUE  " << endl;
        cout << "CERTOS TIPOS TEM VANTAGENS SOBRE OUTROS, FAZENDO COM QUE O [ATK] DA CARTA TENHA UM BUFFER ADCIONAL,   " << endl;
        cout << "ALEM DAS CARTAS O ATAQUE PARA SER EFETIVADO DEPENDE DA SORTE DE CADA JOGADOR, O POKEMON A RECEBER     " << endl;
        cout << "O ATAQUE TEM 50% DE CHANCE DE DESVIAR. NO FINAL DA BATTLE FASE SE A CARTA TIVER SOFRIDO UM DANO QUE   " << endl;
        cout << "REDUZA SEU HP A 0, A CARTA É REMOVIDA DO JOGO. GANHA QUEM ELEMINAR TODAS AS CARTAS DE SEU OPONENTE.   " << endl;
        cout << "                                                                                                      " << endl;
        cout << "|----------------------------------------------------------------------------------------------------|" << endl;
        cout << "|                                    VANTAGENS D0 TIPO D0 POKEMON:                                   |"<< endl;
        cout << "|----------------------------------------------------------------------------------------------------|" << endl;
        cout << "|                  TIPO                          |                       VANTAGENS                   |" << endl;
        cout << "|------------------------------------------------|---------------------------------------------------|" << endl;
        cout << "|                 GRASS                          |            WATER, ELETRIC, GROUND, GRASS          |" << endl;
        cout << "|                 WATER                          |                  FIRE, GROND, WATER               |" << endl;
        cout << "|                 FAIRY                          |                         BUG                       |" << endl;
        cout << "|                 POISON                         |                  FAIRY, GRASS, BUG                |" << endl;
        cout << "|                 BUG                            |                PSYCHIC, GRASS, GROUND             |" << endl;
        cout << "|                 PSYCHIC                        |                        POISON                     |" << endl;
        cout << "|                 ELETRIC                        |                      FLY, WATER                   |" << endl;
        cout << "|                 GROUND                         |            FIRE, NORMAL, FLY, POISON, BUG         |" << endl;
        cout << "|                 FLY                            |                       BUG, GRASS                  |" << endl;
        cout << "|                 FIRE                           |                    FIRE, BUG, GRASS               |" << endl;
        cout << "|                 NORMAL                         |                    NENHUMA VANTAGEM               |" << endl;
        cout << "|----------------------------------------------------------------------------------------------------|" << endl;
        cout << "                                                                                                      " << endl;
        cout << "                                                                                                      " << endl;
        cout << " DIGITE 'EXIT' PARA VOLTAR A TELA INICIAL :                                                           " << endl;
        cin >> a;
        system("clear");
        menu();
    }else if(opcao==4){
        system("clear");
        creditos();
        this_thread::sleep_for(chrono::milliseconds(3000));

        system("clear");
        menu();
    }else{
        cout << "OPCAO INVALIDA, TENTE NOVAMENTE..." << endl;
        this_thread::sleep_for(chrono::milliseconds(1500));
        system("clear");
        menu();
    }
}

void creditos()
{
    cout << endl << "DESENVOLVIDO POR: " << endl << "Pablwo Araujo" << endl <<"Natan Ataide" << endl << "Luiz Boas" << endl << "Almir Crispiniano" << endl << "Walisson Farias" << endl;
}

void layout(){
    if(vez%2==0){
        whoAtk(1);
        cout <<"\n-------------------------------------------VS-------------------------------------------\n"<<endl;
        if(play2==1){
            whoDef(2);
        }else{
            whoDef(0);
        }
    }else{
        if(play2==1){
            whoAtk(2);
        }else{
            whoAtk(0);
        }
        cout <<"\n-------------------------------------------VS-------------------------------------------\n"<<endl;
        whoDef(1);
    }
}

void batalha(Carta carta1, Carta carta2){    
    system("clear");
    cout << carta1.nome + "/ ATK:" + std::to_string(carta1.ataque) + "/ HP:" + std::to_string(carta1.hp) << endl;
    chamaArt(carta1.nome);
    cout <<"-------------------------------------------VS-------------------------------------------"<<endl;

    cout << carta2.nome + "/ ATK:" + std::to_string(carta2.ataque) + "/ HP:" + std::to_string(carta2.hp) << endl;
    chamaArt(carta2.nome);
    this_thread::sleep_for(chrono::milliseconds(5000));
}

Carta ataque(Carta carta1,Carta carta2){
    int atCarta1 = carta1.ataque;
    string grass   = "GRASS     ";
    string fire    = "FIRE      ";
    string water   = "WATER     ";
    string poison  = "POISON    ";
    string bug     = "BUG       ";
    string normal  = "NORMAL    ";
    string psychic = "PSYCHIC   ";
    string eletric = "ELECTRIC  ";
    string ground  = "GROUND    ";
    string fly     = "FLY       ";
    string fairy   = "FAIRY     ";
    
    system("clear");
    if(carta1.tipo == grass){
        if (carta2.tipo == water || carta2.tipo == eletric || carta2.tipo == ground || carta2.tipo == grass){
            atCarta1 = atCarta1 + 10; 
            superEfetivo();
        }else{
            ataqueRealizado();
        }
    }else if(carta1.tipo == fire){
        if (carta2.tipo == fire || carta2.tipo == bug || carta2.tipo == grass){
            atCarta1 = atCarta1 + 10; 
            superEfetivo();
        }else{
            ataqueRealizado();
        }
    }else if(carta1.tipo == water){
        if (carta2.tipo == fire || carta2.tipo == ground || carta2.tipo == water){
            atCarta1 = atCarta1 + 10; 
            superEfetivo();
        }else{
            ataqueRealizado();
        }
    }else if(carta1.tipo == poison){
        if (carta2.tipo == fairy || carta2.tipo == grass || carta2.tipo == bug){
            atCarta1 = atCarta1 + 10; 
            superEfetivo();
        }else{
            ataqueRealizado();
        }
    }else if(carta1.tipo == bug){
        if (carta2.tipo == psychic || carta2.tipo == grass || carta2.tipo == ground){
            atCarta1 = atCarta1 + 10; 
            superEfetivo();
        }else{
            ataqueRealizado();
        }
    }else if(carta1.tipo == psychic){
        if (carta2.tipo == poison){
            atCarta1 = atCarta1 + 10; 
            superEfetivo();
        }else{
            ataqueRealizado();
        }       
    }else if(carta1.tipo == eletric){
        if (carta2.tipo == fly || carta2.tipo == water){
            atCarta1 = atCarta1 + 10; 
            superEfetivo();
        }else{
            ataqueRealizado();
        }
    }else if(carta1.tipo == ground){
        if (carta2.tipo == fire || carta2.tipo == normal || carta2.tipo == fly || carta2.tipo == poison || carta2.tipo == bug ){
            atCarta1 = atCarta1 + 10; 
            superEfetivo();
        }else{
            ataqueRealizado();
        }
    }else if(carta1.tipo == fly){
        if (carta2.tipo == bug || carta2.tipo == grass){
            atCarta1 = atCarta1 + 10; 
            superEfetivo();
        }else{
            ataqueRealizado();
        }
    }else if(carta1.tipo == fairy){
        if (carta2.tipo == bug){
            atCarta1 = atCarta1 + 10; 
            superEfetivo();
        }else{
            ataqueRealizado();
        }
    }else{
        ataqueRealizado();
    }      
    this_thread::sleep_for(chrono::milliseconds(2000));

    carta2.hp = carta2.hp - atCarta1;
    if(carta2.hp<=0){
        carta2.hp=0;
        foraDeCombate();
        this_thread::sleep_for(chrono::milliseconds(3000));
    }
    return carta2;
}

void mostraDeck(int jogador, Carta p1[]){
    if(jogador==1){
        cout<< "PLAYER 1: " <<endl;
    }else{
        if(play2==true){
            cout<< "PLAYER 2: " <<endl;
        }else{
            cout<< "COMP: " <<endl;
        }
    }
    string tipoFull, nomeFull,atkFull, hpFull, layout,num;
    for(int i = 0; i <= 4; i++){
        if(p1[i].condicao==true){
            layout+= "-----------------";
            nomeFull += "|Nome:" + p1[i].nome+"|";
            tipoFull += "|Tipo:" + p1[i].tipo+"|";
            atkFull += "|ATK: " + std::to_string(p1[i].ataque)+ "        "+"|";
            hpFull += "|HP:  " + std::to_string(p1[i].hp)+ "        "+"|";
            num+= "|NUM: "+ std::to_string(p1[i].num)+"        "+"|";
        }
    }
    cout << "         " + layout << endl;
    cout << "         " + nomeFull<< endl;
    cout << "         " + tipoFull<< endl;
    cout << "         " + atkFull << endl;
    cout << "         " + hpFull << endl;
    cout << "         " + num << endl;
    cout << "         " + layout << endl;
}


void setup(){
    inicializa_cartas();
    inicializar_players();
}

int ia(Carta player[]){
    int melhorCarta = 0;
    int j = -1;
    for(int i = 0; i<=4; i++){
        if (player[i].condicao == true){
            if (player[i].ataque>= melhorCarta && vez%2 == 1){
                j = i;
                melhorCarta= player[i].ataque;
            }
            if (player[i].hp >= melhorCarta && vez%2 == 0){
                j = i;
                melhorCarta= player[i].hp;
            }
        }
    }
    return j;
}

int selecionaCarta(bool play, Carta mao[]){
    int numCarta = 0;
    int iReal1 = 0;
    if(play==true){
        cout <<"-------------------------------------------------------------------------------------------------------"<<endl;

        if(vez%2==0){
            cout << "PLAYER| [NUM] Selecione uma carta: " << endl;
        }else{
            if(play2==true){
                cout << "PLAYER| [NUM] Selecione uma carta: " << endl;
            }else{
                cout << "PLAYER| [NUM] Selecione uma carta: " << endl;

            }
        }
        cin >> numCarta;

        bool var = false;
        for(int i =0; i<=4; i++){
            if(mao[i].num==numCarta){
                if(mao[i].condicao==true){
                    var= true;
                    iReal1 = i;
                }
            }
        }
        if(var==false){
            cout << "[NUM] INVALIDO, TENTE NOVAMENTE! " << endl;
            selecionaCarta(play, mao);
        }else{
            return iReal1;
        }
    }else{
        return ia(mao);
    }
}

void atacar(bool x ,Carta playerX[] ,bool y ,Carta playerY[]){
    int num1 = selecionaCarta(x,playerX);
    int num2 = selecionaCarta(y,playerY);
    system("clear");
    batalha(playerX[num1], playerY[num2]);

    srand(time(0));
    int random = rand() % 2;

    if (random == 0){
        system("clear");
        desvio();
        this_thread::sleep_for(chrono::milliseconds(2000));
    }else{
        Carta newCarta = ataque(playerX[num1], playerY[num2]);
        if(newCarta.hp<=0){
            newCarta.condicao = false;
        }   
        playerY[num2]=newCarta;
        system("clear");
        batalha(playerX[num1], playerY[num2]);
    }
}

void select_numero_players()
{
    cout << "-------------------" << endl;
    cout << " [1] - SINGLEPLAY  " << endl;
    cout << " [2] - MULTPLAYER  " << endl;
    cout << "-------------------" << endl;
    int opcao;
    cout << "Opcao: ";
    cin >> opcao;
    switch (opcao)
    {
    case 1:
        play1 = true;
        play2 = false;
        break;
    case 2:
        play1 = true;
        play2 = true;
        break;
    default:
        cout << "OPCAO INVALIDA! TENTE NOVAMENTE." << endl  ;
        this_thread::sleep_for(chrono::milliseconds(2000));

        system("clear");
        select_numero_players();
        break;
    }
}

int verificaStatus(){
    int contador1 = 0;
    int contador2 = 0;
    for(int i =0; i<=4; i++){
        if(player1[i].condicao==false){
             contador1++;
        }
        if(player2[i].condicao==false){
            contador2++;
        }
    }
    if(contador1>=5){
        return 1;
    }else if(contador2>=5){
        return 2;
    }else{
        return 0;
    }
}

int main(){    
    system("clear");
    banner();
    this_thread::sleep_for(chrono::milliseconds(3000));
    system("clear");
    setup();
    menu();
    this_thread::sleep_for(chrono::milliseconds(1000));
    system("clear");

    while(true){ 
        layout();
        this_thread::sleep_for(chrono::milliseconds(3000));
        system("clear");
        mostraDeck(1, player1);
        mostraDeck(2, player2);

        if(vez%2==0){
            atacar(play1, player1, play2, player2);
        }else{
            atacar(play2, player2, play1, player1);
        }
        vez++;
        if (verificaStatus()!= 0){
            break;
        }
        system("clear");
    }
    system("clear");
    mostraDeck(1, player1);
    mostraDeck(2, player2);
    this_thread::sleep_for(chrono::milliseconds(2000));

    system("clear");
    if(verificaStatus()==1){
        if(play2==true){
            whoWins(2);
        }else{
            whoWins(0);
        }
    }else{
            whoWins(1);
    }
    return 0;
}

void superEfetivo(){
        cout << "                  █████╗ ████████╗ █████╗  ██████╗ ██╗   ██╗███████╗                 "<<endl;
        cout << "                 ██╔══██╗╚══██╔══╝██╔══██╗██╔═══██╗██║   ██║██╔════╝                 "<<endl;
        cout << "                 ███████║   ██║   ███████║██║   ██║██║   ██║█████╗                   "<<endl;
        cout << "                 ██╔══██║   ██║   ██╔══██║██║▄▄ ██║██║   ██║██╔══╝                   "<<endl;
        cout << "                 ██║  ██║   ██║   ██║  ██║╚██████╔╝╚██████╔╝███████╗                 "<<endl;
        cout << "                 ╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝ ╚══▀▀═╝  ╚═════╝ ╚══════╝                 "<<endl;
        cout << "                                                                                     "<<endl;
        cout << "                      ███████╗██╗   ██╗██████╗ ███████╗██████╗                       "<<endl;
        cout << "                      ██╔════╝██║   ██║██╔══██╗██╔════╝██╔══██╗                      "<<endl;
        cout << "                      ███████╗██║   ██║██████╔╝█████╗  ██████╔╝                      "<<endl;
        cout << "                      ╚════██║██║   ██║██╔═══╝ ██╔══╝  ██╔══██╗                      "<<endl;
        cout << "                      ███████║╚██████╔╝██║     ███████╗██║  ██║                      "<<endl;
        cout << "                      ╚══════╝ ╚═════╝ ╚═╝     ╚══════╝╚═╝  ╚═╝                      "<<endl;
        cout << "                                                                                     "<<endl;
        cout << "                 ███████╗███████╗███████╗████████╗██╗██╗   ██╗ ██████╗               "<<endl;
        cout << "                 ██╔════╝██╔════╝██╔════╝╚══██╔══╝██║██║   ██║██╔═══██╗              "<<endl;
        cout << "                 █████╗  █████╗  █████╗     ██║   ██║██║   ██║██║   ██║              "<<endl;
        cout << "                 ██╔══╝  ██╔══╝  ██╔══╝     ██║   ██║╚██╗ ██╔╝██║   ██║              "<<endl;
        cout << "                 ███████╗██║     ███████╗   ██║   ██║ ╚████╔╝ ╚██████╔╝              "<<endl;
        cout << "                 ╚══════╝╚═╝     ╚══════╝   ╚═╝   ╚═╝  ╚═══╝   ╚═════╝               "<<endl;                                            
}

void ataqueRealizado(){
        cout << "                 █████╗ ████████╗ █████╗  ██████╗ ██╗   ██╗███████╗                   "<<endl;
        cout << "                ██╔══██╗╚══██╔══╝██╔══██╗██╔═══██╗██║   ██║██╔════╝                   "<<endl;
        cout << "                ███████║   ██║   ███████║██║   ██║██║   ██║█████╗                     "<<endl;
        cout << "                ██╔══██║   ██║   ██╔══██║██║▄▄ ██║██║   ██║██╔══╝                     "<<endl;
        cout << "                ██║  ██║   ██║   ██║  ██║╚██████╔╝╚██████╔╝███████╗                   "<<endl;
        cout << "                ╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝ ╚══▀▀═╝  ╚═════╝ ╚══════╝                   "<<endl;
        cout << "                                                                                      "<<endl;
        cout << "        ██████╗ ███████╗ █████╗ ██╗     ██╗███████╗ █████╗ ██████╗  ██████╗           "<<endl;
        cout << "        ██╔══██╗██╔════╝██╔══██╗██║     ██║╚══███╔╝██╔══██╗██╔══██╗██╔═══██╗          "<<endl;
        cout << "        ██████╔╝█████╗  ███████║██║     ██║  ███╔╝ ███████║██║  ██║██║   ██║          "<<endl;
        cout << "        ██╔══██╗██╔══╝  ██╔══██║██║     ██║ ███╔╝  ██╔══██║██║  ██║██║   ██║          "<<endl;
        cout << "        ██║  ██║███████╗██║  ██║███████╗██║███████╗██║  ██║██████╔╝╚██████╔╝          "<<endl;
        cout << "        ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚═╝╚══════╝╚═╝  ╚═╝╚═════╝  ╚═════╝           "<<endl;
                                                                   
}

void desvio(){
        cout << "      ██████╗     ██████╗  ██████╗ ██╗  ██╗███████╗███╗   ███╗ ██████╗ ███╗   ██╗     "<<endl;
        cout << "     ██╔═══██╗    ██╔══██╗██╔═══██╗██║ ██╔╝██╔════╝████╗ ████║██╔═══██╗████╗  ██║     "<<endl;
        cout << "     ██║   ██║    ██████╔╝██║   ██║█████╔╝ █████╗  ██╔████╔██║██║   ██║██╔██╗ ██║     "<<endl;
        cout << "     ██║   ██║    ██╔═══╝ ██║   ██║██╔═██╗ ██╔══╝  ██║╚██╔╝██║██║   ██║██║╚██╗██║     "<<endl;
        cout << "     ╚██████╔╝    ██║     ╚██████╔╝██║  ██╗███████╗██║ ╚═╝ ██║╚██████╔╝██║ ╚████║     "<<endl;
        cout << "      ╚═════╝     ╚═╝      ╚═════╝ ╚═╝  ╚═╝╚══════╝╚═╝     ╚═╝ ╚═════╝ ╚═╝  ╚═══╝     "<<endl;
        cout << "                                                                                      "<<endl; 
        cout << "                ██████╗ ███████╗███████╗██╗   ██╗██╗ ██████╗ ██╗   ██╗                "<<endl; 
        cout << "                ██╔══██╗██╔════╝██╔════╝██║   ██║██║██╔═══██╗██║   ██║                "<<endl;
        cout << "                ██║  ██║█████╗  ███████╗██║   ██║██║██║   ██║██║   ██║                "<<endl;
        cout << "                ██║  ██║██╔══╝  ╚════██║╚██╗ ██╔╝██║██║   ██║██║   ██║                "<<endl;
        cout << "                ██████╔╝███████╗███████║ ╚████╔╝ ██║╚██████╔╝╚██████╔╝                "<<endl;
        cout << "                ╚═════╝ ╚══════╝╚══════╝  ╚═══╝  ╚═╝ ╚═════╝  ╚═════╝                 "<<endl;
}

void banner(){
        cout << "                                          ░░▓▓░░                                      "<<endl;
        cout << "                               ░░░░     ░░▓▓▀▒░                                       "<<endl;
        cout << "      ░░▒░░░░░░░░░░      ░▒░░▄▒░░░▄░▒  ░░░░░▒░▄  ░░░░░░░░▓▓░▌     ░▒▄▄                "<<endl;
        cout << "  ░▒░▓▓▓▓▓▓▓▓▓▓▓▓▓░░    ░░░░▓▓▌░▓▓▓▓▓░░░▓▓▓▓▓▓▓░░░░▓▓▓▌░▓▓▓░░    ░░░░▓▓▓░░░░▒▒▄▄      "<<endl;
        cout << "  ░░░▓▓▓▓▓▓▓▓░░░▓▓▓░░   ░░░░▓▓▌▓▓▓▓▀░░▓▓▌░ ░▓▓▀░░░░▓▓▓▓░▓▓▓▌░░▄▒▒▓░░░▓▓▓▌░░▓▓▓▌░░     "<<endl;
        cout << "   ░░░░░▓▓▓▓▓░░▐░▓▌░░▒▓░▓▓░░░▓▓▓▓▌░▒ ░▓▓▌▒▓▓▒░▓░░░░▓▓▓▓▓▓▓▓▌░▓▀░▓▓▓▓░░▓▓▓░░▓▓▓░▌      "<<endl;
        cout << "    ░░░░░▓▓▓▓▌░▄▓▀░░▓▌░░▓▓▐▓░░▓▓▓▓▓▓▓░░▀▓▓▓▓▓▓▓▓░░▓▓▓░▓▓▓▓▌░▓▓░░░░░▓░░▓▓▓▌▓▓▓░░       "<<endl;
        cout << "       ░░░▓▓▓▓▓▀░░░▓▓▓░░░▄▓▓░░▓░░░▀▀▓▓▓░░░░░░░░░░░▓▓▌░░▀░▐░░▓▓▓▓▓▓▓▓░░▌▐▓▓▓▓▌░        "<<endl;
        cout << "        ░░░▓▓▓▌░░░░░▓▓▓▓▓▓▓░░▓▓░░ ░░░░░▀▓▓░░   ░░░░░░░░░░░▓░░▀▓▓▓▀░░▓▓▌░▓▓▓▓░░        "<<endl;
        cout << "         ░░░▓▓▓▌░░░░░░▀▀░░░░░▀▀░░     ░░░░░░           ░░░░░░░░░ ░░░▀▓░░▓▓▓░▌         "<<endl;
        cout << "          ░░░▓▓▓░░                                           ░      ░░░░▓▓▌░          "<<endl;
        cout << "           ░░░░░░                                                     ░░░░░           "<<endl;            
}

void foraDeCombate(){
        cout << "                                                                                      "<<endl;
        cout << "           ██████╗  ██████╗ ██╗  ██╗███████╗███╗   ███╗ ██████╗ ███╗   ██╗            "<<endl;
        cout << "           ██╔══██╗██╔═══██╗██║ ██╔╝██╔════╝████╗ ████║██╔═══██╗████╗  ██║            "<<endl;
        cout << "           ██████╔╝██║   ██║█████╔╝ █████╗  ██╔████╔██║██║   ██║██╔██╗ ██║            "<<endl;
        cout << "           ██╔═══╝ ██║   ██║██╔═██╗ ██╔══╝  ██║╚██╔╝██║██║   ██║██║╚██╗██║            "<<endl;
        cout << "           ██║     ╚██████╔╝██║  ██╗███████╗██║ ╚═╝ ██║╚██████╔╝██║ ╚████║            "<<endl;
        cout << "           ╚═╝      ╚═════╝ ╚═╝  ╚═╝╚══════╝╚═╝     ╚═╝ ╚═════╝ ╚═╝  ╚═══╝            "<<endl;
        cout << "                                                                                      "<<endl;
        cout << "               ███████╗ ██████╗ ██████╗  █████╗     ██████╗ ███████╗                  "<<endl;
        cout << "               ██╔════╝██╔═══██╗██╔══██╗██╔══██╗    ██╔══██╗██╔════╝                  "<<endl;
        cout << "               █████╗  ██║   ██║██████╔╝███████║    ██║  ██║█████╗                    "<<endl;
        cout << "               ██╔══╝  ██║   ██║██╔══██╗██╔══██║    ██║  ██║██╔══╝                    "<<endl;
        cout << "               ██║     ╚██████╔╝██║  ██║██║  ██║    ██████╔╝███████╗                  "<<endl;
        cout << "               ╚═╝      ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝    ╚═════╝ ╚══════╝                  "<<endl;
        cout << "                                                                                      "<<endl;
        cout << "            ██████╗ ██████╗ ███╗   ███╗██████╗  █████╗ ████████╗███████╗              "<<endl;
        cout << "           ██╔════╝██╔═══██╗████╗ ████║██╔══██╗██╔══██╗╚══██╔══╝██╔════╝              "<<endl;
        cout << "           ██║     ██║   ██║██╔████╔██║██████╔╝███████║   ██║   █████╗                "<<endl;
        cout << "           ██║     ██║   ██║██║╚██╔╝██║██╔══██╗██╔══██║   ██║   ██╔══╝                "<<endl;
        cout << "           ╚██████╗╚██████╔╝██║ ╚═╝ ██║██████╔╝██║  ██║   ██║   ███████╗              "<<endl;
        cout << "            ╚═════╝ ╚═════╝ ╚═╝     ╚═╝╚═════╝ ╚═╝  ╚═╝   ╚═╝   ╚══════╝              "<<endl;
}

void whoWins(int player){
    if(player == 1){
        cout << "               ██████╗ ██╗      █████╗ ██╗   ██╗███████╗██████╗      ██╗              "<<endl;
        cout << "               ██╔══██╗██║     ██╔══██╗╚██╗ ██╔╝██╔════╝██╔══██╗    ███║              "<<endl;
        cout << "               ██████╔╝██║     ███████║ ╚████╔╝ █████╗  ██████╔╝    ╚██║              "<<endl;
        cout << "               ██╔═══╝ ██║     ██╔══██║  ╚██╔╝  ██╔══╝  ██╔══██╗     ██║              "<<endl;
        cout << "               ██║     ███████╗██║  ██║   ██║   ███████╗██║  ██║     ██║              "<<endl;
        cout << "               ╚═╝     ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚══════╝╚═╝  ╚═╝     ╚═╝              "<<endl;
        cout << "                                                                                      "<<endl;
        cout << "                          ██╗    ██╗██╗███╗   ██╗███████╗                             "<<endl;
        cout << "                          ██║    ██║██║████╗  ██║██╔════╝                             "<<endl;
        cout << "                          ██║ █╗ ██║██║██╔██╗ ██║███████╗                             "<<endl;
        cout << "                          ██║███╗██║██║██║╚██╗██║╚════██║                             "<<endl;
        cout << "                          ╚███╔███╔╝██║██║ ╚████║███████║                             "<<endl;
        cout << "                           ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚══════╝                             "<<endl;
    }else if(player == 2){
        cout << "              ██████╗ ██╗      █████╗ ██╗   ██╗███████╗██████╗     ██████╗            "<<endl;
        cout << "              ██╔══██╗██║     ██╔══██╗╚██╗ ██╔╝██╔════╝██╔══██╗    ╚════██╗           "<<endl;
        cout << "              ██████╔╝██║     ███████║ ╚████╔╝ █████╗  ██████╔╝     █████╔╝           "<<endl;
        cout << "              ██╔═══╝ ██║     ██╔══██║  ╚██╔╝  ██╔══╝  ██╔══██╗    ██╔═══╝            "<<endl;
        cout << "              ██║     ███████╗██║  ██║   ██║   ███████╗██║  ██║    ███████╗           "<<endl;
        cout << "              ╚═╝     ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚══════╝╚═╝  ╚═╝    ╚══════╝           "<<endl;
        cout << "                                                                                      "<<endl;
        cout << "                          ██╗    ██╗██╗███╗   ██╗███████╗                             "<<endl;
        cout << "                          ██║    ██║██║████╗  ██║██╔════╝                             "<<endl;
        cout << "                          ██║ █╗ ██║██║██╔██╗ ██║███████╗                             "<<endl;
        cout << "                          ██║███╗██║██║██║╚██╗██║╚════██║                             "<<endl;
        cout << "                          ╚███╔███╔╝██║██║ ╚████║███████║                             "<<endl;
        cout << "                           ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚══════╝                             "<<endl;
    }else{
        cout << "        ██████╗ ██████╗ ███╗   ███╗██████╗    ██╗    ██╗██╗███╗   ██╗███████╗         "<<endl;
        cout << "       ██╔════╝██╔═══██╗████╗ ████║██╔══██╗   ██║    ██║██║████╗  ██║██╔════╝         "<<endl;
        cout << "       ██║     ██║   ██║██╔████╔██║██████╔╝   ██║ █╗ ██║██║██╔██╗ ██║███████╗         "<<endl;
        cout << "       ██║     ██║   ██║██║╚██╔╝██║██╔═══╝    ██║███╗██║██║██║╚██╗██║╚════██║         "<<endl;
        cout << "       ╚██████╗╚██████╔╝██║ ╚═╝ ██║██║        ╚███╔███╔╝██║██║ ╚████║███████║         "<<endl;
        cout << "        ╚═════╝ ╚═════╝ ╚═╝     ╚═╝╚═╝         ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚══════╝         "<<endl;
        cout << "                                                                                      "<<endl;
        cout << "                 ██╗   ██╗ ██████╗ ██╗   ██╗    ██╗      ██████╗ ███████╗███████╗     "<<endl;
        cout << "                 ╚██╗ ██╔╝██╔═══██╗██║   ██║    ██║     ██╔═══██╗██╔════╝██╔════╝     "<<endl;
        cout << "                  ╚████╔╝ ██║   ██║██║   ██║    ██║     ██║   ██║███████╗█████╗       "<<endl;
        cout << "                   ╚██╔╝  ██║   ██║██║   ██║    ██║     ██║   ██║╚════██║██╔══╝       "<<endl;
        cout << "                    ██║   ╚██████╔╝╚██████╔╝    ███████╗╚██████╔╝███████║███████╗     "<<endl;
        cout << "                    ╚═╝    ╚═════╝  ╚═════╝     ╚══════╝ ╚═════╝ ╚══════╝╚══════╝     "<<endl;                                                
    }
}

void whoAtk(int player){
    if(player == 1){
        cout << "               ██████╗ ██╗      █████╗ ██╗   ██╗███████╗██████╗      ██╗              "<<endl;
        cout << "               ██╔══██╗██║     ██╔══██╗╚██╗ ██╔╝██╔════╝██╔══██╗    ███║              "<<endl;
        cout << "               ██████╔╝██║     ███████║ ╚████╔╝ █████╗  ██████╔╝    ╚██║              "<<endl;
        cout << "               ██╔═══╝ ██║     ██╔══██║  ╚██╔╝  ██╔══╝  ██╔══██╗     ██║              "<<endl;
        cout << "               ██║     ███████╗██║  ██║   ██║   ███████╗██║  ██║     ██║              "<<endl;
        cout << "               ╚═╝     ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚══════╝╚═╝  ╚═╝     ╚═╝              "<<endl;
        cout << "                                                                                      "<<endl;
        cout << "                  █████╗ ████████╗ █████╗  ██████╗ ██╗   ██╗███████╗                  "<<endl;
        cout << "                 ██╔══██╗╚══██╔══╝██╔══██╗██╔═══██╗██║   ██║██╔════╝                  "<<endl;
        cout << "                 ███████║   ██║   ███████║██║   ██║██║   ██║█████╗                    "<<endl;
        cout << "                 ██╔══██║   ██║   ██╔══██║██║▄▄ ██║██║   ██║██╔══╝                    "<<endl;
        cout << "                 ██║  ██║   ██║   ██║  ██║╚██████╔╝╚██████╔╝███████╗                  "<<endl;
        cout << "                 ╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝ ╚══▀▀═╝  ╚═════╝ ╚══════╝                  "<<endl;
    }else if(player == 2){
        cout << "              ██████╗ ██╗      █████╗ ██╗   ██╗███████╗██████╗     ██████╗            "<<endl;
        cout << "              ██╔══██╗██║     ██╔══██╗╚██╗ ██╔╝██╔════╝██╔══██╗    ╚════██╗           "<<endl;
        cout << "              ██████╔╝██║     ███████║ ╚████╔╝ █████╗  ██████╔╝     █████╔╝           "<<endl;
        cout << "              ██╔═══╝ ██║     ██╔══██║  ╚██╔╝  ██╔══╝  ██╔══██╗    ██╔═══╝            "<<endl;
        cout << "              ██║     ███████╗██║  ██║   ██║   ███████╗██║  ██║    ███████╗           "<<endl;
        cout << "              ╚═╝     ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚══════╝╚═╝  ╚═╝    ╚══════╝           "<<endl;
        cout << "                                                                                      "<<endl;
        cout << "                  █████╗ ████████╗ █████╗  ██████╗ ██╗   ██╗███████╗                  "<<endl;
        cout << "                 ██╔══██╗╚══██╔══╝██╔══██╗██╔═══██╗██║   ██║██╔════╝                  "<<endl;
        cout << "                 ███████║   ██║   ███████║██║   ██║██║   ██║█████╗                    "<<endl;
        cout << "                 ██╔══██║   ██║   ██╔══██║██║▄▄ ██║██║   ██║██╔══╝                    "<<endl;
        cout << "                 ██║  ██║   ██║   ██║  ██║╚██████╔╝╚██████╔╝███████╗                  "<<endl;
        cout << "                 ╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝ ╚══▀▀═╝  ╚═════╝ ╚══════╝                  "<<endl;
    }else{
        cout << "                         ██████╗ ██████╗ ███╗   ███╗██████╗                           "<<endl;
        cout << "                        ██╔════╝██╔═══██╗████╗ ████║██╔══██╗                          "<<endl;
        cout << "                        ██║     ██║   ██║██╔████╔██║██████╔╝                          "<<endl;
        cout << "                        ██║     ██║   ██║██║╚██╔╝██║██╔═══╝                           "<<endl;
        cout << "                        ╚██████╗╚██████╔╝██║ ╚═╝ ██║██║                               "<<endl;
        cout << "                         ╚═════╝ ╚═════╝ ╚═╝     ╚═╝╚═╝                               "<<endl;
        cout << "                                                                                      "<<endl;
        cout << "                  █████╗ ████████╗ █████╗  ██████╗ ██╗   ██╗███████╗                  "<<endl;
        cout << "                 ██╔══██╗╚══██╔══╝██╔══██╗██╔═══██╗██║   ██║██╔════╝                  "<<endl;
        cout << "                 ███████║   ██║   ███████║██║   ██║██║   ██║█████╗                    "<<endl;
        cout << "                 ██╔══██║   ██║   ██╔══██║██║▄▄ ██║██║   ██║██╔══╝                    "<<endl;
        cout << "                 ██║  ██║   ██║   ██║  ██║╚██████╔╝╚██████╔╝███████╗                  "<<endl;
        cout << "                 ╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝ ╚══▀▀═╝  ╚═════╝ ╚══════╝                  "<<endl;
    }
}

void whoDef(int player){
    if(player == 1){
        cout << "               ██████╗ ██╗      █████╗ ██╗   ██╗███████╗██████╗      ██╗              "<<endl;
        cout << "               ██╔══██╗██║     ██╔══██╗╚██╗ ██╔╝██╔════╝██╔══██╗    ███║              "<<endl;
        cout << "               ██████╔╝██║     ███████║ ╚████╔╝ █████╗  ██████╔╝    ╚██║              "<<endl;
        cout << "               ██╔═══╝ ██║     ██╔══██║  ╚██╔╝  ██╔══╝  ██╔══██╗     ██║              "<<endl;
        cout << "               ██║     ███████╗██║  ██║   ██║   ███████╗██║  ██║     ██║              "<<endl;
        cout << "               ╚═╝     ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚══════╝╚═╝  ╚═╝     ╚═╝              "<<endl;
        cout << "                                                                                      "<<endl;
        cout << "               ██████╗ ███████╗███████╗███████╗███╗   ██╗██████╗ ███████╗             "<<endl;
        cout << "               ██╔══██╗██╔════╝██╔════╝██╔════╝████╗  ██║██╔══██╗██╔════╝             "<<endl;
        cout << "               ██║  ██║█████╗  █████╗  █████╗  ██╔██╗ ██║██║  ██║█████╗               "<<endl;
        cout << "               ██║  ██║██╔══╝  ██╔══╝  ██╔══╝  ██║╚██╗██║██║  ██║██╔══╝               "<<endl;
        cout << "               ██████╔╝███████╗██║     ███████╗██║ ╚████║██████╔╝███████╗             "<<endl;
        cout << "               ╚═════╝ ╚══════╝╚═╝     ╚══════╝╚═╝  ╚═══╝╚═════╝ ╚══════╝             "<<endl;
    }else if(player == 2){
        cout << "              ██████╗ ██╗      █████╗ ██╗   ██╗███████╗██████╗     ██████╗            "<<endl;
        cout << "              ██╔══██╗██║     ██╔══██╗╚██╗ ██╔╝██╔════╝██╔══██╗    ╚════██╗           "<<endl;
        cout << "              ██████╔╝██║     ███████║ ╚████╔╝ █████╗  ██████╔╝     █████╔╝           "<<endl;
        cout << "              ██╔═══╝ ██║     ██╔══██║  ╚██╔╝  ██╔══╝  ██╔══██╗    ██╔═══╝            "<<endl;
        cout << "              ██║     ███████╗██║  ██║   ██║   ███████╗██║  ██║    ███████╗           "<<endl;
        cout << "              ╚═╝     ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚══════╝╚═╝  ╚═╝    ╚══════╝           "<<endl;
        cout << "                                                                                      "<<endl;
        cout << "               ██████╗ ███████╗███████╗███████╗███╗   ██╗██████╗ ███████╗             "<<endl;
        cout << "               ██╔══██╗██╔════╝██╔════╝██╔════╝████╗  ██║██╔══██╗██╔════╝             "<<endl;
        cout << "               ██║  ██║█████╗  █████╗  █████╗  ██╔██╗ ██║██║  ██║█████╗               "<<endl;
        cout << "               ██║  ██║██╔══╝  ██╔══╝  ██╔══╝  ██║╚██╗██║██║  ██║██╔══╝               "<<endl;
        cout << "               ██████╔╝███████╗██║     ███████╗██║ ╚████║██████╔╝███████╗             "<<endl;
        cout << "               ╚═════╝ ╚══════╝╚═╝     ╚══════╝╚═╝  ╚═══╝╚═════╝ ╚══════╝             "<<endl;
    }else{
        cout << "                         ██████╗ ██████╗ ███╗   ███╗██████╗                           "<<endl;
        cout << "                        ██╔════╝██╔═══██╗████╗ ████║██╔══██╗                          "<<endl;
        cout << "                        ██║     ██║   ██║██╔████╔██║██████╔╝                          "<<endl;
        cout << "                        ██║     ██║   ██║██║╚██╔╝██║██╔═══╝                           "<<endl;
        cout << "                        ╚██████╗╚██████╔╝██║ ╚═╝ ██║██║                               "<<endl;
        cout << "                         ╚═════╝ ╚═════╝ ╚═╝     ╚═╝╚═╝                               "<<endl;
        cout << "                                                                                      "<<endl;
        cout << "               ██████╗ ███████╗███████╗███████╗███╗   ██╗██████╗ ███████╗             "<<endl;
        cout << "               ██╔══██╗██╔════╝██╔════╝██╔════╝████╗  ██║██╔══██╗██╔════╝             "<<endl;
        cout << "               ██║  ██║█████╗  █████╗  █████╗  ██╔██╗ ██║██║  ██║█████╗               "<<endl;
        cout << "               ██║  ██║██╔══╝  ██╔══╝  ██╔══╝  ██║╚██╗██║██║  ██║██╔══╝               "<<endl;
        cout << "               ██████╔╝███████╗██║     ███████╗██║ ╚████║██████╔╝███████╗             "<<endl;
        cout << "               ╚═════╝ ╚══════╝╚═╝     ╚══════╝╚═╝  ╚═══╝╚═════╝ ╚══════╝             "<<endl; 
    }
}

void chamaArt(string nome){

    if(nome=="Bulbasaur "){
        cout << "                                                           ▄▓▓▓ ▓░░                   "<<endl;
        cout << "                                        ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▓▓▓▓▓▓░▒▓▓░ ░░                 "<<endl;
        cout << "                                   ▄▄▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌▓▌▓▓▓▓▓▓▓▓▓▓▓░░░                  "<<endl;
        cout << "                                 ▓▓▓▓▓▓▓▓▓▓▓▓▀▒▄▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░░░░                  "<<endl;
        cout << "                               ▓░▓▓▓▓▓▓▓▓▓▓░▄▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░▐░░                  "<<endl;
        cout << "            ▄▓▓▓▓▓▓░ ▄▄▄▄▄▄▄▄▄▄▄░░▀▀▓▓▀▒▄▄▄▓▓▓░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░░░░░░                 "<<endl;
        cout << "           ▐▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌▓░▓▓▓▓▓▓▓▓▓▓▓▓▓▓░░░░░░░░                "<<endl;
        cout << "           ▓▓▓▓▓▓▓▓▓▓▓▓▀▀░░░░░░▄▓▌▓▓▓▓▓▓▓▌▓▓▓▌▓▌▓▓▓▓▓▓▓▓▓▓░░░░░░░░░░░░░░              "<<endl;
        cout << "           ▓▓▓▓▓▓▓▓▀░░░░░░░░░▄▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░ ░░░░░░░░░░░░░░░░░░░░░░░▌             "<<endl;
        cout << "         ▓▓▓▓▓▓▓▓▓▓▄░░░░░░▄▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░░▌░░░░░░░░░░░░░░░░░░░░▓░░░▌            "<<endl;
        cout << "        ▓▓▀▓▓▓▓▀░▐▓▓▓▓▄▄▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░▓░ ░░░░░░░░░░░░░░░░░░░ ░░░░▌           "<<endl;
        cout << "       ▓▄█░▓▓▐▓░░▓▓▓▓▓▓▓▓▓▓▓▓▓▀▓▓▓▓▓▄ ░░▀▓▓▓▓░▓░░░▓▄░░░░░░░░░░░░░░░░░ ░░░░░           "<<endl;
        cout << "      ▌██░░▐▓▐▓▓▓▓▓▓▓▀░░▐▓▓▓▓░▓▓▓▒██░░░▄░░▓▓░░░░▓▌▓░░░░░░░░░░░░░░░░░░░░░░░░▌          "<<endl;
        cout << "     ▐▐█░░█▐▓▓▓▓▓▓▓▓ ░░░▐▓▓▓▓▓▓▓▐██▌░░██▌░░▓░░▓▓▓░▐░▓░░░░░░░░░░░░░░░░░░░░░░░          "<<endl;
        cout << "     ▓██░░█▐▓▓▓▓▓▓▓▓▓▓▄░▓▓▓▓▓▓▓░███░░░██▌░░▐░░▓░░░░░░░░░░░░░░▒░░░░░░░░░░░░░           "<<endl;
        cout << "    ▐▓▀█▌░░▐▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▐███▌░░░▀░░░▐▓▓░░░░░░░░░░░░░░░░ ░░░░░░░░░░░░           "<<endl;
        cout << "    ▐▓▓▓▓▄▄▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▐████░▌▀░▒▒▄▓░░░░░░░░░░░▌░░░░░░░▐▓░░░░░░░░░            "<<endl;
        cout << "     ▒░▀▓▓▓▓▓▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▀░░░░░░░░░░░░░▌░░░░░░▄░░▌░▓░░░              "<<endl;
        cout << "       ▀▓▒░░▀▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▀▀▒ ▒▄▒▓░░░░░░░░░░░░░░░░░░▓░░░░░░▄                 "<<endl;
        cout << "          ▀▓▒▄ ░░░░░░▄▄▄▄▄▄░░░░░▒▓░░░░▓░░░░░▓▓▄▓░▓▓▓▓▓▓▓▌░░░░░░▓▓▓░░░▌                "<<endl;
        cout << "             ▒▀▓▓░▀▀▓▓▓▓▓▓▓▓▓▓▀▀░▄▒░░░▓▓░▓▀▄▓▓▓▓▓▓▓▓▓▓▓▓▌░▓░▓▓▓▀▀▓░░░░▌               "<<endl;
        cout << "             ▓▓▓▄▄▒▀▒▒▒▄▄░░▄▒▓░░░▓▓▒▀░░░░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌░▄▓▀░░░░▐░░░░░               "<<endl;
        cout << "             ▓▓▓▓▓▀▀▓▓▓▓░░░░░░░▒▒▓░░░░░░░▄▓▓▓▌░░░▓▓▓▓▓▓▓ ▓▓░░░░░░▐░░░░░▌              "<<endl;
        cout << "              ▓▒░░░░▓▓▓▓▓▒▒░▓░░░░░░░░░░▌▒▀▒░░▓▓▄▄▓▓▓▓▓▓▌▐▓▓▒░░░░░░░░░░░▌              "<<endl;
        cout << "               ▓░░░░▐▓▓▓▓▓░░▒░ ▀▀▓░░░░░ ▒░░░░▓▓▓▓▓▓▓▓▓▌ ░░░░▓▄░░░▄░░░░░▌              "<<endl;
        cout << "                ░░░▒▓▓▓▓▓▓▓▓▀     ░░░░ ░░░░░▓▓▓▓▓▓▓▓▓▀ ░░░░░░░░░░░░░░░░               "<<endl;
        cout << "                ▀▓▓▓▓░▓▓▓▓▓         ░▒ ░░░░▄▓▓▓▓▓▓▓▓     ░░░░░░░░░░░░░░               "<<endl;
        cout << "                ▄▐▄░▓░▄▓▓▀            ▓▓▓▓▓▓▓▓▓▓▓▓▀       ░░░░░░░▌▓░▌                 "<<endl;

    }else if(nome=="Charmander"){

        cout << "                          ▄▄▓▓▓▓▓▓▓▓▒▄                                                "<<endl;
        cout << "                        ▄▓██▓▓▓▓▓▓▓▓▓▓▓▓▒                                             "<<endl;
        cout << "                      ▄▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                                            "<<endl;
        cout << "                     ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▀▀▌▓░                                          "<<endl;
        cout << "                     ▒▓▌▓▓▓▓▓▓▓▓▓▓▓▓▄▓▌█▌ ▀▓                                          "<<endl;
        cout << "                     █▐▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓ ██  ▓▌                                         "<<endl;
        cout << "                    ░▀▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓    ░▐▓                                         "<<endl;
        cout << "                    ░  ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░░▄░░▐▓▌                                        "<<endl;
        cout << "                    ▓▄▄▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▄▓▒▓▓▓▓                                        "<<endl;
        cout << "                   ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▀▌▓▌                                        "<<endl;
        cout << "                   ▒▓▒▀▀▓▓▓▓▓▓▓▓▓▓▓▓▀▀▒░▌░▓▓▓                          ▐▓▒            "<<endl;
        cout << "                     ▀▌░▄░░▒▒▒▒░▒▒▒░░░░▒░▓▓▓░                          ▒▓▓░           "<<endl;
        cout << "                        ▀▌▒▒░▒▄▓▓▓▓▓▓▀░▓▓▓▓░                        ░▓░▓▓▓▌           "<<endl;
        cout << "                             ▀░▒▒▌▌▒▓▓▓▓▓▓▌                        ▐▓▓▓▓▓▓▓           "<<endl;
        cout << "                          ▄▄▓▓▓▓▓▒▒▒▀░▓▓▓▓▓▓▓▓▓▄▄▄                  ▓▓▓▓▓▓▓▓▓         "<<endl;
        cout << "                      ▄▓▓▓▓▓▓▓▓▄▓▓▓▓▓▄▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▄▄  ▄         ▄▓▓▓▓▓▓██▀         "<<endl;
        cout << "                ▒▓▓▓▓▓▓▓▓▓▓▓▌▌█████████▄▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▄▄      ▓▓▓▓▌▓▓▓█▌▄░        "<<endl;
        cout << "                ▀▓▓▓▓▓▓▓▓▓▓▓▐████████████▄▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▀░     ▐▓▓▓▓▓█▓▓▓▓▓░        "<<endl;
        cout << "                 ▓▀▀▀▀▀▀▀▀▀▀██████████████▌▓▓▒▒▀▀▀▀▀▀▀▀            ▀▓▓▓▓▓▓▓▓░         "<<endl;
        cout << "                            ███████████████▌▓▓▓▓▓                   ▐▓▓▓▓▓▓▀          "<<endl;
        cout << "                           ▐████████████████▌▓▓▓▓▓▄                    ▓▌             "<<endl;
        cout << "                           ▐█████████████████▐▓▓▓▓▓▓                  ▄▓▌             "<<endl;
        cout << "                           ▐█████████████████▌▓▓▓▓▓▓▓▄               ▄▓▓              "<<endl;
        cout << "                         ▄▓▌███████████████▓▓▀▓▓▓▓▓▓▓▓▄            ▄▓▓▌░              "<<endl;
        cout << "                       ▄▓▓▓▓▒▓▓█████▓▓▓▓▓▓▓▓▌▓██▓▓▓▓▓▓▓▌        ▄▒░░░▒▀               "<<endl;
        cout << "                      ███▓▓▓▓▒▓▓███▓▓▓▓█▓▓▓▓▐██▓▓▓▓▓▓▓▓▓▌▒░░░░░░░░░░▄                 "<<endl;
        cout << "                     ▓▓▓▓▓▓▓▓▓▌▓▀▓█▓▓▓▓▓▓▓██▐▓▓▓▓▓▓▓▓▓▓▓▓░░░░░░░▒▒▒▀                  "<<endl;
        cout << "                     ▓▓▓▓▓▓▓▓▓▓▓▓▒▒▀▀▓▓█▓███▌▓▓▓▓▓▓▓▓▓▓▓▓░▒▒░▒▄▒▀                     "<<endl;
        cout << "                      ▓▓▓▓▓▓▓▓▓▓▓▀         ▀▀ ▐▌▓▓▓▓▓▓▓▓▓▌▀▀▀                         "<<endl; 

    }else if(nome=="Squirtle  "){

        cout << "                                ▄▄▄██▓▓▓▓▓▓▓▓▄                                        "<<endl;
        cout << "                             ▄█████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▄                                    "<<endl;
        cout << "                           ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▄                                  "<<endl;
        cout << "                          ▄▒▓▓▓▓▓▓▓▓▓▓▓▓▓ ███ ▓▓▓▓▓▓▓                                 "<<endl;
        cout << "                         ░▀▓▓▓▓▓▓▓▓▓▓▓▓▓   ▀  ▐▓▓▓▓▓▓▓                                "<<endl;
        cout << "                         ░▐▓▓▓▓▓▓▓▓▓▓▓▓▌    ░░▐▓▓▓▓▓▓▓▌                               "<<endl;
        cout << "                        ▄░▓▓▓▓▓▓▓▓▓▓▓▓▓░▄▄▄▓▌█▒▓▓▓▓▓▓▓▓                               "<<endl;
        cout << "                       ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▄▌▓▓▓▓▓▓▓▓▌                               "<<endl;
        cout << "                       ▐▒▀▓▓▓▀▒▒▒▒▀▀▀▀▀▀▓▓▓▓▓▓▌▀▌▓▓▓▓▓░                               "<<endl;
        cout << "                        ▐▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒                                "<<endl;
        cout << "                          ▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌▐▌                                "<<endl;
        cout << "                             ▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓░▒                               "<<endl;
        cout << "                          ▄▄▓▌▄▄▒▀▀▓▓▓▓▓▓▓▓▓▓▓▀▒▄▄▒▒▀▐░░▒                             "<<endl;
        cout << "                    ▄▄▓▓▓▓▓▓▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▄▓▓▓▓▓▓▓▓▒░▒░▓                            "<<endl;
        cout << "                 ▄▓▓▓▓▓▓▓▓▀▐▓████▓▓▓▓▓▓▓▓▓▀▄▓██▓▓▓▓▌▓▓▌▐░▒▒                           "<<endl;
        cout << "            ▐▓▓▓▓▓▓▓▓▓▓▓▓▌▓████▀██▓▓▓▓▓▓▓▒▓▓▓▓▓▓▓▓▓▓▓▓▓░▓░░▓                          "<<endl;
        cout << "             ▒▓▒▓▓▓▓▓▓▓▓▌▓▓██████▓▓░▓▓▓▓▌▓▓▓▓▓▓▓▓▓▓▓▓▓▌▄▐░░▓▓                         "<<endl;
        cout << "            ▓▓▓▓▓▓▓▓▓▓▓▓▐████████▓▓▐█▓▓▓▐▓▀▒▒▀▓▓▓▓▓▓▓▌▄▓▐░▓▓▓                         "<<endl;
        cout << "                        ▌▀█████▓▓▓▓▓▓▓▓▀▓▓▓░▓▓▓▌▓▌▌▓▒▓▓█▒░▓▓▓▌                        "<<endl;
        cout << "                        ▓▌▓▓█▓█▓▓█▌▓██░▀▀▓▓▓▓▓▓▓▓░▒▒▓▓█▌░░░▓▌░                        "<<endl;
        cout << "                        ██▐▓▀▀▀█▓▓▌█▓▓▓▓▓▓▓▄▌▄▄▒▓▓▓░▓▓█░░░░░▒                         "<<endl;
        cout << "                        ▐▌▓▓▓▓▓▓▓▓░▓▓▓▓▓▓▓▓▓▐▓▓▓▓▓▓▌▓▓█░░░░▒░      ▄▓▓▓▓▓▓▓▓▒▄        "<<endl;
        cout << "                        ▄▐▓▓▓▓▓▓▓▓░▓▓▓▓▓▓▓▓▓▓▓▀▓▓▀▀▀▐▓▓▌▒░░▒░   ▄▓▓▓▓▓▓▓▓▓▓▓▓▓▓       "<<endl;
        cout << "                      ▄▓▓▌▓▓▓▓███▓▒▓▓▓▓▓▓▓▓▓▓▓▒▄▓▓▓▓▓▓▓▀░░░▒   ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓      "<<endl;
        cout << "                     ▓██▓▓▓▀▓▓▓▓██▌█▓▓▓▓▓▓▓▓▀▓▓▓▓▓▓▓▓▓▓▓▒░▒  ▄▓▓▓▓▓▓▌▒▒▒▒▒▒▒▓▓▓▓▌     "<<endl;
        cout << "                    ▐███▓▓▓▓▒▀▓▓▀▓▒▓▀▓▓▓▓▓▓▒▓▓▓▓▓▓▓▓▓▓▓▓▌░ ▒▓▓▓▓▓▓▓▓▐▓▓▓▓▓▓▓▓▓▓▓▌     "<<endl;
        cout << "                    ▓▓▓▓▓▓▓▓▓▓▒▀▓▓▓▓▓▓▓▒▓▀▀▐▓▓▓▓▓▓▓▓▓▓▓▓▌▌▒▓▓▓▓▓▓▓▓▌▒▓▓▓▓▓▓▓▓▓▓▌      "<<endl;
        cout << "                    ▓▓▓▓▓▓▓▓▓▓▓▓▒  ▀▀▓▓▓▓▓▓░▓▓▓▓█▓▓▓▓▓▓▓▓▓▐▓▓▓▓▓▓▓▓▓▒▀▓▓▓▓▓▓▓▓▀       "<<endl;
        cout << "                   ▄▓▓▓▓▓▓▓▓▓▓▓░             ▓▓▓▓▓▓▓▓▓▓▓▓▓▐▌▓▓▓▓▓▓▓▓▓▓▒▒▒▀▀▀          "<<endl;
        cout << "                   ▐▓▓▌▓▓▓▓▓▀▀                ▓▓▓▓▓▓▓▓▓▓▓▓        ▀▀▀▀▀               "<<endl;

    }else if(nome=="Caterpie  "){

        cout << "                            ▄▄▓▓█▓▓▓▓▓▀▒▄▄▄░▄                                         "<<endl;
        cout << "          ▄▓▓▓▄        ▄▄▓▓█████▓▀▀▄▄▓▓▓▓▓▓▌▐▓▓▒▄                                     "<<endl;
        cout << "         ▒▓▓▓▓▓▓▓▒▄  ▓▓▓▓▓▓▓▓▀▀▄▓▓▓▓▓▓▓▓░░░▌▐▓▓▓▓▓▓▄                                  "<<endl;
        cout << "          ▀▓░▓▓▓▓▓▓▓▓▄▒▀▀▀▒▄▓▓▓▓▓▓▓░░░░▌▒▒▄▒▒▄████▄▌▓▒                                "<<endl;
        cout << "                ▀▀▓▓▓▓▓▓▓▓▓▓▓░░▒▀▒▒▄▄▒▓▓▓▌▐██▀ ░░░░▀█▄░                               "<<endl;
        cout << "               ▐▓▓▓▒▄▒▓░░░░▒▄▄▒▓▓▓▓▓▓▓▓▓▓░██   ░░░░░░▀▓░░                             "<<endl;
        cout << "               ▓▓▓▓▓▓▓▐░░░▓▐▓▓▓▓▓▓▓▓▓▓▓▓▓▐██     ░░░░ ▓▌▓                             "<<endl;
        cout << "              ▐▓▓▓▓▓▓▓▒▒▒▀░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▐██          ▓▌▓▌                            "<<endl;
        cout << "              ▐▓▓▓▓▓▓▓▓▓▓▌▌▌▓▓▓▓▓▓▓▓▓▓▓▓▓▓▀██        ▐▓░▓▓                            "<<endl;
        cout << "               ▓▓▓▓▓▀▒▄▄▒▒▓▒▓▄▄▄▒▓▓▓▓▓▓▓▓▓▓▒▀██▄▄ ▄▄▓▀░▓▓▌                            "<<endl;
        cout << "               ▀▓▌▄▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▄▀▓▓▓▓▓▓▓▓▓▓▒▓▀▀▀▀░░░▓▓░▄                           "<<endl;
        cout << "                ▀▄▓▓▓█▓▓▓▓▌▓▓▓▓▓▓▓▓▓▄▒░░░▓▓▓▓▓▓▓▓░░░░░░░▌▐▓▓                          "<<endl;
        cout << "                 ▓▓▓▀▄▓▓▓▓▓▓▓▒▒▓▓▓▓░░▓░▒░░░░░░░░░░░░░░░▌░▓▓▓▓                         "<<endl;
        cout << "                 ▓▌░▓▓▓▓▓▓▓▓▓▓▓▓▒▓▓░░░░ ░▓░░░░░░░░░░░░░▄▓▓▓▓▓▓                        "<<endl;
        cout << "                  ▌▓▓▓▓▓▓▓▓▓▓▓▓▓▓░░░░▒     ▀▒░░░░▓▒▀░▒▌▓▓▓▓▓▓▓░                       "<<endl;
        cout << "                   ▐▓▓▓▓▓▓▓▓▓▓░░░░░▒       ▄▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▌                       "<<endl;
        cout << "                       ▀▒░░░░░▌▀░▄▄▓▓▓▓▄▄  ░░░░▓▓▓▓▓▓▓▓█▀▀█▓▓▓░                       "<<endl;
        cout << "                       ▄██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒░░░▓▓▓▓▓▓▓█▓▓▓▓▓█▓▓               ▄▄▄      "<<endl;
        cout << "                      ▐████████████████▓▓▓▐░░░▓▓▓▓▓▓█▓▓▓▓▓▓█▓▀             ▄████▌     "<<endl;
        cout << "                      ██▄▀████████████▀▓▄▄▄▒▒░▓▓▓▓▓▓█▓▓▓▓▓▓▓              ▐▓▓▓▓▓▌     "<<endl;
        cout << "                     ████▓░██████████▄█████▌▓▐░▓▓▓▓▓░▓▓▓▓▓▀               ▓▓▓▓▓▓▌     "<<endl;
        cout << "                     ▐██▓▓▌▓████████▌▓████▓▓▓░░▀▓▓▓▓▓▓▓▓▀                 ▓▓▓▓▓▌      "<<endl;
        cout << "                       ▀▀▀▐▓▓██████▓▓▒▓▓▓▓▓▓▀▄░░▒▒▄▄▄▒▒                   ▓▓▓▓▌       "<<endl;
        cout << "                           ▄▄▒▀▀▀▀▀▀▒▄▄▄▒▓▓▓▓▄▒░▓▓▓▀▀▌▓                   ▓▓▓▌        "<<endl;
        cout << "                          ███████████▓▓▓▓▓▓▓▓▓░░▓▓▌▓░▌░                    ▓▌         "<<endl;
        cout << "                          ░▓▓██████▓▓▓▓▌▒▓▓▄▄▒▐░▓▓░▀░░▒▓▒                 ▒▄          "<<endl;
        cout << "                          █▄▀▓▓▓▓▓▓▓▓▓▌███▓▓▓▓░░▓▓▌▀▄▓░▓▓▓▌▄            ▄▒░           "<<endl;
        cout << "                           ▀▓▓▄▒▀▓▓▓▓▓▌▓██▓▓▓▓░▄░▄▒░░░░▌░░░░░░▓▒▒▄▄▄▄▀░▓░░░           "<<endl;
        cout << "                                  ▀▓▓▄▄▄▄▒▒▒▄▓▓▓▓▄░░░░░░░░░░░▌░░▓░░░░▒▐░▒░            "<<endl;

    }else if(nome=="Weedle    "){

        cout << "                                              ▄█                                      "<<endl;    
        cout << "                                           ▄███                                       "<<endl;
        cout << "                                         ██████                                       "<<endl;
        cout << "                                       ▄███████▌                                      "<<endl;
        cout << "                               ▄▄▓▓▓▓░██████▓██▌                                      "<<endl;
        cout << "                             ▀▓▓▓▓▓▓▓▓▓▓▓▀▀▀▀▓▓░▒                                     "<<endl;
        cout << "                          ▒ ▐▄▓▓▓▓▓▓▓▓▓▓▓░░░░░▓░░░▌                                   "<<endl;
        cout << "                       ▄▄▄▄▄▒▀▓▓▓▓▓▓▓▓░░░░▓░░▓▓░░░░▓▄                                 "<<endl;
        cout << "                     ▄▓▓█▓▓▓▓▓▓▓▒▓░░░░░░▓▀▀▒░░░░░░░░░▄                                "<<endl;
        cout << "                     ▓▓▓▓▓▓▓▓▓▓▓▌▌▒░░░░░  ▀ ▓░░░░░░░░░                                "<<endl;
        cout << "                      ▀░░▓▓▓▓▓░░▓▓▌▓▓▓░░▒▄▄▒░░░░░░░░░░░                               "<<endl;
        cout << "                       ▒▒▀▓▓▓▓▓▓▓▌░░░░░▓░░░░░░░░░░░▓▓░▌                               "<<endl;
        cout << "                       ▐▓░▒▒▒▒▒▒▄▓░░░░░░░░░▓░░░░░░▓▓▓░                                "<<endl;
        cout << "                        ▒▓░░░░░░░░░▓░░░░▓░░░░▓░░▓▓▓▓▓                                 "<<endl;
        cout << "                          ▓▓░░░░░░░▓░▓░░░░░░▓▓▓▓▓▓▓▓                                  "<<endl;
        cout << "                            ▌░▓░░░░░░░░▓▓▓▓▓▓▓▓▓▓▓▀                                   "<<endl;
        cout << "                            ▒▄▀▒░░░░░░░░░░░░▓▓▓▀                                      "<<endl;
        cout << "                        ▄▒▄▓▓▓░▌▒▄▄░▀▒▀▀▀▀▀░▒░                                        "<<endl;
        cout << "                        ▓░▓▓▓▓░░░░░░░░░░░░░░░▓                                        "<<endl;
        cout << "                          ▓▓▓▓░░░░▓▓▓▒▓▒▒░▓░░▓                                        "<<endl;
        cout << "                           ▓▓▌░░░░░░▐▓▓▓▌▒░░▓▌                            ▐           "<<endl;
        cout << "                             ▓▓▓░░░░▄▒▀▀░▓░▓▀                             ██          "<<endl;
        cout << "                              ▒▒▀▒▓░░░░░▒▒▒▒▓▓                          ▄██▓▓         "<<endl;
        cout << "                             ▐▌▓▓▓▒▒▒▄▒▒▓░░░░▓                        ▄▓█▓▓▓▓         "<<endl;
        cout << "                            ▐▌▀▓░░░░░░░▄▄▒▌░░░▓▓                     ▄▓▓▓▓▓▓▌         "<<endl;
        cout << "                                ▀▓░░░▌▒▓▓▓▐▀▒▓░░▓                    ▓▓▓▓▓▓▌          "<<endl;
        cout << "                                   ▄▒▒▒░░▄▄▓░▓░░░░▓▒             ▄▓░▓░▀▀▀▀▀           "<<endl;

    }else if(nome=="Pidgey    "){

        cout << "                        █ ▄▒▓▓▓▓▓░░░░                                                 "<<endl;
        cout << "                     ▐██░▓▀▌▓▓▀▒░░▄▄▄▄▄                                               "<<endl;
        cout << "                     ▓▀▒▀▀░▄▄▄██████████▓▄                                            "<<endl;
        cout << "                    ▐░░░▒▀▌▀▀ ▓▄   ░░░░░▒▀▀▀                                          "<<endl;
        cout << "                ▓█▓▓▓▓▓░▓▄▌  ██▀     ░░░░░                                            "<<endl;
        cout << "                  ░▒▀▓▓▓░████▄▄        ░░░                                            "<<endl;
        cout << "                   ▐░░▄▒▀▓██████▄      ▐░░░                                           "<<endl;
        cout << "                    ▄▄▌▒▒▓███████    ░░░░░░                                           "<<endl;
        cout << "                   ░▓▌▓▌▄▓██████▀ ░▄░░░░░░░░                                          "<<endl;
        cout << "                     ▓▓▓▓██████▌▄▓▓░░░░░░░░░░                                         "<<endl;
        cout << "                    ▄██████████▓▓▓▓░░░░░▓▓▓▓▓▓▓▒▄                                     "<<endl;
        cout << "                   ▄██████████▌▒▓▓▌░░░▓▓▓▓▓▓▓▓▓▓▓▓▓▒▄                                 "<<endl;
        cout << "                  ▄█████████████▄▓░░░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░░░                              "<<endl;
        cout << "                 ▐███████████████▓▄░░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░░░             ▄▄▄             "<<endl;
        cout << "                 ███████████████▓▓▓▓░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌░░░░         ▒▓▓▓▓▓▓▓▌▒▄        "<<endl;
        cout << "                ███████████████▓▓▓▓▓░░░░░▓▓▓▓▓▓▓▓▓▓▌░░░░░░░     ░░░▓▓▓▓▓▓▓▀▀▀▌▀▒░     "<<endl;
        cout << "                ██████████████▓▓▓▓▓▐░░░░░░░░░░░░░░░░░░░░░░ ▄░░░░░░░░░░░░░▒░░░░░       "<<endl;
        cout << "                █▐████▐█████▌█▓▓▓▐▓▐▓░░░░░░░░░░░░░░░░░░░░░░▓▓░░░░░░░░░░░░░░░░░░░░     "<<endl;
        cout << "                ▀ ▓██▓░▓▓█▌▓▓░▓▓▓░▀▐▓▌░░░░░░░░░░░░░░░░░░▓▓▓▓▌▌ ░░░░░░░░░░░░░          "<<endl;
        cout << "                  ▀▓▓▀▌▐▌▓▓▓▓▌▐▓▓░▌▓▓▓▄░░░░░░░░░░░▐▓▄▓▄▓▓▓▓▓█▒▄                       "<<endl;
        cout << "                      ▀░▀▐▓▓▓▓░▄▀▄▓▓▓▓▓▓░░░░░░░░░░░▐▓▓▓▓▓▓▓▓▓█▀                       "<<endl;
        cout << "                       ▀▓▓▓▄▓▓▓▓▓▓▓▓▓▓▓▓▓▓▄░░▄░▐▄▄▄▓▓▓█▓▓▓███▀▌▌                      "<<endl;
        cout << "                          ▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▀▓▓▓▓▓▓▓███████▀                       "<<endl;
        cout << "                              ▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▄▀▀▓▓▓▓▓▀████                       "<<endl;
        cout << "                                  ▒▀▀▓▓▓▓▓▓▓▓▓▓▀▀▀        ▀ ▀▀██                      "<<endl;
        cout << "                                ░▒░░▌      ▒▓▓                                        "<<endl;
        cout << "                     ▄▌▓▀░▄▒▄▓▒▒░░▒░░▒░░ ▄▒▓▓▓▒▄                                      "<<endl;
        cout << "                   ▐▀▀  ▐██▌░░░▄▓▓▓▓▒▒▒▀▀▌▓▓▓▌▀▓▓▌▓▓▐                                 "<<endl;
        cout << "                            ▐██▀░▀▀░▄▀▓▓▓▓▌▀                                          "<<endl;

    }else if(nome=="Rattata   "){

        cout << "                                               ▄▓▓▓▓▓▓▒▄                              "<<endl;
        cout << "                                              ▐▓▓▓▓▀▒▒▀▓▓▓▒▄                          "<<endl;
        cout << "                                               ▓▓▓▓▌▓░░▒░▓▓▓▓▄                        "<<endl;
        cout << "                                                ▀▓▓▓░░░░▓  ▀▓▓▓▄                      "<<endl;
        cout << "                                                   ▀▒▒▒░      ▓▓▓                     "<<endl;
        cout << "                                                                ▌▓▄                   "<<endl;
        cout << "                      ▒▓▓▒▄                                      ▀▓                   "<<endl;
        cout << "                     ▒▒▒░░░░░                                     ▓▓                  "<<endl;
        cout << "                    ▒▐▓▓░░░░░                ▄▄▒▓▓▄                ▌▌                 "<<endl;
        cout << "                    ▌▓▓▌▒▄▓▓▓▓▓▓▒▒▄▄     ▄▓▓▓▓▀▀▀▓▓▌                ░                 "<<endl;
        cout << "                    ▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓ ▄▓▓▌▒▄▓▓▓▓▌▌░                ░▌                "<<endl;
        cout << "              ▄    ▄▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌░▓▓▓▓▓▓▓▌▒░                ▒░                "<<endl;
        cout << "                ▒ ▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌▀▀▓░░░░░▓▓▓▓▓▓▓▌▒░                ░░                "<<endl;
        cout << "             ▄▄▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌▀░▐█▓▌░░░░░░▓▓▓▓▓▓▓░░▌  ▄▄▓▓▓▓▓▓▒▄    ░░                "<<endl;
        cout << "             ▒░▓▓▓▓▓▓░░░░░▌░▐█░▌███▌░░░░░░▀▀▓▓▓▓▀▒▒░▒▓▓▓▓▓▓▓▓▓▓▓▓▓▄▐░                 "<<endl;
        cout << "              ▓▄▄▄▓▓▓▓▓▓▓▓▓█▓▓▄▄██▌▒░░░░▒░▀▒▒▒░░▒▀░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌                  "<<endl;
        cout << "               ▌▓▓▓▓▓▓▒▓▓▓███▓▓▓▓▓▓▓▓▌▀▀▀▀▀▀▀▀▀▓▌▓▌▌▌▌▌▒▒▄▓▓▓▓▓▓▓▓▓▓▄                 "<<endl;
        cout << "              ▐██████▀▒▒░▀▓▓▓▓▓▓▓▓▓▓▓▓░░░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌                 "<<endl;
        cout << "        ▄░▒▓▓▓░█████▀▄░░░▒░▀▓▓▓▓▓▓▓▓▓▓▓░▓▓▌▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                 "<<endl;
        cout << "      ▀▓▓▓▓▓▒░▒▀░██░░░░░▓░▒▓▓▀▓▓▓▓▓▓▓▓▓▌░░▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒                "<<endl;
        cout << "     ▄▀▀▓▀▀▀░▀░░░░░▀▀▀▀▒░▒▓▓▓▓▓▀▓▓▓▓▓▓▓▓▒▓▓▓▓▓▓▓▓▓░░▓▓▄█████▌▓▓▓▓▓▓▓░░▒               "<<endl;
        cout << "                         ▓▓▓▓▓▓▐▓▓▓▓▀▀▀▒▓▓▓▓▓▓▓▓▓░▓▓▓▓▓▓▓▓▓▓▓▄▓▓▓▓▓░░░░░▒░            "<<endl;
        cout << "                        ▄▓███▓▄▓▓▀    ▓▓▓▓▓▓▓▓▓▌ ▀▓▓▓▓▓▓▓▓▀▀    ▒░░░░░░░░░░▌          "<<endl;
        cout << "                         ▀▀▓▓▀▀      ▓▓▓▓▓▓▓▓▓▀░▒▓░░░░             ░░░░▒░░░▌          "<<endl;
        cout << "                                    ░▓▓▓▓▓▓░▌ ▒▀▀▒▀                  ▄░░░░░░          "<<endl;
        cout << "                                   ▄░░░░░░░░                       ▄▀█████▌           "<<endl;
        cout << "                                ▄▀███▓▓░▒                           ▓▀ ▓▀             "<<endl;
        cout << "                                ▄█▀▐██▀                                               "<<endl;

    }else if(nome=="Ekans     "){

        cout << "                      ▄▄▄▓▓▓▓▓▒▄▄▄                                                    "<<endl;
        cout << "                  ▄▓███▓▓▓▓▓▓▓▓▓▓▓▌▒                                                  "<<endl;
        cout << "                ▓▓▓▓▓▓▓▓▓▓▀▄ ▄▄▄▒░░░░▒░                          ▐██▄                 "<<endl;
        cout << "              ▐▓▓▓▓▓▓▀▒▓▓▐██████▌░░░░░░░                           ▀▓▄▄               "<<endl;
        cout << "           ▄▓▓▒▄▄▄▓▓▓▓▓▓▓▐████▐█▀▒░░░░░░░                           ▀▓▓▓░             "<<endl;
        cout << "          ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▀░░▀▀░░░░░░░░░░░░░░                          ▄██▓▄           "<<endl;
        cout << "          ▀▓▓▓▀▓▓▓▓▀▀░░░░░░░░░░░░░░░░░░░░▒░░░▒▄                       ▀▓▓▌▓░          "<<endl;
        cout << "           ░░░░░░░░░░░░░░░░░▒░▒░░░░░░░░░░░░░░░▓▓▄                       ▄▓▓▓▄         "<<endl;
        cout << "                   ░░░░░░▄▄▄▄▄░▒░░░░░░░░░░░░░░░░▓▌                      ▓▓▓▓▓▌        "<<endl;
        cout << "                   ░░▄▓▓▓▓▓▓▓▓▓▐░░░░░░░░░░░░░░░░░▓▌                      ▀▄▓▓▄        "<<endl;
        cout << "                  ▐▐████████▓▓░▒░░░░░░░░░░░░░░░░░▓▓                      ▓▓▓▌░░       "<<endl;
        cout << "                  ▐▒▒▀▀▀▀▀▀▀░░░░░▒░░░░░░░░░░▓░░░░▓▓                      ░░░░░░░      "<<endl;
        cout << "                   ░░░░░░░░░░▄█▌▄░░░░░░░░░▓▓▓▌░░▓▀░                       ▄▓▓░▒░      "<<endl;
        cout << "                            ▄██▌▓▓▒▄▄▒░░░▀▀▀▒▒▄▄██                       ▐▓▓▓▌░░      "<<endl;
        cout << "                          ▄▀█▓▌▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██                        ▒▓▓▓▌░░░     "<<endl;
        cout << "                        ▓▓▓░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▀                         ▓▓▓▓░░░░     "<<endl;
        cout << "                     ▄▓▓▓░░░░░▒▓▓▓▓▓▓▓▓▓▓▓▓▓▌▀ ░░░░░░░░▒░░░░░           ▒▓▓▓░░░░      "<<endl;
        cout << "                   ▓▓▓▓▌░░░░░░▒░░░▒▀▀▀▀▀▀▒░░░░░░░░░░░░░░▒░░░░▒░        ▐▓▓▌░░░░░      "<<endl;
        cout << "                 ▐▓▓▓▓▓▓░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒░░░░▒░░░░░░░░     ░▓▓░░░░░░       "<<endl;
        cout << "                 ▓▓▓▓▓▓▓▓▓▌▓▄▄░░░░░░░░░░░░░▒░░░░▄▓▓▓▓▓▓▌░░░▒░░░░░    ░░░░░░░░░        "<<endl;
        cout << "                ▐▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░░░░░░░░░░░  ░░░░░░░░░░         "<<endl;
        cout << "                 ░░▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░░░░░░░░░░░░░░░░░░░░░░░░░░░          "<<endl;
        cout << "               ▄▄░░▒░░░░▀▌▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌▌▌░░░░░░░░░░░░░░░░░░░░░░░░░░░░           "<<endl;
        cout << "            ▄▓▓▓▓▓▒░ ░░▒░░░░░░░░░░░░░▀░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒░░░░░             "<<endl;
        cout << "          ▄▓▓▓▓▓▀▌▒▓░▒░░░░░░░░░░░░░░░░░░░░░░░░▒▄▒▒░░░░░░░░░░░░░░░░░░░▒░               "<<endl;
        cout << "         ▐▓▓▓▓▀▓▓▓▓▓▓▄░░░▒░░░░░░░░░░░░░░░░░░░░░░▒░░░░░▄▓▓▓▓▒░▒░░░░░░░░░░              "<<endl;
        cout << "         ▐░▓▓░▓▓▓▓▓▓▓▓▓▓▀▓▓▓▓▓▓▓▄▄▄░▄▄▄▄▄▄▄▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░░░░▒░░░░░░░░░              "<<endl;
        cout << "          ▒░░▒▌▓▓▓▓▓▓▓▓▌▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░░░░░░░░▐░░░░░░░▒               "<<endl;

    }else if(nome=="Pikachu   "){

        cout << "                                          ▄▓▓▓                                        "<<endl;
        cout << "                                        ▐▓▓▓▓▌                                        "<<endl;
        cout << "                                        ▓▓▓▓▓                                         "<<endl;
        cout << "                                        ▓▓▓▓▓                                         "<<endl;
        cout << "                                        ▓▓▓▓                                          "<<endl;
        cout << "                                        ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▄▄       ▄▄▄▄▄▒▓▓▓▓▒            "<<endl;
        cout << "                                        ▄▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▀              "<<endl;
        cout << "                      ▄▄▄▓▓▓▓          ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▀▀▓▀▀▀▀▀                 "<<endl;
        cout << "               ▄▄▒▓▓▓▓▓▓▓▓▓▓          ▓▓▓▀▐▄▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌                        "<<endl;
        cout << "         ▄▄▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓ ▄▒▄▌     ▄▓▓▓  ▀ ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌                        "<<endl;
        cout << "     ▄▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓ ▓▓▓▓▓▓▓▄ ▐▒▒▀▓▓▄▄▓▓▓▓▓▓▀▓▓▓▓▀█▌▐▓▓                         "<<endl;
        cout << "    ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓ ▐▓▓▓▓▓▓▓▌░░░░▐▓▓▓▓▓▀▀▀▀▀▓▓▓▓▄  ▄▓▌                         "<<endl;
        cout << "     ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌  ▓▓▓▓▓▓▓▓░░░░▄▓▓▓▓▌░░░░░░░▀▓▓▓▓▓▀                          "<<endl;
        cout << "     ▐▓▓▓▓▓▓▓▓▓▓▓▀  ▓▓▓▓▌    ▓▓▓▓▓▓▓▓▒▓▓▓▓▓▓▓▌▓▓▓▓▓▄░▓▓▓▓▌░▓░ ▄▄▄▄▄                   "<<endl;
        cout << "      ▐▓▓▓▓▓▓▀      ▓▓▓▓    ▄▐▓▓▓▓▓▓▓▓▒▓▓▓▓▓▓▓▒▓▓▓▀▄▓▓▓▓▓░▌░▓▓▓▓▓▓▓▓▌                 "<<endl;
        cout << "       ▀▓▓▓▀       ▐▓▓▓▓▄▄▓▓▓▓▐▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▄▒▒▄▓▓▓▓▓▓▀▒▓▓▓▓▓▓▓▓▓                   "<<endl;
        cout << "        ▀          ▓▓▓▓▓▓▓▓▓▓   ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▀                     "<<endl;
        cout << "                   ▓▌▀   ▐▓▒    ▄▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌▀                        "<<endl;
        cout << "                         ░░░ ░░▄▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▀▀                             "<<endl;
        cout << "                         ░░░ ░▄▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                               "<<endl;
        cout << "                             ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                               "<<endl;
        cout << "                           ▄▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                              "<<endl;
        cout << "                          ▐▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌                            "<<endl;
        cout << "                          ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌                           "<<endl;
        cout << "                           ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░                           "<<endl;
        cout << "                           ▄▒▓▒▀▓▓▓▓▀▀▀▀▀   ░▒▓▓▓▓▓▓▓▓▓▓▓▀                            "<<endl;
        cout << "                         ░▒▌▀▀                     ░▒▓▓▓▓▓▒                           "<<endl;

    }else if(nome=="Nidoran   "){

        cout << "                             ▓░░░▌░▄▄                     ▄▄▓▌                        "<<endl;
        cout << "                           ▓░░░░░░░░░                  ▄▓▓▓▌                          "<<endl;
        cout << "                        ░▓░░░░░░░░░░░           ▄▓░ ▄▓▓▓▓░▓▓▓                         "<<endl;
        cout << "                   ▄   ▓░░░░░░░░░░░░░░        ▓▓▌░▐▓▓▓▀░░░░░▓░▄▄▄                     "<<endl;
        cout << "                   ░▄▒░░░░░░░░░░░░░░░░░     ▓▓▌░▓▓▌▀░░░░░░░░▒▓▌                       "<<endl;
        cout << "                   ░░░░░░░░░░░░░░░░░░░░░  ▄▓▓░▓▓▀░░░░░░░░░░░▓░                        "<<endl;
        cout << "                   ░░░░░░░░░░░░░░░░░░░░░▄▓▓░▓▌░░░░░░░░░░░░░▐▌                         "<<endl;
        cout << "                  ▐░░░░░░░░░░░░░░░░░▄░▄▓▓░░▀░░░░░░░░░░░░░░░▓░                         "<<endl;
        cout << "                  ▐░░░░░░░░░░░░░░░░░▓▌▓▓░▀░░░░░░░░░░░░░░░░▐▓░        ▄▄               "<<endl;
        cout << "                 ░░░░░░░░░░░░░░░░░▓▌▓▓░▀░░░░░░░░░░░░░░░░░░▌▀      ▄▓▓▀                "<<endl;
        cout << "               ░ ░░░░░░░░░░░░░░░░░▓▌▓▓ ░░░░░░░░░░░░░░░░░░▓      ▄▓▓▓                  "<<endl;
        cout << "               ▐░░░░░░░░░░░░░░░░░▐▓▌▓░░░░░░░░░░░░░░░░░░░▓    ▄▓▓▓▓▌                   "<<endl;
        cout << "                ░░░░░░░░░░░░░░░░░▓▓░░░░░░░░░░░░░░░░░░▒░▓░  ▒▓▀▀░░░                    "<<endl;
        cout << "                 ░░░░░░░▄▄▓▓▓▓▓▓▌▓▌▌░░░░░░░░░░░░░░░░▌░░░░░░░░░░░░      ▄▄▓            "<<endl;
        cout << "                  ░░░▄▓▓▓▓▓▓▓▓▓▓░▓░░░░░░░░░░░░░░░░░░▄▌░░░░░░░░░░ ░▒░░░░▒░             "<<endl;
        cout << "                  ░▓▓▓▓▓▓▓▓▓▓▓▓▓▐▓▌░░░░░░░░░░░░░░▒░▓▀░░░░░▄▄▄▓░░░░░░░▒                "<<endl;
        cout << "                 ▄▓▓▓▓▓▓▓▓▓▓▓▓▓▓▐▓▌░░░▄▓░░░░░░▒░▄▒░▄▄▄▄▓▓▓▓▓▀░░░░░░░                  "<<endl;
        cout << "           ▄▄▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▐▌▌░░▓▓░░░░░░▄▒▒▄▒░▓▓▓▓▓▓▓▓▌░▄▄▄▒░░░                  "<<endl;
        cout << "           ▀▀▀▀▒▒▀▒▒▒▀▒▓▓▓▓▓▓▓▓▓▓▓▌▓▓▓░░░░░▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▌▓▓▓▀░░░░░░                "<<endl;
        cout << "             ▐▓▓▓░░░░░▓▓▓▓▓▓▓▓▓▓▒▓▓▓▓▌▒░░░░░░░░▓░░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▀░                  "<<endl;
        cout << "             ▓▓▓▓▒░░▄▓▓▓▓▓▓▓▓▀  ▐░▓▓▓▓▓░░░░░░░░░░░░░▓▓▓▓▓▓▓▓░░░░▓▄░░                  "<<endl;
        cout << "             ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▐█   ▓▓▓▓▓▓░░▐░░░░░░░░░░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌▄                 "<<endl;
        cout << "              ▓▓▓▓▓▓▓▓▓▓▓▒▓█▌▒▒▄░▓▓▓▓▓▓░░▐░░░▓░▓░░░▓▀▒▓░▓▓▓▓░░░░░▓▓░▓▌                "<<endl;
        cout << "              ▐▓▓▓▓▓▓▓▓░▄░▓▀▓▌▌▒▓▓▓▓▓▓▓░░▒░░░░░░░▓▓▓░▓░▓▓▓▓▓▓░░░░░▓▌░▓░               "<<endl;
        cout << "              ▐▓▓▓▓▓▓░▓▓▓▓▓▓▓▓░▓▓▓▓▓░▓▒░░░░░░░░░░▓▓░▓▓▓▓▓▓▓▓▓▓▓▓▓░▓▓░▓▓▌              "<<endl;
        cout << "              ▀▓▓▓▓▒▓▓▓▓▓▓▓▓▓▓▒▀░░▄▒▒▓░▓▓░░░░░░░▓▓▓░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░▓▓▓▓              "<<endl;
        cout << "            ▄░▄░░▓▄▒▒▓▓▓▓▒▀     ▓▓▓▓▓▓▓░▓▓▓▓▓▓▓▓▓▓▓▌▒▓▓░▓▓▓▓▓▓▓▓▓░▓▓▓▓▓▌              "<<endl;
        cout << "           ▀▀█▀▀  ▀██       ▄▓▓▓▓▓▓▓▓▓▓▌▓▓▓▓▓▌▀▀▀▀▀░░░▌▓▓░░░░▓▓▓▓▓▓▓▓▓▒               "<<endl;
        cout << "                           ▄█▌▓▄▓▓▓▓▓░░▌▀                ▀▒▓░▓▓░▓▓▒▒▒                 "<<endl;

    }else if(nome=="Clefairy  "){

        cout << "               ▒░░░▓▓▓▌▄█▄▄             ▄▄▄▄▄▄                                        "<<endl;
        cout << "                ░░░░░░▄██████▄▄     ▄▄███████████▄▄                                   "<<endl;
        cout << "                 ░░░▄███████████▌ ▄█████████████████▄                                 "<<endl;
        cout << "                 ▐░█████████████▀▄████████████████████  ▄▄▄▄▄▄▄▄▄▄▄▄▄▄                "<<endl;
        cout << "                  ▓█████████████▌████████▀█████▀███████▐▀███████████░▓▓▓░░░░░         "<<endl;
        cout << "                  ▐█████████████████████▐███████▒███████████████████▌░░░░░░           "<<endl;
        cout << "           ██▄   ░░▀█████████████▄██████████████▌████████████████████░░░▒             "<<endl;
        cout << "          ▄▓███▄▄▄░░▓█████████████▄▀████████████▐████████████████████▌░░              "<<endl;
        cout << "       ▐█▌███████▌░░▄███████████████▄▀███████▓▀▄█████████████████████▌                "<<endl;
        cout << "        ▄█████████▄▀████████████████████▓▓▓▓▓██████████████████████▓▀                 "<<endl;
        cout << "        ▐███████████▀██████████▒██░░███████████▀██████████████████▀  ░                "<<endl;
        cout << "         ████████████▌█████████▌██░▐██████████▌ ▐██▐████████████▌  ░░░                "<<endl;
        cout << "          ████████████████▀████▀██████████████▌▄██▀██████████████░░░    ▄             "<<endl;
        cout << "          ▐████████████████████▓█████▐▓▓▓▌▀█▓█████▀▀▀▀███████████▌    ▄██▌            "<<endl;
        cout << "           ▀█████████████████████████▐▓▓▓▓▓░█████▄████▀▄█████▀▀█▄█████████▌██▀        "<<endl;
        cout << "            ▀████████████████████████▌▀███▌█████████████████████████████████▌         "<<endl;
        cout << "             ▀█████████████████████████████████████████████████████████████▓█         "<<endl;
        cout << "             ██████████████████████████████████████████████████████████████           "<<endl;
        cout << "             ██████████████████████████████████████████████████████████▀▀             "<<endl;
        cout << "             ▓█████████████████████████████████████████████████████▀▀▌▓▓▌             "<<endl;
        cout << "             ▓▓▓███████████████████████████████████████████████▓▓▌▄▓▓▓▓▓▓             "<<endl;
        cout << "             ▐▓▓▓▓███████████████████████████████████████████▓▓▓▓▌▓▐▓▓▓▓▓             "<<endl;
        cout << "              ▓▓▓▓▓▓████████████████████████████████████████▓▓▓▓▓▐▌▓▓▓▓▓▓             "<<endl;
        cout << "              ▓▓▓▓▓▓▓▓▓▓████████████████████████████████▓▓▓▓▓▓▓▓░▌▓▓▓▓▓▓▌             "<<endl;
        cout << "              ▐▓▓▓▓▓▓▓▓▓▓▓▓▓▓██████████████████████▓▓▓▓▓▓▓▓▓▓▓▓▀▒▓▓▓▓▓▓▓              "<<endl;
        cout << "               ▐▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌▓▓▓▓▓▓▓▀               "<<endl;
        cout << "                ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▀▓▓▓▓▓▓▓                 "<<endl;
        cout << "                 ▓▓▓▓▓▓▓▓▓▓▓▓▓▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▀▓▓▓▓▓▀                   "<<endl;
        cout << "                  ▀▓▓▓▓▓▓▓▓▓▓▓▓▓▌  ▀▀▀▀▀▀▀▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▓▓▀▀                      "<<endl;

    }else if(nome=="Jigglypuff"){

        cout << "                       ▄████▄▄                                                        "<<endl;    
        cout << "                      ▐█▌ ▀█████▄▄                                                    "<<endl;    
        cout << "                      █▌    ▀██████▓▄                                                 "<<endl;    
        cout << "                     ▓▓       ▀███████▄   ▄▄▄█████▄▄▄                                 "<<endl;    
        cout << "                     █▌         █████▀▓████████████████▄                              "<<endl;    
        cout << "                    ▐▓░░░░  ▄▀█████▀▄███████████████████▌                             "<<endl;    
        cout << "                    █▓░░░▄████████████████████████████████                            "<<endl;    
        cout << "                    ▓▓▄█████████▌█████████████████████████▄                           "<<endl;    
        cout << "                   ▄████████████▄████████████████████████████▄▄▄▀▄▄▄▄                 "<<endl;    
        cout << "                  ▓████████████▌██████████████████████████████████████████▄▄          "<<endl;    
        cout << "                ▄██████████████▌█████████████▀▓▓▄▓▓▓▓▓██████████▀▀▀▀▀▀▀▀▀▀████▄       "<<endl;    
        cout << "               ▐████▀███▀░░░░░▀▀▐██████████▓▓▓▓▐▓▓▓▓████████████▌           ▓█        "<<endl;    
        cout << "               ████▄██▀░░░░░▐██▌░▐██████████▓▓▓▐▓████████████████▌        ▄▓█         "<<endl;    
        cout << "              ████▄██▌░░░░░░░░░░░██████████▓▓▀▄▓██████████████████ ░░░   ▓▓▀          "<<endl;    
        cout << "              ████▐██▌░░░░░░░░░░▐████▓▓▓▓▓▓▓▓▓▓▀███████████████████░░░▄▓▓▌            "<<endl;    
        cout << "             ▐████▌███▄▀▓▓▓▓▓▌▄▒█████████████▓███▀░░░░▄▄▀▄█████████░▄▓▓▀              "<<endl;    
        cout << "             ▐█████▄▀████▄▄██▀▓█████████████▌██▌░░░░░░▀█▀░▀████████▓▀▀                "<<endl;    
        cout << "        ▄▄▄▄▄░▓██████▓█████████████████████████░░░░░░░░░░░ ████████                   "<<endl;    
        cout << "       ▀█████▌▓▓▓███████████████▀██████████▌███░░░░░░░░░░░░███████▌                   "<<endl;    
        cout << "         ▀████▓▓▓▓▓█████████████████▀▀▀█████▀███░▓▓▓▓▓▓▓░▌████████                    "<<endl;    
        cout << "            ▀▓▓▀▓▓▓▓▓████████████████████████▄▀███▄▓▌▌▄▌█████████▀                    "<<endl;    
        cout << "                ▀▓▓▓▓▓▓▓▓█████████████████████████████▓████████▓▀                     "<<endl;    
        cout << "                 ▀▓▓▓▓▓▓▓▓██▓███████████████████████████████▓▓▓                       "<<endl;    
        cout << "                   ▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓███████████████████▀▓▓▓▓▀                        "<<endl;    
        cout << "                     ▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌███████▒▓▓▀                          "<<endl;    
        cout << "                   ▄▄▄▄▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▓████▓▐▀                            "<<endl;    
        cout << "                ▄██████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▀▓▓▓▀                              "<<endl;    
        cout << "               █████████▌▓▓▓▀ ▀▀▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▄▄▄                              "<<endl;    
        cout << "               ▀███████▀▀▀                    ▓▓▓▓███████▄                            "<<endl;    
        cout << "                                                ▀██████████                           "<<endl;

    }else if(nome=="Zubat     "){

        cout << "                            ░░░░░░▀▓                                                  "<<endl;    
        cout << "                        ░░░░░░░░░░▓                                                   "<<endl;    
        cout << "                    ░░▒▒░░░░░░░░░▒░                                                   "<<endl;    
        cout << "                 ░▒▒░░░░░░░░░░░░░░     ░▄                                             "<<endl;    
        cout << "              ░▒▒░░▓▓░░░░░░░░░░░░▓   ░░░░▒▄                                           "<<endl;    
        cout << "            ▒▒▓▓▓▓▓▓▓▓░░░░░▒▒░░░░▒   ▐░░░░░▒                                          "<<endl;    
        cout << "          ░▒▓▓▓▓▓▓▓░▓░░░░▒░░▄▓░░░▐   ▐░░░░░░▄                           ▄             "<<endl;    
        cout << "        ▒▒▓▓▓▓▓▓▓▓▓▓░▓░▒░░▒░░░░░░░░  ░▒░░░░▄░▄▄▄                       ▐▓▌            "<<endl;    
        cout << "       ░▓▓▓▓▓▓▓▓▓▓▓▓░▒░▄▒░░░░░░░░░░    ░░▀  ▐    ▌▒ ▒▀▒░░░░░░░▐       ▄░░▓▄           "<<endl;    
        cout << "               ▀▓▓▓▌░░▒░░░░░░░░░░░░░   ░        ▐▀ ▌░░░░░░░░░░       ▒░░░░▓           "<<endl;    
        cout << "                 ▀▌░▒░░░░░░░░░░░░░░░░   ▄          ▓░░░▐▓▓▌▀░      ░▒▓░░░░░▌          "<<endl;    
        cout << "                             ▀▒░░░░░░░▓▌▓▄▄░░░     ▌░░░░░        ▒░▒░░▓▓░░▌▒          "<<endl;    
        cout << "                                 ░░░░░░░▓▓▓▓▓▒░▀ ▄░           ░░▒▐░▓▓▓▓▓▓▓▓▐░         "<<endl;    
        cout << "                                   ░░░░░░░▓▓▓▓░░░▌      ░░░░░▓░▓▓░░▓▓▓▓▓▓▓▓░▌         "<<endl;    
        cout << "                                   ░░░░░░░░░░░░░░░░░░░░░░░▓▓▓▓▓▓▓░░▓▓▓▓▓▓▓▓▌▓         "<<endl;    
        cout << "                                   ▐░░░░░░░░░░░░░▓░░░░░▓▓▓▓▓▓▓▓▓▓░░▓▓▓▓▓▓▓▓▓▒         "<<endl;    
        cout << "                                   ░░░░░░░░░░░▒       ▀▓▓▓▓▓▓▓▓▓▓▐▐▓▓▓▓▓▌▓▓▓▐         "<<endl;    
        cout << "                                  ░░    ░░░░░            ▀▓▓▓▓▓▓▌░▓▓▓▓▓▓▓▓▓▓▐         "<<endl;   
        cout << "                                 ░        ▐░               ▐▓▓▓▓░░▓▓▓▓▓▓▓▓▓▌▒         "<<endl;    
        cout << "                                ░          ░                 ▒▓▌▒▌▓▓▓▓▓▓▓▓▓▌▌         "<<endl;    
        cout << "                               ░           ░                   ▐▒▒▓▓▓▓▓▓▓▓▓▌░         "<<endl;    
        cout << "                              ░           ▐                          ▀▓▓▓▓▓▒          "<<endl;    
        cout << "                             ░            ░                              ▓▓▒░         "<<endl;    
        cout << "                                         ░                              ▌▒            "<<endl;    
        cout << "                                        ▐                               ░             "<<endl;     
        cout << "                                                                                      "<<endl; 

    }else if(nome=="Oddish    "){

        cout << "                    ▐▄                                                                "<<endl;
        cout << "                    ▓▓▓▄                   ░                                          "<<endl;         
        cout << "                   ▐▓▓▒▓▓               ░░░░                                          "<<endl;         
        cout << "                   ▓▓▓▓▒▓▓▒          ░░░░░░                                           "<<endl;         
        cout << "                   ░▓▓▓▓▒▓▓▌       ░░░░░░░░       ▄▄▄▒▓▓▓▓▓▓▀▒▓▓▓▀░                   "<<endl;         
        cout << "                  ▐░░░▓▓▌▒▌░░░   ░░░░░░░░░░  ░▒▓▓▓▓▓▓▓▓▀▒▒▓▓▓▓▓▓░░░                   "<<endl;         
        cout << "                  ▐░░░░░▓▒░░░░░░░░░░░░░░░░▒░░░░░▓▓▓▒▒▓▓▓▓▓▓▓▓▓▌ ░░░                   "<<endl;         
        cout << "                  ▐░░░░░░░░░░░░░░░░░░░▒░░░░░░░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌░   ░░░                  "<<endl;         
        cout << "                   ░░░░░░░░▒░░░░░░░▒░░░░░░░░░▒▓▓▓▓▓▌░░▓▓░░░░                          "<<endl;         
        cout << "                   ░░░░░░░░░░░░░ ░░░░░░░▒░░▒░░░░░░░░░░░░░▒░░░░░░░░░░░░                "<<endl;         
        cout << "                    ░░░░░░░▒░░░░▒░░░░░░░▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░          "<<endl;         
        cout << "                      ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░              "<<endl;         
        cout << "                        ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒░▒▄▄▄                  "<<endl;         
        cout << "                         ▄▄▄░▄░░░░░░░░░░░░░░░░░▒░░░░░░░░░░░░▓▓▓▓▓▓▓▓▓▓▓▓▄▄            "<<endl;         
        cout << "                    ▄▓▓▓▓▓▓▓▓▓▓▓▌▓▄░░░░░░░░░░░░░░░░▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▓▓▓▒▀          "<<endl;         
        cout << "                 ▄░░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌░░░░░░░░░░░░░░░░░░░░░░░▓▓▓▓▓▓▓▓▓▓▓▀              "<<endl;         
        cout << "               ▒░░░░▌▓▐▓▓▓▓▓▓▓▓▓▓▓▓▓▓░░▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░▀                 "<<endl;         
        cout << "              ░░░░░░▒░░▓▓▓▓▓▓▓▓▓▀▌░░░░░░░░░░  ░▒░░░░░░░░░░░░░░░░▒░                    "<<endl;         
        cout << "            ▒▒░░░░░░░░░░▒▒▒▒▒░░░▐▒░░░░░░░░░░▌         ░░░░░░░                         "<<endl;         
        cout << "            ░░░░░░░░░░░░▓▓▓░░░░░░░░░░░░░░░░░░                                         "<<endl;         
        cout << "            ▓▓░░░░░░░░░░▓▓▒░░░░░░░░░░░░░░░░░░░                                        "<<endl;         
        cout << "              ▓░░░░░░░░░▒░░░░░░░░░░░░░░░░░░░░░                                        "<<endl;         
        cout << "               ▀░░░░░░░░░░░░░░░░░░░░░░░░░░░░░                                         "<<endl;         
        cout << "                 ▒░░░░░░░░░░░░░░░░░░░░░░░░░░                                          "<<endl;         
        cout << "                    ▒░░░░░░░░░░░░░░░░░░░░░░                                           "<<endl;         
        cout << "                    ░░░░░▒░░░░░░░░░░░░░▒░                                             "<<endl;         
        cout << "                  ░░░░░░░░     ░░░░░░                                                 "<<endl;         
        cout << "                 ░░░░░░░░░    ░░░░░░░░                                                "<<endl;         
        cout << "                ▐░░░░░░░░    ░░░░░░░░░                                                "<<endl;         
        cout << "                 ░░░░░░░     ░░░░░░░░░                                                "<<endl;         
        cout << "                  ▀▒▀░       ░░░░░░░░                                                 "<<endl;

    }else if(nome=="Venonat   "){

        cout << "                            ▀████▄                                                    "<<endl;
        cout << "                              ▀████▓                                                  "<<endl;
        cout << "       ▄▄███████▄▄▄▄▄▄              ▓▓▓▄                                              "<<endl;
        cout << "       ▀██████▀▀          ▀▀▀ ▄▄     ▓▓▓▓▄     ▄                                      "<<endl;
        cout << "                   ▄▄▄▄▄▄▄▄▄▄▄    ▀▐▄ ▀▓▓▓▓▄ ▐▄ ▄▒▌                                   "<<endl;
        cout << "                     ▀▀▀▀▓▓▓▓▓▓▓▓▓▓▓▓▌▓▀▄▌▓▓▓▓▓▌░░▌                                   "<<endl;
        cout << "                                ▒▒▓▓▓▓▓▓▓▌▀░▒▓▓▌▓░▄▒▀▒▒                               "<<endl;
        cout << "                         ▄▄▒▓▌▓▓▓▓▓▓▓▀▒▒▓▒▒▒▒░▓▓▓▌▓▌▀▓▓▓▓▓▄                           "<<endl;
        cout << "                        ░▓▓▓▓▓▓▓▓▓▒▄▓▓▓▓▓▓▓▓▓▒▓▓▓▓▓▓▄▀▓▓▓▓▓▓▓                         "<<endl;
        cout << "                        ▒▀▓▓▓▓▓▓▌▄▓▓▓▓▓▓▓▓▓▓▓▓░▓▓▓▓▓▓▌▒▓▓▓▓▓▓▓▄                       "<<endl;
        cout << "                        ▄▓▓▓▓▓▓▓░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▐░▓░▓▓▓░▄▀▓▓▓▓▓▓                       "<<endl;
        cout << "                     ▄▒░▓▓▓░░▓▓▓▐▓▓▓▓▓▓▓▓▓▓▓▓▓▓▐▓▓▓▓▀▄▓▓▓▓▓░▒▓▓▌                      "<<endl;
        cout << "                     ▄▓▓▓▓▓▓▓░▓▓░▓▓▓▓▓▓▓▓▓▓▓▓▓░▓▓▓▓░▄▄▓▓▓░▀░█▓░░                      "<<endl;
        cout << "                    ▓▓▓▓▓▓▓▓▓▓▓▓▓▒▓▓▓▓▓▓▓▓▓▓▌░▒▓▓▓▓▐██░░░░░░░▀░░░                     "<<endl;
        cout << "                   ▓▀▀▓░▓▓▓▓▓▓▓▓▓▓▌▒▀▓▓▓▓▀▀▄▒▓▓▓▓▓▓░▀█▐░░░░░░░░░░                     "<<endl;
        cout << "                     ░░░▒▓▓▓░▓▓▓░▓▓▓▓▓▒▒▓▓▓░░░░░░░░░░▒▒░░░░░░░░░░░                    "<<endl;
        cout << "                       ░░░░░░░▓░░░░▓▓▓▓░░░░░░▄▄▄░░░░░░░░░░░░░░░░▓                     "<<endl;
        cout << "                      ░░░░░░░░░░░░░░░▓▓░░░░░▓▓▓▄░░░░░░░░░░░░░░▓▓▓▓                    "<<endl;
        cout << "                      ▐░░░░░░░░░░░░░░░░░░░░▐▓▓▀▒░▒░░░░░░░░░░░░▐▓▓▌                    "<<endl;
        cout << "                      ░░░░░░░░░░░░░░░░░░░░░░░▒▀░░░░░░░░░░░░░░░░░░                     "<<endl;
        cout << "                        ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░                      "<<endl;
        cout << "                          ▐░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░                        "<<endl;
        cout << "                           ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░ ░░                          "<<endl;
        cout << "                               ░░░▄░░░░░░░░░░░░░░░░░░░░░░                             "<<endl;
        cout << "                              ▓▓▓▓▓▄░░░░░░░░░░░ ▐░▄░▄░░▓▓▓▓▒▄▄▄                       "<<endl;
        cout << "                          ▄▄▓▓▓▓▓▓▓▓▓             ▀▓▓▌▄▓▓▓▓▓▓▓▀▓                      "<<endl;
        cout << "                        ▓▓▓▀▓▓▓▓▓▓▓▌                  ▀▀▓▓▓▓▓▓▀░                      "<<endl;
        cout << "                        ▓▓▒▓▓▓▓▓▓▀                                                    "<<endl;

    }else if(nome=="Diglett   "){

        cout << "                                    ▄▄▄▄▄▄▓▓▒▄▄▄▄                                     "<<endl;
        cout << "                               ▄▄▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▄                               "<<endl;
        cout << "                            ▄▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▄                           "<<endl;
        cout << "                          ▄▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▄                         "<<endl;
        cout << "                         ▓▓▓▓▓▓▌▀▓▓▓▓▓▓▓▓▓▓▓▓▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌                        "<<endl;
        cout << "                       ▄▓▓▓▓▓▓▌▐▀▓▓▓▓▓▓▓▓▓▓▌▐▌▐▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▄                      "<<endl;
        cout << "                      ▐▓▓▓▓▓▓▓   ▓▓▓▓▓▓▓▓▓▓   ▐▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░                     "<<endl;
        cout << "                      ▓▓▓▓▓▓▓▓ ░░▓▓▓▓▓▓▓▓▓▓  ░▐▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                     "<<endl;
        cout << "                     ▐▓▓▓▓▓▓▓▓▓▒▓▓▓▓▓▓▓▓▓▓▓▓▄▄▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌                    "<<endl;
        cout << "                     ▓▓▓▓▓▓▓▓▀▒▄▄▄▓▓▓▓▓▄▄▄▒▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌                    "<<endl;
        cout << "                     ▓▓▓▓▓▓▌▐▓███████████▓▓▌▄▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                    "<<endl;
        cout << "                     ▓▓▓▓▓▓▌▓▓▓▓▓█████▓▓▓▓▓▓▓ ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                    "<<endl;
        cout << "                     ▓▓▓▓▓▓▌▄▀▓▓▓▓▓▓▓▓▓▓▓▓▓▌ ▒░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                    "<<endl;
        cout << "                     ▓▓▓▓▓▓▓▓▓▒▄▒░▒▀▀▀▀▒░░░▒░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                    "<<endl;
        cout << "                     ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░░░░░░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                    "<<endl;
        cout << "                     ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                    "<<endl;
        cout << "                     ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                    "<<endl;
        cout << "                    ▐▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                    "<<endl;
        cout << "                    ▐▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░                   "<<endl;
        cout << "                    ▐▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░                   "<<endl;
        cout << "              ▄▄▄    ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░                   "<<endl;
        cout << "            ▄▓▓▌▒▒▒▒░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░▓▓▄                "<<endl;
        cout << "          ▐▓▓▀▒░░░░░░▓▀▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░░░░░▄░▒▄           "<<endl;
        cout << "          ▐▒▒▓░░░░░░▄▓▓▓▓ ▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▀ ▄▄░░▒░░░░░▒          "<<endl;
        cout << "         ▄▓▓▓░░░░░▄▓▓▓▓▓▌▒ ▒▀▀▀▒▓▌▒▄▄▄▄▄▒▒▓▓▓▓▓▀▀▒▄▄▄▄▄▄▄▄▒▀░▌▐░▒░▒▀▀▓▒▒░░░░▒         "<<endl;
        cout << "       ▓▓░░░░░░░░▓▓▓▓▓▓▒▒░░ ▓▀▓▓ ░▓▓▓▓▓▓▓▓ ▄▀▀░▒▀▓▓▓▓▓▓▓▓▓▓▓▄░░░░▌░▄▄▒▒░░░░▓▓▒        "<<endl;
        cout << "       ░░░▌▄▓░░░▄▀▀▀▒░░░░░░▄▒▀▀▒▒▌▀▓▓▓▒▓▄▓▓▒▓▓░░▓░░▀▀▓▓▓▀▒▒▀▀▀▒░░░░▒ ▄▄▒░▒░▓▓▓▀       "<<endl;
        cout << "               ▓░░▒░░░░▓░░░░░░░░░░▌░▓▓▒▓▓▄░░░░░░░░░░░▓▒▄░▒▒▒░░░░░░░░░▀▀▓▓▓▄           "<<endl;
        cout << "                ▀▒░░░▓▌      ▀▓▓▓▓░░▒░▒░▒▒▒░░░▒▀▒▒░░░░░░░░░░░░░░░░░▒░░░░              "<<endl;

    }else if(nome=="Meowth    "){

        cout << "                  ░░░░░░░░░░░░░    ▐▄            ▄      ░░░░░░░                       "<<endl;      
        cout << "                  ░░░▐▓▓▓▓▄░░░░░░░  ▐▄   ▓▓▓▓▓▄  ▌  ░░░░░░░░░░░░                      "<<endl;      
        cout << "                 ░░░░██▓▓▓▓▓▓▄▄░░░░░░█ ▐▀████▓▓▄▐▌░░░░░░▄▓▓▄░░░░░                     "<<endl;      
        cout << "                ░░░░░██████▓▓▓▓▓▒▄▄▄▄▄█▐▐▄▄░▀███▌▌░░░▄▓▓▓▓██▌░░░░                     "<<endl;      
        cout << "                ░░░░░██████████████████▌▐██▓▓▓░▀▀████▄▌▓█████░░░░░                    "<<endl;      
        cout << "                ░░░░░███████████████████▌▓█████▓▓████████████░░░░░                    "<<endl;      
        cout << "                ░░░░░███████████████████▌░▓▓▓▓▓▓█████████████▌░░░░                    "<<endl;      
        cout << "                ░░░▄█████████████████████▄░▀▀▓▓▓▓█████████████░░░░                    "<<endl;      
        cout << "                ░░███████████████▌█▌████████████████▌██████████▄░░                    "<<endl;      
        cout << "              ▀▀▄████████████████▌  ████████████████ █▐██████████░                    "<<endl;      
        cout << "                ██████████████████░░████████████████ ░▐██████████▄▄▄▀▀▀               "<<endl;      
        cout << "                ██████████████████░░██████████████▌█▌░▐███████████                    "<<endl;      
        cout << "               ▐█████████████████████████████████████▄████████████▌                   "<<endl;      
        cout << "                ██████████████████████████████████████████████████▌                   "<<endl;      
        cout << "            ▄▄▄▀▀██████████████████████████████████████████████████▄                  "<<endl;      
        cout << "                █████████████████████████████████████████████████   ▀▀▄               "<<endl;     
        cout << "                  ▀██████████████████████████████████████████████                     "<<endl;      
        cout << "                   ▀▓▓█████████████████████████████████████████▀                      "<<endl;      
        cout << "                     ▀▓▓▓▓███████████████████████████████████▀                        "<<endl;      
        cout << "                        ▀▓▓▓▓▓█████████████████████████████▀                          "<<endl;      
        cout << "                           ▀▀▓▓▓▓▓▓▓▓██████████████▓▓▀▀                               "<<endl;         
        cout << "                                ▄▄█▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓█▄▄                                "<<endl;      
        cout << "            ▄▄▄             ▄▄██████████████████████████▄                             "<<endl;      
        cout << "         ▄▌▓▓▓▓▓▓▒        ▄█████▀▀▐███████████████▄ ▀▀█████                           "<<endl;      
        cout << "         ▓▓▓▒▒▓▓▓▓▓▄    ▄█████▀   █████████████████    ▀████                          "<<endl;      
        cout << "         ▓▓▓▒▓▓▓▓▓▓▌   ▐█████▌    ██████████████████    ████▌                         "<<endl;      
        cout << "          ▓▓▓▒▒▀▀▀      ██████▄  ▐██████████████████   ▄████                          "<<endl;      
        cout << "           ▀▓▓▓▓▓▄       ▀██████▄▀██████████████████▌▄█████                           "<<endl;      
        cout << "             ▀▌▓▓▓▓▒       ▀████████████████████████▌████▀                            "<<endl;      
        cout << "                ▀▓▓▓▓▄█▄▄    ▄██████▌▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌███                              "<<endl;     
        cout << "                    ▀▀█████▓▒████████▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌████▌                            "<<endl;  

    }else if(nome=="Psyduck   "){   

        cout << "                                        ░░    ░                                       "<<endl;            
        cout << "                                         ░   ░                                        "<<endl;            
        cout << "                                         ░  ░                                         "<<endl;
        cout << "                                   ▄▄▄▄▄▓▓▓▄▄▄▄▄                                      "<<endl;            
        cout << "                          ▄▀▄▀▓▄███████████████▓▓█▓▄                                  "<<endl;            
        cout << "                        ▄▓▓▓██████████████████▓▓▓▓██▓▓▄                               "<<endl;            
        cout << "                      ▄▓▓▓▓█████████████████▓▓▓▓▓▓███▓▓▓▄▄▓                           "<<endl;            
        cout << "                    ▄▓▓▓▒▐█████████████▓▓▀███████▓▓▌▓▓█▓▓▓▓▌                          "<<endl;            
        cout << "                   ▄▓▓▓▌▓▓███████▓▓▓▓▓▓▓▌█████████▐▓▓▀▓▓▓▓▓▓▓                         "<<endl;            
        cout << "                   ▓▓▓▓▌▓▓▓▓▓▓▓▒▄██▓▓▓▓▓▓▓███████▌▓▓▓▌▓▓▓▓▓▓▓▓▄                       "<<endl;            
        cout << "                  ▓▓▓▓▓▓▒▓▓███████████▓▓▄▄▄▓▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                      "<<endl;            
        cout << "                  ▒▓▓▓▓▓▄▄████████▓██████████▐▓▓▓▓▓▓▓▓▐▓▓▓▓▓▓▓▓▓▓▄                    "<<endl;            
        cout << "                   ▀▄███████████████████████▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌                   "<<endl;            
        cout << "                  ▄████████████████████████▐▓▓▓▓▓▓▀▀▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓                   "<<endl;            
        cout << "                ▐██████████████████████████▐▓▓▓▓▓▓▓▓▓▌▓▓▓▓▓▓▓▓▓▓▓▓▓                   "<<endl;            
        cout << "                ▐██████████████████████████▓▓▓▓▓▓▓▓▓▓▐▓▓▓▓▓▓▓▓▓▓▓▓▓                   "<<endl;            
        cout << "                 ▐████████████████████████▒▓▓▓▓▓▓▓▓▓▓▌▓▓▓▓▓▓▓▓▓▓▓▓▌                   "<<endl;            
        cout << "                    ▀▀▓██████████████▓█▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▓▓▓▓▓▓▓▓▓▓▀                    "<<endl;            
        cout << "                        ▄█▓▓██▀█▓▓▓█▓█████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▄▄                     "<<endl;            
        cout << "                       ▐████████████████████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                     "<<endl;            
        cout << "                       ███████████████████████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌                    "<<endl;            
        cout << "                      ▐██████████████████████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌                    "<<endl;            
        cout << "              ▓▓▄▄▄▄▄▄▐▓████████████████████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                    "<<endl;            
        cout << "               ▀▓▓▓▓▓▓░▓▓▓▓██████████████████▓▓▓▓▓▓▓▓▓▓▓▓▌▓▓▓▓▓█░▌                    "<<endl;            
        cout << "                 ▀▓▓▓▓▌▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▄█▓▓▄██▓▓▌                     "<<endl;            
        cout << "                   ▀▓▓▓▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▄█▓▓▓▓▓▓▓▓▓▓▓▀                  "<<endl;            
        cout << "                      ▀▓▒▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▐█▓▓▓▓▓▓▓▓▓▓▓                    "<<endl;            
        cout << "                          ░▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌██▓▓▓▓▓▓▓▓▓▀                     "<<endl;            
        cout << "                               ▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▀▀▀▀▀  ██▓▓▓▓▓▓▀                        "<<endl;            
        cout << "                             ▄▓▓▓▓▓▓▓▓▓▒▓▒             ▀▀▀▀                           "<<endl;            
        cout << "                           ▀▀▀▀▀███████▓▓▓▄                                           "<<endl;

    }else if(nome=="Growlithe "){ 

        cout << "                                             ▄█▀▄▄▄                                   "<<endl; 
        cout << "                                           ▄██████▀                                   "<<endl;  
        cout << "                                        ▄██████████▓▓▓▓▓▀▀                            "<<endl;  
        cout << "                                      ▄█████████▓▓▓▓▓▓▓▌                              "<<endl;  
        cout << "                                     ▄██████▓▓▓▓▓▓▓▓▓▓▓▓▓▄                            "<<endl;  
        cout << "                                     ▐▓▓▀▀▓▓▀▀▀▓▓▓▓▓▓▓▀▀ ▀▀▀                          "<<endl;  
        cout << "                                 ▄░░▄▓▓▓▓▓▓▓▓▓▓▓▓▌▀▓▀▒▒▀▒                             "<<endl;  
        cout << "                                ▒▒▄▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▀░░░░░▓░▀                           "<<endl;  
        cout << "                               ▒▌▓▓▓▓▓▓▓▓▀ ▓▓█▌▓▓▓▌▄▓░░░░░▒░▄                         "<<endl;  
        cout << "                               ░░▒░░▓▓▓▌░  ▐██▌▓▓▓▓▓░░░▓▓▓▓▓▐▌                        "<<endl;  
        cout << "                              ▐█▄▄▄▄█████████▓▓▓▓▓▒▓▌▓▓▌▒▓▒░                          "<<endl;  
        cout << "                              ▐███████████████▓▓▓▓▓▒▓▓▓▌▒                             "<<endl;  
        cout << "                               ▀▓█▓▓▓▓▓██████▓▓▓▓▓▓▓▓▓▓▓▓                             "<<endl;  
        cout << "                                 ▀██████▓▓▓▓▓▓▓▓▓▓▓▀▒▓▓▄▌░                            "<<endl;  
        cout << "                                   ▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒░                            "<<endl;  
        cout << "                      ▄▄▄▄▄▄▄      ▐▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▀                        "<<endl;  
        cout << "                  ▓▓▓█████████▓▓▄  ▄█████████▓▓▓▓▓▓▓▓▓▓▓▓▀▒░                          "<<endl;  
        cout << "               ▄▄▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▄█████████▓▓▓▓▓▓▓▓▓▓▓▓▓▀▒                          "<<endl;  
        cout << "               ▄▓▓█▓▓▓▓▓▓▓▓████▓▓▀▀▀▀▀█████████▓▓▓▓▓▓▓▓▓▓▓▓▒                          "<<endl;  
        cout << "              ▓▓▀▓▓▒▓▓▓▓▓▓▓▓▓▓▓▀▌░░░▌██████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▄                        "<<endl;  
        cout << "                 ▐▓▓▓▓▓▓▓▓▓▓▓▀░░▌░░░▀▌▓▓▀███████▓▓▓▓▓▓▓▓▓▓▓▓▒                         "<<endl;  
        cout << "                ▄▓▓▓▓▓▓▓▓▓▓▓▓▓░░▌░░▓▓▓▓▒▓▓█▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░                         "<<endl;  
        cout << "               ▓▀▓▓▐▓▓▓▓▓▒▓▓▓▓▓▓▓▓▄▒▓▓▓▓▓▌▌▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▀▓▓                         "<<endl;  
        cout << "                    ▀▓▓▀░░░░▓▓▓▓▓▌▓▓▐▓▓▓▓▓▓▓▓▓▒▓▓▓▓▓▓▓▓▓▓░▌▓░                         "<<endl;  
        cout << "                     ▀▌░▄▄▓▓▓▓▓▓▓▓▒▓▐▓▓▓▓▓▓▓▓▓▓▒▓▓▓▓▓▓▓▓▌▓▓▓░                         "<<endl;  
        cout << "                      ▐▓▀░░░▀▓▓▓▓▓▌▒░▀░▀▀▓▓▓▓▓▓▒▓▓▓▓▓▓▌▓▒▓▓▌                          "<<endl;  
        cout << "                       ░░░▄▓▓▓▓▓▓▓▓▐▒▄░░░░░▀▀▀░░▓▓▓▒▐▌░░░▀░░                          "<<endl;  
        cout << "                       ░░▓▓▓▓▓▓▓▓▓▌▓▓▓▓▓▄░░░░░░░▐▒▒▓▌▒▄░░░░                           "<<endl;  
        cout << "                       ▐▓▓▓▓▓▓▓▓▓▌▓▓▓▐▓▓▓▓▓▄░░░▄▌░▓▓▓▓▓▓▄░▓▌                          "<<endl;  
        cout << "                        ▓▓▓▓▓▓▓▓▓▓▓▓▓▌▓▓▓▓▓▓▓▓▓▓▓░▓▓▓▓▓▓▓▓▓▌                          "<<endl;  
        cout << "                         ▄▒▒▓▌▓▒▓▓▓▓▓▀▐▓▓▓▓▓▓▓▓▓▓▌▌▓▌▌▌▓▓▓▓▒                          "<<endl;

    }else if(nome=="Poliwag   "){

        cout << "                      ▄▄▄▄▄▄▄                                                         "<<endl;   
        cout << "                 ▄▄▓▓▓▓▓▓▓▓▓▀   ▀▀▄                                                   "<<endl;   
        cout << "               ▒░ ▄▀▓▓▓▓▓▓▓▓▌▀▀    ██▄▄                                               "<<endl;   
        cout << "            ▄▄▀  ▐██ ▓▓▓▓▓▓▓▓▓▄░░░ ▄██▐▓▄                                             "<<endl;   
        cout << "           ▓▐█       ▓▓▓▓▓▓▓▓▓▌▀▒▒▀▀▀▌▓▓▓░▒                                           "<<endl;   
        cout << "          ▓▌██▄ ░░░░░▓▓▒▓██▓▓▓▓▌▒▒▓▓▓▓▓▓▓▓▓▓▄                                         "<<endl;   
        cout << "         ▓▓▓▀███▄▄▀▌▓▓▓░▓▓▓▓▓▓▓█████▄▄▒▌▓▓▓▓▓▄                                        "<<endl;   
        cout << "        ▒▓▓▓▓▓▓▓▓▓▓▓▀▄█████▌▀▀▀▀▀▀▀█████▄▀▓▓▓▓▒                                       "<<endl;   
        cout << "        ▓▓▓▓▓▓▓▓▓▓▌▄████▀░▄██████▄▄▄ ▀████▄▓▓▓░                                       "<<endl;   
        cout << "       ▐▓▓▓▓▓▓▓▓▓▒████░▄███▀▀▀  ▀▀▀███▄▐███░▓▓▓▌                                      "<<endl;   
        cout << "       ▒▓▓▓▓▓▓▓▓░████ ▓██▀ ▄█▀▀▀▀█▄ ▐██▄ ███▒▓░░                                      "<<endl;   
        cout << "       ▒░▓▓▓▓░░░▐███ ▐██  █▀ ▄██▄ ▀█ ▐██ ███▐░░░                                      "<<endl;   
        cout << "       ▐▓▓▓▓▓▓▓░▐███ ▐██ ▐█ ▐███▀ ▐█ ▐██ ███▐░░░                                      "<<endl;   
        cout << "        ▓▓▓▓▓▓▓▓░███  ██▄▐█▄ ▀█▄▄▓▀ ▄██ ▐▓▓░░░░                                       "<<endl;   
        cout << "         ▓▓▓▓▓▓▓▓▐███ ▐██▄ ▀█▄▄▄▄▄▄██▀ ▄▓▓░░░                                         "<<endl;   
        cout << "          ▌░░▓▓▓▓░░▓██▄ ▀▀█▄   ▀▀   ▄▓▓▓▀▒░░▄░▒▄                                      "<<endl;   
        cout << "           ░░░░░░░░▒░▀█▓▄▄  ▓▓▓▓▓▓▓▓▓▀░▓▌░▐░░░░░░░▒                                   "<<endl;   
        cout << "              ▒░░░░░░░▒░░▀▀▀▀▀▀▀▀▒░▒░▒░    ▐░░░░░░▓▓▄         ▄▄                      "<<endl;   
        cout << "                 ▀▒▓░░░░░░░░░░░▒▒▒▒▒▒▒       ░▓▓▓▓▓▓▌▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▄▄             "<<endl;   
        cout << "                     ░▄▄▄▄░         ▀▀▓▒░▒▀▓▓▓▓▄▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▄          "<<endl;   
        cout << "                     ▐░░░░░▒           ▀▄▄▒░░░▒▀▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓████▌        "<<endl;   
        cout << "                      ▒░░░░░░▒           ▀▓▓▓▓▄▄▄▒░░▒▀▀▀▓▓▓▓▓▓▓▓▓▓▓▓▓██████████       "<<endl;   
        cout << "                       ░▓▓▓▓▓▓▓▄            ▀▓▓▓▓▓▓▓▓▓▄▄▄▒░░░░░▀▀▀▀▀▀▀▌▄███████       "<<endl;   
        cout << "                        ▓▓▓▓▓▓▓▓               ▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓███████████████▀        "<<endl;   
        cout << "                         ▀▓▓▓▓▌                    ▀▀▓▓████████████████████▀          "<<endl;   
        cout << "                                                         ▀▀▀▀▀███████▀▀▀              "<<endl;  

    }else if(nome=="Weepinbell"){

        cout << "                                                       ▄▒▓▓▓▓▌░░░░                    "<<endl;    
        cout << "                                                ▄▄▓▓▄▄▀▀▀░▒░     ░░                   "<<endl;    
        cout << "       ▄▄▓▓▓▓▓▓▓▓▓▄▄▄                    ▄▄███████▓▓▓██▓░          ░                  "<<endl;    
        cout << "        ▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▄             ▄█▀▓███████████▓▓▓▓                             "<<endl;    
        cout << "          ▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒        ████████████████▓▓▓▌▓        ▄▄▄▄▒▓▓▓▄▄▄▄         "<<endl;    
        cout << "           ▐▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒    ▄████████▀░░▓███▓▓▓▓▓▓▌    ▄▄▓▓▓▓▓▓▓▓▓▓▓▓▓▓▀        "<<endl;    
        cout << "            ▐▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓  ▓▄▓████████▓███▓▓▓▓▓▓▓▓▓ ▄▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▀           "<<endl;    
        cout << "             ▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▄█▌█████████▀█▀█▓▓▓▓▓▓▓▓▓▀▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▀             "<<endl;    
        cout << "              ▓▓▓▓▓▓▓▓▓▓▓▓▓░█▀▀█▌█████████████▄▀▓▓▓▓▓▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▀              "<<endl;    
        cout << "              ▐▓▓▓▓▓▓▓▓▓▓▓▌█   ▀▓▓█▓▓▓▐█▀ ░ ▀███▓▓▓▀▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌               "<<endl;    
        cout << "               ▓▓▓▓▓▓▓▓▓▓▓▒█▄▄▓▓▓▓▓▓▓▓▐▌ ░  ▐██▌▓▓▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                "<<endl;    
        cout << "                ▀▓▓▓▓▓▓▓▌░▄▓▓▓▓▓▓▓▓▓▓▓▓▄▀▄▄▓██▓▓▓▌▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌                "<<endl;    
        cout << "                    ▀▄▓████▓▓▓▄▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌                 "<<endl;    
        cout << "                   ▄████████████▓▓▓▀▓▓▓▓▓▓▓▓▓▓▓▓▓▌▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▀                  "<<endl;    
        cout << "                  ▐███▓▓▓▀▓▓▓██████▓▓▀▓▓▓▓▓▓▓▓▓▓▓▓▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▀                    "<<endl;    
        cout << "                  ▐███▌▄      ▀▓█████▓▄▓▓▓▓▓▓▓▓▓▓▓▓▄▀▓▓▓▓▓▓▓▓▓▓▀                      "<<endl;    
        cout << "                   ▓▓▓▓▓▄     ░░░▀▓▓▓▓▓▌▓▓▓▓▓▓▓▓▓▓▓▓▓▒  ▀▀▀                           "<<endl;    
        cout << "                    ▀▓▓▓▓▄    ░░░░░▀▓▓▓▓▒▓▓▓▓▓▓▓▓▓▓▓▀                                 "<<endl;    
        cout << "                     ▐▓▓▓▓     ░░░░░▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓                                   "<<endl;    
        cout << "                      ▐▓▓▓▌     ░░░░▒▓▓▓▓▐▓▓▓▓▓▓▓▀                                    "<<endl;    
        cout << "                       ▓▓▓▓      ░░░░▓▓▓▓▐▓▓▓▓▓                                       "<<endl;    
        cout << "                       ▐▓▓▓▌  ░      ▓▓▓▒▓▓▓▀                                         "<<endl;    
        cout << "                        ▓▓▓▓▄░░░░░▄▄▓▓▓▀▀▀                                            "<<endl;    
        cout << "                         ▓▓██▓▓████▓▓▀                                                "<<endl;    
        cout << "                            ▀▀▀▀▀▀▀                                                   "<<endl;  

    }else if(nome=="Geodude   "){

        cout << "                                                                     ▄▓▓▄             "<<endl;    
        cout << "           ▄ ▓▓▓▒▓▒                                               ▄▓▓▓▓▀▓▓▄▄          "<<endl;    
        cout << "        ▄▄▓▓▓▓▀░░░░              ▄▄▄▄▄▄▓▓▓▓▓▓▌░                  ▒░▓▓▌▓▓▓▓▓▓▌         "<<endl;    
        cout << "       ▒▀▓▌░░░░░░░▓▄▄         ▄▄▀░░▓▓▓▓▓▓▓▀▓▓▌░░                ▄░░░░▓▓▓▓▓▒▓▓▒        "<<endl;    
        cout << "       ▀▓▒░░▄▒░░░░▒▀▀        ▓▓▓▓▓▓▓▓▓▒▓▓▓▓░▒░░░░░              ░▒░░▒░▓▓▓▓▓▓▓▓▌       "<<endl;    
        cout << "        ▀▓▓▓▓▓▒░░▀         ▄▓▓▓▓▓▓▓▓▓▓▓▓▓▐▓░░░░░░░░▒  ▄     ▄▄▓▓▓▄▄▒░▒░▓▓▓▓▒▓▓▀       "<<endl;    
        cout << "         ▐▓▓▓▌▓░▓         ▐▓░▐▌▌▓▓▓▓▀▀▐██▄▐▌░░░░░░▓▓▓▓▓▓▓▄▒▓▓▓▓▓▓▓▓▓▌░░░ ░▀▀          "<<endl;    
        cout << "           ▀▓▓▓░░▓▄         ▓▐██▌▐▓▓▓▓▓▓▓▓▓░░░░░░░▀▀▀▀▀▀▀▓▓▓▓▓▓▓▓▓▓▓▀                 "<<endl;    
        cout << "            ▓▓▓▓▓▓▌▌        ▓▓▓▌▓▓▓▓▓▓▀▒▒▒▒▒░░░▒░░░░                                  "<<endl;    
        cout << "             ▓▓▓▓▓▓▌   ▄▓▓░▌▓▓▓▒▒▒▒▄▓▓▓▓▓▓░░░░░░░░░                                   "<<endl;    
        cout << "              ▀▓▌▓▓▓▓▄▄▓▓▒░   ░▓▓▓▓▓▓▓▓▓▌░░░░░░▒                                      "<<endl;    
        cout << "                 ░▀▓▓▓▓▀         ▀▓▀▀░░░░░░░░                                         "<<endl;

    }else if(nome=="Magnemite "){

        cout << "                                                                         ▄░           "<<endl;    
        cout << "                                    ░░░░░░░░▒░                     ▄▒▓▓▓▓▓░▓          "<<endl;    
        cout << "                                 ░░░░░░░░░▒░▒░               ▄▄▓▓▓▓▓▓▓▓▓▓▓▌▒          "<<endl;    
        cout << "                                 ░░░░░░░░░░               ▄▓▓▓▓▓▓▓▓▓▓▀▀▀░░░░░         "<<endl;    
        cout << "                                      ░▓▀▀░             ▄▓▓▓▓▓▓▀▀░░░░░                "<<endl;    
        cout << "                                      ▄▓███████▓▄▄     ▄▓▓▓▓▓░░░░                     "<<endl;    
        cout << "                                  ▄██████▀███████▓▓▓▄  ▓▓▓▓▓▌░░            ▄▄         "<<endl;    
        cout << "                                ▄████████████▀██▓▓▓▓▓▓▌▓▓▓▓▓▓▄░    ▄▄▄▒▓▓▓▓▓▓░░       "<<endl;    
        cout << "                               ▄██████████████▄▓▓▓▓▓▓▓▓▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌░▒       "<<endl;    
        cout << "        ▄░▄▄▄▄▄               ▐██▌█████████████▒▓▓▓▓▓▓▓▓▓▀▓▓▓▓▓▓▓▓▓▓▓▀▀▀░░░░          "<<endl;    
        cout << "       ▐░░░▓▓▓▓▓▓▓▓▓▓▓▒▄▄     ▓██▌█████████████▐▓▓▓▓▓▓▓▓▓▓  ░▀▀▀░░░░░                 "<<endl;    
        cout << "         ░░▒▒▀▀▀▓▓▓▓▓▓▓▓▓▓▓▒  ▓▓▓▓▀███████████▌▓▓▓▀▓▓▀▓▓▓▓                            "<<endl;    
        cout << "           ░░░░░░░░░░░░░▀▓▓▓▓▄▓▓▓▓▓▓████████▀▓▓▓▌▓█░░▀▒▒▓▓                            "<<endl;    
        cout << "                       ░░░▓▓▓▓▐▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌▓▄▄▒▐▓▒▓                             "<<endl;    
        cout << "                ░▄▄▄▄▄▄ ░▄▓▓░░░▒▀▓▓▒▀▓▓▓▓▓▓▓▓▓▓▓▓▄▓▌▀▒▄▓▀                             "<<endl;    
        cout << "              ▒░░░▓▓▓▓▓▓▓░░░░░▀░░░▄▌░▓▓▓▓▓▓▓▓▓▓▓██████▀                               "<<endl;    
        cout << "               ▀░░▌▀▓▓▓░░░░░░░░▀▒▄▌▀▓▓▓▓▓████▓██████▀                                 "<<endl;    
        cout << "                ▐▓▒░░░░░░░░░░          ▀▀▀██▓▓▓▀▀                                     "<<endl;

    }else if(nome=="Grimer    "){

        cout << "                                   ▄▄▓▓▓▓▓▓▓▒▄                                        "<<endl;    
        cout << "                               ▄▓█▓▓▓▓▓▓▓▓▄▄▄░░▓░                                     "<<endl;    
        cout << "                             ██▓▓▓▓▓▓▓▓▌█████▌░░░░▒                                   "<<endl;    
        cout << "                           ▐██▌▓▓▓▓▓▀▀▀▐████▀░░▒▓░░░░                                 "<<endl;    
        cout << "                           ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░░░░░░░░▄                                "<<endl;    
        cout << "                           ▀▓▓▓▓▓▓▓▀▀▀▀▀▀▀░░░░░░░▒▓░░░▒                               "<<endl;    
        cout << "                                 ░         ▐░░░░░░░░░░░▌                              "<<endl;    
        cout << "                                       ░░░░▐░░░░░░░░░░░▓▓▌                            "<<endl;    
        cout << "                              ▄▒░    ░░░▄▄░▓░░░░░░░░░░▓░▀░░▓▄                         "<<endl;    
        cout << "                         ▄▄▓▄▓▓▀  ▒▓▓▓▓▓▓▓▓▌░░░░░░░░▒░░░▒░░▓▓▓                        "<<endl;    
        cout << "                       ▄▓▀▀▓▌▓▌ ▐▓▓▓▓▓▓▓▌▄▓░░░░░░░░░░░▓░▒▓░░░▌                        "<<endl;    
        cout << "           ▄▄▒▓▓▓▒▒▄▄▒░▀▓▓▓░▐▓▄ ▓▓▓▓▓▓▓▓▓▓▌░▓░░▓▓▓▓▓░░▓░░▒▒░░▌                        "<<endl;    
        cout << "         ▓▓▓▓▌▐▓▓▓▓░▓▓▓▓░░▓▓▒▀▓▓▓▄▄▓▓▓▓▓▀▒░░░░░░░░▄▓▓▄░░░░▌▒░░▓░░▄▄                   "<<endl;    
        cout << "          ▀▀▒▒░░▓▀▓▓▓▓▒▓▓▌░▓▓▓▒▒▒▀▓▓▓▓▓░▓░▄▄▄▄▒▀░▀▓▄▄░▀▀▓▓░░░░░░▓░░▓▓░                "<<endl;    
        cout << "        ▄▓▓▌▓▓░░▓▓▓▓▓▓▓░▓▀  ▀▀▌░░▓▄░░░▄░▐▓▓▓▓▓▓▓░▀▓▓▓▓▓▓░▓▄░▒▓░░░▓░░░░                "<<endl;    
        cout << "       ▓▓▓▌░░░░░▀▓▓▀▒░░░   ▓▓▓░░░░░░░░░░░▒▀▀▓▓▓▓▓▓▓░░▓▓▓▓░▓▌▓░░░░░░▄░░                "<<endl;    
        cout << "        ▀▀          ░░░   ▓▓▓▓▓▓▓▓▓▒░▒▒░▄▓▓▒▒░▄▓▓▓▓▓▌░▓▓▓░▓░▒▄░░░▒▓░░░▓▓▒▄▄           "<<endl;    
        cout << "                          ▐▓▓▓▓▓▓▓▓▓▓▓▌▓▓▓▓▓▌▓▓▓▓▓▓▓▓░▓▓▓░░▓░▓▒▒▄▓░░░░░▓▓▓▌░░         "<<endl;    
        cout << "                          ░▓▒░░░░▀▀▀▒░░░▒▒▒▒▒░▀▀▒▒▒░░▓▓▀░░░░░░░▒▓░░░░░░░▒░░░▒▌▄       "<<endl;    
        cout << "                        ▓▓▓▓▄░░░░░▒░░░░░░░░░░░░░░░░░░░░░░░▒▒▓▓▒░░░░░░░░░░░░░░░▀       "<<endl;    
        cout << "                       ▐▓▓▓▓▓▓▓▓▓▒░░░░░░░▒▓▓░▓▓▒▒░░░░▒▓░░░░░░░░░▓▓▓▓▓░░▒              "<<endl;    
        cout << "                               ▀▓░░░░░░░▌▒▀▀   ▀▀▒▓░░░░░░░▌▀     ▀▀▀▀                 "<<endl; 

    }else if(nome=="Voltorb   "){

        cout << "                                    ▄▄▄▄▄▄▄▄▄                                         "<<endl;   
        cout << "                             ▄▄▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌▒▄▄                                "<<endl;    
        cout << "                        ▄▄▓▓▓▓██▓▓████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▄▄                           "<<endl;    
        cout << "                     ▄▓▓▓▓██▓▓▓▓███▓████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▄                        "<<endl;    
        cout << "                   ▓▓▓███████████▓█▓█▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▄                     "<<endl;    
        cout << "                ▄▓▓▓▓█████████████▓▓███▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌▄                   "<<endl;    
        cout << "               ▓▓▓▓▓▓▓████▓▓████████████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▄                 "<<endl;    
        cout << "             ▄▓▓▓█▓▓▓▓▓█▓▓▓▓███████████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌                "<<endl;    
        cout << "            ▓▓▓▓▓▓▓▓███████████████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▄              "<<endl;    
        cout << "           ▓▓▓▓▓▓▓▓▓▓▓████████████████▓▓█▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒             "<<endl;    
        cout << "          ▓▓▓▓▓▓▓██▓█▓▓▓▓████████████▓▓█▓▓████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▄            "<<endl;    
        cout << "         ▓▓▓▓▓▓▓▓▓▓▓██▓▓▓█████████████▓▓▒▄▓███████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▄           "<<endl;    
        cout << "        ▐▓▓▓▓▓▓▓▓▓▓▓▓▓█████████████▓▓▓▓▓▓▌▀▓▓▓█████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌          "<<endl;    
        cout << "        ▐▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒ ▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓         "<<endl;    
        cout << "       ▐▌░▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌▐█▄░▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌▀▓▓▓▓▓▓▓▓▓▓▓▓        "<<endl;    
        cout << "       ▐▓▓▓▄▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░████▓▄▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌▐▓▓▓▓▓▓▓▓▓▓▓▌       "<<endl;    
        cout << "       ▐▓▓▓▓▓▄▌▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▐███████▄▀▓▓▓▓▓▓▓▓▓▓▓▓▓░▓▓▓▓▓▓▓▓▓▓▓▌       "<<endl;    
        cout << "       ▐▓▓▓▓▓▓██▄▌▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██████████▄░▓▓▓▓▓▓▓▓▓▓▓▐▓▓▓▓▓▓▓▓▓▓▀        "<<endl;    
        cout << "        ▓▓▓▓▓▓▓████▄▄▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌███████████▐▓░▓▓▓▓▓▓▓▌▌▓▓▓▓▓▓▓▓▓▀          "<<endl;    
        cout << "        ▀▓▓▓▓▓▓▓▓██████▄▄▀▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌▀█████████████▓░▓▓▓▓▌▐▓▓▌▐▓▓▓▀▐            "<<endl;    
        cout << "         ▓▓▓▓▓▓▓▓▓▓████████▄▄▌▀▓▓▓▓▓▓▓▓▓▓▓▓▓▒▄▄▄▀▀▀▀███████▄▐▓▀▄▓▓▌░▌▀▐▄██            "<<endl;    
        cout << "         ▐▓▓▓▓▓▓▓▓▓▓▓███████████▄▄▄▀▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▄▄▄▒▓▓▓▓▓▓░ ▄█▄██▀░            "<<endl;    
        cout << "          ▐▓▓▓▓▓▓▓▓▓▓▓▓███████████████▄▄▄▌▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░▀▀▀░▄▓             "<<endl;    
        cout << "           ▐▓▓▓▓▓▓▓▓▓▓▓▓▓███████████████████▓▓▄▄▒▀▀▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓              "<<endl;    
        cout << "             ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▄▄▄▄▄▒▒▒▀▀▀▀▀▀▀░               "<<endl;    
        cout << "              ▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▀                "<<endl;    
        cout << "                ▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▀                  "<<endl;    
        cout << "                  ▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▀                    "<<endl;    
        cout << "                     ▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▀                       "<<endl;    
        cout << "                        ▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▀                          "<<endl;    
        cout << "                            ▀▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▀▀                              "<<endl;    
        cout << "                                  ▀▀▀▀▀▓▓▓▓▓▓▀▀▀▀▀                                    "<<endl;

    }else if(nome=="Cubone    "){

        cout << "                      ▐███▄                              ▄▓█▓▄                        "<<endl;           
        cout << "                       ▀██████▄▄  ▄▄▄███████▓█▓▓▄▄   ▄▄████▓▓                         "<<endl;           
        cout << "                         ▓▓█████████████████████▌▄▓█████▓▓▓▀                          "<<endl;           
        cout << "                          ▀▓▓████████████████████▓██▓▓▓▓▓▓                            "<<endl;           
        cout << "                           ▄████████████▓███▓░░▒▀▀▀▓▓▓▓▓▓                             "<<endl;           
        cout << "                          ▐████████████████░░░░░▀▓▓▒▓▓▓▓▒                             "<<endl;           
        cout << "                          ▐███████████████▒░░░░▒▓▄▓▓▓▓▓▓▓▓▄                           "<<endl;           
        cout << "                          ▐██████████████░░░░▓▌▀▓▓░▓▓▓▓▓▓▓▓▓▓▄▄                       "<<endl;           
        cout << "                          ▒█████████████▌░░▓▌ ▓█▄▓▓▐▓▓▓▌▓▓▓▓▓▓▓▓▄                     "<<endl;           
        cout << "                          ██████████████░░▐▀▄ ▐██▓▓▌▐▓▌▓▓▓▓▓▓▓▓▓                      "<<endl;           
        cout << "                        ▄███████████████▌░░   ▐██▒▓▌▓▓▓▓▓▓▓▓▓▌                        "<<endl;           
        cout << "                      ▄█████████████████▓▄░ ░▄▄▒▓▓▀▓▌▓▓▓▓▓▓▓▌                         "<<endl;           
        cout << "                    ▄██████████████▓▓▓▓▓▓▓▓▓▄▄░░▒░▒▐▓▓▓▓▓▓▓▌                          "<<endl;           
        cout << "                    ▀███████████▀▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▓▀▓▓▓▓                           "<<endl;           
        cout << "                     ██▓▓██████   ▐▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░                                 "<<endl;           
        cout << "                     ▐███████▓     ▓▀▌▓▓▓██▓░░▒▒▒░░░▄                                 "<<endl;           
        cout << "                     ▀▓▓▓▓▓▓▓▓ ░▄▒▓▓▓▌▓▓▓█▓▓▐░░░░░░░░░▒                               "<<endl;           
        cout << "                       ▀▓▓▓▓▓▓▓▓▓▀▒░░▒▒▒▐▓▀░░░░▓▓▓░▄░▒░░▒▄                            "<<endl;           
        cout << "                           ▀▀▓▓▀▒▓▓▓▓░░░░▓▓▓▓▓▓▓▓▓▓▓▓▓▄░░░░▒▄                         "<<endl;           
        cout << "                         ▄▓▓▓▓▓▓▓▓▓▓▓▓████████▓▓▓▓██████░░▓▓▓▓▓▄                      "<<endl;           
        cout << "                       ▄▓▓▓▓▓▓▓▓▓▓▓▓▓████████████████████▒▓▓▓▓▓▓▓▄                    "<<endl;           
        cout << "                     ▄▓▓▓▓▓▓▓▓▀▒▒▓▓▓█████████████████████▌▀▀▓▓▓▓▓▓▌▓▄                 "<<endl;           
        cout << "                   ▄▓▓▓▓▓▓▓▓▀▄▓▓▓▒▓███████████████████████   ▀▓▓▓▓▒▓▀                 "<<endl;           
        cout << "                   ▓▓▄▓▄▀▓▌▐▓▓▓▓▓▓▓▓██████████████████████▐░▄  ░▒░░                   "<<endl;           
        cout << "               ▒░░░░▄██▀░▒▄▓▓▓▓▓▓▓▓▓▓▀███████████████████▌▓▓▓▓                        "<<endl;           
        cout << "                ░░░███▀▒▄▓▓▓▓▓▓▓▓▓▓▓▓▓▐██████████████████▒▓▓▓▓▌                       "<<endl;           
        cout << "                 ▄███▌▒░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓████████████████▀▒▓▓▓▓▓▌                       "<<endl;           
        cout << "                ▄███▌▒░▐▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓█████████▓▓▓▓▀▄▓░▓▓▓▓▓                        "<<endl;           
        cout << "              ▄█████ ░▒▐░▓▓▓▓▓▓▓▓▓▓▓▓▌▄▓▓▓▓▓▓▓▓▓▓▓▀▒▒░░░░░░░░                         "<<endl;           
        cout << "          ▄▄███████▌   ▐░░░░░▓▓▓▓▓▓▌▒▓▓▓▓▓▓▓▀▀▀   ▀▒▓░░░░░░▒▒▄                        "<<endl;           
        cout << "         ▓█████▓███▓    ▒░░░░░░░▌░                         ▀▀▀▀▀                      "<<endl;           
        cout << "          ▓▓▓▀▀▀▀██▓     ░▄▓▓▓▒                                                       "<<endl;

    }else if(nome=="Mew       "){

        cout << "                              ▄▄███                                                   "<<endl;   
        cout << "                            ▄██████                                                   "<<endl;    
        cout << "                         ▄███████▀                                                    "<<endl;    
        cout << "                      ▄▓▓▓▓▓▓▓▓▌         ▄▄▄▄▄                                        "<<endl;    
        cout << "                    ▄▓▓▓▓▓▓▓▓▀  ▄▄▄▓██████████▄                                       "<<endl;    
        cout << "                  ▓▓▓▓▓▓▄███▌▄███████████████▓▌                                       "<<endl;    
        cout << "                ▓▓▓▓▓▓▓████████████████████████▄                                      "<<endl;    
        cout << "              ▓▓▓▓▀▀    █████████████████▓▌▀████▄                                     "<<endl;    
        cout << "            ▄▓▀          █████████████▓▌█▌▀░▀████                                     "<<endl;    
        cout << "           ▓▀           ▀██▓█▄▀▓███████▐██░▓░███▀                                     "<<endl;    
        cout << "         ▄▌             ▓████░░▐███████▌██▌▓███        ▄▄░░░░░▀▀▀▀  ▀▀▀▀▀▒▄▄          "<<endl;    
        cout << "        ▄▀               █████░▒██████████▓▓▀░▄▄░▀░                         ▀         "<<endl;    
        cout << "       ▄▀                  ▀▀████████████▌▄▓▓▓▄▄▄▄▄▄▄▄▄                     ▓         "<<endl;    
        cout << "       ▌                        ░▀████▀▌▒▓▓▓▓▓██████████                   ▓          "<<endl;    
        cout << "       ▓                  ▄░▀    ▄▄▓▓▓▓▓▓▓▓▓███▓▄                       ▄▓▀           "<<endl;    
        cout << "         ▀░░░▄▄▄▄▄░░░░░        ▄███▓▀   ██████████▄                   ▄▓▀             "<<endl;    
        cout << "                               ▀▀       ████████████▄▄             ▄▓▀                "<<endl;    
        cout << "                                        ███████████████▄        ░▒▀                   "<<endl;    
        cout << "                                        █████████████████▌  ░▄░░                      "<<endl;    
        cout << "                                       ▌████████▌██████████░░                         "<<endl;    
        cout << "                                      ▐▌█████████▓█████████▌                          "<<endl;    
        cout << "                                      ▐███████████▌▀█████▓▓▌                          "<<endl;    
        cout << "                                      ▐▀███████▓▓▓▓▓▒▒▀▓▓▓▓▓▓                         "<<endl;    
        cout << "                                      ▐▓▓▓▀▀▀▀▀▀▀▀▀▀      ▓▓▓▌                        "<<endl;    
        cout << "                                       ▓▓▓▓               ▐▓▓▓▌                       "<<endl;    
        cout << "                                       ▓▓▓▓▓               ▓███▌                      "<<endl;    
        cout << "                                        ▓▓▓▓▓▄             ▐████▌                     "<<endl;    
        cout << "                                        ▐▓██▓█▄             █████▌                    "<<endl;    
        cout << "                                         ▐█▓█▓▀             ██████▌                   "<<endl;    
        cout << "                                           ░▀▀              ▓██████                   "<<endl;

    }else if(nome=="Snorlax   "){

        cout << "                                 ▄▄░                                                  "<<endl;
        cout << "                                ▒░▓▓░░░ ░▄▄▄▄▄▄▄   ▄▒▓▓▓░░                            "<<endl;
        cout << "                                ░░▓░░▓▓▓▓▓▓▓░░▓▓▒▓▓▓▓░░▓░░                            "<<endl;
        cout << "                               ▐░▓▓▓▓▓▓▓▓▓░░░░▓▓▓▓▓░▓░▓░░░                            "<<endl;
        cout << "                              ▐▓▓▓░▄▄▄░░▓░░▓▓▌▄▄▌▒░▓▓▓░░░                             "<<endl;
        cout << "                            ▄▐▓▌▄██████▄▒░░▒▄██████▄░░░░░░░░                          "<<endl;
        cout << "                        ▄▒▓▓▓▒▓██████████▄▄████████▓▓▄░░░░░░░░░░░                     "<<endl;
        cout << "                     ▒▓▓▓▓▓▓▓░▌██████████████████▓▓▓▓▓▌░░░░░░░░░░▓▌▄                  "<<endl;
        cout << "                  ▄▓▓▓▓▓▓▓▓▓▓▌░▀██████████████▓▓▓▓▓▓▓▓▓░░░░░░░░░▓▓▓▓▓▒                "<<endl;
        cout << "                ▒▓▓░▓▓▓▓▓▓░░░▓░▒░▓▓▓▓▓▀▓▓▓▓▓▓▓▀▓▓▓▓▓▓▓░░░░░░░░░░▓▓▓▓▓▓▓▌              "<<endl;
        cout << "              ░░░░░░░░░░░░░░░░░░▄▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▄▄░░░░░░░▓▓▓░░▓▓▓▓▓▌            "<<endl;
        cout << "             ░░░░░░░░░░░░░░░▄▄█████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▄▄░░░░░░░░░▓▓▓▓▓▓░▒          "<<endl;
        cout << "            ░░░░░░░░░░░░░░▄███████████████▓▓▓▓▓▓▓▓██████████▄░░░░░░░░░░░░░░░░         "<<endl;
        cout << "              ▄ ▐  ░░░░░▄████████████████████████████████████▄░░░░░░░░░░░░░░░░        "<<endl;
        cout << "                   ░░░░████████████████████████████████████████░░░░░░░░  ▄░░▄░        "<<endl;
        cout << "                  ░░░░▓█████████████████████████████████████████░░░░░░░               "<<endl;
        cout << "                  ░░░▐██████████████████████████████████████████░░░░░░░               "<<endl;
        cout << "                 ▄▄░░▓▓█████████████████████████████████████████▌░░░░░░░              "<<endl;
        cout << "           ██▄▄▄▐█▌░░▓▓▓▓▓▓████████████████████████████████████▓▓█░░░░▄█              "<<endl;
        cout << "          █▄██████▓█▓▓▓▓▓▓▓▓▓▓▓▓▓██████████████████████▓▓▓▓▓▓▓▓▓▀▓▓▓█▄▓▓▌▄  ▄         "<<endl;
        cout << "       ▐█▒███████████▓▓▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓████████████▄▓▀         "<<endl;
        cout << "        ▐██▀▀░░░▀▀██▓▓▓▓▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▓▓█████████████▀         "<<endl;
        cout << "         ██▒▓▓▓▓▓░▒▀▓▓▓▓▓░░▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░▓▓▓▓▓▀░▓▓▓▓▒▀███▌         "<<endl;
        cout << "          ▀▌░░░░░░░░▐▓▓▓▓░░░░░░▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▀▀░░░░▓▓▓▌░░░░░░░░░███          "<<endl;
        cout << "            ▀▄░░░░░░▓▓▓▓            ▀▀▀▀▓▓▓▓▓▓▀▀▀▀▀  ░░░░░░░▐▓▓▒░░░░░░░░▄▓▀           "<<endl;
        cout << "                ▀▀▀▀▀                                         ▀▓▓▄▄▄▄▄▓▀              "<<endl;

    }else if(nome=="Horsea    "){

        cout << "                                  ▄▄▄█████▓▓▓▓▓▄▄        ▄▄                           "<<endl;       
        cout << "                               ▄█████████▓▓▓▓▓▓▓▓▓▓▄  ▄████                           "<<endl;       
        cout << "                             ▄████████▓▓▓▓▓▓▓▓▓▓▓▓▀▓▓▓▓▓▓                             "<<endl;       
        cout << "                           ▐████▀████▄▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌                              "<<endl;       
        cout << "                          ▐████▀▒▒▀███▌▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌▓▓▓                             "<<endl;       
        cout << "           ▄▄▄▄           ▓▓▓▓▓▐▀▓▓▐███▐▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                             "<<endl;       
        cout << "          ▐▌▐▓█████▓▓▓▄▄▄▄▓▓▓▓▌▒ ▐▓▐███▐▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██████                   "<<endl;       
        cout << "          ▐▌  ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▐░▄▓▐██▌▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▀▀▀▀                     "<<endl;       
        cout << "           ▓  ▐▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▄▓▓▌███▄▓▓▓▓▓▓▓▓▓▓▓▓▓▓▀▒▓▓                             "<<endl;       
        cout << "           ▐▌  ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▄▀▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌▀▓▓                              "<<endl;       
        cout << "             ▒ ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▄                              "<<endl;       
        cout << "               ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▀▀▓▓▓▓▓▓█▓▄                          "<<endl;       
        cout << "                               ▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▀    ▀▀███▌       ▄▄               "<<endl;       
        cout << "                                   ▀▀▀▓▓▓▓▀▀▀▒▓▓▓▓▌           ▄▄▓█████████▄           "<<endl;       
        cout << "                                         ▐▓▓░▓▓▓▓▓▓       ▄▒▓▓▓▓███▀███████▌          "<<endl;       
        cout << "                                         ▓▓▓░▓▓▓▓▓▓     ▒▓▓▓▀▓▓████████████           "<<endl;       
        cout << "                                       ▄███▄▐▓▓▓▓▓▓▓ ▄▓▀▓▒▓▓▓▓▓██████████▀            "<<endl;       
        cout << "                                    ▄███████▐▓▓▓▓▓▓▓░▒▀▀▀▀▀▀▀▀██████████▀             "<<endl;       
        cout << "                                 ▄▄█████████▓▓▓▓▓▓▓▓▌ ▀▓▓▓▓▓▓█████████▀               "<<endl;       
        cout << "                               ▄███████████░▓▓▓▓▓▓▓▓▓      ▀▀▀▀▀▀▀▀                   "<<endl;       
        cout << "                             ▄█████████▀███▐▓▓▓▓▓▓▓▓▓░                                "<<endl;       
        cout << "                            ▄█▀█████████▓▀▄▓▓▓▓▓▓▓▓▓▓░                                "<<endl;       
        cout << "                    ▄▄▄▄▄▄▄▐██████▀███▓█▀▓▓▓▓▓▓▓▓▓▓▓▓                                 "<<endl;       
        cout << "                ▄█████████▓▓▓▄▀████▓▌▓▀▓▓▓▓▓▓▓▓▓▓▓▓▓▌                                 "<<endl;       
        cout << "              ▄█████████▓▓▓▓▓▓▓▄██▓▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                                  "<<endl;       
        cout << "             ▐▓████▓▓▓▓▓▓▓▀▓▓▓▓▓▐▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                                   "<<endl;       
        cout << "             ▓▓▓▓▓▓▓▌▓▓▓▓▓▓▓▓▓▓▓▐▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                                    "<<endl;       
        cout << "             ▓▓▓▓▓▓▓▐▓▓▓▓▓▓▓▓▓▓▌▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▀                                     "<<endl;       
        cout << "             ▐▓▓▓▓▓▓▄▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▀                                       "<<endl;

    }else if(nome=="Eevee     "){

        cout << "             ▒ ░ ▓                                                                    "<<endl;          
        cout << "             ░ ░░░▀▄                                                                  "<<endl;          
        cout << "             ▒ ░░░░▒▒                                                                 "<<endl;          
        cout << "             ▐░░░░░░▒▄                                                                "<<endl;          
        cout << "              ▌░░░░░░▓                                                                "<<endl;          
        cout << "              ▐░ ░░░  ▌                                  ▄▄▄   ▒▀                     "<<endl;          
        cout << "               ▐▄     ▓  ▐▄ ▓▌▄▄▐▓▄             ▄▄▒▒▀░░░░░░░░ ▒                       "<<endl;          
        cout << "                 ▒    ▒░▐▓▓▓▓▓▓▓▓▓▓▓▓▌▐      ▄▒▀   ░░░░░░░░░▒░                        "<<endl;          
        cout << "                   ░ ▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▄  ▒▀     ░░░░░░░▄▒          ▄                "<<endl;          
        cout << "                     ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌▌░           ░▒▀          ▄▓█▄               "<<endl;          
        cout << "                    ▒▓▓▒▀▓▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌    ▄▄▄▄▒▒▀          ▄▓▓█▓▓▓               "<<endl;          
        cout << "                    ▓▓ ▐ ▐▌▓▓▓▓▓▓▓▓▌▌▌▓▓▓▓▓▒             ▄▄▄▓▓▓▓▓▓▓▓▓▓▓               "<<endl;          
        cout << "                   ▐▓▌   ▐▓▓▓▓▓▓▓▓▓▌ █ ▒▓▓░░       ░▒░░░░░░░░░▀░░░▓█▓▓▓               "<<endl;          
        cout << "                   ▐▓▌░ ░▒▓▓▓▓▓▓▓▓▌    ▐▓░▒      ▒░░░░░░░░░░░░░░░░▓▓██▓               "<<endl;          
        cout << "                 ▄ ░▓▓▒▄▒▓▓▓▓▓▓▓▓▓▌    ▐░░     ░░░░░░░░░░░░░░░░░░░▓▓▓▓▌               "<<endl;          
        cout << "               ▄███░░▓▓▓▓▌▓▓▓▒▓▓▓▓▌▄░░▒░░▒▄▄   ░░░░░░░░░░░░░░░░░░░▀░░▓                "<<endl;          
        cout << "              ▄██████▄▒░▓▓▓▓▓▒▌▒▒▓▓▓▓░░░▒▓▓▓▓▌░░░░░░░░░░░░░░░░░░░░░░░░                "<<endl;          
        cout << "             ▀██████████▄▒▒░░░░░░░░░░▒▒▄▓▓▓▓▓▓▓░░░░░░░░░░░░░░░░░░░░░░                 "<<endl;          
        cout << "             ▀█████████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░░░░░░░░░░░░░░░░░░░░░                  "<<endl;          
        cout << "              ▀▓██▌████▓███████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌▌░░▌░░░░░░░░░░░░░░░░                    "<<endl;          
        cout << "                ▀▓▒███████████████▓▌▓▓▌▓▓▓▓▓▓░▒░░░░░░░░░░░░░░░░░                      "<<endl;          
        cout << "                   █▓█▓███████████▓▓▓▓▌▓▓▓▓▀░░░░░░░▌  ░░░░                            "<<endl;          
        cout << "                    ▀▓▌▓▓▓▓█▓████▓▓▒▓▀▀▀▀░▒░░░░░░░░░                                  "<<endl;          
        cout << "                      ▀▀▓▓▓▓▓▓▓▓▓▓▓▀░▓░░░░░▒░░░░░░░▌                                  "<<endl;          
        cout << "                      ▒▓▒░▀▓▓▀▓▒░▐░░░░▐▀░░  ▓▓▓▓▓░░░                                  "<<endl;          
        cout << "                       ░░░░░░░▓░░░░░░░░░░░   ▓▓▓▓▓▓░                                  "<<endl;          
        cout << "                       ▐▓▓▓▓░▐▓▓▓▓░░▒░░░░    ▓▓▓▓▓▌                                   "<<endl;          
        cout << "                        ▓▓▓▓▓▐▓▓▓▓▓▓░░░░    ▓▓▓▓▓▌                                    "<<endl;          
        cout << "                       ▄▓▓▓▓▌▓▓▓▓▓▓░       ▌▌▓▓▓▌                                     "<<endl; 

    }else if(nome=="Venusaur  "){

        cout << "                                     ▄▓▓▓▓▓▄▓▓▌▓█                                     "<<endl;   
        cout << "                        ▄▄▄▓▓▓▓▓▓▓███▓▓▓▓▀▀░▀▓▓▓▓▄▄▓▓▓▓▓▓▓▀▄▄                         "<<endl;   
        cout << "                     ▄▓█▓▓▓▓▓█▓▓████▓▓▓▀     ▀▓▓▓█████▓▓▓▓▓███▓█▄▄                    "<<endl;   
        cout << "                   ▄▓▓▓█▓▓███████████▀        ▓██████████▓▓▀█▓▓▓▀▓▓                   "<<endl;   
        cout << "                  ▀▀ ▀▀▀▐▓▀▐▓▓██▀▓▓▓░░░░░  ░░░▐▓▓▓▀▓▓▓▓▓▌▓▓▓ ░                        "<<endl;   
        cout << "                            ░░░      ░░░ ░░ ░░░░░  ▀▀▀▀▀░░░░░░░░░░░                   "<<endl;   
        cout << "                ▄▄░░░░░░░░░░░░░░░░   ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▄                 "<<endl;   
        cout << "            ▄▓▓▓▌▌░▒▓░░░░░▐░░▐░░░░░ ░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒░▒▓▌▌▒▄▄            "<<endl;   
        cout << "         ░▓▓▓▌▓▓▓▓▓▓▓▓▓░▓░░░░ ░░░░░░░░░░░░░░░░░░░░░░░░░░░░▓░▒▄░░▓▓▓▓▄▀▓▓▓▓▓▄          "<<endl;   
        cout << "       ▒▒▓░▓▓▓▓▓▓▓▓▓▌▓▓ ▒▀░░  ░   ░  ░░░▒░░░░░░░░▀░▄░░▓▓▓░▓▓▓▌▓▒▓▌▓▓▓▓▓▓▓▓▓▓▄         "<<endl;   
        cout << "       ▓▀ ▓▓▓▓▓▓▓▌▓▓▌▌▀░ ▄▓▓▓▓▄▓▓▓▓▄▓█▓▓░▒░░░░░ ░░▐▌ ▓▓▓▓▓▓▓▓▓▓▄▀░▓▓▌▓▓▓▓▓▓▌          "<<endl;   
        cout << "         ▄▓ ▐▓▌▌▓░▀░▀▓▓▓▓▓▓▓▓█▓▓▓▓▓▓▓▀▓▓▓▓▓▓█▀░░    ▓▓▓▐▓▓▓▓▓▓▓▓  ▐▀░▐▓░▓▓▀▓▌         "<<endl;   
        cout << "        ▐▌  ▓▓      ░░▀▌▓▓▓▓▓▓▓▓▓▀▓▓▓▓▓▓▓▓▀░░░▒░░░░░░▀ ▓▓▌▓▓▓▓▒▀ ░    ░ ▐▀░░▀▓        "<<endl;   
        cout << "                ░░░░░▀▄▓▓▓▓▄▓▓▓▓▓▒▓▓▓▓▓▓▓▓▓▓▓▄░░░░░░░░░▀▀░▓▓▌▓▌        ░  ░           "<<endl;   
        cout << "             ░░░░░░░▄▓▌▓▓▌▓▀▓▓▓▓▀▓▓▓▓▓▓▓▓▓▓▓▓▓▓▄░░░░░░░░░░▀▓▌░░░                      "<<endl;   
        cout << "           ░░░░░░░░▓▓▓█▄░▓▓▄▀░░▓▄▄▓▌▓▌▀░█▓▓▓▓▓▓▓▌░░░░░░░░░░░ ░░░░░░                   "<<endl;   
        cout << "               ▄▄▓▓▒▀▓▓▓▓▓██▒▓░▓▓▓▓▓▓▓█▓▓▓▓▓▒▓▓▒▓▓▌░░░░░░░░░░░░░░ ░░                  "<<endl;   
        cout << "              ▒▓▓▓▓▓▓▒░▌▀▀▓██▓█▓██▀▀▒░░▒▀▌░▓▒▒▐▓▓▓▓▓▓▓▄░░░░░░░░░░                     "<<endl;   
        cout << "              ▓▓▓▓▓▓▓▓▓░▄░▒▓▒▄▄▓▓▓▓░░░░░▒▒░░░░▓▓▓▓▓▓▓▓▓▓▓░░░░░░░░░                    "<<endl;   
        cout << "              ▐░░▓▓▓░░░░▌  ░░▀▀▀▀▀▀░░░░░░░░░░░▓▓▓▓▓▓▓▓▓▓▓▒░░░░▒░▓                     "<<endl;   
        cout << "               ▓░░░░░░░▓     ░░░░░░░          ▐░░░░░░░░░▌▒▒░░▓░▒                      "<<endl;   
        cout << "              ▄▄▄▌▐▓▄▌▒                       ▐░▒░▒▒▓░▒▒    ▀  ▀                      "<<endl;   
        cout << "                                               ▀  ▐█  ▀▀                              "<<endl; 

    }else if(nome=="Charizard "){

        cout << "                                    ▄▄▄                                               "<<endl;   
        cout << "                                 ▓▓▀▀▌▓▓▓▄▒▄                                          "<<endl;  
        cout << "                           ▄▒    ▐▓▓▓▓▓▓▌▌▀▌▓▓▄                                       "<<endl;  
        cout << "                   ▄▄▄▒▒▒▓▓░      ▀▓▓▓▓▓▓▓▓▒▓▌ ▀▀▒▄            ▀▄                     "<<endl;  
        cout << "                 ▄▀░░▄▒▒░░░░         ▀▀▀▓▓▓▓▓▓                  ▒▒░                   "<<endl;  
        cout << "             ▄░░░▒░░░░░░░░░▒             ▓▓▓▓▓▄                ▐░░░░░▄                "<<endl;  
        cout << "           ▒░░▓░░░░░░░░░░░░░▓             ▓▓▓▓▓               ░░░░░░░▒░░              "<<endl;  
        cout << "          ▄░▒░░░░░░░░░░░░░░░░▌            ▓▓▓▓▓▌             ░░░░░░░░░░▒▒░            "<<endl;  
        cout << "         ▒░░░░░░░░░░░░░░▒░░░▒░▀░▄         ▓▓▓▓▓▓            ░░░░░░░░░░░░░▌░░░         "<<endl;  
        cout << "        ▒░░░░▀      ▌░░░░░░░░░░░░░░░▄     ▓▓▓▓▓▓▌        ░░░░░░░░░░░░░░░░░░▒░░        "<<endl;  
        cout << "       ▓░░░          ▐░░░░░░░░░░░░░░░░▒▒░ ▓▓▓▓▓▓▓ ▐▒▒░░░░░░░░░░░░░░░░▓░░░░░░░░        "<<endl;  
        cout << "       ▌░░             ░░░░     ░░░▄▄▄▓▓▓▓▓▓▓▓▓▓▓▌▒▄░░░░░░░░░░░░░░░░   ░▒░░░░░░       "<<endl;  
        cout << "       ▒░               ▒     ▄▓▌▀▀▀▀▀▓▓▓▓▓▓▓▓▓▓▓▌▓▓▓▀▀▀▀▓▒   ▀░░░     ▓░ ░░░░▐       "<<endl;  
        cout << "                           ▄▄▓▓      ▄▓▓▓▓███████▌▌▌░     ▀▓▒   ░     ▒▓▓▌  ░░▐       "<<endl;  
        cout << "                         ▀ ▓▓▓▓▓    ▓▓▓▓▓█████████▓▌▒     ▄▓▓▓▓▓▄     ▐▌██▄  ░▐       "<<endl;  
        cout << "                           ▀  ▐▀  ▄▓▓▓▓███████████▓▓▓░    ▀  ▓░      ▄█▌▌▓    ▌       "<<endl;  
        cout << "                                 ▄▓▓▓▓████████████▓▓▓▓               ▐▓██▌▒░          "<<endl;  
        cout << "                              ▄▓▓▓▓▓▌███████████▓▓▓▓▓▓░              ██▓███▌          "<<endl;  
        cout << "                   ▄▒▓▓▓░░░░░▓▓▓▓▓▓▓▌▓▓▓███████▓▓▓▓▓▓▓▒▌▒            ▀█▀▓▀            "<<endl;  
        cout << "                 ▄▓▓▓▓▓▓▓▓▓▒▓▓▓▓▓▓▓▓▌▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌▓▓▓▓▓           ░               "<<endl;  
        cout << "                ▓▓▓▓▓▓▓▓░░░▓▓▓▓▓▓▓▓▓▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌      ▄░░                "<<endl;  
        cout << "               ▐░░░░░░░░░░▓▌▓▓▓▓▓▌▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▀▒▓▓▓▓▓▓▓▓▓▓░▓▀▒░▒▀                  "<<endl;  
        cout << "                ░░░░░▒▓▌▓░▓▓▓▓▓▓░▓▓▓▓▌▓▓▓▓▀▀▀▀░░▓▓▒▒░▒▌▓▓▓▓▓▓░░░                      "<<endl;  
        cout << "                   ▀▀▀▀▀▀▓▌▓▓▓▌▓░                     ▐▓▌▌▓▌▌▄                        "<<endl;  
        cout << "                        ▐█▓▓▌▌▄▀                          ▀▌▀▌▀                       "<<endl;  
        cout << "                        ▐  ▀  ▀                                                       "<<endl;

    }else if(nome=="Blastoise "){

        cout << "                                          ▄▄▄▄▓▓▓▓▓▓▓▓▓▄                              "<<endl;     
        cout << "                                         ▌  ▀▓▓▓▓▌▒▓▄▌▒▄▓▄▄▒▒▓▒                       "<<endl;       
        cout << "                                         ▐▌ ▄▓▓▓▓▒▄▓▓▓▓▓▓▓▌▒▒▌▓▒                      "<<endl;       
        cout << "                                          ▐▓▓▓▓▓▓▌▓▓▓▓▓▓░▓▌▒▓▓▓░                      "<<endl;       
        cout << "                                          ▓▓▓▓▓▒▓▄▒▒▒▒▒▓▓▓▓▓▓▓▓                       "<<endl;       
        cout << "                                        ▄▄▌▓▓▓▄▄▓▓▓▓▓▓▓▓▓▓▓▓▓▓▀                       "<<endl;       
        cout << "               ▄▓▓▓█▄            ▄▄▓▓▓▓▓▓▓▓▓▓▓▒░▀▀▓▓▓▓▓▓▓▓▓▓▀                         "<<endl;       
        cout << "              ▐█▓▓▓▓█▓       ▄▒▓▀▀▓▓▓▓▀▀▀▀▒▒▒▒▓▓▓▒░░░▀▓▌▀▀       ▄▄                   "<<endl;       
        cout << "               ▐█▌▓██▀░▓░░▄▄▓▓▌▓▓▓▓▓▌▒░▓▓▓▓▓▓▓░░░░░░░░░▀▄▄▄███████ ▀                  "<<endl;       
        cout << "                 ▀█▀▒░▓░▒▓▓▓▓▓▓▓▓▓▌░░▒▓▌▀▓▓▓▓▌░░░░░░▒▒▄░░█████████  ▌                 "<<endl;       
        cout << "                  ░░▒░▒▓▓▓▓▓▌░▓░░░░░░▐░░░▓▀░░░░░░░░░░░▀▓▌▓▓▓▓▓▓▓▓▓█▄▌                 "<<endl;       
        cout << "                 ░░░▒░░▓▓▌░░░░░░░░░░░░░░░░░░░░░▌░░▐░▒▓░░▄▄▓▓▓▓▓▀▀▀▀                   "<<endl;       
        cout << "                ░░░▓░░▓▓▌░░░░░░░░░░░░░░░░░░░░░░░░░▀▀▄▄▓██▓▒▓▓▓▓▓▐▓▄                   "<<endl;       
        cout << "              ▄▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░ ▐█▓███▌▓▓▓▓▓▓▒▓▓█▄                 "<<endl;       
        cout << "             ▐░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▐█████▐▓▓▓▓▓▀▓▓▓▓▓▌▒               "<<endl;       
        cout << "             ▀░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▀████▒▓▓▓▌▒▓▓▓▓▓▓▓▒▓▒             "<<endl;       
        cout << "               ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▄▓▓██░▀▒▒▓▓▓▓▓▓▓▓▒▓▓▓▄            "<<endl;       
        cout << "              ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▓▓▓▓██░▒▓▓▓▓▓▓▓▌▀▒▓░▌▄ ▀           "<<endl;       
        cout << "              ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▄▓▓▓█▌▓▓▓▓▌         ░  ▀             "<<endl;       
        cout << "             ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▓█▓██▓▀▄▒▓▓                           "<<endl;       
        cout << "            ▄░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▄██████▌▓▓▓░                            "<<endl;       
        cout << "           ▓▓░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▄█████████▒▓▓█                             "<<endl;       
        cout << "          ▓▓▓░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████████▀▓▓▓▒▓▓▄                            "<<endl;       
        cout << "          ▓▓▓░░░░░░░░░░░░░░░░░░░░░░░░░▄▓████████▌▓▓▓▓▓▓▒▓▓▓▄                          "<<endl;       
        cout << "         ▐▓▓▓▐▄░░░░░░░░░░░░░░░░░░░░░▄▓▓███████▌▓▓▓▓▓▓▓▓▓▒▓▓▓▄                         "<<endl;       
        cout << "         ▐▓▓▓▐█▄▄█████▓▓▄░░░░░░░▄▄▓█████████▀░▓▓▓▓▓▓▓▓▓▓▓▐▓▓▓                         "<<endl;       
        cout << "         ▐░▌░▒████▀▀▀▀▀█▓▓▓▓▓▓▓██████▓▓▓▓█▀▒░░░░▓▓▓▓▓▓▓▓▓▒▓▓░                         "<<endl;       
        cout << "          ░░░░░▌▓▓▓▓▓▓░▒░▀▀▓▓▓▓▓▓▓▓▓▀▀▀▀▀░░░░░░░░░░░░░░░░▌░░▌                         "<<endl;       
        cout << "          ▄█▓▄▓▓▓▓▓▓▌░░░░░░░▓▓▓▓▓▓▓▓▓▓▓▓░▒░░░░░░░░░░░░░░░░░░                          "<<endl;       
        cout << "         ▓█▓▒▓▓▓▓▓░░░░░░░░░▓▓▓▓▓▀▀▀▀▀     ▒░░░░░░░░░░░░░░▌░                           "<<endl;       
        cout << "           ▓▓▓▓▌░░░░░▓░░▒                  ░▒▒░░░░░░░░░░░░▒▄                          "<<endl;

    }else if(nome=="Mewtwo    "){

        cout << "                                          ███▌▓▄▄▄▄██▌                                "<<endl;           
        cout << "                                         ▄████▓█████▓▌                                "<<endl;           
        cout << "                                        █████████████▌                                "<<endl;           
        cout << "                                       ▓█████▌███████▓                                "<<endl;           
        cout << "                                        █████▓░▐▓█▌▓▓▓                                "<<endl;           
        cout << "                           ▐████         ▓▓███▓███▓▓▌                                 "<<endl;           
        cout << "                            ▀█▓▌▓       ▓▓  ▓▓▀▓▓▓▓▓▌                                 "<<endl;           
        cout << "                              ▓▓▓▓▓██▓▄▐▒▓█▓▓▌▌ ▄▄                                    "<<endl;           
        cout << "                       ▄▄▄▄▄▄▓▓▓▓▓▓▓███▓███▓███████▄                                  "<<endl;           
        cout << "                       ███▌▀▀▓▓▓▓▓▀▀███▀▓▓▓▓▐█████▓▓▄                                 "<<endl;           
        cout << "             ▓▓▓▓▓▓▒▄                    ███▌████▓▓▓▌▓▄                               "<<endl;           
        cout << "           ▐▌░    ▀▓▓▓▄                   ▐███▓▓▓▓▓▀ ▀▓▓▄▄                            "<<endl;           
        cout << "           ▓░       ▐░░▓                    ▀█▓▓▓▓▓     ▀▀▓▓▄                         "<<endl;           
        cout << "           ░░         ░▓░▒                   ▓▓▓▓▓▓▓▄      ▀▓▓                        "<<endl;           
        cout << "           ░░░        ▐░▓▓▓                 ▄█▓▓▓▓▓▀▓▒       ▓▓▄                      "<<endl;           
        cout << "           ▐░▌         ▐░▓▓▓▒            ▄██████▓▌▓▓▓▓▌▓▄     ▓██▄                    "<<endl;           
        cout << "            ▒░▄         ▐▓▓▓▓░▄        ▄████████▌░▓▓▓▓▓▓▓▓   ▓▓▀▀█▓▄                  "<<endl;           
        cout << "             ▒░▒         ▐▓░▓▓░▓▓▄▄   ███████████▐░▓▓▓▓▓▒▓▓  ▓▌  ▐▓▀▓                 "<<endl;           
        cout << "              ▒░▓▄        ▐░░▓▓▓▓▓▓▓▌▓██████████▌▓▓▓▓▓▓▓▌▓█▌    ▐▓▀░▀                 "<<endl;           
        cout << "               ▒▓▓▓▓▄      ▐░▓▓▓▓▓▓░░██████▓███▓░▓▓▓▓▓▓░▒▓▓░                          "<<endl;           
        cout << "                ▀▓▓▓▓▓▓▄     ▒░░▓▓▓▓▐███▓▓▓▓▓▓▓▀▓▓▓▓▓▓▌▒▓▓▀                           "<<endl;           
        cout << "                  ▓▓▓▓▓▓▓▄     ▀▓░▓▓░▓▓▓▓▓▓▓▓▀░░░░░░░▒▓▓▓▀                            "<<endl;           
        cout << "                   ▀▓▓▓▓▓▓▓       ▀▒▒▓▓▓▓▀▒░▒░░▒▒▀▒▓▓▓▓▀                              "<<endl;           
        cout << "                      ▓▓▓▓▓░        ▓▓▓▀          ▐█▓▌                                "<<endl;           
        cout << "                                  ▄███▀           ▐██▌                                "<<endl;           
        cout << "                                 ▓███             ▓▓▓▌                                "<<endl;           
        cout << "                                ███▌            ▄▓▓▓▓▓▒                               "<<endl;           
        cout << "                               ▓██▓            ▐▓▓▓▐▓▓▓▓▒▄                            "<<endl; 
    }
}