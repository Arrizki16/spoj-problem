#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

// k = number of coins
// n = number of cities
// r = total roads
// s = start
// d = tujuan
// l = road length
// t = toll (pajak)

int main(){
    int tcase;
    scanf ("%d", &tcase);
    while (tcase--){
        int k,n,r;
        scanf ("%d%d%d", &k,&n,&r);
        
        vector <pair <int,pair<int, int> > > vct[n+1];
        // bool visited [n+1];
        priority_queue <pair<int,pair<int,int> > > pq;
        
        for (int i=1 ; i<=r ; i++){
            int s,d,l,t;
            scanf ("%d%d%d%d", &s, &d, &l, &t);
            vct[s].pb(mp(d,mp(l,t)));
        }
        // road , coins , asal
        // memset(visited , false , sizeof(visited));
        pq.push(mp(0, mp(0,1)));
        int temp = 0;
        int flag = 0;
        while (!pq.empty()){
            int road = pq.top().first;
            int coins = pq.top().second.first;
            int standing = pq.top().second.second;

            pq.pop();
            if (standing == n){
                temp = abs(road);
                flag = 1;
                break;
            }
            // visited[standing] = true;

            int index = vct[standing].size();
            for (int i=0 ; i<index ; i++){
                int tujuan = vct[standing][i].first;
                int length = vct[standing][i].second.first;
                int toll = vct[standing][i].second.second;
                // if (visited[tujuan] == false && abs(coins-toll) <= k){
                if (abs(coins-toll) <= k){
                    pq.push(mp(road-length,mp(coins-toll, tujuan)));
                }
            }
        }
        if (flag == 1){
            cout << temp << "\n";
        }
        else cout << "-1" << "\n";
    }
}