#ifndef GRAFOEXCEPTION_H
#define GRAFOEXCEPTION_H

#include <stdexcept>
#include <string>

class grafoException : public std::runtime_error {
public:

    grafoException(const std::string &message);
};

class emptyException : public grafoException {
public:
    //se grafo risulta essere vuoto
    emptyException(const std::string &message);
};

class nodeNotFoundException : public grafoException {
public:
    //se non viene trovato un certo nodo
    nodeNotFoundException(const std::string &message);
};

class nodeDuplicateException : public grafoException {
public:
    //se un nodo che voglio inserire esiste gia' 
    nodeDuplicateException(const std::string &message);
};

class edgeException : public grafoException {
public:
    //se un arco e' gia' stato inserito
    edgeException(const std::string &message);
};

class edgeNotFoundException : public grafoException {
public:
    //se un arco non viene trovato
    edgeNotFoundException(const std::string &message);
};

#endif