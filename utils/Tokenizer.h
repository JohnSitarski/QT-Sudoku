#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <vector>
#include <sstream>
/**
* QT Sudoku
* Written By John Sitarski & Sinan Kocadag
* Email Address John Sitarski - sitjy001@mymail.unisa.edu.au / Sinan Kocagag - kocsy006@mymail.unisa.edu.au
*/
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

#endif // TOKENIZER_H
