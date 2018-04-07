#include<iostream>

using namespace std;

void main()
{
	int a=0,b=0,n=1,win=0,loc=0,i,j;
	int game[4][4];

	while(a!=1 && a!=2)
	{
		cout<<"玩家A請輸入 1使用○ 2使用╳ 來進行遊戲:";
		cin>>a;
		if(a!=1 && a!=2)
			cout<<a<<"輸入錯誤"<<endl;
	}
	if(a==1)
	{
		cout<<"玩家A選擇使用○進行遊戲，玩家B為╳"<<endl;
		b=2;
	}
	else
	{
		cout<<"玩家A選擇使用╳進行遊戲，玩家B為○"<<endl;
		b=1;
	}

	for(i=1;i<=3;i++)
		for(j=1;j<=3;j++)
		{
			game[i][j]=n;
			n++;
		}

	for(i=1;i<=3;i++)
	{
		for(j=1;j<=3;j++)
		{
			cout<<" "<<game[i][j]<<" ";
			if(game[i][j]%3!=0)
				cout<<"|";
		}
		cout<<endl;
		if(game[i][j]!=9)
			cout<<"-----------"<<endl;
		else
			cout<<endl;
	}
	
	
	for(i=1;i<=3;i++)
		for(j=1;j<=3;j++)
			game[i][j]=0;

	cout<<"請輸入螢幕上所顯示的位置的代號來放入○或╳"<<endl;

	while(win==0)
	{
		while(loc==0)
		{
			cout<<"玩家A要放在哪:";
			cin>>loc;
			if(loc<1 || loc>9)
			{
				cout<<"請輸入1~9的數字"<<endl;
				loc=0;
			}
			else if(loc>3)
			{
				if(loc%3==0)
				{
					game[(loc+2)/3][3]=1;
					loc=1;
				}
				else if(game[(loc+2)/3][loc%3]==0)
				{
					game[(loc+2)/3][loc%3]=1;
					loc=1;
				}
				else
				{
					cout<<"不能放在這個地方，請重新輸入"<<endl;
					loc=0;
				}
			}
			else
			{
				if(game[1][loc]==0)
				{
					game[1][loc]=1;
					loc=1;
				}
				else
				{
					cout<<"不能放在這個地方，請重新輸入"<<endl;
					loc=0;
				}
			}
		}
		loc=0;

		for(i=1;i<=3;i++)
		{
			for(j=1;j<=3;j++)
			{
				if(game[i][j]==0)
					cout<<"    ";
				else if(game[i][j]==1 && a==1)
						cout<<" ○ ";
				else if(game[i][j]==1 && a==2)
						cout<<" ╳ ";
				else if(game[i][j]==2 && b==1)
						cout<<" ○ ";
				else
						cout<<" ╳ ";
				if(j!=3)
					cout<<"|";
			}
			cout<<endl;
			if(i*j!=9)
				cout<<"--------------"<<endl;
			else
				cout<<endl;
		}

		for(i=1;i<=3;i++)
		{
			if(game[i][1]==1 && game[i][2]==1 && game[i][2]==1)
				win=1;
		}
		for(i=1;i<=3;i++)
		{
			if(game[1][i]==1 && game[2][i]==1 && game[3][i]==1)
				win=1;
		}
		if(game[1][1]==1 && game[2][2]==1 && game[3][3]==1)
			win=1;
		if(game[1][3]==1 && game[2][2]==1 && game[3][1]==1)
			win=1;

		if(win!=1)
		{
			while(loc==0)
			{
				cout<<"玩家B要放在哪:";
				cin>>loc;
				if(loc<1 || loc>9)
				{
					cout<<"請輸入1~9的數字"<<endl;
					loc=0;
				}
				else if(loc>3)
				{
					if(loc%3==0)
					{
						game[(loc+2)/3][3]=1;
						loc=1;
					}
					else if(game[(loc+2)/3][loc%3]==0)
					{
						game[(loc+2)/3][loc%3]=2;
						loc=2;
					}
					else
					{
						cout<<"不能放在這個地方，請重新輸入"<<endl;
						loc=0;
					}
				}
				else
				{
					if(game[1][loc]==0)
					{
						game[1][loc]=2;
						loc=2;
					}
					else
					{
						cout<<"不能放在這個地方，請重新輸入"<<endl;
						loc=0;
					}
				}	
			}
			loc=0;

			for(i=1;i<=3;i++)
			{
				for(j=1;j<=3;j++)
				{
					if(game[i][j]==0)
						cout<<"    ";
					else
					{
						if(game[i][j]==1 && a==1)
							cout<<" ○ ";
						else if(game[i][j]==1 && a==2)
							cout<<" ╳ ";
						else if(game[i][j]==2 && b==1)
							cout<<" ○ ";
						else
							cout<<" ╳ ";
					}
					if(j!=3)
						cout<<"|";
				}
				cout<<endl;
				if(i*j!=9)
					cout<<"--------------"<<endl;
				else
					cout<<endl;
			}

			for(i=1;i<=3;i++)
			{
				if(game[i][1]==2 && game[i][2]==2 && game[i][2]==2)
					win=2;
			}
			for(i=1;i<=3;i++)
			{
				if(game[1][i]==2 && game[2][i]==2 && game[3][i]==2)
					win=2;
			}
			if(game[1][1]==2 && game[2][2]==2 && game[3][3]==2)
				win=2;
			if(game[1][3]==2 && game[2][2]==2 && game[3][1]==2)
				win=2;
		}
	}

	if(win==1)
		cout<<"玩家A連線成功"<<endl;
	else
		cout<<"玩家B連線成功"<<endl;
}