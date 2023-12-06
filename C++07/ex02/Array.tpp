/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:54:52 by jomirand          #+#    #+#             */
/*   Updated: 2023/12/06 10:08:37 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

template <class T>
Array<T>::Array() : _arraySize(0)
{
	_array = new T[_arraySize];
}

template <class T>
Array<T>::Array(unsigned int n) : _arraySize(n)
{
	_array = new T[n];
	for(unsigned int i = 0; i < n; i++)
		_array[i] = T();
}

template <class T>
Array<T>::Array(const Array& obj) : _arraySize(obj._arraySize)
{
	_array = new T[obj._arraySize];
	for(unsigned int i = 0; i < obj._arraySize; i++)
		_array[i] = obj._array[i];
}

template <class T>
Array<T>&	Array<T>::operator=(const Array& obj)
{
	if(this != obj)
	{
		delete [] _array;
		_arraySize = obj._arraySize;
		_array = new T[_arraySize];
		for(unsigned int i = 0; i < _arraySize; i++)
			_array[i] = obj._array;
	}
	return(*this);
}

template <class T>
Array<T>::~Array()
{
	if(_array)
		delete [] _array;
}

template <class T>
unsigned int	Array<T>::size() const
{
	return(_arraySize);
}

template <class T>
T&	Array<T>::operator[](unsigned int i)
{
	if(i >= _arraySize)
		throw IndexOutOfBounds();
	return(_array[i]);
}

#endif