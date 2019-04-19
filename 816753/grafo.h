#ifndef GRAFO_H
#define GRAFO_H

#include <iterator> // std::forward_iterator_tag
#include <cstddef>  // std::ptrdiff_t
#include <iostream>
#include "grafoexception.h"

/**
 * Classe che definisce una struttura a grafo con nodi e archi. La tipologia di nodo e' template.
 * @short Classe Grafo
 */
template<typename T>
class grafo {

private:

    T *_vertici; //array dei nodi
    bool **_archi; //matrice di adiacenza
    unsigned int n_vert; //numero dei nodi
    
    /**
     * Elimina le strutture puntate dal grafo: array dei nodi, matrice di adiacenza. Utile quando
     * si riaggionano i dati e quando si richiama il distruttore
     * @short Elimina i dati del grafo
     */
    void clear(){
        delete[] _vertici;
        for (int i=0; i < n_vert; ++i){
            delete[] _archi[i];
        }
        delete[] _archi;
    }

    /**
     * Restituisce l'indice del nodo che corrisponde al valore value. Lancia una nodeNotFoundException
     * se il nodo cercato non esiste
     * @short Indice del nodo
     * @param value di tipo T da cercare nel grafo
     * @return int che corrispondente all'indice del nodo
     */
    int get_index(const T value) const{
        if (!exists(value)){
            throw nodeNotFoundException("");
        }
        typename grafo<T>::const_iterator i, ie;
        int pos = 0;
        i = this->begin();
        ie = this->end();
        while(!(*i == value) || i == ie) {
            pos++;
            i++;
        }
        return pos;
    }
public:

    /**
     * Istanzia un grafo vuoto
     * @short Costruttore di default
     */
    grafo() : _vertici(0), _archi(0), n_vert(0) {}

    /**
     * Istanzia un grafo con gli attributi di un altro grafo. Lancia l'eccezione
     * bad_alloc se non vengono istanziate correttamente il vettore e la matrice 
     * @short Copy constructor
     * @param other grafo da inserire
     */
    grafo(const grafo &other): _vertici(0), _archi(0), n_vert(0) {
        T* tmp = other._vertici;
        bool** matr = other._archi;
        int tmp_vert = other.n_vert;

        try {
            for (int i = 0; i < tmp_vert; i++) {
                insertNodo(tmp[i]);
            }
            for (int i = 0; i < n_vert; ++i) {
                for (int j = 0; j < n_vert; ++j) {
                    _archi[i][j] = matr[i][j];
                }
            }
        } catch (std::bad_alloc &e) {
            clear();
            throw;
        }
    }

    /**
    * Ridefinisco l'operatore di assegnamento che sovrascrive il grafo this con i dati 
    * copiati dal grafo in input
    * @short Operatore di assegnamento 
    * @param other grafo n input
    * @return reference a this
    */
    grafo& operator=(const grafo &other){
        if(&other != this){
            grafo tmp(other);
            std::swap(tmp._vertici, _vertici);
            std::swap(tmp._archi, _archi);
            std::swap(tmp.n_vert, n_vert);
        }
        return *this;
    }
    /**
     * Inserisce un nodo del valore passato in input, aggiornando il vettore dei nodi
     * e la matrice degli archi, aggiungendovi una riga e una colonna
     * @short inserisce un nodo
     * @param value reference da aggiungere nel grafo
     */
    void insertNodo(const T &value) {

        //controllo se nodo esiste gia'
        if (!exists(value)) {
            //aggiungo in array nodo
            T* vert_aus = new T[n_vert+1];

            //copio vecchio vettore in quello nuovo
            for(int i=0; i < n_vert; i++) {
                vert_aus[i] = _vertici[i];
            }
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
        else 
        {
            throw nodeDuplicateException("");
        }
    } //end insertNodo

    /**
     * Inserisco un arco che va da n1 a n2 modificando la matrice di adiacenza nelle
     * coordinate dei due nodi. Lancia eccezione nodeNotFoundException se uno dei due nodi
     * non e' presente nel grafo, lancia una edgeException se l'arco esiste gia'. 
     * @short inserisco un arco
     * @param n1 reference al nodo partenza
     * @param n2 reference al nodo destinazione
     */
    void insertArco(const T &n1, const T &n2){
        
        if (!exists(n1) || !exists(n2)){
            throw nodeNotFoundException("");
        }
        //se l'arco esiste gia'
        if (hasEdge(n1,n2)){
            throw edgeException("");
        } else
        {   
            //cerco gli indici che corrispondono ai 2 nodi
            int idx1, idx2;
            idx1 = get_index(n1);
            idx2 = get_index(n2);
        
            _archi[idx1][idx2] = true;
        }
    }

    /**
     * Elimina nodo che corrisponde al valore in input. Lancia una emptyException se il grafo
     * risulta essere vuoto, lancia una nodeNotFoundException se non viene trovato il nodo considerato
     * @short elimina nodo
     * @param value reference da eliminare
     */
    void deleteNodo(const T &value) {
        if (empty()) {
            throw emptyException("");
        }
        if (!exists(value)) {
            throw nodeNotFoundException("");
        }

        int index_del = get_index(value);

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

    /**
     * Elimina arco che va da n1 a n2. Lancia un eccezione nodeNotFoundException se uno dei
     * due nodi non appartiene al grafo, lancia edgeNotFoundException se non viene trovato 
     * l'arco richiesto
     * @short elimina arco da n1 a n2
     * @param n1 reference a nodo partenza
     * @param n2 reference a nodo destinazione
     */
    void deleteArco(const T &n1, const T &n2){
        
        if (!exists(n1) || !exists(n2)){
            throw nodeNotFoundException("");
        }
        int idx1, idx2;
        idx1 = get_index(n1);
        idx2 = get_index(n2);

        //se c'era l'arco
        if (hasEdge(n1,n2))
            _archi[idx1][idx2] = false;
        
    }

    /**
     * Valuta se esiste gia' un nodo con lo stesso valore di value. Restituisce un boolean
     * @short Esiste il nodo
     * @param value di tipo template
     * @return true se il nodo esiste
     * @return false se nodo non esiste
     */
    bool exists(const T value) const{
        typename grafo<T>::const_iterator i, ie;
    
        for (i=this->begin(), ie =this->end(); i!=ie; ++i) {
            if (*i == value)
                return true;
        }
        return false;
    }

    /**
     * Valuta se esiste gia' un arco tra il nodo di valore 'val1' e il nodo con valore 'val2'. Controllando
     * prima se i nodi in questione esistono
     * @short Esiste l'arco 
     * @param val1 valore del nodo di partenza
     * @param val2 valore del nodo di destinazione
     * @return true se l'arco esiste
     * @return false se l'arco non esiste
     */
    bool hasEdge(const T val1, const T val2) {
        if (exists(val1) && exists(val2)) {
            //cerco gli indici che corrispondono ai 2 nodi
            int idx1, idx2;
            idx1 = get_index(val1);
            idx2 = get_index(val2);

            return _archi[idx1][idx2];
        }
        return false;
    }

    /**
     * Restituisce il numero di nodi del grafo
     * @short Numero nodi
     * @return unsigned int del numero dei vertici
     */ 
    unsigned int get_nvert() const{
        return n_vert;
    }

    /**
     * Restituisce il numero di archi presente nel grafo
     * @short Numero archi
     * @return unsigned int del numero di archi
     */
    unsigned int get_narchi() const{
        unsigned int narchi = 0;
        for (int i = 0; i < n_vert; ++i) {
            for (int j = 0; j < n_vert; ++j) {
                if (_archi[i][j])
                    narchi++;
            }
        } 
        return narchi;
    }

    /**
     * Restituisce il valore dell'arco che si trova nella matice di adiacenza in
     * posizione di indice i,j. Restituisce una edgeNotFoundException se gli indici non sono
     * interni alla matrice
     * @short Valore dell'arco
     * @param i e' indice dell'arco di partenza
     * @param j e' indice dell'arco di destinazione
     * @return true se l'arco esiste
     * @return false se l'arco non esistes
     */ 
    bool get_arco(unsigned int i, unsigned int j) const{
        if (i >= n_vert || j >= n_vert){
            throw edgeNotFoundException("index out of bounds");
        }
        return _archi[i][j];
    }
    
    /**
     * Richiama la funzione clear() per eliminare le strutture del grafo
     * @short Distruttore
     */
    ~grafo(){
        clear();
    }

    /**
     * Controlla se il grafo e' vuoto, ovvero se ha numero dei nodi pari a 0
     * @short Grafo vuoto
     * @return true se e' vuoto
     * @return false se arco non e' vuoto
     */
    bool empty() const{
        return n_vert == 0;
    }

    //const_iterator
class const_iterator {

	public:
		typedef std::forward_iterator_tag iterator_category;
		typedef T                         value_type;
		typedef ptrdiff_t                 difference_type;
		typedef const T*                  pointer; 
		typedef const T&                  reference;

	
		const_iterator() : array(0) {
		}
		
		const_iterator(const const_iterator &other) : array(other.array) {
		}

		const_iterator& operator=(const const_iterator &other) {
			array = other.array;
            return *this;
		}

		~const_iterator() {
		}

		// Ritorna il dato riferito dall'iteratore (dereferenziamento)
		reference operator*() const {
			return *array;
		}

		// Ritorna il puntatore al dato riferito dall'iteratore
		pointer operator->() const {
			return array;
		}
		
		// Operatore di iterazione post-incremento
		const_iterator operator++(int) {
			return const_iterator(array++);
		}

		// Operatore di iterazione pre-incremento
		const_iterator& operator++() {
			++array;
            return *this;
		}

		// Uguaglianza
		bool operator==(const const_iterator &other) const {
			return (array == other.array);
		}
		
		// Diversita'
		bool operator!=(const const_iterator &other) const {
			return (array != other.array);
		}

	private:
		//Dati membro
        const T* array;
		// La classe container deve essere messa friend dell'iteratore per poter
		// usare il costruttore di inizializzazione.
		friend class grafo; 

		// Costruttore privato di inizializzazione usato dalla classe container
		// tipicamente nei metodi begin e end
		const_iterator(const T* ident) : array(ident) {}
		
		// !!! Eventuali altri metodi privati
		
	}; // classe const_iterator

    //Ritorna l'iteratore all'inizio della sequenza dati
	const_iterator begin() const {
		return const_iterator(_vertici);
	}
	
	// Ritorna l'iteratore alla fine della sequenza dati
    const_iterator end() const {
	    return const_iterator(_vertici + n_vert);
	}
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const grafo<T> &graph) {
    typename grafo<T>::const_iterator i, ie;

    os << "Nodi: ";

    for(i = graph.begin(), ie = graph.end(); i != ie; ++i) {
        os << *i << " ";
    }
    os << std::endl;

    os << "Archi: " << std::endl;
    
    for (unsigned int i= 0; i < graph.get_nvert(); ++i){
        for (unsigned int j =0; j < graph.get_nvert(); ++j) {
            os << graph.get_arco(i,j) << " ";
        }
    os << std::endl;
    }

    return os;
}

#endif