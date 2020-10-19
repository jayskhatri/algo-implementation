#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int lookup(char lexemeTable[][100], char ch[], int symbolEntry){

    for(int i=0; i<symbolEntry; i++){
        if(strcmp(lexemeTable[i], ch)==0){
            return 1;
        }
    }
    return 0;

}


int iskeyw(char buffer[]){
char keywords[32][10]= { "auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while" };
    int i, flag = 0;

    for(i = 0; i < 32; ++i){
        if(strcmp(keywords[i], buffer) == 0){
            flag = 1;
            break;
        }
    }
    return flag;
}

int main(){
     char ch, buffer[210],idf[80],str[80],dig[80], operators[] = "+-*/%=&", SC[] = "(){}[];,";
	char buffer1[512], buffer2[512];
	int n=512;
	char *fp, *bp;
    int i,j=0,st=0,d=0;
    char symbolTableLexene[1000][100];
    char symbolTableToken[1000][100];
    int symbolEntry=0;
	buffer1[n-1] = '\0';
	buffer2[n-1] = '\0';
    FILE *fd;
	fd = fopen("input.txt","r");
	if(fd == NULL){
		printf("Error while opening the file\n");
		exit(0);
	}


	int flag=1, bflag=1;
	int cou=0, curr=0;
	int size= fread(buffer1, 1, n-1, fd);
	fp = buffer1;
	bp = buffer1;
    printf("--------------------------------------\n");
    printf("Lexene  :  Token\n");
    printf("--------------------------------------\n");
    while(1){
    	if(*fp=='\0'){

			if(flag==1 && size==n-1){
                memset(buffer2, 0, n);
				size = fread(buffer2, 1, n-1, fd);
				buffer2[size]='\0';
				fp = buffer2;
				flag = 2;
				cou=0;

			}
			else if(flag==2 && size==n-1){
                memset(buffer1, 0, n);
				size =fread(buffer1, 1, n-1, fd);
				buffer1[size]='\0';
				fp = buffer1;
				flag = 1;
				cou=0;

			}
			else{
				break;
			}
            switch(curr){
            case 1:
                goto identi;
                break;
            case 2:
                goto constant;
                break;
            case 3:
                goto string;
                break;
            case 4:
                goto string2;
                break;
            case 5:
                goto single;
                break;
            case 6:
                goto multi;
                break;
            case 7:
                goto comm;
                break;
            }

		}
		else{
//            printf("%c",*fp);
            if(*fp=='/')
			{
				fp++;
            comm:
                curr=0;
                if(*fp=='\0'){
                    curr=7;
                    continue;
                }
				if(*fp=='/')
				{
                single:
				    curr=0;
					while((*fp!='\n')&&(*fp!='\0'))
					{
						fp++;
					}
					if(*fp=='\0'){
                        curr=5;
                        continue;
					}
				}
				else if(*fp=='*')
				{
                multi:
                    curr=0;
					while(1)
					{
						fp++;
						if(*fp=='\0'){
                            curr=6;
                            continue;

						}
						if(*fp=='*')
						{
							fp++;
							if(*fp=='/')
							{
								break;
							}
						}
					}
					fp++;
				}
				else
				{
					fp--;
				}
				if(*fp='\0'){
					continue;
				}
				bp=fp;
			}
            if(isdigit(*fp))
			{
            constant:
                curr=0;
                while(isdigit(*fp))
				{
					fp++;
					cou++;
				}
				if(*fp=='\0' && cou==n-1)
				{
				    curr=2;
					continue;
				}
				while(*bp!=*fp)
				{
					if(*bp=='\0')
					{
						if(flag==1)
						{
							bp=buffer1;
						}
						else{
							bp=buffer2;
						}
					}
					else
					{
						dig[d++]=*bp;
						bp++;
					}
				}
				dig[d]='\0';
				d=0;
				if(!lookup(symbolTableLexene, dig, symbolEntry))
				{
	                strcpy(symbolTableLexene[symbolEntry],dig);
	                strcpy(symbolTableToken[symbolEntry],"Constant");
	                symbolEntry++;

            	}
			}
			else
            {
                if(isalpha(*fp)||*fp=='_')
				{
                identi:
                    curr=0;
					while(isalnum(*fp) || *fp=='_')
					{
						fp++;
						cou++;
					}

					if(*fp=='\0' && cou==n-1){
                        curr=1;
						continue;
					}
					while(*bp!=*fp)
					{
						if(*bp=='\0')
						{
							if(flag==1)
							{
								bp=buffer1;
							}
							else{
								bp=buffer2;
							}
						}
						else
						{
							idf[j++]=*bp;
							bp++;
						}
					}
                    idf[j] = '\0';
                    j = 0;
                    if(iskeyw(idf) == 1)
                    {
                        if(!lookup(symbolTableLexene, idf, symbolEntry)){
                            strcpy(symbolTableLexene[symbolEntry],idf);
                            strcpy(symbolTableToken[symbolEntry],"Reserved Keyword");
                            symbolEntry++;
                        }
                    }
                    else
                    {
                        if(!lookup(symbolTableLexene, idf, symbolEntry)){
                            strcpy(symbolTableLexene[symbolEntry],idf);
                            strcpy(symbolTableToken[symbolEntry],"Identifier");
                            symbolEntry++;
                        }
                    }
				}
			}
			if(*fp=='\'')
			{
				str[st++]=*fp;
				fp++;
				bp++;
				cou++;
        string2:
                curr=0;
				while((*fp!='\'') &&(*fp!='\0'))
				{

					fp++;
					cou++;

				}
				if(*fp=='\0' && cou==n-1){
					curr=4;
					continue;
				}

				while(*bp!=*fp)
				{
					if(*bp=='\0')
					{
						if(flag==1)
						{
							bp=buffer1;
						}
						else{
							bp=buffer2;
						}
					}
					else
					{
					str[st++]=*bp;
					bp++;
					}
				}
				str[st++] = '\'';
				str[st++] = '\0';
				if(!lookup(symbolTableLexene, str, symbolEntry))
				{
	                strcpy(symbolTableLexene[symbolEntry],str);
	                strcpy(symbolTableToken[symbolEntry],"String");
	                symbolEntry++;
	            }
             	st=0;
            }
			if(*fp=='"')
			{
				str[st++]=*fp;
				fp++;
				bp++;
				cou++;
        string:
                curr=0;
				while((*fp!='"') &&(*fp!='\0'))
				{

					fp++;
					cou++;

				}
				if(*fp=='\0' && cou==n-1){
					curr=3;
					continue;
				}

				while(*bp!=*fp)
				{
					if(*bp=='\0')
					{
						if(flag==1)
						{
							bp=buffer1;
						}
						else{
							bp=buffer2;
						}
					}
					else
					{
					str[st++]=*bp;
					bp++;
					}
				}
				str[st++] = '"';
				str[st++] = '\0';
				if(!lookup(symbolTableLexene, str, symbolEntry))
				{
	                strcpy(symbolTableLexene[symbolEntry],str);
	                strcpy(symbolTableToken[symbolEntry],"String");
	                symbolEntry++;
	            }
             	st=0;
            }
            for(i = 0; i < 7; i++)
        	{
           		if(*fp == operators[i])
	           	{
	               char chNew[2];
	               chNew[0]=*fp;
	               chNew[1]='\0';
	               	if(!lookup(symbolTableLexene, chNew, symbolEntry))
	               	{
	                    strcpy(symbolTableLexene[symbolEntry],chNew);
	                    strcpy(symbolTableToken[symbolEntry],"Operator");
	                    symbolEntry++;
	                }
	              break;
	           	}
	        }
	        for(i=0;i<8;i++)
       		{
               if(*fp == SC[i])
                {
                   char chNew[2];
                   chNew[0]=*fp;
                   chNew[1]='\0';
                   if(!lookup(symbolTableLexene, chNew, symbolEntry)){
                        strcpy(symbolTableLexene[symbolEntry],chNew);
                        strcpy(symbolTableToken[symbolEntry],"Special Symbol");
                        symbolEntry++;
                    }
                    break;
                }
       		}
			fp++;
			bp++;
			cou++;
		}
    }
    fclose(fd);
    for(int i=0;i<symbolEntry;i++)
    {
        printf("%s  :  %s\n",symbolTableLexene[i],symbolTableToken[i]);
    }

    return 0;

}
