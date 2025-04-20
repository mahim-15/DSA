#include<iostream>
using namespace std;
const int MAX_SIZE=1000;
void insertionSort(int arr[],int size)
{
    for(int i=1;i<size;i++){
      int curr=arr[i];
      int prev=i-1;
      while(prev>=0 && arr[prev]>curr){
        arr[prev+1]=arr[prev];
        prev--;
      }
      arr[prev+1]=curr;
    }


}
void display(int arr[], int size) {
    cout << "Sorted Array: ";
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int arr[MAX_SIZE];
    int size=0;
    cout<<"Enter Elements: ";
    while(cin.peek()!='\n')
    {
        if(size<MAX_SIZE)
        {
            cin>>arr[size++];
        }
        else
        {
            cout << "Size limit reached!" << endl;
            break;
        }

    }
    cin.ignore();
    insertionSort(arr,size);
    display(arr,size);

}