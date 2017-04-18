void Lee (int k, int x, int y)
 {
     // First check for boundaries...
     if(x+1 < n+1)
     {
         // Go down...
         if(m[x+1][y] > k+1)
         {
             m[x+1][y] = k+1;
             Lee (k+1, x+1, y);
         }
     }
      
     // First check for boundaries
     if(x-1 > 0)
     {
         // Go up...
         if(m[x-1][y] > k+1)
         {
             m[x-1][y] = k+1;
             Lee (k+1, x-1, y);
         }
     }
  
     // First check for boundaries
     if(y+1 < n+1)
     {
         // Go right...
         if(m[x][y+1] > k+1)
         {
             m[x][y+1] = k+1;
             Lee (k+1, x, y+1);
         }
     }
  
     // First check for boundaries
     if(y-1 > 0)
     {
         // Go left...
         if(m[x][y-1] > k+1)
         {
             m[x][y-1] = k+1;
             Lee (k+1, x, y-1);
         }
     }
 }