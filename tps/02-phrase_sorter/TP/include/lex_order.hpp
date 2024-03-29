//---------------------------------------------------------------------
// Arquivo	: lex-order.hpp
// Conteudo	: definicoes da classe LexOrder
// Autor	: Pedro de Oliveira Guedes (pedro.og2002@gmail.com)
//---------------------------------------------------------------------

#ifndef LEXORDER_H
#define LEXORDER_H

#include <iostream>
#include <string>

#include "memlog.hpp"

/**
 * @brief Classe LexOrder, define a ordem lexicográfica com a qual as palavras vão ser ordenadas.
 * 
 */
class LexOrder {
    public:
        /**
         * @brief Construtor da classe LexOrder. Atribui valor a todas as letras, crescentemente de acordo com a string recebida em lexOrder.
         * 
         * @param lexOrder String com a ordem lexicográfica a ser seguida.
         */
        LexOrder(std::string lexOrder);

        /**
         * @brief Retorna o valor da letra recebida como parâmetro.
         * 
         * @param letter Letra que se quer saber o valor na nova ordem lexicográfica.
         * @return int Valor da letra na ordem lexicográfica atual.
         */
        int getLetterValue(int letter);

        /**
         * @brief Define o valor associado à letra recebida na nova ordem lexicográfica.
         * 
         * @param letter Letra que se quer definir o valor.
         * @param value Valor a ser associado à letra.
         */
        void setLetterValue(std::string letter, int value);

    private:
        /**
         * @brief Letra do alfabeto.
         * 
         */
        int a = -1, b = -1, c = -1, d = -1, e = -1,\
            f = -1, g = -1, h = -1, i = -1, j = -1, \
            k = -1, l = -1, m = -1, n = -1, o = -1,\
            p = -1, q = -1, r = -1, s = -1, t = -1, \
            u = -1, v = -1, w = -1, x = -1, y = -1, z = -1;
};

#endif