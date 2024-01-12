#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std ;

class Direction { 
	public : 
	char k ;
	int ucome = 0 ;
	int dcome = 0 ;
	int lcome = 0 ;
	int rcome = 0 ;
};
class test{
    public:
      	int N = 0 ;
	    int N2 = 0 ;
	    int method = 0 ;
	    int quit = 0 ;
	    int i = 0 ;
     	int j = 0 ;
    	int a = 0 ;
    	int b = 0 ;
    	int c = 0 ;
    	int c2 = 0 ;
    	int d = 0 ;
    	int d2 = 0 ;
    void mission(string fileName, int N ){     	
      	FILE *infile = NULL; 		
	    fileName ="input"+fileName+".txt"; 
	    infile = fopen(fileName.c_str(),"r"); // 開啟資料夾
	    cout << fileName ;
	    fscanf(infile, "%d %d", &j, &i);	// 迷宮大小 
	    Direction matrix[i][j] ;    //順序:右下左上
	    if(infile == NULL)
	      cout<<endl<<fileName<<"does not exist!!"<<endl;
	    else {	          
	        for(c = 0 ; c < i ; c++) {
	    	    for(d = 0 ; d < j ; d++){
	    	        if(d == 1 && matrix[c][0].k == '\n'){
						d = 0 ;
					}
	    	        if ( fscanf(infile, "%c" , &matrix[c][d].k ) == -1 ){  // 迷宮比數字小 
                        cout << "Please try again!2";
	    	            return ;	
		        	}
	                if ( matrix[c][d].k != 'E'&& matrix[c][d].k != 'O'&& matrix[c][d].k != 'G' && matrix[c][d].k != '\n') {
	    	        	cout << "Please try again!3";
	    	        	return ;
					}	    	            
	    	        if(matrix[c][d].k == '\n' && d != 0){
	    	        	d--;
					}
				}
			}
			char k2 ;
			fscanf(infile, "%c" , &k2 ) ;
			if ( fscanf(infile, "%c" , &k2 ) != -1 ){  // 迷宮比數字大 
                cout << "Please try again!4";
	    	    return ;	
			}          
			for(c = 0 ; c < i  ; c++) {
    		    cout << "\n" ;
    	        for(d = 0 ; d < j ; d++) {
    		        cout << matrix[c][d].k ; // a為y座標, b為x座標 
                } // for
            } // for	
	        fclose(infile); // 關掉資料夾 
	        cout << "\n" ;
            while(N2 < N || matrix[a][b].k != 'G' ){
        	    if(matrix[a][b].k == 'G'){
        	    	for(c = 0 ; c < i ; c++) {
        	            for(d = 0 ; d < j ; d++) {
         	                if(matrix[c][d].k != 'G' && matrix[c][d].k != 'E') {
         	                    if(matrix[c][d].ucome != 10){
        	                        matrix[c][d].ucome = 0 ;
        	                    }
        	                    if(matrix[c][d].dcome != 10){
        	                        matrix[c][d].dcome = 0 ;
        	                    }
        	                    if(matrix[c][d].lcome != 10){
        	                        matrix[c][d].lcome = 0 ;
        	                    }
        	                    if(matrix[c][d].rcome != 10){
        	                        matrix[c][d].rcome = 0 ;
        	                    }
        	                }
        	            }  // for
                    } // for
                }
                if(matrix[a][b].k != 'G'){
        	    	matrix[a][b].k = 'V' ;
			    }
                if(b == j - 1 || matrix[a][b + 1].k == 'O'){
                    matrix[a][b].rcome = 10 ;	
			    }
			    if(a == i - 1 || matrix[a + 1][b].k == 'O'){
			    	matrix[a][b].dcome = 10 ;
			    }
		      	if(b == 0 || matrix[a][b - 1].k == 'O'){
				    matrix[a][b].lcome = 10 ;
			    }
			    if(a == 0 || matrix[a - 1][b].k == 'O'){
				    matrix[a][b].ucome = 10 ;
			    }
			    if(matrix[a][b].rcome + matrix[a][b].dcome + matrix[a][b].lcome + matrix[a][b].ucome >= 30 && matrix[a][b].k != 'G'){
				    while(matrix[a][b].rcome + matrix[a][b].dcome + matrix[a][b].lcome + matrix[a][b].ucome >= 30 && matrix[a][b].k != 'G'){
				    	matrix[a][b].k = 'E' ;
					    if (a != 0 && matrix[a - 1][b].k != 'O' && matrix[a - 1][b].dcome < 2) {
    	                    matrix[a][b].ucome++ ;
    	                    a-- ;
    	                    matrix[a][b].dcome = 10 ;
    	                }
    	                else if (b != 0 && matrix[a][b - 1].k != 'O' && matrix[a][b - 1].rcome < 2) {
    	                    matrix[a][b].lcome++ ;
    	                    b-- ; 
    	                    matrix[a][b].rcome = 10 ;	
    	                }
    	                else if (a != i - 1 && matrix[a + 1][b].k != 'O' && matrix[a + 1][b].ucome < 2) {
    	           	        matrix[a][b].dcome++ ;
    	           	        a++ ;
    	           	        matrix[a][b].ucome = 10 ;
    	                }
    	                else if (b != j - 1 && matrix[a][b + 1].k != 'O' && matrix[a][b + 1].lcome < 2) {
    	       		        matrix[a][b].rcome++ ;
    	       		        b++ ;
    	       		        matrix[a][b].lcome = 10 ;
    	                }
				    }
			    }
			    else if(b != j - 1 && matrix[a][b + 1].k == 'G' && matrix[a][b + 1].rcome + matrix[a][b + 1].dcome + matrix[a][b + 1].lcome + matrix[a][b + 1].ucome == 0){
				    matrix[a][b].rcome++ ;
    	    	    b++ ;
    	    	    matrix[a][b].lcome++ ;
			    }
			    else if(a != i - 1 && matrix[a + 1][b].k == 'G' && matrix[a + 1][b].rcome + matrix[a + 1][b].dcome + matrix[a + 1][b].lcome + matrix[a + 1][b].ucome == 0){
				    matrix[a][b].dcome++ ;
    	            a++ ;
    	            matrix[a][b].ucome++ ;
			    }
			    else if(b != 0 && matrix[a][b - 1].k == 'G' && matrix[a][b - 1].rcome + matrix[a][b - 1].dcome + matrix[a][b - 1].lcome + matrix[a][b - 1].ucome == 0){
				    matrix[a][b].lcome++ ;
            	    b-- ; 
    	       	    matrix[a][b].rcome++ ;
			    }
			    else if(a != 0 && matrix[a - 1][b].k == 'G' && matrix[a - 1][b].rcome + matrix[a - 1][b].dcome + matrix[a - 1][b].lcome + matrix[a - 1][b].ucome == 0){
				    matrix[a][b].ucome++ ;
            	    a-- ;
             	    matrix[a][b].dcome++ ;
			    }
		    	else if(b != j - 1 && matrix[a][b + 1].k != 'O' && matrix[a][b + 1].rcome + matrix[a][b + 1].dcome + matrix[a][b + 1].lcome + matrix[a][b + 1].ucome == 0){
				    matrix[a][b].rcome++ ;
    	    	    b++ ;
    	    	    matrix[a][b].lcome++ ;
			    }
			    else if(a != i - 1 && matrix[a + 1][b].k != 'O' && matrix[a + 1][b].rcome + matrix[a + 1][b].dcome + matrix[a + 1][b].lcome + matrix[a + 1][b].ucome == 0){
				    matrix[a][b].dcome++ ;
    	            a++ ;
    	            matrix[a][b].ucome++ ;
			    }
			    else if( b != 0 && matrix[a][b - 1].k != 'O' && matrix[a][b - 1].rcome + matrix[a][b - 1].dcome + matrix[a][b - 1].lcome + matrix[a][b - 1].ucome == 0){
				    matrix[a][b].lcome++ ;
            	    b-- ; 
    	       	    matrix[a][b].rcome++ ;
			    }
			    else if(a != 0 && matrix[a - 1][b].k != 'O' && matrix[a - 1][b].rcome + matrix[a - 1][b].dcome + matrix[a - 1][b].lcome + matrix[a - 1][b].ucome == 0){
				    matrix[a][b].ucome++ ;
                	a-- ;
             	    matrix[a][b].dcome++ ;
			    }
			    else if(b != j - 1 && matrix[a][b + 1].k != 'O' && (matrix[a][b + 1].rcome + matrix[a][b + 1].dcome + matrix[a][b + 1].lcome + matrix[a][b + 1].ucome) % 10 == 0){
				    matrix[a][b].rcome++ ;
    	    	    b++ ;
    	    	    matrix[a][b].lcome++ ;
			    }
			    else if(a != i - 1 && matrix[a + 1][b].k != 'O' && (matrix[a + 1][b].rcome + matrix[a + 1][b].dcome + matrix[a + 1][b].lcome + matrix[a + 1][b].ucome) % 10 == 0){
				    matrix[a][b].dcome++ ;
    	            a++ ;
    	            matrix[a][b].ucome++ ;
			    }
			    else if(b != 0 && matrix[a][b - 1].k != 'O' && (matrix[a][b - 1].rcome + matrix[a][b - 1].dcome + matrix[a][b - 1].lcome + matrix[a][b - 1].ucome) % 10 == 0){
				    matrix[a][b].lcome++ ;
                    b-- ; 
    	       	    matrix[a][b].rcome++ ;
			    }
			    else if(a != 0 && matrix[a - 1][b].k != 'O' && (matrix[a - 1][b].rcome + matrix[a - 1][b].dcome + matrix[a - 1][b].lcome + matrix[a - 1][b].ucome) % 10 == 0){
				    matrix[a][b].ucome++ ;
            	    a-- ;
                    matrix[a][b].dcome++ ;
			    }
    	        else if (b != j - 1 && matrix[a][b + 1].k != 'O' && matrix[a][b + 1].lcome < 2) {
    	       	    matrix[a][b].rcome++ ;
    	       	    b++ ;
    	       	    matrix[a][b].lcome++ ;
    	        }
    	        else if (a != i - 1 && matrix[a + 1][b].k != 'O' && matrix[a + 1][b].ucome < 2) {
    	            matrix[a][b].dcome++ ;
    	            a++ ;
    	            matrix[a][b].ucome++ ;
    	        }
    	        else if (b != 0 && matrix[a][b - 1].k != 'O' && matrix[a][b - 1].rcome < 2) {
    	            matrix[a][b].lcome++ ;
    	            b-- ; 
    	            matrix[a][b].rcome++ ;	
    	        }
    	        else if (a != 0 && matrix[a - 1][b].k != 'O' && matrix[a - 1][b].dcome < 2) {
    	            matrix[a][b].ucome++ ;
    	            a-- ;
    	            matrix[a][b].dcome++ ;
    	        }
    	        else {
    	        	cout << "Can't find G or N > amount of G\n" ;
    	            break ;
    		    }
    	    	if(matrix[a][b].k == 'G' && matrix[a][b].rcome + matrix[a][b].dcome + matrix[a][b].lcome + matrix[a][b].ucome == 1){
    			    N2++ ;
			    } 
	   	    }
	   	    matrix[0][0].k = 'V' ;
		    for(c = 0 ; c < i ; c++) {
    	        cout << "\n" ;
    	        for(d = 0 ; d < j ; d++) {
    	        	cout << matrix[c][d].k ; // a為y座標, b為x座標 
    	        } // for
    	    } // for
            if(matrix[a][b].k == 'G'){
    	        for(c2 = 0 ; c2 < i ; c2++) {
        	        for(d2 = 0 ; d2 < j ; d2++) {
					    if(matrix[c2][d2].k == 'G' && N2 > 0)	{
					        a = c2 ;
					        b = d2 ;
    	        	        for(c = 0 ; c < i ; c++) {
        	                    for(d = 0 ; d < j ; d++) {
         	                	    if(matrix[c][d].k == 'V' || matrix[c][d].k == 'G' || matrix[c][d].k == 'R') {
        	                		    matrix[c][d].ucome = 0 ;
        	                		    matrix[c][d].dcome = 0 ;
        	                    	    matrix[c][d].lcome = 0 ;
        	                		    matrix[c][d].rcome = 0 ;
        	                	    }  // if
        	                    } // for
                	        } // for
        	                while(a != 0 || b != 0) {
        	                    if(a != 0 && matrix[a - 1][b].k != 'O' && matrix[a - 1][b].rcome + matrix[a - 1][b].dcome + matrix[a - 1][b].lcome + matrix[a - 1][b].ucome == 0 && (matrix[a - 1][b].k == 'V' || matrix[a - 1][b].k == 'G' || matrix[a - 1][b].k == 'R')){
				                    matrix[a][b].ucome++ ;
            	                    a-- ;
             	                    matrix[a][b].dcome++ ;
				                }		
				                else if( b != 0 && matrix[a][b - 1].k != 'O' && matrix[a][b - 1].rcome + matrix[a][b - 1].dcome + matrix[a][b - 1].lcome + matrix[a][b - 1].ucome == 0 && (matrix[a][b - 1].k == 'V' || matrix[a][b - 1].k == 'G' || matrix[a][b - 1].k == 'R')){
				                    matrix[a][b].lcome++ ;
            	                    b-- ; 
    	       	                    matrix[a][b].rcome++ ;
				                }
				                else if(a != i - 1 && matrix[a + 1][b].k != 'O' && matrix[a + 1][b].rcome + matrix[a + 1][b].dcome + matrix[a + 1][b].lcome + matrix[a + 1][b].ucome == 0 && (matrix[a + 1][b].k == 'V'|| matrix[a + 1][b].k == 'G' || matrix[a + 1][b].k == 'R')){
				                    matrix[a][b].dcome++ ;
    	                            a++ ;
    	                            matrix[a][b].ucome++ ;
				                }				                
							    else if(b != j - 1 && matrix[a][b + 1].k != 'O' && matrix[a][b + 1].rcome + matrix[a][b + 1].dcome + matrix[a][b + 1].lcome + matrix[a][b + 1].ucome == 0 && (matrix[a][b + 1].k == 'V' || matrix[a][b + 1].k == 'G' || matrix[a][b + 1].k == 'R')){
				                    matrix[a][b].rcome++ ;
    	    	                    b++ ;
    	    	                    matrix[a][b].lcome++ ;
			                    }
        	                    else if (a != 0 && matrix[a - 1][b].k != 'O' && matrix[a - 1][b].dcome < 2 && (matrix[a - 1][b].k == 'V' || matrix[a - 1][b].k == 'G' || matrix[a - 1][b].k == 'R')) {
    	                            matrix[a][b].ucome++ ;
    	                            a-- ;
    	                            matrix[a][b].dcome++ ;
    	                        }
    	                        else if (b != 0 && matrix[a][b - 1].k != 'O' && matrix[a][b - 1].rcome < 2 && (matrix[a][b - 1].k == 'V' || matrix[a][b - 1].k == 'G' || matrix[a][b - 1].k == 'R')) {
    	                            matrix[a][b].lcome++ ;
    	                            b-- ; 
    	                            matrix[a][b].rcome++ ; 
    	                        }
    	                        else if (a != i - 1 && matrix[a + 1][b].k != 'O' && matrix[a + 1][b].ucome < 2 && (matrix[a + 1][b].k == 'V'|| matrix[a + 1][b].k == 'G' || matrix[a + 1][b].k == 'R')) {
	                                matrix[a][b].dcome++ ;
    	           	                a++ ;
    	           	                matrix[a][b].ucome++ ;
	                            }
    	                        else if (b != j - 1 && matrix[a][b + 1].k != 'O' && matrix[a][b + 1].lcome < 2 && (matrix[a][b + 1].k == 'V' || matrix[a][b + 1].k == 'G' || matrix[a][b + 1].k == 'R')) {
    	                    	    matrix[a][b].rcome++ ;
    	       		                b++ ;
    	       		                matrix[a][b].lcome++ ;
    	                        }
    	                        else {
    	                            N2++ ;
    	                            break ;
							    }
    	                        if(matrix[a][b].k != 'G'){
    	                            matrix[a][b].k = 'R' ;
    	                        }
    	                    } 
    	                    cout << "\n" ;
						    N2-- ; 
    	                }
                    }
                }
                for(c = 0 ; c < i ; c++) {
        	        for(d = 0 ; d < j ; d++) {
         	            if(matrix[c][d].k == 'V') {
        	                matrix[c][d].k = 'E' ;
        	            }
        	        } // for
                } // for
                for(c = 0 ; c < i ; c++) {
    		        cout << "\n" ;
    	            for(d = 0 ; d < j ; d++) {
    		            cout << matrix[c][d].k ; // a為y座標, b為x座標 
                    } // for
                } // for
            }	
	    }  // else
    } // mission 
};

int main() {
	cout << "請注意不要按到空格\n";
	int N = 0 ;
	int N2 = 0 ;
	int method = 0 ;
	int quit = 0 ;
	int i = 0 ;
	int j = 0 ;
	int a = 0 ;
	int b = 0 ;
	int c = 0 ;
	int c2 = 0 ;
	int d = 0 ;
	int d2 = 0 ;
	string fileName;
	test atest;
	while(quit == 0){
		cin >> method ;
        cin >> fileName ;
    	if(method == 1){
    	    N = 1 ;
    	    atest.mission(fileName, N);
        } // if
        else if(method == 2) {
        	cin >> N ; 
			atest.mission(fileName, N); 
    	}
    	else{
          cout << "Please try again!1";
		}
    	cin >> quit ;
    } // while
}