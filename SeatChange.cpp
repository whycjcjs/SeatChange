#include<iostream>
#include<fstream>
#include<cstdio>
#include<string>
using namespace std;

struct node{
	string name;
	int number=0;
};

struct node1{
    node name1[7][8];
    node name2[7][8];
}t;

bool gunmu(int i,int j){
	return i<6||(j>=2&&j<=5);
}

void chushihua(node a[][8]) {
    for (int i=0;i<7;i++){
        for (int j=0;j<8;j++){
            a[i][j]=node{};
        }
    }
}

void ff(node a[][8],node b[][8]) {
	for(int i=0;i<7;i++)
	{
		for(int j=0;j<8;j++)
		{
			if (!gunmu(i, j)) continue;
			if(j==0||j==1){
				b[i+1][j+2]=a[i][j];
			}
			else if(j==2||j==3){
				if(i==6){
					b[i-6][j+2]=a[i][j];
				}
				else{
					b[i+1][j+2]=a[i][j];	
				}
			}
			else if(j==4||j==5){
				if(i==5){
					b[i-5][j+2]=a[i][j];
				}
				else if(i==6){
					b[i-6][j-2]=a[i][j];
				}
				else{
					b[i+1][j+2]=a[i][j];
				}
			}
			else{
				if(i==5){
					b[i-5][j-6]=a[i][j];
				} 
				else{
					b[i+1][j-6]=a[i][j];
				}
			}
		}
	}	
	
}
int main(){
	int times;
	int tt=0;
	freopen("tt.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d",&times);
	int timesf=times;
	chushihua(t.name1);
	chushihua(t.name2);
	for(int i=0;i<7;i++){
		for(int j=0;j<8;j++){
			if(!gunmu(i,j)) continue;
			cin>>t.name1[i][j].name;
		}
	}
	
//	for(int i=0;i<7;i++){
//		for(int j=0;j<8;j++){
//			cout<<t.name1[i][j].name<<"  ";	
//		} 
//		cout<<endl;
//	}
	bool lunshu=true;
	while(times>0){
		if(lunshu){
			ff(t.name1,t.name2);
		}
		else{
			ff(t.name2,t.name1);
		}
		lunshu=!lunshu;
		times--;
	}
	cout<<endl;
	if(lunshu){
		for(int i=0;i<7;i++){
			for(int j=0;j<8;j++){
				printf("%s ",t.name1[i][j].name.c_str());
			} 
			printf("\n");
		}
	}
	else{
		for(int i=0;i<7;i++){
			for(int j=0;j<8;j++){
				printf("%s ",t.name2[i][j].name.c_str());
			} 
			printf("\n");
		}
	}
	
	return 0;
}
