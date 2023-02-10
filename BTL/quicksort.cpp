#include <iostream>
#include<stdio.h>  
using namespace std;
int partition(int arr[], int low, int high) // phân hoạch
{
	int pivot = arr[high];
	int i = low - 1;
	for (int j = low; j <= high - 1; j++) 
    {
        // Nếu phần tử hiện tại nhỏ hơn hoặc bằng pivot
        if (arr[j] <= pivot) 
		{
            // Tằn chỉ số của phần tử nhỏ hơn
            i++; 
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
/* Hàm thực hiện giải thuật quick sort */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi là chỉ số nơi phần tử này đã đứng đúng vị trí
         và là phần tử chia mảng làm 2 mảng con trái & phải */
        int pi = partition(arr, low, high); 
        // Gọi đệ quy sắp xếp 2 mảng con trái và phải
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
} 
/* Hàm xuất mảng */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}  
int main()
{
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    cout<<"Sorted array: \n";
    printArray(arr, n);
    return 0;
}