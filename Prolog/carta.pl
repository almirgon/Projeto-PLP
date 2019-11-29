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

get_carta(1, carta('Bulbasaur','GRASS',30,60,1)).
get_carta(2, carta('Venusaur','GRASS',50,80,2)).
get_carta(3, carta('Charmander','FIRE',31,50,3)).
get_carta(4, carta('Charizard','FIRE',70,70,4)).
get_carta(5, carta('Squirtle','WATER',38,56,5)).
get_carta(6, carta('Blastoise','WATER',50,80,6)).
get_carta(7, carta('Caterpie','BUG',30,40,7)).
get_carta(8, carta('Weedle','BUG',35,45,8)).
get_carta(9, carta('Pidgey','FLY',40,45,9)).
get_carta(10, carta('Rattata','NORMAL',25,40,10)).
get_carta(11, carta('Ekans','POISON',37,48,11)).
get_carta(12, carta('Pikachu','ELECTRIC',70,50,12)).
get_carta(13, carta('Nidoran','POISON',27,80,13)).
get_carta(14, carta('Clefairy','FAIRY',35,75,14)).
get_carta(15, carta('Jigglypuff','NORMAL',20,50,15)).
get_carta(16, carta('Zubat','FLY',20,30,16)).
get_carta(17, carta('Oddish','GRASS',35,60,17)).
get_carta(18, carta('Diglett','GROUND',30,20,18)).
get_carta(19, carta('Meowth','NORMAL',36,40,19)).
get_carta(20, carta('Psyduck','WATER',30,64,20)).
get_carta(21, carta('Growlithe','FIRE',60,45,21)).
get_carta(22, carta('Poliwag','WATER',40,60,22)).
get_carta(23, carta('Weepinbell','GRASS',38,50,23)).
get_carta(24, carta('Geodude','GROUND',40,40,24)).
get_carta(25, carta('Magnemite','ELECTRIC',35,30,25)).
get_carta(26, carta('Grimer','POISON',30,70,26)).
get_carta(27, carta('Voltorb','ELECTRIC',20,70,27)).
get_carta(28, carta('Cubone','GROUND',35,50,28)).
get_carta(29, carta('Mew','PSYCHIC',80,67,29)).
get_carta(30, carta('Snorlax','NORMAL',35,99,30)).
get_carta(31, carta('Horsea','WATER',43,30,31)).
get_carta(32, carta('Eevee','NORMAL',70,40,32)).
get_carta(33, carta('Mewtwo','PSYCHIC',99,99,33)).
get_carta(34, carta('Venonat','BUG',30,40,34)).