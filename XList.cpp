#pragma once
#include <exception>

#ifndef NULL
#define NULL nullptr
#endif


template <class T>
struct XLink {
	XLink * _next;
	XLink * _prev;
	T _data;
};

template <class T>
class XList{
public:
	class iterator;

	iterator begin()
	{
		return iterator(_head);
	};
	iterator end()
	{
		return iterator(_tail->_next);
	};

	XList<T>() : _head(NULL), _tail(NULL), _size(0) {};
	XList<T>(T data)
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
		while (toDel != NULL)
		{
			_head = _head->_next;
			delete toDel;
			toDel = _head;
		}
	};

	XLink<T> * addTail(const T data)
	{
		XLink<T> * elem = new XLink<T>();
		elem->_data = data;
		elem->_prev = _tail;
		elem->_next = NULL;

		if (_tail)
		{
			_tail = elem;
			_tail->_prev->_next = _tail;
		}
		else
		{
			_tail = elem;
			_head = elem;
		}
		++_size;

		return _tail;
	};
	XLink<T> * addHead(const T data)
	{
		XLink<T> * elem = new XLink<T>();
		elem->_data = data;
		elem->_prev = NULL;
		elem->_next = _head;

		if (_head)
		{
			_head = elem;
			_head->_next->_prev = _head;
		}
		else
		{
			_head = elem;
			_tail = elem;
		}
		
		++_size;

		return _head;
	};
	XLink<T> * delTail(void)
	{
		XLink<T> * toDel = _tail;
		
		_tail = _tail->_prev;
		_tail->_next = NULL;

		delete toDel;

		--_size;

		return _tail;
	};
	XLink<T> * delHead(void)
	{
		XLink<T> * toDel = _head;

		_head = _head->_next;
		_head->_prev = NULL;

		delete toDel;
		
		--_size;

		return _head;
	};

	T& getHead(void) const
	{
		if (_head == NULL)
			throw std::exception & Exception;
		return _head->_data;
	};
	T& getTail(void) const
	{
		if (_tail == NULL)
			throw std::exception & Exception;
		return _tail->_data;
	};

	unsigned short getSize(void) const
	{
		return _size;
	};

	bool isEmpty(void) const
	{
		return (_tail == NULL && _head == NULL)	
	};

	void clear(void)
	{
		XLink<T> * elem = this->_head;

		while (this->_head != NULL)
		{
			this->_head = this->_head->_next;
			delete elem;
			elem = this->_head;
		}

		this->_tail = NULL;
		this->_size = 0;
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
		iterator& operator++(int i) //i++
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
		iterator& operator--(int i) //i++
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
	XLink<T> * _head;
	XLink<T> * _tail;

	unsigned short _size;
};

