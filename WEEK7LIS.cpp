#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];

    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    int dp[n];
    for(int i = 0;i<n;i++){
        dp[i] = 1;
    }
    for(int i = 1;i < n;i++){
        for(int j = 0;j<n;j++){
            if(arr[j] < arr[i]){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
    return *max_element(dp,dp+n);
} 
