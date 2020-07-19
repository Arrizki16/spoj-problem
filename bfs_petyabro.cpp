#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

vector<pair<int, int>> adj[100005];
priority_queue<pair<int, int>> pq;
bool visited[100005];

int main(){

    int t;
    cin >> t;
    while (t--){
        int v, e;
        cin >> v >> e;
        memset(adj, 0, sizeof(adj));
        for (int i = 1; i <= e; i++){
            int a, b, c;
            cin >> a >> b >> c;
            adj[a].pb(mp(b, c));
        }

        memset(visited, false, sizeof(visited));
        while (!pq.empty()){
            pq.pop();
        }
        int x, y;
        cin >> x >> y;
        pq.push(mp(0, x));

        int step = -1;
        while (!pq.empty()){
            int temp = 0;
            int jarak = pq.top().first;
            int standing = pq.top().second;

            if (standing == y){
                step = abs(jarak);
                break;
            }

            pq.pop();
            visited[standing] = true;

            int size = adj[standing].size();


            for (int i = 0; i < size; i++){
                int tujuan = adj[standing][i].first;
                int cost = adj[standing][i].second;
                // cout << cost << " " << tujuan << "\n";

                if (visited[tujuan] == false){
                    pq.push(mp(jarak - cost, tujuan));
                }
            }
        }
        if (step == -1){
            cout << "NO\n";
        }
        else
            cout << step << "\n";
    }
}