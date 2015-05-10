
     /* section contains letters which are all 5 spaces tall inputted coordinates is of the top left corner of each letter box
        if there is no character in the top left of the character the (0,0) corner of each letter is taken*/
   /* Character length with 1 space each side. Esp. useful when placing the letters on the grid adjacent to one another.
    * A - 7
    * B - 6
    * C - 7
    * D - 5
    * E - 6
    * F - 
    * G - 7
    * H - 
    * I - 7
    * J - 
    * K - 5
    * L - 7
    * M - 9
    * N - 7
    * O - 7
    * P - 5
    * Q - 
    * R - 7
    * S - 5
    * T - 7
    * U - 7
    * Y - 7
    * Z - 7
    * 
   */  
   /*6x6 box*/
void print6Box(int x, int y)
     {
		 mvaddch(y - 1, x - 1, ' ');
		 mvaddch(y + 1, x + 1, ' ');
		 mvaddch(y + 1, x - 1, ' ');
		 mvaddch(y - 1, x + 1, ' ');
		 mvaddch(y, x, ' ');
		 
		 mvaddch(y + 1, x, ' ');
		 mvaddch(y - 1, x, ' ');
		 mvaddch(y , x - 1, ' ');
		 mvaddch(y , x + 1, ' ');
	 } 
 
void printGameO(int x, int y)
     {
		 mvaddch(y - 1, x - 1, ' ');
		 mvaddch(y + 1, x + 1, ' ');
		 mvaddch(y + 1, x - 1, ' ');
		 mvaddch(y - 1, x + 1, ' ');
		 
		 
		 mvaddch(y + 1, x, ' ');
		 mvaddch(y - 1, x, ' ');
		 mvaddch(y , x - 1, ' ');
		 mvaddch(y , x + 1, ' ');
	 }   
void printGameX(int x, int y)
     {
		 mvaddch(y , x, ' ');
		 mvaddch(y + 1, x + 1, ' ');
		 mvaddch(y - 1, x - 1, ' ');
		 mvaddch(y - 1, x + 1, ' ');
		 mvaddch(y + 1, x - 1, ' ');
	 }
     
 
	 
void outK( int x, int y)
     {
		 mvaddch(y, x, ' ');
		 mvaddch(y + 1, x, ' ');
		 mvaddch(y + 2, x, ' ');
		 mvaddch(y + 3, x, ' ');
		 mvaddch(y + 4, x, ' ');
		 
		 mvaddch(y + 2, x + 1, ' ');
		 
		 mvaddch(y + 1, x + 2, ' ');
		 mvaddch(y + 3, x + 2, ' ');
		 
		 mvaddch(y , x + 3, ' ');
		 mvaddch(y + 4, x + 3, ' ');
	 }   
void outD(int x, int y)
     {
		 
		 mvaddch(y, x, ' ');
		 mvaddch(y, x + 1, ' ');
		 mvaddch(y, x + 2, ' ');
		 mvaddch(y + 4, x + 1, ' ');
		 mvaddch(y + 4, x + 2, ' ');
		 
		 mvaddch(y + 1, x, ' ');
		 mvaddch(y + 2, x, ' ');
		 mvaddch(y + 3, x, ' ');
		 mvaddch(y + 4, x, ' ');
		 
		 mvaddch(y + 1, x + 3, ' ');
		 mvaddch(y + 3, x + 3, ' ');
		 
		 mvaddch(y + 2, x + 4, ' ');

	 }   
void outB(int x, int y)
     {
		 mvaddch(y, x + 1, ' ');
		 mvaddch(y, x + 2, ' ');
		 mvaddch(y + 1, x, ' ');
		 mvaddch(y + 2, x, ' ');
		 mvaddch(y + 3, x, ' ');
		 mvaddch(y + 4, x, ' ');
		 mvaddch(y + 1, x + 3, ' ');
		 mvaddch(y + 2, x + 1, ' ');
		 mvaddch(y + 3, x + 3, ' ');
		 mvaddch(y + 2, x + 2, ' ');
		 mvaddch(y + 4, x + 1, ' ');
		 mvaddch(y + 4, x + 2, ' ');		 
	 }
void outZ(int x, int y)
     {
		 mvaddch(y, x + 2, ' ');
		 mvaddch(y, x , ' ');
		 mvaddch(y, x + 1, ' ');
		 mvaddch(y, x + 3, ' ');
		 mvaddch(y, x + 4, ' ');
		 
		 mvaddch(y + 1, x + 3, ' ');
		 mvaddch(y + 2, x + 2, ' ');
		 mvaddch(y + 3, x + 1, ' ');
		 
		 mvaddch(y + 4, x, ' ');
		 mvaddch(y + 4, x + 1, ' ');
		 mvaddch(y + 4, x + 2, ' ');
		 mvaddch(y + 4, x + 3, ' ');
		 mvaddch(y + 4 , x + 4, ' ');
	 }
void outS(int x, int y)
     {
		 mvaddch(y, x, ' ');
		 mvaddch(y + 1, x, ' ');
		 mvaddch(y + 2, x, ' ');
		 mvaddch(y + 4, x, ' ');
		 mvaddch(y , x + 1, ' ');
		 mvaddch(y + 2, x + 1, ' ');
		 mvaddch(y + 4, x + 1, ' ');
		 mvaddch(y , x + 2, ' ');
		 mvaddch(y + 2, x + 2, ' ');
		 mvaddch(y + 3, x + 2, ' ');
		 mvaddch(y + 4, x + 2, ' ');
	 }
	 
void outT( int x, int y)
     {
		 mvaddch(y, x, ' ');
		 mvaddch(y, x + 2, ' ');
		 mvaddch(y + 1, x + 2, ' ');
		 mvaddch(y + 2, x + 2, ' ');
		 mvaddch(y + 3, x + 2, ' ');
		 mvaddch(y + 4 , x + 2, ' ');
		 mvaddch(y, x , ' ');
		 mvaddch(y, x + 1, ' ');
		 mvaddch(y, x + 3, ' ');
		 mvaddch(y, x + 4, ' ');
	 }
	 
void outA( int x, int y)
     {
		 
		 mvaddch(y + 3, x + 2, ' ');
		 
		 mvaddch(y + 3, x + 3, ' ');
		 mvaddch(y + 3, x + 4, ' ');
		 mvaddch(y + 3, x + 5, ' ');
		 mvaddch(y + 3, x + 6, ' ');
		 
		 mvaddch(y + 4, x + 2, ' ');
		 mvaddch(y + 2, x + 2, ' ');
		 mvaddch(y + 1, x + 3, ' ');
		 mvaddch(y + 0, x + 4, ' ');
		 mvaddch(y + 1, x + 5, ' ');
		 mvaddch(y + 2, x + 6, ' ');
		 
		 mvaddch(y + 4, x + 6, ' ');
		  
	 }
	 
void outR(int x, int y)
     {
		 mvaddch(y, x, ' ');
		 mvaddch(y + 1, x, ' ');
		 mvaddch(y + 2, x, ' ');
		 mvaddch(y + 3, x, ' ');
		 mvaddch(y + 4, x, ' ');
		 
		 mvaddch(y , x + 1, ' ');
		 mvaddch(y , x + 2, ' ');
		 mvaddch(y + 2, x, ' ');
		 mvaddch(y + 2, x + 1, ' ');
		 mvaddch(y + 2, x + 2, ' ');
		 
		 mvaddch(y + 1, x + 3, ' ');
		 mvaddch(y + 3, x + 3, ' ');
		 mvaddch(y + 4, x + 4, ' ');
		 
	 } 
	 
void outO( int x, int y)
     {
		 mvaddch(y, x, ' ');
		 mvaddch(y + 1, x, ' ');
		 mvaddch(y + 2, x, ' ');
		 mvaddch(y + 3, x, ' ');
		 mvaddch(y + 4, x, ' ');
		 
		 mvaddch(y, x+ 4, ' ');
		 mvaddch(y + 1, x + 4, ' ');
		 mvaddch(y + 2, x + 4, ' ');
		 mvaddch(y + 3, x + 4, ' ');
		 mvaddch(y + 4, x + 4, ' ');
		 
		 mvaddch(y , x + 1, ' ');
		 mvaddch(y , x + 2, ' ');
		 mvaddch(y , x + 3, ' ');
		 
		 mvaddch(y + 4 , x + 1, ' ');
		 mvaddch(y + 4, x + 2, ' ');
		 mvaddch(y + 4, x + 3, ' ');
	 }	 
	 
void outP(int x, int y)
     {
		 mvaddch(y, x, ' ');
		 mvaddch(y + 1, x, ' ');
		 mvaddch(y + 2, x, ' ');
		 mvaddch(y + 3, x, ' ');
		 mvaddch(y + 4, x, ' ');
		 
		 mvaddch(y , x + 1, ' ');
		 mvaddch(y , x + 2, ' ');
		 mvaddch(y + 1, x + 2, ' ');
		 mvaddch(y + 2, x + 1, ' ');
		 mvaddch(y + 2, x + 2, ' ');
	 }
void outI( int x, int y)
     {
		 mvaddch(y, x + 2, ' ');
		 mvaddch(y + 1, x + 2, ' ');
		 mvaddch(y + 2, x + 2, ' ');
		 mvaddch(y + 3, x + 2, ' ');
		 mvaddch(y + 4 , x + 2, ' ');
		 mvaddch(y, x , ' ');
		 mvaddch(y, x + 1, ' ');
		 mvaddch(y, x + 3, ' ');
		 mvaddch(y, x + 4, ' ');
		 
		 mvaddch(y + 4, x, ' ');
		 mvaddch(y + 4, x + 1, ' ');
		 mvaddch(y + 4, x + 2, ' ');
		 mvaddch(y + 4, x + 3, ' ');
		 mvaddch(y + 4 , x + 4, ' ');
	 }
void outN (int x, int y)
     {
	   	 mvaddch(y, x, ' ');
		 mvaddch(y + 1, x, ' ');
		 mvaddch(y + 2, x, ' ');
		 mvaddch(y + 3, x, ' ');
		 mvaddch(y + 4, x, ' ');
		 
		 mvaddch(y, x + 4, ' ');
		 mvaddch(y + 1, x + 4, ' ');
		 mvaddch(y + 2, x + 4, ' ');
		 mvaddch(y + 3, x + 4, ' ');
		 mvaddch(y + 4, x + 4, ' '); 
		 
		 mvaddch(y + 1, x + 1, ' ');
		 mvaddch(y + 2, x + 2, ' ');
		 mvaddch(y + 3, x + 3, ' ');
		 
	 }
void outC (int x, int y)
     {
	 	 mvaddch(y, x, ' ');
		 mvaddch(y + 1, x, ' ');
		 mvaddch(y + 2, x, ' ');
		 mvaddch(y + 3, x, ' ');
		 mvaddch(y + 4, x, ' ');
		 
		 		 
		 mvaddch(y + 4, x + 1, ' ');
		 mvaddch(y + 4, x + 2, ' ');
		 mvaddch(y + 4, x + 3, ' ');
		 mvaddch(y + 4 , x + 4, ' ');
		 
		 		 
		 mvaddch(y , x + 1, ' ');
		 mvaddch(y , x + 2, ' ');
		 mvaddch(y , x + 3, ' ');
		 mvaddch(y , x + 4, ' ');
		 
	 }
void outL( int x, int y)
     {
	     mvaddch(y, x, ' ');
		 mvaddch(y + 1, x, ' ');
		 mvaddch(y + 2, x, ' ');
		 mvaddch(y + 3, x, ' ');
		 mvaddch(y + 4, x, ' ');
		 
		 mvaddch(y + 4, x + 1, ' ');
		 mvaddch(y + 4, x + 2, ' ');
		 mvaddch(y + 4, x + 3, ' ');
		 mvaddch(y + 4 , x + 4, ' ');
		 
		 
	 }	 
void outY (int x, int y)
     {
		 mvaddch(y + 2, x+ 2, ' ');
		 mvaddch(y + 3, x + 2, ' ');
		 mvaddch(y + 4, x + 2, ' ');
		 mvaddch(y, x + 4, ' ');
		 mvaddch(y ,x, ' ');
		 mvaddch(y + 1 ,x + 3, ' ');
		 mvaddch(y + 1 ,x + 1, ' ');
		 
	 }
void outG (int x, int y)
     {
		 mvaddch(y, x, ' ');
		 mvaddch(y + 1, x, ' ');
		 mvaddch(y + 2, x, ' ');
		 mvaddch(y + 3, x, ' ');
		 mvaddch(y + 4, x, ' ');
		 
		 		 
		 mvaddch(y + 4, x + 1, ' ');
		 mvaddch(y + 4, x + 2, ' ');
		 mvaddch(y + 4, x + 3, ' ');
		 mvaddch(y + 4 , x + 4, ' ');
		 
		 		 
		 mvaddch(y , x + 1, ' ');
		 mvaddch(y , x + 2, ' ');
		 mvaddch(y , x + 3, ' ');
		 mvaddch(y , x + 4, ' ');
		 
		 mvaddch(y + 3 , x + 4, ' ');
		 mvaddch(y + 2 , x + 4, ' ');
		 mvaddch(y + 2 , x + 3, ' ');
		 mvaddch(y + 2 , x + 2, ' ');
	 }
void outM (int x, int y)
     {
		 mvaddch(y, x, ' ');
		 mvaddch(y + 1, x, ' ');
		 mvaddch(y + 2, x, ' ');
		 mvaddch(y + 3, x, ' ');
		 mvaddch(y + 4, x, ' ');
		 
		 mvaddch(y, x + 6, ' ');
		 mvaddch(y + 1, x + 6, ' ');
		 mvaddch(y + 2, x + 6, ' ');
		 mvaddch(y + 3, x + 6, ' ');
		 mvaddch(y + 4, x + 6, ' ');
		 
		 mvaddch(y + 1, x + 1, ' ');
		 mvaddch(y + 1, x + 5, ' ');
		 
		 mvaddch(y + 2, x + 2, ' ');
		 mvaddch(y + 3, x + 2, ' ');
		 mvaddch(y + 2, x + 4, ' ');
		 mvaddch(y + 3, x + 4, ' ');
		 
		 mvaddch(y + 4, x + 3, ' ');
		 
	 }
void outE(int x, int y)
     {
		 mvaddch(y, x, ' ');
		 mvaddch(y + 1, x, ' ');
		 mvaddch(y + 2, x, ' ');
		 mvaddch(y + 3, x, ' ');
		 mvaddch(y + 4, x, ' ');
		 
		 		 
		 mvaddch(y + 4, x + 1, ' ');
		 mvaddch(y + 4, x + 2, ' ');
		 mvaddch(y + 4, x + 3, ' ');
		 
		 		 
		 mvaddch(y , x + 1, ' ');
		 mvaddch(y , x + 2, ' ');
		 mvaddch(y , x + 3, ' ');
 
         mvaddch(y + 2, x + 1, ' ');
         mvaddch(y + 2, x + 2, ' ');
         mvaddch(y + 2, x + 3, ' ');
	 }
	 
void outU(int x, int y)
     {
		 mvaddch(y, x, ' ');
		 mvaddch(y + 1, x, ' ');
		 mvaddch(y + 2, x, ' ');
		 mvaddch(y + 3, x, ' ');
		 mvaddch(y + 4, x, ' ');
		 
		 mvaddch(y, x+ 4, ' ');
		 mvaddch(y + 1, x + 4, ' ');
		 mvaddch(y + 2, x + 4, ' ');
		 mvaddch(y + 3, x + 4, ' ');
		 mvaddch(y + 4, x + 4, ' ');
		 
		 mvaddch(y + 4 , x + 1, ' ');
		 mvaddch(y + 4, x + 2, ' ');
		 mvaddch(y + 4, x + 3, ' ');
	 }
