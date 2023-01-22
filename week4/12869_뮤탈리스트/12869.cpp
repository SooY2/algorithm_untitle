/*12869 뮤탈리스트

큐에 [0,0,0] 원소 세개 넣고
순열의 각 경우마다 -9,-3,-1해서 큐에 넣어주기()
원소가 -면 0으로 바꿔주기
만약 원소가 다 000이면 탐색 중지 

메모리초과,,->visited조건걸어줌, visited인덱스에 -값 넣으면 안되니까 zero로 0으로 바꿔줘야함

*/

#include <iostream>
#include <deque>
using namespace std;

struct NODE
{
    int x,y,z;
    int depth;
};

int zero(int x){
    if(x<=0) return 0;
    else return x;
}

int N;
int attack[3]={-9,-3,-1};
int scv[3];
bool visited[61][61][61];
deque<NODE> q;

int bfs(NODE temp){

    q.push_back(temp);
    visited[temp.x][temp.y][temp.z]=true;
    NODE pos;
    while (!q.empty())
    {
        NODE f=q.front();
        q.pop_front();
        
        
        if(visited[zero(f.x-9)][zero(f.y-3)][zero(f.z-1)]==false){//xyz
            pos.x=zero(f.x-9);
            pos.y=zero(f.y-3);
            pos.z=zero(f.z-1);
            pos.depth=f.depth+1;
            if(pos.x==0&&pos.y==0&&pos.z==0) return pos.depth;
            q.push_back(pos);
            visited[pos.x][pos.y][pos.z]=true;
        }
        if(visited[zero(f.x-9)][zero(f.z-3)][zero(f.y-1)]==false){//xzy
            pos.x=zero(f.x-9);
            pos.z=zero(f.z-3);
            pos.y=zero(f.y-1);
            pos.depth=f.depth+1;
            q.push_back(pos);
            visited[pos.x][pos.z][pos.y]=true;
            if(pos.x==0&&pos.y==0&&pos.z==0){
                return pos.depth;
            } 
        }
        if(visited[zero(f.y-9)][zero(f.x-3)][zero(f.z-1)]==false){//yxz
            pos.y=zero(f.y-9);
            pos.x=zero(f.x-3);
            pos.z=zero(f.z-1);
            pos.depth=f.depth+1;
            q.push_back(pos);
            visited[pos.y][pos.x][pos.z]=true;
            if(pos.x==0&&pos.y==0&&pos.z==0){
                return pos.depth;
            } 
        }
        if(visited[zero(f.y-9)][zero(f.z-3)][zero(f.x-1)]==false){//yzx
            pos.y=zero(f.y-9);
            pos.z=zero(f.z-3);
            pos.x=zero(f.x-1);
            pos.depth=f.depth+1;
            q.push_back(pos);
            visited[pos.y][pos.z][pos.x]=true;
            if(pos.x==0&&pos.y==0&&pos.z==0){
                return pos.depth;
            } 
        }
        if(visited[zero(f.z-9)][zero(f.x-3)][zero(f.y-1)]==false){//zxy
            pos.z=zero(f.z-9);
            pos.x=zero(f.x-3);
            pos.y=zero(f.y-1);
            pos.depth=f.depth+1;
            q.push_back(pos);
            visited[pos.z][pos.x][pos.y]=true;
            if(pos.x==0&&pos.y==0&&pos.z==0){
                return pos.depth;
            } 
        }
        if(visited[zero(f.z-9)][zero(f.y-3)][zero(f.x-1)]==false){//zyx
            pos.z=zero(f.z-9);
            pos.y=zero(f.y-3);
            pos.x=zero(f.x-1);
            pos.depth=f.depth+1;
            q.push_back(pos);
            visited[pos.z][pos.y][pos.x]=true;
            if(pos.x==0&&pos.y==0&&pos.z==0){
                return pos.depth;
            } 
        }
        
    }
    return 0;
}

int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>scv[i];
    }

    NODE node;

    node.x=scv[0];
    node.y=scv[1];
    node.z=scv[2];
    node.depth=0;

    visited[node.x][node.y][node.z]=true;
    cout<<bfs(node);


    return 0;

}
