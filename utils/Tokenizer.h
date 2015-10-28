#ifndef TOKENIZER_H
#define TOKENIZER_H

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

#endif // TOKENIZER_H
