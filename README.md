# Practica Primavera 2020

## Enunciat de la pràctica
Volem crear un programa per tal de gestionar un conjunt d'espècies, amb dos atributs identificador i gen, calcular les distàncies
entre espècies i generar un arbre filogenètic.

## Com executar el codi
### Linux
**Requisits:**

- Make, instal·lable executant `sudo apt install make` a la terminal
  
- G++, instal·lable executant `sudo apt install g++` a la terminal
  
**Execució**

Obrir la terminal a la carpeta on tinguem els fitxers:
  
1. `make` , per compilar i crear el fitxer executable
  
2. `./program.exe`, per executar el programa

*Opcional per provar el programa:*
  
    ./program.exe < sample1.inp > sample.out
    
    diff -b sample1.cor sample.out
    
Si no ens surt cap missatge d'error el programa és correcte
    
//A L'EXECUTAR EL PROGRAMA EL PRIMER VALOR QUE S'INTRODUEIX ÉS K\\
  
**Instruccions del programa:**

1. lee_cjt_especies , seguit del número d'espècies que volem introduir
    
  
