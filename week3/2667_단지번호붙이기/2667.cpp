/*
지도 for문으로 돌면서 1이고 방문 안했으면 큐 넣어주기
큐에서 pop되는 위치의 위 아래 오른쪽 왼쪽 이 1인지 확인하고 1이면 q에 넣어주기
방문체크

만약 (0,0) 자리면 위랑 왼쪽은 없으므로 접근하려는 곳이 안에 있는지도 확인해줘야함

어려웠던점:
- 위아래양옆을 if문 4개로 해야하나..? 는 생각-> 배열 만들어서 for문으로
- 큐에 원소 두개씩 넣어주는 방법
- 아직 bfs에 너무 미숙함
- 백준에서 계속 실패뜸 -> count를 큐에 push할 때 ++해주는데 bfs함수 들어가기 전에 push할 때 ++안해줘서였음,방문체크도

시간복잡도 O(n^2)
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
char v[26][26]; // 지도 배열
vector<int> ans; // 단지별 크기 입력할 벡터 -> 정렬 해줄거임
bool visited[26][26]={0}; //방문 체크 배열 false로 초기화
queue<pair<int,int>> q; //지도의 행과 열 넣어줘야하므로 벡터에 두개를 한쌍으로 넣어줄거임

int r[4]={-1,1,0,0};//상하좌우
int c[4]={0,0,-1,1};


bool inside(int a,int b){ //확인하려는 곳이 배열 안에있는지(지도  내인지)
    return ((a>=0&&a<N)&&(b>=0&&b<N));
}

int bfs(){ //너비우선탐색
    int count=0; // 단지별 크기
    int pos_r=0;
    int pos_c=0;//검사하려는 곳의 행과 열 인덱스

    while (!q.empty()){ // 큐가 비었으면 탈출
        
        pos_r=q.front().first;//검사하려는 곳의 행
        pos_c=q.front().second;//검사하려는 곳의 열
        q.pop();
        count++;

        for(int i=0;i<4;i++){
            if(inside(pos_r+r[i],pos_c+c[i])&&v[pos_r+r[i]][pos_c+c[i]]=='1'&&visited[pos_r+r[i]][pos_c+c[i]]==false){
                //내부에 있고,아파트가 있고(값이 '1'이고),방문을 안했으면
                
                q.push(pair<int,int>(pos_r+r[i],pos_c+c[i]));//큐에 넣어주기
                visited[pos_r+r[i]][pos_c+c[i]]=true; //방문표시
            }
        }
    }
    return count;
}



int main(){
    
    cin>>N;

    for(int j=0;j<N;j++){
        for(int i=0;i<N;i++){
            cin>>v[j][i];
        }
    }//입력받기

    
    int result=0;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(v[i][j]=='1'&&visited[i][j]==false){//값이 1이고 방문을 안했으면
                q.push(pair<int,int>(i,j)); //큐에 넣어주기
                visited[i][j]=true;//큐에 넣었으니 방문표시 (이거 안해서 계속 틀렸다함)
                result = bfs(); //너비우선 탐색으로 위아래오른쪽왼쪽 검사
                ans.push_back(result); //결과값(count) 넣어주기
            }
        }
    }

    cout<<ans.size()<<endl;
    sort(ans.begin(),ans.end());//내림차순으로 정렬해주기
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }

    return 0;
}
