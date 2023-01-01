/*
N입력받기 3<= N <=5000
N을 5로 나눈 몫 저장할 변수, 나머지 저장할 변수
5로 나눈 나머지를 다시 3으로 나눈 몫을 저장할 변수

case 5개
5로 나눈 나머지가 0일때, N/5출력
5로 나눈 나머지가 1일때, 1+5=6이므로 5kg하나 빼고 3kg 2개로 대체 가능--> 몫이 0이면 -1, 몫이>0이면 5몫-1+(1+5)/3= 5몫-1+2 
5로 나눈 나머지가 2일때, 1+5+5=12이므로 5kg 2개 빼고 3kg 4개로 대체 가능--> 몫이 0,1이면 -1, 몫>=2면 5몫-2+(2+5+5)/3 = 5몫-2+4
5로 나눈 나머지가 3일때, 3kg 봉지 하나 더하면 됨--> 몫+3/3=5몫+1
5로 나눈 나머지가 4일때, 4+5=9이므로 5kg하나 빼고 3kg 3개로 대체 가능--> 몫이 0이면 -1, 몫이>0이면 5몫-1+(4+5)/3 = 5몫-1+3

시간 복잡도 O(1)..?
공간 복잡도 O(1)
*/

#include <iostream>
using namespace std;

int main(){
    int quotient5,remainder5;//N을 5로 나눈 몫,N을 5로 나눈 나머지
    int N;
    int result;

    cin>>N;
    quotient5=N/5;
    remainder5=N%5;

    switch (remainder5) //5로 나눈 나머지의 값에 따라 결과가 달라지므로 switch case문 사용 -> 자세한건 맨 위 주석 참고
    {
    case 0: // 5로 나눈 나머지가 0이면, 5로 나눈 몫을 출력
        result=quotient5;
        break;
    case 1: // 5로 나눈 나머지가 1일 때
        if (quotient5==0){// 몫이 0이면 몫에서 1을 뺄 수 없으므로 -1 출력
            result=-1;
        }else{//몫이 0보다 크면 5kg하나 빼고 3kg 2개로 대체 가능
            result=quotient5+1;
        }
        break;
    case 2:
        if (quotient5==0||quotient5==1){ //몫에서 2를 빼야하는데 0과1이면 뺄 수 없으므로 -1출력
            result=-1;
        }else{//5kg 2개 빼고 3kg 4개로 대체 가능
            result=quotient5+2;
        }
        break;
    case 3:
        result=quotient5+1;// 나머지가 3이면 5로 나눈 몫에 3kg봉지 한개 추가
        break;
    case 4:
        if (quotient5==0){ 
            result=-1; // 몫이 0이면 몫에서 1을 뺄 수 없으므로 -1 출력
        }else{
            result=quotient5+2; //5kg하나 빼고 3kg 3개로 대체 가능
        }
        break;
    
    default:
        break;
    }
    
    cout<<result;

    return 0;
    
}
