//
// Created by John on 10/14/2015.
//

#include "Tokenizer.h"


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
