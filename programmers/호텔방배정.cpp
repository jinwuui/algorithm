#include <bits/stdc++.h>

#define ll long long
using namespace std;

unordered_map<ll, ll> mp;

ll findRoom(ll n) {
	if (mp[n] == 0) return n;
	return mp[n] = findRoom(mp[n]);
}

vector<ll> solution(ll k, vector<ll> room_number) {
    vector<ll> ans;

	for (int i = 0; i < room_number.size(); i++) {
		ll room = room_number[i];
		ll num = findRoom(room);
		mp[num] = num + 1;
		ans.push_back(num);
	}

    return ans;
}