/** @file Especie.hh
 * @brief Especificació de la classe Especie */

#ifndef ESPECIE
#define ESPECIE

#ifndef NO_DIAGRAM
#include <map>
#include <iostream>
#endif

using namespace std;

class Especie{ 
private:
    ///Gen de l'espècie
    string gen;
    ///Distàncies de les espècies amb la resta
    map<string,double> distancies;
    ///kmer
    map<string,int> kmer;
    ///k per crear els kmers
    static int k;
    
public:
    
    //Creadores:

    /** @brief Creadora per defecte 
     * \pre Cert
     * \post S'ha creat una espècie buida */
    Especie();

    /** @brief Creadora
    * \pre gen.size() >= k
    * \post L'especie s'ha creat amb this->gen = gen i amb el kmer amb el parametre k */
    Especie(string gen);

    //Consultores:

    /** @brief Consulta el gen de l'espècie
    * \pre Cert
    * \post Ha retornat el gen de l'espècie */
    string consultar_gen() const;

    /** @brief Consulta la distància amb l'espècie id
    * \pre Id ha d'estar al cjt de distàncies, id != this->id
    * \post Ha retornat la distància amb espècie id*/
    double consultar_distancia(const string& id) const;

    /** @brief Imprimeix les distàncies amb la resta d'espècies
    * \pre Cert
    * \post S'han imprès totes les distàncies del paràmetre implícit */
    void imprimir_distancies() const;

    //Modificadores:

    /** @brief Calcula la distància amb l'espècie del paràmetre
    * \pre Esp té el gen definit
    * \post S'ha afegit a la taula de distancies la distancia amb esp */
    void distancia(const Especie& esp, string id);

    /** @brief Elimina la distància amb l'espècie id
    * \pre Id ha d'estar al cjt de distàncies
    * \post S'ha eliminat la distància amb l'espècie */
    void eliminar_esp_dist(const string& id);

    /** @brief Defineix el valor de k
     * \pre k > 0
     * \post Static k = k; */
    static void definir_k(int k);

    //Destructora per defecte:

    /** @brief Destructora per defecte 
     * \pre Cert
     * \post S'ha eliminat l'espècie */
    ~Especie();
};

#endif
