
#include <iostream>

using namespace std;

int table[6][7];

int main()
{
    int W[] = {1,2,1,2,3} , val[] = {3,5,6,9,10}, wt=6;  // Items MUST be sorted b

    for(int i(1);i<6;++i)
        for(int j(0);j<7;++j)
        {
            if(W[i-1]>j)
                table[i][j]=table[i-1][j];
            else
                {
                    table[i][j]=max(table[i-1][j], val[i-1] + table[i-1][j-W[i-1]]);
                }
        }

    int ret = table[5][6];
    for(int i = 5 - 1; i >= 0 && ret > 0; --i)
        if(ret != table[i][6])
        {
            cout<< i << ' ';
            ret = ret - val[i];
            wt -= W[i];
        }

    cout<<endl;
    
    return 0;
}
