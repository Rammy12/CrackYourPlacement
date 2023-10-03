/*
problem:p- https://www.codechef.com/problems/SPACEARR?tab=statement
*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;cin >> t;
	while(t--){
	    int n; 
	    cin >> n;
	    vector<int>arr(n);
	    for(int i=0; i<n; i++)
	    {
	        cin>>arr[i];
	    }
	    sort(arr.begin(),arr.end());
	    int total = 0;
	    bool flag = 0;
	    for(int i=0; i<n; i++)
	    {
	        if(arr[i]>(i+1))
	        {
	            flag=1;
	            cout<<"Second"<<endl;
	            break;
	        }
	        else
	        {
	            total+=(i+1)-arr[i];
	        }
	    }
	    if(!flag){
	        if(total&1)
	        {
	            cout<<"First"<<endl;
	        }
	        else 
	        {
	            cout << "Second" <<endl;
	        }
	    }
	}
	return 0;
}