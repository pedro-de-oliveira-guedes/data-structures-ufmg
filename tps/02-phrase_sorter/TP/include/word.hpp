//---------------------------------------------------------------------
// Arquivo	: word.hpp
// Conteudo	: definicoes da classe Word
// Autor	: Pedro de Oliveira Guedes (pedro.og2002@gmail.com)
//---------------------------------------------------------------------

#ifndef WORD_H
#define WORD_H

#include "lex_order.hpp"

/**
 * @brief Classe Word. Define os atributos que devem ser guardados para a contagem e ordenação das palavras.
 * 
 */
class Word {
    public:
        /**
         * @brief Construtor padrão da classe Word.
         * 
         */
        Word();

        /**
         * @brief Construtor da classe Word. Atribui a string recebida à palavra que o objeto armazena.
         * 
         * @param word Palavra que se quer armazenar.
         */
        Word(std::string word);

        /**
         * @brief Retorna o tamanho da palavra armazenada.
         * 
         * @return int Atributo this->size.
         */
        int getSize();

        /**
         * @brief Retorna a palavra que a classe armazena.
         * 
         * @return std::string Atributo this->word.
         */
        std::string getWord();

        /**
         * @brief Verifica se a string recebida é igual à palavra que este objeto armazena.
         * 
         * @param newWord Palavra que se quer verificar a igualdade.
         * 
         * @return true(1) se a string é igual à palavra armazenada e false (0) caso contrário
         */
        bool matches(std::string newWord);

        /**
         * @brief Verifica se o objeto de palavra atual é menor que o fornecido por parâmetro.
         * 
         * @param word Objeto que se quer saber se é maior que o objeto atual.
         * @param lexOrder Ordem lexicográfica na qual os objetos serão comparados.
         * 
         * @return true (1) se o objeto palavra atual for menor e false (0) caso contrário.
         */
        bool isLessThan(Word *word, LexOrder *lexOrder);

        /**
         * @brief Verifica se o objeto de palavra atual é maior que o fornecido por parâmetro.
         * 
         * @param word Objeto que se quer saber se é menor que o objeto atual.
         * @param lexOrder Ordem lexicográfica na qual os objetos serão comparados.
         * 
         * @return true (1) se o objeto palavra atual for maior e false (0) caso contrário.
         */
        bool isGreaterThan(Word *word, LexOrder *lexOrder);

    private:
        std::string word; // Palavra armazenada pela classe.
        int occurrences; // Quantidade de vezes que essa palavra foi lida.
        int size; // Tamanho da palavra armazenada.

        Word *next; // Próxima palavra.
    
    /**
     * @brief Método para imprimir as informações da palavra.
     */
    friend std::ostream &operator<<(std::ostream &out, const Word *word);

    friend class WordList;
};

#endif