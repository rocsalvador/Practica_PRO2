/** @file Cjt_clusters.hh
*  @brief Especificació de la classe Cjt_clusters */

#ifndef CJT_CLUSTERS
#define CJT_CLUSTERS

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <map>
#include <iostream>
#endif

using namespace std;

/** @class Cjt_clusters
 * @brief Representa el conjunt de clusters i les operacions
 * que aquests permeten.
 * 
 * Cada cluster està definit per un identificador i les seves distàncies.
 * 
 * Conté totes les operacions necessàries perquè es pugui executar
 * l'algorisme WPGMA a partir d'un conjunt d'espècies i generar 
 * l'arbre filogenètic.
 * 
 * Les dades de les estructures de dades del conjunt sempre estan ordenades alfabèticament
 * 
 * Les distàncies entre dos clusters només es guarden al cluster amb id més petit. */
class Cjt_clusters{
private:
    typedef map<string,double> dist_cluster;
    /// Map que conté els clusters i la seva distància amb la resta, no s'aguarden distàncies repetides
    map<string,dist_cluster> distancies;
    /// Arbres dels diferents clusters amb la distància amb els seus fills
    map<string,BinTree<pair<string,double>>> colleccio_clusters;

    map<string,int> num_fills;

    /** @brief Retorna els ids dels clusters a menor distància
     * \pre Número de clusters > 1
     * \post S'ha retornat els strings dels clusters a menor distància ordenats alfabèticament */
    pair<string,string> calcular_min_dist() const;

    /** @brief Actualitza el conjunt de clusters a lpexecutar el pas wpgma
     * \pre Min_dist conté dos ids del cjt de clusters ordenats alfabèticament i distancies.size() > 1
     * \post S'ha actualitzat la taula de distàncies afegint el nou cluster amb id = id_1 + id_2 (id1 < id2)
     *  afegit les distàncies amb aquest als clusters amb id < id_nou_cluster i al nou cluster les distàncies
     * amb id > id_nou_cluster*/
    void recalcular_distancia_wpgma(const pair<string,string>& min_dist, map<string,double>& dist_nou_cluster);

public:
    //Creadora:

    /** @brief Constructora per defecte
     * \pre Cert
     * \post S'ha creat un cjt de clusters buit*/
    Cjt_clusters();

    //Modificadores

    /** @brief Executa un pas de l'algorisme WPGMA amb el cjt_clusters actual
    *  \pre distancies.size() > 1
    *  \post El cjt_clusters ha quedat actualitzat amb un nou cluster a la taula distàncies i a l'arbre, també s'han eliminat
    * els fills del nou cluster de la taula de distàncies i la col·lecció. A la taula de distàncies: s'han eliminat les distàncies dels 
    * fills que hi havia a la taula i s'han afegit les distàncies del nou cluster als clusters amb id < id_nou_cluster i al 
    * nou_cluster els clusters amb id > id_nou_cluster.*/
    void pas_wpgma();

    /** @brief Imprimeix l'arbre després d'executar tot l'algorisme WPGMA
    *  \pre Cert
    *  \post La taula de distàncies i la col·lecció s'han quedat amb un sol element (el cluster arrel), l'arbre filogenètic ha 
    * quedat completat i aquest s'ha imprès pel canal estàndard de sortida */
    void imprimeix_arbre_filogenetic();

    /** @brief Afegeix una distància amb una altra espècie
     * \pre dist >= 0 i id1 != id2
     * \post S'ha afegit (ordenat alfabèticament) dist a la taula de distàncies d'id1 la distància amb id2 */
    void afegir_dist_cluster(const string& id1, const string& id2, const double& dist);

    /** @brief Afegeix un nou cluster al cjt de clusters
     * \pre id no present al paràmetre implícit
     * \post S'ha afegit (ordenat alfabèticament) el cluster id a l'arbre i a la taula de distàncies */
    void afegir_cluster(const string& id);

    /** @brief Elimina tots els elements de la classe cjt clusters
     * \pre Cert
     * \post El paràmatre implícit ha quedat buit */
    void neteja_clusters();

    //Lectura/escriptura:

    /** @brief Imprimeix el clúster amb l'id donat
    *  \pre Existeix un clúster amb this->id = id
    *  \post S'ha imprès l'id i estructura arbòrea del clúster pel canal estàndard de sortida */
    void imprimeix_cluster(const string& id) const;

    /** @brief Imprimeix les distàncies de tots els clústers
    *  \pre Cert
    *  \post S'han imprès totes les distàncies pel canal estàndard de sortida */
    void imprimir_taula_distancies() const;

    //Consultores:

    /** @brief Retorna si existeix un clúser amb id dins del cjt_clusters
    *  \pre Cert
    *  \post Retorna cert si i només si el clúster pertany al paràmetre implícit */
    bool existeix_cluster(const string& id) const;

    /** @brief Retorna el numero de clusters de la taula de distàncies
     * \pre Cert
     * \post S'ha retornat la mida del paràmetre implícit */
    int num_clusters() const;

    //Destructora:

    /** @brief Desctructora per defecte
     * \pre Cert
     * \post S'ha eliminat el cjt de clusters*/
    ~Cjt_clusters();
};

#endif
