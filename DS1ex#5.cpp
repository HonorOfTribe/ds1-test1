#include<stdio.h>
#include<stdlib.h>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<time.h>
#include<cstring>
#include<string.h>
#include<fstream>
using namespace std ;
struct school{
	string schoolcode ="";
	string schoolname="";
	string code2="";
	string name2="";
	string day="";
	string day2="";
	string rank="";
	string rank2="";
	string student="";
	string teacher="";
	string graduate="";
	string city="";
	string cityname="";
	string degree="";
	string degree2=""; //15
};
class sort{
	public:
	void mission1(string fileName){
		vector<school> sort;
		vector<school> sort2;
		school work ;
		int i = 0,j = 0, max = 0,num = 1;
	    school temp;
	    school temp2;
		char c;
		string b;
		clock_t start, end ;
		double test;
		FILE *infile = NULL;
		FILE *outfile = NULL; 
		FILE *outfile2 = NULL; 		
	    infile = fopen(("input"+fileName+".txt").c_str(),"r"); 
	    if ( infile == NULL)
			cout << fileName << "does not exist!"<< endl;
		else {
			while(j < 3 ){        //«e3¦æ 
	        	fscanf(infile, "%c", &c) ;
	        	if ( c == '\n')
	        	    j++;
	        	 	        	
			}			
			sort.push_back(work) ;			 
			
			while ( fscanf(infile, "%c", &c ) != -1 ){			
								
				while (c != ' '&& c!= '\t' )   {
					sort[i].schoolcode = sort[i].schoolcode + c;
					fscanf(infile, "%c", &c );					
			 	}			 					 			    			 	
			 	while ( c == '\t' || c == ' ')
			 	  fscanf(infile, "%c", &c );
			 	
				while (c != ' '&& c!= '\t' )   {
					sort[i].schoolname = sort[i].schoolname + c;
					fscanf(infile, "%c", &c );
			 	}
	            
				while ( c == '\t' || c == ' ')
			 	  fscanf(infile, "%c", &c );
				
				while (c != ' '&& c!= '\t' )   {
					sort[i].code2 = sort[i].code2 + c;
					fscanf(infile, "%c", &c );
			 	}
			 	
				while ( c == '\t' || c == ' ')
			 	  fscanf(infile, "%c", &c );
				while (c != ' '&& c!= '\t' )   {
					sort[i].name2 = sort[i].name2 + c;
					fscanf(infile, "%c", &c );
			 	}
			 	
				while ( c == '\t' || c == ' ')
			 	  fscanf(infile, "%c", &c );
			 	  
			 	while (c != ' '&& c!= '\t' )   {
					sort[i].day = sort[i].day + c;
					fscanf(infile, "%c", &c );
			 	}
			 	while ( c == '\t' || c == ' ')
			 	  fscanf(infile, "%c", &c );
			 	  
			 	while (c != ' '&& c!= '\t' )   {
					sort[i].day2 = sort[i].day2 + c;
					fscanf(infile, "%c", &c );
			 	}
			 	while ( c == '\t' || c == ' ')
			 	  fscanf(infile, "%c", &c );
			 	while (c != ' '&& c!= '\t' )   {
					sort[i].rank = sort[i].rank + c;
					fscanf(infile, "%c", &c );
			 	}
			 	while ( c == '\t' || c == ' ')
			 	  fscanf(infile, "%c", &c );
			 	  
			 	while (c != ' '&& c!= '\t' )   {
					sort[i].rank2 = sort[i].rank2 + c;
					fscanf(infile, "%c", &c );
			 	}
			 	while ( c == '\t' || c == ' ')
			 	  fscanf(infile, "%c", &c );
			 	  
			 	while (c != ' '&& c!= '\t' )   {
					sort[i].student = sort[i].student + c;
					fscanf(infile, "%c", &c );
			 	}
			 	while ( c == '\t' || c == ' ')
			 	  fscanf(infile, "%c", &c );
			 	  
			 	while (c != ' '&& c!= '\t' )   {
					sort[i].teacher = sort[i].teacher + c;
					fscanf(infile, "%c", &c );
			 	}
			 	while ( c == '\t' || c == ' ')
			 	  fscanf(infile, "%c", &c );
			 	  
			 	while (c != ' '&& c!= '\t' )   {
					sort[i].graduate = sort[i].graduate + c;
					fscanf(infile, "%c", &c );
			 	}
			 	
			 	while ( c == '\t' || c == ' ')
			 	  fscanf(infile, "%c", &c );
			 	  
			 	while (c != ' '&& c!= '\t' )   {
					sort[i].city = sort[i].city + c;
					fscanf(infile, "%c", &c );
			 	}
			 	while ( c == '\t' || c == ' ')
			 	  fscanf(infile, "%c", &c );
			 	  
			 	while (c != ' '&& c!= '\t' )   {
					sort[i].cityname = sort[i].cityname + c;
					fscanf(infile, "%c", &c );
			 	}
			 	
			 	while ( c == '\t' || c == ' ')
			 	  fscanf(infile, "%c", &c );
			 	  
			 	while (c != ' '&& c!= '\t' )   {
				    sort[i].degree = sort[i].degree + c;
					fscanf(infile, "%c", &c );
			 	}	
													 			 	
			 	while ( c == '\t' || c == ' ')
			 		fscanf(infile, "%c", &c );	
					 		 				 	
			 	while (c != '\n' ) {
					sort[i].degree2 = sort[i].degree2+ c;		
					if ( fscanf(infile, "%c", &c ) == -1)
					  break;
			 	}							 	
				sort.push_back(work); 				 												
				i++;									
			}	
			
			for ( i = 0; i <sort.size() ; i++ ){        
			  sort2.push_back(work); 				
			  sort2[i].schoolcode=sort[i].schoolcode;
			  sort2[i].schoolname=sort[i].schoolname;
			  sort2[i].code2=sort[i].code2;
			  sort2[i].name2=sort[i].name2;
			  sort2[i].day=sort[i].day;
			  sort2[i].day2=sort[i].day2;
			  sort2[i].rank=sort[i].rank;
			  sort2[i].rank2=sort[i].rank2;
			  sort2[i].student=sort[i].student;
			  sort2[i].teacher=sort[i].teacher;
			  sort2[i].graduate=sort[i].graduate;
			  sort2[i].city=sort[i].city;
			  sort2[i].cityname=sort[i].cityname;
			  sort2[i].degree=sort[i].degree;
			  sort2[i].degree2=sort[i].degree2;			  
			  
			}
			 				  		
			start = clock() ;
			sort.pop_back();								
			for ( i = 0 ; i < sort.size() -1; i++) {      // ¿ï¾Ü±Æ§Ç 
				max = i;
				for ( j = i + 1 ; j < sort.size() ; j++ ) {
					int a = atoi(sort[j].graduate.c_str());
					int b = atoi(sort[max].graduate.c_str());
					if ( a > b )    // ¤ñ°_©lªº¤j 
					   max = j;
				}
				
				temp= sort[max];
				sort[max] = sort[i];
				sort[i] = temp;
				
			}  
			end = clock() ;			 	    				       			
		    test = ((double)(end - start)) ; 
			outfile = fopen(("select_sort" + fileName + ".txt").c_str(),"a");   
			i = 0;  
			while( i < sort.size() ){
				fprintf(outfile, "%s\t%s\t%s\t%s\t%s %s\t%s %s\t%s\t%s\t%s\t%s\t%s %s %s\n", sort[i].schoolcode.c_str(),  sort[i].schoolname.c_str(), sort[i].code2.c_str(), sort[i].name2.c_str(), sort[i].day.c_str(), sort[i].day2.c_str(), sort[i].rank.c_str(), 
				        sort[i].rank2.c_str(), sort[i].student.c_str(), sort[i].teacher.c_str(), sort[i].graduate.c_str(), sort[i].city.c_str(), sort[i].cityname.c_str(), sort[i].degree.c_str(), sort[i].degree2.c_str() );
				i++ ;
		    }
		    cout << "Selection sort:" << test << "ms"<< endl;
		    fclose(outfile);
	
		    
		    start = clock() ;
			bool sorted = false;
			for ( i = 0 ; i < sort2.size() && !sorted ; i++) {      // ªwªj±Æ§Ç 
				sorted = true;
				for ( j = 0 ; j < sort2.size() ; j++ ) {
					int a = atoi(sort2[j+1].graduate.c_str());
					int b = atoi(sort2[j].graduate.c_str());
					if ( a > b )  {  // ¤ñ°_©lªº¤j 
					   temp= sort2[j];
				       sort2[j] = sort2[j+1];
				       sort2[j+1] = temp;
					   sorted = false;
					}
					
				}								
				
			}  	
			end = clock() ;
			test = ((double)(end - start)) ;
			outfile2 = fopen(("bubble_sort" + fileName + ".txt").c_str(),"a");  
			i = 0;  
			while( i < sort2.size() ){
				fprintf(outfile2, "%s\t%s\t%s\t%s\t%s %s\t%s %s\t%s\t%s\t%s\t%s\t%s %s %s\n", sort2[i].schoolcode.c_str(),  sort2[i].schoolname.c_str(), sort2[i].code2.c_str(), sort2[i].name2.c_str(), sort2[i].day.c_str(), sort2[i].day2.c_str(), sort2[i].rank.c_str(), 
				        sort2[i].rank2.c_str(), sort2[i].student.c_str(), sort2[i].teacher.c_str(), sort2[i].graduate.c_str(), sort2[i].city.c_str(), sort2[i].cityname.c_str(), sort2[i].degree.c_str(), sort2[i].degree2.c_str() );
				i++ ;
		    }
			
			cout << "Bubble sort:" << test << "ms"<< endl;
			fclose(outfile2);
			return  ;
	    }
	}
	
	void mission2(string fileName){
		vector<school> sort;
		vector<school> sort2;
		school work ;
		int i = 0,j = 0, max = 0,num = 1;
		char c;
		clock_t start, end ;
		double test;
		FILE *infile = NULL;
		FILE *outfile = NULL; 
		FILE *outfile2 = NULL; 		
	    infile = fopen(("input"+fileName+".txt").c_str(),"r"); 
	    if ( infile == NULL)
			cout << fileName << "does not exist!"<< endl;
		else {
			while(j < 3 ){        //«e3¦æ 
	        	fscanf(infile, "%c", &c) ;
	        	if ( c == '\n')
	        	    j++;	        	 	        	
			}
			sort.push_back(work) ;			 			
			while ( fscanf(infile, "%c", &c ) != -1 ){			
								
				while (c != ' '&& c!= '\t' )   {
					sort[i].schoolcode = sort[i].schoolcode + c;
					fscanf(infile, "%c", &c );					
			 	}			 					 			    			 	
			 	while ( c == '\t' || c == ' ')
			 	  fscanf(infile, "%c", &c );
			 	
				while (c != ' '&& c!= '\t' )   {
					sort[i].schoolname = sort[i].schoolname + c;
					fscanf(infile, "%c", &c );
			 	}
	            
				while ( c == '\t' || c == ' ')
			 	  fscanf(infile, "%c", &c );
				
				while (c != ' '&& c!= '\t' )   {
					sort[i].code2 = sort[i].code2 + c;
					fscanf(infile, "%c", &c );
			 	}
			 	
				while ( c == '\t' || c == ' ')
			 	  fscanf(infile, "%c", &c );
				while (c != ' '&& c!= '\t' )   {
					sort[i].name2 = sort[i].name2 + c;
					fscanf(infile, "%c", &c );
			 	}
			 	
				while ( c == '\t' || c == ' ')
			 	  fscanf(infile, "%c", &c );
			 	  
			 	while (c != ' '&& c!= '\t' )   {
					sort[i].day = sort[i].day + c;
					fscanf(infile, "%c", &c );
			 	}
			 	while ( c == '\t' || c == ' ')
			 	  fscanf(infile, "%c", &c );
			 	  
			 	while (c != ' '&& c!= '\t' )   {
					sort[i].day2 = sort[i].day2 + c;
					fscanf(infile, "%c", &c );
			 	}
			 	while ( c == '\t' || c == ' ')
			 	  fscanf(infile, "%c", &c );
			 	while (c != ' '&& c!= '\t' )   {
					sort[i].rank = sort[i].rank + c;
					fscanf(infile, "%c", &c );
			 	}
			 	while ( c == '\t' || c == ' ')
			 	  fscanf(infile, "%c", &c );
			 	  
			 	while (c != ' '&& c!= '\t' )   {
					sort[i].rank2 = sort[i].rank2 + c;
					fscanf(infile, "%c", &c );
			 	}
			 	while ( c == '\t' || c == ' ')
			 	  fscanf(infile, "%c", &c );
			 	  
			 	while (c != ' '&& c!= '\t' )   {
					sort[i].student = sort[i].student + c;
					fscanf(infile, "%c", &c );
			 	}
			 	while ( c == '\t' || c == ' ')
			 	  fscanf(infile, "%c", &c );
			 	  
			 	while (c != ' '&& c!= '\t' )   {
					sort[i].teacher = sort[i].teacher + c;
					fscanf(infile, "%c", &c );
			 	}
			 	while ( c == '\t' || c == ' ')
			 	  fscanf(infile, "%c", &c );
			 	  
			 	while (c != ' '&& c!= '\t' )   {
					sort[i].graduate = sort[i].graduate + c;
					fscanf(infile, "%c", &c );
			 	}
			 	
			 	while ( c == '\t' || c == ' ' )
			 	  fscanf(infile, "%c", &c );
			 	  
			 	while (c != ' '&& c!= '\t' )   {
					sort[i].city = sort[i].city + c;
					fscanf(infile, "%c", &c );
			 	}
			 	while ( c == '\t' || c == ' ')
			 	  fscanf(infile, "%c", &c );
			 	  
			 	while (c != ' '&& c!= '\t' )   {
					sort[i].cityname = sort[i].cityname + c;
					fscanf(infile, "%c", &c );
			 	}
			 	
			 	while ( c == '\t' || c == ' ')
			 	  fscanf(infile, "%c", &c );
			 	  
			 	while (c != ' '&& c!= '\t' )   {
				    sort[i].degree = sort[i].degree + c;
					fscanf(infile, "%c", &c );
			 	}	
													 			 	
			 	while ( c == '\t' || c == ' ')
			 		fscanf(infile, "%c", &c );	
					 		 				 	
			 	while (c != '\n' ) {
					sort[i].degree2 = sort[i].degree2+ c;		
					if ( fscanf(infile, "%c", &c ) == -1)
					  break;
			 	}							 	
				sort.push_back(work); 				 												
				i++;									
			}	
			sort.pop_back();
			for ( i = 0; i <sort.size() ; i++ ){        
			  sort2.push_back(work); 				
			  sort2[i].schoolcode=sort[i].schoolcode;
			  sort2[i].schoolname=sort[i].schoolname;
			  sort2[i].code2=sort[i].code2;
			  sort2[i].name2=sort[i].name2;
			  sort2[i].day=sort[i].day;
			  sort2[i].day2=sort[i].day2;
			  sort2[i].rank=sort[i].rank;
			  sort2[i].rank2=sort[i].rank2;
			  sort2[i].student=sort[i].student;
			  sort2[i].teacher=sort[i].teacher;
			  sort2[i].graduate=sort[i].graduate;
			  sort2[i].city=sort[i].city;
			  sort2[i].cityname=sort[i].cityname;
			  sort2[i].degree=sort[i].degree;
			  sort2[i].degree2=sort[i].degree2;			  
			  
			}			 
			
			int first = 0,last = sort.size()-1;
			start = clock() ;
							  			
			mergesort( sort,  first,  last );   //¦X¨Ö±Æ§Ç 
			
			end = clock();
			test = ((double)(end - start)) ;
			outfile = fopen(("merge_sort" + fileName + ".txt").c_str(),"a");  
			i = 0;  		
			while( i < sort.size() ) {
				fprintf(outfile, "%s\t%s\t%s\t%s\t%s %s\t%s %s\t%s\t%s\t%s\t%s\t%s %s %s\n", sort[i].schoolcode.c_str(),  sort[i].schoolname.c_str(), sort[i].code2.c_str(), sort[i].name2.c_str(), sort[i].day.c_str(), sort[i].day2.c_str(), sort[i].rank.c_str(), 
				        sort[i].rank.c_str(), sort[i].student.c_str(), sort[i].teacher.c_str(), sort[i].graduate.c_str(), sort[i].city.c_str(), sort[i].cityname.c_str(), sort[i].degree.c_str(), sort[i].degree2.c_str() );
				i++ ;				
		    }			
			cout << "Merge sort:" << test << "ms"<< endl;
			fclose(outfile);
			
			first = 0;
			last = sort2.size()-1;			
			int pivotindex = 0;
			start = clock() ;
			
			quicksort( sort2, first,  last);  // §Ö³t±Æ§Ç 
			
			end = clock();
			test = ((double)(end - start)) ;
			outfile2 = fopen(("quick_sort" + fileName + ".txt").c_str(),"a");  
			i = 0;  
			while( i < sort2.size() ){
				fprintf(outfile2, "%s\t%s\t%s\t%s\t%s %s\t%s %s\t%s\t%s\t%s\t%s\t%s %s %s\n", sort2[i].schoolcode.c_str(),  sort2[i].schoolname.c_str(), sort2[i].code2.c_str(), sort2[i].name2.c_str(), sort2[i].day.c_str(), sort2[i].day2.c_str(), sort2[i].rank.c_str(), 
				        sort2[i].rank2.c_str(), sort2[i].student.c_str(), sort2[i].teacher.c_str(), sort2[i].graduate.c_str(), sort2[i].city.c_str(), sort2[i].cityname.c_str(), sort2[i].degree.c_str(), sort2[i].degree2.c_str() );
				i++ ;
		    }
		    cout << "Quick sort:" << test << "ms"<< endl;
			fclose(outfile2);
			
			return ;
		}
	}
	void quicksort( vector<school> &sort2, int first, int last){
		int pivotindex;
		if ( first < last){
			
			partition( sort2, first,  last,  pivotindex);
			quicksort( sort2, first,  pivotindex -1);
			quicksort( sort2, pivotindex+1,  last);
		}
	}
	
	void partition( vector<school> &sort2, int first, int last, int &pivotindex){					 
		int firstunknown=first+1;
		int lastS1= first;  // S1ªº³Ì«á 
		school temp, temp2;  
		while ( firstunknown <= last){
		    int a = atoi(sort2[first].graduate.c_str() );  // p
			int b = atoi(sort2[firstunknown].graduate.c_str() );
			if (  b >= a ) {  // S1
				
				lastS1++;		
				temp = sort2[firstunknown];
				sort2[firstunknown] = sort2[lastS1] ;
				sort2[lastS1] = temp;	
			}   
			else { // S2
				;			
			}			
			firstunknown++;
		}
	    
				
		
		temp2=sort2[lastS1];    // S1³Ì«á¸òÀY´« 
		sort2[lastS1] = sort2[first];
		sort2[first] = temp2;
		pivotindex = lastS1;
	
	}
	
	
	
	void mergesort(vector<school>&sort,int first,int last ) {		
		if ( first < last){
			int mid = (first + last) / 2;
			mergesort( sort,  first,  mid );//¥ª						
			mergesort( sort,  mid+1,  last );		// ¥k	
			merge(sort, first , mid ,last);//±Æ§Ç 
		}		
	}
	
	void merge(vector<school>&sort,int first,int mid, int last){
		school work;
		vector<school> temp;
		int first1 = first, last1 = mid;
		int first2 = mid+1, last2 = last;
		int index = 0;
		for( ; (first1 <= last1) && (first2 <= last2) ; index++ ){
		
			int a = atoi(sort[first1].graduate.c_str() );
			int b = atoi(sort[first2].graduate.c_str() );
			if ( a >= b ){
				
			    temp.push_back(work);			
			    temp[index] = sort[first1];  // ©ñ¨ìtemp³Ì«e­±¶µ 
			    
			    first1++;			    			    
			}
			else {
				temp.push_back(work);
				
			    temp[index] = sort[first2];  // ©ñ¨ìtemp³Ì«e­±¶µ 
				first2++;				
			}
		}
		for(; first1 <= last1; index++ , first1++ ){			
			temp.push_back(work);
			
		    temp[index] = sort[first1];			    
				    
		}
		for(; first2 <= last2 ; index++ , first2++ ){			
			temp.push_back(work);		
		    temp[index] = sort[first2]; 	    
		    
		    
		}
		int num = 0;
		for(index=first ; index <= last ; index++, num++ ) {			
			
			
		    sort[index] = temp[num];   // ????????    
		    			 
		}
		
	}
};

int main(){
	int test = 0;
	int method = 0;
	string name;
	sort a;
	while ( test==0){
		cout << "Input a choice(0¡A1¡A2):";
        cin >> method;
		if ( method == 0 )
		    break;
		if ( method != 0 && method != 1 && method != 2) {
		    cout << "Please try again!";
		    break ;
	    }	
	    cout << "Input a file number:";
		cin >> name;
		if ( method == 1){
			a.mission1(name);
		}
		if ( method == 2 ){
			a.mission2(name);
		}
    }
}