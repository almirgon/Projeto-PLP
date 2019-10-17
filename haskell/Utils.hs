module Utils where

import qualified Cards as Cards

import System.IO.Unsafe(unsafeDupablePerformIO)
import System.Random
import Data.List.Split

randomPokemon :: Int
randomPokemon = unsafeDupablePerformIO (getStdRandom (randomR (0,33))) 

iniciarCartas :: [Cards.Carta]
iniciarCartas = do
    let file = unsafeDupablePerformIO (readFile "pokemons.txt")
    let lista =  ((map ( splitOn ",") (lines file))) 
    let indexPokemon = randomPokemon
    let lista_cartas = ((map (mapeiaCarta indexPokemon)) (lista))
    return lista_cartas !! 0 

mapeiaCarta :: Int -> [String] -> Cards.Carta
mapeiaCarta indexPokemon lista =
  Cards.Carta{Cards.tipo = (lista) !! 0, 
  Cards.nome = (lista) !! 1,
  Cards.ataque = read((lista) !! 2),
  Cards.vida = read((lista) !! 3),
  Cards.num =  read((lista) !! 4)}