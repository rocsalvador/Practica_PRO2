    #include "Cjt_clusters.hh"

    void imprimir_arbre(const BinTree<pair<string,double>>& arbre){
        if(arbre.empty()) cout << "buit" << endl;
        else{
            cout << arbre.value().first << " " << arbre.value().second << endl;
            imprimir_arbre(arbre.left());
            imprimir_arbre(arbre.right());
        }
    }

    Cjt_clusters::Cjt_clusters(){}

    void Cjt_clusters::afegir_cluster(string id1, string id2, double dist){
        if(distancies.find(id1) != distancies.end()){
            if(id1 != id2) distancies.find(id1)->second.insert(make_pair(id2,dist));
            else distancies.find(id1)->second.insert(make_pair(id2,0));
        }
        else{
            map<string,double> aux;
            distancies.insert(make_pair(id1,aux));

            if(id1 != id2) distancies.find(id1)->second.insert(make_pair(id2,dist));
            else distancies.find(id1)->second.insert(make_pair(id2,0));

            BinTree<pair<string,double>> arbre(make_pair(id1,-1));
            colleccio_clusters.insert(make_pair(id1,arbre));
        }
    }

    void Cjt_clusters::pas_wpgma(){
        if(distancies.size() > 1){
            pair<string,string> min_dist;
            double dist_min = 101;
            for(map<string,dist_cluster>::iterator it = distancies.begin(); it != distancies.end(); ++it){
                for(map<string,double>::iterator it_1 = it->second.begin(); it_1 != it->second.end(); ++it_1){
                    if(it->first != it_1->first and it_1->second < dist_min){
                        min_dist.first = it->first;
                        min_dist.second = it_1->first;
                        dist_min = it_1->second;
                    }
                }
            }

            double dist_fills = distancies.find(min_dist.first)->second.find(min_dist.second)->second/2;
            string id_nou_cluster = min_dist.first + min_dist.second;
            map<string,double> dist_nou_cluster;

            for(map<string,dist_cluster>::iterator it = distancies.begin(); it != distancies.end(); ++it){
                if(it->first != min_dist.first and it->first != min_dist.second){
                    double mitjana = (it->second.find(min_dist.first)->second + it->second.find(min_dist.second)->second)/2;
                    dist_nou_cluster.insert(make_pair(it->first,mitjana));
                    it->second.erase(min_dist.first);
                    it->second.erase(min_dist.second);
                    it->second.insert(make_pair(min_dist.first + min_dist.second,mitjana));
                }
                else{
                    if(it->first == min_dist.first){
                        distancies.erase(it->first);
                    }
                    else if(it->first == min_dist.second){
                        distancies.erase(it->first);
                    }
                }
            }

            dist_nou_cluster.insert(make_pair(id_nou_cluster,0));
            distancies.insert(make_pair(id_nou_cluster,dist_nou_cluster));

            BinTree<pair<string,double>> nou_cluster(make_pair(id_nou_cluster,dist_fills), 
                colleccio_clusters.find(min_dist.first)->second, colleccio_clusters.find(min_dist.second)->second);

            colleccio_clusters.insert(make_pair(id_nou_cluster,nou_cluster));
        }
    }

    void Cjt_clusters::neteja_clusters(){
        distancies.clear();
        colleccio_clusters.clear();
    }

    void Cjt_clusters::imprimeix_arbre_filogenetic(){
        while(distancies.size() > 1){
            pas_wpgma();
        }

        imprimir_arbre(colleccio_clusters.find(distancies.begin()->first)->second);
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
                cout << " " << it_1->first << "(" << it_1->second << ")";
            }
            cout << endl;
        }
    }

    Cjt_clusters::~Cjt_clusters(){

    }
