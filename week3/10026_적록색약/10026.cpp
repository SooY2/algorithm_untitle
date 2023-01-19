/* 10026 적록색약

정상인 r,g,b 를 각각 하나의 구역으로해서 숫자세기
적록색약 rg(하나로),b를 각각 하나의 구역으로해서 숫자세기

rgb 배열로 입력받기
int 정상인구역개수,적록색약구역개수
N 이중for문 돌며 bfsㄱㄱ

정상인 bfs(char c) 
큐
큐에 c넣기,방문표시

큐가 비었으면 탈출
1.pos=q.front 앞에거 저장
2.팝해주기
3. 상하좌우검사
3-1. 다음게 pos고, 방문안했고, 안에있으면 큐에 넣어주기 정상인구역개수++
4. 정상인구개수가 0보다 크면 최종 정상인구카운트++

정상인 bfs(char c) 
큐2
큐2에 c넣기,방문표시

큐가 비었으면 탈출
1.pos=q.front 앞에거 저장
2.팝해주기
3. 상하좌우검사
3-1. pos가 r||g면 / 다음게 r이나 b고, 방문안했고, 안에있으면 큐에 넣어주기 정상인구역개수++
3-2. pos가 b이면 / 다음게 pos이고 방문안했고, 안에있으면 큐에 넣어주기 적록인구개수++
4. 적록인구개수 0보다 크면 최종적록인구카운트++;



*/
#include <iostream>
#include <queue>
using namespace std;


int N;//입력 줄개수
int nomalcnt,rgcnt;//총 구역 개수
char rgb[100][100];//rgb입력받을 배열
bool n_visited[100][100];
bool rg_visited[100][100];

int xy[2][4]={{-1,1,0,0},{0,0,-1,1}};

bool inside(int x, int y){
    return ((x>=0&&y>=0)&&(x<N&&y<N));
}

void n_bfs(int x, int y){
    nomalcnt++;
    queue<pair<int,int>> q;

    q.push({x,y});
    n_visited[x][y]=true;
    while(!q.empty()){
        int pos_x=q.front().first;
        int pos_y=q.front().second;

        q.pop();
        for(int i=0;i<4;i++){
            int nx=pos_x+xy[0][i];
            int ny=pos_y+xy[1][i];

            if(inside(nx,ny)&&rgb[nx][ny]==rgb[pos_x][pos_y]&&n_visited[nx][ny]==false){
            //안에 있고, rgb값이 같고,방문 안했으면
                q.push({nx,ny});
                n_visited[nx][ny]=true;
            }
        }
    }
    return ;
}

void rg_bfs(int x, int y){
    rgcnt++;
    queue<pair<int,int>> q;

    q.push({x,y});
    n_visited[x][y]=true;
    while(!q.empty()){
        int pos_x=q.front().first;
        int pos_y=q.front().second;

        q.pop();
        for(int i=0;i<4;i++){
            int nx=pos_x+xy[0][i];
            int ny=pos_y+xy[1][i];

            if(inside(nx,ny)&&rg_visited[nx][ny]==false){
                if(rgb[pos_x][pos_y]=='R'||rgb[pos_x][pos_y]=='G'){                
                //안에 있고, pos가 r이나 g고,방문 안했으면
                    if(rgb[nx][ny]!='B'){
                    q.push({nx,ny});
                    rg_visited[nx][ny]=true;
                    }
                }else if(rgb[nx][ny]=='B'){
                //안에 있고, rgb값이 같고,방문 안했으면
                    q.push({nx,ny});
                    rg_visited[nx][ny]=true;               
                
                }
            }
        }
       
    }

    return;
    
}



int main(){

    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>rgb[i][j];
        }
    }//rgb입력받기

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(n_visited[i][j]==0){//방문 안했으면_정상인
                n_bfs(i,j);//bfsㄱ
            }
            if(rg_visited[i][j]==0){//방문 안했으면_적록색약
                rg_bfs(i,j);//bfsㄱ
            }
        }
    }

    cout<<nomalcnt<<" "<<rgcnt<<"\n";

    return 0;
}
