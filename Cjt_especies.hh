/** @file Cjt_especies.hh
*  @brief Especificació de la classe Cjt_especies */

#ifndef CJT_ESPECIES
#define CJT_ESPECIES

#include "Especie.hh"
#include "Cjt_clusters.hh"

/** @class Cjt_especies
 * @brief Representa el conjunt d'espècies i les operacions
 * que permet.
 * 
 * Conté les operacions necessàries per poder gestionar
 * totes les espècies i traspassar tota la informació
 * necessària al conjunt de clusters. 
 * 
 * Les distàncies només s'aguarden a l'espècie amb id més petit. */
class Cjt_especies{
private:
    ///Conjunt d'especies, que no guarden distàncies repetides
    map<string,Especie> inventari;
public:
    //Creadora:
    
    /** @brief Constructora per defecte 
     * \pre Cert
     * \post S'ha creat un cjt d'espècies buit*/
    Cjt_especies();

    //Modificadores:

    /** @brief Crea una especie i l'afegeix al parametre implicit
     * \pre La nova espècie id no està al paràmetre implícit
     * \post La nova especie s'ha afegit al parametre implicit ordenat alfabèticament, s'han afegit a les espècies amb identificador 
     * < id la distància amb espeècie id i a espècie id s'han afegit les distàncies amb espècies amb identificador > id */
    void afegeix_especie(const string& id, const string& gen);

    /** @brief Elimina una especie del parametre implicit
     * \pre L'especie id pertany al parametre implicit
     * \post L'especie id s'ha eliminat del parametre implicit i s'han eliminat les distàncies amb espècie id 
     * de les espècies amb identificador < id*/
    void eliminar_especie(const string& id);


    /** @brief Llegeix n espècies i les afegeix al conjunt
     * \pre Cert
     * \post S'han esborrat les espècies anteriors i s'han afegit les espècies llegides al parametre implícit */
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
     * \post S'ha retornat la distancia entre les dues espècies */
    double consultar_distancia(const string& id_1,const string& id_2) const;
    
    /** @brief Inicialitza el cjt de clusters amb el cjt d'especies actual
     * \pre Cert
     * \post El paràmetre explícit ha quedat igual que la taula de distàncies de les espècies del 
     * paràmetre implícit */
    void inicialitza_clusters(Cjt_clusters& clusters) const;

    /** @brief Retorna el número d'espècies del conjunt
     * \pre Cert
     * \post S'ha retornat el valor de la mida del paràmetre implicit */
    int consultar_mida() const;

    //Lectura/escriptura:

    /** @brief Imprimeix totes les distàncies del conjunt d'espècies
     * \pre Cert
     * \post S'han imprès totes les distàncies pel canal estàndard de sortida */
    void imprimir_taula_distancies() const;

    /** @brief Escriu el conjunt d'espècies
     * \pre Cert
     * \post S'han imprès les espècies pel canal estàndard de sortida*/
    void escriure_cjt_especies() const;
    
    //Destructora:

    /** @brief Constructora per defecte 
     * \pre Cert
     * \post S'ha eliminat el cjt d'espècies*/
    ~Cjt_especies();
};

#endif
