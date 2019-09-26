#pragma once

template <typename T>
class Stackmm
{
	size_t _size;
	size_t _capacity;
	T* _elements;
	
	void realloc(size_t capacity) {
		_capacity = capacity;
		T* tmp = new T[_capacity];
		memcpy(tmp, _elements, _size * sizeof(T));
		delete[] _elements;
		_elements = tmp;
	}
	
public:
	Stackmm() : _size(0), _capacity(2), _elements(new T[_capacity]) {}
	size_t size() const { return _size; }
	bool empty() const { return _size == 0; }

	void push(const T& obj) {
		if (_size == _capacity) {
			realloc(_capacity *= 2);
		}
		_elements[_size++] = obj;
	}

	void pop() {
		if(_capacity > 4 * _size--)
			realloc(_capacity /= 2);
	}

	T& top() { return _elements[_size - 1]; }

	~Stackmm() { delete[] _elements; }
};
