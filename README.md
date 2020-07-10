# Practica Primavera 2020

*Per accedir al codi de l'examen de la pràctica simplement heu de canviar a la branca examen.*

## Enunciat de la pràctica
Volem crear un programa per tal de gestionar un conjunt d'espècies, amb dos atributs identificador i gen, calcular les distàncies
entre espècies i generar un arbre filogenètic mitjançant l'algorisme WPGMA.

## Com executar el codi
### Linux
**Requisits:**

- Make, instal·lable executant `sudo apt install make` a la terminal
  
- G++, instal·lable executant `sudo apt install g++` a la terminal
  
**Execució:**

Obrir la terminal a la carpeta on tinguem els fitxers:
  
1. `make` , per compilar i crear el fitxer executable
  
2. `./program.exe`, per executar el programa

*Opcional per provar el programa:*
  
    ./program.exe < ./Samples/sample1.inp > sample.out
    
    diff -b ./Samples/sample1.cor sample.out
    
Si no ens surt cap missatge d'error el programa és correcte
  
**Instruccions del programa:**

*El primer valor que s'introdueix és k*

1. *lee_cjt_especies*

        Input: n (número d'espècies a introduir), seguit de l'id i el gen de cada espècie

2. *crea_especie*
    
        Input: id i gen de l'espècie
    
3. *tabla_distancias*

        Output: Distàncies entre espècies del cjt d'espècies
    
4. *elimina_especie*

        Input: id de l'espècie
  
5. *distancia*

        Input: id de les dues espècies
    
        Output: Distància entre les dues espècies
  
6. *obtener_gen*

        Input: id de l'espècie
    
        Output: Gen de l'epècie
    
7. *existe_especie*

        Input: id de l'espècie
    
        Output: SI si existeix, NO si no
    
8. *imprime_cjt_especies*

        Output: Cjt d'ids de les espècies i el seu respectiu gen

9. *inicializa_clusters*

        Output: Cjt d'ids dels clusters i les seves respectives distàncies
    
10. *ejecuta_paso_wpgma*

        Output: Cjt d'ids dels clusters i les seves respectives distàncies
    
11. *imprime_arbol_filogenetico*

        Output: Arbre dels clusters i les distàncies amb els fills
     
12. *imprime_cluster*

        Input: id del cluster

        Output: Arbre del cluster i les distàncies amb els seus fills

13. *fin*
    
  
