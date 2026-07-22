/* 
@author WeakBlood<3
*/
#include <bits/stdc++.h>

#define ll long long int
#define inf 1e9
using namespace std;

//!!!EXPLANATION!!!:
/* 

*/

//Cases

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    ifstream cin("input.txt");
    auto start = std::chrono::steady_clock::now();
    #endif


    // solve 

	int N; 
	cin >> N; 
	cout << fixed << setprecision(9); 
	vector<double> coins(N+1); 
	for(int i = 1; i <= N; i++) cin >> coins[i]; 
	
	vector<vector<double>> dp(N+1,vector<double>(N+1)); 
	dp[0][0] = 1; 
	for(int i = 1; i <= N; i++){
		for(int j = 0; j <= i; j++){
			if(j > 0) dp[i][j] = dp[i-1][j]*(1-coins[i])+dp[i-1][j-1]*coins[i];
			else dp[i][j] = dp[i-1][j]*(1-coins[i]);  
		} 
	}
	double ans = 0; 
	for(int j = N/2+1; j <= N; j++){
		ans+=dp[N][j]; 
	}
	cout << ans << '\n'; 
    #ifdef LOCAL
    auto end = std::chrono::steady_clock::now();
    double t = std::chrono::duration<double>(end - start).count();
    cout << "Time taken: " << t << '\n';
    #endif

    return 0;
}
