//------------------------ Un, Deux, Trois, Quatre, Cinq -----------------------//
#include<bits/stdc++.h>
using namespace std;

//Shorthands
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll int
#define ld long double
#define vll vector<ll>
#define vv vector<vll>
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define pll pair<ll,ll>
#define vpll vector<pll>
#define ff first
#define ss second
#define tll tuple<ll,ll,ll>
#define vtll vector<tll> 
#define mt make_tuple
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define vect(a,n) vll a(n); rep(i,0,n) cin>>a[i];
#define all(a) a.begin(),a.end()
#define sortall(a) sort(a.begin(),a.end());

//Debug
#define printv(a) rep(i,0,a.size()) cout<<a[i]<<" "; cout<<endl;
#define pout(p) cout<<"("<<p.ff<<","<<p.ss<<")"<<" ";
#define printvp(a) rep(i,0,a.size()) cout<<"("<<a[i].ff<<","<<a[i].ss<<")"<<" "; cout<<endl;
#define tout(t) cout<<"("<<get<0>(t)<<","<<get<1>(t)<<","<<get<2>(t)<<")"<<endl;
#define trace(x) cout<< '>' << #x << ':' << (x) << "\n";
#define trace2(x,y) cout<< '>' << #x << ':' << (x) << " | " << #y << ':' << (y) << "\n";
#define trace3(a,b,c) cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n";
#define trace4(a,b,c,d) cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<"\n";

//Constants
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
const ll mod = 998244353;
const ll mxN = 1e6+1;
//-------------------------- Six, Sept, Huit, Neuf, Dix ------------------------//
// Keep Calm & Code Fast 

// Lazy Propgation Segment Tree for and Range min query (val,idx) and Range update (inc. all values in range by x)
// It also returns index of min element
struct SegTree {
public:
    ll N;
    vector<pll> seg;
    vll upd;
    SegTree(ll n)
    {
        N = n+1;
        seg.resize(4*N,{0,-1});
        upd.resize(4*N,0);
    }

    void update(ll L,ll R,ll x,ll nd=0,ll l=0,ll r=-1)
    {
        if(r==-1) r=N-1;
        ll m=(l+r)/2, lnd=2*nd+1, rnd=2*nd+2;
    
        seg[nd].ff+=upd[nd];
        if(l!=r)
        {
            upd[lnd]+=upd[nd];
            upd[rnd]+=upd[nd];
        }
        upd[nd]=0; 
    
        if(r<L || R<l) return; 
        if(r==l)
        { 
            seg[nd].ff+=x;
            seg[nd].ss=l;
            return; 
        }
        if(L<=l && r<=R) 
        {
            seg[nd].ff+=x;
            upd[lnd]+=x; 
            upd[rnd]+=x;
            return;
        }
        
        update(L,R,x,lnd,l,m);
        update(L,R,x,rnd,m+1,r);
        seg[nd] = min(seg[lnd],seg[rnd]);
    }

    pair<ll,ll> query(ll L,ll R,ll nd=0,ll l=0,ll r=-1)
    {
        if(r==-1) r=N-1;
        ll m=(l+r)/2, lnd=2*nd+1, rnd=2*nd+2;
    
        seg[nd].ff+=upd[nd];
        if(l!=r)
        {
            upd[lnd]+=upd[nd];
            upd[rnd]+=upd[nd];
        }
        upd[nd]=0;
    
        if(r<L || R<l) return {INF,-1}; 
        if(r==l) return {seg[nd].ff,l}; 
        if(L<=l && r<=R) return seg[nd];
       
        pll q1=query(L,R,lnd,l,m);
        pll q2=query(L,R,rnd,m+1,r);
        seg[nd] = min(seg[lnd],seg[rnd]);
        return min(q1,q2);
    }
};


void solve()
{
    ll n,k; cin >> n >> k;
    vect(a,n);
    
    SegTree s(n);
    rep(i,0,n) s.update(i,i,a[i]);
    
    vll p(n,0);
    ll x = 1;
    set<ll> z;
    while(x <= n)
    {
        while(1)
        {
            pll q = s.query(0,n-1);
            if(q.ff == 0) 
            {
                z.insert(q.ss);
                s.update(q.ss, q.ss, INF);
            }
            else break;
        }
        if(z.empty())
        {
            cout << -1 << endl;
            return;
        }
        
        
        ll idx = -1;
        if(z.size() == 1)
        {
            idx = *z.begin();
        }
        else
        {
            ll start = *z.begin(), end = *z.rbegin();
            if(n - end + start > k) idx = start;
            else
            {
                ll prev = start;
                for(auto x: z)
                {
                    if(x == start) continue;
                    if(x - prev > k){
                        idx = x;
                        break;
                    }
                    prev = x;
                }
            }
        }
        
        if(idx == -1)
        {
            cout << -1 << endl;
            return;
        }
        
        p[idx] = x++;
        z.erase(idx);
        
        if(idx-k >= 0) 
        {
            s.update(idx-k, idx-1, -1);
        }
        else
        {
            if(idx != 0) s.update(0, idx-1, -1);
            ll rem = k-idx;
            s.update(n-rem, n-1, -1);
        }
    }
    
    printv(p);

}


int main()
{
	fastio; 
    int tc; cin>>tc; while(tc--)
    solve();
}





