//Sorting.cpp
#include "Sorting.h"

/**
 * Print function to display all elements in the integer array
 * Pre: inArr is initialized, all necessary variables are passed in and print is called
 * Post: All elements of the integer array are sent to standard output
 */
void Sorting::print(int length){
  for(int f1=0; f1<length; f1++){
    if(f1%10 == 0)
      cout << endl;
    cout << inArr[f1] << " ";
  }//for
  cout << endl;
}//print

/**
 * Insert helper method that does the actual insertion sort on an unsorted integer array
 * Pre: inArr is initialized, all necessary variables are passed in and insertSort has been called
 * Post: sorted array and number of comparisons (nc) is returned to insertSort
 */
void Sorting::insert(int start, int end, int & nc){
  bool done = false;
  int current = end;
  bool moreToSearch = (current != start);
  int tempInt = 0;

  while (moreToSearch && !done){
    if(inArr[current] < inArr[current-1]){
      tempInt = inArr[current];
      inArr[current] = inArr[current-1];
      inArr[current-1] = tempInt;
      current--;
      moreToSearch = (current != start);
    }else
      done = true;
    nc++;
  }//while
}//insert

/**
 * InsertSort driver method that calls the insert method necessary for executing an
 * insertion sort on an unsorted integer array
 * Pre: inArr is initialized, instance variables are properly passed in.
 * Post: insert has been called and the insertionSort is complete, number of comparisons incremented
 */
void Sorting::insertSort(int length, int & nc){
  for(int f1=0; f1<length; f1++){
    insert(0, f1, nc);
  }//for
}//insertSort

/**
 * Merge helper method for the executing a merge sort on an unsorted integer array
 * Pre: inArr is initialized, instance variables passed in and mergeSort has been called on the object
 * Post: the two halves of the sorted array are merged into a single sorted array
 */
void Sorting::merge(int lf, int ll, int rf, int rl, int & nc){
  int tempArr[10000];
  int index = lf;
  int sf = lf;

  while((lf<=ll) && (rf <= rl)){
    if(inArr[lf] < inArr[rf]){
      tempArr[index] = inArr[lf];
      lf++;
    }//if
    else{
      tempArr[index] = inArr[rf];
      rf++;
    }//else
    nc++;
    index++;
  }//while

  while(lf <= ll){
    tempArr[index] = inArr[lf];
    lf++;
    index++;
  }//while

  while(rf <= rl){
    tempArr[index] = inArr[rf];
    rf++;
    index++;
  }//while

  for(index = sf; index <=rl; index++){
    inArr[index] = tempArr[index];
  }//for
}//merge

/**
 * Merge sort driver method that splits the interger array into two arrays, sorts them then merges them
 * Pre: inArr is initialized, all necessary variables have been passed in and mergeSort is called
 * Post: Two sorted arrays have been combined into one sorted array, nc is the number of comparisons
 */
void Sorting::mergeSort(int first, int last, int & nc){
  if(first<last){
    int middle = (first + last) /2;
    mergeSort(first, middle, nc);
    mergeSort(middle+1, last, nc);
    merge(first, middle, middle+1, last, nc);
  }//if
}//mergeSort

/**
 * Heap sort helper method that is responsible for making the unsorted array into a heap
 * Pre: inArr is intialized, all necessary variables have been passed in and heapSort is called
 * Post: inArr is a heap and is returned to the heapSort to then be sorted by reheapDown
 */
void Sorting::reheapDown(int root, int bottom, int & nc){
  int max;
  int right;
  int left;
  int tempInt;

  left = root * 2 + 1;
  right = root * 2 + 2;
  if(left <= bottom){
    if(left == bottom){
      max = left;
    }//if
    else{
      if(inArr[left] <= inArr[right]){
        max = right;
      }//if
      else{
        max = left;
      }//else
      nc++;
    }//else
    if(inArr[root] < inArr[max]){
      tempInt = inArr[root];
      inArr[root] = inArr[max];
      inArr[max] = tempInt;
      reheapDown(max, bottom, nc);
    }//if
    nc++;
  }//if
}//reheapDown

/**
 * Heap Sort driver method that uses reHeapDown to turn the interger array into a heap and sort it
 * Pre: inArr is intialized, all necessary variables and heapSort has been called
 * Post: inArr is a heap and is sorted, nc is the number of comparisons made within heapSort
 */
void Sorting::heapSort(int length, int & nc){
  int tempInt;
  for(int f1 = length/2 - 1; f1 >= 0; f1--){
    reheapDown(f1, length-1, nc);
  }//for
  for(int f1 = length - 1; f1 >= 1; f1 --){
    tempInt = inArr[0];
    inArr[0] = inArr[f1];
    inArr[f1] = tempInt;
    reheapDown(0, f1-1, nc);
  }//for
}//heapSort

/**
 * Split helper method that splits the integer array into two parts for the quickSort method
 * Pre: inArr has been initialized, all necessary variables have been passed in and quickSort has been called
 * Post: 
 */
void Sorting::split(int first, int last, int& sPoint, int& nc){
  int pivot = inArr[first];
  int saveFirst = first;
  bool onCorrectSide;
  first++;
  int tempInt = 0;
  do{
    onCorrectSide = true;
    while (onCorrectSide){
      if(inArr[first] > pivot){
        onCorrectSide = false;
      }//if
      else{
        first++;
        onCorrectSide = (first <= last);
      }//else
      nc++;
    }//while
    onCorrectSide = (first <= last);
    while(onCorrectSide){
      if(inArr[last] <= pivot){
        onCorrectSide = false;
      }//if
      else{
        last--;
        onCorrectSide = (first <= last);
      }//else
      nc++;
    }//while
    if(first < last){
      tempInt = inArr[first];
      inArr[first] = inArr[last];
      inArr[last] = tempInt;
      first++;
      last--;
    }//if
  }while(first <= last);
  sPoint = last;
  tempInt = inArr[saveFirst];
  inArr[saveFirst] = inArr[sPoint];
  inArr[sPoint] = tempInt;
}//split

/**
 * Quick sort driver method, recursively calls itself and the split helper method to execute quick sort
 * on the unsorted integer array
 * Pre: inArr has been intializaed, all necessary variables have been passed in and quickSort has been called
 * Post: inArr has been sorted, nc contains the number of comparisons made within the quickSort method
 */
void Sorting::quickSort(int first, int last, int& nc){
  if(first<last){
    int tempInt;
    int randInd = rand() % (last-first) + first;
    tempInt = inArr[first];
    inArr[first] = inArr[randInd];
    inArr[randInd] = tempInt;
    int sPoint;
    split(first, last, sPoint, nc);
    quickSort(first, sPoint-1, nc);
    quickSort(sPoint+1, last, nc);
  }//if
}//quickSort

/*
 * Setter method for the integer array, used for inserting values into the elements of the array
 * Pre: inArr has been intialized, all necessary variables have been passed in and setArr has been called
 * Post: inArr has been filled with all the target values
 */
void Sorting::setArr(int i, int n){
  inArr[i] = n;
}//setArr
