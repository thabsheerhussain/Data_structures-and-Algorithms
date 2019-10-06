// Program to search an element in an array using Linear Search.

#include <stdio.h>
#include <stdlib.h>

// Function to scan an array as an input.

void scanArray(int array[], int size) {

     for(int i=0; i<size; i++) 
          scanf("%d", &array[i]);
          
}

// Function to implement Linear Search.

int linearSearch(int array[], int size, int key) {

     int res=-1;                   // If element is not in the given array -1 will be returned.
     for(int i=0; i<size; i++) {
          if(array[i]==key)
               res=i;              // Result will be the index where the element if found. 
                       
     }
     return res;
}

// Main Function

int main() {

     int array[5]={0};             // Initialising Array with Zero.
     int key;
     int result;
     printf("Enter the elements of array:\n");
     scanArray(array,5);
     printf("Enter the key element :\n");
     scanf("%d", &key);
     result = linearSearch(array,5,key);
     if (result==-1)
          printf("Key element not found!\n");
     else
          printf("Key element is found at index : %d\n", result);
     return 0;
}     
