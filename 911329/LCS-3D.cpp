#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int m, n, o; //¦r¼Æ
  string str1, str2, str3;
  cin >> m >> n >> o >> str1 >> str2 >> str3;
  int dp[m+1][n+1][o+1];
    for(int i=0; i<=m; i++){
      for(int j=0; j<=n; j++){
        for(int k=0; k<=o; k++){
          if(i==0 || j==0 || k==0){
                dp[i][j][k]=0;
            }else if(str1[i-1]==str2[j-1]&&str2[j-1]==str3[k-1]){
                dp[i][j][k] = dp[i-1][j-1][k-1]+1;
            }else{
                dp[i][j][k] = max({dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]});
            }
        }
      }
    }
    cout << dp[m][n][o] << endl;
}
