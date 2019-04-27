#include "median.h"


double median(double arr[], int n) {
    if(n == 0)
        return 0;
    if(n == 1)
        return arr[0];
    int midPos = n/2;
    
    double x = kthSmallest(arr, 0, n-1, midPos);
    return x;        
}

double findMedian(double arr[], int n) 
{ 
    sort(arr, arr+n);  
    return arr[n/2];  
} 

double kthSmallest(double arr[], int l, int r, int k) 
{ 

    if (k > 0 && k <= r - l + 1) 
    { 
        int n = r-l+1; 
  
        int i;
        double median[(n+4)/5];
        for (i=0; i<n/5; i++) 
            median[i] = findMedian(arr+l+i*5, 5); 
        if (i*5 < n) 
        { 
            median[i] = findMedian(arr+l+i*5, n%5);  
            i++; 
        }     

        double medOfMed = (i == 1)? median[i-1]: 
                                 kthSmallest(median, 0, i-1, i/2); 
  
        int pos = partition(arr, l, r, medOfMed); 

        if (pos-l == k-1) 
            return arr[pos]; 
        if (pos-l > k-1)   
            return kthSmallest(arr, l, pos-1, k); 
  
        return kthSmallest(arr, pos+1, r, k-pos+l-1); 
    } 
  
    return INT_MAX; 
} 
  
void swap(double *a, double *b) 
{ 
    double temp = *a; 
    *a = *b; 
    *b = temp; 
} 
  
int partition(double arr[], int l, int r, double x) 
{ 
    int i; 
    for (i=l; i<r; i++) 
        if (abs(arr[i] == x) < 0.000001)  
           break; 
    swap(&arr[i], &arr[r]); 
  
    i = l; 
    for (int j = l; j <= r - 1; j++) 
    { 
        if (arr[j] <= x || abs(arr[j] - x) < 0.0000001)  
        { 
            swap(&arr[i], &arr[j]); 
            i++; 
        } 
    } 
    swap(&arr[i], &arr[r]); 
    return i; 
} 