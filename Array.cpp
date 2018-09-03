// $Id: Array.cpp 820 2011-01-17 15:30:41Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
//default constructor
Array::Array (void)
{
	cur_size_=5;
	max_size_=10;
	data_[cur_size_];
}

/**
 * Initializing constructor.
 *
 * @param[in]	length	Initial size
 */
Array::Array (size_t length)
{
	cur_size_=length;
	max_size_=cur_size_ * 2;
	data_[cur_size_];
}

/**
 * Initializing constructor.
 *
 * @param[in]	length	Initial size
 * @param[in]	fill 	Initial value for each element
 */
Array::Array (size_t length, char fill)
{
	cur_size_=length;
	max_size_=cur_size_ * 2;
	data_[cur_size_];
	for(int i=0;i<cur_size_;++i)
	{
		data_[i]=fill;
	}
}

/**
 * Copy constructor
 *
 * @param[in]	arr	The source array
 */
Array::Array (const Array & array)
{

}

///Destructor
Array::~Array (void)
{

}

/**
 * Assignment operation
 *
 * @param[in]	rhs	Right-hand side of equal sign
 * @return 	Reference to self
 */
const Array & Array::operator = (const Array & rhs)
{

}

/**
 * Get the character at the specified index. If the index is not
 * within the range of the array, then std::out_of_range exception
 * is thrown.
 *
 * @param[in]	index	Zero-based location
 * @exception	std::out_of_range	Invalid /a index value
 */
char & Array::operator [] (size_t index)
{
	return data_[index];
}

/**
 * @overload
 *
 * The return character is not modifiable.
 */
const char & Array::operator [] (size_t index) const
{
	return data_[index];
}

/**
 * Get the character at the specified index. If the /a index is not within
 * the range of the array, then std::out_of_range exception is thrown.
 *
 * @param[in]	index	Zero-based location
 * @return	Character at /index
 * @exception 	std::out_of_range	Invalid index value
 */
char Array::get (size_t index) const
{
	return data_[index];
}

/**Set the character at the specified /a index. If the /a index is not
 * within range of the array, then std::out_of_range exception is
 * thrown.
 *
 * @oaram[in]	index	Zero-based location
 * @param[in]	value	New value for character
 * @exception	std::out_of_range	Invalid /a index value
 */
void Array::set (size_t index, char value)
{
	data_[index]=value;
}

/**
 * Set a new size for the array. If /a new_size is less than the current
 * size, then the array is truncated. If /a new_size if greater then the 
 * current size, then the array is made larger and the new elements are
 * not initialized to anything. If /a new_size is the same as the current
 * size, then nothing happens.
 *
 * The array's original contents are preserved regardless of whether the
 * array's size is either increased or decreased.
 *
 * @param[in]	new_size	New size of the array
 */
void Array::resize (size_t new_size)
{
	char new_data_[new_size];
	for(int i=0;i<cur_size_;++i)
	{
		new_data_[i]=data_[i];
	}
}

/**
 * Locate the specified character in the array. The index of the first
 * occurence of the character is returned. If the character is not
 * found in the array, then -1 is returned.
 *
 * @param[in]	ch	Character to search for
 * @return 	Index value of the character
 * @retval	-1	Character not found
 */
int Array::find (char ch) const
{
	
}

/**
 * @overload
 *
 * This version allows you to specify the start index of the search,If 
 * the start index is not within the range of the array, then the 
 * std::out_of_range exception is thrown.
 *
 * @param[in]	ch	Character to search for
 * @param[in]	start	Index to begin search
 * @return	Index value of first occurence
 * @retval	-1
 * @exception	std::out_of_range	Invalid index
 */
int Array::find (char ch, size_t start) const
{

}

/**
 * Test the array for inequality.
 *
 * @param[in]	rhs	Right hand size of equal to sign
 * @retval 	true	Left side is equal to right side
 * @retval	false	Left side is not equal to right side
 */
bool Array::operator == (const Array & rhs) const
{

}

/**
 * Test the array for inequality.
 *
 * @param[in]	rhs	Right-hand size of not equal sign
 * @retval 	true	Left side is not equal to right side
 * @retval	false	Left side is equal to right side
 */
bool Array::operator != (const Array & rhs) const
{

}

/**
 * Fill the contents of the array.
 *
 * @param[in]	ch	Fill character
 */
void Array::fill (char ch)
{

}

void Array::shrink (void)
{
  
}
///Reverse the contents of the array such that the first element is now
///the last element and the last element is the first element.
void Array::reverse (void)
{
  
}

/**
 * The slice() method returns a shallow copy of a portion of an array into 
 * a new array object selected from begin to end (end not included).
 * array will not be modified
 *
 * @param[in]	begin	The starting index
 * @return 	A new Array object
 */
Array Array::slice (size_t begin)const
{
  
}

/**
 * @overload
 *
 * @param[in]	begin	The starting index
 * @param[in]	end	The ending index
 * @return	A new Array object
 */
Array Array::slice (size_t begin, size_t end)const
{
  
}
