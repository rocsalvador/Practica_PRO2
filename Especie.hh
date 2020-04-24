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
public:
    
    //Creadores:

    /** @brief Creadora per defecte 
     * \pre Cert
     * \post S'ha creat una espècie buida */
    Especie();

    /** @brief Creadora
    * \pre Cert
    * \post L'especie s'ha creat amb this->gen = gen i amb el kmer amb el parametre k */
    Especie(string gen, int k);

    //Consultores:

    /** @brief Consulta el gen de l'espècie
    * \pre Cert
    * \post Ha retornat el gen de l'espècie */
    string consultar_gen() const;

    /** @brief Calcula la distància amb l'espècie del paràmetre
    * \pre ert
    * \post S'ha retornat el valor de la distància */
    double distancia(const Especie& esp) const;

    /** @brief Consulta la distància amb l'espècie id
    * \pre Id ha d'estar al cjt de distàncies
    * \post Ha retornat la distància amb espècie id*/
    double consultar_distancia(const string& id) const;

    void imprimir_distancies() const;

    //Modificadores:

    /** @brief Afegeix o modifica una distància amb una altra espècie
    * \pre Cert
    * \post S'ha afegit l'id amb la distància corresponent al cjt de distàncies */
    void afegir_distancia(const string& id, const double& dist);

    /** @brief Elimina la distància amb l'espècie id
    * \pre Id ha d'estar al cjt de distàncies
    * \post S'ha eliminat la distància amb l'espècie */
    void eliminar_esp_dist(const string& id);

    //Destructora per defecte:

    /** @brief Destructora per defecte 
     * \pre Cert
     * \post S'ha eliminat l'espècie */
    ~Especie();
};

#endif
