#include <iostream>
#include <algorithm>
#include <string>

int rgpdigits(const std::string &numStr) {
    int coinccidencias = 0;

    for (int i = 1; i < numStr.size(); i++) {
        if (numStr[i] == numStr[i - 1]) {
            coinccidencias++;
        }
    }
    return coinccidencias == 3;
}

std::string intToString(int num) {
    std::string numStr = std::to_string(num);
    while (numStr.length() < 4) {
        numStr = "0" + numStr;
    }
    return numStr;
}

int kaprekar(int num) {
    const int CONSTANTE_KAPREKAR = 6174;
    int pasos = 0;

    while (num != CONSTANTE_KAPREKAR && num != 0) {
        std::string numStr = intToString(num);

        std::sort(numStr.begin(), numStr.end());
        int ascendente = std::stoi(numStr);
        std::reverse(numStr.begin(), numStr.end());
        int descendente = std::stoi(numStr);

        num = descendente - ascendente;
        pasos++;

        if (rgpdigits(numStr)) {
        pasos = 8;
        }
    }
    return pasos;
}


int main() {
    int pasos;
    pasos = kaprekar(3524);
    std::cout << pasos << std::endl;
    pasos = kaprekar(1111);
    std::cout << pasos << std::endl;
    pasos = kaprekar(1121);
    std::cout << pasos << std::endl;
    pasos = kaprekar(6174);
    std::cout << pasos << std::endl;
    pasos = kaprekar(1893);
    std::cout << pasos << std::endl;
    return 0;
}