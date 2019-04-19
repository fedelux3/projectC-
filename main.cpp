#include <iostream>
#include "grafo.h"
#include <string>
#include <assert.h>

//tipo custom point
struct point {
    int _x;
    double _y;

    point(): _x(0), _y(0) {}

    point(int x, double y): _x(x), _y(y) {}

    bool operator==(const point &other) const{
        if (this->_x == other._x && this->_y == other._y)
            return true;
        else
            return false;
    }     
};

//stampa del point
std::ostream &operator<<(std::ostream &os, const point &p) {

    os << "x: " << p._x << ", y: " << p._y;

    return os;
}

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
    try {
    g.insertNodo(7);
    }
    catch(nodeDuplicateException &e){}

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

    std::cout << "dopo1" << std::endl;
    std::cout << g << std::endl;

    g.insertNodo(57);

    std::cout << "dopo2" << std::endl;
    std::cout << g << std::endl;

    g.deleteNodo(42);
    try{
        g.deleteNodo(42);
    } catch (nodeNotFoundException &e) {}

    std::cout << "dopo3" << std::endl;
    std::cout << g << std::endl;

    g.deleteNodo(57);
    
    std::cout << "dopo5" << std::endl;
    std::cout << g << std::endl;
    try{
    g.deleteNodo(42);
    } catch (emptyException &e) {}
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
    try{
    g.insertArco(51,2);
    } catch (edgeException &e) {}
    try {
    g.insertArco(3,5);
    } catch (nodeNotFoundException &e){}
    std::cout << g << std::endl;


    g.deleteArco(51,2);
    try {
    g.deleteArco(2,83);
    } catch (edgeNotFoundException &e){}
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

    grafo_type g3 = g2;

    std::cout << g2 << std::endl;

    g2.insertArco("primo", "primo");
    std::cout << "g:" << std::endl;
    std::cout << g << std::endl;
    std::cout << "g2:" << std::endl;
    std::cout << g2 << std::endl;

    std::cout << "g3" << std::endl;
    std::cout << g3 << std::endl;
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
    try {
    g.insertArco(4.3,53); //gia` inserito
    } catch (edgeException &e) {}

    std::cout << g << std::endl;

    try {
    g.deleteArco(7.5,7.5); //non esiste
    } catch (edgeNotFoundException &e) {}
    g.deleteArco(53,4.3);
    try {
    g.deleteArco(4.3,54); //non esiste nodo
    } catch (nodeNotFoundException &e) {}
    std::cout << g << std::endl;

    //copy constructor
    g_type g2(g);
    g_type g3 = g;
    g2.insertNodo(23.43);
    g2.insertArco(7.5, 23.43);
    std::cout << "g" << std::endl;
    std::cout << g << std::endl;
    
    std::cout << "g2" << std::endl;
    std::cout << g2 << std::endl;

    g3.insertNodo(13.42);
    g3.insertArco(13.42,4.3);
    g3.insertArco(13.42,13.42);

    std::cout << "g3" << std::endl;
    std::cout << g3 << std::endl;
}

void testCustom() {
    point p(5,3.4);
    point p2(5,3.4);
    std::cout << p << std::endl;
    bool b;
    b = p == p2;
    std::cout<<b << std::endl;
    
    typedef grafo<point> grafo_type;
    grafo_type g;

    g.insertNodo(p);
    try{
        g.insertNodo(p2);
    } catch (nodeDuplicateException &e) {
        std::cout << "duplicate exception" << std::endl;
    }
    g.insertNodo(point(6,8));
    g.insertNodo(point(2,12.2));
    
    g.insertArco(p,point(6,8));
    g.insertArco(point(6,8),p);
    g.insertArco(point(2,12.2),point(2,12.2));
    std::cout << g << std::endl;

    g.deleteArco(p,point(6,8));
    g.deleteNodo(point(2,12.2));
    std::cout << g << std::endl;

    grafo_type g2(g);

    point p3(3,7.2);
    g2.insertNodo(p3);
    g2.insertArco(p, p3);
    g2.insertArco(p3, p3);
    
    std::cout << "g\n" << g << std::endl;
    std::cout << "g2\n" << g2 << std::endl;
}

int main() {

    std::cout<< " - - - Test Create - - - \n" << std::endl;
    testCreate();
    std::cout<< " - - - Test Delete - - - \n" << std::endl;
    testDelete();
    std::cout<< " - - - Test Archi - - - \n" << std::endl;
    testArchi();
    std::cout<< " - - - Test Tipi - - - \n" << std::endl;
    testTipi();
    std::cout<< " - - - Test Vario - - - \n" << std::endl;
    testVario();
    std::cout<< " - - - Test Custom - - - \n" << std::endl;
    testCustom();
    return 0;
}