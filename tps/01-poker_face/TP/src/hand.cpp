#include "hand.hpp"
#include "msgassert.hpp"

Hand::Hand() {
    this->cleanHand();
    this->bestCombination = -1;
}

Hand::~Hand() {
    this->cleanHand();
}

void Hand::sortHand() {
    for (int i = 0; i < this->maxCards; i++) {
        Card *minCard = this->cards[i];
        for (int j = i; j < this->maxCards; j++)
        {
            if (this->cards[j] < minCard)
            {
                minCard = this->cards[j];
            }
        }
        swapCards(this->cards[i], minCard);
    }
}

bool Hand::checkFlush() {
    std::string previousNipe = this->cards[0]->nipe;
    for (auto &&card : this->cards)
    {
        if (card->nipe != previousNipe)
        {
            return false;
        }
        previousNipe = card->nipe;
    }
    return true;
}

void Hand::cleanHand() {
    for (int i = 0; i < this->maxCards; i++)
    {
        delete this->cards[i];
        this->cards[i] = nullptr;
    }

    delete this->highestCard;
    this->highestCard = nullptr;
}