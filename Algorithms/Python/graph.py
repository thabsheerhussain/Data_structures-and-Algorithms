# Graph algorithms in Python
from collections import defaultdict

class Graph:
	def __init__(self):
		# Adjacency list representation
		self.graph = defaultdict(list)

	def addEdge(self, u, v):
		# Assuming undirected graph
		self.graph[u].append(v)
		self.graph[v].append(u)	# Remove this line if graph is directed

	def dfsIterative(self, start):
		visited, stack = set(), [start]
		# stack stores the nodes from which we need to perform dfs
		# we remove the top node from the stack and perform dfs on that node
		while stack:
			u = stack.pop()
			if u not in visited:
				visited.add(u)
				for w in self.graph[u]:
					if w not in visited:
						stack.append(w)

	def dfsRecursive(self, node, visited=set()):
		if node not in visited:
			visited.add(node)
			for other in self.graph[node]:
				# recur down all the nodes adjacent to the current
				if other not in visited:
					self.dfsRecursive(other, visited)

	def bfs(self, start):
		visited, queue = set(), [start]
		visited.add(start)
		while queue:
			u = queue.pop(0)	# Unlike in dfs, we pop from the left
			for v in self.graph[u]:
				if v not in visited:
					visited.add(v)
					queue.append(v)
	
	def dijkstra(self, start, end):
		heap = [(0, start)]				# dist to start is 0
		visited = set()
		while heap:
			(u_dist, u) = heapq.heappop(heap)	# Remove the closest vertex
			if u not in visited:
				visited.add(u)
				if u == end:
					return u_dist
				for v, v_dist in self.graph[u]:	# Relax all neighbours from u
					if v not in visited:
						dist = u_dist + v_dist
						heapq.heappush(heap, (dist, v))
		return inf	# we cannot reach the target
