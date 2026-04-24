#include <iostream>
#include <iomanip>
#include <vector>

const int MxN = 3030;

int main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	int n;
	std::cin >> n;
	std::vector<double> dp(2 * MxN, 0.0f);
	dp[MxN] = 1.0f;
	for(int i=1; i<=n; ++i) {
		double p;
		std::cin >> p;
		std::vector<double> new_dp(2 * MxN, 0.0f);
		for(int j=0; j<2 * MxN; ++j) {
			if(j - 1 >= 0) {
				new_dp[j] += dp[j - 1] * p;
			}
			if(j + 1 < 2 * MxN) {
				new_dp[j] += dp[j + 1] * (1 - p);
			}
		}
		dp = new_dp;
	}
	double answer = 0.0f;
	for(int i=MxN + 1; i<2*MxN; ++i) {
		answer += dp[i];
	}
	std::cout << std::fixed << std::setprecision(15) << answer;
	return 0;
}
