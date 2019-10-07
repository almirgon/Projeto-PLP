module Cards where

data Carta = Carta {
    nome:: String,
    tipo:: String,
    ataque:: Int,
    vida:: Int,
    num:: Int
} deriving (Show)


toString :: Carta -> String
toString Carta{nome=nom, tipo=tip, ataque=ataqu, vida=vid, num=nu}=
    "Nome: " ++ nom ++ "\n" ++
    "Tipo: " ++ tip ++ "\n" ++
    "ATK : " ++ show(ataqu) ++"\n" ++
    "VIDA: " ++ show(vid) ++"\n" ++
    "NUM : " ++ show(nu)