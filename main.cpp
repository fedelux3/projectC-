#include <iostream>
#include "grafo.h"
#include <string>

void testCreate() {
    
    typedef grafo<int> grafo_type;
    grafo_type g;

    g.insertNodo(0);
    g.insertNodo(1);
    g.insertNodo(2);
    g.insertNodo(7);
    g.insertNodo(8);
    g.insertNodo(9);
    
    
    g.stampVertici();
    std::cout << "MATRICE" << std::endl;
    g.stampArchi();
    
    //std::cout << g.get_arco(2,3) << std::endl;
}

void testDelete() {

    typedef grafo<int> grafo_type;
    grafo_type g;

    g.insertNodo(23);
    g.insertNodo(42);

    std::cout << "prima" << std::endl;
    g.stampVertici();
    g.stampArchi();

    g.deleteNodo(23);

    std::cout << "dopo" << std::endl;
    g.stampVertici();
    g.stampArchi();

    g.insertNodo(57);

    std::cout << "dopo2" << std::endl;
    g.stampVertici();
    g.stampArchi();

    g.deleteNodo(42);
    g.deleteNodo(42);

    std::cout << "dopo3" << std::endl;
    g.stampVertici();
    g.stampArchi();

    g.deleteNodo(57);
    
    std::cout << "dopo5" << std::endl;
    g.stampVertici();
    g.stampArchi();

    g.deleteNodo(42);
    // GESTIRE CASO DEL GRAFO VUOTO E DELETE SBAGLIATE
}

void testArchi() {
    typedef grafo<int> grafo_type;
    grafo_type g;

    g.insertNodo(2);
    g.insertNodo(51);
    g.insertNodo(83);
    g.stampVertici();
    g.stampArchi();
    std::cout << std::endl;
    
    g.insertArco(51,2);
    g.insertArco(2,2);
    g.insertArco(2,51);
    g.insertArco(51,2);
    g.insertArco(3,5);
    g.stampArchi();
    std::cout << std::endl;

    g.deleteArco(51,2);
    g.deleteArco(2,83);
    g.deleteArco(2,2);
    g.stampArchi();
    std::cout << std::endl;

    g.insertNodo(42);
    g.insertNodo(13);
    g.insertArco(42,13);
    g.insertArco(2,13);
    g.stampArchi();
    std::cout << std::endl;

    g.insertArco(51,83);
    g.insertArco(13,42);
    g.stampArchi();
    std::cout << std::endl;

    g.deleteNodo(2);
    g.stampArchi();
    
}

void testTipi() {
    typedef grafo<std::string> grafo_type;
    grafo_type g;
    std::string s = "ciao";

    g.insertNodo(s);
    g.insertNodo("prova");
    g.insertNodo("ieila");
    g.stampVertici();
    g.stampArchi();
    std::cout << std::endl;
    
    g.deleteNodo(s);
    g.insertArco("prova","ieila");
    g.insertArco("prova", "prova");
    g.stampArchi();
}

void testIterator(){
    typedef grafo<int> grafo_type;
    grafo_type g;

    g.insertNodo(4);
}

int main() {

    //testCreate();
    //testDelete();
    //testArchi();
    testTipi();

    return 0;
}