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
        if(sum==m)
            count++;
        sum=0;
    }
    return count;
}
int findCount(int n,int k,int m){
    if(k==0 || k>n)
        return 0;
    if(k==1 && m<=n)
        return 1;
    int sum = 0;
    for(int i=1;i<=k;i++){
        sum+=i;
    }
    int count = 0;
    if(k==n){
        if(sum==m)
            return 1;
        return 0;
    }
    count=generateComb(n,k,m);
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
