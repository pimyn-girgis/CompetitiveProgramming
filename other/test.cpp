#include<bits/stdc++.h>
using namespace std;
/*------- Constants---- */
#define forn(i,n)               for( int i=0 ; i < n ; i++ )
#define mp                      make_pair
#define pb                      push_back
#define all(x)                  (x).begin(),(x).end()
#define PI                      acos(-1.0)
#define EPS                     1e-9
#define xx                      first
#define yy                      second
#define lc                      ((n)<<1)
#define rc                      ((n)<<1|1)
#define db(x)                   cout << #x << " -> " << x << endl;
#define ms(ara_name,value)      memset(ara_name,value,sizeof(ara_name))
 
/*************************** END OF TEMPLATE ****************************/
 
const int N = 104;
int n;
int a[N];
int LIM = 0;
int nxt[N];
bool vis[N];
 
bool dfs(int ind,int sum,int cnt)
{
    if(cnt==n) return 1;
    for(int i = ind ;  i < n; i ++) {
        if(vis[i] == 0) {
            if(sum + a[i] <  LIM) {
                vis[i] = 1;
                if(dfs(i+1,sum + a[i],cnt+1)) return 1;
                vis[i] = 0;
                if(sum==0)return 0; 
                /*
                 This line is very important. This denotes we don't take anything and taking the ith element 
                 we can not reach destinition. So there is no solution where we can take the ith element .So
                 We return */
 
                while(i+1<n&& a[i]==a[i+1])i++; // Skipping
            }
            if(sum + a[i] == LIM ) {
                vis[i] = 1;
                if(dfs(0,0,cnt+1)) return 1; // One round is over, Now check for another 
                vis[i] =0;
                return 0;
            }
        }
    }
    return 0;
}
 
int main()
{
     
    while(scanf("%d",&n)==1 && n) {
        int sum = 0, iM = 0;
        for(int i = 0; i < n; i ++) {
            scanf("%d",&a[i]);
            sum += a[i];
            iM = max(iM, a[i]);
        }
        sort(a,a+n);
        reverse(a,a+n);
        for(int i = iM; i <= sum ;i ++ ) {
            if(sum % i) continue;
            LIM = i;
            memset(vis,0,sizeof vis);
            bool k = dfs(0,0,0);
            if(k) {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
