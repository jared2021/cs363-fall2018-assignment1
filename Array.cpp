// $Id: Array.cpp 820 2011-01-17 15:30:41Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
#include <stdexcept>
//default constructor
Array::Array (void)
// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.
// RESPONSE Initializing member variables in a base member initialization section
// of the constructor each on its own line.
:cur_size_ (5),
max_size_ (10)
{
	data_=new char[cur_size_];
  
  // COMMENT There is no need to initialize the array with a default value because (1) the
  // user may not want to initialize it with the value you chose and (2) if they did they would
  // use the fill constructor.
  //RESPONSE Removed for loop that initialized variables in the array  
}

/**
 * Initializing constructor.
 *
 * @param[in]	length	Initial size
 */
Array::Array (size_t length)
// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.
// RESPONSE Initializing member variables in a base member initialization section
// of the constructor each on its own line.
:cur_size_ (length),
max_size_ (cur_size_ * 2)
{
	data_=new char[cur_size_];
  
  // COMMENT There is no need to initialize the array with a default value because (1) the
  // user may not want to initialize it with the value you chose and (2) if they did they would
  // use the fill constructor.
  //RESPONSE Removed for loop that initialized variables in the array  
}

/**
 * Initializing constructor.
 *
 * @param[in]	length	Initial size
 * @param[in]	fill 	Initial value for each element
 */
Array::Array (size_t length, char fill)
// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.
// RESPONSE Initializing member variables in a base member initialization section
// of the constructor each on its own line.
:cur_size_ (length),
max_size_ (cur_size_ * 2)
{
	data_=new char[cur_size_];
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
// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.
// RESPONSE Initializing member variables in a base member initialization section
// of the constructor each on its own line.
:cur_size_ ((array).size()),
max_size_ (cur_size_ * 2)
{
	data_=new char[cur_size_];
	for(int i=0;i<cur_size_;++i)
	{
    // COMMENT Do not call the get() method as you will be doing an unnecessary
    // bound check on an index that is already in range.
    // RESPONSE Replaced the get() method with the array getting the value
    // at the passed in array's index
		data_[i]=(array).data_[i];
	}
}

///Destructor
Array::~Array (void)
{
  // COMMENT You have a memory leak here.
  //
	delete data_;
}

/**
 * Assignment operation
 *
 * @param[in]	rhs	Right-hand side of equal sign
 * @return 	Reference to self
 */
const Array & Array::operator = (const Array & rhs)
{
  // COMMENT Check for self assignment first.
  // RESPONSE Now checks for self assignment first before assigning values
  // to the array.
	if(this==&rhs)
	{
		return *this;
	}
	else
	{
		for(int i=0;i<cur_size_;++i)
		{
    // COMMENT Do not call the get() method as you will be doing an unnecessary
    // bound check on an index that is already in range.
    // RESPONSE Replaced the get() method with the array getting the value
    // at the passed in array's index
			data_[i]=(rhs).data_[i];
		}
		return *this;
  
  // COMMENT This method should return *this for call chaining.
  // RESPONSE Changed return statement to return the Array class itself 
  // and not the *data_.
	}
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
  // COMMENT You are to throw out of range exception if the index is invalid.
  // RESPONSE Changed it to where it throws an out of range exception when
  // the index is greater than the alotted size of the array.
	if(index>cur_size_)
	{
		throw std::out_of_range("That index is bigger than the array itself.");
	}
	else
	{
		return data_[index];
	}
}
/**
 * @overload
 *
 * The return character is not modifiable.
 */
const char & Array::operator [] (size_t index) const
{
  // COMMENT You are to throw out of range exception if the index is invalid.
  // RESPONSE Changed it to where it throws an out of range exception when 
  // the index is greater than the alotted size of the array.
  	if(index>cur_size_)
	{
		throw std::out_of_range("That index is bigger than the array itself.");
	}
	else
	{
		return data_[index];
	}
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
  // COMMENT You are to throw out of range exception if the index is invalid.
  //RESPONSE Changed it to where it throws an out of range exception when
  //the index is greater than the allotted size of the array.
	if(index>cur_size_)
	{
		throw std::out_of_range("That index is bigger than the array itself.");
	}
	else
	{
		return data_[index];
	}
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
  // COMMENT You are to throw out of range exception if the index is invalid.
  // RESPONSE Changed it to where it throws an out of range exception when 
  // the index is greater than the allotted size of the array.
	if(index>cur_size_)
	{
		throw std::out_of_range("That index is bigger than the array itself.");
	}
	else
	{
		data_[index]=value;
	}
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
  // COMMENT The resize method should only increase the size of the allocation if
  // the new size is larger than the current memory allocation for the array. If resized,
  // you need to preserve the old data. Otherwise, you can just update cur_size_ to
  // reflect the new size.
  // RESPONSE resized method now increases allocation size if the new size
  // is larger than the current memory allocation, while preserving the 
  // old data. If it is not larger then the it makes sure the new size and 
  //current size match.
	if(new_size>cur_size_)
	{
		char new_data_[cur_size_];
		for(int i=0;i<cur_size_;++i)
		{
			new_data_[i]=data_[i];
		}
		char *data_=new char [new_size];
		cur_size_=new_size;
		for(int i=0;i<cur_size_;++i)
		{
			data_[i]=new_data_[i];
		}
	}
	else
	{
		cur_size_=new_size;
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
	bool found=false;
	int i=0;
	while(i<cur_size_)
	{
		if(data_[i]==ch)
		{
			return i;
			found =true;
			i=cur_size_;
		}
		else
		{
			i=i+1;
		}
	}
	if(found==false)
	{
		return -1;
	}
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
  // COMMENT You are to throw an exception if the start is invalid.
  // RESPONSE Changed it to where it throws and out of range exception when
  // the starting point is greater than the array itself.
	if(start>cur_size_)
	{
		throw std::out_of_range("That index is bigger than the array itself.");
	}
	else
	{
		bool found=false;
		int i=start;
		while(i<cur_size_)
		{
			if(data_[i]==ch)
			{
				found=true;
				return i;
				i=cur_size_;
			}
			else
			{
				i=i+1;
			}
		}
		if(found==false)
		{
			return -1;
		}
	}
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
  // COMMENT Check for self comparison first.
  // RESPONSE Now checks whether the array's are the same before
  // comparing the two arrays.
	if(this==&rhs)
	{
		return true;
	}
	else
	{
		bool equal=true;
		int i=0;
		while(i<cur_size_)
		{
    // COMMENT Do not call the get() method as you will be doing an unnecessary
    // bound check on an index that is already in range.
    // RESPONSE Replaced the get() method with the array getting the value
    // at the passed in array's index

			if(data_[i]<(rhs).data_[i])
			{
				equal=false;
				i=cur_size_;
				return false;
			}
    // COMMENT Do not call the get() method as you will be doing an unnecessary
    // bound check on an index that is already in range.
    // RESPONSE Replaced the get() method with the array getting the value
    // at the passed in array's index

			else if(data_[i]>(rhs).data_[i])
			{
				equal=false;
				i=cur_size_;
				return false;
			}
			else
			{
				i=i+1;
			}
		}
		if(equal==true)
		{
			return true;
		}
	}
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
  // COMMENT You can define operator != in terms of operator ==.
  //RESPONSE Defined operator != in terms of operator ==.	
	return !((*this) == rhs);
    // COMMENT Do not call the get() method as you will be doing an unnecessary
    // bound check on an index that is already in range.
    //RESPONSE Removed if statement and by extension get() method as
    //it was no longer needed.
    // COMMENT Do not call the get() method as you will be doing an unnecessary
    // bound check on an index that is already in range.
    //RESPONSE Removed else if statement and by extension get() method as
    //it was no longer needed.
}
/**
 * Fill the contents of the array.
 *
 * @param[in]	ch	Fill character
 */
void Array::fill (char ch)
{
	for(int i=0;i<cur_size_;++i)
	{
		data_[i]=ch;
	}
}
/// Shrinks the array to reclaim unused space.
void Array::shrink (void)
{
  // COMMENT The goal of the shrink method is to reduce the memory allocation
  // size, if applicable.
  // RESPONSE Shrink method now reduces the maximum memory allocation to match
  // the current size of the array.
	if(cur_size_<max_size_)
	{
		max_size_=cur_size_;
	}
}	
///Reverse the contents of the array such that the first element is now
///the last element and the last element is the first element.
void Array::reverse (void)
{
	int end=cur_size_;
	int temp=0;
	for(int i=0;i>end;++i)
	{
		temp=data_[end];
		data_[end]=data_[i];
		data_[i]=temp;
		end=end-1;
	}
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
	int temp=0;
	Array* myArray = new Array(cur_size_);
	for(int i=begin;i<=cur_size_;++i)
	{
		(*myArray).data_[temp]=data_[i];
		temp=temp+1;
	}
	return *myArray;
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
	int temp=0;
	Array* myArray=new Array(cur_size_);
	for(int i=begin;i<=end;++i)
	{
		(*myArray).data_[temp]=data_[i];
		temp=temp+1;
	}
	return *myArray;
}
