//---------------------------------------------------------------------
// Arquivo	: inbox.hpp
// Conteudo	: definicoes da classe Inbox (Caixa de Entrada)
// Autor	: Pedro de Oliveira Guedes (pedro.og2002@gmail.com)
//---------------------------------------------------------------------

#ifndef INBOX_H
#define INBOX_H

#include "email.hpp"

/**
 * @brief Classe Inbox. Define o sistema de armazenamento de e-mails para os usuários.
 * 
 */
class Inbox {
    public:
        /**
         * @brief Construtor padrão da classe Inbox. Cria uma caixa de entrada vazia.
         * 
         */
        Inbox();

        /**
         * @brief Destrutor da classe Inbox. Remove todos os e-mails armazenados ao fim da sessão.
         * 
         */
        ~Inbox();

        /**
         * @brief Procura por um e-mail na caixa de entrada do(s) usuário(s).
         * 
         * @param emailID Identificador do e-mail buscado.
         * @return std::string -> Conteúdo de texto do e-mail encontrado.
         */
        std::string searchEmail(int emailID);

        /**
         * @brief Adiciona um novo e-mail à caixa de entrada do destinatário.
         * 
         * @param emailID Identificador do novo e-mail.
         * @param userID Identificador do destinatário.
         * @param wordsAmount Quantidade de palavras no e-mail.
         * @param msg Mensagem a ser enviada para o destinatário.
         * @return true (1) ou false (0), a depender se a adição foi bem sucedida ou não.
         */
        bool addEmail(int emailID, int userID,
                      int wordsAmount, std::string msg);

        /**
         * @brief Apaga um e-mail enviado para o usuário.
         * 
         * @param emailID Identificador do e-mail que se quer apagar.
         * @return true (1) ou false (0), a depender se a exclusão foi bem sucedida ou não.
         */
        bool deleteEmail(int emailID);

    private:
        Email *root; // E-mail raiz da caixa de entrada.

    /**
     * @brief Método para imprimir a caixa de entrada por caminhamento pré-ordem.
     */
    friend std::ostream &operator<<(std::ostream &out, const Inbox *inbox);
};

#endif