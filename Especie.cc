/** @file Especie.cc
 * @brief Implementació de la classe Especie */

#include "Especie.hh"

void Especie::definir_k(const int& k_in){
    k = k_in;
}

void Especie::calcular_kmer(){
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

Especie::Especie(const string& gen){
    this->gen = gen;
    calcular_kmer();
}

string Especie::consultar_gen() const{
    return gen;
}

void Especie::distancia(const Especie& esp, const string& id){
    map<string,int>::const_iterator i = kmer.begin(), k = esp.kmer.begin();
    double dalt = 0, baix_1 = 0, baix_2 = 0;
    while (i != kmer.end() and k != esp.kmer.end()) { 
        if (i->first == k->first) {
            dalt += i->second*k->second;
            baix_1 += i->second*i->second;
            baix_2 += k->second*k->second;
            ++i;
            ++k;
        }
        else if (i->first < k->first) {
            baix_1 += i->second*i->second;
            ++i;
        }
        else {
            baix_2 += k->second*k->second;
            ++k;
        }
    }

    while (i != kmer.end()) {
            baix_1 += i->second*i->second;
            ++i;
    } 

    while (k != esp.kmer.end()) { 
            baix_2 += k->second*k->second;
            ++k;
    }
    double den = sqrt(baix_1) * sqrt(baix_2);
    double pi = M_1_PI*acos(dalt/den);
    distancies.insert(make_pair(id,(1-pi)*100));
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
