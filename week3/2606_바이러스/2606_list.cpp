#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){

    int n,connectnum,ans=0,pos,poslinked;
    int visited[101]={0};
    
    
    cin>>n;
    cin>>connectnum;

    vector<int> connect[n+1];

    for(int i=0;i<connectnum;i++){
        int m,n;
        cin>>m>>n;
        connect[m].push_back(n);
        connect[n].push_back(m); 
    }
    queue<int> q;
    q.push(1);
    visited[1]=1;

    while (!q.empty())
    {
        pos=q.front();
        q.pop();
        for(int i=1;i<=n;i++){
            for(int j=0;j<connect[pos].size();j++){
                poslinked=connect[pos][j];//연결된 노드번호
                if(visited[poslinked]!=1){
                    q.push(poslinked);
                    visited[poslinked]=1;
                    ans++;
                }
            }
        }
    }
    cout<<ans;

    return 0;
}
