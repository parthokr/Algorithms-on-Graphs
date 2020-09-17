res = []
def topSort(adj, v, visited):
	if(visited[v]):
		return
	visited[v] = 1
	for i in adj[v]:
		topSort(adj, i, visited)
	res.append(v)
n,m = [int(i) for i in input().split()]
adj = [[] for _ in range(n)]
for i in range(n):
	adj[i] = list()
visited = [0]*n
for _ in range(m):
	x,y = [int(i) for i in input().split()]
	adj[x-1].append(y-1)
# print(adj)
for v in range(n):
	topSort(adj, v, visited)
res = [i+1 for i in res]
print(*res[::-1])
