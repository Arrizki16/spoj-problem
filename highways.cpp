#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

vector <pair<int , int> > vct[100005];
priority_queue <pair<int,int> > pq;
pair <int, int> memo[100005];
bool visited[100005];

int main(){
    int t;
    cin >> t;
    while (t--){
        memset (memo, 0 , sizeof(memo));
        memset (visited, false, sizeof(visited));
        int n,e,x,y;
        cin >> n >> e >> x >> y;
        for(int i=1 ; i<=e ; i++){
            int a,b,w;
            cin >> a >> b >> w;
            vct[a].pb(mp(b,w));
            vct[b].pb(mp(a,w));
        }

        pq.push(mp(0,x));
        memo[x].first = 0;
        memo[x].second = 0;
        int flag = -1;
        while (!pq.empty()){
            int jarak = pq.top().first;
            int standing = pq.top().second;
            pq.pop();

            if (standing == y){
                flag = abs(jarak);
                break;
            }
            visited[standing] = true;

            int index = vct[standing].size();
            for (int i=0 ; i<index  ; i++){
                int tujuan = vct[standing][i].first;
                int cost = vct[standing][i].second;
                if (visited[tujuan] == false){
                    pq.push(mp(jarak-cost, tujuan));
                }
            }
        }
        if (flag == -1){
            cout << "NONE" << "\n";
        }
        else cout << flag << "\n";
    }
}