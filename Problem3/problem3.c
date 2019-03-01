/*
**	This program is a template for SP lab 3 task 3 you are 
**	required to implement its one function.
*/


#include<stdio.h>
#include<string.h>
#include <stdlib.h>

/*	
**	This function take file pointer as paramter to read content from and 
**	char pointer as an second argument which points to string to search in file
*/
void mygrep(FILE* file, char* ch){
  while(!feof(file))
{
	char temp[200];
fgets(temp,1000,file);
if(strstr(temp,ch))
  printf("%s",temp);
}
}

/*	
**	This function take file pointer as paramter to read content from and 
**	char pointer as an second argument which points to string to search in file
** 	and char pointer as an third argument to replace the string finded with it.
*/





  void myreplace(FILE *fp,char *ch, char * replace)
{

int i, j=0, k;
  for(i=0; file[i]; i++)
  {
    if(file[i] == ch[j])
    {
      int x=i;
      for(k=i, j=0; file[k] && ch[j]; j++, k++)
        if(file[k]!=ch[j])
            break;
       
       for(int l=0,m=i; file[m] && ch[l]; m++,l++)
        file[m]=replace[l];
    }
    }
  }

}

int  main(int argc,char *argv[])
{


	/*	creating variables	
*/

	char behaviour;
	FILE *fp;
	char *filename=argv[1];
	char *find=argv[2];
	char * replace;

	/*	check if mygrep is called or myreplace	
*/	
	if(argv[0]=="mygrep" )
	{
		printf("ikram is ok\n");
		if(argc != 3)
		{
			printf("usage\t./mygrep filename <string-to-search>\n");
			exit(1);
		}

		behaviour = 'G';
	}
	else if(argv[0]=="myreplace")
	{
		if(argc != 4)
		{
			printf("\t./myreplace filename  <string-to-search> <string-to-replace>");
			exit(1);
		}
		behaviour = 'R';
		replace = argv[3];
	}
	else
	{
		behaviour = -1;
	}



	/* opening file	
*/

	fp=fopen(filename,"rt");

	if(behaviour == 'G')
	{
		mygrep(fp,find);		/*	caling function	
*/
	}
	else if ( behaviour == 'R' )
	{
		myreplace(fp,find,replace);		/*	calling myreplace	

	}
*/	
	fclose(fp);		/*	closing file	*/


	return 0;
}
