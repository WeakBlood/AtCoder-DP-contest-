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


vector<char> lcs(const string &a, const string &b){
	int N = a.size(); 
	int M = b.size(); 
	vector<vector<int>> dp(N+1,vector<int>(M+1)); 
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(a[i] == b[j]) dp[i+1][j+1] = dp[i][j]+1; 
			else dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]); 
		}
	}
	
	vector<char> ans; 
	int i = N; 
	int j = M; 
	while(i > 0 && j > 0){
		if(dp[i][j] == dp[i][j-1]){
			j--; 
		} else if(dp[i][j] == dp[i-1][j]) i--; 
		else{
			i--; 
			j--; 
			ans.push_back(a[i]); 
		}
	}
	reverse(ans.begin(),ans.end()); 
	return ans; 
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    ifstream cin("input.txt");
    auto start = std::chrono::steady_clock::now();
    #endif


    // solve 
	string a,b; 
	cin >> a >> b; 

	auto ans = lcs(a,b); 
	for(char c:ans) cout << c; 
	cout << '\n'; 

    #ifdef LOCAL
    auto end = std::chrono::steady_clock::now();
    double t = std::chrono::duration<double>(end - start).count();
    cout << "Time taken: " << t << '\n';
    #endif

    return 0;
}
