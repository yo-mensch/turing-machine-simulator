#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "masina.h"

struct eilute {
    string dab_busena;
    string dab_simbolis;
    string nauj_simbolis;
    string kryptis;
    string nauj_busena;
};

struct instrukc {
    std::string juosta;
    int pozicija;
    std::vector<struct eilute> komandos;
};

instrukc readFile(std::string filename) {
    std::ifstream fin(filename);
    std::string x;
    int pozic;
    std::vector<struct eilute> kom;

        std::getline(fin, x);
        fin >> pozic;
        //std::cout << x << std::endl;
        while (!fin.eof()) {
            eilute a;
            fin >> a.dab_busena >> a.dab_simbolis >> a.nauj_simbolis >> a.kryptis >> a.nauj_busena;
            kom.push_back(a);
            //std::cout << a.dab_busena << " " << a.dab_simbolis << " " << a.nauj_simbolis << " " << a.kryptis << " " << a.nauj_busena << std::endl;
        }
        instrukc result;
        result.juosta = x;
        result.pozicija = pozic;
        result.komandos = kom;
        fin.close();
        return result;
}

int main() {
    instrukc kodas = readFile("1.txt");
    judejimas(kodas);
}
