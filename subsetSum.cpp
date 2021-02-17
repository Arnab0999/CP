#include<bits/stdc++.h>
using namespace std;
void makeCombiUtil(vector<vector<int> >& ans, vector<int>& tmp, int n, int left, int k) 
{  
    if (k == 0) { 
        ans.push_back(tmp); 
        return; 
    }  
    for (int i = left; i <= n; ++i) 
    { 
        tmp.push_back(i);
	//calling the function recursively 
        makeCombiUtil(ans, tmp, n, i + 1, k - 1);  
        tmp.pop_back(); 
    } 
} 
int generateComb(int n,int k,int m){
    int count = 0, sum = 0;
    vector<vector<int> > ans; 
    vector<int> tmp; 
    makeCombiUtil(ans, tmp, n, 1, k); 
    for (int i = 0; i < ans.size(); i++) { 
        for (int j = 0; j < ans[i].size(); j++) { 
            sum += ans.at(i).at(j); 
        } 
        if(sum%m==0)
            count++;
        sum=0;
    }
    return count;
}
int findCount(int n,int k,int m){
    int count=generateComb(n,k,m);
    return count;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,k,m;
        cin>>n>>k>>m;
        cout<<findCount(n,k,m)<<endl;
    }
}
