#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallest(int *input, int n) {
	stack<int> s;
	vector<int> v;
	for(int i=n-1;i>=0;i--) {
		if(s.size() == 0) {
			v.push_back(-1);
		} else if(s.size() > 0 && s.top() < input[i]) {
			v.push_back(s.top());
		} else if(s.size() > 0 && s.top() >= input[i]) {
			while(s.size() > 0 && s.top() >= input[i]) {
				s.pop();
			}
			if(s.size() == 0) {
				v.push_back(-1);
			} else {
				v.push_back(s.top());
			}
		}
		s.push(input[i]);
	}
	reverse(v.begin(), v.end());
	return v;
}

int main() {
	int n, input[100];
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>input[i];
	}
	vector<int> ans = nextSmallest(input, n);
	for(int i=0;i<ans.size();i++) {
		cout<<ans[i]<<" ";
	}
	return 0;
}
