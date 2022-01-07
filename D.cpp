#include<bits/stdc++.h>
using namespace std;

int main() {

    ios :: sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, m, q; cin >> n >> m >> q;
        set<pair<int,int>> s;
        int x = 0, y = 0 ;
        int dir = 0;
        while(1) {
            s.insert({x, y});
            if((x == 0 && y == m) || (x == n && (y == 0 || y == m))) break ;
            if(dir == 0) {
                if(x < n && y < m) ++x, ++ y;
                else if(x == n) --x, ++y, dir = 3;
                else ++x, -- y, dir = 1;
            }
            else if(dir == 1) {
                if(x < n && y > 0) ++x, -- y;
                else if(x == n) --x, --y, dir = 2;
                else ++x, ++y, dir = 0;
            }
            else if(dir == 2) {
                if(x > 0 && y > 0) --x, --y ;
                else if(x == 0) ++x, -- y, dir = 1;
                else --x, ++y, dir = 3;
            }
            else { 
                if(x > 0 && y < m) --x, ++y ;
                else if(x == 0) ++x, ++y, dir = 0;
                else --x, -- y, dir = 2;
            }
        }
        while(q--) {
            int x, y; cin >> x >> y;
            if(s.find({x, y}) != s.end()) cout << "YES\n" ;
            else cout << "NO\n" ;
        }
    }

    return 0;
}
