//Main.cpp
#include "Sorting.h"
#include <fstream>

int main(int argc, char** argv){
  Sorting list;
  int input;
  fstream fs;
  fs.open(argv[1], fstream::in);
  if(fs.is_open()){
    for(int f1=0; f1<10000; f1++){
      fs >> input;
      list.setArr(f1, input);
    }//for
  }//if
  else{
    cout << "Failed to open the input file" << endl;
    return 0;
  }//else

  list.print(10000);

  cout << "insertion-sort (i), merge-sort (m)," << endl;
  cout << "heap-sort (h), quick-sort (q)" << endl << endl;
  cout << "Enter the algorithm: ";

  char al;
  cin >> al;

  int numComp = 0;
  switch(al){
  case 'i':
    list.insertSort(10000, numComp);
    list.print(10000);
    cout << "Insertion-Sort comparisons: " << numComp << endl;
    break;
  case 'm':
    list.mergeSort(0, 9999, numComp);
    list.print(10000);
    cout << "Merge-Sort comparisons: " << numComp << endl;
    break;
  case 'h':
    list.heapSort(10000, numComp);
    list.print(10000);
    cout << "Heap-Sort comparisons: " << numComp << endl;
    break;
  case 'q':
    list.quickSort(0, 9999, numComp);
    list.print(10000);
    cout << "Quick-Sort comparisons: " << numComp << endl;
    break;
  }//switch
}//main
