/** @file Cjt_clusters.cc
 * @brief Implementació de la classe Cjt_clusters */

#include "Cjt_clusters.hh"

/** @brief Imprimeix un arbre
 * \pre El double de les fulles és igual a -1
 * \post S'ha imprès l'arbre pel canal estàndard de sortida */
void imprimir_arbre(const BinTree<pair<string,double>>& arbre){
    if(arbre.value().second == -1) cout << "[" << arbre.value().first << "]";
    else{
        cout << "[(" << arbre.value().first << ", " << arbre.value().second << ") ";
        imprimir_arbre(arbre.left());
        imprimir_arbre(arbre.right());
        cout << "]";
    }
}

Cjt_clusters::Cjt_clusters(){}

void Cjt_clusters::afegir_dist_cluster(const string& id1, const string& id2, const double& dist){
    distancies.find(id1)->second.insert(make_pair(id2,dist));
}

void Cjt_clusters::afegir_cluster(const string& id){
    map<string,double> aux;
    distancies.insert(make_pair(id,aux));
    num_fills.insert(make_pair(id,1));
    BinTree<pair<string,double>> arbre(make_pair(id,-1));
    colleccio_clusters.insert(make_pair(id,arbre));
}

pair<string,string> Cjt_clusters::calcular_min_dist() const{
    pair<string,string> min_dist;
    double dist_min = 101;
    for(map<string,dist_cluster>::const_iterator it = distancies.begin(); it != distancies.end(); ++it){
        for(map<string,double>::const_iterator it_1 = it->second.begin(); it_1 != it->second.end(); ++it_1){
            if(it->first != it_1->first and it_1->second < dist_min){
                min_dist.first = it->first;
                min_dist.second = it_1->first;
                dist_min = it_1->second;
            }
        }
    }
    return min_dist;
}

void Cjt_clusters::recalcular_distancia_wpgma(const pair<string,string>& min_dist, map<string,double>& dist_nou_cluster){
    string id_nou_cluster = min_dist.first + min_dist.second;
    double dist_a_b = distancies.find(min_dist.first)->second.find(min_dist.second)->second;
    double fills = num_fills.find(min_dist.first)->second;
    double fills1 = num_fills.find(min_dist.second)->second;
    for(map<string,dist_cluster>::iterator it = distancies.begin(); it != distancies.end(); ++it){
        double dist;
        string id_actual = it->first;
        if(id_actual != min_dist.first and id_actual != min_dist.second){
            //si l'id de l'espècie actual és més petit q l'id del cluster nou més 
            //petit vol dir que conté les distàncies amb els clusters que formen el nou cluster
            if(id_actual < min_dist.first){ 
                dist = fills*it->second.find(min_dist.first)->second;
                dist += fills1*it->second.find(min_dist.second)->second;
                dist /= fills+fills1;
                dist -= ((fills*fills1)/((fills+fills1)*(fills+fills1)))*dist_a_b;
                it->second.erase(min_dist.first);
                it->second.erase(min_dist.second);
                it->second.insert(make_pair(id_nou_cluster,dist));
            }
            //si l'id actual és més petit que l'id més gran del nou cluster vol dir que
            //conté les seves distàncies
            else if(id_actual < min_dist.second){ // 
                auto aux = dist_nou_cluster.find(id_actual);
                dist = aux->second;
                dist += (fills1*it->second.find(min_dist.second)->second)/(fills+fills1);
                dist -= (((fills*fills1)/((fills+fills1)*(fills+fills1)))*dist_a_b);
                aux->second = dist;
                it->second.erase(min_dist.second);
            }
        }
        else if(id_actual == min_dist.first){
            for(auto it1 = it->second.begin(); it1 != it->second.end(); ++it1){
                if(it1->first != min_dist.second){
                    dist = fills*it1->second;
                    dist /= fills+fills1;
                    dist_nou_cluster.insert(make_pair(it1->first,dist));
                }
            }
        }
        else if(id_actual == min_dist.second){
            for(auto it1 = it->second.begin(); it1 != it->second.end(); ++it1){
                auto aux = dist_nou_cluster.find(it1->first);
                dist = aux->second;
                dist += (fills1*it->second.find(it1->first)->second)/(fills+fills1);
                dist -= ((fills*fills1)/((fills+fills1)*(fills+fills1)))*dist_a_b;
                aux->second = dist;
            }
        }
    }
}

void Cjt_clusters::pas_wpgma(){
    pair<string,string> min_dist = calcular_min_dist();

    double dist_fills = distancies.find(min_dist.first)->second.find(min_dist.second)->second/2;
    string id_nou_cluster = min_dist.first + min_dist.second;
    map<string,double> dist_nou_cluster;

    recalcular_distancia_wpgma(min_dist, dist_nou_cluster);

    distancies.erase(min_dist.first);
    distancies.erase(min_dist.second);
    distancies.insert(make_pair(id_nou_cluster,dist_nou_cluster));

    BinTree<pair<string,double>> nou_cluster(make_pair(id_nou_cluster,dist_fills),
        colleccio_clusters.find(min_dist.first)->second, colleccio_clusters.find(min_dist.second)->second);

    colleccio_clusters.erase(min_dist.first);
    colleccio_clusters.erase(min_dist.second);
    colleccio_clusters.insert(make_pair(id_nou_cluster,nou_cluster));
    int numero_fills = num_fills.find(min_dist.first)->second + num_fills.find(min_dist.second)->second;
    num_fills.insert(make_pair(id_nou_cluster,numero_fills));
}

void Cjt_clusters::neteja_clusters(){
    distancies.clear();
    colleccio_clusters.clear();
}

void Cjt_clusters::imprimeix_arbre_filogenetic(){
    while(distancies.size() > 1){
        pas_wpgma();
    }
    imprimir_arbre(colleccio_clusters.begin()->second);
}

void Cjt_clusters::imprimeix_cluster(const string& id) const{
    imprimir_arbre(colleccio_clusters.find(id)->second);
}

bool Cjt_clusters::existeix_cluster(const string& id) const{
    return colleccio_clusters.find(id) != colleccio_clusters.end();
}

void Cjt_clusters::imprimir_taula_distancies() const{
    for(map<string,dist_cluster>::const_iterator it = distancies.begin(); it != distancies.end(); ++it){
        cout << it->first << ":";
        for(map<string,double>::const_iterator it_1 = it->second.begin(); it_1 != it->second.end(); ++it_1){
            cout << " " << it_1->first << " (" << it_1->second << ")";
        }
        cout << endl;
    }
}

int Cjt_clusters::num_clusters() const{
    return distancies.size();
}

Cjt_clusters::~Cjt_clusters(){}
