#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

int main(){
    long long n,m;
    cin >> n >> m;

    long long milkman[n+2];
    bool visited[n+2];
    vector <pair <long long, long long> > vct[n+2];
    priority_queue <pair<long long,pair<long long,long long> > > pq;

    memset(milkman, 0, sizeof(milkman));
    memset(visited, false, sizeof(visited));

    long long temp = 0;
    for (long long i=1 ; i<=n ; i++){
        cin >> milkman[i];
        if (milkman[i] == 1){
            pq.push(mp(0,mp(0,i)));
            visited[i] = true;
            temp++;
        }
    }
    for (long long i=1 ; i<=m ; i++){
        long long a,b,w;
        cin >> a >> b >> w;
        vct[a].pb(mp(b,w));
        vct[b].pb(mp(a,w));
    }
    
    long long ans = 0;
    while (!pq.empty()){
        long long sum = pq.top().first;
        long long ori = pq.top().second.first;
        long long standing = pq.top().second.second;

        pq.pop();
        if (visited[standing] == false){
            ans += abs(ori);
            visited[standing] = true;
            temp++;
        }
        if (temp == n) break;

        long long index = vct[standing].size();
        for (long long i=0 ; i<index ; i++){
            long long tujuan = vct[standing][i].first;
            long long cost = vct[standing][i].second;
            if (visited[tujuan] == false){
                pq.push(mp(sum-cost,mp (0-cost, tujuan)));
            }
        }
    }
    if (temp != n){
        cout << "impossible" << "\n";
    }
    else cout << ans << "\n";   
}