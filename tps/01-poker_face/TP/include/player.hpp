//---------------------------------------------------------------------
// Arquivo	: player.hpp
// Conteudo	: definicoes da classe Jogador
// Autor	: Pedro de Oliveira Guedes (pedro.og2002@gmail.com)
//---------------------------------------------------------------------

#ifndef PLAYER_H
#define PLAYER_H

#include "hand.hpp"

/**
 * @brief Classe Jogador. Guarda os atributos relacionados a ele, além de realizar operações como aposta.
 * 
 */
class Player {
    public:
        /**
         * @brief Construtor padrão de um novo jogador.
         * 
         */
        Player();
        /**
         * @brief Construtor do jogador inicializando o nome do mesmo e o total de fichas iniciais que ele possui.
         * 
         * @param name Nome atribuído ao jogador.
         * @param coins Total de fichas que o jogador possui inicialmente.
         */
        Player(std::string name, int coins);
        /**
         * @brief Destrutor padrão do jogador. Desaloca a mão e a torna um ponteiro nulo.
         * 
         */
        ~Player();

        /**
         * @brief Retorna o nome do jogador.
         * 
         * @return std::string this->name.
         */
        std::string getName();

        /**
         * @brief Retorna a quantidade de fichas do jogador.
         * 
         * @return int this->coins.
         */
        int getCoins();

        /**
         * @brief Realiza o teste de sanidade do jogador, ou seja, se ele pode ou não realizar a aposta.
         * 
         * @param coinAmount Quantidade de fichas a serem apostadas na rodada (incluindo o pingo).
         * 
         * @return true (1) ou false (0), dependendo se a aposta pode ou não ser realizada.
         * 
         */
        bool sanityTest(int coinAmount);

        /**
         * @brief Realiza a aposta do jogador.
         * 
         * @param bet Quantidade de fichas investidas na aposta.
         */
        void makeBet(int bet);

        /**
         * @brief Adiciona uma nova carta à mão do usuário.
         * 
         * @param cardCode Código da carta que se quer adicionar.
         */
        void addCard(std::string cardCode, Deck *cardDeck);

        /**
         * @brief Operador de comparação: Menor que.
         * 
         * @param player Outro jogador que se quer saber se ele é maior que o atual.
         * 
         * @return true (1) ou false (0), dependendo de se um jogador é ou não menor que outro.
         * 
         */
        bool operator < (Player &player) {
            return *this->hand < *player.hand;
        }

        /**
         * @brief Operador de comparação: Maior que.
         * 
         * @param player Outro jogador que se quer saber se ele é menor que o atual.
         * 
         * @return true (1) ou false (0), dependendo de se um jogador é ou não menor que outro.
         * 
         */
        bool operator > (Player &player) {
            return *this->hand > *player.hand;
        }

        /**
         * @brief Operador de comparação: Igual a.
         * 
         * @param player Outro jogador que se quer saber se ele é igual ao atual.
         * 
         * @return true (1) ou false (0), dependendo de se um jogador é ou não igual ao outro.
         * 
         */
        bool operator == (Player &player) {
            return *this->hand == *player.hand;
        }

        // TODO:
        // - Declarar método de impressão do usuário para debug. (Nome - fichas - Mão)

    private:
        std::string name; // Nome do jogador.
        int coins; // Total de moedas do jogador.
        Hand *hand; // Mão atual do jogador.

    friend std::ostream &operator<<(std::ostream &out, const Player *player);
    friend std::ostream &operator<<(std::ostream &out, const Player player);
    friend class Round;
    friend class Match;
};

#endif