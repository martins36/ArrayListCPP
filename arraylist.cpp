/*
  ArrayList.cpp - Code for implement ArrayList in C++.
  Created by M. Macoritto, June 2, 2020.
  GNU General Public License (GPL) vesion 3.
*/

#include <iostream>

template <class T>
class ArrayList
{
public:
	ArrayList();
	void add(T element);
	void clear();
	T get(int index);
	bool isEmpty();
	void set(int index, T element);
	void show();
	void showDetail();
	int size();
private:
	template <class T>
	class Node
	{
	public:
		T value = NULL;
		Node* p_next = NULL;
	};
	int _size;
	Node<T>* _p_start;
	Node<T>* _p_end;
};

template<class T>
ArrayList<T>::ArrayList()
{
	_size = 0;
	_p_start = NULL;
	_p_end = NULL;
}

template <class T>
void ArrayList<T>::add(T element)
{
	if (isEmpty()) {
		_p_start = new Node<T>;
		_p_start->value = element;
		_p_end = _p_start;
	}
	else
	{
		_p_end->p_next = new Node<T>;
		_p_end = _p_end->p_next;
		_p_end->value = element;
	}
	_size++;
}

template<class T>
void ArrayList<T>::clear()
{
	_size = 0;
	delete[] _p_start;
	delete[] _p_end;
}

template<class T>
T ArrayList<T>::get(int index)
{
	Node<T>* p = _p_start;
	for (int i = 0; i < index; i++)
	{
		p = p->p_next;
	}
	return p->value;
	delete[] p;
}

template<class T>
bool ArrayList<T>::isEmpty()
{
	return _size == 0;
}

template<class T>
void ArrayList<T>::set(int index, T element)
{
	Node<T>* p = _p_start;
	for (int i = 0; i < index; i++)
	{
		p = p->p_next;
	}
	p->value = element;
}

template<class T>
void ArrayList<T>::show()
{
	Node<T>* p = _p_start;
	std::cout << "[ ";
	for (int i = 0; i < _size - 1; i++)
	{
		std::cout << p->value << ", ";
		p = p->p_next;
	}
	std::cout << p->value << " ] \n";
	delete [] p;
}

template<class T>
void ArrayList<T>::showDetail()
{
	Node<T>* p = _p_start;
	std::cout << "[ \n";
	for (int i = 0; i < _size; i++)
	{
		std::cout << "    (location: " << p << ", value: " << p->value
			<< ", point to: " << p->p_next << ")\n";
		p = p->p_next;
	}
	std::cout << "] \n";
	delete [] p;
}

template<class T>
int ArrayList<T>::size()
{
	return _size;
}

int main()
{
	ArrayList<int> arr;
	arr.add(3);
	arr.add(2);
	arr.show();
	arr.add(5);
	arr.showDetail();
}
