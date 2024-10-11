#include<iostream>
using namespace std;
void merge(int *arr, int s, int e){
    int mid = s + (e - s) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    //Create 2 new arrays
    int *first=new int[len1];
    int *second = new int[len2];

    for(int i=0; i<len1; i++){
        
    }

    int index1 = 0;
    int index2 = 0;

}
void mergesort(int *arr, int s,int e){
    if(s>=e){
        return;
    }
    int mid = s + (e - s) / 2;
    mergesort(arr, s, mid);
    mergesort(arr, mid + 1, e);
    merge(arr, s, e);
}

int main(){
    int arr[6] = {3, 7, 2, 5, 3, 8};
    cout << "Enter Size: ";
    int size;
    cin >> size;
    cout << "Before:-\n";
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    mergersort(arr, 0, size - 1);
    cout << "After:- \n";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}