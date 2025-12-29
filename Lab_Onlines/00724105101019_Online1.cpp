#include<bits/stdc++.h>
using namespace std;

int binarySearch(const vector<int>& vec,int x){
    int low = 0;
    int high = vec.size();

    while (low<=high){
        int mid = (low+high)/2;
        if(vec[mid]==x){
            return 1;
        }
        else if(vec[mid]>x){
            high = mid -1;
        }
        else {
            low = mid +1;
        }
    }
    return 2;
}

void insertionSort(vector<int>& vec){
    int n = vec.size();
    for(int i= 1;i<n;i++){
        int cur = vec[i];
        int pre = i-1;
        while(pre>=0&&vec[pre]>cur){
            vec[pre+1]=vec[pre];
            pre--;
        }
        vec[pre+1]=cur;
    }
}

int main(){
    int n;
    cin>>n;
    cin.ignore();
    vector<int> vec;
    for(int i=0;i<n;i++){
        int entry;
        cin>>entry;
        vec.push_back(entry);
    }
    int m;
    cin>>m;
    cin.ignore();
    vector<int> vect;
    for(int i=0;i<m;i++){
        int entry;
        cin>>entry;
        vect.push_back(entry);
    }
    insertionSort(vec);
    for(int b:vect){
        int j=binarySearch(vec,b);
        if(j==1){
            cout<<"Found"<<endl;
        }
        else {
            cout<<"Not Found"<<endl;
        }
    }
}
