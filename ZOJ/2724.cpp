#include<cstdio>
#include<queue>
#include<cstring>
#include<cstdlib>

using namespace std;

struct record{
	char cmd[100];
	int priority;

	bool operator < (const record &a) const{
		return a.priority < priority;
	}
};

int main(){
	char buf[100], *str, *tok;
	priority_queue<record> q;
	record r;

	while(fgets(buf, sizeof(buf), stdin) != NULL){
		if(!strcmp(buf, "GET\n")){
			if(q.size() == 0)
				printf("EMPTY QUEUE!\n");
			else{
				r = q.top();
				printf("%s\n", r.cmd);
				q.pop();
			}
		}
		else{
			str = buf;
			tok = strtok(str, " \n");
			tok = strtok(NULL, " \n");
			strcpy(r.cmd, tok);
			strcat(r.cmd, " ");
			tok = strtok(NULL, " \n");
			strcat(r.cmd, tok);
			tok = strtok(NULL, " \n");
			r.priority = atoi(tok);
			q.push(r);
		}
	}
	return 0;
}
