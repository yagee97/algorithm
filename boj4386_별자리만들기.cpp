#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;
int parent[101];

int find(int x)
{
	if (parent[x] == x)
		return x;
	return parent[x] = find(parent[x]);
}

bool merge(int x, int y)
{
	x = find(x);
	y = find(y);
	
	if (x == y)
		return false;
	else
	{
		if (x > y)
			parent[y] = x;
		else
			parent[x] = y;
		return true;
	}
}

class Pos {
public:
	float x;
	float y;
	Pos(float x, float y)
	{
		this->x = x;
		this->y = y;
	}
};

class Edge {
public:
	float node[2];
	float distance;
	Edge(float a, float b, float distance)
	{
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}
	bool operator <(Edge &edge) {
		return this->distance < edge.distance;
	}
};

int n;
vector<Edge> e;
vector<Pos> p;
float cost;

float cal_distance(Pos p1, Pos p2)
{
	return sqrt(pow(p1.x - p2.x, 2) +
		pow(p1.y - p2.y, 2));
}

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		float x, y;
		cin >> x >> y;
		p.push_back(Pos(x,y));
	}

	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (i != j) {
				cost = cal_distance(p[i], p[j]);
				e.push_back(Edge(i, j, cost));
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
	}

	sort(e.begin(), e.end());
	
	float sum = 0;

	for (int i = 0; i < e.size(); i++) {
		float x = e[i].node[0];
		float y = e[i].node[1];
		float c = e[i].distance;
		//cout << c << ' ';
		if (merge(x, y)) {
			sum += c;
		}
	}

	printf("%.2f", sum);


}