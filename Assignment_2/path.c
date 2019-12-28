/*
program : path.c
Author : Vanshaj Verma
*/

#include <stdio.h>

int find_path (int n, int m, int A[], int i, int j, int k, int l, int path[][2]){

    // Defining variables
    int yMove=i, xMove=j;
    int A2[n][m], A2Marked[n][m];
    int pathFound=0; 
    int checkCounter=0; // Keeps track of number of directional checks
    int pRow=0;         // Used to index path array's rows 
    int length=0;       // Finds length of path
    int moved=0;        // Tracks how many movements were made
    int y=0,t=0;

    // Converts 1D matrix A to 2D matrix A2 for easier indexing
    for (y=0;y<m;y++){
        for(t=0;t<n;t++){
            A2[t][y]=A[t*m+y];
            A2Marked[t][y]=A[t*m+y];
        }
    }

    // Returns exceptions handeled here
    if (A2[i][j]==1 || A2[k][l]==1) return -1;
    if (i<0||i>=n) return -2;
    if (j<0||j>=m) return -3; 

    // Return 1 if path is found right away
    if (i==k && j==l) return 1;

    // Puts first entry in path array and marks first element
    A2Marked[i][j]=2;  path[0][0]=i;  path[0][1]=j;  length++;

    // Keep traversing untill a path is found
    while(pathFound==0) 
    {
                   
        // Traverses matrix rightward
        while (xMove<(m-1)) {
            if (A2[yMove][xMove+1]==0 && A2Marked[yMove][xMove+1]!=2) {
                xMove++; 
                A2Marked[yMove][xMove]=2;
                path[++pRow][0]=yMove;
                path[pRow][1]=xMove; 
                length++;   moved++;   checkCounter=0; 
                if (xMove==l && yMove==k) { pathFound=1; return length; } 
            } else { checkCounter++; break; }
        } 

        // Traverses matrix downward
        while (yMove<(n-1)) {
            if (A2[yMove+1][xMove]==0 && A2Marked[yMove+1][xMove]!=2) {
                yMove++; 
                A2Marked[yMove][xMove]=2;
                path[++pRow][0]=yMove;
                path[pRow][1]=xMove; 
                length++;   moved++;   checkCounter=0;  
                if (xMove==l && yMove==k) { pathFound=1; return length; } 
            } else { checkCounter++; break; }
        } 

        // Traverses matrix leftward
        while (xMove>0) {
            if (A2[yMove][xMove-1]==0 && A2Marked[yMove][xMove-1]!=2) {
                xMove--; 
                A2Marked[yMove][xMove]=2;
                path[++pRow][0]=yMove;
                path[pRow][1]=xMove; 
                length++;   moved++;   checkCounter=0; 
                if (xMove==l && yMove==k) { pathFound=1; return length; } 
            } else { checkCounter++; break; }
        } 

        // Traverses matrix upward
        while (yMove>0) {
            if(A2[yMove-1][xMove]==0 && A2Marked[yMove-1][xMove]!=2) {
                yMove--; 
                A2Marked[yMove][xMove]=2;
                path[++pRow][0]=yMove;
                path[pRow][1]=xMove; 
                length++;   moved++;   checkCounter=0; 
                if (xMove==l && yMove==k) { pathFound=1; return length; } 
            } else { checkCounter++; break; }
        } 

        // If all 4 directions are checked, either there is no path or there is
        if (checkCounter>3) 
        {
            if (yMove>=0 && yMove<=(n-1) && xMove>=0 && xMove<=(m-1) && moved>0) 
            {
                // Eliminates current values
                path[pRow][0]=0;
                path[pRow][1]=0;

                // Go up the path list
                yMove=path[--pRow][0];
                xMove=path[pRow][1]; 
                length--;
                moved--;
                checkCounter=0;
            } else { return 0; }
        }
    }    
    return 0;    
}
