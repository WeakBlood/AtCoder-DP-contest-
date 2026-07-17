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
	int W; 
	cin >> N >> W; 
	int V = 0; 
	vector<int> w(N); 
	vector<int> v(N); 
	for(int i = 0; i < N; i++){
		cin >> w[i] >> v[i]; 
		V+=v[i]; 
	}
	
	vector<int> dp(V+1,W+1); 
	dp[0] = 0; 
	for(int i = 0; i < N; i++){
		for(int j = V; j >= v[i]; j--){
			if(dp[j-v[i]] == W+1) continue; 
			dp[j] = min(dp[j],dp[j-v[i]]+w[i]); 
		}
	}
	int ans = 0; 
	for(int i = V; i > 0 && ans == 0; i--){
		if(dp[i] <= W) ans = i; 
	}
	cout << ans << '\n'; 
    #ifdef LOCAL
    auto end = std::chrono::steady_clock::now();
    double t = std::chrono::duration<double>(end - start).count();
    cout << "Time taken: " << t << '\n';
    #endif

    return 0;
}
