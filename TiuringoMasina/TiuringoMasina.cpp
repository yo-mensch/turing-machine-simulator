#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "masina.h"

instrukc readFile(std::string filename) {
    std::ifstream fin(filename);
    std::string x;
    int pozic;
    std::vector<struct eilute> kom;
        std::getline(fin, x);
        fin >> pozic;
        std::cout << x << std::endl;
        while (!fin.eof()) {
            eilute a;
            fin >> a.dab_busena >> a.dab_simbolis >> a.nauj_simbolis >> a.kryptis >> a.nauj_busena;
            kom.push_back(a);
        }
        instrukc result;
        result.juosta = x;
        result.pozicija = pozic;
        result.komandos = kom;
        fin.close();
        return result;
}

int main() {
    instrukc kodas = readFile("4.txt");
    judejimas(kodas);
}
