#ifndef MEDIAN_H
#define MEDIAN_H

#include <bits/stdc++.h>
using namespace std;

    //! A function findMedian.
    /*!
     \param arr[] a double array
     \param n an integer value
     \return double
      It finds median in a small array, that is, in an array of size less than or equal to 5.
    */
double findMedian(double arr[], int n) ;

    //! A function kthSmallest.
    /*!
     \param arr[] a double array
     \param l an integer value
     \param r an integer value
     \param k an integer value
     \return double
      It finds kth smallest element in the array by finding medians of groups of 5 and finding median of all of them. This is used to compare the position and retrieve the element.
    */
double kthSmallest(double arr[], int l, int r, int k) ;

    //! A function swap.
    /*!
     \param *a a double pointer
     \param *b a double pointer
     \return void
      It swaps the 2 double elements.
    */
void swap(double *a, double *b) ;

    //! A function partition.
    /*!
     \param arr[] a double array
     \param l an integer value
     \param r an integer value
     \param x a double value
     \return int
      It creates a partition in the array by swapping elements such that all elements to it's right are greater than the given and left are smaller.
    */
int partition(double arr[], int l, int r, double x) ;

    //! A function median.
    /*!
     \param arr[] a double array
     \param n an integer value
     \return double
      It finds the median element by calling kth smallest element for k being median position.
    */
double median(double arr[], int n);

#endif