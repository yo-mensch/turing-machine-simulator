#include <fstream>
#include <iostream>
#include <string>
#include <thread>
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

void threadExecution(std::string filename) {
    std::cout << filename << std::endl;
    instrukc kodas1 = readFile(filename);
    judejimas(kodas1);
    std::cout <<kodas1.juosta<< endl;
}

int main() {
    //reikia kad:
    // 1) nemirguliuotu ekraniuks
    // 2) stabilioj pozicijoj butu visos juostos
    // 3) pahaltinus neissitrintu galutinio rezultato eilute
    thread t1(threadExecution, "1.txt");
    this_thread::sleep_for(chrono::milliseconds(500));
    thread t3(threadExecution, "3.txt");
    this_thread::sleep_for(chrono::milliseconds(500));
    t1.join();
    t3.join();
}
