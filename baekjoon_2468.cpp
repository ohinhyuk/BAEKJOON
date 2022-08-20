#include <iostream>
#include <deque>

using namespace std;

bool visit[100][100];
int map[100][100];
int cnt = 0;

void DFS(int i, int j ,int N){
    visit[i][j] = true;

    if( i > 0 && visit[i-1][j] == false && map[i-1][j] > N ) DFS(i-1,j,N);
    if(i < N - 1 && visit[i+1][j] == false && map[i+1][j] >N) DFS(i+1,j,N);
    if(j > 0 && visit[i][j-1] == false && map[i][j-1] > N) DFS(i,j-1,N);
    if(j < N-1 && visit[i][j+1] == false && map[i][j+1] > N) DFS(i,j+1,N);

}

void sink(int height,int N){
    int new_cnt = 0;
    visit[100][100] = {false};

    for(int i = 0 ; i < N ; ++i){
        for(int j = 0 ; j < N; ++j){
            if(map[i][j] > height && visit[i][j] == false) { DFS(i,j,height); new_cnt++;}
        }
    }
    cnt = max(new_cnt , cnt);
}

int main(int argc, char** argv){
    int N;
    int max_height = -1;

    cin >> N;

    for(int i = 0 ; i < N ; ++i){
        for(int j = 0 ; j < N ; ++j){
            cin >> map[i][j];
            max_height = max(map[i][j] , max_height);
        }
    }

    // for(int i = 0 ; i < N ; ++i){
    //     for(int j = 0 ; j < N ; ++ j){
    //         // DFS
    //         if( map[i][j] > N && visit[i][j] == false){ DFS(i,j,N); cnt++;}
    //     }
    // }
    for(int i = 1 ; i < max_height ; ++i){
        sink(i,N);
    }

    cout << cnt;


}