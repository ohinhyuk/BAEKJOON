// BaekJoon 10451
// Title : 순열 사이클
// URL : https://www.acmicpc.net/problem/10451

#include <iostream>
#include <vector>

using namespace std;


// DFS recursion

void DFS(vector<vector<bool>> &arr ,vector<bool> &check ,int i){
    check[i-1] = true;
    for(int j = 1 ; j <= check.size(); ++j){
        if(arr[i-1][j-1] == true && check[j-1] == false) DFS(arr,check, j );
    }
}

int main(int argc , char** argv){

    int T , N , temp;
    
    cin >> T;

    while(T--){

        int cnt = 0;        // answer

        cin >> N;

        vector<vector<bool>> arr(N , vector<bool>(N , false));      // adj matrix
        vector<bool> check ( N , false );                           // check list
        
        for(int i = 1 ; i <= N ; ++i){

            cin >> temp;

            arr[i-1][temp - 1] = true;
            arr[temp-1][i-1] = true;

        }

        for(int i = 1 ; i <= N ; ++i){
            if(check[i-1] == false){
                DFS(arr , check, i );       // DFS or BFS
                cnt++;
            }
        }

        cout << cnt << endl;

    }

}