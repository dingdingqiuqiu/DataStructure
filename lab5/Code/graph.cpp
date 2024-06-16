#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

class Graph {
	int V;
	list< pair< int, int > > *adj;

            public:
	Graph(int V);
	void addEdge(int u, int v, int w);
	void printAdjMatrix();
	void BFS(int s);
	void DFSUtil(int v, bool visited[]);
	void DFS(int v);
	void dijkstra(int src);
};

Graph::Graph(int V) {
	this->V = V;
	adj     = new list< pair< int, int > >[V];
}

void Graph::addEdge(int u, int v, int w) {
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
}

void Graph::printAdjMatrix() {
	for(int i = 0; i < V; i++) {
		vector< int > row(V, INF);
		for(auto j : adj[i]) {
			row[j.first] = j.second;
		}
		for(int j = 0; j < V; j++) {
			if(row[j] == INF) {
				cout << "INF ";
			} else {
				cout << row[j] << " ";
			}
		}
		cout << endl;
	}
}

void Graph::BFS(int s) {
	bool *visited = new bool[V];
	for(int i = 0; i < V; i++)
		visited[i] = false;
	list< int > queue;
	visited[s] = true;
	queue.push_back(s);
	list< int >::iterator i;
	while(!queue.empty()) {
		s = queue.front();
		cout << s + 1 << " ";
		queue.pop_front();
		list< pair< int, int > >::iterator i;
		for(i = adj[s].begin(); i != adj[s].end(); ++i) {
			if(!visited[i->first]) {
				queue.push_back(i->first);
				visited[i->first] = true;
			}
		}
	}
}

void Graph::DFSUtil(int v, bool visited[]) {
	visited[v] = true;
	cout << v + 1 << " ";
	list< pair< int, int > >::iterator i;
	for(i = adj[v].begin(); i != adj[v].end(); ++i)
		if(!visited[i->first])
			DFSUtil(i->first, visited);
}

void Graph::DFS(int v) {
	bool *visited = new bool[V];
	for(int i = 0; i < V; i++)
		visited[i] = false;
	DFSUtil(v, visited);
}

void Graph::dijkstra(int src) {
	priority_queue< pair< int, int >, vector< pair< int, int > >, greater< pair< int, int > > > pq;
	vector< int > dist(V, INF);
	pq.push(make_pair(0, src));
	dist[src] = 0;
	while(!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		list< pair< int, int > >::iterator i;
		for(i = adj[u].begin(); i != adj[u].end(); ++i) {
			int v      = (*i).first;
			int weight = (*i).second;
			if(dist[v] > dist[u] + weight) {
				dist[v] = dist[u] + weight;
				pq.push(make_pair(dist[v], v));
			}
		}
	}
	printf("Vertex   Distance from Source\n");
	for(int i = 0; i < V; ++i)
		printf("%d \t\t %d\n", i + 1, dist[i]);
}

void test() {
	int V = 6;
	Graph g(V);
	g.addEdge(0, 1, 1);
	g.addEdge(0, 5, 1);
	g.addEdge(1, 3, 1);
	g.addEdge(1, 2, 1);
	g.addEdge(2, 4, 1);
	g.addEdge(2, 3, 1);
	g.addEdge(3, 4, 1);
	g.addEdge(4, 5, 1);
	while(true) {
		cout << "\n1. 输出邻接矩阵" << endl;
		cout << "2. 深度优先搜索" << endl;
		cout << "3. 广度优先搜索" << endl;
		cout << "4. Dijkstra最短路径" << endl;
		cout << "5. 退出" << endl;
		int choice;
		cin >> choice;
		if(choice == 1) {
			g.printAdjMatrix();
		} else if(choice == 2) {
			cout << "从哪个顶点开始深度优先搜索？" << endl;
			int v;
			cin >> v;
			g.DFS(v - 1);
		} else if(choice == 3) {
			cout << "从哪个顶点开始广度优先搜索？" << endl;
			int v;
			cin >> v;
			g.BFS(v - 1);
		} else if(choice == 4) {
			cout << "从哪个顶点开始Dijkstra最短路径？" << endl;
			int v;
			cin >> v;
			g.dijkstra(v - 1);
		} else if(choice == 5) {
			break;
		}
	}
	return;
}

void menu() {
	cout << "请输入相应的边的个数" << endl;
	int n;
	cin >> n;

	// 创建一个有n个顶点的图
	Graph g(n);
	// 根据用户的输入添加边
	for(int i = 0; i < n; i++) {
		int a, b, v;
		// 获取用户输入的两个顶点和边的权重
		cin >> a >> b >> v;
		// 在图中添加一条边
		g.addEdge(a - 1, b - 1, v);
	}

	while(true) {
		cout << "\n1. 输出邻接矩阵" << endl;
		cout << "2. 深度优先搜索" << endl;
		cout << "3. 广度优先搜索" << endl;
		cout << "4. Dijkstra最短路径" << endl;
		cout << "5. 退出" << endl;
		int choice;
		cin >> choice;
		if(choice == 1) {
			g.printAdjMatrix();
		} else if(choice == 2) {
			cout << "从哪个顶点开始深度优先搜索？" << endl;
			int v;
			cin >> v;
			g.DFS(v - 1);
		} else if(choice == 3) {
			cout << "从哪个顶点开始广度优先搜索？" << endl;
			int v;
			cin >> v;
			g.BFS(v - 1);
		} else if(choice == 4) {
			cout << "从哪个顶点开始Dijkstra最短路径？" << endl;
			int v;
			cin >> v;
			g.dijkstra(v - 1);
		} else if(choice == 5) {
			break;
		}
	}
	return;
}

int main() {
	int T;
	cout << "请选择你要操作的模式:" << endl;
	cout << "1. 单步调试" << endl;
	cout << "2. 案例测试" << endl;
	cin >> T;

	if(T == 1)
		menu();
	else if(T == 2)
		test();
	return 0;
}
