#include<bits/stdc++.h>
using namespace std;
void rearrange(int arr[],int size){
    int s=0,l=size-1;
    while(s<l){
        if(arr[s]<0)
        s++;
        else if(arr[l]>0)
        l--;
        else 
        swap(arr[s],arr[l]);
    }

}
int main(){
    int arr[]= { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
    int size=sizeof(arr)/sizeof(arr[0]);
    rearrange(arr,size);
    for(int i=0;i<size;i++)
    cout<<arr[i]<<" ";

}

// A C++ program to put all negative
// numbers before positive numbers
// #include <bits/stdc++.h>
// using namespace std;

// void rearrange(int arr[], int n)
// {
// 	int j = 0;
// 	for (int i = 0; i < n; i++) {
// 		if (arr[i] < 0) {
// 			if (i != j)
// 				swap(arr[i], arr[j]);
// 			j++;
// 		}
// 	}
// }

// // A utility function to print an array
// void printArray(int arr[], int n)
// {
// 	for (int i = 0; i < n; i++)
// 		printf("%d ", arr[i]);
// }

// // Driver code
// int main()
// {
// 	int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
// 	int n = sizeof(arr) / sizeof(arr[0]);
// 	rearrange(arr, n);
// 	printArray(arr, n);
// 	return 0;
// }
