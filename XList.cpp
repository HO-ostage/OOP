#pragma once
#include <exception>

#ifndef NULL
#define NULL nullptr
#endif

template <class T>
class XList{
public:
	class iterator;

	iterator begin() const
	{
		return iterator(_head);
	};
	iterator end() const
	{
		return iterator(_tail->_next);
	};

	XList<T>() : _head(NULL), _tail(NULL), _size(0) {};
	XList<T>(T& data)
	{
		XLink<T> * elem = new XLink<T>();
		elem->_data = data;
		elem->_prev = NULL;
		elem->_next = NULL;

		_head = _tail = elem;

		_size = 1;
	};

	~XList<T>()
	{
		XLink<T> * toDel = _head;
		while (toDel)
		{
			_head = _head->_next;
			delete toDel;
			toDel = _head;
		}
	};

	void addTail(const T& data)
	{
		XLink<T> * elem = new XLink<T>();
		elem->_data = data;
		elem->_prev = _tail;
		elem->_next = NULL;

		_tail = elem;

		if (!_head)
			_head = elem;
		else
			_tail->_prev->_next = _tail;

		++_size;
	};
	void addHead(const T& data)
	{
		XLink<T> * elem = new XLink<T>();
		elem->_data = data;
		elem->_prev = NULL;
		elem->_next = _head;

		_head = elem;

		if (!_tail)
			_tail = elem;
		else
			_head->_next->_prev = _head;
		
		++_size;
	};
	void delTail()
	{
		if (!_tail)
			throw std::exception("Tail == NULL");

		XLink<T> * toDel = _tail;
		
		if (_tail == _head)
			_head = _tail = NULL
		else
		{
			_tail = _tail->_prev;
			_tail->_next = NULL;
		}

		delete toDel;

		--_size;
	};
	void delHead()
	{
		if (!_head)
			throw std::exception("Head == NULL");

		XLink<T> * toDel = _head;

		if (_tail == _head)
			_head = _tail = NULL
		else
		{
			_head = _head->_next;
			_head->_prev = NULL;
		}

		delete toDel;

		--_size;
	};

	T& getHead() const
	{
		if (!_head)
			throw std::exception;
		return _head->_data;
	};
	T& getTail() const
	{
		if (!_tail)
			throw std::exception;
		return _tail->_data;
	};

	unsigned short getSize() const
	{
		return _size;
	};

	bool isEmpty() const
	{
		return _head;
	};

	void clear()
	{
		XLink<T> * elem = _head;

		while (_head)
		{
			_head = _head->_next;
			delete elem;
			elem = _head;
		}

		_tail = NULL;
		_size = 0;
	};

	class iterator
	{
	public:
		iterator(XLink<T> * p) : _elem(p) {};

		iterator& operator++()
		{
			_elem = _elem->_next;
			return * this;
		}
		iterator& operator++(int)
		{
			XLink<T> * tmp = _elem;
			
			_elem = _elem->_next;
			return * tmp;
		}
		iterator& operator--()
		{
			_elem = _elem->_prev;
			return *this;
		}
		iterator& operator--(int) 
		{
			XLink<T> * tmp = _elem;

			_elem = _elem->prev;
			return * tmp;
		}

		bool operator!=(const iterator& elem) const
		{
			return (_elem != elem._elem);
		}
		bool operator==(const iterator& elem) const
		{
			return (_elem == elem._elem)
		}

		T& operator*()
		{
			return _elem->_data;
		}

	private:
		XLink<T> * _elem;
	};

private:
	template <class T>
	struct XLink {
		XLink * _next;
		XLink * _prev;
		T _data;
	};

	XLink<T> * _head;
	XLink<T> * _tail;

	unsigned short _size;
};

