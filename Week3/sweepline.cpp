#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define prec(n) fixed<<setprecision(n)
using namespace std;
typedef long long ll;
typedef unsigned long long int ull ;
 
const int MOD=1e9+7;
const char nl = '\n';
const double EPS =1e-9;
const double pi = 2*acos(0.0);
 
 
double DEG_to_RAD(double d) { return d * pi / 180.0; }
double RAD_to_DEG(double r) { return r * 180.0 / pi; }
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // Ví dụ, có một nhà hàng mở cửa đón khách, họ có thời gian ra vào của một khác hàng
    // Tính số người tối đa trong cửa hàng tại một thời điểm
 
    // n = 10^5
    // in out 1 -> 10^9
    // 5
    //0    2 5
    //1    3 4
    //2    1 10
    //3    5 10
    //4    6 7

    
    //     1  2  3  4  5  6  7  8  9  10
    // 0      1       -1 
    // 1         1 -1
    // 2   1                          -1
    // 3               1              -1 
    // 4                  1 -1
    
    
    // [1] +1
    // [2] +1
    // [3] +1
    // [4] -1
    // [5] -1
    // [5] +1
    // [6] +1
    // [7] -1
    // [10] -2
    
    // 2,1  5,-1    3,1  4,-1   1,1  10,-1  5,1  10,-1  6,1  7,-1
    int n; cin>>n;
    int ans=0;
    
    vector<pair<int,int>> sweepline;
    
    // 1->n
    
    // in out
    // (in,1)
    // (out,-1)
    // 2*n
    // a[in]+=1;
    // a[out]-=1;
    
    // O(n);
    // a[time] 2*10^5

    // out = 10^7
    
    // sweep line
    for(int i=0;i<n;i++){
        int in_,out_; cin>>in_>>out_;
        sweepline.pb(mp(in_,1));
        sweepline.pb(mp(out_,-1));
    }
    
    // cout<<"Before\n";
    // for(auto &item:sweepline) cout<<item.fi<<" "<<item.se<<nl;
    
    sort(all(sweepline));
    // cout<<"After\n";
    // for(auto &item:sweepline) cout<<item.fi<<" "<<item.se<<nl;
    int count=0;
    for(auto &item:sweepline) {
        count+=item.se;
        ans=max(ans,count);
    }
    cout<<ans<<nl;


    
    return 0;
}