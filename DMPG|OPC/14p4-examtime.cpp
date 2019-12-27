#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> pii;
typedef pair<double, pair<int, int>> tii;

int amt, edges, a, b, leng, speed;
double times;
double dist[100005];
vector<tii> adj[200005];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> amt >> edges;
    for(int i = 0; i <= amt; i++) dist[i] = LONG_MAX;
    for(int i = 0; i < edges; i++){
        cin >> a >> b >> leng >> speed;
        times = leng * 1.0 / speed;
        adj[a].pb({times, {b, INT_MAX}});
        adj[b].pb({times, {a, INT_MAX}});
    }

    dist[0] = 0;
    priority_queue<tii, vector<tii>, greater<tii>> pq;

    pq.push({0,{1,0}}); int ind = 0;

    while(!pq.empty()) {
        double dis = pq.top().first;
        int cur = pq.top().second.first;
        int roads = pq.top().second.second;

        pq.pop();
        for (pair<double, pair<int, int>> c: adj[cur]){
            if(c.first + dis < dist[c.second.first] || (c.first + dis == dist[c.second.first] && c.second.second > roads+1)){
                dist[c.second.first] = dis + c.first;
                if(c.second.first == amt) ind = roads; 
                pq.push({dis + c.first, {c.second.first, roads+1}});
            }
        }
    }
    cout << ind+1 << "\n" << round(dist[amt]*20);
}

//We first find the shortest path using a Dijkstra, and then print out the time saved
