#pragma once
#include <iostream>
#include<iomanip>
#include <mutex>
#include <Windows.h>
//using namespace std;

std::mutex mtx;

struct eilute {
	std::string dab_busena;
	char dab_simbolis;
	char nauj_simbolis;
	char kryptis;
	std::string nauj_busena;
};

struct instrukc {
	std::string juosta;
	int pozicija;
	std::vector<struct eilute> komandos;
};

void cls(int id) {
	HANDLE hOut;
	COORD Position;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	Position.X = 0;
	Position.Y = id;
	SetConsoleCursorPosition(hOut, Position);
}

void judejimas(struct instrukc code, int id) {
	code.pozicija--;//masyvuose pozicija 1 maziau
	std::string busena = "0";//pradine busena
	bool isHalted = false;
	bool isChanged = false;
	while (isHalted==false) {
		for (int i = 0; i < code.komandos.size(); i++) {
			if (busena == code.komandos[i].dab_busena) {
				if (code.juosta[code.pozicija]==code.komandos[i].dab_simbolis) {
					if (code.komandos[i].dab_simbolis != code.komandos[i].nauj_simbolis) isChanged = true;
					code.juosta[code.pozicija] = code.komandos[i].nauj_simbolis;
					busena = code.komandos[i].nauj_busena;

					if (code.komandos[i].kryptis == 'L' && code.pozicija > 0) {
						code.pozicija--;
					}
					else if (code.komandos[i].kryptis == 'R' && code.pozicija < code.juosta.size() - 1) {
						code.pozicija++;
					}
					else {
						isHalted = true;
					}
				}
				else{
					continue;
				}
				if (isChanged) {
					mtx.lock();
					cls(id);
					std::cout << code.juosta;
					isChanged = false;
					mtx.unlock();
				}
			}
			else {
				continue;
			}
		}
	}
	//return code.juosta;
}