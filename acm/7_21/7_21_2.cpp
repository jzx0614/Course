   #include<iostream.h>
   #include<fstream.h>
   #include<math.h>
   void f ( int , unsigned long );
   int check (unsigned long);
   unsigned long x[10000]={0},t=0;
   void main()
   {
	int n;
	unsigned long num;
	ifstream fin("sprime.in");
	ofstream fout("sprime.out");
	fin >> n;
	f(n,2);	f(n,3);	f(n,5);	f(n,7);
	for(int i=0;i<t;i++)
	{
		fout << x[i] <<endl;
	}
	fin.close();
	fout.close();
   }
   int check(unsigned long num)
   {    int r=1;
	for(int i=2;i<=sqrt(num);i++)
	{
		   if(num%i==0)
		   {
			r=0;
			break;
		   }
	}
	return r;
   }
   void f ( int n,unsigned long num)
   {
	if(n>1)
	{
		for(int i=1;i<10;i++)
		{
			if(check(num*10+i))
				{f(n-1,num*10+i);}
		}
	}
	else if (n==1)
	{
		x[t++]=num;
	}
   }