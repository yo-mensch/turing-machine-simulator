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
        //std::cout << x << std::endl;
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

void threadExecution(std::string filename, int id) {
    instrukc kodas1 = readFile(filename);
    std::cout<<judejimas(kodas1, id);
}

int main() {
    std::thread t1(threadExecution, "1.txt", 3);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    //std::thread t2(threadExecution, "3.txt", 0);
    //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    //t2.join();
    t1.join();
    
}
