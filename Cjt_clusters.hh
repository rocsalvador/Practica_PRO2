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
 * La quantitat d'elements de les dues estructures de dades que formen la
 * classe són sempre iguals (els maps, no el BinTree).
 * 
 * Les distàncies només es guarden al cluster amb id més petit. */
class Cjt_clusters{
private:
    typedef map<string,double> dist_cluster;
    /// Map que conté els clusters i la seva distància amb la resta, no s'aguarden distàncies repetides
    map<string,dist_cluster> distancies;
    /// Arbres dels diferents clusters amb la distància amb els seus fills
    map<string,BinTree<pair<string,double>>> colleccio_clusters;

    /** @brief Retorna els ids dels clusters a menor distància
     * \pre Número de clusters > 1
     * \post S'ha retornat els strings dels clusters a menor distància */
    pair<string,string> calcular_min_dist();

    /** @brief 
     * \pre Min_dist conté dos ids del cjt de clusters i número de clusters > 1
     * \post S'ha actualitzat la taula de distàncies afegint el nou cluster amb id = id_1 + id_2 (id1 < id2)
     *  i eliminant els dos antics (id1 i id2) */
    void recalcular_distancia_wpgma(const pair<string,string>& min_dist, map<string,double>& dist_nou_cluster);

public:
    //Creadora:

    /** @brief Constructora per defecte
     * \pre Cert
     * \post S'ha creat un cjt de clusters buit*/
    Cjt_clusters();

    //Modificadores

    /** @brief Executa un pas de l'algorisme WPGMA amb el cjt_clusters actual
    *  \pre clusters.size() > 1
    *  \post El cjt_clusters ha quedat actualitzat amb un nou cluster a la taula distàncies i a l'arbre, eliminant els seus fills
    * dels maps i linkejant al BinTree el cluster pare amb els fills */
    void pas_wpgma();

    /** @brief Imprimeix l'arbre després d'executar tot l'algorisme WPGMA
    *  \pre Cert
    *  \post Els maps s'han quedat amb un sol element (el cluster arrel), l'arbre filogenètic ha quedat completat i
    * aquest s'ha imprès pel canal estàndard de sortida */
    void imprimeix_arbre_filogenetic();

    /** @brief Afegeix una distància amb una altra espècie
     * \pre dist >= 0 i id1 != id2
     * \post S'ha afegit dist al map de distàncies d'id1 la distància amb id2 */
    void afegir_dist_cluster(const string& id1, const string& id2, const double& dist);

    /** @brief Afegeix un nou cluster al cjt de clusters
     * \pre id no present al paràmetre implícit
     * \post S'ha afegit el cluster id al paràmetre implícit */
    void afegir_cluster(const string& id);

    /** @brief Elimina tots els elements de la classe cjt clusters
     * \pre Cert
     * \post El paràmatre implícit ha quedat buit */
    void neteja_clusters();

    //Consultores:

    /** @brief Imprimeix el clúster amb l'id donat
    *  \pre Existeix un clúster amb this->id = id
    *  \post S'ha imprès l'id i estructura arbòrea del clúster pel canal estàndard de sortida */
    void imprimeix_cluster(const string& id) const;

    /** @brief Retorna si existeix un clúser amb id dins del cjt_clusters
    *  \pre Cert
    *  \post Retorna cert si i només si el clúster pertany al paràmetre implícit */
    bool existeix_cluster(const string& id) const;

    /** @brief Imprimeix les distàncies de tots els clústers
    *  \pre Cert
    *  \post S'han imprès totes les distàncies pel canal estàndard de sortida */
    void imprimir_taula_distancies() const;

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
