//셀프넘버
//시간복잡도 : O(1)..?
//공간복잡도 : O()
#include <iostream>
using namespace std;
#include <string>


int d(int n){ //n과 n의 각 자리수 더한 값
    string s;
    s = to_string(n); //각 자리수를 더해줄 때 string타입으로 바꾸어 한글자씩 나눠 더해줄거임
    int result=n;
    for(int i=0;i<s.length();i++){//바꾼 문자열의 길이만큼 반복하며 각 자리수 더하기
        int b=s[i]-'0'; //문자를 정수형으로 바꿀 때
        result+=b;
    }
    return result;
}

int main(){
    
    bool selfnums[10001]={0};//1부터 10000까지 인덱스값이 숫자고 bool으로 셀프넘버인지 아닌지 판단 

    for(int i=1;i<=10000;i++){
        int a=d(i);//함수 실행
        if(a<10001)
            selfnums[a]=true;//함수의 결과로 나온 수는 셀프넘버가 아니므로 true표시
    }
    
    for(int i=1;i<=10000;i++){
        if(!selfnums[i]) cout<<i<<endl;//false일 때 출력
    }

    
    return 0;

}
