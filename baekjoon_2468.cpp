// BaekJoon 2468
// Title : 안전 영역
// URL : https://www.acmicpc.net/problem/2468

#include <iostream>
#include <deque>

using namespace std;

bool visit[100][100];
int map[100][100];
int cnt = 0;
int N;

void DFS(int i, int j ,int height){
    visit[i][j] = true;

    if( i > 0 && visit[i-1][j] == false && map[i-1][j] > height ) DFS(i-1,j,height);
    if(i < N - 1 && visit[i+1][j] == false && map[i+1][j] >height) DFS(i+1,j,height);
    if(j > 0 && visit[i][j-1] == false && map[i][j-1] > height) DFS(i,j-1,height);
    if(j < N-1 && visit[i][j+1] == false && map[i][j+1] > height) DFS(i,j+1,height);

}

void sink(int height){
    int new_cnt = 0;

    for(int i = 0 ; i < N; ++i){
        for(int j = 0 ; j < N ; ++j){
            visit[i][j] = false;
        }
    }

    for(int i = 0 ; i < N ; ++i){
        for(int j = 0 ; j < N; ++j){
            if(map[i][j] > height && visit[i][j] == false) { 
                DFS(i,j,height); 
                new_cnt++;
            }
        }
    }
    cnt = max(new_cnt , cnt);
}

int main(int argc, char** argv){
    int max_height = -1;

    cin >> N;

    for(int i = 0 ; i < N ; ++i){
        for(int j = 0 ; j < N ; ++j){
            cin >> map[i][j];
            max_height = max(map[i][j] , max_height);
        }
    }


    for(int i = 0 ; i < max_height ; ++i) sink(i);
    

    cout << cnt;


}