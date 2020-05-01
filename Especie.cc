#include "Especie.hh"

Especie::Especie(){}

Especie::Especie(string gen, int k){
    this->gen = gen;
    for(int i = 0; i < gen.size() - (k-1); ++i){
        string part1="";
        for(int j = i; j < k + i; ++j){
            part1.push_back(gen[j]);
        }
        if(kmer.find(part1) == kmer.end()){
            kmer.insert(make_pair(part1,1));
        }
        else{
            ++kmer.find(part1)->second;
        }
    }
}
string Especie::consultar_gen() const{
    return gen;
}

void Especie::distancia(const Especie& esp, string id){
    map<string,int> kmer1 = esp.kmer;
    double unio = 0;
    double inters = 0;

    for(map<string,int>::const_iterator it_1 = kmer.begin(); it_1 != kmer.end(); ++it_1){
        string id = it_1->first;
        int num_kmer = it_1->second;
        if(kmer1.find(id) != kmer1.end()){
            int num_kmer1 = kmer1.find(id)->second;
            unio += max(num_kmer,num_kmer1);
            inters += min(num_kmer,num_kmer1);
            kmer1.erase(id);
        }
        else unio += num_kmer;
    }

    for(map<string,int>::const_iterator it_1 = kmer1.begin(); it_1 != kmer1.end(); ++it_1){
        unio += it_1->second;
    }

    double dist = (1 - (inters/unio))*100;

    distancies.insert(make_pair(id,dist));
}

void Especie::imprimir_distancies() const{
    for(map<string,double>::const_iterator it = distancies.begin(); it != distancies.end(); ++it){
        cout << " " << it->first << " (" << it->second << ")";
    }
}

void Especie::eliminar_esp_dist(const string& id){
    distancies.erase(id);
}

double Especie::consultar_distancia(const string& id) const{
    return distancies.find(id)->second;
}

Especie::~Especie(){}
