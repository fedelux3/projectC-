#include "sortedException.h"

sortedException::sortedException(const std::string &message) 
    : std::runtime_error(message) {
}

emptyException::emptyException(const std::string &message) 
    : sortedException::sortedException(message) {
}

insertException::insertException(const std::string &message) 
    : sortedException::sortedException(message) {
}

elemNotFoundException::elemNotFoundException(const std::string &message) 
    : sortedException::sortedException(message) {
}

deleteException::deleteException(const std::string &message) 
    : sortedException::sortedException(message) {
}