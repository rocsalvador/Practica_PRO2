/** @file Cjt_especies.hh
*  @brief Especificació de la classe cjt_especies */

#ifndef CJT_ESPECIES
#define CJT_ESPECIES

#include "Especie.hh"

using namespace std;

class Cjt_especies{
private:
    ///Conjunt d'especies
    map<string,Especie> inventari;
    
public:
    //Creadora:
    
    /** @brief Constructora per defecte 
     * \pre Cert
     * \post S'ha creat un cjt d'espècies buit*/
    Cjt_especies();

    //Modificadores:

    /** @brief Crea una especie i l'afegeix al parametre implicit
     * \pre La nova espècie no està al paràmetre implícit
     * \post La nova especie s'ha afegit al parametre implicit i les distancies de la nova espècie amb la resta s'han actualitzat */
    void afegeix_especie(const string& id, const string& gen);

    /** @brief Elimina una especie del parametre implicit
     * \pre L'especie pertany al parametre implicit
     * \post L'especie s'ha eliminat del parametre implicit i s'han actualitzat les distàncies de la resta d'espècies del conjunt*/
    void eliminar_especie(const string& id);


    /** @brief Llegeix n espècies i les afegeix al conjunt
     * \pre n>=0
     * \post S'han afegit les espècies llegides pel canal estàndard d'entrada al parametre implícit */
    void llegir_cjt_especies();

    //Consultores:

    /** @brief Retorna el gen de l'espècie id
     * \pre L'element id pertany al parametre implicit
     * \post S'ha retornat el gen de l'identificador*/
    string obtenir_gen(const string& id) const;

    /** @brief Retorna cert si l'espècie és al cjt d'espècies
     * \pre Cert
     * \post S'ha retornat cert si l'especie pertany al parametre implicit sinó fals */
    bool existeix_especie(const string& id) const;

    /** @brief Calcula la distancia entre dues espècies
     * \pre Els paràmetres pertanyen al paràmetre implicit
     * \post S'ha retornat la distancia entre les dues especies */
    double consultar_distancia(const string& id_1,const string& id_2) const;

    /** @brief Imprimeix totes les distàncies del conjunt d'espècies
     * \pre Cert
     * \post S'han imprès totes les distàncies pel canal estàndard de sortida */
    void imprimir_taula_distancies() const;

    /** @brief Escriu el conjunt d'espècies
     * \pre Cert
     * \post S'han imprès les espècies pel canal estàndard de sortida*/
    void escriure_cjt_especies() const;

    /** @brief Retorna el numero d'espècies del conjunt
     * \pre Cert
     * \post S'ha retornat el valor de la mida del paràmetre implicit */
    int consultar_mida() const;
    
    //Destructora:

    /** @brief Constructora per defecte 
     * \pre Cert
     * \post S'ha eliminat el cjt d'espècies*/
    ~Cjt_especies();
};

#endif
