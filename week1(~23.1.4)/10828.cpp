/*
�ð� ���⵵ O(n)
���� ���⵵ O(n)
��������� :
 �ϴ� push x�� ���Ⱑ �־ ��� ������ �����߾���. 
 ó���� ������ ���� �����ؼ� �ߴµ� ���� ���÷� ������ ���� ����� �°� �����µ�
 ���ؿ��� ä���� �� ��� Ʋ�Ƚ��ϴ� ��� ���ͼ� c++�� �����Ǿ��ִ� stack�� ����ߴ�.
 ������ ��ɿ� �°Ը� �����ؼ� �ȵǴ°��� �𸣰ڴ�!!! �Ф�
*/

#include<iostream>
#include <stack>
using namespace std;

int main(){
    int N; //��� ����
    cin>>N;

    stack<int> Stack; //C++�� �����Ǿ��ִ� ���� 
    string str; //���

    for (int i=0;i<N;i++){
        cin>>str;
        if (str=="push"){ //push��
            int x;
            cin>>x; //c++���� cin�� ���� �������� �ν��ϹǷ� ���� ���� �ٽ� cin���� �޾��ش�.
            Stack.push(x); //���ÿ� �־��ֱ�
        }
        else if(str=="pop"){ 
            if(Stack.empty()) cout<<-1<<endl;//������ ��������� -1 ���
            else {
                cout<<Stack.top()<<endl;//������ pop�� �� �� ���ǰ�top�� ��ȯ�ϹǷ� top�� �����Ͱ��� ���
                Stack.pop();//pop���ֱ� 
            }
        }
        else if(str=="size"){
            cout<<Stack.size()<<endl; //������ ũ�� ���
        }
        else if(str=="empty"){
            if(Stack.empty()) cout<<1<<endl;//������ ��������� 1���
            else cout<<0<<endl;//�ƴϸ� 0���
        }
        else if(str=="top"){
            if(Stack.empty()) cout<<-1<<endl;//������ ��������� -1���
            else cout<<Stack.top()<<endl;//�ƴϸ� top�� �����Ͱ� ���
        }
    }
    
    
    return 0;
}