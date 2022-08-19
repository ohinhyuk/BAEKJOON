// BaekJoon 2606
// Title : Virus
// URL : https://www.acmicpc.net/problem/2606

#include <iostream>
#include <deque>

using namespace std;

deque<int> adj_list[100];
deque<bool> check(100 , false);

void DFS(int i , int &cnt){
    check[i-1] = true;

    for(int j = 0 ; j < adj_list[i-1].size() ; ++j){
        if(check[adj_list[i-1][j] - 1] == false){ DFS( adj_list[i-1][j], cnt) ; cnt++; }
    }
}

int main(int argc , char** argv){

    int cmpr , num , first , second;
    int cnt = 0;

    cin >> cmpr >> num;

    while(num--){
        
        cin >> first >> second;

        adj_list[first - 1].push_back(second);
        adj_list[second - 1].push_back(first);

    }
    
    DFS(1 , cnt);
    
    cout << cnt;
}


