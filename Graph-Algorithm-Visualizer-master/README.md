# Graph-Algorithm-Visualizer

This is a mini project I created to show how different graph algorithms work, currently the project contains - :
1) Breadth-First Search
2) Depth-First Search

I intent on adding more path finding algorithms and different visualization to the code


The algorithms I have created are for visualization purpose so each time a node is visited the complete array is printed from beginning and this means a huge dip in terms of computation.

Normally for a matrix BFS and DFS take O(n^2) time but as after each iteration the complete matrix is being printed again so that adds a O(n^2) extra operation per iteration.

Input Format: 
It takes a 10*10 matrix intially empty

First Input: Starting Position 
Second Input: Ending Position
Third Input: No. of walls / Places which cannot be traversed by the algorithm
Fourth Input: Coordinated of Walls
Fifth Input: 1) BFS 2)DFS
