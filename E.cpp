#include<bits/stdc++.h>
using namespace std;

int main() {

    ios :: sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<pair<int,int>> a(n), ans(n);
        for(int i = 0 ; i < n ; ++i) {
            cin >> a[i].first ;
            a[i].second = i ; 
        }

        sort(a.begin(), a.end(), greater<pair<int,int>>()) ;

        long long sum = 0 ;

        for(auto [x,y] : a) {
            if(x >= k-x) { 
                if(k-x <= m) {
                    sum += 0 ;
                    ans[y].second = k-x ;
                    m -= k-x ;
                }
                else {
                    sum += x - m ;
                    ans[y].first = m;
                    m = 0 ;
                }
            }
            else { 
                sum += x - min(m, x) ;
                ans[y].first = min(m, x) ;
                m -= min(m, x) ;
            }
        }

        if(m % 2 == 0) {
            ans[0].first += m / 2 ;
            ans[0].second += m / 2 ;
        }
        else {
            if(k % 2 == 1) {
                bool ok = 0;
                for(auto [x,y] : a) {
                    if(ans[y].first) {
                        if(m + ans[y].first - (k-x) >= 0) {
                            m += ans[y].first - (k-x);
                            ans[y].first = 0;
                            ans[y].second = k-x ;
                            ok = 1 ;
                            break ;
                        }
                    } 
                    else if(ans[y].second) {
                        if(m + ans[y].second - x >= 0) {
                            m += ans[y].second - x ;
                            ans[y].first = x ;
                            ans[y].second = 0 ;
                            ok = 1 ;
                            break ;
                        }
                    }
                    else if(k <= m) {
                        m -= k ;
                        ans[y].first = 0 ;
                        ans[y].second = k ;
                        ok = 1;
                        break ;
                    }
                }

                ans[0].second += (m + 1) /2;
                ans[0].first += m / 2;

                if(!ok) sum += (1 % k);
            }
            else {
                ans[0].second += (m + 1) / 2;
                ans[0].first += m / 2;
                sum += (1 % k) ;
            }
        }

        cout << sum << '\n' ;
        for(auto [x,y] : ans) cout << x << " " << y << '\n' ;
    }

    return 0;
}
