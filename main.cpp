#include <iostream> 
#include <assert.h>
#include "sortedArray.h"

struct equals_int {

   bool operator()(const int &a, const int &b) const{
      return a == b;
   }
};
struct compare_int {

   bool operator()(const int &a, const int &b) const{
      return a < b;
   }
};
struct functor_int {

   bool operator()(const int &a) const{
      return a < 4;
   }
};

struct equals_string {

   bool operator()(const std::string &s1, const std::string &s2) const {
      return (s1.compare(s2) == 0);
   }
};
struct compare_string {

   bool operator()(const std::string &s1, const std::string &s2) const {
      if (s1.compare(s2) < 0) {
         return true;
      } else {
         return false;
      }
   }
};
struct functor_string {

   bool operator()(const std::string &a) const{
      return a.length() >= 4;
   }
};

struct point {
   double _x;
   int _y;

   point(): _x(0), _y(0) {}

   point(double x, int y): _x(x), _y(y) {} 
};
struct equals_point {

   bool operator()(const point &p1, const point &p2) const{
      return (p1._x == p2._x && p1._y == p2._y);
   }
};
struct compare_point {

   bool operator()(const point &p1, const point &p2) const {
      if (p1._x == p2._x) 
         return (p1._y <= p2._y);
      return (p1._x < p2._x);

   }
};
struct functor_point {
   //se il punto si trova nel primo quadrante
   bool operator()(const point &p) const {
      return (p._x > 0 && p._y > 0);
   }
};
//stampa point
std::ostream &operator<<(std::ostream &os, const point &p) {
    os << "(" << p._x << "," << p._y << ")";
    return os;
}

void testInsert() {
   typedef sortedArray<int,compare_int, equals_int> sortedArrInt;

   sortedArrInt a;

   a.insertElem(5);
   a.insertElem(1);
   a.insertElem(6);
   
   std::cout << a << std::endl;
   
   a.insertElem(2);
   a.insertElem(4);
   a.insertElem(4);
   a.insertElem(6);

   std::cout << "stampa random_access" << std::endl;
   std::cout << a << std::endl;

   assert(a.exist(1));
   assert(a.exist(4));
   assert(!a.exist(3));

   //testo iteratore random_access
   typename sortedArrInt::const_iterator i, ie;
   i = a.begin();
   ie = a.end();
   
   assert(i[1]==2);
   assert(i[3]==4);
   i-=1;
   ie-=1;
   std::cout << "stampa inversa da iteratore random_access" << std::endl;
   for (; i!=ie; --ie) {
      std::cout << ie[0] << " ";
   }
   i = a.begin();
   ie = a.end();

   assert(*(i+1) == 2);
   assert(*(i+=1) == 2);
   assert(*(i+1) == 4);
   
   std::cout << std::endl;
   
   typename sortedArrInt::reverse_iterator ir, ire;
   ir = a.begin_r();
   ire = a.end_r();
   
   
   std::cout << "stampa inversa da iteratore reverse" << std::endl;
   for (; ir!=ire; ++ir) {
      std::cout << *ir << " ";
   }
   std::cout << std::endl;

   //test functor custom
   sortedArrInt sa = a.functor(functor_int());
   std::cout << "applico funtore \" < 4 \"" << std::endl;
   std::cout << sa << std::endl;
}

void testDelete() {
   typedef sortedArray<std::string, compare_string, equals_string> sortedArrString;

   sortedArrString a;

   a.insertElem("a");
   a.insertElem("ab");
   a.insertElem("abc");
   a.insertElem("zeta");
   
   std::cout << a << std::endl;
   
   a.insertElem("ciao");
   a.insertElem("ba");
   a.insertElem("ab");
   a.insertElem("acb");
   a.insertElem("zorro");

   std::cout << "stampa random_access" << std::endl;
   std::cout << a << std::endl;

   a.deleteElem("ab");
   std::cout << "eliminato \"ab\"" << std::endl;
   std::cout << a << std::endl;
   a.deleteElem("zeta");
   std::cout << "eliminato \"zeta\"" << std::endl;
   std::cout << a << std::endl;

   sortedArrString b = a;
   std::cout << "fisso b" << std::endl;

   a.insertElem("abba");
   a.deleteElem("zorro");
   a.insertElem("sa");
   a.insertElem("aldo");
   a.deleteElem("a");
   std::cout << a << std::endl;
   try {
      a.deleteElem("a");
   } catch (elemNotFoundException e) {
      std::cout << "elemNotFoundException found" << std::endl;
   }

   sortedArrString c(a);
   std::cout << "fisso c" << std::endl;
   
   std::cout << "svuoto a" << std::endl;
   a.clear();
   std::cout << "a: " << a << std::endl;
   try {
      a.deleteElem("a");
   } catch (emptyException e) {
      std::cout << "emptyException found" << std::endl;
   }
   std::cout << "b: " << b << std::endl;
   std::cout << "c: " << c << std::endl;

   //testo costruttore secondario
   sortedArrString::reverse_iterator ib, ibe;
   ib = b.begin_r();
   ibe = b.end_r();

   std::cout << "costruttore secondario:" << std::endl;
   sortedArrString d(ib, ibe);
   std::cout << "d (=b): " << d << std::endl;
   d.insertElem("fitz");
   std::cout << "d: " << d << std::endl;
   
   //testo funtore esterno
   sortedArrString f = d.functor(functor_string());
   std::cout << "testo futore string \" lengh() >= 4 \"" << std::endl;
   std::cout << f << std::endl;
}

void testCustom() {
   point p1 = point(3.4,2);
   point p2 = point(-3.4,1);
   point p3 = point(7.0,-5);
   point p4 = point(2,2);
   point p5 = point(-1.5,7);
   
   typedef sortedArray<point, compare_point, equals_point> sortedArrPoint;

   sortedArrPoint a;

   a.insertElem(p1);
   a.insertElem(p2);
   a.insertElem(p3);
   a.insertElem(p4);
   a.insertElem(p5);
   a.insertElem(p1);
   a.insertElem(point(2,3));

   std::cout << "a: " << a << std::endl;

   a.deleteElem(p1);
   a.deleteElem(p3);
   a.insertElem(point(1,1));
   a.insertElem(point(1,1));

   sortedArrPoint::const_iterator i, ie; 
   i = a.begin();
   ie = a.end();
   

   std::cout << "a: " << a << std::endl;  

   sortedArrPoint b = a;
   sortedArrPoint c = b.functor(functor_point());
   
   std::cout << "b: " << b << std::endl;

   std::cout << "c generato applicando funtor in b - solo primo quadrante" << std::endl;
   std::cout << "c: " << c << std::endl;

   b.insertElem(point());

   std::cout << "b: " << b << std::endl;

   std::cout << "stampa tramite reverse iterator" << std::endl << "b: ";
   sortedArrPoint::reverse_iterator ir, ier;
   ir = b.begin_r();
   ier = b.end_r();
   
   for (; ir != ier; ++ir)
      std::cout << *ir << " ";
   std::cout << std::endl;


}

int main(){
   std::cout << "*** Test Insert ***" << std::endl;
   testInsert();
   std::cout << std::endl;
   std::cout << "*** Test Delete ***" << std::endl;
   testDelete();
   std::cout << std::endl;
   std::cout << "*** Test Custom ***" << std::endl;
   testCustom();
return 0;
}
