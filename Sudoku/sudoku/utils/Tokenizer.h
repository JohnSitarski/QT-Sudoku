//
// Created by John on 10/14/2015.
//

#ifndef SUDOKU_TOKENIZER_H
#define SUDOKU_TOKENIZER_H

#include <string>
#include <vector>
#include <sstream>

class Tokenizer {

private:

    std::string string;
    char splitToken;
public:
    Tokenizer(std::string string, char splitToken);

    std::vector<std::string> getTokens();

    std::string getString();

    char getToken();


};

#endif //SUDOKU_TOKENIZER_H
