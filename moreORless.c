/*
	Name: Amine Yesilyurt 
	Date: 09.03.15 20:18
	Description:CSE 244 HW01
	Student Number: 131044004 
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<termios.h>
#include<unistd.h>
#include"vector.c"

int getch(void);/* reads from keypress, doesn't echo */
void readLine(FILE* inp,int amountLine,char mode,Vector* vector);

int main(int argc,char* argv[]){

    FILE* inp;
    int amountLine;
    char mode=' ';
    char **buffer;
    int endOfbuf=0;
    int i,j;
    int check1=0;
    int check2=0;
    
    /* declare and initialize a new vector*/
    Vector vector;
    vectorLine(&vector);
    
    printf("");
    
    if(argc>3 || argc<3){
        perror("Entered too much argument or missing argument");
        exit(1);
    }
    
        if((inp=fopen(argv[1],"r"))==NULL){
            perror("File not found");
            exit(1);
            }
            
            amountLine=atoi(argv[2]);
            readLine(inp,amountLine,mode,&vector);
  
            while(mode != 'q'){
            
                mode=getch();
                
                /*for to move  down on terminal.  */
                if(mode=='u'|| mode=='U' ){
                        check1++;
                    if(vector.size>amountLine && vector.size>39 ){
                        system("clear");
                        for(i=vector.size-check1-40;i<vector.size-check1;++i){                                       
                        printf("%s",vectorGet(&vector,i));
                        }
                    }
                    else if(vector.size<39){
                       
                        system("clear");
                        check2++;                                              
                            for(i=0;i<vector.size-check2;++i)                                      
                            printf("%s",vectorGet(&vector,i));                        
                        
                        }
                    }

                  /*for move to page by page or line by line*/  
                  if(mode =='\n' || mode==27 ){
                    check1=-1;
                    check2=-1;                     
                    if(mode != 'q')                   
                    readLine(inp,amountLine,mode,&vector);
                }
                
                }           
                               
              
    vectorFree(&vector);
    fclose(inp);
    return 0;
}


int getch(void){

    /*
    This fuction was copyed from stackoverflow.com
    
    */
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

void readLine(FILE* inp,int amountLine,char mode,Vector* vector){

    /*
    This function reads lines from file and prints to console.
    And each readed line copy to vector. 
    Vector keeps lines which printed to console.
    */
    
    char line[200];
    int i;
    
    if(!feof(inp) && mode != '\n')
        for(i=0;i<amountLine;++i){
            fgets(line,200,inp);
            if(!feof(inp)){
                
                vectorAppend(vector,line);
                printf("%s",line);
            }                
        }   
        
    if( !feof(inp) && mode == '\n'){
 
        fgets(line,200,inp);
        if(!feof(inp)){          
            printf("%s",line);
            vectorAppend(vector,line);
        }
    }
}

