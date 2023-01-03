/*
시간 복잡도 O(n)
공간 복잡도 O(n)
어려웠던점 :
 일단 push x에 띄어쓰기가 있어서 어떻게 받을지 막막했었다. 
 처음엔 스택을 직접 구현해서 했는데 내가 예시로 실행할 때는 결과각 맞게 나오는데
 백준에서 채점할 때 계속 틀렸습니다 라고 나와서 c++에 구현되어있는 stack을 사용했다.
 스택을 명령에 맞게만 구현해서 안되는건지 모르겠다!!! ㅠㅠ
*/

#include<iostream>
#include <stack>
using namespace std;

int main(){
    int N; //명령 개수
    cin>>N;

    stack<int> Stack; //C++에 구현되어있는 스택 
    string str; //명령

    for (int i=0;i<N;i++){
        cin>>str;
        if (str=="push"){ //push면
            int x;
            cin>>x; //c++에서 cin은 띄어쓰기 전까지만 인식하므로 뒤의 값을 다시 cin으로 받아준다.
            Stack.push(x); //스택에 넣어주기
        }
        else if(str=="pop"){ 
            if(Stack.empty()) cout<<-1<<endl;//스택이 비어있으면 -1 출력
            else {
                cout<<Stack.top()<<endl;//스택은 pop할 때 맨 위의값top을 반환하므로 top의 데이터값을 출력
                Stack.pop();//pop해주기 
            }
        }
        else if(str=="size"){
            cout<<Stack.size()<<endl; //스택의 크기 출력
        }
        else if(str=="empty"){
            if(Stack.empty()) cout<<1<<endl;//스택이 비어있으면 1출력
            else cout<<0<<endl;//아니면 0출력
        }
        else if(str=="top"){
            if(Stack.empty()) cout<<-1<<endl;//스택이 비어있으면 -1출력
            else cout<<Stack.top()<<endl;//아니면 top의 데이터값 출력
        }
    }
    
    
    return 0;
}