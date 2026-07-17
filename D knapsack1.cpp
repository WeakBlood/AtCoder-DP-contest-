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
	int N,W; 
	cin >> N >> W; 
	vector<int> w(N); 
	vector<ll> v(N); 
	for(int i = 0; i < N; i++) cin >> w[i] >> v[i]; 
	vector<ll> dp(W+1,0); 
	for(int i = 0; i < N; i++){
		for(int j = W; j >= w[i]; j--){
			dp[j] = max(dp[j],dp[j-w[i]]+v[i]); 
		}
	}
	cout << dp[W] << '\n'; 


    #ifdef LOCAL
    auto end = std::chrono::steady_clock::now();
    double t = std::chrono::duration<double>(end - start).count();
    cout << "Time taken: " << t << '\n';
    #endif

    return 0;
}
