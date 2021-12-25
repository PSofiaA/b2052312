#pragma once
#include <initializer_list>
#define CNST 5
template<class T> class IteratorT;
template<class T> class ConstIteratorT;

template<class T> class VectorT
{
private:
	int _size;
	int _capacity;
	T* array;

public:
	VectorT();
	VectorT(int);
	VectorT(std::initializer_list<T> list);
	~VectorT();
	
	//O P E R A T O R S
	bool operator==(const VectorT<T>&);
	bool operator!=(const VectorT<T>&);

	//C A P A C I T Y
	bool empty() const;
	int size() const;
	int capacity() const;
	void reserve(int);

	//M O D I F I E R S
	void clear();
	void pushback(const T&);
	//void popback();

	// E L E M E N T   A C C E S S 
	T& at(int);
	T& operator[](int);
	T& front();
	T& back();
	T* data();

	//I T E R A T O R S
	friend class IteratorT<T>;
	friend class ConstIteratorT<T>;

	typedef IteratorT<T> Iterator;
	Iterator begin() const
	{
		return Iterator(array);
	}
	Iterator end() const
	{
		return Iterator(_size + array);
	}
	typedef ConstIteratorT<T> ConstIterator;
	ConstIterator cbegin()
	{
		return ConstIterator(array);
	}
	ConstIterator cend()
	{
		return ConstIterator(_size + array);
	}
};

//I T E R A T O R S
template<class T> class IteratorT
{
private:
	T* current;
public:
	IteratorT() : current(0) {};
	IteratorT(T* t) : current(t) {};

	T& operator*() const
	{
		return *current;
	}
	bool operator ==(const IteratorT& check) const
	{
		return *current == *check.current;
	}
	bool operator !=(const IteratorT& check) const
	{
		return *current != *check.current;
	}
	IteratorT& operator++()
	{
		++current;
		return *this;
	}
	IteratorT& operator--()
	{
		--current;
		return *this;
	}
};

template<class T> class ConstIteratorT
{
private:
	const T* current;
public:
	ConstIteratorT() : current(0) {};
	ConstIteratorT(T* t) : current(t) {}
	const T& operator*()
	{
		return *current;
	}
	bool operator ==(const ConstIteratorT& check) const
	{
		return *current == *check.current;
	}
	bool operator !=(const ConstIteratorT& check) const
	{
		return *current != *check.current;
	}
	ConstIteratorT& operator++()
	{
		++current;
		return *this;
	}
	ConstIteratorT& operator--()
	{
		--current;
		return *this;
	}
};

//O P E R A T O R S
	template<class T> bool VectorT<T>::operator==(const VectorT<T>& that)
{
	for (int i = 0; i < this->_capacity; i++)
	{
		if (array[i] != that.array[i])
			return false;
	}
}
template<class T> bool VectorT<T>::operator!=(const VectorT<T>& that)
{
	for (int i = 0; i < this->_capacity; i++)
	{
		if (array[i] != that.array[i])
			return true;
	}
}

//C O N S T R U C T O R S
template<class T> VectorT<T>::VectorT() :
	_capacity(0), _size(0), array(nullptr) {};

template<class T> VectorT<T>::VectorT(int msize) :
	_capacity(msize), _size(0), array(new T[_capacity]) {};

template<class T> VectorT<T>::~VectorT()
{
	delete[] array;
}

template<class T> VectorT<T>::VectorT(std::initializer_list<T> list) :
	_size(list.size()),
	_capacity(this->_size + CNST),
	array(new T[_capacity])
{
	int i = 0;
	for (auto value : list)
	{
		array[i] = value;
		i++;
	}
};

//M O D I F I E R S
template<class T> void VectorT<T>::clear()
{
	delete[] array;
	_size = 0;
	array = new T[_capacity];
}
template<class T> void VectorT<T>::pushback(const T& t)
{
	if (_size == _capacity && _capacity != 0 )
	{
		T* buffer = new T[this->_capacity + CNST];
		for (int i = 0; i < _size; i++)
		{
			buffer[i] = array[i];
		}
		delete[] array;
		array = buffer;
	}
	if (_capacity == 0)
	{
		this->_capacity = CNST;
		this->array = new T[CNST];
	}
	_size++;
	array[_size] = t;
}


//C A P A S I T Y
template<class T> bool VectorT<T>::empty() const
{
	return (_size == 0);
}
template<class T> int VectorT<T>::capacity() const
{
	return (_capacity);
}
template<class T> int VectorT<T>::	size() const
{
	return (_size);
}
template<class T> void VectorT<T>::reserve(int s)
{
	if (s > _capacity)
	{
		T* buffer = new T[s];
		for (int i = 0; i < _size; i++)
		{
			buffer[i] = array[i];
		}
		delete[] array;
		array = buffer;
		_capacity	 = s;
	}
}

// E L E M E N T   A C C E S S 
template<class T> T& VectorT<T>::at(int index)
{
	if (index >= _size)
		throw std::logic_error("Incorrect index!");
	return array[index];
}
template<class T>T& VectorT<T>::operator[](int index)
{
	return array[index];
}
template<class T> T& VectorT<T>::front()
{
	return array[0];
}
template<class T> T& VectorT<T>::back()
{
	return array[_size - 1];
}
template<class T> T* VectorT<T>::data()
{
	return array;
}

