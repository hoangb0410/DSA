#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
/*Hàm này nhận phần tử cuối cùng làm pivot, đặt phần tử pivot vào đúng vị trí của nó trong mảng đã sắp xếp 
và đặt tất cả các phần tử nhỏ hơn (nhỏ hơn pivot) sang trái của pivot và tất cả các phần tử lớn hơn ở bên phải pivot*/
int partition(int arr[], int low, int high) // phân hoạch (Lomoto)
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
// Tạo Pivot ngẫu nhiên, hoán đổi pivot với phần tử cuối và gọi hàm partition
int partition_r(int arr[], int low, int high)
{
	// Tạo một số ngẫu nhiên ở giữa low .. high
	srand(time(NULL));
	int random = low + rand() % (high - low);
	// Đổi chỗ A[random] với A[high]
	swap(arr[random], arr[high]);
    // Gọi hàm partition
	return partition(arr, low, high);
}
// Function chính cài đặt QuickSort
// arr[] --> Mảng cần được sắp xếp,
// low --> Chỉ số đầu,
// high --> Chỉ số cuối
void quickSort(int arr[], int low, int high)
{
	if (low < high) 
	{
		// pi là chỉ số vách ngăn,
		int pi = partition_r(arr, low, high);
		// Sắp xếp riêng biệt các phần tử trước vách ngăn và sau vách ngăn
		quickSort(arr, low, pi);
		quickSort(arr, pi + 1, high);
	}
}
// In mảng
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
