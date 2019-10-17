module Cards where

    data Carta = Carta {
        
        tipo:: String,
        nome:: String,
        ataque:: Int,
        vida:: Int,
        num:: Int
    
    } deriving (Show)
    
    toString :: Carta -> String
    toString (Carta {tipo=tip, nome=nom, ataque=ataqu, vida=vid, num=n})=
        "|Nome: " ++ nom ++ " | \n" ++
        "|Tipo: " ++ tip ++ " | \n" ++
        "|ATK : " ++ show(ataqu) ++" | \n" ++
        "|VIDA: " ++ show(vid) ++" | \n" ++
        "|NUM : " ++ show(n) ++" | "