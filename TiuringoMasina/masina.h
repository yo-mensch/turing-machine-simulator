#pragma once
#include <iostream>
#include<iomanip>
using namespace std;

void judejimas(instrukc code) {
	int position = code.pozicija--;
	string busena = "0";
	int index = 0;
	while (position >= 0 || position <= code.juosta.size()) {
			for (int i = 0; i < code.komandos.size(); i++) {
				string simb = to_string(code.juosta.at(position));

				if (busena == code.komandos[i].dab_busena) {
					//something
				}

				if (code.komandos[i].dab_simbolis == simb) {
					simb = code.komandos[i].nauj_simbolis;
					if (code.komandos[i].kryptis == "L") {
						position--;
						busena = code.komandos[i].nauj_busena;
						if (busena == "H" || busena == "X") break;
					}
					if (code.komandos[i].kryptis == "R") {
						position++;
						busena = code.komandos[i].nauj_busena;
						if (busena == "H" || busena == "X") break;
					}
				}
			}
	}
}