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
int vez=2;

void inicializar_player1()
{
    player1[0].tipo = "GRASS     ";
    player1[0].nome = "Bulbasaur ";
    player1[0].ataque = 30;
    player1[0].defesa = 70;
    player1[0].condicao= true;
    player1[0].num=001;

    player1[1].tipo = "FIRE      ";
    player1[1].nome = "Charmander";
    player1[1].ataque = 20;
    player1[1].defesa = 70;
    player1[1].condicao = true;
    player1[1].num=002;


    player1[2].tipo = "WATER     ";
    player1[2].nome = "Squirtle  ";
    player1[2].ataque = 10;
    player1[2].defesa = 60;
    player1[2].condicao = true;
    player1[2].num=003;


    player1[3].tipo = "ELECTR    ";
    player1[3].nome = "Pikachu   ";
    player1[3].ataque = 50;
    player1[3].defesa = 70;
    player1[3].condicao = true;
    player1[3].num=70;
    random_shuffle(&player1[0], &player1[4]);

}

void inicializar_player2()
{
    player2[0].tipo = "GRASS     ";
    player2[0].nome = "Bulbasaur ";
    player2[0].ataque = 30;
    player2[0].defesa = 70;
    player2[0].condicao = true;
    player2[0].num=001;

    player2[1].tipo = "FIRE      ";
    player2[1].nome = "Charmander";
    player2[1].ataque = 20;
    player2[1].defesa = 70;
    player2[1].condicao = true;
    player2[1].num=002;

    player2[2].tipo = "WATER     ";
    player2[2].nome = "Squirtle  ";
    player2[2].ataque = 10;
    player2[2].defesa = 60;
    player2[2].condicao = true;
    player2[2].num=003;

    player2[3].tipo = "ELECTR    ";
    player2[3].nome = "Pikachu   ";
    player2[3].ataque = 50;
    player2[3].defesa = 70;
    player2[3].condicao = true;
    player2[3].num=70;
}
void chamaArt(string nome){
    if(nome=="Bulbasaur "){
        cout << "                                           \n";
        cout << "                        _,.------....___,.' ',.-.\n";
        cout << "                     ,-'          _,.---|        |\n";
        cout << "                   ,'         _.-'              .\n";
        cout << "                  /   ,     ,'                   `\n";
        cout << "                 .   /     /                     ``.\n";
        cout << "                 |  |     .                       \\.\\\n";
        cout << "       ____      |___._.  |       __               \\ `.\n";
        cout << "     .'    `---\\\\       ``\\-.--\\'`  \\               .  \\ \n";
        cout << "    .  ,            __               `              |   .\n";
        cout << "    `,'         ,-\\'  .               \\             |    L\n";
        cout << "   ,'          '    _.'                -._          /    |\n";
        cout << "  ,`-.    ,\\.   `--'                      >.      ,'     |\n ";
        cout << " . .'\\'   `-'       __    ,  ,-.         /  `.__.-      ,'\n";
        cout << " ||:, .           ,'  ;  /  / \\ `        `.    .      .'/\n";
        cout << " ||:D  \\          `--'  ' ,'_  . .         `.__, \\   , /\n";
        cout << "/ L:_  |                 .  \\' :_;                `.'.'\n";
        cout << ".    \\\\'                  \\\\\\\\\\'                    V\n";
        cout << " `.                                 .    `.   _,..  `\n* ";
        cout << "   `,_   .    .                _,-'/    .. `,'   __  `\n";
        cout << "    ) \\`._        ___....----\\'  ,'   .'  \\ |   '  \\.\n";
        cout << "   /   `. \\`-.--\\'         _,' ,'     `---' |    `./  |\n";
        cout << "  .   _  `\\\\ '--.._____..--\\   ,             '         |\n";
        cout << "  | .\\ `. `-.                /-.           /          ,\n";
        cout << "  | `._.'    `,_            ;  /         ,'          .\n";
        cout << " .'          /| `-.        . ,'         ,           ,\n";
        cout << " '-.__ __ _,','    '`-..___;-...__   ,.'\\ ____.___.'\n";
        cout << " `\\^--'..'   '-`-^-'\\--    `-^-'`.''\\\\\\\\\\`.,^.`.--' mh\n";
    }

}

void banner(){
    cout <<"                                      ,' \n";
    cout <<"    _.----.        ____         ,''\\   ___    ___     ____\n";
    cout <<"_,-'       `.     |    |  /`.   \\-'    |   \\  /   |   |   \\  |`.\n" ;
    cout <<"\\     __   \\    '-.  | /   `.  ___    |    \\/    |   '-.  \\ |  |\n";
    cout <<" \\.  \\ \\   |  __  |  |/    ,','_  `.  |          | __  |   \\|  |\n";
    cout <<"  \\   \\/   /,' _`.|      ,' / / / /    |          ,' _`.|     |  |\n";
    cout <<"   \\     ,-'/  /  \\    ,'   | \\// ,`. |         /  /   \  |     |\n";
    cout <<"    \\    \\ |  \\_/  |   `-.  \\   `'  /|  |    ||   \_/  | |\    |\n";
    cout <<"     \\    \\ \\     /       `-.`.___,-' |  |\\ /| \\     /  | |   |\n";
    cout <<"      \\    \\ `.__,'|  |`-._    `|      |__| \\/|  `.__,'|  | |   |\n";
    cout <<"       \\_.-'       |__|    `-._ |             '-.|     '-.| |   |\n";
    cout <<"                                `'                            '-._|\n";
}

void batalha(Carta carta1, Carta carta2){
    cout << "---------------------------------------------"<< endl;
    
    int life1 = carta1.defesa ;
    cout << carta1.nome + "/ " + std::to_string(life1) << endl;
    //chamaArt(carta1.nome);

    cout << "-------------------VS---------------------"<< endl;
    this_thread::sleep_for(chrono::milliseconds(2000));

    int life2 = carta2.defesa ;
    cout << carta2.nome + " / " + std::to_string(life2)<< endl;

    //chamaArt(carta2.nome);
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

int contador1= 0;
int main(){
    system("clear");
    banner();
    this_thread::sleep_for(chrono::milliseconds(2000));
    system("clear");
    
    cout << "INICIALIZA: " << endl;
    setup();
    int cartaP1=0;

    while(contador1<4 && ia(player2)!=-1){

    
    while(true){
        mostraDeck(player1);
        mostraDeck(player2);

        if(vez%2==0){
            //PLAYER 1
            cout << "Selecione uma carta: " << endl;
            cin >> cartaP1;
            cout << "Fase de Batalha " << endl;
            bool var = false;
            int real = 0;
            for(int i =0; i<4; i++){
                if(player1[i].num==cartaP1){
                    if(player1[i].condicao==true){
                        var= true;
                        real = i;
                    }
                }
            }
            if(var==true){
                batalha(player1[real], player2[ia(player2)]);

            }else{
                cout << "CARTA INVALIDA, TENTE NOVAMENTE " << endl;
                    break;

            }

            cout << "Press to atk...";
            string name2 = "";
            cin >> name2;


            int random = rand()%2;
            if (random ==0){
                cout << "Voce errou o ataque! Tente Novamente Na PROXIMA" << endl;
                this_thread::sleep_for(chrono::milliseconds(3000));
            }else{
                Carta newCarta = ataque(player1[real], player2[ia(player2)]);
                if(newCarta.defesa==0){
                    newCarta.condicao = false;
                }
            player2[ia(player2)]=newCarta;
            //batalha(player1[real], player2[ia(player2)]);
            }
        }else{
            //PLAYER 2
            cout << "Selecione uma carta: " << endl;
            cin >> cartaP1;
            bool var = false;
                        int real = 0;

            for(int i =0; i<4; i++){
                if(player1[i].num==cartaP1){
                    if(player1[i].condicao==true){
                        var= true;
                        real= i;
                    }
                }
            }
            if(var==true){
                batalha(player2[ia(player2)], player1[real]);

            }else{
                cout << "CARTA INVALIDA, TENTE NOVAMENTE " << endl;

                break;
            }
            cout << "Fase de Batalha " << endl;

            cout << "Press to defnder...";
            string name2 = "";
            cin >> name2;


            int random = rand()%2;
            if (random ==0){
                cout << "Seu Openente errou o ataque! Que Sorte" << endl;
                this_thread::sleep_for(chrono::milliseconds(3000));
            }else{
                Carta newCarta = ataque(player2[ia(player2)], player1[real]);
                if(newCarta.defesa==0){
                    newCarta.condicao = false;
                    contador1+=1;
                }
            player1[real]=newCarta;
            //batalha(player1[real], player2[ia(player2)]);
            }
        }
        vez+=1;

       
        //system("clear");
        
        if(contador1>=4 || ia(player2)==-1){
            break;
        }

        system("clear");
    }
    }
    mostraDeck(player1);
    mostraDeck(player2);
    if(ia(player2)==-1){
            cout << "YOU LOSE"<< endl;
    }else{
            cout << "YOU WIN"<< endl;
    }
    return 0;
}