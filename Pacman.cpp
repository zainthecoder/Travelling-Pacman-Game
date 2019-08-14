#include <bits/stdc++.h>
#include "rtutils.h"
#include <conio.h>
#include <fstream>
#include "windows.h"
#include <unistd.h>
#define INT_MAX 999999
using namespace std;

void display(int);
int score=0;

     int n;
     char name[100][200];
     int dist[30][30];


void AdjMat(int dist[30][30],char name[100][200],int n){

	for(int i=0;i<30;++i){
		for(int j=0;j<60;++j){
			//now we have a element of the game and we will find the distance of element from the other element
			if(name[i][j]!='.'){
				for(int p=0;p<30;++p){
					for(int q=0;q<60;++q){
						if(name[p][q]!='.'){
							int src=name[i][j]-65;
							int dest=name[p][q]-65;
							dist[src][dest]=(abs(i-p)+abs(j-q));

						}
					}
				}


			}
		}
	}


}

void gameMap(int n){

	for(int i=0;i<30;++i){
		for(int j=0;j<60;++j){
			name[i][j]='.';
		}
	}
	int a,b;
	char x='A';
	for(int i=0;i<(n*3);++i){
        a=rand()%30+2;
		b=rand()%60+2;

		if(name[a][b]=='.'){
		name[a][b]=x;
		x=x+1;

	   }
	   else{
	   	i--;
	   }
	}

}



int VISITED_ALL;

int dp[10000][30];



int  tsp(int mask,int pos){

	cout<<mask<<"\n";

	if(mask==VISITED_ALL){
		return dist[pos][0];
	}
	if(dp[mask][pos]!=-1){
	   return dp[mask][pos];
	}

	//Now from current node, we will try to go to every other node and take the min ans
	int ans = INT_MAX;
    int u=3*n;
	//Visit all the unvisited cities and take the best route
	for(int city=0;city<u;city++){

		if((mask&(1<<city))==0){

			int newAns = dist[pos][city] + tsp( mask|(1<<city), city);
			ans = min(ans, newAns);
		}

	}

	return dp[mask][pos] = ans;
}

bool isvalid(int x,int y,int &mask,int &counter,int &isDot)
{



	if(name[x][y]==20){
		return false;
	}
	if(name[x][y]!='.'){
		if(counter==0){
			//this is the first node
			name[x][y]=20;
			score=0;
			int u=name[x][y]-65;
			mask=mask<<(u);
			counter++;
			return true;

	  }
		else{
			//this is a node in between
			name[x][y]=156;
			counter++;
			int u=name[x][y]-65;
			mask=mask<<u;

			return true;
		}
	}
	if(name[x][y]=='.'){

		isDot=1;
		name[x][y]='@';
		return true;
	}
	return true;

}

int main()
{

	
	cout<<"                        Welcome                 \n";
	cout<<"                Travelling Pacman Game           ";

	cout<<"\n"<<"       Instructions";
	cout<<"1.There are N cities in the game.\n2.The player have to visit every city in least steps\n3.The player can move in 4 direction: up, Down, Left, and Right";
	cout<<"\n\n\nEnter the Level :";
    cin>>n;
    

int x=0;int y=0;
    gameMap(n);
    cout<<"\nGAME MAP\n\n";
	for(int i=0;i<30;i++){
		for(int j=0;j<60;++j){
			cout<<name[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
	AdjMat(dist,name,n);
int u=(3*n);

cout<<"\nthe adjaceny matrix of the cities:\n\n";
for(int i=0;i<u;++i){
	for(int j=0;j<u;++j){
		cout<<dist[i][j]<<" ";
	}
	cout<<endl;
}
cout<<endl;


//cout<<"u:"<<u<<endl;
 VISITED_ALL = (1<<u) -1;
//cout<<"\nvisited all"<<VISITED_ALL <<endl;


   for(int i=0;i<(1<<u);i++){
        for(int j=0;j<u;j++){
            dp[i][j] = -1;        }
    }

    int minDist=tsp(1,0);
	cout<<"\nThe minimum number of steps required to cover all cities(Min cost Hamiltonian Cycle):  "<<minDist<<endl;

  

	  char input='p';
	  bool game=true;
	  int i=0;
	  int counter=0;
	  int mask=0;

cout<<VISITED_ALL;

	  while(game)
	  {
	  	flag:
	  	input=getch();


	  	switch(input)       //up
	  	{
       	       case 72:
			   	   while(1) {
			   	   	int isDot=0;
			   if(isvalid(x-1,y,mask,counter,isDot)){
			   x-=1;
			   score=score+1;
		//	   cout<<score;
			   display(score);

			Sleep(.01);
			   if(isDot)name[x][y]='.';
			   isDot=0;
			   system("clear");
			   if (kbhit())goto flag;
		}
		else
		{

		system("clear");
		cout<<"                     GAME OVER                 ";
		goto endd;



		display(score); Sleep(.01);
		 system("clear");
			   if (kbhit())goto flag;
		}
	}
			   break;

			  case 80:

			   while(1) {
        int isDot=0;
			   	if(isvalid(x+1,y,mask,counter,isDot)){
          	   x+=1;
          	   score=score+1;
          //	   cout<<score;
			   display(score);
			 Sleep(.01);
			   if(isDot)name[x][y]='.';
			   isDot=0;
			   system("clear");
			   if (kbhit())goto flag;
		}
	else
		{
		system("clear");

		cout<<"                     GAME OVER                 ";
		goto endd;


		display(score);Sleep(.01);
		system("clear");
			   if (kbhit())goto flag;
		}
	}
			  break;

				case 75:
			   while(1) {
			   	int isDot;
			   	if(isvalid(x,y-1,mask,counter,isDot)){
                y-=1;
                 score=score+1;
          	//   cout<<score;
			   display(score);
Sleep(.01);
			   if(isDot)name[x][y]='.';
			   isDot=0;
			   system("clear");
			   if (kbhit())goto flag;
		}
	else
		{


		system("clear");
		cout<<"                     GAME OVER                 ";
		goto endd;


		display(score);  Sleep(.01);
		system("clear");
			   if (kbhit())goto flag;
		}
	}
				  break;      //left

				case 77:
				while(1) {
					int isDot;
					if(isvalid(x,y+1,mask,counter,isDot)){

			   y+=1;
	 score=score+1;
          	  // cout<<score;
			   display(score);
			   Sleep(.01);
			   if(isDot)name[x][y]='.';
			   isDot=0;
			   system("clear");
			   if (kbhit())goto flag;
		}
	else
		{


		system("clear");
		cout<<"                     GAME OVER                 ";
		goto endd;


		display(score);  Sleep(.01);
		system("clear");
			   if (kbhit())goto flag;
		}
	}
		  break;     //right


		  }

      }

			endd:int s,c=0;
			vector<int>v;

				ofstream myfile("gamescore.txt",ios::app);
                myfile<<"Level: "<<n;
				myfile<<"   Score: "<<score;
				myfile<<"\n";
				myfile.close();

				cout<<endl<<endl<<"Score"<<endl;

				ifstream obj("gamescore.txt");
				while(obj>>s)
				{cout<<s<<endl;
				v.push_back(s);
				c++;
			}
			sort(v.begin(),v.end());
			cout<<"                                    Result\n\n";
			cout<<"\nThe Highest Score is: "<<v[c-1];
				cout<<"\n\nTravelling Saleman Distance is "<<minDist;
					cout<<"\n\nYour Step Count: "<<score<<endl;

				
   }


      void display(int score)
      {
      	cout<<"\nscore: "<<score<<endl;

      	system("color 2");
    for(int i=0;i<50;i++){
		for(int j=0;j<100;++j){
			cout<<name[i][j];
		}
		cout<<endl;
	}
	cout<<endl;


	  }


