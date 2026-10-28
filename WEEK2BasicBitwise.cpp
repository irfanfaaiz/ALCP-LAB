#include<iostream>
using namespace std;

int number(int arr[],int n){
	int result = 0;
	for(int i = 0;i<n;i++){
		result = result^arr[i];
		
	}
	return result;
}
int main(){
	int arr[100];
	int n;
	cout<<"enter the value of n\n";
	cin>>n;
	cout<<"enter the elements\n";
	for(int i = 0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"single number :"<<number(arr,n)<<endl;
	return 0;
	
}
