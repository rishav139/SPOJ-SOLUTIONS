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
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int edge[n+1][n+1]={0};

        for(int i=1;i<=m;i++)
        {
            int x,y,w;
            cin>>x>>y>>w;
            edge[x][y]=w;
        }

        int A,B;
        cin>>A>>B;

        int vis[n+1],dist[n+1];

        for(int i=1;i<=n;i++)
        vis[i]=0, dist[i]=INT_MAX;

        dist[A]=0;

        for(int i=1;i<=n-1;i++)
        {
            int val=INT_MAX,v;

            for(int j=1;j<=n;j++)
            if(!vis[j] && dist[j]<val)
            {
                val=dist[j];
                v=j;
            }

            vis[v]=1;

            for(int j=1;j<=n;j++)
            {
                if(!vis[j] && edge[v][j] && dist[j]>dist[v]+edge[v][j])
                dist[j]=dist[v]+edge[v][j];
            }

        }
        int ans=dist[B];

        if(ans==INT_MAX)
        cout<<"NO\n";
        else
        cout<<ans<<"\n";

        // for(int i=1;i<=n;i++)
        // cout<<dist[i]<<" ";
    }
}

