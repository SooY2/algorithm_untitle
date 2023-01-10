/*
NxM직사각형에서 가로와 세로 중 짧은것의 길이의 정사각형부터 변의 길이를 줄여가며 각 모서리의 값 같으면 그때의 변의 길이로 크기 구하기

시간복잡도: O(n^2)
공간복잡도: O(N*M+6)
*/

#include <iostream>
using namespace std;
#include <string>


int main(){
    int N,M;//
    cin>>N>>M;
    string s;//행을 string으로 입력받아 정수형으로 바꿔줄거임

    
    int r[N][M];//NxM 2차원배열 생성
    for(int i=0;i<N;i++){
        cin>>s;// 각 행마다 숫자 입력받기
        for(int j=0;j<M;j++){
            r[i][j]=s[j]-'0'; //입력받은 행의 숫자들을 익덱스마다 정수형으로 바꿔서 배열에 넣기
        }
    }

    int size=1;//기본 사이즈를 1로 설정 
    int min = (N<=M)? N:M; //
    bool st=true;// 가장 큰 변부터 검사할 것이므로 만약 모서리가 같은 경우가 나오면 while문을 빠져나오도록 하기 위한 bool형 변수
    while (st) //st가 true일때
    {
        for(int i=0;i<N-min+1;i++){
            for(int j=0;j<M-min+1;j++){
                //cout<<r[i][j]<<r[i][j+min-1]<<r[i+min-1][j]<<r[i+min-1][j+min-1]<<endl; //모서리 확인코드
                if(r[i][j]==r[i][j+min-1]&&r[i][j]==r[i+min-1][j]&&r[i][j]==r[i+min-1][j+min-1]){//모서리가 같으면
                    if(min*min>size) {
                        size=min*min;//size= 정사각형 크기                        
                    }
                    st=false; //가장 큰 정사각형 찾았으므로
                }
            }
        }
        min--; //못찾았으면 정사각형 변 길이 줄여서 다시 검사 
    }

    cout<<size; 
    

    
    return 0;
}
