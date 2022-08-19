// BaekJoon 2606
// Title : Virus
// URL : https://www.acmicpc.net/problem/2606

#include <iostream>
#include <deque>

using namespace std;

void DFS(deque<int> adj_list[] ,deque<bool> &check , int i , int &cnt){
    check[i-1] = true;

    for(int j = 0 ; j < adj_list[i-1].size() ; ++j){
        if(check[adj_list[i-1][j] - 1] == false){ DFS(adj_list,check , adj_list[i-1][j], cnt) ; cnt++; }
    }
}

int main(int argc , char** argv){

    int cmpr , num , first , second;
    int cnt = 0;

    cin >> cmpr >> num;

    deque<int> adj_list[cmpr];
    deque<bool> check(cmpr , false);
    
    while(num--){
        
        cin >> first >> second;

        adj_list[first - 1].push_back(second);
        adj_list[second - 1].push_back(first);

    }
    
    DFS(adj_list , check , 1 , cnt);
    
    cout << cnt;
}


