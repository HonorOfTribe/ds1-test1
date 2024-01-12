#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;


class Token{
	public:
		string token = "\0";
		Token *next ;
};
bool isdigit(char c){
    if(c - '0' >= 0 && c - '0' <= 9){
		return true ;
	}
	else{
		return false ;
	}
}
bool strisdigit(string token){
	char j[] ="\0" ;
	strcpy(j, token.c_str()) ;
	int i = 0 ;
	for( i = 0 ; i < strlen(j) ; i++ ){
		if(isdigit(j[i]) != true){
			return false ;
		}
	}
	return true ;
}
bool isoperator(string token){
	if(token == "+" || token == "-" || token == "*" || token == "/"){
		return true ;
	}
	else{
		return false ;
	}
}
bool error1(Token *head, Token *tail){
	Token *temp = head ;
	for(temp = head ; temp != NULL ; temp = temp -> next){
		if(strisdigit(temp -> token) != true && isoperator(temp -> token) != true && temp -> token != "(" && temp -> token != ")"){
			cout << "Error1 : " << temp -> token << " is not a legitimate character.\n" ;
			return true ;
		}
	}
}
bool error2(Token *head, Token *tail){
	Token *temp = head ;
	int open = 0 ;
    int close = 0 ;
	for(temp = head ; temp != NULL ; temp = temp -> next){
		if(temp -> token == "("){
			open++ ;
		}
		else if(temp -> token == ")"){
			close++ ;
			if(close > open){
				cout << "Error2 : there is " << close - open << " extra close parenthesis.\n" ;
		        return true ;
			}
		}
	} 
	if(open > close){
		cout << "Error2 : there is " << open - close << " extra open parenthesis.\n" ;
		return true ;
	}
	else if(close > open){
		cout << "Error2 : there is " << close - open << " extra close parenthesis.\n" ;
		return true ;
	}
	return false ;
	
}
bool error3(Token *head, Token *tail){
	Token *temp = head ;
	int extraoperand = 0 ;
	int extraoperator = 0 ;
	for(temp = head ; temp != NULL ; temp = temp -> next){
		if(isoperator(temp -> token) == true && (temp == head || temp == tail)){
	    	extraoperator++ ;
	    }
	    else if(temp != tail && isoperator(temp -> token) == true && isoperator(temp -> next -> token) == true){
	    	extraoperator++ ;
		}
		else if(temp != tail && strisdigit(temp -> token) == true && temp -> next -> token == "("){
			extraoperand++ ;
		}
		else if(temp != tail && isoperator(temp -> token) == true && temp -> next -> token == ")"){
			extraoperator++ ;
		}
		else if(temp != tail && temp -> token == ")" && strisdigit(temp -> next -> token) == true){
			extraoperand++ ;
		}
		else if(temp != tail && temp -> token == "(" && (isoperator(temp -> next -> token) == true || temp -> next -> token == ")")){
			cout << "Error 3: it is not infix in the parentheses.\n" ;
			return true ;
		}
	}
	if(extraoperand != 0){
		cout << "Error3 : there is " << extraoperand << " extra operand.\n" ;
		return true ;
	}
	if(extraoperator != 0){
		cout << "Error3 : there is " << extraoperator << " extra operator.\n" ;
		return true ;
	}
	else{
		return false ;
	}
}
void input(Token *&head, Token *&tail){
	char c ;
	Token *temp = NULL ;
	temp = new Token ;
	head = temp ;
	scanf("%c", &c) ;
	scanf("%c", &c) ;
	while(c != '\n') {
		if(temp -> token.length() == 0 && c != '\n' && c != ' '){
	    	temp -> token = temp -> token + c ;
	    	if(isdigit(c) == false){
	    	    temp -> next = new Token ;
	        	temp = temp -> next ;
	        }
					
	    }
	    else if(temp -> token.length() >= 1 && isdigit(c) == true && strisdigit(temp -> token) == true && c != '\n' && c != ' '){
		    temp -> token = temp -> token + c ;
    	}
    	else if(temp -> token.length() >= 1 && isdigit(c) == false && c != '\n' && c != ' '){
    		temp -> next = new Token ;
	    	temp = temp -> next ;
	    	temp -> token = temp -> token + c ;
	    	temp -> next = new Token ;
	    	temp = temp -> next ;
					
	    }
	    scanf("%c", &c) ;
    }
    if(temp -> token == "\0"){
	    for(temp = head ; temp -> next -> token != "\0" ; temp = temp -> next){
    	}
    	delete temp -> next ;
    }
	tail = temp ;
	tail -> next = NULL ;
}
bool mission1(Token *head, Token *tail){
	int numoferror = 0 ;
	if(error1(head, tail) == true){
		numoferror++ ;
	}
	else if(error2(head, tail) == true){
		numoferror++ ;
	}
	else if(error3(head, tail) == true){
		numoferror++ ;
	}
	if(numoferror == 0){
		cout << "It is a legitimate infix expression.\n" ;
		return true ;
	}
	else{
		return false ;
	}
}
string pop(Token *head, Token *&tail){
	Token *temp = head ;
	string i ;
	if(head -> next == NULL){
		i = head -> token ;
		head -> token = "\0" ;
	}
	else{
	    for(temp = head ; temp -> next != tail ; temp = temp -> next){
	    }
	    tail = temp ;
	    temp = temp -> next ;
      	i = temp -> token ;
	    delete temp ;
	    tail -> next = NULL ;
	}
	return i ;
	
}
void push(string token, Token *&tail){
	if(tail -> token == "\0"){
		tail -> token = token ;
	}
	else{
	    tail -> next = new Token ;
	    tail = tail -> next ;
	    tail -> token = token ;
	    tail -> next = NULL ;
	}
}
string gettoken(Token *&head){
	Token *temp = head ;
	string i = head -> token ;
	if(head -> next != NULL){
		head = head -> next ;
    	temp -> next = NULL ;
    	delete temp ;
	} 
	return i ;  
}
void mission2(Token *&head, Token *&tail){
	Token *head2 = new Token ;
	Token *temp = head ;
	Token *tail2 = head2 ;
	tail2 -> next = NULL ;
	Token *temp2 = head ;	
	if(head -> next != NULL){
		tail -> next = new Token ;
		tail = tail -> next ;
    	temp2 = tail ;
	}
	while(head != temp2){
		if(strisdigit(head -> token) == true){
			push(gettoken(head), tail) ;
		}
		else if(head -> token == "("){
		    push(gettoken(head), tail2) ;
		}
		else if(isoperator(head -> token)){
			if(tail2 -> token == "*" || tail2 -> token == "/"){
			    while(head2 -> token != "\0"){
					if(tail2 -> token =="("){
						break ;
					}
					else{
						push(pop(head2, tail2), tail) ;
					}
				}
				push(gettoken(head), tail2) ;
			}
			else if(tail2 -> token == "+" || tail2 -> token == "-"){
				if(head -> token == "+" || head -> token == "-"){
					while(head2 -> token != "\0"){
						if(tail2 -> token =="("){
							break ;
						}
						else{
							push(pop(head2, tail2), tail) ;
						}
					}
					push(gettoken(head), tail2) ;
				}
				else if(head -> token == "*" || head -> token == "/"){
					push(gettoken(head), tail2) ;
				}
			}
			else{
				push(gettoken(head), tail2) ;
			}
		}
		else if(head -> token == ")"){
			while(tail2 -> token != "("){
				push(pop(head2, tail2), tail) ;
			}
			pop(head2, tail2) ;
			gettoken(head) ;
		}
	}
	while(head2 -> token != "\0"){
		push(pop(head2, tail2), tail) ;
	}
	for(temp = head ; temp != NULL ; temp = temp -> next){
		cout << temp -> token ;
		if(temp != tail){
			cout << "," ;
		}
	}
	cout << "\n" ;
}

int main(){
	Token *head = NULL ;
	Token *tail = NULL ;
	Token *temp = NULL ;
	bool j = false ;
    int quit = 0 ;
    int m = 0 ;
    while(quit != 1){
    	cout << "please enter 1 or 2 to choose mission.\n" ;
        cin >> m ;
        input(head, tail) ;
    	temp = head ;
    	if(m == 1 || m == 2){
    		j = mission1(head, tail) ;
    	}
	    if(m == 2 && j == true){
	        mission2(head, tail) ;
		}
		else if(m != 1 && m != 2){
			cout << "Error! please enter 1 or 2.\n" ;
		}
		cout << "quit? (0(y) or 1(n))\n" ;
		cin >> quit ;
		while(quit != 1 && quit != 0){
			cout << "Error! please enter 0 or 1.\n" ;
			cout << "quit? (0(n) or 1(y))\n" ;
			cin >> quit ;
		}
    }
}