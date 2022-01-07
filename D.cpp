#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int n, m; 
    cin >> n >> m;
    int illuminated[n + 1][m + 1];
    memset(illuminated, 0, sizeof(illuminated));
    illuminated[0][0] = 1;
    int x = 0, y = 0, d = 0;
    while(1)
    {
        if(d == 0)
        {
            x++; 
            y++;
        }
        else if(d == 1)
        {
            x++;
            y--;
        }
        else if(d == 2)
        {
            x--;
            y--;
        }
        else if(d == 3)
        {
            x--;
            y++;
        }
 
        illuminated[x][y] = 1;
 
        // Hits a corner
        if((x == 0 || x == n) && (y == 0 || y == m)) break;
        
        // Hits a wall
        if(x == 0)
        {
            if(d == 2) d = 1;
            else if(d == 3) d = 0;
        }
        else if(x == n)
        {
            if(d == 0) d = 3;
            else if(d == 1) d = 2;
        }
        else if(y == 0)
        {
            if(d == 1) d = 0;
            else if(d == 2) d = 3;
        }
        else if(y == m)
        {
            if(d == 0) d = 1;
            else if(d == 3) d = 2;
        }
    }
 
    int q; 
    cin >> q;
    while(q--)
    {
        int x, y; 
        cin >> x >> y;
        if(illuminated[x][y]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
