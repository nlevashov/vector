#ifndef _MYVECTOR

#define _MYVECTOR

#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

//const & in =
//небазовые типы

namespace myvector {
	template <typename T = double>
	class vector {
		private:
			T * _begin;
			size_t _size, _memory;

		public:
			vector();
			vector(size_t);
			vector(const vector &);
			template <typename U> vector(const vector<U> &);
			~vector();

			size_t size() const { return _size; }
			size_t memory() const { return _memory; }

			vector operator = (const vector &);
			template <typename U> vector operator = (const vector<U> &);
			T & operator [] (size_t i);
			T operator () (size_t i) const;
			void resize(size_t n);
	};

	template <typename T>
	vector<T> :: vector() : _memory(64), _size(0)
	{
		_begin = new T[64];
	}

	template <typename T>
	vector<T>::vector(size_t n) : _memory(n), _size(0)
	{
		_begin = new T[n];
	}

	template <typename T>
	vector<T>::vector(const vector & v)
	{
		_begin = new T[v.memory()];
		_memory = v.memory();
		_size = v.size();
		for (size_t i = 0; i < _size; i++) _begin[i] = v(i);
	}

	template <typename T>
	template <typename U>
	vector<T>::vector(const vector<U> & v)
	{
		_begin = new T[v.memory()];
		_memory = v.memory();
		_size = v.size();
		for (size_t i = 0; i < _size; i++) _begin[i] = v(i);
	}

	template <typename T>
	vector<T>::~vector()
	{
		if (_begin) delete [] _begin;
	}

	template <typename T>
	vector<T> vector<T>::operator = (const vector & v)
	{
		if (_begin) delete [] _begin;
		_begin = new T[v.memory()];
		_memory = v.memory();
		_size = v.size();
		for (size_t i = 0; i < _size; i++) _begin[i] = v(i);
		return *this;
	}

	template <typename T>
	template <typename U>
	vector<T> vector<T>::operator = (const vector<U> & v)
	{
		if (_begin) delete [] _begin;
		_begin = new T[v.memory()];
		_memory = v.memory();
		_size = v.size();
		for (size_t i = 0; i < _size; i++) _begin[i] = v(i);
		return *this;
	}

	template <typename T>
	T & vector<T>::operator [] (size_t i)
	{
		if (i >= _size) {
			_size = i + 1;
			if (i >= _memory) {
				while (_memory <= i) _memory <<= 2;
				_begin = (T *) realloc(_begin, sizeof(T) * _memory);
			}
		}
		return _begin[i];
	}

	template <typename T>
	T vector<T>::operator () (size_t i) const
	{
		if (i < _size) return _begin[i];
	}

	template <typename T>
	void vector<T>::resize(size_t n)
	{
		_begin = (T *) realloc(_begin, sizeof(T) * n);
		_memory = n;
		if (_size > n) _size = n;
	}
}

#endif
