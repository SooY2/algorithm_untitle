/*
N입력받기 3<= N <=5000
N을 5로 나눈 몫 저장할 변수, 나머지 저장할 변수
5로 나눈 나머지를 다시 3으로 나눈 몫을 저장할 변수

case 5개
5로 나눈 나머지가 0일때, N/5출력
5로 나눈 나머지가 1일때, 몫이 0이면 -1, 몫이>0이면 5몫-1+(1+5)/3= 5몫-1+2 
5로 나눈 나머지가 2일때, 몫이 0,1이면 -1, 몫이 >=2면 5몫-2+(2+5+5)/3 = 5몫-2+4
5로 나눈 나머지가 3일때, 몫+3/3=5몫+1
5로 나눈 나머지가 4일때, 몫이 0이면 -1, 몫이>0이면 5몫-1+(4+5)/3 = 5몫-1+3

시간 복잡도 O(1)..?
공간 복잡도  O(1)
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
