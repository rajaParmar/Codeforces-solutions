#include<stdio.h>

int cal_trail_zero(long int x){
	int count=0;

	while(1){
		if(x%10==0){
			count++;
			x/=10;
			if(x==0)
				break;
		}
		else break;
	}
	return count;
}

void print_path(char dir[][100]){
	//char temp=dir[0][0];
	int i=0,j=0;
	while(dir[i][j]!='\0'){
		printf("%c",dir[i][j]);
		if(dir[i][j]=='R')
			j++;
		else i++;

	}
}
long int LR(int x,int y,long int val[][100],char dir[][100],long int in[][100],int n){
	if(x==n-1&&y==n-1){

		val[x][y]=in[x][y];
		dir[x][y]='\0';
		// printf("%d",val[x][y]);
		return in[n-1][n-1];
	}
	if(val[x][y]!=-1){
			return val[x][y];
	}
		long int r,d,fd=0,fr=0;
		if(y+1<n){
			r=LR(x,y+1,val,dir,in,n);
			fr=1;
		}
		if(x+1<n){
			d=LR(x+1,y,val,dir,in,n);
			fd=1;
		}
		if(fd){
			if(fr){
				// printf("\n %d %d",x,y);
				if(cal_trail_zero(d*in[x][y])<cal_trail_zero(r*in[x][y]))
				{	
					
					val[x][y]=d*in[x][y];
					dir[x][y]='D';
					return val[x][y];
				}
				else{
					
					val[x][y]=r*in[x][y];
					dir[x][y]='R';
					
					return val[x][y];
				}
			}
			else{
				
					val[x][y]=d*in[x][y];
					dir[x][y]='D';
					return val[x][y];	
			}
		}
		if(fr){
					val[x][y]=r*in[x][y];
					dir[x][y]='R';
					
					return val[x][y];
		}
		

}



int main() {
	int n=0;
	 long int val[100][100];
	char dir[100][100];
	 long int in[100][100];
	scanf("%d",&n);
	int i=0,j=0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%ld",&in[i][j]);
			val[i][j]=-1;
			
			dir[i][j]='0';
		}
	}

	printf("%d\n",cal_trail_zero(LR(0,0,val,dir,in,n)));
	print_path(dir);
	

	
	
	printf("\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%ld ",val[i][j]);
		}
		printf("\n");
	}
		return 0;
	
}


