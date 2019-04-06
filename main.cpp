#include <iostream>
#include "grafo.h"
#include <string>
#include <assert.h>

//test iteratore
template <typename T>
void testIterator(const grafo<T> &graph){
    typename grafo<T>::const_iterator i, ie;
    
    for (i=graph.begin(), ie =graph.end(); i!=ie; ++i) {
        std::cout << *i <<std::endl;
    }
}

void testCreate() {
    
    typedef grafo<int> grafo_type;
    grafo_type g;

    g.insertNodo(0);
    g.insertNodo(1);
    g.insertNodo(2);
    g.insertNodo(7);
    g.insertNodo(7);
    g.insertNodo(9);
    
    
    std::cout << g << std::endl;
    
    //std::cout << g.get_arco(2,3) << std::endl;
}

void testDelete() {

    typedef grafo<int> grafo_type;
    grafo_type g;

    g.insertNodo(23);
    g.insertNodo(42);

    std::cout << "prima" << std::endl;
    std::cout << g << std::endl;

    g.deleteNodo(23);

    std::cout << "dopo" << std::endl;
    std::cout << g << std::endl;

    g.insertNodo(57);

    std::cout << "dopo2" << std::endl;
    std::cout << g << std::endl;

    g.deleteNodo(42);
    g.deleteNodo(42);

    std::cout << "dopo3" << std::endl;
    std::cout << g << std::endl;

    g.deleteNodo(57);
    
    std::cout << "dopo5" << std::endl;
    std::cout << g << std::endl;

    g.deleteNodo(42);
    // GESTIRE CASO DEL GRAFO VUOTO E DELETE SBAGLIATE
}

void testArchi() {
    typedef grafo<int> grafo_type;
    grafo_type g;

    g.insertNodo(2);
    g.insertNodo(51);
    g.insertNodo(83);
    std::cout << g << std::endl;
    
    g.insertArco(51,2);
    g.insertArco(2,2);
    g.insertArco(2,51);
    g.insertArco(51,2);
    g.insertArco(3,5);
    std::cout << g << std::endl;


    g.deleteArco(51,2);
    g.deleteArco(2,83);
    g.deleteArco(2,2);
    std::cout << g << std::endl;

    g.insertNodo(42);
    g.insertNodo(13);
    g.insertArco(42,13);
    g.insertArco(2,13);
    std::cout << g << std::endl;

    g.insertArco(51,83);
    g.insertArco(13,42);
    std::cout << g << std::endl;

    g.deleteNodo(2);
    std::cout << g << std::endl;
    
}

void testTipi() {
    typedef grafo<std::string> grafo_type;
    grafo_type g;

    g.insertNodo("primo");
    g.insertNodo("secondo");
    g.insertNodo("terzo");
    g.insertArco("primo", "secondo");
    g.insertArco("secondo", "secondo");
    g.insertArco("terzo", "primo");
    std::cout << g << std::endl;

    std::cout << "test iteratore " << std::endl;
    testIterator(g);
    std::cout << "test stampa" << std::endl;
    std::cout << g << std::endl;

    assert(g.exists("primo"));
    assert(g.hasEdge("primo", "secondo"));  

    grafo_type g2(g);

    std::cout << g2 << std::endl;

    g2.insertArco("primo", "primo");
    std::cout << "g:" << std::endl;
    std::cout << g << std::endl;
    std::cout << "g2:" << std::endl;
    std::cout << g2 << std::endl;


}

void testVario() {
    typedef grafo<double> g_type;
    g_type g;

    g.insertNodo(4.3);
    g.insertNodo(53);
    g.insertNodo(4+3.5);
    
    std::cout << g << std::endl;

    g.insertArco(53,4.3);
    g.insertArco(4.3,4.3);
    g.insertArco(53,7.5);
    g.insertArco(7.5,4.3);
    g.insertArco(4.3,53);
    g.insertArco(4.3,53); //gia` inserito
    
    std::cout << g << std::endl;

    g.deleteArco(7.5,7.5); //non esiste
    g.deleteArco(53,4.3);
    g.deleteArco(4.3,54); //non esiste nodo

    std::cout << g << std::endl;

    //copy constructor
    g_type g2(g);

    g2.insertNodo(23.43);
    g2.insertArco(7.5, 23.43);
    std::cout << "g" << std::endl;
    std::cout << g << std::endl;
    
    std::cout << "g2" << std::endl;
    std::cout << g2 << std::endl;
}

int main() {

    // testCreate();
    // testDelete();
    // testArchi();
    // testTipi();
    testVario();

    return 0;
}