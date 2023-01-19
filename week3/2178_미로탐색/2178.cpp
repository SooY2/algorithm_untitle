/* 2178 미로탐색

미로의 n,m위치로 가는 최소경로구하기
큐에 1,1넣고 방문체크,cnt++ bfs함수 ㄱㄱ
1. q.front() 변수에 저장
2. q.pop()
3. q.front()의 상하좌우가 1이고, 방문안했고, 미로안이면 큐에 넣어주기

최단거리....
1,1로부터의 거리 저장하기

시간복잡도 O(n*m)

*/
/*
거리 따로 배열 선언안해주고 miro에+=로 거리 저장하면 메모리 줄일 수 있음!
*/
#include <iostream>
#include <queue>
using namespace std;

int n,m;
char miro[100][100]={0};//미로
int check[100][100]={0};//0,0으로부터의 거리 적어줄 배열
bool visited[100][100]={0};//방문체크 false로 초기화
int r[4]={-1,1,0,0};
int c[4]={0,0,-1,1};
queue<pair<int,int>> q; //두개의 원소 한번에 넣어줄 큐

void bfs(int x,int y){

    q.push({x,y});
    visited[x][y]=true;
    check[x][y]=1;

    while(!q.empty()){
        int pos_r,pos_c;
        int next_r,next_c;

        pos_r=q.front().first; //큐의 front의 첫원소 = 행
        pos_c=q.front().second;//큐의 front의 두번째 원소 =열

        q.pop();

        for(int i=0;i<4;i++){
            next_r=pos_r+r[i];
            next_c=pos_c+c[i];//다음으로 검사할 원소의 위치값
            if(next_r>=0&&next_r<n&&next_c>=0&&next_c<m&&miro[next_r][next_c]=='1'&&visited[next_r][next_c]==false){
            //미로안에 있고, 값이 '1'이고, 방문을 안했으면
                q.push({next_r,next_c});//큐에 넣어주기
                visited[next_r][next_c]=true;
                check[next_r][next_c]=check[pos_r][pos_c]+1;
            }
        }
    }
    return ;
}


int main(){

    
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>miro[i][j];
        }
    }//입력받기


    bfs(0,0);
    
    cout<<check[n-1][m-1];
    return 0;

}
