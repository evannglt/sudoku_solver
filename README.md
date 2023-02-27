# sudoku_solver

How to use it (grid has to be 16\*16 numbers from 1 to 9 or 0 if undetermined):

```bash
<download_path>/sudoku_solver <grid.in
```

e.g

```bash
./sudoku_solver <grid.in
```

will output :

```bash
Found solution in 0.085066 seconds

9 1 7 3 4 5 8 6 2
8 5 6 1 2 9 4 7 3
2 3 4 6 7 8 9 1 5
6 4 2 5 3 1 7 9 8
1 9 3 8 6 7 5 2 4
5 7 8 4 9 2 6 3 1
4 8 9 2 1 6 3 5 7
3 6 1 7 5 4 2 8 9
7 2 5 9 8 3 1 4 6
```

Compiling from source :

```bash
gcc -o <name> sudoku_solver.c
```
