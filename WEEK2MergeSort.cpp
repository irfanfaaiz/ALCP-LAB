#include<iostream>
using namespace std;

void merge(int l,int m,int h,int a[]){
	int i=l,j=m+1,k=l,b[100];
	while(i<=m&&j<=h){
		if(a[i]<=a[j]){
			b[k]=a[i];
			i++;
		}
		else{
			b[k]=a[j];
			j++;
		}
		k++;
	}
	while(i<=m){
		b[k]=a[i];
		i++;
		k++;
	}
	while(j<=h){
		b[k]=a[j];
		j++;
		k++;
	}
	for(i=l;i<=h;i++){
		a[i]=b[i];
	}
}

void mergesort(int l,int h,int a[]){
	if(l<h){
		int mid=(l+h)/2;
		mergesort(l,mid,a);
		mergesort(mid+1,h,a);
		merge(l,mid,h,a);
	}
}

int main(){
	int n,a[100];
	cout<<"enter number of elements\n";
	cin>>n;
	cout<<"enter elements\n";
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	mergesort(0,n-1,a);
	cout<<"sorted array: ";
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
