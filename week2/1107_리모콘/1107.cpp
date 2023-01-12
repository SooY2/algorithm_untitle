//못풀었음
/*
해당 자릿수의 번호가 고장나지 않으면 그 번호를 입력하고, 고장난 숫자면 해당 자릿수 아래자리부터 만들 수 있는 큰거 중 제일 작은거와 작은거중 제일 큰거를 비교해 횟수가 더 작은걸 출력하려함
하지만 예를들어 4,5,9만 누를 수 있고 숫자가 500000면 큰것은 544444, 작은건 만들 수 없음 

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    
    vector <int> N;
    int M;

    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){//N을 int 벡터에 넣어주기
        N.push_back(s[i]-'0');
    }
    cin>>M;
    vector <int> num={0,1,2,3,4,5,6,7,8,9};
    for(int i=0;i<M;i++){
        int m;
        cin>>m;
        num.erase(remove(num.begin(),num.end(),m)); //고장난 번호 삭제
    }

    // for(int i=0;i<num.size();i++){
    //     cout<<num[i];
    // } // 삭제 확인코드

    int result_up=0;
    const int len=N.size();
    int count=0;

    int index=0;
    while(find(num.begin(),num.end(),N[index])!=num.end()){// 해당 자릿수가 고장나지 않은 번호일 때 실행
        result_up+=N[index]*pow(10,len-index);
        count+=1;
        index++;
    }//해당 자릿수가 고장난 번호면
    int bigger_min = 0;
    while (num[bigger_min]<N[index]) //해당 값보다 큰거 중에 제일 작은거 찾기
    {
        bigger_min++;
    }
    result_up+=num[bigger_min]*pow(10,len-index);
    index++;
    for(index;index<len;index++){
        result_up+= *min_element(num.begin(),num.end())*pow(10,len-index);
    }


    cout<<result_up;

        
    return 0;
        

    }

    
    
    
    

