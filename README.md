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
  
**Instruccions del programa:**

1. lee_cjt_especies
2. crea_especie
3. tabla_distancias
4. elimina_especie
5. distancia
6. obtener_gen
7. existe_especie
8. imprime_cjt_especies
9. inicializa_clusters
10. ejecuta_paso_wpgma
11. imprime_arbol_filogenetico
12. imprime_cluster
13. fin
    
  
