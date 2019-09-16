// 10727217 ����޳ 10727226 ��l�s 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
using namespace std;

unsigned long long times4(int i, unsigned long long number, unsigned long long &test, unsigned long long &num1, unsigned long long &num2, unsigned long long times1) {
	unsigned long long times3 = 1 ;
	if(number % test != 0 && times1 < 25000) {     // �C25000�O�@�� 
		test-- ;
		times3 = times3 + times4(i, number, test, num1, num2, times1 + 1) ;
	}
	else if(number % test == 0) {
		num1 = test ;
		num2 = number / test ;
	}
	return times3 ;
}
void InnerRecursion(int i, unsigned long long number, unsigned long long test, unsigned long long num1, unsigned long long num2, unsigned long long times1, unsigned long long k) {
	unsigned long long r = 0 ;
    if( k < 400 && number % test  != 0) {     
        r = times4(i, number, test, num1, num2, times1) ;
        if(r == 25001) {
            k++ ;
        }
        else if( r < 25001 && number % test == 0) {
		    num1 = test ;
		    num2 = number / test ;
		    cout << "[" << i << "]" << number <<  "=" <<  num1 << "*" << num2 <<  "(Inner recursion: " << k*25000 + r + 1 << " times)\n" ;
		}
	}
	else if(k >= 400 && number % test != 0 ){  //�W�L100000000�� 
		cout << "[" << i << "]" << number << " (Inner recursion: more than 10000000times)\n" ;
		return ;
	} 
	else if(number % test == 0){
		num1 = test ;
		num2 = number / test ;
		cout << "[" << i << "]" << number <<  "=" << num1 << "*" << num2 <<  "(Inner recursion: " << k*25000 + 1 << " times)\n" ;
    }
    if(number % test != 0) {
		InnerRecursion(i, number, test, num1, num2, times1, k) ;
	}
} // InnerRecursion()
void OuterRecursion(int max, int i, unsigned long long first, unsigned long long second, unsigned long long times2) {
	unsigned long long number = 0 ;
    number = first + second ;
	if(i <= max) {
		InnerRecursion(i, number, sqrt(number), 1, number, 0, 0) ;
		OuterRecursion(max, i + 1, second, number, times2 + 1) ;
	} // if
	else {
		printf("<Outer recursion: %dtimes>\n", times2) ;
	} // else
} // OuterRecursion()
int main() {
	int quit = 0 ;
	int method = 0 ; // �O�j���ٻ��j 
	int max = 0 ; //�O���ƦC������ 
	unsigned long long test = 0 ; //c���p�ƾ� 
    unsigned long long first = 0 ;
    unsigned long long second = 1 ;
    unsigned long long number = 0 ;
    unsigned long long num1 = 0 ;
    unsigned long long num2 = 0 ;
    unsigned long long times1 = 0 ;
    unsigned long long times2 = 0 ; 
	printf("please enter 0 or 1 to choose whether you want to quit or not.\n") ;
	scanf("%d", &quit) ;
	while(quit == 0 || quit != 1) {	
	    if(quit == 0) {
	    	printf("please enter the range of F series you want.\n") ;
    	    scanf("%d",&max) ;
        	if( max <= 0 || max > 92) {
                printf("out of range or input is not a digit.\n") ;
                printf("please enter 0 or 1 to choose whether you want to quit or not.\n") ;
                scanf("%d", &quit) ;
            	continue ;
            } // if
            printf("then choose the method you want to use.(1, 2)\n") ;
            scanf("%d", &method) ;
        	if(method == 1) {
        		first = 0 ;
        		second = 1 ;
        		number = 0 ;
        		times2 = 0 ;
        	    int i = 1 ;  //max���p�ƾ� 
            	while(  i <= max ) {
            		number = first + second ;
            		num1 = 1 ;
            		num2 = number ;
            		for(test = sqrt(number) ; number % test != 0 ; test--){ // j�t�d�q1��c�@�Ӥ@�ӧ�X�]��, d�Pf�t�d�s���t�ȳ̤p���@�զ]�� 
	            		times1++ ;
	            	} // for
	            	num1 = test ;
	            	num2 = number / test ;
	            	cout << "[" << i << "]" << number << " = " << num1 << "*" << num2 << "(Inner loop: " << times1 + 1 << " times)\n" ;
	            	first = second ;
	            	second = number ;
	            	i++ ;
	            	times2++ ;
	            	times1 = 0 ;
    	        } // while
            	printf("<Outer loop: %dtimes>\n", times2) ;
            } // if
            else if(method == 2) {
            	OuterRecursion(max, 1, 0, 1, 0) ;
        	} // else if
        	else {
        		printf("please enter 1 or 2, thanks.\n") ;
        	} // else
        	printf("please enter 0 or 1 to choose whether you want to quit or not.\n") ;
        } // if
        else if(quit != 1){
        	printf("please enter 0 or 1.\n") ;
		} // else if
		scanf("%d", &quit) ;
    } // while
    printf("thanks for using.\n") ;
} // main()
