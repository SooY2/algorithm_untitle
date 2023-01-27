//2502 떡 먹는 호랑이
#include <iostream>
using namespace std;

int main(){
    int D[31][2]={0};//v의 첫배열의 인덱스는 날짜, 배열의 0번째는 첫째날 준 떡A개가 몇번나왔는지, 1번째는 둘째날 준 떡B개가 몇번나왔는지 
    //D[1][0]-첫째날의 A의 개수,D[1][1]-첫째날의 B의개수
    D[1][0]=1; //첫째날 준 떡 A개
    D[1][1]=0; //첫째날 떡 B의 개수
    D[2][0]=0;
    D[2][1]=1;

    int d,k;//d째날 준 떡의 개수 k개
    cin>>d>>k;

    for(int i=3;i<=d;i++){
        D[i][0]=D[i-1][0]+D[i-2][0];//A개수
        D[i][1]=D[i-1][1]+D[i-2][1];//B개수
    }
    int a=D[d][0];
    int b=D[d][1];

    int ans=1;
    int ansb=0;
    while(1){
        ansb=k-(a*ans);
        if (ansb%b==0){
            cout<<ans<<'\n'<<ansb/b;
            break;
        }
        ans++;
    }



    return 0;
}
