#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int baris, kolom;
    int index = 1;
    cin >> baris >> kolom;
    int b, k;
    int step;
    while (baris != 0 && kolom != 0){
        step = 1;
        queue<pair<int, pair<int, int> > > q;
        char arr[baris + 1][kolom + 1];
        bool invited[baris + 1][kolom + 1];
        memset(invited, false, sizeof(invited));

        for (int i = 1; i <= baris; i++){
            for (int j = 1; j <= kolom; j++){
                cin >> arr[i][j];
                if (arr[i][j] == 'A'){
                    b = i;
                    k = j;
                    q.push(make_pair(b, make_pair(k, step)));
                    invited[i][j] = true;
                }
                else{
                    invited[i][j] = false;
                }
            }
        }
        int answer = 0;
        printf("Case %d: ", index);
        while (!q.empty()){
            
            //1. turunkan
            
            b = q.front().first;
            k = q.front().second.first;
            step = q.front().second.second;
            int current = arr[b][k];

            
            //2. pop
            q.pop();

            //3. step
            if (b > 1){
                if (invited[b-1][k] == false && arr[b-1][k] == current + 1){
                    q.push(make_pair(b-1, make_pair(k, step + 1)));
                    invited[b-1][k] = true;
                }
            }
            if (b < baris){
                if (invited[b + 1][k] == false && arr[b + 1][k] == current + 1){
                    q.push(make_pair(b + 1, make_pair(k, step + 1)));
                    invited[b+ 1][k] = true;
                }
            }
            if (k > 1){
                if (invited[b][k-1] == false && arr[b][k - 1] == current + 1){
                    q.push(make_pair(b, make_pair(k-1, step + 1)));
                    invited[b][k-1] = true;
                }
            }
            if (k < kolom){
                if (invited[b][k+ 1] == false && arr[b][k + 1] == current + 1){
                    q.push(make_pair(b, make_pair(k+ 1, step + 1)));
                    invited[b][k + 1] = true;
                }
            }
            if (b> 1 && k > 1){
                if (invited[b - 1][k - 1] == false && arr[b - 1][k - 1] == current + 1){
                    q.push(make_pair(b- 1, make_pair(k - 1, step + 1)));
                    invited[b - 1][k - 1] = true;
                }
            }
            if (b > 1 && k< kolom){
                if (invited[b- 1][k + 1] == false && arr[b - 1][k + 1] == current + 1){
                    q.push(make_pair(b- 1, make_pair(k + 1, step + 1)));
                    invited[b - 1][k + 1] = true;
                }
            }
            if (b < baris && k > 1){
                if (invited[b + 1][k - 1] == false && arr[b + 1][k- 1] == current + 1){
                    q.push(make_pair(b+ 1, make_pair(k - 1, step + 1)));
                    invited[b + 1][k - 1] = true;
                }
            }
            if (b < baris && k < kolom){
                if (invited[b + 1][k + 1] == false && arr[b + 1][k + 1] == current + 1){
                    q.push(make_pair(b + 1, make_pair(k + 1, step + 1)));
                    invited[b + 1][k + 1] = true;
                }
            }
            }
        while (!q.empty()){
            q.pop(); 
        }
        
        printf ("%d\n", step);
        cin >> baris >> kolom;
        index++;
    }
}