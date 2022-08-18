// BAEKJOON 1260
// Title : DFS와 BFS
// URL : https://www.acmicpc.net/problem/1260

#include <iostream>
#include <list>
#include <algorithm>
// #include <stack>
#include <queue>

using namespace std;

bool check[1000] = { false };

void DFS(list<int> li[] , int N , int V ){

    check[V-1] = true;
    cout << V << " ";

    for(auto x : li[V-1]){
        if(check[x-1] == false) DFS(li , N , x );
    }
    
}
void BFS(list<int> li[], int N , int V){

    queue<int> q;

    q.push(V);
    check[V-1] = true;
    cout << V << " ";

    while(!q.empty()){

        V = q.front();
        q.pop();

        for(auto x : li[V-1]){
            if(check[x-1] == false){
                q.push(x);
                cout << x << " ";
                check[x-1] = true;
            }
        } 

    }

}

bool comp(pair<int,int> a , pair<int,int> b){

    if(a.first == b.first) return a.second < b.second;

    return a.first < b.first;

}

int main(int argc , char** argv){

    int N , M , V;
    int start , end;

    cin >> N >> M >> V;

    pair<int,int> temp[M];

    list<int> li[N]; // adj list

    // make adj list

    for(int i = 0 ; i < M ; ++i){
        cin >> start >> end;
        temp[i] = make_pair(start , end);

    }

    sort(temp , temp + M , comp);

    for(int i = 0 ; i < M ; ++i){
        li[temp[i].first - 1].push_back(temp[i].second);
        li[temp[i].second -1].push_back(temp[i].first); 
    }



    // print adj list for checking
/*
    for(int i = 0 ; i < N ; ++i){
        cout << "This is " << i+1 << " : ";
        for(auto x : li[i]) cout << x << ' ';
        cout << endl;
    }
*/
    // DFS
    
    DFS(li , N , V );

    cout << "\n";

    for(int i = 0 ; i < N ; ++i) check[i] = false;

    // BFS
    BFS(li , N , V);

}