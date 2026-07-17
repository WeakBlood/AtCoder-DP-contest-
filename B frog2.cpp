/* 
@author WeakBlood<3
*/
#include <bits/stdc++.h>

#define ll long long int
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

	int N,K; 
	cin >> N >> K; 
	vector<ll> h(N+1); 
	for(int i = 1; i <= N; i++) cin >> h[i]; 
	const ll inf = 1e18; 
	vector<ll> dp(N+1,inf); 
	
	dp[1] = 0; 
	for(int i = 1; i < N; i++){
		for(int j = 1; j <= K && j+i <= N; j++){
			dp[i+j] = min(dp[i+j],dp[i]+abs(h[i]-h[i+j])); 
		}
	}
	cout << dp[N] << '\n'; 
	
    #ifdef LOCAL
    auto end = std::chrono::steady_clock::now();
    double t = std::chrono::duration<double>(end - start).count();
    cout << "Time taken: " << t << '\n';
    #endif

    return 0;
}
