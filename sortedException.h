#ifndef SORTEDEXCEPTION_H
#define SORTEDEXCEPTION_H

#include <stdexcept>
#include <string>

/**
 * Classe che gestisce le eccezioni del sortedArray
 * @short Eccezione sortedArray
 */
class sortedException : public std::runtime_error {
public:

    sortedException(const std::string &message);
};

/**
 * Classe che gestisce eccezione del sortedArray vuoto
 * @short Eccezione sortedArray vuoto 
 */
class emptyException : public sortedException {
public:

    emptyException(const std::string &message);
};

/**
 * Classe che gestisce l'eccezione per l'inserimento di un elemento erroneamente
 * @short Eccezione insert 
 */
class insertException : public sortedException {
public:

    insertException(const std::string &message);
};

/**
 * Classe che gestisce l'eccezione per la ricerca di un elemento 
 * non presente nel sortedArray
 * @short Eccezione elemento non trovato
 */
class elemNotFoundException : public sortedException {
public:

    elemNotFoundException(const std::string &message);
};

/**
 * Classe che gestisce l'eccezione per l'eliminazione di un elemento erroneamente
 * @short Eccezione delete
 */
class deleteException : public sortedException {
public:

    deleteException(const std::string &message);
};

#endif