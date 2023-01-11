/*
NxM직사각형에서 가로와 세로 중 짧은것의 길이의 정사각형부터 변의 길이를 줄여가며 각 모서리의 값 같으면 그때의 변의 길이로 크기 구하기

시간복잡도: O(n^2)
공간복잡도: O(N*M+6)
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;



int main() {
    int N, M;//
    cin >> N >> M;
    string s;//행을 string으로 입력받아 정수형으로 바꿔줄거임


    vector<vector <char>> r(N,vector<char>(M,0)); ;//NxM 0으로 초기화 한 2차원벡터 생성
    // 이 문제에선 배열안의 값으로 연산하지 않고 안의 값이 같은지 다른지만 판단하므로 char형을 써도 됨. 
    // int형으로 하면 string형식으로 받아 변환하는 과정 필요
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin>>r[i][j];//배열에 입력받기
        }
    }

    int size = 1;//기본 사이즈를 1로 설정 
    int minval = min(N,M);//(N <= M) ? N : M; 
    bool st = true;// 가장 큰 변부터 검사할 것이므로 만약 모서리가 같은 경우가 나오면 while문을 빠져나오도록 하기 위한 bool형 변수
    while (st) //st가 true일때
    {
        for (int i = 0; i < N - minval + 1; i++) {
            for (int j = 0; j < M - minval + 1; j++) {
                //cout<<r[i][j]<<r[i][j+minval-1]<<r[i+minval-1][j]<<r[i+minval-1][j+minval-1]<<endl; //모서리 확인코드
                if (r[i][j] == r[i][j + minval - 1] && r[i][j] == r[i + minval - 1][j] && r[i][j] == r[i + minval - 1][j + minval - 1]) {//모서리가 같으면
                    size = minval * minval;//size= 정사각형 크기                        
                    st = false; //가장 큰 정사각형 찾았으므로
                }
            }
        }
        minval--; //못찾았으면 정사각형 변 길이 줄여서 다시 검사 
    }

    cout << size;



    return 0;
}


/*  10번째 줄   O
#include 할 거 다 하고 using namespace std;가 나오는 게 보기에 훨 나을 거 같아요  */

/* 19번째 줄    O
이거 때매 코드가 제거에선 안 돌아가는데 정답이 어떻게 나왔는 지 모르겠네요 ㅠㅠ
수연님이 사용하신 2차원 배열은 [정적 배열]이라 미리 상수를 이용해 배열의 크기를 지정해줘야해요! ex. r[100][100], r[150][250] 이런식으로!
제가 전부터 계속 강조드린 vector가 [동적 배열]이고 지금 적으신 거처럼 쓰시려면 vector를 사용해주셔야해요! ex. vector<vector<int>> r(N,vector <int>(M,0)); 0으로 초기화되어있고 크기가 N * M인 2차원 벡터 

결론 -> 그냥 2차원 배열 쓰고 싶다! N과 M이 50보다 작거나 같은 자연수이므로 r[50][50]으로 선언!
     -> 아니다 입력받은 N과 M을 쓰고 싶다! vector<vector<int>> r(N,vector <int>(M,0))으로 선언!
https://seongonion.tistory.com/18 정적 배열 설명
https://leeeegun.tistory.com/3 vector 2차원 배열*/

/* 20번째 줄    O
문자열로 입력받은 다음 int형 2차원 배열에 집어넣기 위해 한 문자씩 따로따로 '0'을 빼주면서 넣는 거 잘했습니다 저도 옛날에 저렇게 했거든요!!
근데 차라리 char형 2차원 배열을 사용한다면 굳이 저런 작업을 하지 않아도 넣을 수 있을 거 같은데 한 번 생각해보세요! */

/* 28, 36번째 줄    O
#include <algorithm>의 minval, max에 대해 찾아보세요! 삼항연산자 활용은 아주 굳입니다!! */

/* 총평
정답이 될 수 있는 큰 값부터 줄여나가면서 구하는 아이디어가 매우 좋습니다!!
아이디어는 정말 좋은 거 같고 코드만 조금 더 깔끔하게 다듬으면 좋을 거 같습니다! 파이팅이에요~ */
