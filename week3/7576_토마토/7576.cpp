/*7576 토마토
익은 토마토(1)의 상하좌우에 있는 안익은 토마토(0)들은 하루 후 익음, 이때 다 익으려면 몇일이 걸리는지. -1이면 토마토 없음
모두 익지 못하는 상황이면 -1출력



토마토 상자 2차원 벡터 생성
며칠째인지 저장하는 배열 생성

1. for문 돌며 1이거 다 큐에 넣어주고나서 너비우선탐색 ㄱㄱ
2. 방문표시, 몇일째인지 ++, 
3. q.front값 저장해놓고 pop
4. 상하좌우 (box안인지,방문했는지,0인지)검사해서 true 면
4-1. 큐에 좌표 넣어주기
4-2. 방문표시 해주고, days++


어려웠던점
처음에 for문 돌며 1일때의 좌표를 큐에 다 넣어준 후 bfs를 하면 되는데,
for문에서 1이 나올 때마다 bfs를 하고 또 1이 나오면 bfs를 해서 일수가 가장 적은날짜로 설정하려해서 시간초과가 나왔다.
큐는 어차피 먼저 들어온게 먼저 나가므로 1인걸 다 넣어주면 점점 넓게 탐색 가능하다. 

시간복잡도 O(n*m)->O(n^2)
*/

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int n,m;
int pos_x,pos_y,nx,ny;
int r[2][4]={{-1,1,0,0},{0,0,-1,1}};
int days[1000][1000]={0};//며칠째에 익는지 일수 저장할 배열
bool visited[1000][1000]={0};
vector<vector <int>> box;
//vector<vector <bool>> visited;
//int box[1000][1000];

deque<pair<int,int>> q;

bool isinside(int x, int y){
    return (x>=0&&y>=0&&x<m&&y<n);
}


int main(){
    cin>>n>>m;

    box=vector<vector<int>>(m,vector<int>(n,0));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>box[i][j];
        }
    } //입력받기

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(box[i][j]==1){
                q.push_back({i,j});
                visited[i][j]=true;

            }
        }
    }//탐색 후 1이면 큐에 넣어주기

    while(!q.empty()){ //큐가 비면 탈출
        pos_x=q.front().first;
        pos_y=q.front().second;

        q.pop_front();

        for(int i=0;i<4;i++){
            nx=pos_x+r[0][i];
            ny=pos_y+r[1][i];

            if(isinside(nx,ny)&&box[nx][ny]==0&&visited[nx][ny]==false){
            // 박스 안에 있고 안익은 토마토0이고 방문하지 않았으면
                q.push_back({nx,ny});//큐에 넣어주기
                visited[nx][ny]=true;//방문표시
                days[nx][ny]=days[pos_x][pos_y]+1;
                
            }
        }

    }

    //출력
    int result =0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(box[i][j]==0&&days[i][j]==0){
                cout<< -1;
                return 0;
            }
            if(result<days[i][j]){
                result=days[i][j];
            }
            
        }
    }
    cout<<result;
    return 0;
}

