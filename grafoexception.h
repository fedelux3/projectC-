#ifndef GRAFOEXCEPTION_H
#define GRAFOEXCEPTION_H

#include <stdexcept>
#include <string>

/**
 * Classe che gestisce le eccezioni del grafo
 * @short Eccezione grafo
 */
class grafoException : public std::runtime_error {
public:

    grafoException(const std::string &message);
};

/**
 * Classe che gestisce eccezione del grafo vuoto
 * @short Eccezione grafo vuoto 
 */
class emptyException : public grafoException {
public:

    emptyException(const std::string &message);
};

/**
 * Classe che gestisce eccezione del nodo non trovato nel grafo
 * @short Eccezione nodo non trovato
 */
class nodeNotFoundException : public grafoException {
public:

    nodeNotFoundException(const std::string &message);
};

/**
 * Classe che gestisce eccezione dell'inserimento di un nodo gia' presente nel grafo
 * @short Eccezione nodo gia' presente
 */
class nodeDuplicateException : public grafoException {
public:

    nodeDuplicateException(const std::string &message);
};

/**
 * Classe che gestisce eccezione del'inserimento di un arco gia' presente nel grafo
 * @short Eccezione arco gia' presente
 */
class edgeException : public grafoException {
public:

    edgeException(const std::string &message);
};

/**
 * Classe che gestisce eccezione della ricerca/eliminazione di un arco che non esiste
 * @short Eccezione arco che non c'e'
 */
class edgeNotFoundException : public grafoException {
public:

    edgeNotFoundException(const std::string &message);
};

#endif