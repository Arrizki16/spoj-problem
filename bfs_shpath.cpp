#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back


int main(){//INTEST (scanf, fastio scanf, cin cout, fastio cin cout)
    int s;
    scanf ("%d", &s);
    while (s--){
        vector <pair<int,int> > vct[10005];
        bool visited[10005];
        unordered_map <string,int> kota;
        int n;
        scanf ("%d", &n);
        for (int i=1 ; i<=n ; i++){
            string str;
            cin >> str;
            kota[str] = i;
            int t;
            scanf("%d", &t);
            for (int j=1 ; j<=t ; j++){
                int d,c;
                scanf ("%d%d", &d, &c);
                vct[i].pb(mp(d,c));
            }
        }

        int r;
        scanf ("%d", &r);
        // cin >> r;
        for (int i=1 ; i<=r ; i++){
            memset (visited, false, sizeof(visited));
            priority_queue <pair<int,int> > q;

            string a,b;
            cin >> a >> b;
            int finish = kota[b];
            int start = kota[a];
            q.push(mp(0,start));


            while (!q.empty()){
                int step = q.top().first;
                int standing = q.top().second;

                q.pop();
                if (visited[standing]) continue;
                if (standing == finish){
                    cout << abs(step) << "\n";
                    break;
                }
                visited[standing] = true;

                int index = vct[standing].size();
                for (int i=0 ; i<index ; i++){
                    int tujuan = vct[standing][i].first;
                    int cost = vct[standing][i].second;
                    if (visited[tujuan] == false){
                        q.push(mp(step - cost, tujuan));
                    }
                }
            }
        }
    }
}