import networkx as nx
import matplotlib.pyplot as plt

G=nx.Graph()
G.add_node("a")
G.add_nodes_from(["b","c"])

edge = ("a", "b")
G.add_edge(*edge)
edge = ("a", "c")
G.add_edge(*edge)
edge = ("a", "d")
G.add_edge(*edge)
edge = ("a", "e")
G.add_edge(*edge)
edge = ("a", "f")
G.add_edge(*edge)

#print("Nodes of graph: ")
#print(G.nodes())
#print("Edges of graph: ")
#print(G.edges())

nx.draw(G)
plt.savefig("Grafos.png") # save as png
plt.show() # display
