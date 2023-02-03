# Graph Algorithms 
## To Build
   - make
## To Clean *.out files
   - make clean
# Dijkstra Algorithm
## To Test
   - ./testDijkstra.sh
### Graph being used 
![alt text](./image.png)
### Terminal output of Graph
```
Printed Graph: (src, dst, weight)
(0, 1, 6) (0, 2, 5) 
(1, 0, 6) (1, 2, 7) (1, 2, 4) 
(2, 1, 7) (2, 0, 5) (2, 1, 4) (2, 3, 10) 
(3, 2, 10) 
(4, 5, 1) (4, 5, 3) 
(5, 4, 1) (5, 4, 3) 

Distance Table:

Node 0:  0 6 5 15 1000000000 1000000000 
Node 1:  6 0 4 14 1000000000 1000000000 
Node 2:  5 4 0 10 1000000000 1000000000 
Node 3:  9 8 8 0 1000000000 1000000000 
Node 4:  1000000000 1000000000 1000000000 1000000000 0 1 
Node 5:  1000000000 1000000000 1000000000 1000000000 1 0 
```
