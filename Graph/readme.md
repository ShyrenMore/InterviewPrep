# Intro

- Consider a friendship relationship where anyone person can be friends with any other person, there can be cycles, we cannot represent such a relationship with Tree
- So whenever we have random conncetions among nodes, we use Graph DS
- Graph is represented by pair of sets 
```G = (V, E)```
<br>

    here 
- V is set of vertices, V = {v1, v2..}
- E set of edges, E = {(v1, v2), (v3, v4),...}

## Directed vs Undirected graph 
- In undirected graphs the edge is unordered i.e (v1, v2) is same as (v2, v1) but in a directed graph both pair have different meanings since they are ordered pairs 
- Real word eg of undirected graph: social network, if v1 is friend of v2, this means, v2 is a friend of v1
- Real word eg of directed graph: World wide web, if we consider vertices as web-pages then pair (v1, v2) will mean page v1 has link to page v2 and but vice versa is not true

# Terms

1. Degree of a vertex: 

- For undirected graph: No of egdes going through that vertex
- For directed graph: 
    - InDegree: no of edges coming to the node 
    - OutDegree: no of edges coming out of the node 

2. Relation b/w degree and no of edges:
- For undirected graph: ```sum of indegrees = sum of outdegrees = | E |```
- For directed graph: ```sum of degrees = 2 * | E |```

3. Maximum edges (excluding the possibility of self loops):

- For undirected graph(4 edges for each): ```V*(V-1)``` 
- For directed graph(2 edges for each): ```V*(V-1)/2```

4. Walk: a sequence of vertices that we get **by following edges** 
- eg: v1, v2, v4, v2

5. Path: a path is a special walk with no repitition of vertices 
- eg: v1, v2, v4

6. Cyclic graph: a graph is called cyclic if there exists a walk in the graph that begins and ends with same vertex (cyclic graphs can be directed as well as undirected)

7. Acyclic graph: a graph that does not contain a cycle is called acyclic (acyclic graphs can be directed as well as undirected
- Directed acyclic graph (DAG) has many applications like job scheduling algorithm, topological sorting 

8. Weighted Graph: A graph that has weights assigned to it's edges. It can be directed or undirected. 
- A real life example is a graph of road networks, where roads are connected to multiple cities and weight of edges is determined by length of the road. 
- If two cities are far away from each other then the road or edge that connects these two cities has more weight comapred to closer cities 
- A similar example is with routers in computer networks 