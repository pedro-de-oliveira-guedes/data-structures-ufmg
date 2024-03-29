#include "hand.hpp"
#include "msgassert.hpp"

#define swapCards(A, B) \
    {                      \
        Card *aux = A;       \
        A = B;             \
        B = aux;           \
    }

Hand::Hand() {
    this->cleanHand();
    this->bestCombination = -1;
}

Hand::~Hand() {
    this->cleanHand();
}

void Hand::sortHand() {
    for (int i = 0; i < this->maxCards; i++) {
        int minCardPos = i;
        for (int j = i; j < this->maxCards; j++) {
            if (*this->cards[j] < *this->cards[minCardPos]) {
                minCardPos = j;
            }
        }
        swapCards(this->cards[i], this->cards[minCardPos]);
    }
}

bool Hand::checkStraight() {
    int previousNumber = this->cards[0]->number;
    for (int i = 1; i < this->maxCards; i++) {
        if (this->cards[i]->number != previousNumber + 1) {
            return false;
        }
        previousNumber = this->cards[i]->number;
    }
    this->bestCombinationInfo.straightHighest = this->cards[4]->number;
    return true;
}

bool Hand::checkFlush() {
    std::string previousNipe = this->cards[0]->nipe;
    for (auto &&card : this->cards) {
        if (card->nipe != previousNipe) {
            return false;
        }
        previousNipe = card->nipe;
    }
    return true;
}

bool Hand::checkRoyalStraight() {
    if (this->cards[0]->number != 1) {
        return false;
    }
    int royalCardsNumber = 10;
    for (int i = 1; i < this->maxCards; i++) {
        if (this->cards[i]->number != royalCardsNumber) {
            return false;
        }
        royalCardsNumber++;
    }
    
    return true;
}

bool Hand::checkFourOfAKind() {
    bool isFirstFour, isLastFour;

    isFirstFour = *this->cards[0] == *this->cards[3];
    if (isFirstFour) {
        if (this->cards[3]->number == 1) {
            this->bestCombinationInfo.fourOfAKind = 14;
        } else {
            this->bestCombinationInfo.fourOfAKind = this->cards[3]->number;
        }
    }

    isLastFour = *this->cards[1] == *this->cards[4];
    if (isLastFour) {        
        this->bestCombinationInfo.fourOfAKind = this->cards[4]->number;
    }

    return isFirstFour || isLastFour;
}

bool Hand::checkOnePair() {
    bool isPairFound = false;

    int previousNumber = this->cards[0]->number;
    for (int i = 1; i < this->maxCards; i++) {
        if (this->cards[i]->number == previousNumber) {
            if (previousNumber == 1) {
                this->bestCombinationInfo.singlePair = 14;
                isPairFound = true;
                break;
            }
            
            this->bestCombinationInfo.singlePair = this->cards[i]->number;
            isPairFound = true;
            break;
        }
        previousNumber = this->cards[i]->number;
    }

    int highestCard = -1;
    for (auto &&card : this->cards) {
        if (card->number != this->bestCombinationInfo.singlePair)  {
            if (highestCard == 1) {
                highestCard = 14;
                this->bestCombinationInfo.singlePairHighestCard = highestCard;
                break;
            }
            else if (card->number > highestCard) {
                highestCard = card->number;
                this->bestCombinationInfo.singlePairHighestCard = highestCard;
            }
        }
    }
    
    return isPairFound;
}

bool Hand::checkTwoPairs() {
    bool firstPairFound = false, secondPairFound = false;

    int previousNumber = this->cards[0]->number;

    for (int i = 1; i < this->maxCards; i++) {
        if (this->cards[i]->number == previousNumber) {
            if (!firstPairFound) {
                this->bestCombinationInfo.lowestPair = this->cards[i]->number;
                firstPairFound = true;
            } 
            else {
                this->bestCombinationInfo.highestPair = this->cards[i]->number;
                if (this->bestCombinationInfo.lowestPair == 1) {
                    this->bestCombinationInfo.lowestPair = this->bestCombinationInfo.highestPair;
                    this->bestCombinationInfo.highestPair = 14;
                }
                secondPairFound = true;
                break;
            }
            
            i++;
            if (i >= this->maxCards) {
                break;
            }
        }
        previousNumber = this->cards[i]->number;
    }

    for (auto &&card : this->cards) {
        if (card->number != this->bestCombinationInfo.lowestPair &&
            card->number != this->bestCombinationInfo.highestPair)
        {
            this->bestCombinationInfo.twoPairHighestCard = card->number;
            break;
        }
    }
    
    return firstPairFound && secondPairFound;
}

bool Hand::checkThreeOfAKind() {
    bool isFirstThree = false, isMiddleThree = false, isLastThree = false;

    isFirstThree = *this->cards[0] == *this->cards[2];
    if (isFirstThree) {
        if (this->cards[2]->number == 1) {
            this->bestCombinationInfo.threeOfAKind = 14;
        }
        
        this->bestCombinationInfo.threeOfAKind = this->cards[2]->number;
    }

    isMiddleThree = *this->cards[1] == *this->cards[3];
    if (isMiddleThree) {
        if (this->cards[3]->number == 1) {
            this->bestCombinationInfo.threeOfAKind = 14;
        }
        this->bestCombinationInfo.threeOfAKind = this->cards[3]->number;
    }

    isLastThree = *this->cards[2] == *this->cards[4];
    if (isLastThree) this->bestCombinationInfo.threeOfAKind = this->cards[4]->number;

    return isFirstThree || isMiddleThree || isLastThree;
}

bool Hand::checkFullHouse() {
    bool isPairFirst = false, isPairLast = false;

    isPairFirst = (*this->cards[0] == *this->cards[1]) && (*this->cards[2] == *this->cards[4]);
    if (isPairFirst) {
        if (this->cards[1]->number == 1) {
            this->bestCombinationInfo.fullHousePair = 14;
        } else {
            this->bestCombinationInfo.fullHousePair = this->cards[1]->number;
        }
        this->bestCombinationInfo.fullHouseTrio = this->cards[4]->number;
    }
    
    isPairLast = (*this->cards[3] == *this->cards[4]) && (*this->cards[0] == *this->cards[2]);
    if (isPairLast) {
        if (this->cards[2]->number == 1) {
            this->bestCombinationInfo.fullHouseTrio = 14;
        } else {
            this->bestCombinationInfo.fullHouseTrio = this->cards[2]->number;
        }
        this->bestCombinationInfo.fullHousePair = this->cards[4]->number;
    }

    return isPairFirst || isPairLast;
}

bool Hand::checkValidHand() {
    for (auto &&card : this->cards) {
        if (!card) return false;
    }

    return true;
}

void Hand::findHighestCard() {
    if(!this->checkValidHand()) return;

    if (this->cards[0]->number == 1) {
        this->bestCombinationInfo.highestCard = 14;
    } else {
        this->bestCombinationInfo.highestCard = this->cards[4]->number;
    }
}

void Hand::addCard(std::string cardCode, Deck *cardDeck) {
    for (auto &&card : this->cards) {
        if (!card) {
            card = cardDeck->getCard(cardCode);
            break;
        }
    }
}

std::string Hand::getBestCombinationCode() {
    if (!this->checkValidHand()) return "";

    if (this->bestCombination == -1) {
        this->findBestCombination();
    }

    switch (this->bestCombination) {
        case this->HC:
            return "HC";
            break;
        
        case this->OP:
            return "OP";
            break;

        case this->TP:
            return "TP";
            break;

        case this->TK:
            return "TK";
            break;

        case this->S:
            return "S";
            break;

        case this->F:
            return "F";
            break;

        case this->FH:
            return "FH";
            break;

        case this->FK:
            return "FK";
            break;

        case this->SF:
            return "SF";
            break;

        case this->RSF:
            return "RSF";
            break;
        
        default:
            return "";
            break;
    }
}

void Hand::findBestCombination() {
    if (!this->checkValidHand()) return;

    this->sortHand();
    this->findHighestCard();

    bool isRoyalStraight = this->checkRoyalStraight();
    bool isFourOfAKind = this->checkFourOfAKind();
    bool isFullHouse = this->checkFullHouse();
    bool isFlush = this->checkFlush();
    bool isStraight = this->checkStraight();
    bool isThreeOfAKind = this->checkThreeOfAKind();
    bool isTwoPairs = this->checkTwoPairs();
    bool isOnePair = this->checkOnePair();

    if (isFlush) {
        if (isRoyalStraight) {
            this->bestCombination = this->RSF;
            return;
        }
        else if (isStraight) {
            this->bestCombination = this->SF;
            return;
        }
    }
    if (isFourOfAKind) {
        this->bestCombination = this->FK;
        return;
    }
    if (isFullHouse) {
        this->bestCombination = this->FH;
        return;
    }
    if (isFlush) {
        this->bestCombination = this->F;
        return;
    }
    if (isStraight || isRoyalStraight) {
        this->bestCombination = this->S;
        return;
    }
    if (isThreeOfAKind) {
        this->bestCombination = this->TK;
        return;
    }
    if (isTwoPairs) {
        this->bestCombination = this->TP;
        return;
    }
    if (isOnePair)
    {
        this->bestCombination = this->OP;
        return;
    }
    {
        this->bestCombination = this->HC;
        return;
    }
}

void Hand::cleanHand() {
    for (int i = 0; i < this->maxCards; i++) {
        if (this->cards[i] == nullptr) continue;
        this->cards[i] = nullptr;
    }

    this->bestCombination = -1;
}

std::ostream &operator<<(std::ostream &out, Hand *hand) {
    if (!hand->checkValidHand()) {
        out << "Esta mão é inválida." << std::endl;
        return out;
    }

    for (auto &&card : hand->cards) {
        out << card->getCardNumber() << card->getCardNipe() << " ";
    }
    std::cout << std::endl;
    
    return out;
}

std::ostream &operator<<(std::ostream &out, Hand hand) {
    if (!hand.checkValidHand()) {
        out << "Esta mão é inválida." << std::endl;
        return out;
    }

    for (auto &&card : hand.cards) {
        out << card->getCardNumber() << card->getCardNipe() << " ";
    }
    std::cout << std::endl;
    
    return out;
}