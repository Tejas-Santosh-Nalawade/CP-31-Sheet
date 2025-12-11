#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

void solve(){
	LL a;
	scanf("%lld", &a);
	
	LL ans = 0;
	for(int i = 0; i < 60; ++i)
		if(a & (1LL << i))
			ans += (1LL << (i + 1)) - 1;
	printf("%lld\n", ans);
}

int main(){
	int quest;
	scanf("%d", &quest);
	
	while(quest--)
		solve();
	return 0;
}