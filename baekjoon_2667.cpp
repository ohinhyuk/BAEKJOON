// BaekJoon 2667
// Title : 단지번호붙이기
// URL : https://www.acmicpc.net/problem/2667

#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

// DFS function

void DFS(deque<deque<bool>> &visit , deque<deque<int>> map , int i , int j , int &cnt){
    visit[i][j] = true;
    cnt++;

    if( i > 0 && visit[i-1][j] == false && map[i-1][j] == 1) DFS(visit,map ,i-1,j , cnt);                   // checking left
    if(i < (visit.size()-1) && visit[i+1][j] == false && map[i+1][j] == 1) DFS(visit,map, i+1 , j, cnt);    // checking right
    if(j > 0 && visit[i][j-1] == false && map[i][j-1] == 1) DFS(visit,map,i,j-1, cnt);                      // checking up
    if(j < (visit.size()-1) && visit[i][j+1] == false && map[i][j+1] == 1) DFS(visit,map,i,j+1 , cnt);      // checking down

}

int main(int argc , char** argv){

    int N;
    int num = 0;
    string s;

    cin >> N;

    // Deque init
    deque<deque<int>> map(N , deque<int>(N,0));
    deque<deque<bool>> visit(N , deque<bool>(N,false));
    deque<int> result;

    // making map

    for(int i = 0 ; i < N ; ++i){
            cin >> s;

            for(int j = 0 ; j < N ; ++j){
                map[i][j] = s[j] - '0';
            }
    }

    for(int i = 0 ; i < N ; ++i){
        for(int j = 0 ; j < N ; ++j){
            if(visit[i][j] == false && map[i][j] == 1){
                int cnt = 0;
                DFS(visit,map,i,j,cnt);
                num++;
                result.push_back(cnt);
            }
        }
    }

    sort(result.begin() , result.end());

    result.push_front(num);

    for(int x : result) cout << x << '\n';

}