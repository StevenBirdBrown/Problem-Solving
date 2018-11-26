#include <cstdio>
#include <cmath>
#include <set>
using namespace std;
inline int resq(int a, int b, int p)
{
	int c = a, d = 1;
	for(int i=0;b;++i)
	{
		if(b&0x1)
		{
			d = d * c % p;
			c = c * c % p;
		}
		b>>=1;
	}
	return d;
}
int n = 63;
int main()
{
	set<int> s;
	for(int i=1;i<n;++i)
	{
		int tmp = resq(i, (n-1) / 2, n);
		if(tmp!=1&&tmp!=-1)
		{
			for(int j=1;j<n;++j)
			{
				if(i*j%n==1)
				{
					s.insert(i);
					s.insert(j);
				}
			}
		}
	}
	set<int>::iterator iter;
	for(iter = s.begin(); iter!=s.end(); ++iter)
		printf("%d ", *iter);
	return 0;
 } 
