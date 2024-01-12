#include<stdio.h>
#include<stdlib.h>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<time.h>
#include<cstring>
#include<string.h>
#include<fstream>
#include<math.h>
using namespace std ;
typedef char Str20[40] ;

struct info{
	int num = 0 ;
	int degree = 0 ;	
	int height = 1 ;
};

class sort{
	public :
		void minheap(vector<info> &sort, int j){ //最小堆積 
			j++ ;
			int i = 0 ;
			i = j / 2 ;
			info temp ;
			while(i != 0){ //一路往根比較 
				if(sort[j - 1].degree < sort[i - 1].degree){ //當子節點值比父節點小就交換 
					temp.num = sort[j - 1].num ;
					temp.degree = sort[j - 1].degree ;
					sort[j - 1].num = sort[i - 1].num ;
					sort[j - 1].degree = sort[i - 1].degree ;
					sort[i - 1].num = temp.num ;
					sort[i - 1].degree = temp.degree ;	
				}
				j = i ;
				i = i / 2 ;//上一個父節點 
			}
		}
		int cacu(vector<info> sort, int j){//計算此層的個數 
			int num = 1 ;
			while(j != 0 && sort[j].height == sort[j - 1].height){
				num++ ;
				j-- ;
			}
			return num ;
		}
		void minmaxheap(vector<info> &sort, int j){//最小最大堆積 
			j++ ;
			int i = 0 ;
			i = j / 2 ;
			info temp ;
			while(i != 0){ //一路往根比較 
				if(sort[j - 1].height % 2 == 1 && sort[i - 1].height % 2 == 0){ //當父節點在偶數層時(偶數層為最大堆積層) 
					if(sort[j - 1].degree > sort[i - 1].degree){ //當子節點比父節點大就交換 
						temp.num = sort[j - 1].num ;
						temp.degree = sort[j - 1].degree ;
						sort[j - 1].num = sort[i - 1].num ;
						sort[j - 1].degree = sort[i - 1].degree ;
						sort[i - 1].num = temp.num ;
						sort[i - 1].degree = temp.degree ;	
						j = i ;
					}
				}
				else if(sort[j - 1].height % 2 == 0 && sort[i - 1].height % 2 == 1){ //當父節點在奇數層時(奇數層為最小堆積層) 
					if(sort[j - 1].degree < sort[i - 1].degree){ //當子節點比父節點小就交換 
						temp.num = sort[j - 1].num ;
						temp.degree = sort[j - 1].degree ;
						sort[j - 1].num = sort[i - 1].num ;
						sort[j - 1].degree = sort[i - 1].degree ;
						sort[i - 1].num = temp.num ;
						sort[i - 1].degree = temp.degree ;
						j = i ;	
					}
				}
				else if(sort[j - 1].height % 2 == 0 && sort[i - 1].height % 2 == 0){  //最大堆積層與最大堆積層間比較 
					if(sort[j - 1].degree > sort[i - 1].degree){ //當子節點比父節點大就交換  
						temp.num = sort[j - 1].num ;
						temp.degree = sort[j - 1].degree ;
						sort[j - 1].num = sort[i - 1].num ;
						sort[j - 1].degree = sort[i - 1].degree ;
						sort[i - 1].num = temp.num ;
						sort[i - 1].degree = temp.degree ;
						j = i ;
						i = i / 2 ;	//第一輪以後的比較都是與上上層的父節點比較 所以要多除以2一次 
					}
				}
				else if(sort[j - 1].height % 2 == 1 && sort[i - 1].height % 2 == 1){ //最小堆積層與最小堆積層間比較 
					if(sort[j - 1].degree < sort[i - 1].degree){ //當子節點比父節點小就交換  
						temp.num = sort[j - 1].num ;
						temp.degree = sort[j - 1].degree ;
						sort[j - 1].num = sort[i - 1].num ;
						sort[j - 1].degree = sort[i - 1].degree ;
						sort[i - 1].num = temp.num ;
						sort[i - 1].degree = temp.degree ;
						j = i ;
						i = i / 2 ;	//第一輪以後的比較都是與上上層的父節點比較 所以要多除以2一次 
					}
				}
				i = i / 2 ;
			}
		}
		void mission1(string fileName){
		vector<info> sort;
		int i = 0, k = 0, j = 0 ;
		char c ;
		Str20 useless = "" ;
		info work ;
		FILE *infile = NULL;
		FILE *outfile = NULL; 	
	    infile = fopen(("input"+fileName+".txt").c_str(),"r");
	    if ( infile == NULL)
			cout << fileName << "does not exist!"<< endl;
		else {  
			while(j < 3 ){        //前3行 
	        	fscanf(infile, "%c", &c) ;
	        	if ( c == '\n')
	        	    j++;
	        	 	        	
			}			
	    	while(fscanf(infile, "%c", &c) != -1){
	    		if(k == 7 && c == '\t'){ //只需要畢業人數 其他的都不要(跑過7個\t後下一個就是畢業人數) 
	    			fscanf(infile, "%s", useless) ;
	    			sort.push_back(work) ;
	    			sort[i].degree = atoi(useless) ;
	    			sort[i].num = i + 1 ;
	    			if(i != 0){
	    				sort[i].height = sort[i - 1].height ;
	    				if(cacu(sort, i) > pow(2, sort[i].height - 1)){ //如果當前這層擺滿了就要往下一層擺 
	    					sort[i].height++ ;
						}
					}
	    			minheap(sort, i) ;
	    			i++ ;
				}
				if(c == '\n'){
					k = 0 ;
				}
				if(c == '\t'){
					k++ ;
				}
			}
			i-- ;
			while(i != 0 && sort[i].height == sort[i - 1].height){
				i-- ;
			}
			cout << sort[0].num << "\t" << sort[0].degree << "\n" ; 
			cout << sort[sort.size() - 1].num << "\t" << sort[sort.size() - 1].degree << "\n" ;
			cout << sort[i].num << "\t" << sort[i].degree << "\n" ;
			for(i = 0 ; i < sort.size() ; i++){
				cout << sort[i].num << "\t" << sort[i].degree << "\t" << sort[i].height << "\n" ;
			}
		}
	}
	void mission2(string fileName){
		vector<info> sort;
		int i = 0, k = 0, j = 0 ;
		char c ;
		Str20 useless = "" ;
		info work ;
		FILE *infile = NULL;
		FILE *outfile = NULL; 	
	    infile = fopen(("input"+fileName+".txt").c_str(),"r");
	    if ( infile == NULL)
			cout << fileName << "does not exist!"<< endl;
		else {
			while(j < 3 ){        //前3行 
	        	fscanf(infile, "%c", &c) ;
	        	if ( c == '\n')
	        	    j++;
	        	 	        	
			}			
	    	while(fscanf(infile, "%c", &c) != -1){
	    		if(k == 7 && c == '\t'){
	    			fscanf(infile, "%s", useless) ;
	    			sort.push_back(work) ;
	    			sort[i].degree = atoi(useless) ;
	    			sort[i].num = i + 1 ;
	    			if(i != 0){
	    				sort[i].height = sort[i - 1].height ;
	    				if(cacu(sort, i) > pow(2, sort[i].height - 1)){
	    					sort[i].height++ ;
						}
					}
	    			minmaxheap(sort, i) ;
	    			i++ ;
				}
				if(c == '\n'){
					k = 0 ;
				}
				if(c == '\t'){
					k++ ;
				}
			}
			i-- ;
			while(i != 0 && sort[i].height == sort[i - 1].height){
				i-- ;
			}
			cout << sort[0].num << "\t" << sort[0].degree << "\n" ; 
			cout << sort[sort.size() - 1].num << "\t" << sort[sort.size() - 1].degree << "\n" ;
			cout << sort[i].num << "\t" << sort[i].degree << "\n" ;
		}
	}
};
int main(){
	sort a ;
	int m ;
	Str20 fileName = "" ;
	cout << "enter 0, 1, 2:" ;
	cin >> m ;
	while(m != 0){
		cin >> m ;
		if(m == 1){
			cout << "enter a file:" ;
			cin >> fileName ;
			a.mission1(fileName) ;
		}
		else if(m == 2){
			cout << "enter a file:" ;
			cin >> fileName ;
			a.mission2(fileName) ;
		}
		cout << "enter 0, 1, 2:" ;
	}
}