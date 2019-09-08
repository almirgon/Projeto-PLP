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
    int defesa;
    int num;
    bool condicao;
};

Carta player1[4];   
Carta player2[4];   
Carta baralho[26];
int vez=2;
bool play1;
bool play2;
void chamaArt(string nome);

void inicializar_player1()
{
   player1[0]=baralho[0];
   player1[1]=baralho[1];
   player1[2]=baralho[2];
   player1[3]=baralho[3];

}

void inicializar_player2()
{
    player2[0]=baralho[4];
    player2[1]=baralho[5];
    player2[2]=baralho[6];
    player2[3]=baralho[7];

}

void inicializa_cartas()
{
    baralho[0].tipo = "GRASS     ";
    baralho[0].nome = "Bulbasaur ";
    baralho[0].ataque = 30;
    baralho[0].defesa = 60;
    baralho[0].condicao= true;
    baralho[0].num=10;

    baralho[1].tipo = "GRASS     ";
    baralho[1].nome = "Venusaur  ";
    baralho[1].ataque = 50;
    baralho[1].defesa = 80;
    baralho[1].condicao= true;
    baralho[1].num=11;

    baralho[2].tipo = "FIRE      ";
    baralho[2].nome = "Charmander";
    baralho[2].ataque = 31;
    baralho[2].defesa = 50;
    baralho[2].condicao = true;
    baralho[2].num=12;

    baralho[3].tipo = "FIRE      ";
    baralho[3].nome = "Charizard ";
    baralho[3].ataque = 70;
    baralho[3].defesa = 70;
    baralho[3].condicao = true;
    baralho[3].num=13;

    baralho[4].tipo = "WATER     ";
    baralho[4].nome = "Squirtle  ";
    baralho[4].ataque = 48;
    baralho[4].defesa = 58;
    baralho[4].condicao = true;
    baralho[4].num=14;

    baralho[5].tipo = "WATER     ";
    baralho[5].nome = "Blastoise ";
    baralho[5].ataque = 38;
    baralho[5].defesa = 80;
    baralho[5].condicao = true;
    baralho[5].num=15;

    baralho[6].tipo = "BUG       ";
    baralho[6].nome = "Caterpie  ";
    baralho[6].ataque = 30;
    baralho[6].defesa = 60;
    baralho[6].condicao = true;
    baralho[6].num=16;

    baralho[7].tipo = "BUG       ";
    baralho[7].nome = "Weedle    ";
    baralho[7].ataque = 35;
    baralho[7].defesa = 50;
    baralho[7].condicao = true;
    baralho[7].num=17;

    baralho[8].tipo = "FLY       ";
    baralho[8].nome = "Pidgey    ";
    baralho[8].ataque = 35;
    baralho[8].defesa = 50;
    baralho[8].condicao = true;
    baralho[8].num=18;

    baralho[9].tipo = "NORMAL    ";
    baralho[9].nome = "Ratata    ";
    baralho[9].ataque = 20;
    baralho[9].defesa = 50;
    baralho[9].condicao = true;
    baralho[9].num=19;

    baralho[10].tipo = "POISON    ";
    baralho[10].nome = "Ekans     ";
    baralho[10].ataque = 37;
    baralho[10].defesa = 48;
    baralho[10].condicao = true;
    baralho[10].num=20;

    baralho[11].tipo = "ELECTRIC  ";
    baralho[11].nome = "Pikachu   ";
    baralho[11].ataque = 70;
    baralho[11].defesa = 50;
    baralho[11].condicao = true;
    baralho[11].num=21;

    baralho[12].tipo = "POISON    ";
    baralho[12].nome = "Nidoran   ";
    baralho[12].ataque = 27;
    baralho[12].defesa = 80;
    baralho[12].condicao = true;
    baralho[12].num=22;

    baralho[13].tipo = "FAIRY     ";
    baralho[13].nome = "Clefairy  ";
    baralho[13].ataque = 35;
    baralho[13].defesa = 75;
    baralho[13].condicao = true;
    baralho[13].num=23;

    baralho[14].tipo = "NORMAL    ";
    baralho[14].nome = "Jigglypuff";
    baralho[14].ataque = 20;
    baralho[14].defesa = 50;
    baralho[14].condicao = true;
    baralho[14].num=24;

    baralho[15].tipo = "FLY       ";
    baralho[15].nome = "Zubat     ";
    baralho[15].ataque = 20;
    baralho[15].defesa = 30;
    baralho[15].condicao = true;
    baralho[15].num=25;

    baralho[16].tipo = "GRASS     ";
    baralho[16].nome = "Oddish    ";
    baralho[16].ataque = 35;
    baralho[16].defesa = 60;
    baralho[16].condicao = true;
    baralho[16].num=26;

    baralho[17].tipo = "GROUND    ";
    baralho[17].nome = "Diglett   ";
    baralho[17].ataque = 30;
    baralho[17].defesa = 20;
    baralho[17].condicao = true;
    baralho[17].num=27;

    baralho[18].tipo = "NORMAL    ";
    baralho[18].nome = "Meowth    ";
    baralho[18].ataque = 36;
    baralho[18].defesa = 40;
    baralho[18].condicao = true;
    baralho[18].num=28;

    baralho[19].tipo = "WATER     ";
    baralho[19].nome = "Psyduck   ";
    baralho[19].ataque = 30;
    baralho[19].defesa = 64;
    baralho[19].condicao = true;
    baralho[19].num=29;

    baralho[20].tipo = "FIRE      ";
    baralho[20].nome = "Growlithe ";
    baralho[20].ataque = 50;
    baralho[20].defesa = 53;
    baralho[20].condicao = true;
    baralho[20].num=30;

    baralho[21].tipo = "WATER     ";
    baralho[21].nome = "Poliwag   ";
    baralho[21].ataque = 40;
    baralho[21].defesa = 60;
    baralho[21].condicao = true;
    baralho[21].num=31;

    baralho[22].tipo = "GRASS     ";
    baralho[22].nome = "Weepinbell";
    baralho[22].ataque = 38;
    baralho[22].defesa = 50;
    baralho[22].condicao= true;
    baralho[22].num=32;

    baralho[23].tipo = "GROUND    ";
    baralho[23].nome = "Geodude   ";
    baralho[23].ataque = 40;
    baralho[23].defesa = 40;
    baralho[23].condicao = true;
    baralho[23].num=33;

    baralho[24].tipo = "ELECTRIC  ";
    baralho[24].nome = "Magnemite ";
    baralho[24].ataque = 35;
    baralho[24].defesa = 30;
    baralho[24].condicao = true;
    baralho[24].num=34;

    baralho[25].tipo = "POISON    ";
    baralho[25].nome = "Grimer    ";
    baralho[25].ataque = 30;
    baralho[25].defesa = 70;
    baralho[25].condicao = true;
    baralho[25].num=35;

    baralho[26].tipo = "ELECTRIC  ";
    baralho[26].nome = "Voltorb   ";
    baralho[26].ataque = 30;
    baralho[26].defesa = 60;
    baralho[26].condicao = true;
    baralho[26].num=36;

    baralho[27].tipo = "GROUND    ";
    baralho[27].nome = "Cubone    ";
    baralho[27].ataque = 35;
    baralho[27].defesa = 50;
    baralho[27].condicao = true;
    baralho[27].num=37;

    baralho[28].tipo = "PSYCHIC   ";
    baralho[28].nome = "Mew       ";
    baralho[28].ataque = 80;
    baralho[28].defesa = 67;
    baralho[28].condicao = true;
    baralho[28].num=38;

    baralho[29].tipo = "NORMAL    ";
    baralho[29].nome = "Snolax    ";
    baralho[29].ataque = 40;
    baralho[29].defesa = 99;
    baralho[29].condicao = true;
    baralho[29].num=39;

    baralho[30].tipo = "WATER     ";
    baralho[30].nome = "Horsea    ";
    baralho[30].ataque = 43;
    baralho[30].defesa = 30;
    baralho[30].condicao = true;
    baralho[30].num=40;

    baralho[31].tipo = "NORMAL    ";
    baralho[31].nome = "Eevee     ";
    baralho[31].ataque = 65;
    baralho[31].defesa = 55;
    baralho[31].condicao = true;
    baralho[31].num=41;

    baralho[32].tipo = "PSYCHIC   ";
    baralho[32].nome = "Mewtwo    ";
    baralho[32].ataque = 99;
    baralho[32].defesa = 99;
    baralho[32].condicao = true;
    baralho[32].num=42;

    random_shuffle(&baralho[0], &baralho[32]);
}

void batalha(Carta carta1, Carta carta2){
    cout << "---------------------------------------------"<< endl;
    
    int life1 = carta1.defesa ;
    cout << carta1.nome + "/ " + std::to_string(life1) << endl;
    chamaArt(carta1.nome);
    cout << "-------------------VS---------------------"<< endl;
    this_thread::sleep_for(chrono::milliseconds(2000));

    int life2 = carta2.defesa ;
    cout << carta2.nome + " / " + std::to_string(life2)<< endl;

    chamaArt(carta2.nome);
    this_thread::sleep_for(chrono::milliseconds(2000));
}

Carta ataque(Carta carta1,Carta carta2){
    carta2.defesa = carta2.defesa - carta1.ataque;
    if(carta2.defesa<=0){
        carta2.defesa=0;
    }
    return carta2;
}

void mostraDeck(Carta p1[]){
    string tipoFull, nomeFull,atkFull, defFull, layout,num;
    for(int i = 0; i <= 3; i++){
        if(p1[i].condicao==true){
            layout+= "-----------------";
            nomeFull += "Nome: " + p1[i].nome+"|";
            tipoFull += "Tipo: " + p1[i].tipo+"|";
            atkFull += "ATK:  " + std::to_string(p1[i].ataque)+ "        "+"|";
            defFull += "DEF:  " + std::to_string(p1[i].defesa)+ "        "+"|";
            num+= "NUM:  "+ std::to_string(p1[i].num)+"        "+"|";
        }
    }

    cout << layout << endl;
    cout << nomeFull<< endl;
    cout << tipoFull<< endl;
    cout << atkFull << endl;
    cout << defFull << endl;
    cout << num << endl;
    cout << layout << endl;
}


void setup(){
    inicializa_cartas();
    inicializar_player1();
    inicializar_player2();
}

int ia(Carta player[]){
    int melhorATK = 0;
    int j = -1;
    for(int i = 0; i<4; i++){
        if (player[i].condicao==true){
            if (player[i].ataque>= melhorATK){
                j= i;
                melhorATK= player[i].ataque;
            }
        }
        
    }
    return j;
}

int selecionaCarta(bool play, Carta mao[]){
    int numCarta = -1;
    int iReal1 =-1;
    if(play==true){
        cout << "Selecione uma carta: " << endl;
        cin >> numCarta;
        bool var = false;
        for(int i =0; i<4; i++){
            if(mao[i].num==numCarta){
                if(mao[i].condicao==true){
                    var= true;
                    iReal1 = i;
                }
            }
        }
        if(var==false){
            cout << "CARTA INVALIDA, TENTE NOVAMENTE " << endl;
            selecionaCarta(play, mao);
        }else{
            return iReal1;
        }
    }else{
        return ia(mao);
    }
}

void atk(bool x ,Carta playerX[] ,bool y ,Carta playerY[]){
    int num1 = selecionaCarta(x,playerX);
    int num2 = selecionaCarta(y,playerY);

    batalha(playerX[num1], playerY[num2]);

    int random = rand()%2;
    if (random ==0){
        Carta newCarta = ataque(playerX[num1], playerY[num2]);
        if(newCarta.defesa==0){
            newCarta.condicao = false;
        }   
        playerY[num2]=newCarta;
    }else{
        cout << "O POKEMON DESVIOU DO ATK, TENTE NOVAMENTE NA PROXIMA" << endl;
        this_thread::sleep_for(chrono::milliseconds(3000));
    }
}

void select_numero_players()
{
    cout << "SELECIONE O NÚMERO DE JOGADORES (1 ou 2): " ;
    int opcao;
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
        cin.clear();
        cin.ignore();
        select_numero_players();
        break;
    }
}

int verificaStatus(){
    int contador1 = 0;
    int contador2 = 0;
    for(int i =0; i<4; i++){
        if(player1[i].condicao==false){
             contador1++;
        }
        if(player2[i].condicao==false){
            contador2++;
        }
    }
    if(contador1>=4){
        return 1;
    }else if(contador2>=4){
        return 2;
    }else{
        return 0;
    }
}

int main(){    
    cout << "INICIALIZA... " << endl;
    setup();
    select_numero_players();
    while(true){
        mostraDeck(player1);
        mostraDeck(player2);
        if(vez%2==0){
            atk(play1, player1, play2, player2);
        }else{
            atk(play2, player2, play1, player1);
        }
        vez+=1;
        if (verificaStatus()!= 0){
            break;
        }
        system("clear");
    }
    mostraDeck(player1);
    mostraDeck(player2);

    if(verificaStatus()==1){
            cout << "PLAYER 2 WINS"<< endl;
    }else{
            cout << "PLAYER 1 WINS"<< endl;
    }
    return 0;
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

    }else if(nome=="Snolax    "){

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