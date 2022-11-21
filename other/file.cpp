#include <iostream>
#include <vector>

using namespace std;

int main()

{
    int S[] = {1, 2, 3},N; // It MUST be sorted and first one must be ZERO.
    cin>>N;
    vector<vector<int>> dparr((sizeof(S)/sizeof(S[0])),vector<int>(N+1,0));

    for(int i(1);i<N+1;++i)
        {
            if(i%S[1]==0)
                dparr[1][i]=1;
            else
                dparr[1][i]=0;
        }                      //Base Case

    for(int i(2);i<(sizeof(S)/sizeof(S[0]));++i)
        for(int j(1);j<N+1;++j)
        {
            dparr[i][j]=dparr[i-1][j];
            if(j==S[i])
            {
                dparr[i][j]++;
            }
            if(j>S[i])
            {
                dparr[i][j]+=dparr[i][j-S[i]];
            }
        }
    cout<<dparr[(sizeof(S)/sizeof(S[0]))-1][N];
    return 0;
}