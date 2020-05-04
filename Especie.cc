#include "Especie.hh"

Especie::Especie(){}

void Especie::definir_k(int k_in){
    k = k_in;
}

Especie::Especie(string gen){
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
    double unio = 0;
    double inters = 0;

    map<string,int>::const_iterator it = kmer.begin();
    map<string,int>::const_iterator it1 = esp.kmer.begin();

    while(it != kmer.end() and it1 != esp.kmer.end()){
        if(it1->first == it->first){
            unio += max(it->second,it1->second);
            inters += min(it->second,it1->second);
            ++it;
            ++it1;
        }
        else if(it->first < it1->first){
            unio += it->second;
            ++it;
        }
        else{
            unio += it1->second;
            ++it1;
        }
    }

    while(it != kmer.end()){
        unio += it->second;
        ++it;
    }

    while(it1 != esp.kmer.end()){
        unio += it1->second;
        ++it1;
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
