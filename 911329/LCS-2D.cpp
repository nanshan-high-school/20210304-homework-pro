#include <iostream>
using namespace std;

int main(){
  int m, n; //¦r¼Æ
  string str1, str2;
  cin >> m >> n >> str1 >> str2;
  int dp[m+1][n+1];
    for(int i=0; i<=m; i++){
      for(int j=0; j<=n; j++){
          if(i==0 || j==0){
            dp[i][j]=0;
          }else if(str1[i-1]==str2[j-1]){
            dp[i][j] = dp[i-1][j-1]+1;
          }else{
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
          }
      }
    }
    cout << dp[m][n] << endl;
}
