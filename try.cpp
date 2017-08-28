#include<bits/stdc++.h>
using namespace std;
int fun(vector<int>& a,int n,vector<int>& inc){
    if(inc[n] == -1){
        inc[n] = 1;
        for(int i = 0; i < n; i++){
            int t1 = fun(a,i,inc);
            if(a[i] < a[n]){
                inc[n] = max(t1+1,inc[n]);
            }
        }
    }
    return inc[n];
}
int find(vector<int>& a,int index,int n,vector<int>& dec){
    if(dec[index] == -1){
        dec[index] = 1;cout << "hello";
        for(int i = index+1; i < n; i++){
            int t1 = find(a,i,n,dec);
            if(a[index] > a[i]){
                dec[index] = max(t1+1,dec[index]);
            }
        }
    }
    return dec[index];
}
int main(){
    int v[] = {1,11,2,10,4,5,2,1};
    vector<int> a(v,v+7);
    int n = a.size();
    if(n == 0)
        return 0;
    vector<int> inc(n,-1);
    vector<int> dec(n,-1);
    fun(a,n-1,inc);
    find(a,0,n,dec);
    int sum = 0;
    for(int i = 0; i < n; i++){
        cout << inc[i] << " " << dec[i] << "|";
        sum = max(inc[i]+dec[i]-1,sum);
    }
    cout << sum;
    return 0;
}
