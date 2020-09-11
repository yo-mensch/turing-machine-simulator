#pragma once
#include <iostream>
#include<iomanip>
using namespace std;

struct eilute {
	string dab_busena;
	char dab_simbolis;
	char nauj_simbolis;
	char kryptis;
	string nauj_busena;
};

struct instrukc {
	std::string juosta;
	int pozicija;
	std::vector<struct eilute> komandos;
};

void judejimas(struct instrukc code) {
	code.pozicija--;//masyvuose pozicija 1 maziau
	string busena = "0";//pradine busena
	bool isHalted = false;
	
	while (isHalted==false) {
		for (int i = 0; i < code.komandos.size(); i++) {
			if (busena == code.komandos[i].dab_busena) {
				if (code.juosta[code.pozicija]==code.komandos[i].dab_simbolis) {
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
			}
			else {
				continue;
			}
			system("cls");
			cout << code.juosta << endl;
			if (isHalted) {
				cout << "Halted." << endl;
				break;
			}
		}
	}
	//if (isHalted) cout << " halted." << endl;
}