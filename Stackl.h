#pragma once

template <typename T>
class Stackl
{
	struct Node
	{
		Node(const T& _obj, Node* _next) : obj(_obj), next(_next) {}
		T obj;
		Node* next;
	};
	
	Node* _top;
	size_t _size;
public:
	Stackl() : _top(nullptr), _size(0) {}
	
	bool empty() const { return _size == 0; }
	size_t size() const { return _size; }

	void push(const T& obj) {

		_top = new Node(obj, _top);
		_size++;
	}

	void pop() {
		Node* tmp = _top->next;
		delete _top;
		_top = tmp;
		_size--;
	}

	T& top() { return _top->obj; }

	~Stackl() {
		while(!empty())
			pop();
	}
};