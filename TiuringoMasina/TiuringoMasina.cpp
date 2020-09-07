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

void readFile(std::string filename) {
    std::ifstream fin(filename);
    std::string juosta;
    int num;
    std::vector<struct eilute> komandos;
    if (fin.good()) {
        std::getline(fin, juosta);
        fin >> num;
        std::cout << juosta << std::endl;
        //int i = 0;
        while (!fin.eof()) {
            eilute a;
            fin >> a.dab_busena >> a.dab_simbolis >> a.nauj_simbolis >> a.kryptis >> a.nauj_busena;
            komandos.push_back(a);
            std::cout << a.dab_busena << " " << a.dab_simbolis << " " << a.nauj_simbolis << " " << a.kryptis << " " << a.nauj_busena << std::endl;
        }
        fin.close();
    }
}

int main() {
    readFile("4.txt");
}
