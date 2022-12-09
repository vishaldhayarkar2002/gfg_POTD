// The idea is , for each cell the knight can attack at most 8 cells . So for each cell we can place other knight in (M*N-1) places . So total possible arrangements are (M*N)*(M*N-1) .
/*we keep track of a variable ret , initialize the variable with 0 
now we will loop through all the boxes in chess board
for each boxes in chess board (i,j) we will check (i+2,j+1),(i+2,j-1),(i-2,j+1),(i-2,j-1),(i+1,j-2),(i+1,j+2),(i-1,j+2),(i-1,j-2) positions
for each attacking positions if the positions lies inside the bound of the board , we will increase the ret variable by 1
now we will substract ret from all possible arrangements . and return the answer

Alternative approach
Intuition
We can solve this problem more efficiently . 
 The arrangements in this case where knight to move 2 steps in the horizontal direction and 1 step in the vertical.
where attack is possible are equal to 4 * (N – 2) * (M – 1) and similarly for 2 steps in the vertical direction and 1 step in the horizontal ,
 where attack is possible are equal to 4* (N-1) * (M-2). Thus the answer will be 
 Total possible arrangement – 4 * (N – 2) * (M – 1) – 4 * (N – 1) * (M – 2).
Implementation
check if N is greater then or equal to 2 and M is greater than or equal to 1. then substract 4 * (N – 2) * (M – 1) from all possible arrangements
check if M is greater than or equal to 1 and N is greater than or equal to 2 . then substract  4* (N-1) * (M-2) from all possible arrangements*/ 

//Function to find out the number of ways we can place a black and a white 
//Knight on this chessboard such that they cannot attack each other.
long long numOfWays(int n, int m) 
{
    //specifying the directions to check in i.e 8 directions.
    static int x_off[] = {-2, -2, -1, 1, 2, 2, 1, -1};
    static int y_off[] = {-1, 1, 2, 2, 1, -1, -2, -2};
    static const long long MOD = (long long)1e9 + 7;

    //using variable to maintain number of positions which are not feasible.
    long long ret = 0;
    int x, y;

    //iterating for complete matrix.
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j) 
        {
            for (int k = 0; k < 8; ++k)
            {
                x = i + x_off[k];
                y = j + y_off[k];
                //checking if the attack position is within bounds.
                if (x >= 0 && x < n && y >= 0 && y < m)
                    //if in bounds then it is not feasible so we increment.
                    ++ret; 
            }
        }
    }
    long long total = n * m;
    
    //total possible combinations of 2 knights.
    total =(total * (total - 1)) % MOD; 
    
    // returning total feasible combinations.
    return (total + MOD - ret) % MOD; 
}