#ifndef GRAFO_H
#define GRAFO_H

#include <iterator> // std::forward_iterator_tag
#include <cstddef>  // std::ptrdiff_t
#include <iostream>

template<typename T>
class grafo {

private:
    //dichiaro l'array di nodi
    T *_vertici;
    //dichiaro matrice di adiacenza
    bool **_archi;

    //numero di nodi
    unsigned int n_vert;
    
public:

    grafo() : _vertici(0), _archi(0), n_vert(0) {}

    //fare copy constructor

    void insertNodo(const T &value) {
        bool same = false;
        //aggiungo in array nodo
        T* vert_aus = new T[n_vert+1];

        //controllo se vi e gia un nodo uguale
        for(int i=0; i < n_vert; i++) {
            if (value == _vertici[i]) {
                same = true;
            }
            vert_aus[i] = _vertici[i];
        }

        //aggiungo elemento in ultima posizione
        if (!same) {
            vert_aus[n_vert] = value;

            //aggiungo riga e colonna alla matrice di adiacenza
            //creo una matrice di appoggio
            bool **matr = new bool*[n_vert+1];
            for (int i =0; i < n_vert +1; i++) {
                matr[i] = new bool[n_vert+1];
                for (int j = 0; j < n_vert +1; j++)
                    matr[i][j] = false;
            }
            //copio la vecchia matrice di adiacenza in quella temporanea
            for(int i = 0; i < n_vert+1; ++i){
                for(int j = 0; j < n_vert+1; ++j){
                    if (i >= n_vert || j >= n_vert)
                        matr[i][j] == false;
                    else 
                        matr[i][j] = _archi[i][j];
                }
            }
            //elimino strutture vecchie
            clear();

            _vertici = vert_aus;
            _archi = matr;
            n_vert = n_vert+1;  
        } //end if
    } //end insertNodo

    //inserisco un arco che va da n1 a n2
    void insertArco(const T &n1, const T &n2){
        int idx1=-1, idx2 = -1;
        //cerco gli indici che corrispondono ai 2 nodi
        for(int i = 0; i < n_vert; ++i) {
            if (_vertici[i] == n1)
                idx1 = i;
            if (_vertici[i] == n2)
                idx2 = i;
        }
        //se non esiste nodo
        if (idx1 == -1 || idx2 == -1){
            std::cout << "nodo non esiste" << std::endl;
            return;
        }
        //se l'arco esiste gia' lo dico
        if (_archi[idx1][idx2]){
            std::cout << "L'arco esiste gia'" << std::endl;
        } else
        {
            _archi[idx1][idx2] = true;
            std::cout << "inserito" << std::endl;

        }
    }

    //elimina un nodo che corrisponde a value
    void deleteNodo(const T &value) {
        if (empty()) {
            std::cout << "grafo vuoto" << std::endl;
            return;
            //FAI L'ECCEZIONE
        }
        int index_del = 0;
        bool flag = false; //assumo che il nodo non ci sia
        for (int i=0; i < n_vert; ++i){
            if (_vertici[i] == value){
                index_del = i;
                flag = true;
            }
        }
        if (!flag) {
            std::cout << "nodo non presente" << std::endl;
            return;
        }
        //creo nuovo vettore di nodi e archi
        T* vet_aus = new T[n_vert-1];
        bool **matr = new bool*[n_vert-1];

        for (int i =0; i < n_vert -1; ++i) {
            matr[i] = new bool[n_vert-1];
        }
        int j = 0;
        //riempio nuovo vettore
        for (int i=0; i < n_vert; i++) {
            if (i != index_del){
                vet_aus[j] = _vertici[i];
                j++;
            }
        }
        
        int a = 0, b = 0;
        for (int i=0; i < n_vert; ++i) {
            if (i != index_del){
                for (int j=0; j < n_vert; ++j) {
                    if (j != index_del) {
                        matr[a][b] = _archi[i][j];
                        a++;
                    } 
                } //end for int
                b++; 
                a=0;  
            } //end if
        }//end for ext
        clear();
        _archi = matr;
        _vertici = vet_aus;
        n_vert--;
    } //end deleteNodo

    //cancella l'arco che va da n1 a n2
    void deleteArco(const T &n1, const T &n2){
        int idx1=-1, idx2 = -1;
        //cerco gli indici che corrispondono ai 2 nodi
        for(int i = 0; i < n_vert; ++i) {
            if (_vertici[i] == n1)
                idx1 = i;
            if (_vertici[i] == n2)
                idx2 = i;
        }
        //se non esiste nodo
        if (idx1 == -1 || idx2 == -1){
            std::cout << "nodo non esiste" << std::endl;
            return;
        }
        //se non c'era nessun arco
        if (_archi[idx1][idx2] == false)
            std::cout << "Non c'era nessun arco" << std::endl;
        else {
            _archi[idx1][idx2] = false;
            std::cout << "eliminato" << std::endl;
        }
    }

    int get_nvert(){
        return n_vert;
    }

    T get_nodo(int i){
        return _vertici[i]; 
    }
    bool get_arco(int i, int j){
        return _archi[i][j];
    }

    ~grafo(){
        clear();
    }

    //elimino le strutture dei nodi e matr di adiacenza
    void clear(){
        delete[] _vertici;
        for (int i=0; i < n_vert; ++i){
            delete[] _archi[i];
        }
        delete[] _archi;
    }

    //stabilisce se il grafo e' vuoto
    bool empty(){
        return n_vert == 0;
    }

    //const_iterator
    class const_iterator {
		//uso il puntatore al array di identificatori per passare la struttura dati
        const T* id; 

	public:
		typedef std::forward_iterator_tag iterator_category;
		typedef T                         value_type;
		typedef ptrdiff_t                 difference_type;
		typedef const T*                  pointer; //a parte questi 2 const è identica a quella sopra
		typedef const T&                  reference;

	
		const_iterator() : id(0){
		}
		
		const_iterator(const const_iterator &other) : id(other.id){
		}

		const_iterator& operator=(const const_iterator &other) {
			id = other.id;
            return *this;
		}

		~const_iterator() {
		}

		// Ritorna il dato riferito dall'iteratore (dereferenziamento)
		reference operator*() const {
			return id->value;
		}

		// Ritorna il puntatore al dato riferito dall'iteratore
		pointer operator->() const {
			return &(id->value);
		}
		
		// Operatore di iterazione post-incremento
		const_iterator operator++(int) {
			const_iterator tmp(*this);
            id = id++; //sposto il puntatore alla posizione successiva ?????
            return tmp;
		}

		// Operatore di iterazione pre-incremento
		const_iterator& operator++() {
			id = id++;
            return *this;
		}

		// Uguaglianza
		bool operator==(const const_iterator &other) const {
			return (id == other.id);
		}
		
		// Diversita'
		bool operator!=(const const_iterator &other) const {
			return (id != other.id);
		}

	private:
		//Dati membro

		// La classe container deve essere messa friend dell'iteratore per poter
		// usare il costruttore di inizializzazione.
		friend class grafo; 

		// Costruttore privato di inizializzazione usato dalla classe container
		// tipicamente nei metodi begin e end
		const_iterator(const T* ident) : id(ident) { 
			//???????????????
		}
		
		// !!! Eventuali altri metodi privati
		
	}; // classe const_iterator

    //Ritorna l'iteratore all'inizio della sequenza dati
	const_iterator begin() const {
		return const_iterator(_vertici);
	}
	
	// Ritorna l'iteratore alla fine della sequenza dati
	////////////////////////////////////////////
    // FAI PROVE SE HA SENSO QUESTO END
    /////////////////////////////////////////
    const_iterator end() const {
        if (n_vert != 0)
		    return const_iterator(_vertici[n_vert-1]);
        else
            return const_iteretor(_vertici);
	}

    void stampbool(bool** matr, int lung) {
        //std::cout << "stampo bool**" << std::endl;
        for (int i= 0; i < lung; ++i){
            for (int j =0; j < lung; ++j) {
                std::cout << matr[i][j] << " ";
            }
        std::cout << std::endl;
        }
    }

    void stampArchi() {
        std::cout << "MATRICE ADIACENZA:" << std::endl;
        stampbool(_archi, n_vert);   
    }

    void stampVertici() {
        std::cout << "NODI:" << std::endl;
        for (int i = 0; i < n_vert; ++i)
            std::cout << _vertici[i] << " ";
        std::cout << std::endl;
    }
};

// template<typename T>
// void printNodi(grafo<T> g) {
//     int n_nodi = g.get_nvert();
//         std::cout << "Num nodi: " << n_nodi << std::endl;
//         for(int i=0; i < n_nodi; i++) {
//             std::cout << g.get_nodo(i) << ", ";           
//         }
//         std::cout << std::endl;
//     }

// template<typename T>
// void printArchi(grafo<T> g) {
//     int n_nodi = g.get_nvert();
//     std::cout << "Matrice adiacenza: " << std::endl;
//     for(int i=0; i < n_nodi; i++) {
//         for(int j =0; j < n_nodi; j++){
//             //std::cout << "i,j: " << i << "," << j;
//             std::cout << g.get_arco(i,j) << " ";
//         }           
//         std::cout << std::endl;
//     }
//     std::cout << std::endl;
// }

// template<typename T>
// std::ostream &operator<<(std::ostream &os, const grafo<T> &gr) {
    
//     return os;
// }

#endif