/*
시간 복잡도 O(n^2)
공간 복잡도 O(n)

어려웠던 점 :
많은 반복으로 소수인지 찾아내는거라 방법을 생각해내는건 어렵지 않았지만
시간 복잡도가 느려 좋은 방법은 아닌 것 같다.
더 빠른 시간복잡도를 가지는 알고리즘을 생각해봐야겠다.
*/

#include<iostream>
using namespace std;

int main(){
    int N,prime;//개수 N, 소수인지 판단 할 변수 prime
    int count=0;//소수의 개수
    

    cin>>N;
    int arr[N];//N개의 원소 가지는 배열 만들기
    for (int i=0;i<N;i++){
        cin>>arr[i];
    }

    for (int i=0;i<N;i++){
        prime=1;//prime은 매번 1로 초기화, 1이면 소수, 0이면 소수아님
        if (arr[i]==1)
            prime=0; //1은 소수 아님
        if (arr[i]==2)
            prime=1;//2는 소수
        else if (arr[i]%2==0)
            prime=0;  //짝수는 소수아님      
        else{ //자신보다 작은수로 나누었을 때, 나머지가 0이 되는 것이 1과 자기 자신만이여야 소수임-> 
        //즉, 1과 자기자신을 제외하면 나머지가 0이 나오면 안됨
            for(int j=2;j<arr[i];j++){//2부터 자기자신 전까지
                if(arr[i]%j==0) {
                    prime=0;//나머지가 0이 나오면 prime을 0으로 변경
                    break;// 소수가 아니면 빠져나오기
                }
            }
                        
        }
        if(prime==1) count++;//소수면 count+1해주기

    }

    cout<<count;

    return 0;
}