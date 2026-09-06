<h2><a href="https://www.geeksforgeeks.org/problems/game-of-life/1">Conway's Game Of Life</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18px;">Consider a binary matrix <strong>mat[][]</strong> of size <strong>m × n</strong>, where each cell represents either a <strong>dead </strong>(0) or <strong>live </strong>(1) state. This configuration represents a generation, and your task is to compute the next generation of the matrix based on the following rules:</span></p>
<ol>
<li><span style="font-size: 18px;">Any live cell with fewer than two live (&lt; 2) neighbours dies as if caused by underpopulation.</span></li>
<li><span style="font-size: 18px;">Any live cell with two or three live (= 2 or 3) neighbours lives on to the next generation.</span></li>
<li><span style="font-size: 18px;">Any live cell with more than three live (&gt; 3) neighbours dies, as if by overpopulation.</span></li>
<li><span style="font-size: 18px;">Any dead cell with exactly three live (= 3) neighbours becomes a live cell, as if by reproduction.</span></li>
</ol>
<p><span style="font-size: 18px;">Neighbours are the cells connected horizontally, vertically, or diagonally to a given cell (i.e., all 8 adjacent cells are considered neighbours).</span></p>
<p><span style="font-size: 18px;"><strong>Note:</strong> The neighbour cells that lie outside the matrix mat[][] are considered dead. The updation of all cells should be done based on the original values of the matrix, not on the values that are being updated during the process. You do not need to return anything, modify the matrix in-place.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>mat[][] = [[0, 1, 0],<br>               [0, 0, 1],<br>               [1, 1, 1],<br>               [0, 0, 0]]
<strong>Output: </strong>[[0, 0, 0],<br>        [1, 0, 1],<br>        [0, 1, 1],<br>        [0, 1, 0]]<br></span></pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>mat[][] = [[1,1],<br>               [1,0]]
<strong>Output: </strong>[[1,1],<br>        [1,1]]</span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:<br></strong></span><span style="font-size: 18px;">1 ≤ m, n ≤ 300<br>0 ≤ mat[i][j] ≤ 1</span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Matrix</code>&nbsp;