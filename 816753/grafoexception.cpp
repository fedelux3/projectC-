#include "grafoexception.h"

grafoException::grafoException(const std::string &message) 
    : std::runtime_error(message) {
}

nodeNotFoundException::nodeNotFoundException(const std::string &message) 
    : grafoException::grafoException(message) {
}

emptyException::emptyException(const std::string &message) 
    : grafoException::grafoException(message){
}

edgeException::edgeException(const std::string &message) 
    : grafoException::grafoException(message){
}

edgeNotFoundException::edgeNotFoundException(const std::string &message) 
    : grafoException::grafoException(message) {
}

nodeDuplicateException::nodeDuplicateException(const std::string &message) 
    : grafoException::grafoException(message) {
}
