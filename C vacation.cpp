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
	vector<array<int,3>> a(N); 
	for(int i = 0; i < N; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
	
	vector<array<int,3>> dp(N+1,{0,0,0}); 
	dp[0] = {0,0,0};  

	for(int i = 0; i < N; i++){
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 3; k++){
				if(j == k) continue; 
				dp[i+1][k]=max(dp[i+1][k],dp[i][j]+a[i][k]); 
			}
		}
	}
	cout << max({dp[N][0],dp[N][1],dp[N][2]}) << '\n';  

    #ifdef LOCAL
    auto end = std::chrono::steady_clock::now();
    double t = std::chrono::duration<double>(end - start).count();
    cout << "Time taken: " << t << '\n';
    #endif

    return 0;
}
