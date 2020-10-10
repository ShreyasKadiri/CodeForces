#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const int N=2e3+10;
int Match[N],Pre[N][N],Pos[N][N],n,a[N][N],tot=0,to[N],from[N],To[N];
vector<pii>vec;
inline void solve(int p)
{
	for(int i=0;i<p;++i)
	{
		from[i]=to[i]=p;
		To[i]=0;
	}
	bool fl=false;
	while(!fl)
	{
		fl=true;
		for(int k=0;k<p;++k)
		{
			if(To[k]>=p-1)return;
			if(to[k]==p)
			{
				int tmp=Pre[k][To[k]],op=Pos[tmp][k],cur=p;
				if(from[tmp]!=p)cur=Pos[tmp][from[tmp]];
				if(op<cur)
				{
					to[k]=tmp;
					if(from[tmp]!=p)
					{
						to[from[tmp]]=p;
						fl=false;
					}
					from[tmp]=k;
				}
				else fl=false;
				To[k]++;
			}
		}
	}
	vector<deque<int> >mp(p,deque<int>(p-1));
	for(int k=0;k<p;++k)for(int i=0;i<p-1;++i)mp[k][i]=Pre[k][i];
	for(int k=0;k<p;++k)for(int i=mp[k].size()-1;i>=0;i--)
	if(mp[k][i]==from[k])break;
	else
	{
		if(mp[k].size()==0)return;
		bool is=false;
		for(int j=0;j<mp[mp[k].back()].size();++j)if(mp[mp[k].back()][j]==k)
		{
			mp[mp[k].back()].erase(mp[mp[k].back()].begin()+j);
			is=true;
			break;
		}
		if(!is)return;
		mp[k].pop_back();
	}
	fl=false;
	while(!fl)
	{
		fl=true;
		for(int k=0;k<p;++k)if(mp[k].size()>1)
		{
			fl=false;
			vector<int>x,index;
			int Index=k,Tail=-1;
			while(Tail==(int)(index.end()-index.begin()-1))
			{
				int X=mp[Index][1];
				Index=mp[X].back();
				Tail=find(index.begin(),index.end(),Index)-index.begin();
				x.push_back(X);
				index.push_back(Index);
			}
			for(int i=Tail+1;i<index.size();++i)while(mp[x[i]].back()!=index[i-1])
			{
				int Size=mp[mp[x[i]].back()].size();
				mp[mp[x[i]].back()].erase(remove(mp[mp[x[i]].back()].begin(),mp[mp[x[i]].back()].end(),x[i]),mp[mp[x[i]].back()].end());
				if(Size==mp[mp[x[i]].back()].size())return;
				if(mp[x[i]].size()==1)return;
				mp[x[i]].pop_back();
			}
		}
	}
	for(int i=0;i<mp.size();++i)if(mp[i].empty())return;
	for(int k=0;k<p;++k)Match[k]=mp[k][0];
	return;
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)if(i!=j)a[i][j]=read();
	if(n&1)
	{
		puts("-1");
		return 0;
	}
	for(int i=1;i<=n;++i)
	{
		vec.clear();
		for(int j=1;j<=n;++j)if(i!=j)vec.push_back(make_pair(a[i][j],j));
		sort(vec.begin(),vec.end());
		for(int j=0;j<vec.size();++j)
		{
			Pre[i-1][j]=vec[j].second-1;
			Pos[i-1][vec[j].second-1]=j;
		}
	}
	solve(n);
	for(int i=1;i<=n;++i)if(Match[i]!=0)
	{
		tot=1;
		break;
	}
	if(!tot)
	{
		puts("-1");
		return 0;
	}
	for(int i=1;i<=n;++i)printf("%d\n",Match[i-1]+1);
	return 0;
}
