/*
N�Է¹ޱ� 3<= N <=5000
N�� 5�� ���� �� ������ ����, ������ ������ ����
5�� ���� �������� �ٽ� 3���� ���� ���� ������ ����

case 5��
5�� ���� �������� 0�϶�, N/5���
5�� ���� �������� 1�϶�, ���� 0�̸� -1, ����>0�̸� 5��-1+(1+5)/3= 5��-1+2 
5�� ���� �������� 2�϶�, ���� 0,1�̸� -1, ���� >=2�� 5��-2+(2+5+5)/3 = 5��-2+4
5�� ���� �������� 3�϶�, ��+3/3=5��+1
5�� ���� �������� 4�϶�, ���� 0�̸� -1, ����>0�̸� 5��-1+(4+5)/3 = 5��-1+3

�ð� ���⵵ O(1)..?
���� ���⵵  O(1)
*/

#include <iostream>
using namespace std;

int main(){
    int quotient5,remainder5;
    int N;
    int result;

    cin>>N;
    quotient5=N/5;
    remainder5=N%5;

    switch (remainder5)
    {
    case 0:
        result=quotient5;
        break;
    case 1:
        if (quotient5==0){
            result=-1;
        }else{
            result=quotient5+1;
        }
        break;
    case 2:
        if (quotient5==0||quotient5==1){
            result=-1;
        }else{
            result=quotient5+2;
        }
        break;
    case 3:
        result=quotient5+1;
        break;
    case 4:
        if (quotient5==0){
            result=-1;
        }else{
            result=quotient5+2;
        }
        break;
    
    default:
        break;
    }
    
    cout<<result;

    return 0;
    
}