#include "word.hpp"

Word::Word() {
    this->word = "";
    this->occurrences = 0;
    this->size = -1;

    this->next = nullptr;
}

Word::Word(std::string word) {
    this->word = word;
    this->occurrences = 1;
    this->size = word.length();

    this->next = nullptr;
}

bool Word::matches(std::string newWord) {
    if (this->word == newWord) {
        this->occurrences++;
        return true;
    }
    
    return false;
}

int Word::getSize() {
    return this->size;
}

std::string Word::getWord() {
    return this->word;
}

bool Word::isLessThan(Word *word, LexOrder *lexOrder) {
    int smallerWordSize = this->getSize() < word->getSize() ? this->getSize() : word->getSize();
    for (int i = 0; i < smallerWordSize; i++) {
        if (this->word[i] == word->word[i]) {
            continue;
        }

        else if ( lexOrder->getLetterValue(this->word[i]) < lexOrder->getLetterValue(word->word[i]) ) {
            return true;
        }
        
        return false;
    }

    return this->getSize() < word->getSize();
}

bool Word::isGreaterThan(Word *word, LexOrder *lexOrder) {
    int smallerWordSize = this->getSize() < word->getSize() ? this->getSize() : word->getSize();
    for (int i = 0; i < smallerWordSize; i++) {
        if (this->word[i] == word->word[i]) {
            continue;
        }

        else if ( lexOrder->getLetterValue(this->word[i]) > lexOrder->getLetterValue(word->word[i]) ) {
            return true;
        }
        
        return false;
    }

    return this->getSize() > word->getSize();
}

std::ostream &operator<<(std::ostream &out, const Word *word) {
    out << word->word << " " << word->occurrences;
    
    return out;
}