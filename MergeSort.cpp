/*#include <iostream>
using namespace ; 

int* increasing_insertion_sort(int* arr, int size){


for (int j = 1; j<size; j++){ 
int key = arr[j];
int i = j -1;
while (i >= 0 && arr[i] > key)
{
    arr[i + 1] = arr[i];
    i--;
}
arr[i+1] = key;

}
return arr;
}



int* decreasing_insertion_sort(int* arr, int size){


for (int j = 1; j<size; j++){ 
int key = arr[j];
int i = j -1;
while (i >= 0 && arr[i] < key)
{
    arr[i + 1] = arr[i];
    i--;
}
arr[i+1] = key;

}
return arr;
}


int main(){
int myarr[9] = {14,2,56,32,65,7,8,1,4};
int mysize = sizeof(myarr) / sizeof(myarr[0]);
increasing_insertion_sort(myarr, mysize);

for (int i = 0; i < mysize; i++){cout<< myarr[i] << " ";}

cout<< endl<<endl;
decreasing_insertion_sort(myarr, mysize);

for (int i = 0; i < mysize; i++){cout<< myarr[i] << " ";}
return 0;
}


#include <iostream>
#include <vector>
#include <limits>
using namespace std; 

const int POSITIVE_INFINITY = numeric_limits<int>::max();//Function for infinity, found this from internet.

void merge(vector<int> arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    vector<int> leftArr(n1 + 1);
    vector<int> rightArr(n2 + 1);

    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[middle + j + 1];
    }
    leftArr[n1] = POSITIVE_INFINITY;
    rightArr[n2] =POSITIVE_INFINITY;

    int i = 0, j = 0;
    for (int k = left; k <= right; k++) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
    }
}

void mergeSort( vector<int>& arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

int main() {
     vector<int> arr = {7,6,4,2,1};
    int arrSize = arr.size();

     cout << "Original array: ";
    for (int i = 0; i < arrSize; i++) {
         cout << arr[i] << " ";
    }
     cout <<  endl;

    mergeSort(arr, 0, arrSize - 1);

     cout << "Sorted array: ";
    for (int i = 0; i < arrSize; i++) {
         cout << arr[i] << " ";
    }
     cout <<  endl;

    return 0;
}


*/

#include <iostream>
#include <limits>

using namespace std;

const int POSITIVE_INFINITY = numeric_limits<int>::max();
const int NEGATIVE_INFINITY = numeric_limits<int>::min();

void incmerge(int arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int* leftArr = new int[n1 + 1];
    int* rightArr = new int[n2 + 1];

    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[middle + j + 1];
    }
    leftArr[n1] = POSITIVE_INFINITY;
    rightArr[n2] = POSITIVE_INFINITY;

    int i = 0, j = 0;
    for (int k = left; k <= right; k++) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
    }

    delete[] leftArr;
    delete[] rightArr;
}


void decmerge(int arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int* leftArr = new int[n1 + 1];
    int* rightArr = new int[n2 + 1];

    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[middle + j + 1];
    }
    leftArr[n1] = NEGATIVE_INFINITY;// Negative infinity
    rightArr[n2] =NEGATIVE_INFINITY; // Negative infinity

    int i = 0, j = 0;
    for (int k = left; k <= right; k++) {
        if (leftArr[i] >= rightArr[j]) { // Modified condition for decreasing order
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
    }

    delete[] leftArr;
    delete[] rightArr;
}


void incmergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        incmergeSort(arr, left, middle);
        incmergeSort(arr, middle + 1, right);
        incmerge(arr, left, middle, right);
    }
}

void decmergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        decmergeSort(arr, left, middle);
        decmergeSort(arr, middle + 1, right);
        decmerge(arr, left, middle, right);
    }
}


int main() {
    // int arr[] = {12, 11, 13, 5, 6, 7};
    // int arrSize = sizeof(arr) / sizeof(arr[0]);

    // cout << "Original array: ";
    // for (int i = 0; i < arrSize; i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    // incmergeSort(arr, 0, arrSize - 1);

    // cout << "Sorted array: ";
    // for (int i = 0; i < arrSize; i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    // return 0;
}
