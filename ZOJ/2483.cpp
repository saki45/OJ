#include<cstdio>
#include<stack>
#include<cstring>

using namespace std;

char exp[300];

char calculate(){
	stack<char> st;
	char *e = exp;
	while(*e){
		if(*e=='F' || *e=='V'){
			st.push(*e);
		}
		else if(*e == '!'){
			char tmp = st.top();
			st.pop();
			if(tmp == 'F'){
				st.push('V');
			}
			else{
				st.push('F');
			}
		}
		else{
			char op1 = st.top();
			st.pop();
			char op2 = st.top();
			st.pop();
			if(*e == '&'){
				if(op1=='V' && op2=='V'){
					st.push('V');
				}
				else{
					st.push('F');
				}
			}
			else{
				if(op1=='F' && op2=='F'){
					st.push('F');
				}
				else{
					st.push('V');
				}
			}
		}
		e++;
	}
	return st.top();
}

char process(char buf[]){
	char *s = buf, *e = exp;
	memset(exp, 0, sizeof(exp));
	stack<char> st;
	while(*s != '\n'){
		if(*s == ' '){
			;
		}
		else if(*s=='F' || *s=='V'){
			*e = *s;
			e++;
		}
		else if(*s=='&' || *s=='|'){
			while(st.size()>0 && st.top()!='('){
				char op = st.top();
				*e = op;
				e++;
				st.pop();
			}
			st.push(*s);
		}
		else if(*s=='!'){
			st.push(*s);
		}
		else if(*s=='('){
			st.push('(');
		}
		else if(*s==')'){
			while(st.top()!='('){
				*e = st.top();
				e++;
				st.pop();
			}
			st.pop();
		}
		s++;
	}
	while(st.size()>0){
		*e = st.top();
		e++;
		st.pop();
	}
	return calculate();
}

int main(){
	char buf[200];
	int count = 1;
	while(fgets(buf, sizeof(buf), stdin)){
		char res = process(buf);
		printf("Expression %d: %c\n", count, res);
		count++;
	}
	
	return 0;
}
