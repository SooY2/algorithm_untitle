//바이러스 배열
//시간복잡도 O(n^2)
#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n,connect_num,pos;
    int ans=0;
    int visited[101]={0};//방문 했는지 확인하기 위해 

    int connect[101][101]={0}; //2차원 배열 생성
    
    cin>>n;
    cin>>connect_num;
    while (connect_num--)//connect_num이 양수일 때
    {
        int r,c;
        cin>>r>>c;
        connect[r][c]=1;
        connect[c][r]=1;//양방향이라 둘 다 1로 바꿔줘야함
    }

    queue<int> q;
    q.push(1);

    while(!q.empty()){
        pos = q.front();
        q.pop();
        visited[1]=1;

        for(int i=1;i<=n;i++){
            if(connect[pos][i]==1){//인접하면
                if(visited[i]!=1){//방문하지 않은 숫자면
                    q.push(i);
                    visited[i]=1;
                    ans++;
                }
            }
        }
    }    

    cout<<ans;
    return 0;

}
