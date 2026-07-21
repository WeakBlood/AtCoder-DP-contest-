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
int ans = 0; 
int dfs(int node, const vector<vector<int>> &graph, vector<int> &dp, int len){
	if(dp[node] != -1){
		ans = max(ans,len+dp[node]); 
		return dp[node]+len; 
	} 
	ans = max(ans,len); 
	int mx = len;  
	for(int u:graph[node]){
		int child = dfs(u,graph,dp,len+1); 
		mx = max(child,mx); 
	}
	dp[node] = mx-len;
	ans = max(ans,mx);  
	return mx; 
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    ifstream cin("input.txt");
    auto start = std::chrono::steady_clock::now();
    #endif


    // solve 

	int N,M; 
	cin >> N >> M; 
	vector<vector<int>> graph(N); 
	for(int i = 0; i < M; i++){
		int a,b; 
		cin >> a >> b; 
		a--; b--; 
		graph[a].push_back(b); 
	}


	vector<int> dp(N,-1); 
	for(int i = 0; i < N; i++){
		dfs(i,graph,dp,0); 
	} 
	cout << ans << '\n'; 
    #ifdef LOCAL
    auto end = std::chrono::steady_clock::now();
    double t = std::chrono::duration<double>(end - start).count();
    cout << "Time taken: " << t << '\n';
    #endif

    return 0;
}
