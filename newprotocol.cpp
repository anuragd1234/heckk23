#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define fo(a,b,c) for(int a=b;a<c;a++)
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int func(int i, vector<vector<int>>& adj, unordered_map<int, int>& m, int par, int k, int &ans){
    int x = 0;
    for(auto node : adj[i]){
        if(par != node){
            x += func(node, adj, m, i, k, ans);
        }
    }
    if(m[i]) x++;
    ans += min(x, 2*k - x);
    return x;
}
void code()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n + 1);
    unordered_map<int,int> m;
    for(int i = 0; i < 2*k; i++){
        int x;
        cin >> x;
        m[x] = 1;
    }
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = 0;
    // for(int i = 1; i <= n; i++){
        // if(!m[i]){
            int l = func(1, adj, m, -1, k, ans);
            // break;
        // }
    // }
    
    cout << ans;
}
int32_t main()
{
    fast
    int test = 1;
    // cin >> test;
    for(int i=0;i<test;i++)
    {
        code();
    }
    return 0;
}
