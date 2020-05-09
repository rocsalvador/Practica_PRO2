/** @file main.cc
*  @brief Programa que conté el main que consisteix en donar diferents operacions */

#include "Cjt_especies.hh"
#include "Cjt_clusters.hh"

/** \mainpage Especificació de les classes i el main de la pràctica. 
 * \section classes Classes:
 * \subsection esp - Especie
 * \subsection cjt_e - Cjt_especies
 * \subsection cjt_c - Cjt_clusters
*/

int Especie::k;

/** @brief Main amb totes les operacions que requereix la pràctica */
int main(){
    int k;
    cin >> k;
    Especie::definir_k(k);
    
    Cjt_especies especies;
    Cjt_clusters clusters;

    string op;

    while(cin >> op and op != "fin"){
        string gen, id;

        if(op == "crea_especie"){
            cin >> id >> gen;
            cout << "# " << op << " " << id << " " << gen << endl;
            if(not especies.existeix_especie(id)) especies.afegeix_especie(id,gen);
            else cout << "ERROR: La especie " << id << " ya existe." << endl;
            cout << endl;
        }
        else if(op == "obtener_gen"){
            cin >> id;
            cout << "# " << op << " " << id << endl;
            if(especies.existeix_especie(id)) cout << especies.obtenir_gen(id) << endl;
            else cout << "ERROR: La especie " << id << " no existe." << endl;
            cout << endl;
        }
        else if(op == "distancia"){
            string id2;
            cin >> id >> id2;
            cout << "# " << op << " " << id << " " << id2 << endl;
            if(especies.existeix_especie(id) and especies.existeix_especie(id2)){
                if(id != id2) cout << especies.consultar_distancia(id,id2) << endl;
                else cout << 0 << endl;
            } 
            else{
                cout << "ERROR: La especie ";
                if(especies.existeix_especie(id)) cout << id2 << " no existe.";
                else if(especies.existeix_especie(id2)) cout << id << " no existe.";
                else cout << id << " y la especie " << id2 << " no existen.";
                cout << endl;
            }
            cout << endl;
        }
        else if(op == "elimina_especie"){
            cin >> id;
            cout << "# " << op << " " << id << endl;
            if(especies.existeix_especie(id)) especies.eliminar_especie(id);
            else cout << "ERROR: La especie " << id << " no existe." << endl;
            cout << endl;
        }
        else if(op == "existe_especie"){
            cin >> id;
            cout << "# " << op << " " << id << endl;
            if(especies.existeix_especie(id)) cout << "SI" << endl;
            else cout << "NO" << endl;
            cout << endl;
        }
        else if(op == "lee_cjt_especies"){
            cout << "# " << op << endl << endl;
            especies.llegir_cjt_especies();
        }
        else if(op == "imprime_cjt_especies"){
            cout << "# " << op << endl;
            especies.escriure_cjt_especies();
            cout << endl;
        }
        else if(op == "tabla_distancias"){
            cout << "# " << op << endl;
            especies.imprimir_taula_distancies();
            cout << endl;
        }
        else if(op == "inicializa_clusters"){
            cout << "# " << op << endl;
            especies.inicialitza_clusters(clusters);
            clusters.imprimir_taula_distancies();
            cout << endl;
        }
        else if(op == "ejecuta_paso_wpgma"){
            cout << "# " << op << endl;
            if(clusters.num_clusters() > 1){
                clusters.pas_wpgma();
                clusters.imprimir_taula_distancies();
            }
            else cout << "ERROR: num_clusters <= 1" << endl;
            cout << endl;
        }
        else if(op == "imprime_arbol_filogenetico"){
            cout << "# " << op << endl;
            especies.inicialitza_clusters(clusters);
            if(especies.consultar_mida() > 0){
                clusters.imprimeix_arbre_filogenetic();
                cout << endl;
            }
            else cout << "ERROR: El conjunto de clusters es vacio." << endl;
            cout << endl;
        }
        else if(op == "imprime_cluster"){
            cin >> id;
            cout << "# " << op << " " << id << endl;
            if(clusters.existeix_cluster(id)){
                clusters.imprimeix_cluster(id);
                cout << endl;
            }
            else cout << "ERROR: El cluster " << id << " no existe." << endl;
            cout << endl;
        }
    }
}