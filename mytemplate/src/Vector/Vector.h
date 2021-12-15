#pragma once
template<class T> class VectorT 
{
private:
	T* array;
	int size;
	int max_size;

public:
	VectorT();
	VectorT(int);
	~VectorT();
	//C A P A S I T Y
	bool isempty() const;
	int size() const;
	int max_size() const;
	int capacity() const;
	void reserve(int);

	//M O D I F I E R S
	void clear();
	void pushback(T&);
	//void popback();
	//void resize(int);

	// E L E M E N T   A C C E S S 
	T& at(int);
	T& operator[](int);
	T& front();
	T& back();
	T* data();

	//I T E R A T O R S
	friend class IteratorT<T>;
	friend class ConstIteratorT<T>;
	IteratorT begin() const
	{
		return IteratorT(array);
	}
	ConstIteratorT cbegin()
	{
		return IteratorT(array);
	}

	IteratorT end() const
	{
		return ConstIteratorT(size+array);
	}
	ConstIteratorT cend()
	{
		return ConstIteratorT(size + array);
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
		current++;
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
	T& operator*()
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
		current++;
		return *this;
	}
	ConstIteratorT& operator--()
	{
		--current;
		return *this;
	}
};
//C O N S T R U C T O R S
template<class T> VectorT<T>::VectorT() :
	size(0), max_size(1), array(newT[max_size]) {};

template<class T> VectorT<T>::VectorT(int msize) :
	size(0), max_size(msize), array(newT[max_size]) {};

template<class T> VectorT<T>::~VectorT()
{
	delete[] array;
}

//M O D I F I E R S
template<class T> void VectorT<T>::clear()
{
	delete[] array;
	size = 0;
	array = new T[max_size];
}
template<class T> void VectorT<T>::pushback(T& t)
{
	if (size == max_size)
		resize();
	size++;
	array[size] = t;
}


//C A P A S I T Y
template<class T> bool VectorT<T>::isempty() const
{
	return (size == 0);
}
template<class T> int VectorT<T>::capacity() const
{
	return (max_size - size);
}
template<class T> int VectorT<T>::max_size() const
{
	return (max_size);
}
template<class T> int VectorT<T>::size() const
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
		delete[] buffer;
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

