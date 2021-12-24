#pragma once
#include <initializer_list>
template<class T> class IteratorT;
template<class T> class ConstIteratorT;

template<class T> class VectorT
{
private:
	int size;
	int max_size;
	T* array;

public:
	VectorT();
	VectorT(int);
	VectorT(std::initializer_list<T> list);
	~VectorT();
	
	//O P E R A T O R S
	//T& operator= (const T&); 
	bool operator==(const VectorT<T>&);
	bool operator!=(const VectorT<T>&);

	//C A P A C I T Y
	bool empty() const;
	int ñsize() const;
	int maxsize() const;
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
		return Iterator(size + array);
	}
	typedef ConstIteratorT<T> ConstIterator;
	ConstIterator cbegin()
	{
		return ConstIterator(array);
	}
	ConstIterator cend()
	{
		return ConstIterator(size + array);
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
	for (int i = 0; i < this->max_size; i++)
	{
		if (array[i] != that.array[i])
			return false;
	}
}
template<class T> bool VectorT<T>::operator!=(const VectorT<T>& that)
{
	for (int i = 0; i < this->max_size; i++)
	{
		if (array[i] != that.array[i])
			return true;
	}
}

//C O N S T R U C T O R S
template<class T> VectorT<T>::VectorT() :
	max_size(1), size(0), array(new T[max_size]) {};

template<class T> VectorT<T>::VectorT(int msize) :
	max_size(msize), size(0), array(new T[max_size]) {};

template<class T> VectorT<T>::~VectorT()
{
	delete[] array;
}

template<class T> VectorT<T>::VectorT(std::initializer_list<T> list) :
	size(list.size()),
	max_size(this->size + 5),
	array(new T[max_size])
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
	size = 0;
	array = new T[max_size];
}
template<class T> void VectorT<T>::pushback(const T& t)
{
	if (size == max_size)
	{
		T* buffer = new T[this->max_size + 5];
		for (int i = 0; i < size; i++)
		{
			buffer[i] = array[i];
		}
		delete[] array;
		array = buffer;
	}
	size++;
	array[size] = t;
}


//C A P A S I T Y
template<class T> bool VectorT<T>::empty() const
{
	return (size == 0);
}
template<class T> int VectorT<T>::capacity() const
{
	return (max_size - size);
}
template<class T> int VectorT<T>::maxsize() const
{
	return (max_size);
}
template<class T> int VectorT<T>::ñsize() const
{
	return (size);
}
template<class T> void VectorT<T>::reserve(int s)
{
	if (s > max_size)
	{
		T* buffer = new T[s];
		for (int i = 0; i < size; i++)
		{
			buffer[i] = array[i];
		}
		delete[] array;
		array = buffer;
		max_size = s;
	}
}

// E L E M E N T   A C C E S S 
template<class T> T& VectorT<T>::at(int index)
{
	if (index >= size)
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
	return array[size - 1];
}
template<class T> T* VectorT<T>::data()
{
	return array;
}

