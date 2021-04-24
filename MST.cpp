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

        map <int,set< pair<int,int>>> mp;
        multiset <int> s;

        while(m--)
        {
            int i,j,k;
            cin>>i>>j>>k;
            s.insert(k);
            mp[k].insert({i,j});
        }

        int cnt=0;

        ll mark[n+1],ans=0;
        memset(mark,0,sizeof(mark));

        while(cnt!=n-1)
        {
            int wt=*s.begin();
            pair <int,int> p = *mp[wt].begin();
            int v1=p.first;
            int v2=p.second;

            if(mark[v1]==mark[v2] && mark[v1]==0)
            {
                mark[v1]=-1;
                mark[v2]=v1;
                ans+=wt;
                cnt++;
            }
            else if(mark[v1]!=0 && mark[v2]==0)
            {
                int p,v=v1;

                while(mark[v]>0)
                    v=mark[v];

                p=v;

                mark[p]--;
                mark[v2]=p;
                ans+=wt;
                cnt++;
            }
            else if(mark[v1]==0 && mark[v2]!=0)
            {
                int p,v=v2;

                while(mark[v]>0)
                    v=mark[v];

                p=v;

                mark[p]--;
                mark[v1]=p;
                ans+=wt;
                cnt++;
            }
            else
            {
                int p1,p2;
                int v3=v1,v4=v2;

                while(mark[v3]>0)
                    v3=mark[v3];
                p1=v3;

                while(mark[v4]>0)
                    v4=mark[v4];
                p2=v4;

                if(p1 != p2)
                {
                    if(mark[p1]<mark[p2])
                    {
                        mark[p1]+=mark[p2];
                        mark[p2]=p1;
                    }
                    else
                    {
                        mark[p2]+=mark[p1];
                        mark[p1]=p2;
                    }
                    ans+=wt;
                    cnt++;
                }
            }

            s.erase(s.begin());
            mp[wt].erase(mp[wt].begin());
        }
        cout<<ans;
    }
}

