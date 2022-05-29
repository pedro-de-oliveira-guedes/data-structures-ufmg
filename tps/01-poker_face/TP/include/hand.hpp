//---------------------------------------------------------------------
// Arquivo	: deck.hpp
// Conteudo	: definicoes da classe Baralho
// Autor	: Pedro de Oliveira Guedes (pedro.og2002@gmail.com)
//---------------------------------------------------------------------

#ifndef HAND_H
#define HAND_H

#include "deck.hpp"

/**
 * @brief Classe para armazenar as cartas na mão do jogador.
 * 
 */
class Hand {
    enum {
        HC, // Highest Card
        OP, // One Pair
        TP, // Two Pairs
        TK, // Three of a kind
        S, // Straight
        F, // Flush 
        FH, // Full House
        FK, // Four of a Kind
        SF, // Straight Flush
        RSF // Royal Straight Flush
    };
        
    public:
        /**
         * @brief Construtor da mão de cartas do jogador.
         * 
         */
        Hand();
        /**
         * @brief Destrutor da mão de cartas do jogador
         * 
         */
        ~Hand();

        bool operator < (Hand const &hand) {
            return this->bestCombination < hand.bestCombination;
        }

        bool operator > (Hand const &hand) {
            return this->bestCombination > hand.bestCombination;
        }

        /**
         * @brief Operador de comparação de igualdade entre mãos de cartas dos jogadores.
         * Se uma mão foi declarada como ponteiro (Hand *h;), lembre-se de desreferenciá-la (*h == *g).
         * 
         * @param card 
         * @return true (1) ou false (0) dependendo da igualdade
         */
        bool operator == (Hand const &hand) {
            return ( !(this->bestCombination > hand.bestCombination) && 
                     !(this->bestCombination < hand.bestCombination) );
        }

        /**
         * @brief Ordena a mão de cartas do jogador, deixando a menor carta na primeira posição do array e a maior na última.
         * 
         */
        void sortHand();
        /**
         * @brief Encontra a melhor combinação de cartas presente na mão do usuário.
         * 
         */
        void findBestCombination();
        /**
         * @brief Depois de definida a melhor combinação de cartas na mão do jogador, mapeia a enumeração para os respectivos códigos em string, retornando o código encontrado.
         * 
         * @return String contendo o código da melhor combinação presente na mão.
         */
        std::string getBestCombinationCode();
        /**
         * @brief Adiciona uma nova carta à mão do jogador.
         * 
         * @param cardCode Código da carta (Ex.: "13E")
         */
        void addCard(std::string cardCode);
        /**
         * @brief Limpa todas as cartas utilizadas da mão, tornando os elementos do array ponteiros nulos.
         * 
         */
        void cleanHand();

    private:
        const int maxCards = 5;
        Card *cards[5];
        int bestCombination;
        Card *highestCard;

        /**
         * @brief Verifica se há uma sequência de cartas no baralho.
         * 
         * @return true (1) ou false (0) dependendo de se há uma sequência ou não.
         */
        bool checkStraight();

        /**
         * @brief Verifica se todas as cartas do baralho são do mesmo naipe.
         * 
         * @return true (1) ou false (0) dependendo de se as cartas são ou não do mesmo naipe.
         */
        bool checkFlush();

        /**
         * @brief Verifica se há uma sequência de cartas no baralho e se essa sequência é: Ás(1), 10, Valete(11), Dama(12) e Rei(13).
         * 
         * @return true (1) ou false (0) dependendo de se há uma sequência real ou não.
         */
        bool checkRoyalStraight();

        /**
         * @brief Verifica se há uma quadra presente na mão do jogador.
         * 
         * @return true (1) ou false (0) dependendo de se há uma quadra ou não.
         */
        bool checkFourOfAKind();

        /**
         * @brief Verifica se há um par presente na mão do jogador.
         * 
         * @return true (1) ou false (0) dependendo de se há um par ou não.
         */
        bool checkOnePair();

        /**
         * @brief Verifica se há dois pares distintos presente na mão do jogador.
         * 
         * @return true (1) ou false (0) dependendo de se há dois pares ou não.
         */
        bool checkTwoPairs();

        /**
         * @brief Verifica se há uma tripla presente na mão do jogador.
         * 
         * @return true (1) ou false (0) dependendo de se há uma tripla ou não.
         */
        bool checkThreeOfAKind();

        /**
         * @brief Verifica se a mão presente representa uma combinação de Full House.
         * 
         * @return true (1) ou false (0) dependendo de se é um Full House ou não.
         */
        bool checkFullHouse();

        /**
         * @brief Encontra a maior carta e a registra na variável this->highestCard.
         * 
         */
        void findHighestCard();
};

#endif