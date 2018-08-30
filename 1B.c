#include<stdio.h>
#include<string.h>

int is_alpha(char s){
	if(s>='A'&&s<='Z')
		return 1;
	return 0;
}

void print(char *s){
	int if_rc=0;
	char r,c;
	while(is_alpha(*s)){

	}

	int num=0;
	while(!is_alpha(*(s))){
		num=num*10+(*s-'0')
		s++;
	}
	if(rc==1)
		printf("%d",num);


}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		char *s;
		scanf("%s",s);
		print(s);
		// printf("%s",print(s));
}
	return 0;
}
