#include<iostream>
using namespace std;
int main(){
	int n,i,j,temp;
	int arr[10];
	for(i = 0; i < 10; i++){
		cin >> arr[i];
	}
	for(i = 0; i < 10; i++){
		for(j = i; j < 10; j++){
			if(arr[i] > arr[j]){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for(i = 0; i < 10; i++)
		cout << arr[i] << " ";
	return 0;
}
