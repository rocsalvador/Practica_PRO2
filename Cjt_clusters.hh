/** @file Cjt_clusters.hh
*  @brief Especificació de la classe cjt_clusters */

#ifndef CJT_CLUSTERS
#define CJT_CLUSTERS

#include "Cjt_especies.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <map>
#include <iostream>
#endif

using namespace std;

typedef map<string,double> dist_cluster;

class Cjt_clusters{
private:
    /// Map que conté els clusters i la seva distància amb la resta
    map<string,dist_cluster> distancies;
    /// Arbres dels diferents clusters amb la distància amb els seus fills
    map<string,BinTree<pair<string,double>>> colleccio_clusters;

public:
    //Creadora:
    
    /** @brief Constructora per defecte 
     * \pre Cert
     * \post S'ha creat un cjt de clusters buit*/
    Cjt_clusters();

    //Modificadores
    
    /** @brief Inicialitza els clusters a partir de les espècies actuals
    *  \pre Cert
    *  \post El cjt_clusters ha quedat creat a partir del cjt_especies*/
    void inicialitza_clusters(const Cjt_especies& esp);

    /** @brief Executa un pas de l'algorisme WPGMA amb el cjt_clusters actual
    *  \pre Cert
    *  \post El cjt_clusters ha quedat actualitzat si la mida de cjt de distàncies > 1*/
    void pas_wpgma();

    /** @brief Imprimeix l'arbre després d'executar tot l'algorisme WPGMA
    *  \pre Cert
    *  \post S'ha imprès l'arbre pel canal de sortida estàndard i el cjt_clusters queda actualitzat */
    void imprimeix_arbre_filogenetic();
    
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

    //Destructora:
    
    /** @brief Desctructora per defecte 
     * \pre Cert
     * \post S'ha eliminat el cjt de clusters*/
    ~Cjt_clusters();
};

#endif
