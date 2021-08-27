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
const double pi = 2*acos(0.0);
const double eps = 1e-7 ;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    map<int,bool> check_;
    for(int i=2;i<100;i++){
        bool flag=1;
        for(int j=2;j<=sqrt(i);j++){
            if(i%j==0){
                flag=0;
                break;
            }
        }
        if(flag) check_[i]=1;
    }

    int tt;cin>>tt;
    while(tt--){
        int k; cin>>k;
        vector<char> s(k);
        bool flag=0;
        int min_ = 10;
        //22573
        //2
        //2
        //5
        //6
        //7
        //1
        //3
        for(auto &c:s){
            cin>>c;
            if(!check_.count(c-'0'))     min_ = min(min_,c-'0');      
        }

        if(min_!=10){
            cout<<"1\n"<<min_<<nl;
            continue;
        }
        cout<<"2\n";
        vector<int> mt(10,0);
        vector<vector<int>> arr(k);
        for(int i=k-1;i>=0;i--){
            arr[i]=mt;
            mt[s[i]-'0']++;
        }
        // for(auto&item:arr){
        //     for(int i=0;i<10;i++) cout<<item[i]<<" ";
        //     cout<<nl;
        // }

        // arr[i] <-> s[i]
        // arr[i][0->9] -> đằng sau thằng s[i] có những chữ số nào
        min_ = 100;
        for(int i=0;i<k-1;i++){
            int ans=(s[i]-'0')*10;
            for (int j=0;j<10;j++){
                if(arr[i][j]) {
                    if(!check_.count(ans+j)) min_=min(min_,ans+j);
                    // cout<<ans+j<<" ";
                }
                
            }
            // cout<<nl;
        }
        cout<<min_<<nl;
        // số bé nhất sau khi xoá bất kỳ ký tự nào trong chuỗi s được số không phải 
        // là số nguyên tố 
        // s = 225733
        // 0 1 2 3 4 6
        // s[i] = 2 ,arr[0][0->9] = [0,0,1,2,0,1,0,1,0,0]
        // s[i] = 2 ,arr[1][0->9] = [0,0,0,2,0,1,0,1,0,0]
        // s[i] = 5 ,arr[2][0->9] = [0,0,0,2,0,0,0,1,0,0]
        // s[i] = 7 ,arr[3][0->9] = [0,0,0,2,0,0,0,0,0,0]
        // s[i] = 3 ,arr[4][0->9] = [0,0,0,1,0,0,0,0,0,0]
        // s[i] = 3 ,arr[5][0->9] = [0,0,0,0,0,0,0,0,0,0]
        // 10^4 * 10
        // 1 4 6 8 9 -> kp SNT 
        // 2357
        // x o o
        // o o x 
        // o x o
        // 72 73 77

        // x 1 2 3 4 5 6 7 8 9
        // 1 x o x o o o x o x
        // 2 o o x    
        // 3
        // 4
        // 5
        // 6
        // 7
        // 8
        // 9



        // s[i] = 2 -> ans = 20; arr[0][0->9] = [x,x,22,23,x,25,x,27,x,x]
        // s[i] = 2 -> ans = 20; arr[0][0->9] = [x,x,x,23,x,25,x,27,x,x]
        // s[i] = 5 -> ans = 50; arr[0][0->9] = [x,x,x,53,x,x,x,57,x,x]
        // s[i] = 7 -> ans = 70; arr[0][0->9] = [x,x,x,73,x,x,x,x,x,x]
        // s[i] = 3 -> ans = 30; arr[0][0->9] = [x,x,x,33,x,x,x,x,x,x]
        // s[i] = 3 -> ans = 30; arr[0][0->9] = [x,x,x,x,x,x,x,x,x,x]
        
        // 7
        //       0  1  2  3   4   5   6
        // base  5  1  2  6   10  5   12
        // sum   5  6  8  14  24  29  41
        // l -> r
        // 3 -> 5 = 21    
        // sum[r]-sum[l] + base[l] = 29 - 14 + 6= 15
        // 2 -> 4 = 18
        // sum[r]-sum[l] + base[l] = 24 - 8 + 2 = 18

        // O(1)
        // max(10^5,10^3)

        // n = 10^5 
        // q 10^3 lần truy vấn
        // 10^8 (n*q)
        // l->r







        // n
        // q
        // n = 10^5 
        // q 10^3 lần truy vấn
        // 10^8 (n*q)
        // l r p thực hiện l->r +=p
        // Sau q lần truy vấn in giá trị bé trong mảng nhất?

        //                          0  1   2  3   4   5   6
        // base                     5  1   2  6   10  5   12
        // sump                     0  0   0  0   0   0   0

        // q=1
        // base                     5  1   2  6   10  5   12
        // l = 3, r=5, p = 2        5  1   2  8   12  7   12
        // sump                     0  0   0  2   0   0  -2

        // t=0                      0  0   0  2   2   2   0
        // last_sum                 0  0   0  2   2   2   0

        // q=2
        //l = 0, r=4, p =-3         2 -2  -1  5   9   7   12
        // sump                    -3  0   0  2   0   3  -2

        // t                       -3 -3  -3 -1  -1   2   0
        // last_sum                -3 -3  -3 -1  -1   2   0


        // sump                    -3 -3  -3 -1  -1   2   0
        // base                     5  1   2  6   10  5   12 
        // ans                      2 -2  -1  5   9   7   12


        // sum[l] +=p;
        // sum[r+1] -=p;

                 



    }
    return 0;
}