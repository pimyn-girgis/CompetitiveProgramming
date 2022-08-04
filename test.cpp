#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    while(cin>>n>>m, (n || m))
    {
    vector<pair<int,int>> vec;
    char composed[n][n],start[m][m];
    for(int i(0);i<n;i++)
        for(int j(0);j<n;j++)
          cin>>composed[i][j];

    for(int i(0);i<m;i++)
        for(int j(0);j<m;j++)
          {
              cin>>start[i][j];
              if(start[i][j]=='*'){vec.push_back({i,j});}
          }

    bool possible(1);

    int e,r,sizeofvec=vec.size();

    for(int i(0);i<m;i++)
        {
        for(int j(0);j<m;j++)
        {
            if(composed[i][j]=='*')
            {
                composed[i][j]='.';
                for(int k(1);k<sizeofvec;k++)
                {
                    e=vec[k].first-vec[0].first;
                    r=vec[k].second-vec[0].second;
                    if(i+e<n && j+r<n && composed[i+e][j+r]=='*'){composed[i+e][j+r]='.';}
                    else{possible=0; break;}
                }
            }
        if(!possible){break;}
        }
        if(!possible){break;}
        }
    if(!possible){cout<<"0\n";}
    else{cout<<"1\n";}
    }
    return 0;
}

