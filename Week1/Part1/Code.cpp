#include <bits/stdc++.h>
// Viết tắt để có thể dễ dàng dùng hơn

using namespace std;

// Định nghĩa các kiểu dữ liệu để có thể gọi đến không tốn thời gian.
typedef vector<int> vi;

int main(){  
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    // Example map
    map<int,int> m;
    m[1]=1;
    m[3]=5;
    m[5]=2;
    m[10] = 0;
    m[7] = 1;
    m[1000000] = 1;
    int key_ = 0;
    // check exist 
    if(m.count(key_))    cout<<"YES\n";
    else cout<<"NO\n";

    //get element in map
    for(auto &item:m) cout<<item.first<<" "<<item.second<<endl;

    // set
    set <int> s;

    // pair

    pair<int,int> ii;
    // method 1
    ii.first = 1;
    ii.second = 2;
    // method 2
    ii = make_pair(1,2);

    
    return 0;
}