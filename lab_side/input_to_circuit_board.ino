void setup() {
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(A3,OUTPUT);
  pinMode(A4,OUTPUT);
  pinMode(A5,OUTPUT);
  pinMode(A6,OUTPUT);
  pinMode(A7,OUTPUT);

}

void loop() 
{
  int X[4][3];
  int Y[4][3];
  int Z[4][4];
  int row,i,a,b,m,n,p,q;
  for(row=0;row<10;row++)
  {
    a =2,b=3,c=2;
    switch(c)
    {case 1 : p=0,q=1;
     case 2 : p=1,q=0;
     case 3 : p=1,q=1;
    }
    m=a-1
    n=(a-1)+[b-a-1]
    for(i=m;i<=n;i++)
      {if(i==m)
        {X [row][i] = p;}
       else
       {X [row] [i] = 1;
      }
    for(i=m;i<=n;i++)
      {if(i==m)
        {Y [row][i] = q;}
       else
       {Y [row] [i] = 1;
      }

    Z[[row][m] =1
    Z[row][n] =1
  } 
  for(int j=0;j<3;j++)
  { 
  digitalWrite(A0,X[0][j]);
  digitalWrite(A1,Y[0][j]);
  digitalWrite(A2,X[1][j]);
  digitalWrite(A3,Y[1][j]);
  digitalWrite(A4,X[2][j]);
  digitalWrite(A5,Y[2][j]);
  digitalWrite(A6,X[3][j]);
  digitalWrite(A7,Y[4][j]);
  delay(1000);
  }
}
