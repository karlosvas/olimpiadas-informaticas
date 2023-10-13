#include <iostream>
#include <string>

int countVocales(const std::string& message) {
    int contador = 0;
    std::string vocales = "aeiouAEIOU";
    for (char c : message) {
        if (vocales.find(c) != std::string::npos) {
            contador++;
        }
    }
    return contador;
}

int main() {
    std::string message;

    while (std::getline(std::cin, message)) {

        std::string res;
        int code = message[0] - 'p';
        for (size_t i = 0; i < message.length(); i++) {
            char c = message[i];
            if (isalpha(c)) {
                char base = islower(c) ? 'a' : 'A';
                char decrypted = base + (c - base - code + 26) % 26;
                res += decrypted;
            } else {
                res += c;
            }
        }

        res = res.substr(1);
        if (res == "FIN") {
            break;
        }

        int vocal = countVocales(res);
        std::cout << vocal << "\n";
    }

    return 0;
}
