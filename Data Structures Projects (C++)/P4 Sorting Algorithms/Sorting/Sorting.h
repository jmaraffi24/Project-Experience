//Sorting.h
#include <iostream>

#ifndef SORTING_H_H
#define SORTING_H_H
const int MAX_VALUE = 10000;

using namespace std;

/*
 * Sorting.h which contains all public prototypes for the sorting class
 * as well as all private member variables necessary.
 */
class Sorting{
  public:
    void print(int length);
    void insert(int start, int end, int & nc);
    void insertSort(int length, int & nc);

    void merge(int lf, int ll, int rf, int rl, int &nc);
    void mergeSort(int first, int last, int & nc);

    void reheapDown(int root, int bottom, int & nc);
    void heapSort(int length, int & nc);

    void split(int first, int last, int& sPoint, int& nc);
    void quickSort(int first, int last, int & nc);

    void setArr(int i, int n);
 private:
    int inArr[MAX_VALUE];
};

#endif
