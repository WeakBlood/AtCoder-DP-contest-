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

const int mod = 1e9+7; 
//Cases
int dfs(int i, int j, const vector<vector<char>> &mtx, vector<vector<int>> &dp){
	int N = mtx.size(); 
	int M = mtx[0].size(); 
	if(i == N-1 && j == M-1) return 1; 
	else if(i >= N || j >= M || mtx[i][j] == '#') return 0; 
	if(dp[i][j] != -1) return dp[i][j]; 
	dp[i][j] = 0; 
	dp[i][j] = dfs(i+1,j,mtx,dp); 
	dp[i][j] =(dp[i][j] + dfs(i,j+1,mtx,dp))%mod;
	return dp[i][j];  
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
	vector<vector<char>> mtx(N,vector<char>(M)); 
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++) cin >> mtx[i][j]; 
	}


	vector<vector<int>> dp(N,vector<int>(M,-1)); 
	cout << dfs(0,0,mtx,dp) << '\n'; 	
    #ifdef LOCAL
    auto end = std::chrono::steady_clock::now();
    double t = std::chrono::duration<double>(end - start).count();
    cout << "Time taken: " << t << '\n';
    #endif

    return 0;
}
