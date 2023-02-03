# Graph Alorithms 
## To Build
   - make
## To Clean *.out files
   - make clean
# DijkstraAlgo
## To Test
   - ./testDijkstra.sh
### Graph being used 
![alt text](./Screenshot%202023-02-02%20at%207.47.51%20PM.png)
### Terminal output of Graph
```
Printed Graph: (src, dst, weight)
(0, 1, 6) (0, 2, 5) 
(1, 0, 6) (1, 2, 7) (1, 2, 4) 
(2, 1, 7) (2, 0, 5) (2, 1, 4) (2, 3, 10) 
(3, 2, 10) 
(4, 5, 1) (4, 5, 3) 
(5, 4, 1) (5, 4, 3) 
Current Node ( 0 ): 0 6 5 15 1000000000 1000000000 
Current Node ( 1 ): 6 0 4 14 1000000000 1000000000 
Current Node ( 2 ): 5 4 0 10 1000000000 1000000000 
Current Node ( 3 ): 9 8 8 0 1000000000 1000000000 
Current Node ( 4 ): 1000000000 1000000000 1000000000 1000000000 0 1 
Current Node ( 5 ): 1000000000 1000000000 1000000000 1000000000 1 0 
```
