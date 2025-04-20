#include<iostream>
using namespace std;
const int MAX_SIZE=1000;
void selectionSort(int arr[],int size)
{
    for(int i=0;i<size-1;i++){
        int si=i;
        for(int j=i+1;j<size;j++)
        {
            if(arr[j]<arr[si]){
                si=j;
            }

        }
        swap(arr[i],arr[si]);
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
    selectionSort(arr,size);
    display(arr,size);

}