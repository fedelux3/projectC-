#ifndef SORTEDARRAY_H
#define SORTEDARRAY_H

#include <iostream>
#include <iterator> //std::forward_iterator_tag, std::random_access_tag
#include <cstddef> //std::ptrdiff_t
#include "sortedException.h"

/**
 * Classe che definisce un array ordinato di elementi generici T (template). Gli oggetti sono ordinati
 * secondo un funtore definito dall'utente O e un funtore di uguaglianza E.
 * @short Classe sortedArray
 */
template<typename T, typename O, typename E>
class sortedArray {

   public:
      typedef unsigned int size_type;

   private:
      size_type _size; //numero di elementi dell'array
      T *_array; //puntatore a array
      O _isOrdered; //funtore di < per capire l'ordinamento
      E _equals; //funtore di uguaglianza

   public:

	/**
	 * Istanzia un sortedArray vuoto
	 * @short Costruttore di default
	 */ 
   sortedArray() : _array(0), _size(0) {}

   /**
     * Istanzia un sortedArray con gli attributi di un altro sortedArray. Lancia l'eccezione
     * bad_alloc se non viene istanziato correttamente l'array
     * @short Copy constructor
     * @param other sortedArray da inserire
     */
	sortedArray(const sortedArray &other): _array(0), _size(0) {
		T* tmp = other._array;
		size_type ns = other._size;

		try {
			for (size_type i=0; i < ns; ++i){
				insertElem(tmp[i]);
			}
		} catch (...) {
			clear();
			throw;
		}
	}

	/**
	 * Aggiunge al sortedArray tutti gli elementi che sono passati dai due iteratori generici
	 * in input, partendo dal primo fino al secondo. Se  vengono lanciate eccezioni internamente 
	 * lancia la clear del contenuto e rilancia l'eccezione.
	 * @short genera sortedArray da std::iterator
	 * @param i: iteratore di inizio
	 * @param ie: iteratore di fine
	 */
	template <typename iterator>
	sortedArray(iterator i, iterator ie): _array(0), _size(0) {
		try{
			for (; i != ie; ++i) {
				insertElem(static_cast<T>(*i));
			}
		} catch (...){
			clear();
			throw;
		}
	}

   /**
    * Ridefinisco l'operatore di assegnamento che sovrascrive il sortedArray this con i dati 
    * copiati dal sortedArray in input, sfruttando la funzione std::swap 
    * @short Operatore di assegnamento 
    * @param other sortedArray in input
    * @return reference a this
    */
	sortedArray& operator=(const sortedArray &other) {
		if (&other != this){
			sortedArray tmp(other);
			std::swap(tmp._array, _array);
			std::swap(tmp._size, _size);
		}
		return *this;
	}

	/**
    * Elimina l'array puntato dall'oggetto. Utile quando
    * si riaggionano i dati e quando si richiama il distruttore
    * @short Elimina i dati del grafo
    */
	void clear() {
         delete[] _array;
         _size = 0;
         _array = 0;
   }
	
	/**
   * Richiama la funzione clear() per eliminare l'array puntato
   * @short Distruttore
   */
   ~sortedArray(){
      clear();
   }

	/**
	 * Inserisce un elemento nel sortedArray riaggiornando la size e creando un nuovo array da puntare,
	 * in questo modo la memoria occupata risulta minima possibile.
	 * @short inserimento di un elemento
	 * @param elem reference da inserire
	 */ 
   void insertElem(const T &elem) {
		T *newArray = 0;
      	try{
			size_type newSize = _size+1;
			newArray = new T[newSize];
			
			//se array vuoto
			if (_size == 0) {
				newArray[0] = elem;
			}

			int j=0; //indice del nuovo array
			bool ins = false;

			typename sortedArray<T,O,E>::const_iterator i, ie;
			for(i = this->begin(), ie = this->end(); i!= ie; ++i) {
				//se elem < di *i
				if (_isOrdered(elem, *i) && !ins)
				{
					newArray[j] = elem;
					j++;
					newArray[j] = *i;
					j++;
					ins = true;
				} else {
					newArray[j] = *i;
					j++;
				}
				//caso in cui sono arrivato in fondo e non ho inserito l'elem
				if (i == ie-1 && !ins){
					newArray[j] = elem;
					j++;
				}
			}//end for
         //elimino strutture vecchie
         clear();

         _array = newArray;
         _size = newSize;
         
      	}//end try
      	catch (...) {
			delete[] newArray;
        	throw insertException("Exception insert"); 
      }
   }

	/**
	 * Elimina l'elemento passato in input (come reference). Verifica che il sortedArray non sia vuoto 
	 * e che l'elemento sia presente nella struttura altrimenti lancia rispettivamente una emptyException
	 * e una elemNotFoundException. Crea un nuovo array che contiene tutti gli elementi tranne quelli
	 * uguali a elem in input. Se genera eccezioni di memoria lancia una deleteException.
	 * @short eliminare un elemento uguale a quello in input
	 * @param elem reference da eliminare
	 */
	void deleteElem(const T &elem) {
		if (_size==0){
			throw emptyException("sortedArray vuoto");
		}
      	if (!exist(elem)) {
         	throw elemNotFoundException("elemento non trovato");
      	}
		size_type count = 0; //salva quanti valori di elem ho
		typename sortedArray<T,O,E>::const_iterator i, ie;
		for (i = this->begin(), ie = this->end(); i != ie; ++i){
			if (_equals(*i, elem)){
				count++;
			}
		}

		T *newArray = 0;
		try {
			size_type ns = _size - count;
			newArray = new T[ns];
			
			int j = 0;
			for (i = this->begin(), ie = this->end(); i != ie; ++i){
				if (!_equals(*i, elem)){
					newArray[j] = *i;
					j++;
				}
			}

			//pulisco la memoria
			clear();

			_array = newArray;
			_size = ns;

		} catch (...) {
			delete[] newArray;
			throw deleteException("errore delete elemento");
		}
   }

	/**
	 * Genera un nuovo sortedArray considerando solo gli elementi che rispettano il funtore di un solo 
	 * parametro passato in input. 
	 * @short genera nuovo sortedArray che rispetta condition
	 * @param condition funtore di un parametro
	 * @return sortedArray nuovo 
	 */
	template <typename F>
	sortedArray functor(F condition) {
		sortedArray<T,O,E> tmp;
		const_iterator i, ie;
	
		for(i = begin(), ie = end(); i != ie; ++i) {
			if (condition(*i)) {
				tmp.insertElem(*i);
			}
		}

		return tmp;
	}
   
	/**
	 * Valuta se l'elemento passato in input sia o meno presente (almeno uno) nel sortedArray,
	 * sfrutta il funtore E per ricercarlo.
	 * @short esiste elemento
	 * @param elem reference da ricercare
	 * @return true se elem e' presente
	 * @return false altrimenti
	 */
   	bool exist(const T &elem) const {
		typename sortedArray<T,O,E>::const_iterator i, ie;
      	for (i = this->begin(), ie = this->end(); i != ie; ++i) {
         	if (_equals(*i, elem))
            	return true;
      	}
     	return false;
   	}

   //random access iterator const
    class const_iterator {
		//	
	public:
		typedef std::random_access_iterator_tag iterator_category;
		typedef T                        value_type;
		typedef ptrdiff_t                difference_type;
		typedef const T*                 pointer;
		typedef const T&                 reference;

	
		const_iterator(): ptr(0) {
		}
		
		const_iterator(const const_iterator &other): ptr(other.ptr) {
		}

		const_iterator& operator=(const const_iterator &other) {
			ptr = other.ptr;
         return *this;
		}

		~const_iterator() {
		}

		// Ritorna il dato riferito dall'iteratore (dereferenziamento)
		reference operator*() const {
			return *ptr;
		}

		// Ritorna il puntatore al dato riferito dall'iteratore
		pointer operator->() const {
			return ptr;
		}

		// Operatore di accesso random
		reference operator[](int index) {
         return ptr[index];
			
		}
		
		// Operatore di iterazione post-incremento
		const_iterator operator++(int) {
		 const_iterator tmp(*this);
         ptr++;
         return tmp;
		}

		// Operatore di iterazione pre-incremento
		const_iterator &operator++() {
         ++ptr;
         return *this;
		}

		// Operatore di iterazione post-decremento
		const_iterator operator--(int) {
			const_iterator tmp(*this);
         ptr--;
         return tmp;
		}

		// Operatore di iterazione pre-decremento
		const_iterator &operator--() {
         --ptr;
         return *this;
		}

		// Spostamentio in avanti della posizione
		const_iterator operator+(int offset) {
			const_iterator tmp(*this);
         tmp.ptr = tmp.ptr + offset;
         return tmp;
		}

		// Spostamentio all'indietro della posizione
		const_iterator operator-(int offset) {
			const_iterator tmp(*this);
         tmp.ptr = tmp.ptr - offset;
         return tmp;
		}
		
		// Spostamentio in avanti della posizione
		const_iterator& operator+=(int offset) {
			ptr = ptr + offset;
         return *this;
		}

		// Spostamentio all'indietro della posizione
		const_iterator& operator-=(int offset) {
			ptr = ptr - offset;
         return *this;
		}

		// Numero di elementi tra due iteratori
		difference_type operator-(const const_iterator &other) {
			return ptr - other.ptr;
		}
	
		// Uguaglianza
		bool operator==(const const_iterator &other) const {
			return ptr == other.ptr;
		}

		// Diversita'
		bool operator!=(const const_iterator &other) const {
			return ptr != other.ptr;
		}

		// Confronto
		bool operator>(const const_iterator &other) const {
			return ptr > other.ptr;
		}
		

		bool operator>=(const const_iterator &other) const {
			return ptr >= other.ptr;
		}

		// Confronto
		bool operator<(const const_iterator &other) const {
			return ptr < other.ptr;
		}
		
		
		// Confronto
		bool operator<=(const const_iterator &other) const {
			return ptr <= other.ptr;
		}
		
	private:
		//Dati membro
      const T *ptr;
		// La classe container deve essere messa friend dell'iteratore per poter
		// usare il costruttore di inizializzazione.
		friend class sortedArray; // !!! Da cambiare il nome!

		// Costruttore privato di inizializzazione usato dalla classe container
		// tipicamente nei metodi begin e end
		const_iterator(const T* p): ptr(p) { 
		}
		
		// !!! Eventuali altri metodi privati
		
	}; // classe const_iterator
	
	// Ritorna l'iteratore all'inizio della sequenza dati
	const_iterator begin() const {
		return const_iterator(_array);
	}
	
	// Ritorna l'iteratore alla fine della sequenza dati
	const_iterator end() const {
		return const_iterator(_array + _size);
	}

	//REVERSE FORWARD ITERATOR
    class reverse_iterator {
		//	
	public:
		typedef std::forward_iterator_tag iterator_category;
		typedef T                         value_type;
		typedef ptrdiff_t                 difference_type;
		typedef const T*                  pointer; //a parte questi 2 const è identica a quella sopra
		typedef const T&                  reference;

	
		reverse_iterator() : ptr(0){}
		
		reverse_iterator(const reverse_iterator &other) : ptr(other.ptr){
		}

		reverse_iterator& operator=(const reverse_iterator &other) {
			ptr = other.ptr;
			return *this;
		}

		~reverse_iterator() {
		}

		// Ritorna il dato riferito dall'iteratore (dereferenziamento)
		reference operator*() const {
			return *ptr;
		}

		// Ritorna il puntatore al dato riferito dall'iteratore
		pointer operator->() const {
			return ptr;
		}
		
		// Operatore di iterazione post-incremento
		reverse_iterator operator++(int) {
			return reverse_iterator(ptr--);
		}

		// Operatore di iterazione pre-incremento
		reverse_iterator& operator++() {
			--ptr;
			return *this;
		}

		// Uguaglianza
		bool operator==(const reverse_iterator &other) const {
			return (ptr == other.ptr);
		}
		
		// Diversita'
		bool operator!=(const reverse_iterator &other) const {
			return (ptr != other.ptr);
		}
		
	private:
		//Dati membro
		const T* ptr;
		// La classe container deve essere messa friend dell'iteratore per poter
		// usare il costruttore di inizializzazione.
		friend class sortedArray; // !!! Da cambiare il nome!

		// Costruttore privato di inizializzazione usato dalla classe container
		// tipicamente nei metodi begin e end
		reverse_iterator(const T* sa) : ptr(sa) { 
		}
		
		// !!! Eventuali altri metodi privati
		
	}; // classe const_iterator
	
	// Ritorna l'iteratore all'inizio della sequenza dati
	reverse_iterator begin_r() const {
		return reverse_iterator(_array + _size-1);
	}
	
	// Ritorna l'iteratore alla fine della sequenza dati
	reverse_iterator end_r() const {
		return reverse_iterator(_array-1);
	}
};

template<typename T, typename O, typename E>
std::ostream &operator<<(std::ostream &os, const sortedArray<T,O,E> &sa) {
   typename sortedArray<T,O,E>::const_iterator i, ie;
   i = sa.begin();
   ie = sa.end();

	for (; i != ie; ++i)
		os << *i << " ";
		
	return os;
}

#endif
