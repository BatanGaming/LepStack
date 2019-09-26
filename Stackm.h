#pragma once
const size_t _max_size = 50000;

template <typename T>
class Stackm
{
	T* _elements;
	size_t _size;
public:
	Stackm(size_t size = _max_size) : _elements(new T[size]), _size(0) {}
	size_t size() const { return _size; }
	bool empty() const { return _size == 0; }
	
	void push(const T& obj) { _elements[_size++] = obj; }

	void pop() { --_size; }
	
	T& top() { return _elements[_size - 1]; }
	
	~Stackm() { delete[] _elements; }
};

