# Union Find Algorithm in Python
class UnionFind:
	def __init__(self, n):
		# n: number of nodes
		self.n = n
		self.numComponents = n 					# Initially n components
		self.parent = [i for i in range(n+1)]	# Nodes from [1...n]
		self.size = [1 for i in range(n+1)]		# Initally all component sizes = 1

	def find(self, x):
		# finds parent of node x
		if self.parent[x] == x:	# If parent is itself, return
			return x
		# Otherwise, recursively find the parent and then set current node's parent to the final root
		# AKA, path compression
		root = self.find(self.parent[x])
		self.parent[x] = root
		return root

	def union(self, x, y):
		x = self.find(x)
		y = self.find(y)
		# if both have same root, then no need to unite
		if x != y:
			# For efficiency, we want to set the smaller component's parent as the larger one
			if self.size[x] < self.size[y]:
				x, y = y, x
			# Now x is the larger component
			self.parent[y] = x
			self.size[x] += self.size[y]
			self.numComponents -= 1		# Number of components decreases by one when uniting

	def getNumComponents(self):
		return self.numComponents

	def getComponentSize(self, x):
		return self.size[x]
