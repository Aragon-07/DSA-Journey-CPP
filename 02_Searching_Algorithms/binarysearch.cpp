#include<bits/stdc++.h>
using namespace std;

int upperBoundManual(const vector<int>& arr,int target){
    int low = 0;
    int high = arr.size();
    int result = arr.size();

    while(low < high){
        int mid = low + (high-low)/2;

        if(arr[mid]>target){
           result = mid;
           high=mid;
        }
        else{
            low = mid +1;
        }
    }
    return result;
}
int lowerBoundManual(const vector<int>& arr,int target){
    int low = 0;
    int high = arr.size();
    int result = arr.size();

    while(low < high){
        int mid = low + (high-low)/2;

        if(arr[mid]>=target){
           result = mid;
           high=mid;
        }
        else{
            low = mid +1;
        }
    }
    return result;
}

int main()
{
    vector<int> vec;
    int size,x;
    cout<<"Enter total numbers: "<<'\n';
    cin>>size;
    cout<<"Enter numbers: "<<'\n';
    for(int i=0;i<size;i++){
        cin>>x;
        vec.push_back(x);
    }
    int target;
    cout<<"Enter target: "<<'\n';
    cin>>target;
    int z=upperBoundManual(vec,target);
    int y=lowerBoundManual(vec,target);
    cout<<"Total Occurance= "<<z-y;

}
