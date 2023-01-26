/*숨바꼭질

수빈이 위치 n,동생위치 k 0<=100000
수빈이가 걸으면 1초후에 x+1,x-1 /순간이동하면 1초뒤에 2*x로 이동

수빈이가 동생을 찾는 가장빠른 시간이 몇초후인지

bfs로 3군데 검사x-1,x+1,2*x 큐에 넣어주기
각 위치의 시간+=1 해주고 방문표시..필요한가?
push하는게 동생위치k면 종료

그때 시간s출력

++
depth세는법 - q.size()만큼 for문돌고 depth++해주는 방법도 있음
*/
#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int n,k;//수빈이 위치, 동생 위치
deque<int> q;
int s[1000000];//걸린 시간

bool inside(int x){
    return (x>=0&&x<=1000000);
}

void bfs(int x){
    q.push_back(x);

    int pos;
    while(1){
        pos = q.front();
        q.pop_front();

        if(inside(pos+1)&&s[pos+1]==0){
            q.push_back(pos+1);
            s[pos+1]=s[pos]+1;//앞
            if(pos+1==k) return;
        }
        if(inside(pos-1)&&s[pos-1]==0){
            q.push_back(pos-1);
            s[pos-1]=s[pos]+1;//뒤
            if(pos-1==k) return;
        }
        if(inside(pos*2)&&s[pos*2]==0){
            q.push_back(pos*2);
            s[pos*2]=s[pos]+1;//순간이동
            if(pos*2==k) return;
        }

    }
    return;
}

int main(){
    
    cin>>n>>k;

    if(n!=k){
        bfs(n);
    }

    cout<<s[k];
    
    return 0;
}
