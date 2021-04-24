#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
//#pragma GCC optimize("Ofast")
// #pragma GCC optimize "trapv"

#define ll long long
#define lld long double


int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld t;
    //cin>>t;
    t=1;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        set <pair<int,int>> edge[n+1];

        for(int i=1;i<=m;i++)
        {
            int x,y,w;
            cin>>x>>y>>w;
            edge[x].insert({y,w});
            edge[y].insert({x,w});
        }

        set <pair<int,int>> s;
        int vis[n+1]={0};
        vis[1]=1;

        for(auto it=edge[1].begin();it!=edge[1].end();it++)
        s.insert({it->second,it->first});

        ll ans=0;

        for(int i=1;i<n;i++)
        {
            while(1)
            {
                pair <int,int> p = *s.begin();
                s.erase(p);

                if(vis[p.second]==0)
                {
                    ans+=p.first;
                    int v=p.second;
                    vis[v]=1;

                    for(auto it=edge[v].begin();it!=edge[v].end();it++)
                        s.insert({it->second,it->first});

                    break;
                }
            }
        }
        cout<<ans;
    }
}

