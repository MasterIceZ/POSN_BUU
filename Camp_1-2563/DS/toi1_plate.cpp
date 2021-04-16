/*
 *	AUTHOR : IceBorworntat
 * */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define us unsigned
#define f0(a,b,c) for(a=b;b<c;a++)
#define f1(a,b,c) for(a=b;b<=c;a++)
#define f2(a,b,c) for(a=b;a>c;a--)
#define f3(a,b,c) for(a=b;a>=c;a--)
#define r4i {-1,1,0,0}
#define r4j {0,0,-1,1}
#define r8i {-1,-1,-1,0,0,1,1,1}
#define r8j {-1,0,1,-1,1,-1,0,1}
#define pb push_back
queue <int> classrow;
queue <int> student[11];
int mark[11];
int stu[10010];
int main ()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int i,j,n,m,num1,num2,num;
	cin >> n >> m;
	for(i=0;i<m;i++)
	{
		cin >> num1 >> num2;
		stu[num2] = num1;
	}
	char opr;
	while(1)
	{
		cin >> opr;
		if(opr=='X')
		{
			cout << "0" << endl;
			break;
		}
		if(opr=='E')
		{
			cin >> num;
			if(student[stu[num]].empty())
            {
                classrow.push(stu[num]);
            }
			student[stu[num]].push(num);
			// insert class queue
			// classrow.push(stu[num]);
			/*
			if(classrow[stu[num]].empty())
			{
				classrow.push(stu[num]);
			}
			*/
		}
		if(opr=='D')
		{
			//cin >> num;
			if(classrow.empty())
			{
				cout << "empty" << endl;
			}
			else
			{
				/*
				 * Check Classrow
				 * print(stdudent[Classrow.front()].front)
				 * student[Classrow.front()].pop()
				 * break
				 * */
				cout << student[classrow.front()].front() << endl;
				student[classrow.front()].pop();
				if(student[classrow.front()].empty())
                {
                    classrow.pop();
                }
			}
		}
	}
	return 0;
}
