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
    judejimas(kodas1, id);
}

void userFriendly() {
    int threadCount;
    std::cout << "This is a turing machine simulator" << std::endl;
    std::cout << "How many text files do you want to execute [1-4]?";
    std::cin >> threadCount;
    std::vector<std::thread> threads;
    int placement = 3;
    for (int i = 0; i < threadCount; i++) {
        int fileNumber = i + 1;
        std::string filename = std::to_string(fileNumber) + ".txt";
        threads.push_back(std::thread(threadExecution, filename, placement));
        placement += 2;
    }
    for (auto& thread : threads) {
        thread.join();
    }
}

int main() {
    userFriendly();
}
