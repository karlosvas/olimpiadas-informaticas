#include <iostream>
#include <string>
#include <vector>

bool rgpdigits(const std::string &numStr) {
    int coinccidencias = 0;
    for (int i = 1; i < numStr.size(); i++) {
        if (numStr[i] == numStr[i - 1]) {
            coinccidencias++;
        }
    }
    return coinccidencias == 3;
}

std::string ordenarDescendente(std::string numero) {
    std::vector<int> frecuencia(10, 0);
    for (char d : numero) {
        frecuencia[d - '0']++;
    }
    std::string ordenado;
    for (int d = 9; d >= 0; d--) {
        for (int count = 0; count < frecuencia[d]; count++) {
            ordenado.push_back('0' + d);
        }
    }
    return ordenado;
}
std::string ordenarAscendente(std::string numero) {
    std::vector<int> frecuencia(10, 0);
    for (char d : numero) {
        frecuencia[d - '0']++;
    }
    std::string ordenado;
    for (int d = 0; d <= 9; d++) {
        for (int count = 0; count < frecuencia[d]; count++) {
            ordenado.push_back('0' + d);
        }
    }

    return ordenado;
}

int kaprekar(std::string strTried, int CONSTANTE_KAPREKAR) {
    int tried = 0;
    int stepsTried = 0;

   while (tried != CONSTANTE_KAPREKAR & stepsTried < 8) {
    while (strTried.length() < 4) strTried+="0";
    std::string strAsce = ordenarAscendente(strTried);
    std::string strDesc = ordenarDescendente(strTried);

    int ascending = std::stoi(strAsce);
    int descending = std::stoi(strDesc);

    tried = descending - ascending;
    strTried = std::to_string(tried);
    stepsTried += 1;
    }
    return stepsTried;
}




int main() {
    int steps;
    std::cin>>steps;
    const int CONSTANTE_KAPREKAR = 6174;
    for (int i = 0; i < steps; i++) {
        int tried;
        int stepsTried;
        std::string strTried;
        std::cin>>strTried;

        if(rgpdigits(strTried)) {
            stepsTried = 8;
        } else if(std::stoi(strTried) != CONSTANTE_KAPREKAR) {
            stepsTried = kaprekar(strTried, CONSTANTE_KAPREKAR);
        } else stepsTried = 0;

        std::cout<<stepsTried<<'\n';
    };
    return 0;
}
