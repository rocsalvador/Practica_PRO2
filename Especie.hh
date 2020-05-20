/** @file Especie.hh
 * @brief Especificació de la classe Especie */

#ifndef ESPECIE
#define ESPECIE

#ifndef NO_DIAGRAM
#include <map>
#include <iostream>
#endif

using namespace std;

/** @class Especie
 * @brief Representa una espècie amb els seus atributs i 
 * les seves operacions.
 * 
 * Una espècie està definida pel seu gen i un identificador.
 * 
 * Conté les operacions per tal de poder generar els kmers
 * a partir del seu gen i així poder calcular les distàncies
 * amb altres espècies. */
class Especie{ 
private:
    ///Gen de l'espècie
    string gen;
    ///Distàncies de l'espècie amb la resta ordenades alfabèticament
    map<string,double> distancies;
    ///kmers
    map<string,int> kmer;
    ///k per crear els kmers
    static int k;

    /** @brief Calcula el kmer de l'espècie a partir del valor k i el gen propi
     * \pre gen.size() >= k
     * \post S'ha creat un map amb tots els kmers del gen amb la seva freqüència corresponent */
    void calcular_kmer();

public:
    
    //Creadores:

    /** @brief Creadora
    * \pre gen.size() >= k
    * \post L'especie s'ha creat amb this->gen = gen i s'ha generat el kmer */
    Especie(const string& gen);

    //Consultores:

    /** @brief Consulta el gen de l'espècie
    * \pre Cert
    * \post Ha retornat el gen de l'espècie */
    string consultar_gen() const;

    /** @brief Consulta la distància amb l'espècie id
    * \pre Id ha d'estar al cjt de distàncies, id != this->id
    * \post Ha retornat la distància amb espècie id*/
    double consultar_distancia(const string& id) const;

    //Lectura/escriptura:

    /** @brief Imprimeix les distàncies amb la resta d'espècies
    * \pre Cert
    * \post S'han imprès totes les distàncies del paràmetre implícit */
    void imprimir_distancies() const;

    //Modificadores:

    /** @brief Calcula la distància amb l'espècie del paràmetre esplícit i l'afegeix al paràmetre implícit
    * \pre Esp té el kmer definit i id != this->id
    * \post S'ha afegit a la taula de distancies la distància amb esp */
    void distancia(const Especie& esp, const string& id);

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
