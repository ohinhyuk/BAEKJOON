// BaekJoon 2331
// Title : 반복 수열
// URL : https://www.acmicpc.net/problem/2331

#include <iostream>
#include <cmath>
#include <deque>
#include <algorithm>

using namespace std;

int next_num(int D , int P){
    int total = 0;
    
    while(D > 0){ 
        total += pow( (D % 10) , P);
        D /= 10;
    }
    return total;
}

int main(int argc , char** argv){
    int A , P , num;
    deque<int> dq;
    deque<int> ::iterator iter;

    cin >> A >> P;

    dq.push_back(A);

    while(1){

        A = next_num(A , P);
        iter = find(dq.begin() , dq.end() , A);
        if(iter != dq.end()){
            num = iter - dq.begin();
            break;
        }

        dq.push_back(A);
    }

    cout << num;

}