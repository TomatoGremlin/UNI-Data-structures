#include <iostream>
using namespace std;
// 4. Binary search via recursion
int Binary_Recursion(int* arr, int search_value, int beg_indx, int end_indx) {

    int mid_indx = (beg_indx + end_indx) / 2; // we split the array in 2 parts - before and after the middle index
    if (beg_indx == end_indx) {
        if (arr[mid_indx] == search_value) // if the value is found 
        {
            return mid_indx;
        }
        else if(arr[mid_indx] > search_value) // if the value is in the left side of the array
        {
            return Binary_Recursion(arr, search_value, beg_indx, mid_indx - 1 );
        }
        return Binary_Recursion(arr, search_value, mid_indx + 1, end_indx); // if the value is in the right side of the array   arr[mid_indx] < search_value
    }
    else { // if the beg_index becomes greater than the end_index we stop searching
        cout << "The value "<< search_value << " wasn't found" << endl;
        return -1;
    }
}

int main(){
    int array[] = {1,8,9,4,7,3};
    int search = 2;
    int size = sizeof(array)/sizeof(array[0]);
    Binary_Recursion(array, search, 0, size - 1); // 0 = beg index ; size - 1 = end index
    return 0;
}

