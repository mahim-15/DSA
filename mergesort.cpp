#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>&arr,int s,int mi,int r){
    vector<int>temp;
    int i=s;
    int j=mi+1;
    while(i<=mi && j<=r){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mi){
        temp.push_back(arr[i]);
        ++i;
    }
    while(j<=r){
        temp.push_back(arr[j]);
        j++;

    }
    for(int idx=0;idx<temp.size();idx++){
        arr[idx+s]= temp[idx];
    }
}
void mergeSort(vector<int>&aa,int st,int end){
    int mid;
    if(st<end){
        mid=st+(end-st)/2;
        mergeSort(aa,st,mid);
        mergeSort(aa,mid+1,end);
        merge(aa,st,mid,end);


    }
}
int main(){
    vector<int>arr={1,7,88,33,44,16};
    mergeSort(arr,0,arr.size()-1);
    cout<<"SOrted array: ";
    for(int i=0;i<arr.size();++i){
        cout<<arr[i]<<" ";
    }
}