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
get_num(Carta, Num_),string_concat('|ATK : ', Num_, Num),string_concat(Num,'         | ' , NumF),writeln(NumF).


