#include<bits/stdc++.h>
using namespace std;
char a[100];
int now,len;
void play(int thumb,int time)
{
    int i;
    switch(thumb)
    {
    case 1 :
        for(i=0; i<time; i++)
        {
            len = strlen(a);
            if(len==0)
                return ;
            a[len-1] = '\0';
            now-=1;
        }
        break;
    case 2 :
        time%=3;
        if(time==1)
            a[now] = 'A';
        else if(time==2)
            a[now] = 'B';
        else
            a[now] = 'C';
        now++;
        break;
    case 3 :
        time%=3;
        if(time==1)
            a[now] = 'D';
        else if(time==2)
            a[now] = 'E';
        else
            a[now] = 'F';
        now++;
        break;
    case 4 :
        time%=3;
        if(time==1)
            a[now] = 'G';
        else if(time==2)
            a[now] = 'H';
        else
            a[now] = 'I';
        now++;
        break;
    case 5 :
        time%=3;
        if(time==1)
            a[now] = 'J';
        else if(time==2)
            a[now] = 'K';
        else
            a[now] = 'L';
        now++;
        break;
    case 6 :
        time%=3;
        if(time==1)
            a[now] = 'M';
        else if(time==2)
            a[now] = 'N';
        else
            a[now] = 'O';
        now++;
        break;
    case 7 :
        time%=4;
        if(time==1)
            a[now] = 'P';
        else if(time==2)
            a[now] = 'Q';
        else if(time==3)
            a[now] = 'R';
        else
            a[now] = 'S';
        now++;
        break;
    case 8 :
        time%=3;
        if(time==1)
            a[now] = 'T';
        else if(time==2)
            a[now] = 'U';
        else
            a[now] = 'V';
        now++;
        break;
    default :
        time%=4;
        if(time==1)
            a[now] = 'W';
        else if(time==2)
            a[now] = 'X';
        else if(time==3)
            a[now] = 'Y';
        else
            a[now] = 'Z';
        now++;
    }

}
int main ()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
    int q,pos,s,i,time,v,h,mkr;
    cin >> q;
    cin >> s >> time ;
    pos = s;
    now=0;
    q-=1;
    play(s,time);

    while(q--)
    {
        cin >> h >>v >> time ;
        pos = pos + h + (v*3);
        play(pos,time);
        //cout << pos << endl;
    }
    mkr = strlen(a);
    if(mkr==0)
    {
        cout << "null";
        return 0;
    }
    for(i=0; i<now; i++)
        cout << a[i] ;
    return 0;
}
