#include<bits/stdc++.h>
using namespace std;

vector <int> vec;

int binarySearch(int x){
    int low = 0;
    int high = vec.size()-1;
    int mid;

    while(low <= high){
        mid = (low + high)/2;
        if(vec[mid]==x){
            return 1;
        }
        else if(vec[mid]>x){
            high = mid -1;
        }
        else {
            low = mid+1;
        }
    }
    return 2;
}

int findLowerBound(int x){
    int low = 0;
    int high = vec.size()-1;
    int value = vec.size();
    while (low<=high){
        int mid = (low+high)/2;
        if(vec[mid]>=x){
            value = mid;
            high=mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return value;
}

int findUpperBound(int x){
    int low=0;
    int high = vec.size()-1;
    int value = vec.size();
    while (low<=high){
        int mid =(low+high)/2;
        if(vec[mid]>x){
            value = mid;
            high = mid -1;
        }
        else {
            low = mid +1;
        }
    }
    return value;
}

int main(){
    int total , entry ,bookId;
    cout<<"Enter the number of total bookIds: ";
    cin>>total;
    cout<<endl;
    cout<<"Enter book ids(sorted): ";
    for(int i=0;i<total;i++){
        cin>>entry;
        vec.push_back(entry);
    }
    cout<<"Enter the bookId you are searching for: ";
    cin>>bookId;
    int y = binarySearch(bookId);
    if(y==1){
        cout<<"The id exists in the list"<<endl;
    }
    else{
        cout<<"The id does not exist in the list"<<endl;
    }
    int low = findLowerBound(bookId);
    int high = findUpperBound(bookId);
    cout<<"The low bound of the given id is " <<low<<endl;
    cout<<"The upper bound of the given id is "<<high<<endl;
    return 0;
}
