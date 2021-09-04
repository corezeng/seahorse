/**
*@file Sort.h
*@author core zeng (corezeng@gmail.com)
*@brief 
*@version 0.1
*@date 2021-06-28
*
*@copyright Copyright (c) 2021
*
 */

#include<cstddef>
namespace seahorse{
namespace algorithm{

/**
*@brief 快速排序
*
*@tparam T Type operator < must can be use
*@param array array of elements want to be sort
*@param begin begin location of sort
*@param end end location of sort
 */
template<typename T>
void QuickSort(T array[],const size_t begin,size_t end);

template<typename T>
void MergeSort(T array[],const size_t begin,size_t end);
} // namespace algorithm
} // namespace seahorse
