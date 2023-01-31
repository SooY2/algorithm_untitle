//11055 가장 큰 증가하는 부분 수열
/*
arr[i]보다 작은 것 중 dp[]가 가장 큰거 찾아서 dp[i]=arr[i]+i보다 작은거중 이제까지 합 가장 큰거 더하기

arr 5 1 2 3 7
 dp 5 1 3 6 13

* arr[i]보다 작으면서 그 dp가 가장 커야함. 예를 들어 5,3은 둘다 7보다 작지만 dp는 3일때가 더 크므로 3을 더함
* arr[i]보다 작은게 없는 경우도 생각해야함
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[1000]={0};
    int dp[1000]={0}; //
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }//입력받기

    dp[0]=arr[0];
    for(int i=1;i<n;i++){
        int max=i;//dp[max]==0임
        bool b=false;//arr[i]보다 작은게 없을경우 찾기 위해서
        for(int j=i-1;j>=0;j--){
            if(arr[j]<arr[i]&&dp[j]>=dp[max]){//현재 인덱스가 i일때 i보다 작은 것 중 arr[i]보다 작으면서 그 때의 dp는 가장 큰 것의 인덱스 찾기
                max=j;
                b=true;
            }
        }
        if(b==true) dp[i]=dp[max]+arr[i];
        else dp[i]=arr[i];
    }

    cout<<*max_element(dp,dp+1000);
    return 0;
}
