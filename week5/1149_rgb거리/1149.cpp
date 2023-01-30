//rgb거리
/*
    r  g  b
0|  26 40 83
1|  49 60 57
2|  13 89 99
n|  ...n줄

dp  r               g                b
0|  26              40              83
1|  min(40,83)+49   min(26,83)+60   min(26,40)+83
2|  
n|  ...n줄


1. n번째의 r= dp[n-1]의 g와 b중 작은거 + rgb의 r값
2. n번째의 g= dp[n-1]의 b와 r중 작은거 + rgb의 g값
3. n번째의 b= dp[n-1]의 r와 g중 작은거 + rgb의 b값



****처음 생각한 풀이****
1. rgb중 제일 작은 값 찾기
2. 제일 작은 값을 다음 집 rgb에 다 더하기
3. 그중에서 전의 rgb랑 안겹치는 것들 중 작은것을 제일 작은값으로 설정

--> 다음 rgb가 겹치면 안돼서 제일 작은값을 더한게 최소값이 아닐 수 있음

**채워나갈 곳을 기준으로 생각해보기

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
        D[i][0]=min(D[i-1][1],D[i-1][2])+rgb[i][0];// dp[n-1]의 g와 b중 작은거 + rgb의 r값
        D[i][1]=min(D[i-1][2],D[i-1][0])+rgb[i][1];// dp[n-1]의 b와 r중 작은거 + rgb의 g값
        D[i][2]=min(D[i-1][0],D[i-1][1])+rgb[i][2];// dp[n-1]의 r와 g중 작은거 + rgb의 b값
    }

    return;
}

int main(){
    input();
    dp();

    cout<<*min_element(D[n-1],D[n-1]+3); //마지막 줄에서 가장 작은값 출력
    return 0;

}
