#include "Tokenizer.h"

/**
* QT Sudoku
* Written By John Sitarski & Sinan Kocadag
* Email Address John Sitarski - sitjy001@mymail.unisa.edu.au / Sinan Kocagag - kocsy006@mymail.unisa.edu.au
*/
Tokenizer::Tokenizer(std::string string, char splitToken) {
    this->string = string;
    this->splitToken = splitToken;
}

 std::string Tokenizer:: getString() {
    return this->string;
}

char Tokenizer::getToken() {
    return this->splitToken;
}

std::vector<std::string> Tokenizer::getTokens() {
    std::vector<std::string> vector;
    std::stringstream stream;
    stream.str(this->string);
    while (std::getline(stream, string, this->splitToken)) {
        vector.push_back(string);
    }
    return vector;
}
