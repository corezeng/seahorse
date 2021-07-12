/**
*@file Search.h
*@author core zeng (corezeng@gmail.com)
*@brief  
*@version 0.1
*@date 2021-06-28
*
*@copyright Copyright (c) 2021
*
 */

#ifndef SEAHORSE_ALGORITHM_SEARCH_H
#define SEAHORSE_ALGORITHM_SEARCH_H
#include<cstddef>
namespace seahorse {
namespace algorithms{

/**
*@brief 
*
*@tparam T 
*@param array 
*@param begin 
*@param end 
*@param target 
*@return const T& 
 */
template<typename T>
const T& BinarySearch(const T array[],const size_t begin,const size_t end,const T& target);    
} // namespace algorithms
} // namespace seahorse


#endif