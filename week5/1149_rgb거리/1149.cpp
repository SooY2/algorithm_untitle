//rgb거리
/*
1. n번째의 r= dp[n-1]의 g와 b중 작은거 + rgb의 r값
2. n번째의 g= dp[n-1]의 b와 r중 작은거 + rgb의 g값
3. n번째의 b= dp[n-1]의 r와 g중 작은거 + rgb의 b값

*/

#include <iostream>
#include <algorithm>
using namespace std;

int n, rgb[1000][3] ,D[1000][3],min_idx;

void input(){//rgb배열에 값 입력받기
    cin>>n;
    for(int j=0;j<n;j++){
        for(int i=0;i<3;i++){
            cin>>rgb[j][i];
        }
    }
    return;
}

void dp(){
    D[0][0]=rgb[0][0];
    D[0][1]=rgb[0][1];
    D[0][2]=rgb[0][2];//D배열에 첫 집의 rgb비용 넣어주기

    for(int i=1;i<n;i++){
        D[i][0]=min(D[i-1][1],D[i-1][2])+rgb[i][0];
        D[i][1]=min(D[i-1][2],D[i-1][0])+rgb[i][1];
        D[i][2]=min(D[i-1][0],D[i-1][1])+rgb[i][2];
    }

    return;
}

int main(){
    input();
    dp();

    cout<<*min_element(D[n-1],D[n-1]+3);
    return 0;

}
