#include <iostream>
#include <vector>
//#include <bits/stdc++.h>
using namespace std;
 
#define ms(s,n) memset(s,n,sizeof(s))
#define all(a) a.begin(),a.end()
#define present(t, x) (t.find(x) != t.end())
#define sz(a) int((a).size())
#define FOR(i, a, b) for (int i = (a) ; i < (b); ++i)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); --i)
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mp make_pair
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vii; 
const int MOD = (int) 1e9+7;
const int INF = (int) 1e9+1;
inline ll gcd(ll a,ll b)
{
    ll r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
inline ll lcm(ll a,ll b)
{
    return a/gcd(a,b)*b;
} 
void FileIO()
{
	freopen("N_queen_input.txt","r", stdin);
	freopen("N_queen_output.txt","w",stdout);
}
 
int n,a[100],xuoi[100],nguoc[100],cnt; 
void inp()
{
	cin>>n;
	FOR(i,1,100)
    {
		a[i]=xuoi[i]=nguoc[i]=1;
	}
	cnt=0;
}
 
void ql(int i)
{
	for(int j=1;j<=n;j++)
    {
		if(a[j] && xuoi[i-j+n] && nguoc[i+j-1])
        {
			a[j]=xuoi[i-j+n]=nguoc[i+j-1]=0;
			if(i==n) ++cnt;
			else ql(i+1);
			a[j]=xuoi[i-j+n]=nguoc[i+j-1]=1;
		}
	}
}
 
int main()
{
	int t;cin>>t;
	while(t--)
    {
		inp();
		ql(1);
		cout<<cnt<<"\n";
	}
}