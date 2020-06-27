#include <bits/stdc++.h>
using namespace std;

#define mp make_pair

bool visited[51][51];
stack <pair<int,pair<int,int>>> s;
char arr[51][51];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int baris, kolom;
    cin >> baris >> kolom;
    int index = 1;
    int b,k;
    while (baris!=0 && kolom != 0){
        int flag = 1;
        memset (visited, false, sizeof(visited));

        int step = 1;
        for (int i=1 ; i<=baris ; i++){
            for (int j=1 ; j<=kolom ; j++){
                cin >> arr[i][j];
                if (arr[i][j] == 'A'){
                    b = i;
                    k = j;
                    s.push(mp(b,mp(k,step)));
                    visited[i][j] = true;
                    flag++;
                }
                else visited[i][j] = false;
            }
        }
        printf ("Case %d: ", index);

        int answer = 0;
        while (!s.empty()){
            b = s.top().first;
            k = s.top().second.first;
            step = s.top().second.second;
            int current = arr[b][k];

            // printf ("%d %d %d %d\n",b,k,step,current);

            s.pop();

            // printf ("%d %d %d %d\n", b, k ,step , current);

            if (b > 1){
                if (visited[b - 1][k] == false && arr[b - 1][k] == current + 1){
                    s.push(make_pair(b - 1, make_pair(k, step + 1)));
                    visited[b - 1][k] = true;
                    // current++;
                    // printf("atas\n");
                }
            }
            if (b < baris){
                if (visited[b + 1][k] == false && arr[b + 1][k] == current + 1){
                    s.push(make_pair(b + 1, make_pair(k, step + 1)));
                    visited[b + 1][k] = true;
                    // current++;
                    // printf("bawah\n");
                }
            }
            if (k > 1){
                if (visited[b][k - 1] == false && arr[b][k - 1] == current + 1){
                    s.push(make_pair(b, make_pair(k - 1, step + 1)));
                    visited[b][k - 1] = true;
                    // current++;
                    // printf("kiri\n");
                }
            }
            if (k < kolom){
                if (visited[b][k + 1] == false && arr[b][k + 1] == current + 1){
                    s.push(make_pair(b, make_pair(k + 1, step + 1)));
                    visited[b][k + 1] = true;
                    // current++;
                    // printf("kanan\n");
                }
            }
            if (b > 1 && k > 1){
                if (visited[b - 1][k - 1] == false && arr[b - 1][k - 1] == current + 1){
                    s.push(make_pair(b - 1, make_pair(k - 1, step + 1)));
                    visited[b - 1][k - 1] = true;
                    // current++;
                    // printf("atas kiri\n");
                }
            }
            if (b > 1 && k < kolom){
                if (visited[b - 1][k + 1] == false && arr[b - 1][k + 1] == current + 1){
                    s.push(make_pair(b - 1, make_pair(k + 1, step + 1)));
                    visited[b - 1][k + 1] = true;
                    // current++;
                    // printf("atas kanan\n");
                }
            }
            if (b < baris && k > 1){
                if (visited[b + 1][k - 1] == false && arr[b + 1][k - 1] == current + 1){
                    s.push(make_pair(b + 1, make_pair(k - 1, step + 1)));
                    visited[b + 1][k - 1] = true;
                    // current++;
                    // printf("bawah kiri\n");
                }
            }
            if (b < baris && k < kolom){
                if (visited[b + 1][k + 1] == false && arr[b + 1][k + 1] == current + 1){
                    s.push(make_pair(b + 1, make_pair(k + 1, step + 1)));
                    visited[b + 1][k + 1] = true;
                    // current++;
                    // printf("bawah kanan\n");
                }
            }
            if (arr[b][k] == current && visited[b][k] == true){
                memset(visited, false, sizeof (visited));
            }
        }
        while (!s.empty()){
            s.pop();
        }
        
        answer = max(answer, step);

        

        
        printf("%d\n", answer);
        cin >> baris >> kolom;
        index++;
    }
}