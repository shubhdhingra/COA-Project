
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<string.h>
#include<malloc.h>
#include<graphics.h>
#define TBG textbackground(YELLOW);textcolor(BLUE)

void SetValue1(char *instruction,char *source)
{
	//printf("\n%s %s %s",instruction,source,dest);
	char opcode[10];
	char d[2], w[2];
	char mod[3];
	char reg[4];
	char reg_mem[4];
	if (strcmpi(instruction,"ADD") == 0)
	{
		if(source+1!="\0")
		{
		strcpy(opcode,"100101");
			if(source[1]=='x'||source[1]=='X')
			{
			strcpy(reg_mem,"000");
			}
			else if(source[1]=='h'||source[1]=='H')
			{
				strcpy(reg_mem,"100");
			}
			else{                          ////register single char
				printf("wrong input\n");
	getch();		}
			if (source[0] == 'A' || source[0] == 'B' || source[0] == 'C' || source[0] == 'D' || source[0] == 'S' || source[0] == 'a' || source[0] == 'b' || source[0] == 'c' || source[0] == 'd' || source[0] == 's')
	    {
			strcpy(mod,"11");

			strcpy(d,"0");
			if (source[1] == 'X' || source[1] == 'I' || source[1] == 'P' || source[1] == 'x' || source[1] == 'i' || source[1] == 'p')
			{
		//		printf("2");
				strcpy(w,"1");
			//	strcpy(reg_mem,"000");
			}
			else if(source[1] == 'h' || source[1] == 'H' ){
		//		printf("3");
				strcpy(w,"0");
			//	strcpy(reg_mem,"100");
			}
			else{
				printf("wrong input\n");
			getch();}
			if (source[0] == 'B' || source[0] == 'b')
			{
		//		printf("4");
				if (source[1] == 'X' || source[1] == 'L' || source[1] == 'x' || source[1] == 'l')
				{
			    strcpy(reg,"011");
	Display(opcode, d, w, mod, reg, reg_mem);
    				//reg = 011;
				}
				else if (source[1] == 'P' || source[1] == 'p')
				{
					strcpy(reg,"101");
	Display(opcode, d, w, mod, reg, reg_mem);
    				//reg,101;
					//printf("6");
				}
				else if(source[1] == 'H' || source[1] == 'h' ){
					//printf("7");
					//reg = 111;
				strcpy(reg,"111");
	Display(opcode, d, w, mod, reg, reg_mem);
    
				}
				else{
					printf("wrong input\n");
				getch();}
			}
			else if (source[0] == 'S'||source[0] == 's')
			{
				//printf("8");
				if (source[1] == 'P'|| source[1] == 'p')
				{
				strcpy(reg,"100");
				Display(opcode, d, w, mod, reg, reg_mem);
    
				}
				else if(source[1]=='I'||source[1]=='i'){
					//printf("10");
					//reg = 110;
				strcpy(reg,"110");
				Display(opcode, d, w, mod, reg, reg_mem);
    
				}
	else{
		printf("wrong input\n");
	getch();}			
			}
			else if (source[0] == 'D' || source[0] == 'd')
			{
				if (source[1] == 'X' || source[1] == 'L' || source[1] == 'x' || source[1] == 'l')
				{
					strcpy(reg,"010");
					//reg = 010;
				}
				else if (source[1] == 'i' || source[1] == 'I')
				{
					strcpy(reg,"111");
	Display(opcode, d, w, mod, reg, reg_mem);
    				//reg = 111;
				}
				else if(source[1]=='H'||source[1]=='h'){
					strcpy(reg,"110");
					//reg = 110;
				Display(opcode, d, w, mod, reg, reg_mem);
    }
				else{
					printf("wrong input\n");
			getch();	}
			}
			else if (source[0] == 'A' || source[0] == 'a')
			{
				if (source[1] == 'X' || source[1] == 'L' || source[1] == 'x' || source[1] == 'l')
				{
					strcpy(reg,"000");
	Display(opcode, d, w, mod, reg, reg_mem);
    				//reg = 000;
				}
				else if(source[1]=='H'||source[1]=='h'){
					strcpy(reg,"100");
	Display(opcode, d, w, mod, reg, reg_mem);
    				//reg = 100;
				}
	else{
		printf("wrong input\n");
	}
		getch();	}
				
			
			else if (source[0] == 'C' || source[0] == 'c')
			{
				if (source[1] == 'X' || source[1] == 'L' || source[1] == 'x' || source[1] == 'l')
				{
					strcpy(reg,"011");
				//	reg = 001;
				Display(opcode, d, w, mod, reg, reg_mem);
    
				}
				else if(source[1]=='H'||source[1]=='h'){
					strcpy(reg,"101");
Display(opcode, d, w, mod, reg, reg_mem);
    					//reg = 101;
				}
				else{
					printf("wrong input\n");
				getch();}
			}
			
}
	else{                               /////////////wrong register initials
		printf("wrong input\n");
	getch();}
	}
	else           //////////register null
	{
		printf("wrong input\n");
	getch();
	}

	//printf("\nwrong input\n");

if(source[0]=='[')
{
//if(source[2]=='X'&&dest[1]=='X'||source[2]=='x'&&dest[1]=='x'||source[1]!='B'&&dest[1]=='X'||source[1]!='b'&&dest[1]=='x')
  if(source+2!="\0")
{

	
	    strcpy(reg,"000");
	strcpy(d,"1");
	strcpy(mod,"00");
	strcpy(w,"1");
	if(source[1]=='B'||source[1]=='b')
	{
		if(source[2]=='X'||source[2]=='x')
		{

	    if(strlen(source)==4)
	    {
		strcpy(reg_mem,"111");
		}
		else if(source[4]=='S'||source[4]=='s')
		{
			strcpy(reg_mem,"000");
		}
		else if(source[4]=='D'||source[4]=='d')
		{
			strcpy(reg_mem,"001");
		}
		}
	Display(opcode, d, w, mod, reg, reg_mem);
	}
	else if(strlen(source)==6)
    {
	strcpy(reg_mem,"110");
    Display(opcode, d, w, mod, reg, reg_mem);
    }
    else
	{
	printf("wrong input\n");
   getch(); }

}
    else                          /////null memory source
	{
	printf("\nwrong input\n");
    getch();}
 }
}
else                                            ////wrong instruction
{
printf("\nwrong input\n");
getch();}
}



void SetValue2(char *instruction,char *source)
{

	//printf("\n%s %s %s",instruction,source,dest);
	char opcode[10];
	char d[2], w[2];
	char mod[3];
	char reg[4];
	char reg_mem[4];
	if (strcmpi(instruction,"SUB") == 0)
	{
		if(source+1!="\0")
		{
		strcpy(opcode,"100011");
			if(source[1]=='x'||source[1]=='X')
			{
			strcpy(reg_mem,"000");
			}
			else if(source[1]=='h'||source[1]=='H')
			{
				strcpy(reg_mem,"100");
			}
			else{                          ////register single char
				printf("wrong input\n");
	getch();		}
			if (source[0] == 'A' || source[0] == 'B' || source[0] == 'C' || source[0] == 'D' || source[0] == 'S' || source[0] == 'a' || source[0] == 'b' || source[0] == 'c' || source[0] == 'd' || source[0] == 's')
	    {
			strcpy(mod,"11");

			strcpy(d,"0");
			if (source[1] == 'X' || source[1] == 'I' || source[1] == 'P' || source[1] == 'x' || source[1] == 'i' || source[1] == 'p')
			{
		//		printf("2");
				strcpy(w,"1");
			//	strcpy(reg_mem,"000");
			}
			else if(source[1] == 'h' || source[1] == 'H' ){
		//		printf("3");
				strcpy(w,"0");
			//	strcpy(reg_mem,"100");
			}
			else{
				printf("wrong input\n");
			getch();}
			if (source[0] == 'B' || source[0] == 'b')
			{
		//		printf("4");
				if (source[1] == 'X' || source[1] == 'L' || source[1] == 'x' || source[1] == 'l')
				{
			    strcpy(reg,"011");
	Display(opcode, d, w, mod, reg, reg_mem);
    				//reg = 011;
				}
				else if (source[1] == 'P' || source[1] == 'p')
				{
					strcpy(reg,"101");
	Display(opcode, d, w, mod, reg, reg_mem);
    				//reg,101;
					//printf("6");
				}
				else if(source[1] == 'H' || source[1] == 'h' ){
					//printf("7");
					//reg = 111;
				strcpy(reg,"111");
	Display(opcode, d, w, mod, reg, reg_mem);
    
				}
				else{
					printf("wrong input\n");
				getch();}
			}
			else if (source[0] == 'S'||source[0] == 's')
			{
				//printf("8");
				if (source[1] == 'P'|| source[1] == 'p')
				{
				strcpy(reg,"100");
				Display(opcode, d, w, mod, reg, reg_mem);
    
				}
				else if(source[1]=='I'||source[1]=='i'){
					//printf("10");
					//reg = 110;
				strcpy(reg,"110");
				Display(opcode, d, w, mod, reg, reg_mem);
    
				}
	else{
		printf("wrong input\n");
	getch();}			
			}
			else if (source[0] == 'D' || source[0] == 'd')
			{
				if (source[1] == 'X' || source[1] == 'L' || source[1] == 'x' || source[1] == 'l')
				{
					strcpy(reg,"010");
					//reg = 010;
				}
				else if (source[1] == 'i' || source[1] == 'I')
				{
					strcpy(reg,"111");
	Display(opcode, d, w, mod, reg, reg_mem);
    				//reg = 111;
				}
				else if(source[1]=='H'||source[1]=='h'){
					strcpy(reg,"110");
					//reg = 110;
				Display(opcode, d, w, mod, reg, reg_mem);
    }
				else{
					printf("wrong input\n");
			getch();	}
			}
			else if (source[0] == 'A' || source[0] == 'a')
			{
				if (source[1] == 'X' || source[1] == 'L' || source[1] == 'x' || source[1] == 'l')
				{
					strcpy(reg,"000");
	Display(opcode, d, w, mod, reg, reg_mem);
    				//reg = 000;
				}
				else if(source[1]=='H'||source[1]=='h'){
					strcpy(reg,"100");
	Display(opcode, d, w, mod, reg, reg_mem);
    				//reg = 100;
				}
	else{
		printf("wrong input\n");
	}
		getch();	}
				
			
			else if (source[0] == 'C' || source[0] == 'c')
			{
				if (source[1] == 'X' || source[1] == 'L' || source[1] == 'x' || source[1] == 'l')
				{
					strcpy(reg,"011");
				//	reg = 001;
				Display(opcode, d, w, mod, reg, reg_mem);
    
				}
				else if(source[1]=='H'||source[1]=='h'){
					strcpy(reg,"101");
Display(opcode, d, w, mod, reg, reg_mem);
    					//reg = 101;
				}
				else{
					printf("wrong input\n");
				getch();}
			}
			
}
	else{                               /////////////wrong register initials
		printf("wrong input\n");
	getch();}
	}
	else           //////////register null
	{
		printf("wrong input\n");
	getch();
	}

	//printf("\nwrong input\n");

if(source[0]=='[')
{
//if(source[2]=='X'&&dest[1]=='X'||source[2]=='x'&&dest[1]=='x'||source[1]!='B'&&dest[1]=='X'||source[1]!='b'&&dest[1]=='x')
  if(source+2!="\0")
{

	
	    strcpy(reg,"000");
	strcpy(d,"1");
	strcpy(mod,"00");
	strcpy(w,"1");
	if(source[1]=='B'||source[1]=='b')
	{
		if(source[2]=='X'||source[2]=='x')
		{

	    if(strlen(source)==4)
	    {
		strcpy(reg_mem,"111");
		}
		else if(source[4]=='S'||source[4]=='s')
		{
			strcpy(reg_mem,"000");
		}
		else if(source[4]=='D'||source[4]=='d')
		{
			strcpy(reg_mem,"001");
		}
		}
	Display(opcode, d, w, mod, reg, reg_mem);
	}
	else if(strlen(source)==6)
    {
	strcpy(reg_mem,"110");
    Display(opcode, d, w, mod, reg, reg_mem);
    }
    else
	{
	printf("wrong input\n");
   getch(); }

}
    else                          /////null memory source
	{
	printf("\nwrong input\n");
    getch();}
 }
}
else                                            ////wrong instruction
{
printf("\nwrong input\n");
getch();}
}






void SetValue3(char *instruction,char *source)
{

	//printf("\n%s %s %s",instruction,source,dest);
	char opcode[10];
	char d[2], w[2];
	char mod[3];
	char reg[4];
	char reg_mem[4];
	if (strcmpi(instruction,"MUL") == 0)
	{
		if(source+1!="\0")
		{
		strcpy(opcode,"101110");
			if(source[1]=='x'||source[1]=='X')
			{
			strcpy(reg_mem,"000");
			}
			else if(source[1]=='h'||source[1]=='H')
			{
				strcpy(reg_mem,"100");
			}
			else{                          ////register single char
				printf("wrong input\n");
	getch();		}
			if (source[0] == 'A' || source[0] == 'B' || source[0] == 'C' || source[0] == 'D' || source[0] == 'S' || source[0] == 'a' || source[0] == 'b' || source[0] == 'c' || source[0] == 'd' || source[0] == 's')
	    {
			strcpy(mod,"11");

			strcpy(d,"0");
			if (source[1] == 'X' || source[1] == 'I' || source[1] == 'P' || source[1] == 'x' || source[1] == 'i' || source[1] == 'p')
			{
		//		printf("2");
				strcpy(w,"1");
			//	strcpy(reg_mem,"000");
			}
			else if(source[1] == 'h' || source[1] == 'H' ){
		//		printf("3");
				strcpy(w,"0");
			//	strcpy(reg_mem,"100");
			}
			else{
				printf("wrong input\n");
			getch();}
			if (source[0] == 'B' || source[0] == 'b')
			{
		//		printf("4");
				if (source[1] == 'X' || source[1] == 'L' || source[1] == 'x' || source[1] == 'l')
				{
			    strcpy(reg,"011");
	Display(opcode, d, w, mod, reg, reg_mem);
    				//reg = 011;
				}
				else if (source[1] == 'P' || source[1] == 'p')
				{
					strcpy(reg,"101");
	Display(opcode, d, w, mod, reg, reg_mem);
    				//reg,101;
					//printf("6");
				}
				else if(source[1] == 'H' || source[1] == 'h' ){
					//printf("7");
					//reg = 111;
				strcpy(reg,"111");
	Display(opcode, d, w, mod, reg, reg_mem);
    
				}
				else{
					printf("wrong input\n");
				getch();}
			}
			else if (source[0] == 'S'||source[0] == 's')
			{
				//printf("8");
				if (source[1] == 'P'|| source[1] == 'p')
				{
				strcpy(reg,"100");
				Display(opcode, d, w, mod, reg, reg_mem);
    
				}
				else if(source[1]=='I'||source[1]=='i'){
					//printf("10");
					//reg = 110;
				strcpy(reg,"110");
				Display(opcode, d, w, mod, reg, reg_mem);
    
				}
	else{
		printf("wrong input\n");
	getch();}			
			}
			else if (source[0] == 'D' || source[0] == 'd')
			{
				if (source[1] == 'X' || source[1] == 'L' || source[1] == 'x' || source[1] == 'l')
				{
					strcpy(reg,"010");
					//reg = 010;
				}
				else if (source[1] == 'i' || source[1] == 'I')
				{
					strcpy(reg,"111");
	Display(opcode, d, w, mod, reg, reg_mem);
    				//reg = 111;
				}
				else if(source[1]=='H'||source[1]=='h'){
					strcpy(reg,"110");
					//reg = 110;
				Display(opcode, d, w, mod, reg, reg_mem);
    }
				else{
					printf("wrong input\n");
			getch();	}
			}
			else if (source[0] == 'A' || source[0] == 'a')
			{
				if (source[1] == 'X' || source[1] == 'L' || source[1] == 'x' || source[1] == 'l')
				{
					strcpy(reg,"000");
	Display(opcode, d, w, mod, reg, reg_mem);
    				//reg = 000;
				}
				else if(source[1]=='H'||source[1]=='h'){
					strcpy(reg,"100");
	Display(opcode, d, w, mod, reg, reg_mem);
    				//reg = 100;
				}
	else{
		printf("wrong input\n");
	}
		getch();	}
				
			
			else if (source[0] == 'C' || source[0] == 'c')
			{
				if (source[1] == 'X' || source[1] == 'L' || source[1] == 'x' || source[1] == 'l')
				{
					strcpy(reg,"011");
				//	reg = 001;
				Display(opcode, d, w, mod, reg, reg_mem);
    
				}
				else if(source[1]=='H'||source[1]=='h'){
					strcpy(reg,"101");
Display(opcode, d, w, mod, reg, reg_mem);
    					//reg = 101;
				}
				else{
					printf("wrong input\n");
				getch();}
			}
			
}
	else{                               /////////////wrong register initials
		printf("wrong input\n");
	getch();}
	}
	else           //////////register null
	{
		printf("wrong input\n");
	getch();
	}

	//printf("\nwrong input\n");

if(source[0]=='[')
{
//if(source[2]=='X'&&dest[1]=='X'||source[2]=='x'&&dest[1]=='x'||source[1]!='B'&&dest[1]=='X'||source[1]!='b'&&dest[1]=='x')
  if(source+2!="\0")
{

	
	    strcpy(reg,"000");
	strcpy(d,"1");
	strcpy(mod,"00");
	strcpy(w,"1");
	if(source[1]=='B'||source[1]=='b')
	{
		if(source[2]=='X'||source[2]=='x')
		{

	    if(strlen(source)==4)
	    {
		strcpy(reg_mem,"111");
		}
		else if(source[4]=='S'||source[4]=='s')
		{
			strcpy(reg_mem,"000");
		}
		else if(source[4]=='D'||source[4]=='d')
		{
			strcpy(reg_mem,"001");
		}
		}
	Display(opcode, d, w, mod, reg, reg_mem);
	}
	else if(strlen(source)==6)
    {
	strcpy(reg_mem,"110");
    Display(opcode, d, w, mod, reg, reg_mem);
    }
    else
	{
	printf("wrong input\n");
   getch(); }

}
    else                          /////null memory source
	{
	printf("\nwrong input\n");
    getch();}
 }
}
else                                            ////wrong instruction
{
printf("\nwrong input\n");
getch();}
}






void SetValue4(char *instruction,char *source)
{

	//printf("\n%s %s %s",instruction,source,dest);
	char opcode[10];
	char d[2], w[2];
	char mod[3];
	char reg[4];
	char reg_mem[4];
	if (strcmpi(instruction,"DIV") == 0)
	{
		if(source+1!="\0")
		{
		strcpy(opcode,"100111");
			if(source[1]=='x'||source[1]=='X')
			{
			strcpy(reg_mem,"000");
			}
			else if(source[1]=='h'||source[1]=='H')
			{
				strcpy(reg_mem,"100");
			}
			else{                          ////register single char
				printf("wrong input\n");
	getch();		}
			if (source[0] == 'A' || source[0] == 'B' || source[0] == 'C' || source[0] == 'D' || source[0] == 'S' || source[0] == 'a' || source[0] == 'b' || source[0] == 'c' || source[0] == 'd' || source[0] == 's')
	    {
			strcpy(mod,"11");

			strcpy(d,"0");
			if (source[1] == 'X' || source[1] == 'I' || source[1] == 'P' || source[1] == 'x' || source[1] == 'i' || source[1] == 'p')
			{
		//		printf("2");
				strcpy(w,"1");
			//	strcpy(reg_mem,"000");
			}
			else if(source[1] == 'h' || source[1] == 'H' ){
		//		printf("3");
				strcpy(w,"0");
			//	strcpy(reg_mem,"100");
			}
			else{
				printf("wrong input\n");
			getch();}
			if (source[0] == 'B' || source[0] == 'b')
			{
		//		printf("4");
				if (source[1] == 'X' || source[1] == 'L' || source[1] == 'x' || source[1] == 'l')
				{
			    strcpy(reg,"011");
	Display(opcode, d, w, mod, reg, reg_mem);
    				//reg = 011;
				}
				else if (source[1] == 'P' || source[1] == 'p')
				{
					strcpy(reg,"101");
	Display(opcode, d, w, mod, reg, reg_mem);
    				//reg,101;
					//printf("6");
				}
				else if(source[1] == 'H' || source[1] == 'h' ){
					//printf("7");
					//reg = 111;
				strcpy(reg,"111");
	Display(opcode, d, w, mod, reg, reg_mem);
    
				}
				else{
					printf("wrong input\n");
				getch();}
			}
			else if (source[0] == 'S'||source[0] == 's')
			{
				//printf("8");
				if (source[1] == 'P'|| source[1] == 'p')
				{
				strcpy(reg,"100");
				Display(opcode, d, w, mod, reg, reg_mem);
    
				}
				else if(source[1]=='I'||source[1]=='i'){
					//printf("10");
					//reg = 110;
				strcpy(reg,"110");
				Display(opcode, d, w, mod, reg, reg_mem);
    
				}
	else{
		printf("wrong input\n");
	getch();}			
			}
			else if (source[0] == 'D' || source[0] == 'd')
			{
				if (source[1] == 'X' || source[1] == 'L' || source[1] == 'x' || source[1] == 'l')
				{
					strcpy(reg,"010");
					//reg = 010;
				}
				else if (source[1] == 'i' || source[1] == 'I')
				{
					strcpy(reg,"111");
	Display(opcode, d, w, mod, reg, reg_mem);
    				//reg = 111;
				}
				else if(source[1]=='H'||source[1]=='h'){
					strcpy(reg,"110");
					//reg = 110;
				Display(opcode, d, w, mod, reg, reg_mem);
    }
				else{
					printf("wrong input\n");
			getch();	}
			}
			else if (source[0] == 'A' || source[0] == 'a')
			{
				if (source[1] == 'X' || source[1] == 'L' || source[1] == 'x' || source[1] == 'l')
				{
					strcpy(reg,"000");
	Display(opcode, d, w, mod, reg, reg_mem);
    				//reg = 000;
				}
				else if(source[1]=='H'||source[1]=='h'){
					strcpy(reg,"100");
	Display(opcode, d, w, mod, reg, reg_mem);
    				//reg = 100;
				}
	else{
		printf("wrong input\n");
	}
		getch();	}
				
			
			else if (source[0] == 'C' || source[0] == 'c')
			{
				if (source[1] == 'X' || source[1] == 'L' || source[1] == 'x' || source[1] == 'l')
				{
					strcpy(reg,"011");
				//	reg = 001;
				Display(opcode, d, w, mod, reg, reg_mem);
    
				}
				else if(source[1]=='H'||source[1]=='h'){
					strcpy(reg,"101");
Display(opcode, d, w, mod, reg, reg_mem);
    					//reg = 101;
				}
				else{
					printf("wrong input\n");
				getch();}
			}
			
}
	else{                               /////////////wrong register initials
		printf("wrong input\n");
	getch();}
	}
	else           //////////register null
	{
		printf("wrong input\n");
	getch();
	}

	//printf("\nwrong input\n");

if(source[0]=='[')
{
//if(source[2]=='X'&&dest[1]=='X'||source[2]=='x'&&dest[1]=='x'||source[1]!='B'&&dest[1]=='X'||source[1]!='b'&&dest[1]=='x')
  if(source+2!="\0")
{

	
	    strcpy(reg,"000");
	strcpy(d,"1");
	strcpy(mod,"00");
	strcpy(w,"1");
	if(source[1]=='B'||source[1]=='b')
	{
		if(source[2]=='X'||source[2]=='x')
		{

	    if(strlen(source)==4)
	    {
		strcpy(reg_mem,"111");
		}
		else if(source[4]=='S'||source[4]=='s')
		{
			strcpy(reg_mem,"000");
		}
		else if(source[4]=='D'||source[4]=='d')
		{
			strcpy(reg_mem,"001");
		}
		}
	Display(opcode, d, w, mod, reg, reg_mem);
	}
	else if(strlen(source)==6)
    {
	strcpy(reg_mem,"110");
    Display(opcode, d, w, mod, reg, reg_mem);
    }
    else
	{
	printf("wrong input\n");
   getch(); }

}
    else                          /////null memory source
	{
	printf("\nwrong input\n");
    getch();}
 }
}
else                                            ////wrong instruction
{
printf("\nwrong input\n");
getch();}
}








void SetValue5(char *instruction,char *source)
{

	//printf("\n%s %s %s",instruction,source,dest);
	char opcode[10];
	char d[2], w[2];
	char mod[3];
	char reg[4];
	char reg_mem[4];
	if (strcmpi(instruction,"INC") == 0)
	{
		if(source+1!="\0")
		{
		strcpy(opcode,"110010");
			if(source[1]=='x'||source[1]=='X')
			{
			strcpy(reg_mem,"000");
			}
			else if(source[1]=='h'||source[1]=='H')
			{
				strcpy(reg_mem,"100");
			}
			else{                          ////register single char
				printf("wrong input\n");
	getch();		}
			if (source[0] == 'A' || source[0] == 'B' || source[0] == 'C' || source[0] == 'D' || source[0] == 'S' || source[0] == 'a' || source[0] == 'b' || source[0] == 'c' || source[0] == 'd' || source[0] == 's')
	    {
			strcpy(mod,"11");

			strcpy(d,"0");
			if (source[1] == 'X' || source[1] == 'I' || source[1] == 'P' || source[1] == 'x' || source[1] == 'i' || source[1] == 'p')
			{
		//		printf("2");
				strcpy(w,"1");
			//	strcpy(reg_mem,"000");
			}
			else if(source[1] == 'h' || source[1] == 'H' ){
		//		printf("3");
				strcpy(w,"0");
			//	strcpy(reg_mem,"100");
			}
			else{
				printf("wrong input\n");
			getch();}
			if (source[0] == 'B' || source[0] == 'b')
			{
		//		printf("4");
				if (source[1] == 'X' || source[1] == 'L' || source[1] == 'x' || source[1] == 'l')
				{
			    strcpy(reg,"011");
	Display(opcode, d, w, mod, reg, reg_mem);
    				//reg = 011;
				}
				else if (source[1] == 'P' || source[1] == 'p')
				{
					strcpy(reg,"101");
	Display(opcode, d, w, mod, reg, reg_mem);
    				//reg,101;
					//printf("6");
				}
				else if(source[1] == 'H' || source[1] == 'h' ){
					//printf("7");
					//reg = 111;
				strcpy(reg,"111");
	Display(opcode, d, w, mod, reg, reg_mem);
    
				}
				else{
					printf("wrong input\n");
				getch();}
			}
			else if (source[0] == 'S'||source[0] == 's')
			{
				//printf("8");
				if (source[1] == 'P'|| source[1] == 'p')
				{
				strcpy(reg,"100");
				Display(opcode, d, w, mod, reg, reg_mem);
    
				}
				else if(source[1]=='I'||source[1]=='i'){
					//printf("10");
					//reg = 110;
				strcpy(reg,"110");
				Display(opcode, d, w, mod, reg, reg_mem);
    
				}
	else{
		printf("wrong input\n");
	getch();}			
			}
			else if (source[0] == 'D' || source[0] == 'd')
			{
				if (source[1] == 'X' || source[1] == 'L' || source[1] == 'x' || source[1] == 'l')
				{
					strcpy(reg,"010");
					//reg = 010;
				}
				else if (source[1] == 'i' || source[1] == 'I')
				{
					strcpy(reg,"111");
	Display(opcode, d, w, mod, reg, reg_mem);
    				//reg = 111;
				}
				else if(source[1]=='H'||source[1]=='h'){
					strcpy(reg,"110");
					//reg = 110;
				Display(opcode, d, w, mod, reg, reg_mem);
    }
				else{
					printf("wrong input\n");
			getch();	}
			}
			else if (source[0] == 'A' || source[0] == 'a')
			{
				if (source[1] == 'X' || source[1] == 'L' || source[1] == 'x' || source[1] == 'l')
				{
					strcpy(reg,"000");
	Display(opcode, d, w, mod, reg, reg_mem);
    				//reg = 000;
				}
				else if(source[1]=='H'||source[1]=='h'){
					strcpy(reg,"100");
	Display(opcode, d, w, mod, reg, reg_mem);
    				//reg = 100;
				}
	else{
		printf("wrong input\n");
	}
		getch();	}
				
			
			else if (source[0] == 'C' || source[0] == 'c')
			{
				if (source[1] == 'X' || source[1] == 'L' || source[1] == 'x' || source[1] == 'l')
				{
					strcpy(reg,"011");
				//	reg = 001;
				Display(opcode, d, w, mod, reg, reg_mem);
    
				}
				else if(source[1]=='H'||source[1]=='h'){
					strcpy(reg,"101");
Display(opcode, d, w, mod, reg, reg_mem);
    					//reg = 101;
				}
				else{
					printf("wrong input\n");
				getch();}
			}
			
}
	else{                               /////////////wrong register initials
		printf("wrong input\n");
	getch();}
	}
	else           //////////register null
	{
		printf("wrong input\n");
	getch();
	}

	//printf("\nwrong input\n");

if(source[0]=='[')
{
//if(source[2]=='X'&&dest[1]=='X'||source[2]=='x'&&dest[1]=='x'||source[1]!='B'&&dest[1]=='X'||source[1]!='b'&&dest[1]=='x')
  if(source+2!="\0")
{

	
	    strcpy(reg,"000");
	strcpy(d,"1");
	strcpy(mod,"00");
	strcpy(w,"1");
	if(source[1]=='B'||source[1]=='b')
	{
		if(source[2]=='X'||source[2]=='x')
		{

	    if(strlen(source)==4)
	    {
		strcpy(reg_mem,"111");
		}
		else if(source[4]=='S'||source[4]=='s')
		{
			strcpy(reg_mem,"000");
		}
		else if(source[4]=='D'||source[4]=='d')
		{
			strcpy(reg_mem,"001");
		}
		}
	Display(opcode, d, w, mod, reg, reg_mem);
	}
	else if(strlen(source)==6)
    {
	strcpy(reg_mem,"110");
    Display(opcode, d, w, mod, reg, reg_mem);
    }
    else
	{
	printf("wrong input\n");
   getch(); }

}
    else                          /////null memory source
	{
	printf("\nwrong input\n");
    getch();}
 }
}
else                                            ////wrong instruction
{
printf("\nwrong input\n");
getch();}
}



























 Display(char *opcode, char *d, char *w, char *mod, char *reg, char *reg_mem)
{	printf("-----------------------------------------------\n");
	printf("| OPCODE  |  D  |  W  |  MOD  |  REG  |  R/M  |\n");
	printf("|---------|-----|-----|-------|-------|-------|\n");
	printf("| %s  |  %s  |  %s  |  %s   |  %s  |  %s  |\n", opcode, d, w, mod, reg, reg_mem);
	printf("-----------------------------------------------\n");
getch();
main_menu();
}

SetValue6(char *instruction,char *dest,char *source)
{
	//printf("\n%s %s %s",instruction,source,dest);
	char opcode[10];
	char d[2], w[2];
	char mod[3];
	char reg[4];
	char reg_mem[4];
	if (strcmpi(instruction,"CMP") == 0)
	{
		
		//printf("\n%s %s %s",instruction,source,dest);
		strcpy(opcode,"111000");
		
	if (source[0] == 'A' || source[0] == 'B' || source[0] == 'C' || source[0] == 'D' || source[0] == 'S' || source[0] == 'a' || source[0] == 'b' || source[0] == 'c' || source[0] == 'd' || source[0] == 's')
{
			strcpy(d,"0");
			if (source[1] == 'X' || source[1] == 'I' || source[1] == 'P' || source[1] == 'x' || source[1] == 'i' || source[1] == 'p')
			{
		//		printf("2");
				strcpy(w,"1");
			}
			else{
		//		printf("3");
				strcpy(w,"0");
			}
			if (source[0] == 'B' || source[0] == 'b')
			{
		//		printf("4");
				if (source[1] == 'X' || source[1] == 'L' || source[1] == 'x' || source[1] == 'l')
				{
		            strcpy(reg,"011");
					//reg = 011;
				}
				else if (source[1] == 'P' || source[1] == 'p')
				{
					strcpy(reg,"101");
					//reg,101;
					//printf("6");
				}
				else{
					//printf("7");
					//reg = 111;
				strcpy(reg,"111");
				}
			}
			else if (source[0] == 'S'||source[0] == 's')
			{
				//printf("8");
				if (source[1] == 'P'|| source[1] == 'p')
				{
				//	printf("9");
				//	reg = 100;
				strcpy(reg,"100");
				}
				else{
					//printf("10");
					//reg = 110;
				strcpy(reg,"110");
				}
			}
			else if (source[0] == 'D' || source[0] == 'd')
			{
				if (source[1] == 'X' || source[1] == 'L' || source[1] == 'x' || source[1] == 'l')
				{
					strcpy(reg,"010");
					//reg = 010;
				}
				else if (source[1] == 'i' || source[1] == 'I')
				{
					strcpy(reg,"111");
					//reg = 111;
				}
				else{
					strcpy(reg,"110");
					//reg = 110;
				}
			}
			else if (source[0] == 'A' || source[0] == 'a')
			{
				if (source[1] == 'X' || source[1] == 'L' || source[1] == 'x' || source[1] == 'l')
				{
					strcpy(reg,"000");
					//reg = 000;
				}
				else{
					strcpy(reg,"100");
					//reg = 100;
				}
			}
			else if (source[0] == 'C' || source[0] == 'c')
			{
				if (source[1] == 'X' || source[1] == 'L' || source[1] == 'x' || source[1] == 'l')
				{
					strcpy(reg,"011");
				//	reg = 001;
				}
				else{
					strcpy(reg,"101");
					//reg = 101;
				}
			}
			
		///////////////////////////////////////////////////////dest starts
			if (dest[0] == '[')
			{
				//if(dest[1]!='B'&&source[1]=='X'||dest[1]!='b'&&source[1]=='x'||dest[2]=='X'&&source[1]=='X'||dest[2]=='x'&&source[1]=='x')
				//{
				
				strcpy(mod,"00");
	if(dest[1]=='B'||dest[1]=='b')
	{

		if(dest[2]=='X'||dest[2]=='x')
		{
			
	if(strlen(dest)==4)
	{
		strcpy(reg_mem,"111");
			}		
		else if(dest[4]=='S'||dest[4]=='s')
		{
			strcpy(reg_mem,"000");
		}
		else if(dest[4]=='D'||dest[4]=='d')
		{	
			strcpy(reg_mem,"001");
		}
		}}
	
	else{
		//printf("chaljaaaaaaaaa");
		strcpy(reg_mem,"110");
	}
		}
			else	//if(strcmpi(dest[0],"A")||strcmpi(dest[0],"B")||strcmpi(dest[0],"C")||strcmpi(dest[0],"D")||strcmpi(dest[0],"S")) 
			{
				strcpy(mod,"11");
			if (dest[0] == 'B'||dest[0] == 'b')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg_mem,"011");
				}
				else if (dest[1] == 'P' || dest[1] == 'p')
				{
					strcpy(reg_mem,"101");
					//reg_mem = 101;
				}
				else{
					strcpy(reg_mem,"111");
					//reg_mem = 111;
				}
			}
			else if ( dest[0] == 'S' || dest[0] == 's')
			{
				if ( dest[1] == 'P' || dest[1] == 'p')
				{
					strcpy(reg_mem,"100");
					//reg_mem = 100;
				}
				else{
					strcpy(reg_mem,"110");
					//reg_mem = 110;
				}
			}
			else if (dest[0] == 'D' || dest[0] == 'd')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg_mem,"010");
					//reg_mem = 010;
				}
				else if (dest[1] == 'I' || dest[1] == 'i')
				{
					strcpy(reg_mem,"111");
				//	reg_mem = 111;
				}
				else{
					strcpy(reg_mem,"110");
					//reg_mem = 110;
				}
			}
			else if (dest[0] == 'A' || dest[0] == 'a')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg_mem,"000");
					//reg_mem = 000;
				}
				else{
					strcpy(reg_mem,"100");
					//reg_mem = 100;
				}
			}
			else if (dest[0] == 'C' || dest[0] == 'c')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg_mem,"001");
					//reg_mem = 001;
				}
				else{
					strcpy(reg_mem,"101");
					//reg_mem = 101;
				}

		}
	}
			}
	
else if(source[0]=='[')
{
//if(source[2]=='X'&&dest[1]=='X'||source[2]=='x'&&dest[1]=='x'||source[1]!='B'&&dest[1]=='X'||source[1]!='b'&&dest[1]=='x')


	strcpy(d,"1");
	strcpy(mod,"00");
	strcpy(w,"1");
	
	if(source[1]=='B'||source[1]=='b')
	{
		if(source[2]=='X'||source[2]=='x')
		{
			
	if(strlen(source)==4)
	{
		strcpy(reg_mem,"111");
			}		
		else if(source[4]=='S'||source[4]=='s')
		{
			strcpy(reg_mem,"000");
		}
		else if(source[4]=='D'||source[4]=='d'){
			strcpy(reg_mem,"001");
		}
		}
	}
	else
{
	strcpy(reg_mem,"110");
}
	if (dest[0] == 'B'||dest[0] == 'b')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg,"011");
				}
				else if (dest[1] == 'P' || dest[1] == 'p')
				{
					strcpy(reg,"101");
					//reg = 101;
				}
				else{
					strcpy(reg,"111");
					//reg = 111;
				}
			}
			else if ( dest[0] == 'S' || dest[0] == 's')
			{
				if ( dest[1] == 'P' || dest[1] == 'p')
				{
					strcpy(reg,"100");
					//reg = 100;
				}
				else{
					strcpy(reg,"110");
					//reg = 110;
				}
			}
			else if (dest[0] == 'D' || dest[0] == 'd')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg,"010");
					//reg = 010;
				}
				else if (dest[1] == 'I' || dest[1] == 'i')
				{
					strcpy(reg,"111");
				//	reg = 111;
				}
				else{
					strcpy(reg,"110");
					//reg = 110;
				}
			}
			else if (dest[0] == 'A' || dest[0] == 'a')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg,"000");
					//reg = 000;
				}
				else{
					strcpy(reg,"100");
					//reg = 100;
				}
			}
			else if (dest[0] == 'C' || dest[0] == 'c')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg,"001");
					//reg = 001;
				}
				else{
					strcpy(reg,"101");
					//reg = 101;
				}

			}
			
			
			}
		}
	Display(opcode, d, w, mod, reg, reg_mem);
}
SetValue9(char *instruction,char *dest,char *source)
{
	//printf("\n%s %s %s",instruction,source,dest);
	char opcode[10];
	char d[2], w[2];
	char mod[3];
	char reg[4];
	char reg_mem[4];
	if (strcmpi(instruction,"OR") == 0)
	{
		
		//printf("\n%s %s %s",instruction,source,dest);
		strcpy(opcode,"110011");
		
	if (source[0] == 'A' || source[0] == 'B' || source[0] == 'C' || source[0] == 'D' || source[0] == 'S' || source[0] == 'a' || source[0] == 'b' || source[0] == 'c' || source[0] == 'd' || source[0] == 's')
{
			strcpy(d,"0");
			if (source[1] == 'X' || source[1] == 'I' || source[1] == 'P' || source[1] == 'x' || source[1] == 'i' || source[1] == 'p')
			{
		//		printf("2");
				strcpy(w,"1");
			}
			else{
		//		printf("3");
				strcpy(w,"0");
			}
			if (source[0] == 'B' || source[0] == 'b')
			{
		//		printf("4");
				if (source[1] == 'X' || source[1] == 'L' || source[1] == 'x' || source[1] == 'l')
				{
		            strcpy(reg,"011");
					//reg = 011;
				}
				else if (source[1] == 'P' || source[1] == 'p')
				{
					strcpy(reg,"101");
					//reg,101;
					//printf("6");
				}
				else{
					//printf("7");
					//reg = 111;
				strcpy(reg,"111");
				}
			}
			else if (source[0] == 'S'||source[0] == 's')
			{
				//printf("8");
				if (source[1] == 'P'|| source[1] == 'p')
				{
				//	printf("9");
				//	reg = 100;
				strcpy(reg,"100");
				}
				else{
					//printf("10");
					//reg = 110;
				strcpy(reg,"110");
				}
			}
			else if (source[0] == 'D' || source[0] == 'd')
			{
				if (source[1] == 'X' || source[1] == 'L' || source[1] == 'x' || source[1] == 'l')
				{
					strcpy(reg,"010");
					//reg = 010;
				}
				else if (source[1] == 'i' || source[1] == 'I')
				{
					strcpy(reg,"111");
					//reg = 111;
				}
				else{
					strcpy(reg,"110");
					//reg = 110;
				}
			}
			else if (source[0] == 'A' || source[0] == 'a')
			{
				if (source[1] == 'X' || source[1] == 'L' || source[1] == 'x' || source[1] == 'l')
				{
					strcpy(reg,"000");
					//reg = 000;
				}
				else{
					strcpy(reg,"100");
					//reg = 100;
				}
			}
			else if (source[0] == 'C' || source[0] == 'c')
			{
				if (source[1] == 'X' || source[1] == 'L' || source[1] == 'x' || source[1] == 'l')
				{
					strcpy(reg,"011");
				//	reg = 001;
				}
				else{
					strcpy(reg,"101");
					//reg = 101;
				}
			}
			
		///////////////////////////////////////////////////////dest starts
			if (dest[0] == '[')
			{
				//if(dest[1]!='B'&&source[1]=='X'||dest[1]!='b'&&source[1]=='x'||dest[2]=='X'&&source[1]=='X'||dest[2]=='x'&&source[1]=='x')
				//{
				
				strcpy(mod,"00");
	if(dest[1]=='B'||dest[1]=='b')
	{

		if(dest[2]=='X'||dest[2]=='x')
		{
			
	if(strlen(dest)==4)
	{
		strcpy(reg_mem,"111");
			}		
		else if(dest[4]=='S'||dest[4]=='s')
		{
			strcpy(reg_mem,"000");
		}
		else if(dest[4]=='D'||dest[4]=='d')
		{	
			strcpy(reg_mem,"001");
		}
		}}
	
	else{
		//printf("chaljaaaaaaaaa");
		strcpy(reg_mem,"110");
	}
		}
			else	//if(strcmpi(dest[0],"A")||strcmpi(dest[0],"B")||strcmpi(dest[0],"C")||strcmpi(dest[0],"D")||strcmpi(dest[0],"S")) 
			{
				strcpy(mod,"11");
			if (dest[0] == 'B'||dest[0] == 'b')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg_mem,"011");
				}
				else if (dest[1] == 'P' || dest[1] == 'p')
				{
					strcpy(reg_mem,"101");
					//reg_mem = 101;
				}
				else{
					strcpy(reg_mem,"111");
					//reg_mem = 111;
				}
			}
			else if ( dest[0] == 'S' || dest[0] == 's')
			{
				if ( dest[1] == 'P' || dest[1] == 'p')
				{
					strcpy(reg_mem,"100");
					//reg_mem = 100;
				}
				else{
					strcpy(reg_mem,"110");
					//reg_mem = 110;
				}
			}
			else if (dest[0] == 'D' || dest[0] == 'd')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg_mem,"010");
					//reg_mem = 010;
				}
				else if (dest[1] == 'I' || dest[1] == 'i')
				{
					strcpy(reg_mem,"111");
				//	reg_mem = 111;
				}
				else{
					strcpy(reg_mem,"110");
					//reg_mem = 110;
				}
			}
			else if (dest[0] == 'A' || dest[0] == 'a')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg_mem,"000");
					//reg_mem = 000;
				}
				else{
					strcpy(reg_mem,"100");
					//reg_mem = 100;
				}
			}
			else if (dest[0] == 'C' || dest[0] == 'c')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg_mem,"001");
					//reg_mem = 001;
				}
				else{
					strcpy(reg_mem,"101");
					//reg_mem = 101;
				}

		}
	}
			}
	
else if(source[0]=='[')
{
//if(source[2]=='X'&&dest[1]=='X'||source[2]=='x'&&dest[1]=='x'||source[1]!='B'&&dest[1]=='X'||source[1]!='b'&&dest[1]=='x')


	strcpy(d,"1");
	strcpy(mod,"00");
	strcpy(w,"1");
	
	if(source[1]=='B'||source[1]=='b')
	{
		if(source[2]=='X'||source[2]=='x')
		{
			
	if(strlen(source)==4)
	{
		strcpy(reg_mem,"111");
			}		
		else if(source[4]=='S'||source[4]=='s')
		{
			strcpy(reg_mem,"000");
		}
		else if(source[4]=='D'||source[4]=='d'){
			strcpy(reg_mem,"001");
		}
		}
	}
	else
{
	strcpy(reg_mem,"110");
}
	if (dest[0] == 'B'||dest[0] == 'b')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg,"011");
				}
				else if (dest[1] == 'P' || dest[1] == 'p')
				{
					strcpy(reg,"101");
					//reg = 101;
				}
				else{
					strcpy(reg,"111");
					//reg = 111;
				}
			}
			else if ( dest[0] == 'S' || dest[0] == 's')
			{
				if ( dest[1] == 'P' || dest[1] == 'p')
				{
					strcpy(reg,"100");
					//reg = 100;
				}
				else{
					strcpy(reg,"110");
					//reg = 110;
				}
			}
			else if (dest[0] == 'D' || dest[0] == 'd')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg,"010");
					//reg = 010;
				}
				else if (dest[1] == 'I' || dest[1] == 'i')
				{
					strcpy(reg,"111");
				//	reg = 111;
				}
				else{
					strcpy(reg,"110");
					//reg = 110;
				}
			}
			else if (dest[0] == 'A' || dest[0] == 'a')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg,"000");
					//reg = 000;
				}
				else{
					strcpy(reg,"100");
					//reg = 100;
				}
			}
			else if (dest[0] == 'C' || dest[0] == 'c')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg,"001");
					//reg = 001;
				}
				else{
					strcpy(reg,"101");
					//reg = 101;
				}

			}
			
			
			}
		}
	Display(opcode, d, w, mod, reg, reg_mem);
}
SetValue10(char *instruction,char *dest,char *source)
{
	//printf("\n%s %s %s",instruction,source,dest);
	char opcode[10];
	char d[2], w[2];
	char mod[3];
	char reg[4];
	char reg_mem[4];
	if (strcmpi(instruction,"XOR") == 0)
	{
		
		//printf("\n%s %s %s",instruction,source,dest);
		strcpy(opcode,"100001");
		
	if (source[0] == 'A' || source[0] == 'B' || source[0] == 'C' || source[0] == 'D' || source[0] == 'S' || source[0] == 'a' || source[0] == 'b' || source[0] == 'c' || source[0] == 'd' || source[0] == 's')
{
			strcpy(d,"0");
			if (source[1] == 'X' || source[1] == 'I' || source[1] == 'P' || source[1] == 'x' || source[1] == 'i' || source[1] == 'p')
			{
		//		printf("2");
				strcpy(w,"1");
			}
			else{
		//		printf("3");
				strcpy(w,"0");
			}
			if (source[0] == 'B' || source[0] == 'b')
			{
		//		printf("4");
				if (source[1] == 'X' || source[1] == 'L' || source[1] == 'x' || source[1] == 'l')
				{
		            strcpy(reg,"011");
					//reg = 011;
				}
				else if (source[1] == 'P' || source[1] == 'p')
				{
					strcpy(reg,"101");
					//reg,101;
					//printf("6");
				}
				else{
					//printf("7");
					//reg = 111;
				strcpy(reg,"111");
				}
			}
			else if (source[0] == 'S'||source[0] == 's')
			{
				//printf("8");
				if (source[1] == 'P'|| source[1] == 'p')
				{
				//	printf("9");
				//	reg = 100;
				strcpy(reg,"100");
				}
				else{
					//printf("10");
					//reg = 110;
				strcpy(reg,"110");
				}
			}
			else if (source[0] == 'D' || source[0] == 'd')
			{
				if (source[1] == 'X' || source[1] == 'L' || source[1] == 'x' || source[1] == 'l')
				{
					strcpy(reg,"010");
					//reg = 010;
				}
				else if (source[1] == 'i' || source[1] == 'I')
				{
					strcpy(reg,"111");
					//reg = 111;
				}
				else{
					strcpy(reg,"110");
					//reg = 110;
				}
			}
			else if (source[0] == 'A' || source[0] == 'a')
			{
				if (source[1] == 'X' || source[1] == 'L' || source[1] == 'x' || source[1] == 'l')
				{
					strcpy(reg,"000");
					//reg = 000;
				}
				else{
					strcpy(reg,"100");
					//reg = 100;
				}
			}
			else if (source[0] == 'C' || source[0] == 'c')
			{
				if (source[1] == 'X' || source[1] == 'L' || source[1] == 'x' || source[1] == 'l')
				{
					strcpy(reg,"011");
				//	reg = 001;
				}
				else{
					strcpy(reg,"101");
					//reg = 101;
				}
			}
			
		///////////////////////////////////////////////////////dest starts
			if (dest[0] == '[')
			{
				//if(dest[1]!='B'&&source[1]=='X'||dest[1]!='b'&&source[1]=='x'||dest[2]=='X'&&source[1]=='X'||dest[2]=='x'&&source[1]=='x')
				//{
				
				strcpy(mod,"00");
	if(dest[1]=='B'||dest[1]=='b')
	{

		if(dest[2]=='X'||dest[2]=='x')
		{
			
	if(strlen(dest)==4)
	{
		strcpy(reg_mem,"111");
			}		
		else if(dest[4]=='S'||dest[4]=='s')
		{
			strcpy(reg_mem,"000");
		}
		else if(dest[4]=='D'||dest[4]=='d')
		{	
			strcpy(reg_mem,"001");
		}
		}}
	
	else{
		//printf("chaljaaaaaaaaa");
		strcpy(reg_mem,"110");
	}
		}
			else	//if(strcmpi(dest[0],"A")||strcmpi(dest[0],"B")||strcmpi(dest[0],"C")||strcmpi(dest[0],"D")||strcmpi(dest[0],"S")) 
			{
				strcpy(mod,"11");
			if (dest[0] == 'B'||dest[0] == 'b')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg_mem,"011");
				}
				else if (dest[1] == 'P' || dest[1] == 'p')
				{
					strcpy(reg_mem,"101");
					//reg_mem = 101;
				}
				else{
					strcpy(reg_mem,"111");
					//reg_mem = 111;
				}
			}
			else if ( dest[0] == 'S' || dest[0] == 's')
			{
				if ( dest[1] == 'P' || dest[1] == 'p')
				{
					strcpy(reg_mem,"100");
					//reg_mem = 100;
				}
				else{
					strcpy(reg_mem,"110");
					//reg_mem = 110;
				}
			}
			else if (dest[0] == 'D' || dest[0] == 'd')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg_mem,"010");
					//reg_mem = 010;
				}
				else if (dest[1] == 'I' || dest[1] == 'i')
				{
					strcpy(reg_mem,"111");
				//	reg_mem = 111;
				}
				else{
					strcpy(reg_mem,"110");
					//reg_mem = 110;
				}
			}
			else if (dest[0] == 'A' || dest[0] == 'a')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg_mem,"000");
					//reg_mem = 000;
				}
				else{
					strcpy(reg_mem,"100");
					//reg_mem = 100;
				}
			}
			else if (dest[0] == 'C' || dest[0] == 'c')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg_mem,"001");
					//reg_mem = 001;
				}
				else{
					strcpy(reg_mem,"101");
					//reg_mem = 101;
				}

		}
	}
			}
	
else if(source[0]=='[')
{
//if(source[2]=='X'&&dest[1]=='X'||source[2]=='x'&&dest[1]=='x'||source[1]!='B'&&dest[1]=='X'||source[1]!='b'&&dest[1]=='x')


	strcpy(d,"1");
	strcpy(mod,"00");
	strcpy(w,"1");
	
	if(source[1]=='B'||source[1]=='b')
	{
		if(source[2]=='X'||source[2]=='x')
		{
			
	if(strlen(source)==4)
	{
		strcpy(reg_mem,"111");
			}		
		else if(source[4]=='S'||source[4]=='s')
		{
			strcpy(reg_mem,"000");
		}
		else if(source[4]=='D'||source[4]=='d'){
			strcpy(reg_mem,"001");
		}
		}
	}
	else
{
	strcpy(reg_mem,"110");
}
	if (dest[0] == 'B'||dest[0] == 'b')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg,"011");
				}
				else if (dest[1] == 'P' || dest[1] == 'p')
				{
					strcpy(reg,"101");
					//reg = 101;
				}
				else{
					strcpy(reg,"111");
					//reg = 111;
				}
			}
			else if ( dest[0] == 'S' || dest[0] == 's')
			{
				if ( dest[1] == 'P' || dest[1] == 'p')
				{
					strcpy(reg,"100");
					//reg = 100;
				}
				else{
					strcpy(reg,"110");
					//reg = 110;
				}
			}
			else if (dest[0] == 'D' || dest[0] == 'd')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg,"010");
					//reg = 010;
				}
				else if (dest[1] == 'I' || dest[1] == 'i')
				{
					strcpy(reg,"111");
				//	reg = 111;
				}
				else{
					strcpy(reg,"110");
					//reg = 110;
				}
			}
			else if (dest[0] == 'A' || dest[0] == 'a')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg,"000");
					//reg = 000;
				}
				else{
					strcpy(reg,"100");
					//reg = 100;
				}
			}
			else if (dest[0] == 'C' || dest[0] == 'c')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg,"001");
					//reg = 001;
				}
				else{
					strcpy(reg,"101");
					//reg = 101;
				}

			}
			
			
			}
		}
	Display(opcode, d, w, mod, reg, reg_mem);
}

SetValue11(char *instruction,char *dest,char *source)
{
	//printf("\n%s %s %s",instruction,source,dest);
	char opcode[10];
	char d[2], w[2];
	char mod[3];
	char reg[4];
	char reg_mem[4];
	if (strcmpi(instruction,"MVI") == 0)
	{
		
		//printf("\n%s %s %s",instruction,source,dest);
		strcpy(opcode,"100110");
		strcpy(d,"0");
        strcpy(reg_mem,"110");
        strcpy(mod,"00");
	if (dest[0] == 'A' || dest[0] == 'B' || dest[0] == 'C' || dest[0] == 'D' || dest[0] == 'S' ||dest[0] == 'a' || dest[0] == 'b' || dest[0] == 'c' || dest[0] == 'd' || dest[0] == 's')
{
		if (dest[1] == 'X' || dest[1] == 'I' || dest[1] == 'P' || dest[1] == 'x' || dest[1] == 'i' || dest[1] == 'p')
			{
		//		printf("2");
				strcpy(w,"1");
			}
			else{
		//		printf("3");
				strcpy(w,"0");
			}
			if (dest[0] == 'B' || dest[0] == 'b')
			{
		//		printf("4");
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
		            strcpy(reg,"011");
					//reg = 011;
				}
				else if (dest[1] == 'P' || dest[1] == 'p')
				{
					strcpy(reg,"101");
					//reg,101;
					//printf("6");
				}
				else{
					//printf("7");
					//reg = 111;
				strcpy(reg,"111");
				}
			}
			else if (dest[0] == 'S'||dest[0] == 's')
			{
				//printf("8");
				if (dest[1] == 'P'|| dest[1] == 'p')
				{
				//	printf("9");
				//	reg = 100;
				strcpy(reg,"100");
				}
				else{
					//printf("10");
					//reg = 110;
				strcpy(reg,"110");
				}
			}
			else if (dest[0] == 'D' || dest[0] == 'd')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg,"010");
					//reg = 010;
				}
				else if (dest[1] == 'i' || dest[1] == 'I')
				{
					strcpy(reg,"111");
					//reg = 111;
				}
				else{
					strcpy(reg,"110");
					//reg = 110;
				}
			}
			else if (dest[0] == 'A' || dest[0] == 'a')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg,"000");
					//reg = 000;
				}
				else{
					strcpy(reg,"100");
					//reg = 100;
				}
			}
			else if (dest[0] == 'C' || dest[0] == 'c')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg,"011");
				//	reg = 001;
				}
				else{
					strcpy(reg,"101");
					//reg = 101;
				}
			}
		}
}
	Display(opcode, d, w, mod, reg, reg_mem);
}

SetValue7(char *instruction,char *dest,char *source)
{
	//printf("\n%s %s %s",instruction,source,dest);
	char opcode[10];
	char d[2], w[2];
	char mod[3];
	char reg[4];
	char reg_mem[4];
	if (strcmpi(instruction,"XCHG") == 0)
	{

		//printf("\n%s %s %s",instruction,source,dest);
		strcpy(opcode,"101010");

	if (source[0] == 'A' || source[0] == 'B' || source[0] == 'C' || source[0] == 'D' || source[0] == 'S' || source[0] == 'a' || source[0] == 'b' || source[0] == 'c' || source[0] == 'd' || source[0] == 's')
{
			strcpy(d,"0");
			if (source[1] == 'X' || source[1] == 'I' || source[1] == 'P' || source[1] == 'x' || source[1] == 'i' || source[1] == 'p')
			{
		//		printf("2");
				strcpy(w,"1");
			}
			else{
		//		printf("3");
				strcpy(w,"0");
			}
			if (source[0] == 'B' || source[0] == 'b')
			{
		//		printf("4");
				if (source[1] == 'X' || source[1] == 'L' || source[1] == 'x' || source[1] == 'l')
				{
		            strcpy(reg,"011");
					//reg = 011;
				}
				else if (source[1] == 'P' || source[1] == 'p')
				{
					strcpy(reg,"101");
					//reg,101;
					//printf("6");
				}
				else{
					//printf("7");
					//reg = 111;
				strcpy(reg,"111");
				}
			}
			else if (source[0] == 'S'||source[0] == 's')
			{
				//printf("8");
				if (source[1] == 'P'|| source[1] == 'p')
				{
				//	printf("9");
				//	reg = 100;
				strcpy(reg,"100");
				}
				else{
					//printf("10");
					//reg = 110;
				strcpy(reg,"110");
				}
			}
			else if (source[0] == 'D' || source[0] == 'd')
			{
				if (source[1] == 'X' || source[1] == 'L' || source[1] == 'x' || source[1] == 'l')
				{
					strcpy(reg,"010");
					//reg = 010;
				}
				else if (source[1] == 'i' || source[1] == 'I')
				{
					strcpy(reg,"111");
					//reg = 111;
				}
				else{
					strcpy(reg,"110");
					//reg = 110;
				}
			}
			else if (source[0] == 'A' || source[0] == 'a')
			{
				if (source[1] == 'X' || source[1] == 'L' || source[1] == 'x' || source[1] == 'l')
				{
					strcpy(reg,"000");
					//reg = 000;
				}
				else{
					strcpy(reg,"100");
					//reg = 100;
				}
			}
			else if (source[0] == 'C' || source[0] == 'c')
			{
				if (source[1] == 'X' || source[1] == 'L' || source[1] == 'x' || source[1] == 'l')
				{
					strcpy(reg,"011");
				//	reg = 001;
				}
				else{
					strcpy(reg,"101");
					//reg = 101;
				}
			}
			
		///////////////////////////////////////////////////////dest starts
			if (dest[0] == '[')
			{
				//if(dest[1]!='B'&&source[1]=='X'||dest[1]!='b'&&source[1]=='x'||dest[2]=='X'&&source[1]=='X'||dest[2]=='x'&&source[1]=='x')
				//{
				
				strcpy(mod,"00");
	if(dest[1]=='B'||dest[1]=='b')
	{

		if(dest[2]=='X'||dest[2]=='x')
		{
			
	if(strlen(dest)==4)
	{
		strcpy(reg_mem,"111");
			}		
		else if(dest[4]=='S'||dest[4]=='s')
		{
			strcpy(reg_mem,"000");
		}
		else if(dest[4]=='D'||dest[4]=='d')
		{	
			strcpy(reg_mem,"001");
		}
		}}
	
	else{
		//printf("chaljaaaaaaaaa");
		strcpy(reg_mem,"110");
	}
		}
			else	//if(strcmpi(dest[0],"A")||strcmpi(dest[0],"B")||strcmpi(dest[0],"C")||strcmpi(dest[0],"D")||strcmpi(dest[0],"S")) 
			{
				strcpy(mod,"11");
			if (dest[0] == 'B'||dest[0] == 'b')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg_mem,"011");
				}
				else if (dest[1] == 'P' || dest[1] == 'p')
				{
					strcpy(reg_mem,"101");
					//reg_mem = 101;
				}
				else{
					strcpy(reg_mem,"111");
					//reg_mem = 111;
				}
			}
			else if ( dest[0] == 'S' || dest[0] == 's')
			{
				if ( dest[1] == 'P' || dest[1] == 'p')
				{
					strcpy(reg_mem,"100");
					//reg_mem = 100;
				}
				else{
					strcpy(reg_mem,"110");
					//reg_mem = 110;
				}
			}
			else if (dest[0] == 'D' || dest[0] == 'd')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg_mem,"010");
					//reg_mem = 010;
				}
				else if (dest[1] == 'I' || dest[1] == 'i')
				{
					strcpy(reg_mem,"111");
				//	reg_mem = 111;
				}
				else{
					strcpy(reg_mem,"110");
					//reg_mem = 110;
				}
			}
			else if (dest[0] == 'A' || dest[0] == 'a')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg_mem,"000");
					//reg_mem = 000;
				}
				else{
					strcpy(reg_mem,"100");
					//reg_mem = 100;
				}
			}
			else if (dest[0] == 'C' || dest[0] == 'c')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg_mem,"001");
					//reg_mem = 001;
				}
				else{
					strcpy(reg_mem,"101");
					//reg_mem = 101;
				}

		}
	}
			}
	
else if(source[0]=='[')
{
//if(source[2]=='X'&&dest[1]=='X'||source[2]=='x'&&dest[1]=='x'||source[1]!='B'&&dest[1]=='X'||source[1]!='b'&&dest[1]=='x')


	strcpy(d,"1");
	strcpy(mod,"00");
	strcpy(w,"1");
	
	if(source[1]=='B'||source[1]=='b')
	{
		if(source[2]=='X'||source[2]=='x')
		{
			
	if(strlen(source)==4)
	{
		strcpy(reg_mem,"111");
			}		
		else if(source[4]=='S'||source[4]=='s')
		{
			strcpy(reg_mem,"000");
		}
		else if(source[4]=='D'||source[4]=='d'){
			strcpy(reg_mem,"001");
		}
		}
	}
	else
{
	strcpy(reg_mem,"110");
}
	if (dest[0] == 'B'||dest[0] == 'b')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg,"011");
				}
				else if (dest[1] == 'P' || dest[1] == 'p')
				{
					strcpy(reg,"101");
					//reg = 101;
				}
				else{
					strcpy(reg,"111");
					//reg = 111;
				}
			}
			else if ( dest[0] == 'S' || dest[0] == 's')
			{
				if ( dest[1] == 'P' || dest[1] == 'p')
				{
					strcpy(reg,"100");
					//reg = 100;
				}
				else{
					strcpy(reg,"110");
					//reg = 110;
				}
			}
			else if (dest[0] == 'D' || dest[0] == 'd')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg,"010");
					//reg = 010;
				}
				else if (dest[1] == 'I' || dest[1] == 'i')
				{
					strcpy(reg,"111");
				//	reg = 111;
				}
				else{
					strcpy(reg,"110");
					//reg = 110;
				}
			}
			else if (dest[0] == 'A' || dest[0] == 'a')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg,"000");
					//reg = 000;
				}
				else{
					strcpy(reg,"100");
					//reg = 100;
				}
			}
			else if (dest[0] == 'C' || dest[0] == 'c')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg,"001");
					//reg = 001;
				}
				else{
					strcpy(reg,"101");
					//reg = 101;
				}

			}
			
			
			}
		}
	Display(opcode, d, w, mod, reg, reg_mem);
}

SetValue8(char *instruction,char *dest,char *source)
{
	//printf("\n%s %s %s",instruction,source,dest);
	char opcode[10];
	char d[2], w[2];
	char mod[3];
	char reg[4];
	char reg_mem[4];
	if (strcmpi(instruction,"AND") == 0)
	{
		
		//printf("\n%s %s %s",instruction,source,dest);
		strcpy(opcode,"101100");
		
	if (source[0] == 'A' || source[0] == 'B' || source[0] == 'C' || source[0] == 'D' || source[0] == 'S' || source[0] == 'a' || source[0] == 'b' || source[0] == 'c' || source[0] == 'd' || source[0] == 's')
{
			strcpy(d,"0");
			if (source[1] == 'X' || source[1] == 'I' || source[1] == 'P' || source[1] == 'x' || source[1] == 'i' || source[1] == 'p')
			{
		//		printf("2");
				strcpy(w,"1");
			}
			else{
		//		printf("3");
				strcpy(w,"0");
			}
			if (source[0] == 'B' || source[0] == 'b')
			{
		//		printf("4");
				if (source[1] == 'X' || source[1] == 'L' || source[1] == 'x' || source[1] == 'l')
				{
		            strcpy(reg,"011");
					//reg = 011;
				}
				else if (source[1] == 'P' || source[1] == 'p')
				{
					strcpy(reg,"101");
					//reg,101;
					//printf("6");
				}
				else{
					//printf("7");
					//reg = 111;
				strcpy(reg,"111");
				}
			}
			else if (source[0] == 'S'||source[0] == 's')
			{
				//printf("8");
				if (source[1] == 'P'|| source[1] == 'p')
				{
				//	printf("9");
				//	reg = 100;
				strcpy(reg,"100");
				}
				else{
					//printf("10");
					//reg = 110;
				strcpy(reg,"110");
				}
			}
			else if (source[0] == 'D' || source[0] == 'd')
			{
				if (source[1] == 'X' || source[1] == 'L' || source[1] == 'x' || source[1] == 'l')
				{
					strcpy(reg,"010");
					//reg = 010;
				}
				else if (source[1] == 'i' || source[1] == 'I')
				{
					strcpy(reg,"111");
					//reg = 111;
				}
				else{
					strcpy(reg,"110");
					//reg = 110;
				}
			}
			else if (source[0] == 'A' || source[0] == 'a')
			{
				if (source[1] == 'X' || source[1] == 'L' || source[1] == 'x' || source[1] == 'l')
				{
					strcpy(reg,"000");
					//reg = 000;
				}
				else{
					strcpy(reg,"100");
					//reg = 100;
				}
			}
			else if (source[0] == 'C' || source[0] == 'c')
			{
				if (source[1] == 'X' || source[1] == 'L' || source[1] == 'x' || source[1] == 'l')
				{
					strcpy(reg,"011");
				//	reg = 001;
				}
				else{
					strcpy(reg,"101");
					//reg = 101;
				}
			}
			
		///////////////////////////////////////////////////////dest starts
			if (dest[0] == '[')
			{
				//if(dest[1]!='B'&&source[1]=='X'||dest[1]!='b'&&source[1]=='x'||dest[2]=='X'&&source[1]=='X'||dest[2]=='x'&&source[1]=='x')
				//{
				
				strcpy(mod,"00");
	if(dest[1]=='B'||dest[1]=='b')
	{

		if(dest[2]=='X'||dest[2]=='x')
		{
			
	if(strlen(dest)==4)
	{
		strcpy(reg_mem,"111");
			}		
		else if(dest[4]=='S'||dest[4]=='s')
		{
			strcpy(reg_mem,"000");
		}
		else if(dest[4]=='D'||dest[4]=='d')
		{	
			strcpy(reg_mem,"001");
		}
		}}
	
	else{
		//printf("chaljaaaaaaaaa");
		strcpy(reg_mem,"110");
	}
		}
			else	//if(strcmpi(dest[0],"A")||strcmpi(dest[0],"B")||strcmpi(dest[0],"C")||strcmpi(dest[0],"D")||strcmpi(dest[0],"S")) 
			{
				strcpy(mod,"11");
			if (dest[0] == 'B'||dest[0] == 'b')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg_mem,"011");
				}
				else if (dest[1] == 'P' || dest[1] == 'p')
				{
					strcpy(reg_mem,"101");
					//reg_mem = 101;
				}
				else{
					strcpy(reg_mem,"111");
					//reg_mem = 111;
				}
			}
			else if ( dest[0] == 'S' || dest[0] == 's')
			{
				if ( dest[1] == 'P' || dest[1] == 'p')
				{
					strcpy(reg_mem,"100");
					//reg_mem = 100;
				}
				else{
					strcpy(reg_mem,"110");
					//reg_mem = 110;
				}
			}
			else if (dest[0] == 'D' || dest[0] == 'd')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg_mem,"010");
					//reg_mem = 010;
				}
				else if (dest[1] == 'I' || dest[1] == 'i')
				{
					strcpy(reg_mem,"111");
				//	reg_mem = 111;
				}
				else{
					strcpy(reg_mem,"110");
					//reg_mem = 110;
				}
			}
			else if (dest[0] == 'A' || dest[0] == 'a')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg_mem,"000");
					//reg_mem = 000;
				}
				else{
					strcpy(reg_mem,"100");
					//reg_mem = 100;
				}
			}
			else if (dest[0] == 'C' || dest[0] == 'c')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg_mem,"001");
					//reg_mem = 001;
				}
				else{
					strcpy(reg_mem,"101");
					//reg_mem = 101;
				}

		}
	}
			}
	
else if(source[0]=='[')
{
//if(source[2]=='X'&&dest[1]=='X'||source[2]=='x'&&dest[1]=='x'||source[1]!='B'&&dest[1]=='X'||source[1]!='b'&&dest[1]=='x')


	strcpy(d,"1");
	strcpy(mod,"00");
	strcpy(w,"1");
	
	if(source[1]=='B'||source[1]=='b')
	{
		if(source[2]=='X'||source[2]=='x')
		{
			
	if(strlen(source)==4)
	{
		strcpy(reg_mem,"111");
			}		
		else if(source[4]=='S'||source[4]=='s')
		{
			strcpy(reg_mem,"000");
		}
		else if(source[4]=='D'||source[4]=='d'){
			strcpy(reg_mem,"001");
		}
		}
	}
	else
{
	strcpy(reg_mem,"110");
}
	if (dest[0] == 'B'||dest[0] == 'b')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg,"011");
				}
				else if (dest[1] == 'P' || dest[1] == 'p')
				{
					strcpy(reg,"101");
					//reg = 101;
				}
				else{
					strcpy(reg,"111");
					//reg = 111;
				}
			}
			else if ( dest[0] == 'S' || dest[0] == 's')
			{
				if ( dest[1] == 'P' || dest[1] == 'p')
				{
					strcpy(reg,"100");
					//reg = 100;
				}
				else{
					strcpy(reg,"110");
					//reg = 110;
				}
			}
			else if (dest[0] == 'D' || dest[0] == 'd')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg,"010");
					//reg = 010;
				}
				else if (dest[1] == 'I' || dest[1] == 'i')
				{
					strcpy(reg,"111");
				//	reg = 111;
				}
				else{
					strcpy(reg,"110");
					//reg = 110;
				}
			}
			else if (dest[0] == 'A' || dest[0] == 'a')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg,"000");
					//reg = 000;
				}
				else{
					strcpy(reg,"100");
					//reg = 100;
				}
			}
			else if (dest[0] == 'C' || dest[0] == 'c')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg,"001");
					//reg = 001;
				}
				else{
					strcpy(reg,"101");
					//reg = 101;
				}

			}
			
			
			}
		}
	Display(opcode, d, w, mod, reg, reg_mem);
}

SetValue(char *instruction,char *dest,char *source)
{
	//printf("\n%s %s %s",instruction,source,dest);
	char opcode[10];
	char d[2], w[2];
	char mod[3];
	char reg[4];
	char reg_mem[4];
	if (strcmpi(instruction,"MOV") == 0)
	{
		
		//printf("\n%s %s %s",instruction,source,dest);
		strcpy(opcode,"100010");
		//	printf("0");
	      //	int i = 0;
		//printf("%c", source[0]);
	if (source[0] == 'A' || source[0] == 'B' || source[0] == 'C' || source[0] == 'D' || source[0] == 'S' || source[0] == 'a' || source[0] == 'b' || source[0] == 'c' || source[0] == 'd' || source[0] == 's')
{
			strcpy(d,"0");
			if (source[1] == 'X' || source[1] == 'I' || source[1] == 'P' || source[1] == 'x' || source[1] == 'i' || source[1] == 'p')
			{
		//		printf("2");
				strcpy(w,"1");
			}
			else{
		//		printf("3");
				strcpy(w,"0");
			}
			if (source[0] == 'B' || source[0] == 'b')
			{
		//		printf("4");
				if (source[1] == 'X' || source[1] == 'L' || source[1] == 'x' || source[1] == 'l')
				{
		            strcpy(reg,"011");
					//reg = 011;
				}
				else if (source[1] == 'P' || source[1] == 'p')
				{
					strcpy(reg,"101");
					//reg,101;
					//printf("6");
				}
				else{
					//printf("7");
					//reg = 111;
				strcpy(reg,"111");
				}
			}
			else if (source[0] == 'S'||source[0] == 's')
			{
				//printf("8");
				if (source[1] == 'P'|| source[1] == 'p')
				{
				//	printf("9");
				//	reg = 100;
				strcpy(reg,"100");
				}
				else{
					//printf("10");
					//reg = 110;
				strcpy(reg,"110");
				}
			}
			else if (source[0] == 'D' || source[0] == 'd')
			{
				if (source[1] == 'X' || source[1] == 'L' || source[1] == 'x' || source[1] == 'l')
				{
					strcpy(reg,"010");
					//reg = 010;
				}
				else if (source[1] == 'i' || source[1] == 'I')
				{
					strcpy(reg,"111");
					//reg = 111;
				}
				else{
					strcpy(reg,"110");
					//reg = 110;
				}
			}
			else if (source[0] == 'A' || source[0] == 'a')
			{
				if (source[1] == 'X' || source[1] == 'L' || source[1] == 'x' || source[1] == 'l')
				{
					strcpy(reg,"000");
					//reg = 000;
				}
				else{
					strcpy(reg,"100");
					//reg = 100;
				}
			}
			else if (source[0] == 'C' || source[0] == 'c')
			{
				if (source[1] == 'X' || source[1] == 'L' || source[1] == 'x' || source[1] == 'l')
				{
					strcpy(reg,"011");
				//	reg = 001;
				}
				else{
					strcpy(reg,"101");
					//reg = 101;
				}
			}
			
		///////////////////////////////////////////////////////dest starts
			if (dest[0] == '[')
			{
				//if(dest[1]!='B'&&source[1]=='X'||dest[1]!='b'&&source[1]=='x'||dest[2]=='X'&&source[1]=='X'||dest[2]=='x'&&source[1]=='x')
				//{
				
				strcpy(mod,"00");
	if(dest[1]=='B'||dest[1]=='b')
	{

		if(dest[2]=='X'||dest[2]=='x')
		{
			
	if(strlen(dest)==4)
	{
		strcpy(reg_mem,"111");
			}		
		else if(dest[4]=='S'||dest[4]=='s')
		{
			strcpy(reg_mem,"000");
		}
		else if(dest[4]=='D'||dest[4]=='d')
		{	
			strcpy(reg_mem,"001");
		}
		}}
	
	else{
		//printf("chaljaaaaaaaaa");
		strcpy(reg_mem,"110");
	}
		}
			else	//if(strcmpi(dest[0],"A")||strcmpi(dest[0],"B")||strcmpi(dest[0],"C")||strcmpi(dest[0],"D")||strcmpi(dest[0],"S")) 
			{
				strcpy(mod,"11");
			if (dest[0] == 'B'||dest[0] == 'b')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg_mem,"011");
				}
				else if (dest[1] == 'P' || dest[1] == 'p')
				{
					strcpy(reg_mem,"101");
					//reg_mem = 101;
				}
				else{
					strcpy(reg_mem,"111");
					//reg_mem = 111;
				}
			}
			else if ( dest[0] == 'S' || dest[0] == 's')
			{
				if ( dest[1] == 'P' || dest[1] == 'p')
				{
					strcpy(reg_mem,"100");
					//reg_mem = 100;
				}
				else{
					strcpy(reg_mem,"110");
					//reg_mem = 110;
				}
			}
			else if (dest[0] == 'D' || dest[0] == 'd')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg_mem,"010");
					//reg_mem = 010;
				}
				else if (dest[1] == 'I' || dest[1] == 'i')
				{
					strcpy(reg_mem,"111");
				//	reg_mem = 111;
				}
				else{
					strcpy(reg_mem,"110");
					//reg_mem = 110;
				}
			}
			else if (dest[0] == 'A' || dest[0] == 'a')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg_mem,"000");
					//reg_mem = 000;
				}
				else{
					strcpy(reg_mem,"100");
					//reg_mem = 100;
				}
			}
			else if (dest[0] == 'C' || dest[0] == 'c')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg_mem,"001");
					//reg_mem = 001;
				}
				else{
					strcpy(reg_mem,"101");
					//reg_mem = 101;
				}

		}
	}
			}
	
else if(source[0]=='[')
{
//if(source[2]=='X'&&dest[1]=='X'||source[2]=='x'&&dest[1]=='x'||source[1]!='B'&&dest[1]=='X'||source[1]!='b'&&dest[1]=='x')


	strcpy(d,"1");
	strcpy(mod,"00");
	strcpy(w,"1");
	
	if(source[1]=='B'||source[1]=='b')
	{
		if(source[2]=='X'||source[2]=='x')
		{
			
	if(strlen(source)==4)
	{
		strcpy(reg_mem,"111");
			}		
		else if(source[4]=='S'||source[4]=='s')
		{
			strcpy(reg_mem,"000");
		}
		else if(source[4]=='D'||source[4]=='d'){
			strcpy(reg_mem,"001");
		}
		}
	}
	else
{
	strcpy(reg_mem,"110");
}
	if (dest[0] == 'B'||dest[0] == 'b')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg,"011");
				}
				else if (dest[1] == 'P' || dest[1] == 'p')
				{
					strcpy(reg,"101");
					//reg = 101;
				}
				else{
					strcpy(reg,"111");
					//reg = 111;
				}
			}
			else if ( dest[0] == 'S' || dest[0] == 's')
			{
				if ( dest[1] == 'P' || dest[1] == 'p')
				{
					strcpy(reg,"100");
					//reg = 100;
				}
				else{
					strcpy(reg,"110");
					//reg = 110;
				}
			}
			else if (dest[0] == 'D' || dest[0] == 'd')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg,"010");
					//reg = 010;
				}
				else if (dest[1] == 'I' || dest[1] == 'i')
				{
					strcpy(reg,"111");
				//	reg = 111;
				}
				else{
					strcpy(reg,"110");
					//reg = 110;
				}
			}
			else if (dest[0] == 'A' || dest[0] == 'a')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg,"000");
					//reg = 000;
				}
				else{
					strcpy(reg,"100");
					//reg = 100;
				}
			}
			else if (dest[0] == 'C' || dest[0] == 'c')
			{
				if (dest[1] == 'X' || dest[1] == 'L' || dest[1] == 'x' || dest[1] == 'l')
				{
					strcpy(reg,"001");
					//reg = 001;
				}
				else{
					strcpy(reg,"101");
					//reg = 101;
				}

			}
			
			
			}
		}
	Display(opcode, d, w, mod, reg, reg_mem);
}


void display_screen()
{
	int choice;
	char instruct[12];
	char source[12];
	char dest[12];
	printf("Choose any 8086 Instruction\n");
	printf("\t----------\n");
	printf("\t|1.ADD\n\t|2.SUB\n\t|3.MUL\n\t|4.DIV\n\t|5.INC\n\t|6.CMP\n\t|7.MOV\n\t|8.MVI\n\t|9.XCHG\n\t|10.AND\n\t|11.OR\n\t|12.XOR\n");
	printf("\t----------\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
	printf("Enter the instruction\n");
	scanf("%s%s",instruct,source);
			SetValue1(instruct,source);
			break;
		case 2:
	printf("Enter the instruction\n");
	scanf("%s%s",instruct,source);
	
			SetValue2(instruct,source);
			break;
		case 3:
	printf("Enter the instruction\n");
	scanf("%s%s",instruct,source);
	
			SetValue3(instruct,source);
			break;
		case 4:
	printf("Enter the instruction\n");
	scanf("%s%s",instruct,source);
	
			SetValue4(instruct,source);
			break;
		case 5:
	printf("Enter the instruction\n");
	scanf("%s%s",instruct,source);
			SetValue5(instruct,source);
			break;
		case 6:
	printf("Enter the instruction\n");
	scanf("%s%s%s", instruct, dest, source);
	check6(instruct,dest,source);
			//SetValue6();
			break;
		case 7:
	printf("Enter the instruction\n");
	scanf("%s%s%s", instruct, dest, source);
	check(instruct,dest,source);
			//SetValue();
			break;
		case 8:
	printf("Enter the instruction\n");
	scanf("%s%s%s", instruct, dest, source);
	check11(instruct,dest,source);
			//SetValue();
			break;
		case 9:
	printf("Enter the instruction\n");
	scanf("%s%s%s", instruct, dest, source);
	check7(instruct,dest,source);
			//SetValue7();
			break;
		case 10:
	printf("Enter the instruction\n");
	scanf("%s%s%s", instruct, dest, source);
	
			SetValue8(instruct,dest,source);
			break;
		case 11:
	printf("Enter the instruction\n");
	scanf("%s%s%s", instruct, dest, source);
	check9(instruct,dest,source);
			//SetValue9();
			break;
		case 12:
			printf("Enter the instruction\n");
	scanf("%s%s%s", instruct, dest, source);
	check10(instruct,dest,source);
		//	SetValue10();
			break;
		default :
		printf("Enter the valid choice\n");
		break;
	}

}


//GRAPHICS START



main_menu()
  {
	char *menu[]={"ADD INSTRUCTION",
		"EXIT",
		};

	char ch;
	int gd=DETECT,gm,i,choice=0;
	initgraph(&gd,&gm,"..//BGI");
	setfillstyle(1,RED);
	bar(0,0,640,480);
	title("MAIN MENU",180);
	status();
	box(0,menu[0]);               //defined below
	box(1,menu[1]);              //makes a cuboid
	selectbox(choice,menu[choice]);

	//72  up
	//80  down
	//75  left
	//77  right
	//13  enter
	//49  1
	//71  Home
	//79  End
	//73 PgUp
	//81 PgDown
	//27 Escape



	while((ch=getch())!=13)    //GETCH RETURNS THE ASCII VALUE
	{
		switch(ch)
		{
		case 80:
		case 81:
		choice++;
		if(choice==2)
		choice=0;
		selectbox(choice,menu[choice]);
		for(i=0;i<=1;i++)
		{
		if(i==choice)
		continue;
		box(i,menu[i]);
		}
		break;
		case 72:
		case 73:
		choice--;
		if(choice==-1)
		choice=1;
		selectbox(choice,menu[choice]);
		for(i=0;i<=1;i++)
		{
		if(i==choice)
		continue;
		box(i,menu[i]);
		}
		}
	}

       pressbutton(choice,menu[choice]);

       switch(choice)
	  {
	    case 0:
		   //size=sizeof(ctr);     //ctr is object of customer
		   closegraph();
		   restorecrtmode();
		   display_screen();  //  TO BE MADE
		   //break;
	    case 1:
		   closegraph();
		   restorecrtmode();
		   exit(0);
	  }
  }
 screen1()
 {
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"..//BGI");
 setfillstyle(1,RED);
 bar(0,0,640,480);
 setfillstyle(1,WHITE);
 bar(15,15,625,465);
 setfillstyle(1,RED);
 bar(30,30,610,450);
 settextstyle(1,0,8);
 setcolor(WHITE);
 outtextxy(210,35,"COA");
 setfillstyle(1,LIGHTGRAY);
 bar3d(180,140,370,130,20,20);
 outtextxy(160,150,"PROJECT");
 bar3d(140,255,440,245,20,20);
 outtextxy(100,270,"SEMESTER 3");
 bar3d(115,375,520,365,20,20);
/* sleep(4);  */
getch();
 closegraph();
 restorecrtmode();
 }


 screen2()
 {
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"..//BGI");
 setfillstyle(1,RED);
 bar(0,0,640,480);
 setfillstyle(1,WHITE);
 bar(15,15,625,465);
 setfillstyle(1,RED);
 bar(30,30,610,450);
 setfillstyle(1,LIGHTGRAY);
 bar3d(160,80,540,360,25,25); /*members bar*/
 settextstyle(1,1,10);
 setcolor(WHITE);
 outtextxy(10,55,"JIIT");
 setfillstyle(1,LIGHTGRAY);
 bar3d(160,50,420,70,20,20);   /*project members bar*/
 bar3d(50,390,570,440,25,25);   //LRC
 setcolor(BLUE);
 settextstyle(1,0,3);
 outtextxy(175,400,"8086 INSTRUCTION DECODER");
 settextstyle(1,0,2);
 outtextxy(195,48,"PROJECT MEMBERS");


 outtextxy(193,110,"SHUBHAM DHINGRA   14103176");
 outtextxy(193,150,"NIRUPAM SHARMA    14103203");
 outtextxy(193,190,"ANIMESH TEWARI    14103202");
 outtextxy(193,230,"SANYA DESHMUKH    14103304");
outtextxy(193,270, "APOORVA JINDAL     14103173");
outtextxy(193,310, "PRATIGYA AGARAWAL  14103180");
getch();
 closegraph();
 restorecrtmode();
 }

 box(int i,char *p)
 {
 setfillstyle(1,WHITE);
 bar(179,108+55*i,409,138+55*i);
 setfillstyle(1,LIGHTGRAY);
 bar(180,110+55*i,410,140+55*i);
 setcolor(BLUE);
// setfillstyle(SOLID_FILL,BLUE);
 settextstyle(1,0,2);
 outtextxy(184,110+55*i,p);
/* getch();
 setfillstyle(SOLID_FILL,WHITE);
 bar(180,60,390,90);
 setfillstyle(SOLID_FILL,RED);
 bar(179,59,389,89); */


/* bar3d(180,100,420,300,-25,25);*/ /*members bar*/
/* closegraph();
 restorecrtmode(); */
 }



selectbox(int i,char *p)
 {
 setfillstyle(1,WHITE);
 bar(179,108+55*i,409,138+55*i);
 setfillstyle(1,9);            //9-LIGHTBLUE
 bar(180,110+55*i,410,140+55*i);
 setcolor(WHITE);
// setfillstyle(SOLID_FILL,BLUE);
 settextstyle(1,0,2);          //0-horizontal
 outtextxy(184,110+55*i,p);
/* getch();
 setfillstyle(SOLID_FILL,WHITE);
 bar(180,60,390,90);
 setfillstyle(SOLID_FILL,RED);
 bar(179,59,389,89); */

/* bar3d(180,100,420,300,-25,25);*/ /*members bar*/
/* closegraph();
 restorecrtmode(); */
 }

pressbutton(int i,char *p)
 {
 setfillstyle(1,WHITE);
 bar(180,110+55*i,410,140+55*i);
 setfillstyle(1,9);
 bar(179,108+55*i,409,138+55*i);
 setcolor(CYAN);
 settextstyle(1,0,2);
 outtextxy(184,110+55*i,p);
 delay(500);
 }
 title(char *title,int x)           //main menu in middle
 {
	setfillstyle(1,9);
	bar(0,0,640,50);
	setcolor(BLACK);     //boundary colour
	settextstyle(1,0,5);          //int(font,hor dir, char size)
	outtextxy(x,0,title);
 }
 status()                        //instructions to user
 {
	setfillstyle(1,9);
	bar(0,450,640,480);
	setcolor(BLACK);
	settextstyle(1,0,3);
	outtextxy(30,450,"USE UP AND DOWN ARROW KEYS TO SELECT AN OPTION");
 }
 
 
 
check6(char *instruction,char *dest,char *source)
{
if(dest[1]==source[1]||source[1]=='H'&&dest[1]=='L'||source[1]=='h'&&dest[1]=='l'||source[1]=='L'&&dest[1]=='H'||source[1]=='l'&&dest[1]=='h')
{
	SetValue6(instruction,dest,source);
	}	
else if(dest[1]=='X'&&source[0]=='['||dest[1]=='x'&&source[0]=='['||dest[0]=='['&&source[0]=='['||dest[0]=='['&&source[1]=='X'||dest[0]=='['&&source[1]=='x')
{
SetValue6(instruction,dest,source);	
	}	
	else
	{
		printf("Wrong input format\n");
		getch();
		main_menu();
	}
}




check7(char *instruction,char *dest,char *source)
{
if(dest[1]==source[1]||source[1]=='H'&&dest[1]=='L'||source[1]=='h'&&dest[1]=='l'||source[1]=='L'&&dest[1]=='H'||source[1]=='l'&&dest[1]=='h')
{
	SetValue7(instruction,dest,source);
	}	
else if(dest[1]=='X'&&source[0]=='['||dest[1]=='x'&&source[0]=='['||dest[0]=='['&&source[0]=='['||dest[0]=='['&&source[1]=='X'||dest[0]=='['&&source[1]=='x')
{
SetValue7(instruction,dest,source);	
	}	
	else
	{
		printf("Wrong input format\n");
		getch();
		main_menu();
	}
}



check8(char *instruction,char *dest,char *source)
{
if(dest[1]==source[1]||source[1]=='H'&&dest[1]=='L'||source[1]=='h'&&dest[1]=='l'||source[1]=='L'&&dest[1]=='H'||source[1]=='l'&&dest[1]=='h')
{
	SetValue8(instruction,dest,source);
	}	
else if(dest[1]=='X'&&source[0]=='['||dest[1]=='x'&&source[0]=='['||dest[0]=='['&&source[0]=='['||dest[0]=='['&&source[1]=='X'||dest[0]=='['&&source[1]=='x')
{
SetValue8(instruction,dest,source);	
	}	
	else
	{
		printf("Wrong input format\n");
		getch();
		main_menu();
	}
}



check9(char *instruction,char *dest,char *source)
{
if(dest[1]==source[1]||source[1]=='H'&&dest[1]=='L'||source[1]=='h'&&dest[1]=='l'||source[1]=='L'&&dest[1]=='H'||source[1]=='l'&&dest[1]=='h')
{
	SetValue9(instruction,dest,source);
	}	
else if(dest[1]=='X'&&source[0]=='['||dest[1]=='x'&&source[0]=='['||dest[0]=='['&&source[0]=='['||dest[0]=='['&&source[1]=='X'||dest[0]=='['&&source[1]=='x')
{
SetValue9(instruction,dest,source);	
	}	
	else
	{
		printf("Wrong input format\n");
		getch();
		main_menu();
	}
}


check10(char *instruction,char *dest,char *source)
{
if(dest[1]==source[1]||source[1]=='H'&&dest[1]=='L'||source[1]=='h'&&dest[1]=='l'||source[1]=='L'&&dest[1]=='H'||source[1]=='l'&&dest[1]=='h')
{
	SetValue10(instruction,dest,source);
	}	
else if(dest[1]=='X'&&source[0]=='['||dest[1]=='x'&&source[0]=='['||dest[0]=='['&&source[0]=='['||dest[0]=='['&&source[1]=='X'||dest[0]=='['&&source[1]=='x')
{
SetValue10(instruction,dest,source);	
	}	
	else
	{
		printf("Wrong input format\n");
		getch();
		main_menu();
	}
}


check11(char *instruction,char *dest,char *source)
{

if(strlen(source)==4&&dest[1]=='X'||strlen(source)==4&&dest[1]=='x')
{
	SetValue11(instruction,dest,source);
	}
	else if(strlen(source)==2&&dest[1]=='H'||strlen(source)==2&&dest[1]=='h'||strlen(source)==2&&dest[1]=='L'||strlen(source)==2&&dest[1]=='l')
{
	SetValue11(instruction,dest,source);
}
else
{
		printf("Wrong input format\n");
		getch();
		main_menu();
}
}



check(char *instruction,char *dest,char *source)
{
if(dest[1]==source[1]||source[1]=='H'&&dest[1]=='L'||source[1]=='h'&&dest[1]=='l'||source[1]=='L'&&dest[1]=='H'||source[1]=='l'&&dest[1]=='h')
{
	SetValue(instruction,dest,source);
	}
else if(dest[1]=='X'&&source[0]=='['||dest[1]=='x'&&source[0]=='['||dest[0]=='['&&source[0]=='['||dest[0]=='['&&source[1]=='X'||dest[0]=='['&&source[1]=='x')
{
SetValue(instruction,dest,source);
	}
	else
	{
		printf("Wrong input format\n");
		getch();
		main_menu();
	}
}




//INT MAIN
void main()
{
	screen1();
	screen2();
	main_menu();
       // return 0;
}
