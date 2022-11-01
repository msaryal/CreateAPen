#include<stdlib.h>
#include<locale.h>
#include<windows.h>
#include<conio.h>
#include<stdio.h>

struct COLOR
  {
  	int color1;          //���� 1
  	int color2;          //���� 2
  };

struct PENS
  {
  	float feather;       //������� ����
  	int ink;             //���
  	int cap;             //��������
  	COLOR Color;
  };

struct LIST
  {
  	PENS Pens;           //��������� �����
  	struct LIST* next;   //��������� �������
  	struct LIST* prev;   //���������� �������
  };


//----------------------------------------------------------------------------------------------------------
  //��������� �������:
  int menu();                             //�������� ������� �������� ����
  //---------------------����; ����������:-----------------------------------------------------
  LIST* input(LIST*);                     //�������� ������� �����
  LIST* inputField();                     //�������� ������� ���������� �������������� �����
  void inputNext(LIST**, int, LIST*);     //�������� ������� ���������� ��������� ���������
  LIST* addition(LIST *pen1);             //�������� ������� ���������� ���������
  //----------------------------�����:------------------------------------------------------
  void output (LIST*);                    //�������� ������� ������
  int controlOutput();                    //�������� ������� ������ ������
  //---------------------------�����:------------------------------------------------------
  LIST* search (LIST*);                   //�������� ������� ������ ���������
  float feat();                           //�������� ������� ����� ������� ������� ����
  int menu2();                            //�������� ������� �������
  int menu3();                            //�������� ������� �������
  int controlSearch();                    //�������� ������� ������ ������
  //---------------����������/��������������:---------------------------------------------------
  LIST* sort(LIST*);                      //�������� ������� ����������
  LIST* sortFirst(LIST*);                 //�������� ������� ���������� ������� ��������
  int controlSort();                      //�������� ������� ������ ������
  void editing(LIST*);                    //�������� ������� ��������������
  int controlEditing();                   //�������� ������� ������ ������ ��� ��������������
  //----------------------------��������:--------------------------------------------------
  LIST* deletion(LIST*);                  //�������� ������� ��������
  LIST* deletionFirst(LIST*);             //�������� ������� �������� ������� ��������
  void deletionNext(LIST*, int);          //�������� ������� �������� n-�� ��������
  LIST* delitionAll (LIST*);              //�������� ������� �������� ������
  int controlDeletion();                  //�������� ������� ������ ������
  //-------------------------������ � ������:----------------------------------------------
  int filing(LIST*, const char*, int*);    //�������� ������� ������ � ����
  const char* fileName(int);               //�������� ������� ����� ����� �����
  int readFile(LIST**, const char*, int);  //�������� ������� ����������� �����
  int controlFiling();                     //�������� ������� ������ ������ ��� ������
  //-------------------------------�����-----------------------------------------------------
  int amountElements(LIST*);               //�������� ������� ����������� ���������� ��������� � ������
  void info ();                            //�������� ������� ���������� � ���������
//----------------------------------------------------------------------------------------------------------------

int main()
  {
  	setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("mode con cols=100 lines=30");

    LIST *pen1=NULL, *pen2=NULL;
    int c, x, q=0;
    const char *name;
    info();
    system("pause");
    do
      {
      	c = menu();
      	switch(c)
      	  {
      	  	case 1:
      	  				pen1 = delitionAll(pen1);
      	  				pen1 = input(pen1);
      	  				break;
      	  	case 2:
      	  				if(pen1)
      	  				  pen1 = addition(pen1);
      	  				else
      	  				  puts("������ �� �������\n��� ����� ������ �������� 1-�� ����� ����");
      	  				system("pause");
      	  				break;

      	  	case 3:
      	  				if(pen1)
      	  				  {
      	  				  	x = controlDeletion();
      	  				  	if(x==1)
      	  				  	  pen1 = deletion(pen1);
      	  				  	else
      	  				  	  if(pen2&&x==2)
      	  				  	    pen2 = deletion(pen2);
      	  				  	  else
      	  				  	    if(x!=0)
      	  				  	    puts("����� ������ �� ����������, ��� �� ��� �����������\n��� ������ �������� ����� ���� 8");
      	  				  }
      	  				else
      	  				  puts("������ �� �������\n��� ����� ������ �������� 1-�� ����� ����");
      	  				system("pause");
      	  				break;

      	  	case 4:
      	  				  if(pen1)
      	  				    {
      	  				      x = controlOutput();
      	  				      if(x==1)
      	  				        output(pen1);
      	  				      else
      	  				        if(pen2 && x==2)
      	  				          output(pen2);
      	  				        else
      	  				          if(x!=0)
      	  				          puts("����� ������ �� ����������, ��� �� ��� �����������\n��� ������ �������� ����� ���� 8");
      	  				    }
      	  				   else
      	  				     puts("������ �� �������\n��� ����� ������ �������� 1-�� ����� ����");
      	  				system("pause");
      	  				break;
      	  	case 5:
      	  				if(pen1)
      	  				  {
      	  				  	x = controlEditing();
      	  				  	  if(x==1)
      	  				  	    {
      	  				  	      editing(pen1);
      	  				  	      puts("������ �������� �������");
      	  				  	    }
      	  				  	  else
      	  				  	    if(pen2 && x==2)
      	  				  	      {
      	  				  	        editing(pen2);
      	  				  	        puts("������ �������� �������");
      	  				  	      }
      	  				  	    else
      	  				  	      if(x!=0)
      	  				  	      puts("����� ������ �� ����������, ��� �� ��� �����������\n��� ������ �������� ����� ���� 8");
      	  				  }
      	  				  else
      	  				     puts("������ �� �������\n��� ����� ������ �������� 1-�� ����� ����");
      	  			 	system("pause");
      	  			 	break;
      	  	case 6:
      	  				if(pen1)
      	  				  {
      	  				  	x = controlFiling();
      	  				  	if(x==1)
      	  				  	  {
      	  				  	  	name = fileName(1);
      	  				        x = filing(pen1, name, &q);
      	  				  	  }
      	  				  	else
      	  				  	  if(pen2 && x==2)
      	  				  	    {
      	  				  	    	name = fileName(1);
      	  				        	x = filing(pen2, name, &q);
      	  				  	    }
      	  				  	if(x==1)
      	  				      puts("������ � ���� ������� ���������");
      	  				    else
      	  				      if(x==2)
      	  				        puts("������ ������ ����");
      	  				      else
      	  				        puts("������ � ���� �� �������");
      	  				  }
      	  				else
      	  				  puts("������ �� �������\n��� ����� ������ �������� 1-�� ����� ����");
      	  				system("pause");
      	  				break;

      	  	case 7:
      	  				system("cls");
      	  				  name = fileName(2);
      	  				  x = readFile(&pen1, name, q);
      	  				  if(x==1)
      	  				    puts("������ �������");
      	  				  if(x==2)
      	  				    puts("���� ����");
      	  				  if(x==3)
      	  				    puts("������ �� �������");
      	  				system("pause");
      	  				break;
      	  	case 8:
      	  				if(pen1)
      	  				  {
      	  				  	if (amountElements(pen1)+1>1)
      	  				  	  pen2=search(pen1);
      	  				  	else
      	  				  	  puts("��� ������ ����� ��� ������� ��� ��������\n��� ���������� ��������� �������� ����� ���� 2).");
      	  				  }
      	  				else
      	  				  puts("������ �� �������\n��� ����� ������ �������� 1-�� ����� ����");
      	  				system("pause");
      	  				break;

      	  	case 9:
      	  				if(pen1)
      	  				  {
      	  				  	x = controlSort();
      	  				  	if(x==1)
      	  				  	  if (amountElements(pen1)+1>1)
      	  				  	    pen1 = sort(pen1);
      	  				  	  else
      	  				  	    puts("��� ���������� ����� ��� ������� ��� ��������\n��� ���������� ��������� �������� ����� ���� 2).");
      	  				  	else
      	  				  	  if(pen2 && x==2)
      	  				  	    if (amountElements(pen2)+1>1)
      	  				  	      pen2 = sort(pen2);
      	  				  	    else
      	  				  	      puts("��� ���������� ����� ��� ������� ��� ��������\n��� ���������� ��������� �������� ����� ���� 2");
      	  				  	  else
      	  				  	    if(x!=0)
      	  				  	    puts("����� ������ �� ����������, ��� �� ��� �����������\n��� ������ �������� ����� ���� 8");
      	  				  }
      	  				else
      	  				  puts("������ �� �������\n��� ����� ������ �������� 1-�� ����� ����");
      	  				system("pause");
      	  				break;
      	  				break;
      	  	case 10:
      	  				system("cls");
	  	  				info();
	  	  				system("pause");
	  	  				break;

      	  	case 0:
      	  				puts("����!");
	  	  				break;
      	  	default:
      	  				puts("������ ������ �� ����������");
      	  				system("pause");
      	  }
      }
	while(c!=0);
	return 0;
  }
//----------------------------------------------------------------------------------
//������� ����
int menu()
  {
    int c;
    system("cls");
   	puts ("������� ����:");
   	puts ("1. ������ ����� ������");
   	puts ("2. �������� ������� �� ��������� �����");
   	puts ("3. ������� ������� ������");
    puts ("4. ���������� ������");
    puts ("5. ������������� ������");
    puts ("6. �������� ������ � ����");
    puts ("7. ������� ������ �� �����");
   	puts ("8. ����� �������� ������");
   	puts ("9. ������������� ������");
   	puts ("10. ���������� � ���������");
   	puts ("0. �����");
    puts ("������� ����� ������:  ");
   	scanf("%d", &c);
   	fflush(stdin);
   	return c;
  }
//#######################################################################################
//���� � ���������� ���������
//#######################################################################################
//������� ����� ������ � ����
LIST* inputField()
    {
     	LIST* pen1 = NULL;

    	  	pen1 = (LIST*)malloc(sizeof(LIST));
     	    system("cls");
	  	  	do
	  	  	  {
	  	  	  	puts("������� ������� ����\n�� 0,1 �� 3");
    		    scanf("%f", &pen1->Pens.feather);
    		    fflush(stdin);
    		    if(pen1->Pens.feather<0.1 || pen1->Pens.feather>3.0)
    		      puts("������ ��� �����.\n���������� ��� ���.");
	  	  	  }
	  	  	while(pen1->Pens.feather<0.1 || pen1->Pens.feather>3.0);

    		do
    		  {
    		  	puts ("��� �����\n1)���������\n2)��������\n������� �����:");
    		  	scanf("%d", &pen1->Pens.ink);
        		fflush(stdin);
        		if(pen1->Pens.ink>2 || pen1->Pens.ink<1)
        		  puts("������ ��� �����.\n���������� ��� ���.");
    		  }
    		while(pen1->Pens.ink>2 || pen1->Pens.ink<1);

    		do
    		  {
    		  	puts ("��������:\n1) ����\n2) ���\n������� ����");
    		  	scanf("%d", &pen1->Pens.cap);
    			fflush(stdin);
    			if(pen1->Pens.cap>2 || pen1->Pens.cap<1)
        		  puts("������ ��� �����.\n���������� ��� ���.");
    		  }
    		while(pen1->Pens.cap>2 || pen1->Pens.cap<1);

    		puts ("������� ������ ���� �����");
    		puts ("1) �����     4)�������");
    		puts ("2) ������    5)������");
    		puts ("3) �������   6)����������");
    		do
    	      {
    		  	scanf("%d", &pen1->Pens.Color.color1);
    			fflush(stdin);
    			if(pen1->Pens.Color.color1>6 || pen1->Pens.Color.color1<1)
        		  puts("������ ��� �����.\n���������� ��� ���:");
    		  }
    		while(pen1->Pens.Color.color1>6 || pen1->Pens.Color.color1<1);

    		puts ("������� ������ ���� �����");
    		puts ("1) �����     4)�������");
    		puts ("2) ������    5)������");
    		puts ("3) �������   6)����������");
    		do
    	      {
    		  	scanf("%d", &pen1->Pens.Color.color2);
    			fflush(stdin);
    			if(pen1->Pens.Color.color2>6 || pen1->Pens.Color.color2<1)
        		  puts("������ ��� �����.\n���������� ��� ���:");
    		  }
    		while(pen1->Pens.Color.color2>6 || pen1->Pens.Color.color2<1);
    	return pen1;
    }
//----------------------------------------------------------------
//������ ����� ���������
LIST* input (LIST *pen1)
  {
    int z;
  	do
      {
      	if(pen1==NULL)
      	  inputNext(&pen1, 0, NULL);
  	    else
  	      inputNext(&pen1, 1, NULL);
  	    puts("����������?\n1)��\n2)���\n������� �����:");
  	    scanf("%d", &z);
  	    fflush(stdin);
  	  }
  	while(z==1);
  	for(; pen1->prev; pen1 = pen1->prev);
  	return pen1;
  }
//----------------------------------------------------------------
//������� ����� n-�� ��������
void inputNext(LIST **pen1, int n, LIST *A)
  {
  	int i;
  	if(!A)
      A = inputField();
    if(n==0)
      {
      	if((*pen1))
      	  {
      	  	A->next = (*pen1);
      	  	A->prev = NULL;
			(*pen1)->prev = A;
      	  }
      	else
      	  {
            A->prev = NULL;
            A->next = NULL;
            (*pen1) = A;
          }
      }
  	if(n==1)
  	  {
  	    while((*pen1) && (*pen1)->next)
  	  	  (*pen1) = (*pen1)->next;
  	    (*pen1)->next = A;
  	    A->next = NULL;
  	    A->prev = (*pen1);
      }
  	if(n!=0 && n!=1)
  	  {
  	    for(i=1; i<n-1; i++)
  	      (*pen1) = (*pen1)->next;
  	    A->next = (*pen1)->next;
  	    A->prev = (*pen1);
  	    (*pen1)->next->prev = A;
  	    (*pen1)->next = A;

  	  }
  }
//----------------------------------------------------------------
//������� ���������� ���������
LIST* addition(LIST *pen1)
  {
  	  int n;
  	  do
  	    {
  	      puts("�� ����� ����� �������� �������?\n������� �����:");
  	      scanf("%d", &n);
  	      if(n<1 || n>amountElements(pen1)+2)
  	        printf("������ ��� �����. ����� ������ ���� ������ ��� ����� %d\n���������� ��� ���\n", amountElements(pen1)+2);
  	    }
  	  while(n<1 || n>amountElements(pen1)+2);
  	  if(n==1)
  	    inputNext(&pen1, 0, NULL);
  	  else
  	    if(n==amountElements(pen1)+2)
  	      inputNext(&pen1, 1, NULL);
  	  else
  	    inputNext(&pen1, n, NULL);
  	  for(; pen1->prev; pen1 = pen1->prev);
  	  return pen1;
  }
//----------------------------------------------------------------
//������� ����� ���������� ���������
int amountElements(LIST *pen1)
  {
  	int f=0;
  	while(pen1&&pen1->next)
  	  {
  	  	pen1=pen1->next;
  	  	f++;
  	  }
  	for(; pen1->prev; pen1 = pen1->prev);
  	  return f;
  }
//#######################################################################################
//����� ������
//#######################################################################################
//������� ������ ������
  void output (LIST* pen1)
    {
      const char *ink, *cap[5], *color1[11], *color2[11];
      int q=1;

      puts("|__________________________________________________________________|");
      puts("|  �  |      |            |            |           ����            |");
      puts("|     | ���� |    ���     |  ��������  |___________________________|");
      puts("|     |      |            |            |      1      |      2      |");
      puts("|_____|______|____________|____________|_____________|_____________|");
      while(pen1)
    	  {
    	  	printf("| %3d |", q);
    	  	q++;
    	  	printf(" %4.1f |", pen1->Pens.feather);

    	  	if(pen1->Pens.ink==1)
    	  	  {
    	  	  	ink = "���������";
    	  	  	printf(" %10s |", ink);
    	  	  }
    	  	else
    	  	  {
    	  	  	ink = "��������";
    	  	  	printf(" %10s |", ink);
    	  	  }
    	  	//-------------------------------
    	  	if(pen1->Pens.cap==1)
    	  	  {
    	  	  	*cap = "����";
    	  	  	printf(" %10s |", *cap);
    	  	  }
    	  	else
    	  	  {
    	  	  	*cap = "���";
    	  	  	printf(" %10s |", *cap);
    	  	  }
    	  	 //-----------------------------
    	  	if(pen1->Pens.Color.color1==1)
    	  	  {
    	  	  	*color1 = "�����";
    	  	  	printf(" %11s |", *color1);
    	  	  }
    	  	else
    	  	  if(pen1->Pens.Color.color1==2)
    	  	    {
    	  	  	  *color1 = "������";
    	  	  	  printf(" %11s |", *color1);
    	  	    }
    	  	  else
    	  	    if(pen1->Pens.Color.color1==3)
    	  	      {
    	  	  	    *color1 = "�������";
    	  	  	    printf(" %11s |", *color1);
    	  	      }
    	  	    else
    	  	      if(pen1->Pens.Color.color1==4)
    	  	        {
    	  	  	      *color1 = "�������";
    	  	  	      printf(" %11s |", *color1);
    	  	        }
    	  	      else
    	  	        if(pen1->Pens.Color.color1==5)
    	  	          {
    	  	  	        *color1 = "������";
    	  	  	        printf(" %11s |", *color1);
    	  	          }
    	  	        else
    	  	          if(pen1->Pens.Color.color1==6)
    	  	            {
    	  	  	          *color1 = "����������";
    	  	  	          printf(" %11s |", *color1);
    	  	            }
    	    //-----------------------------
    	    if(pen1->Pens.Color.color2==1)
    	  	  {
    	  	  	*color2 = "�����";
    	  	  	printf(" %11s |\n", *color2);
    	  	  }
    	  	else
    	  	  if(pen1->Pens.Color.color2==2)
    	  	    {
    	  	  	  *color2 = "������";
    	  	  	  printf(" %11s |\n", *color2);
    	  	    }
    	  	  else
    	  	    if(pen1->Pens.Color.color2==3)
    	  	      {
    	  	  	    *color2 = "�������";
    	  	  	    printf(" %11s |\n", *color2);
    	  	      }
    	  	    else
    	  	      if(pen1->Pens.Color.color2==4)
    	  	        {
    	  	  	      *color2 = "�������";
    	  	  	      printf(" %11s |\n", *color2);
    	  	        }
    	  	      else
    	  	        if(pen1->Pens.Color.color2==5)
    	  	          {
    	  	  	        *color2 = "������";
    	  	  	        printf(" %11s |\n", *color2);
    	  	          }
    	  	        else
    	  	          if(pen1->Pens.Color.color2==6)
    	  	            {
    	  	  	          *color2 = "����������";
    	  	  	          printf(" %11s |\n", *color2);
    	  	  	        }
    	    puts("|_____|______|____________|____________|_____________|_____________|");
    	   pen1 = pen1->next;
    	  }
    	 system("pause");
    }
//------------------------------------------------------------------
//������� ��������
int controlOutput()
  {
  	int x;
  	do
  	  {
  	    puts("1 - ���������� �������� ������");
  	    puts("2 - ���������� ��������� ������");
  	    puts("3 - ��������� � ������� ����");
  	    puts("������� �����");
  	    scanf("%x", &x);
  	    if(x<0 || x>3)
  	      puts("������ ��� �����.\n���������� ��� ���");
  	  }
  	while(x<0 || x>3);
  	if(x==1 || x==2)
  	  return x;
  	else
  	  return 0;
  }
//###############################################################################################
//����� ���������
//###############################################################################################
//������� ������ ���������
    LIST* search (LIST* pen1)
      {
      	LIST *pen2=NULL, *C;
      	int c,z,g=0;
      	float a;
      	do
          {
          	c = menu2();
	      	switch (c)
	      	  {
	      	  	case 1:
	      	  					a = feat();
	      						for(; pen1; pen1=pen1->next)
	      						  {
	      	  					    if(pen1)
	      	  					      if(pen1->Pens.feather<=a)
	      	                            {
	      	                              g=1;
	      	                          	  C = pen2;
	      	    					      pen2 = (LIST*)malloc(sizeof(LIST));
	      	    					      pen2->Pens=pen1->Pens;
	      	    					      pen2->next=C;
	      	    					      if(pen2 && pen2->next && pen2->next->prev)
	      	    					        pen2->next->prev = pen2;
	      	    					      pen2->prev = pen2;
	      	                            }
	      	                      }
	      	                    if(pen2)
	      	                      pen2->prev = NULL;
	      						break;
	      		case 2:
	      						z = menu3();
	      						for(; pen1; pen1=pen1->next)
		      					  {
		      						if(pen1->Pens.ink==z)
	      	                          {
	      	                          	g=1;
	      	                          	C = pen2;
	      	    					    pen2 = (LIST*)malloc(sizeof(LIST));
	      	    					    pen2->Pens=pen1->Pens;
	      	    					    pen2->next=C;
	      	    					    if(pen2 && pen2->next && pen2->next->prev)
	      	    					      pen2->next->prev = pen2;
	      	    					    pen2->prev = pen2;
	      	                          }
		      					  }
		      					if(pen2)
		      					  pen2->prev = NULL;
	      						break;
	      	   }
      	  }
      	while(c!=1 && c!=2);
      	if(!g)
      	  puts("����� �� ��� �����������.");
      	else
      	  puts("����� �������� �������.");
      	return pen2;
      }
//----------------------------------------------------------------------
//������� ��������
int controlSearch()
  {
  	int x;
  	do
  	  {
  	  	puts("1 - ������ � �������� ������");
  	  	puts("2 - ������ � ��������� ������");
  	  	puts("3 - ��������� � ������� ����");
  	  	puts("������� �����");
  	  	scanf("%d", &x);
  	  	if(x<1 || x>3)
  	  	  puts("������ ��� �����\n���������� ��� ���");
  	  }
  	while(x<1 || x>3);
  	if(x==1 || x==2)
  	  return x;
  	else
  	  return 0;
  }
//---------------------------------------------------------------------
int menu2()
  {
    int c;
    do
      {
        puts("�� ������ �������� ������ �����?");
        puts("1 - ������� ����");
        puts("2 - ���");
        puts("������� �����:");
        scanf("%d", &c);
        fflush(stdin);
        if(c<1 || c>2)
          puts("������ ��� �����\n���������� ��� ���");
      }
    while(c<1 || c>2);
  	return c;
  }
  //--------------------------------------------------------------------
int menu3()
    {
      int z;
      do
        {
          puts("�������� ���");
          puts("1 - ���������");
          puts("2 - ��������");
          puts("������� �����:");
          scanf("%d", &z);
          fflush(stdin);
          if(z<1 || z>2)
            puts("������ ��� �����\n���������� ��� ���");
        }
      while(z<1 || z>2);
      return z;
    }
//---------------------------------------------------------------------
float feat()
    {
      float a;
      do
        {
          puts("�� ����� ������� ���� �������� �����?\n");
	      scanf("%f", &a);
	      fflush(stdin);
	      if(a<0.1 || a>3)
	       puts("������ ��� �����\n������� ���� �� 0,1 �� 3\n���������� ��� ���");
	   }
	  while(a<0.1 || a>3);
	   return a;
    }
//##################################################################################################
//�������� ���������
//##################################################################################################
//������� �������� ���������
LIST* deletion(LIST *pen1)
  {
  	int n;
  	  do
  	    {
  	      puts("� ������ ����� ������� �������?\n������� �����:");
  	      scanf("%d", &n);
  	      if(n<1 || n>amountElements(pen1)+1)
  	        printf("������ ��� �����. ����� ������ ���� ������ %d\n���������� ��� ���\n", amountElements(pen1)+1);
  	    }
  	  while(n<1 || n>amountElements(pen1)+1);
  	  if(n==1)
  	    pen1 = deletionFirst(pen1);
  	  else
  	    if(n==amountElements(pen1)+1)
  	      deletionNext(pen1, n);
  	  else
  	    deletionNext(pen1, n);
  	return pen1;
  }
//----------------------------------------------------------------
int controlDeletion()
  {
  	int x;
  	do
  	  {
  	    puts("1 - ������� �� �������� ������");
  	    puts("2 - ������� �� �������� ������");
  	    puts("3 - ��������� � ������� ����");
  	    puts("������� �����");
  	    scanf("%x", &x);
  	    if(x<0 || x>3)
  	      puts("������ ��� �����.\n���������� ��� ���");
  	  }
  	while(x<0 || x>3);
  	if(x==1 || x==2)
  	  return x;
  	else
  	  return 0;
  }
//-----------------------------------------------------------------
//������� �������� ������� ��������
LIST* deletionFirst(LIST *pen1)
  {
    LIST *A = pen1;
    pen1 = pen1->next;
    free(A);
    //pen1->prev = NULL;
    return pen1;
  }
//---------------------------------------------------------------
//������� �������� n-�� ��������
void deletionNext(LIST *pen1, int n)
  {
  	int i;
  	if(n==amountElements(pen1)+1)
  	  {
  	    for(; pen1->next; pen1=pen1->next);
  	    free(pen1->next);
  	    pen1->next = NULL;
      }
  	else
  	  {
  	  	LIST* A;
  	    for(i=1; i<n-1; i++)
  	      pen1 = pen1->next;
  	    pen1->next->next->prev = pen1->next->prev;
  	    A = pen1->next->next;
  	    free(pen1->next);
  	    pen1->next = A;
  	  }
  }
//----------------------------------------------------------------
//������� ������� ������
LIST* delitionAll (LIST *pen1)
  {
  	int i;
  	LIST *C;
  	C = pen1;
  	while(pen1)
  	  {
  	    for(i=1; i<amountElements(pen1); i++)
  	      pen1 = pen1->next;
  	    if(pen1==C)
  	      {
  	        free(pen1);
  	        pen1 = NULL;
  	      }
  	    else
  	      {
  	        free(pen1->next);
  	        pen1->next = NULL;
  	        pen1 = C;
  	      }
  	  }
  	return pen1;
  }
//##########################################################################################
//���������� � �������������� ���������
//##########################################################################################
//������� ����������
LIST* sort(LIST* pen1)
  {
  	LIST *A, *B, *C;
  	int f=0, i, g=0;
  	B = pen1;
  	C = sortFirst(pen1);
  	  while(f==0)
  	    {
  	      f=1;
  	      pen1 = C;
  	      for(i=0; (i<amountElements(pen1)-1) && (f==1); i++)
  	        {
  	          if(pen1->next->next->Pens.feather < pen1->next->Pens.feather)
  	            f=0;
  	          else
  	            pen1 = pen1->next;
            }
          pen1 = C;
  	      for (;pen1 && pen1->next && pen1->next->next; pen1 = pen1->next)
  	        {
  	     	  if(pen1->next->next->Pens.feather < pen1->next->Pens.feather)
  	            {
  	              g=1;
  	    	      A = pen1->next->next->next;
  	    	      pen1->next->next->next = pen1->next->next->prev;
  	    	      pen1->next->next->prev = pen1->next->prev;
  	    	      pen1->next->prev = pen1->next->next;
  	    	      pen1->next->next = A;
  	    	      pen1->next = pen1->next->prev;
  	    	      if(pen1)
  	    	        if(pen1->next)
  	    	          if(pen1->next->next)
  	    	            if(pen1->next->next->next)
  	    	              if(pen1->next->next->next->prev)
  	    	                pen1->next->next->next->prev = pen1->next->next;
  	            }
  	        }
  	      pen1 = C;
  	      C = sortFirst(pen1);
        }
      if(g==0 && C==B)
        puts("���������� �� �����������. �������� ��� ����� �� �����������.");
      else
        puts("���������� ��������� �������");
  	return C;
  }
//----------------------------------------------------------------
//������� ���������� ������� ��������
LIST* sortFirst(LIST* pen1)
  {
  	if(pen1->next->Pens.feather < pen1->Pens.feather)
  	  {
  	  	LIST *A;
  	  	A = pen1->next->next;
  	  	pen1->next->next = pen1->next->prev;
  	  	pen1->next->prev = NULL;
  	  	pen1->prev = pen1->next;
  	  	pen1->next = A;
  	  	pen1 = pen1->prev;
  	  	if(pen1)
  	  	  if(pen1->next)
  	  	    if(pen1->next->next)
  	  	      if(pen1->next->next->prev)
  	  	        pen1->next->next->prev = pen1->next;
  	  	return pen1;
  	  }
  	else
  	  return pen1;

  }
//---------------------------------------------------------------
//������� ������ ������ ��� ����������
int controlSort()
  {
  	int x;
  	do
  	  {
  	    puts("1 - ����������� �������� ������");
  	    puts("2 - ����������� ��������� ������");
  	    puts("3 - ��������� � ������� ����");
  	    puts("������� �����");
  	    scanf("%x", &x);
  	    fflush(stdin);
  	    if(x<0 || x>3)
  	      puts("������ ��� �����.\n���������� ��� ���");
  	  }
  	while(x<0 || x>3);
  	if(x==1 || x==2)
  	  return x;
  	else
  	  return 0;
  }
//------------------------------------------------------------------
//������� ��������������
void editing(LIST *pen1)
  {
  	int n, i;
  	do
  	  {
	  	puts("������� ������ �� �����?");
	  	puts("1. ��\n2. ���");
	  	scanf("%d", &i);
	  	fflush(stdin);
	  	if(i<1 || i>2);
	  	  puts("������. ���������� ��� ���.");
	  }
	while(i<1 || i>2);
	if(i==1)
	  output(pen1);
  	do
  	  {
  	    puts("������� ����� ��������, ������� ������ ��������:");
  	    scanf("%d", &n);
  	    fflush(stdin);
  	    if(n<0 || n>(amountElements(pen1)+1))
  	      puts("������. ������ �������� �����.");
  	  }
  	while(n<0 || n>(amountElements(pen1)+1));
  	for(i=1; i<n; i++)
  	  pen1 = pen1->next;
  	do
  	  {
	  	puts("1. �������� ������� ����");
	  	puts("2. �������� ��� �����");
	  	puts("3. �������� ������� ��������");
	  	puts("4. �������� ������ ���� �����");
	  	puts("5. �������� ������ ���� �����");
	  	puts("������� �����:");
	  	scanf("%d", &n);
	  	fflush(stdin);
	  	  if(n<0 || n>5)
	  	    puts("������. ������ �������� �����.");
	  }
	while(n<0 || n>5);
	switch(n)
	  {
	  	case 1:
	  				do
			  	  	  {
			  	  	  	puts("������� ������� ����\n�� 0,1 �� 3");
		    		    scanf("%f", &pen1->Pens.feather);
		    		    fflush(stdin);
		    		    if(pen1->Pens.feather<0.1 || pen1->Pens.feather>3.0)
		    		      puts("������ ��� �����.\n���������� ��� ���.");
			  	  	  }
			  	  	while(pen1->Pens.feather<0.1 || pen1->Pens.feather>3.0);
			  	  	break;
		case 2:
					do
		    		  {
		    		  	puts ("��� �����\n1)���������\n2)��������\n������� �����:");
		    		  	scanf("%d", &pen1->Pens.ink);
		        		fflush(stdin);
		        		if(pen1->Pens.ink>2 || pen1->Pens.ink<1)
		        		  puts("������ ��� �����.\n���������� ��� ���.");
		    		  }
		    		while(pen1->Pens.ink>2 || pen1->Pens.ink<1);
		    		break;
		case 3:
					do
		    		  {
		    		  	puts ("��������:\n1) ����\n2) ���\n������� ����");
		    		  	scanf("%d", &pen1->Pens.cap);
		    			fflush(stdin);
		    			if(pen1->Pens.cap>2 || pen1->Pens.cap<1)
		        		  puts("������ ��� �����.\n���������� ��� ���.");
		    		  }
		    		while(pen1->Pens.cap>2 || pen1->Pens.cap<1);
		    		break;
		case 4:
					puts ("������� ������ ���� �����");
		    		puts ("1) �����     4)�������");
		    		puts ("2) ������    5)������");
		    		puts ("3) �������   6)����������");
		    		do
		    	      {
		    		  	scanf("%d", &pen1->Pens.Color.color1);
		    			fflush(stdin);
		    			if(pen1->Pens.Color.color1>6 || pen1->Pens.Color.color1<1)
		        		  puts("������ ��� �����.\n���������� ��� ���:");
		    		  }
		    		while(pen1->Pens.Color.color1>6 || pen1->Pens.Color.color1<1);
		    		break;
		case 5:
					puts ("������� ������ ���� �����");
		    		puts ("1) �����     4)�������");
		    		puts ("2) ������    5)������");
		    		puts ("3) �������   6)����������");
		    		do
		    	      {
		    		  	scanf("%d", &pen1->Pens.Color.color2);
		    			fflush(stdin);
		    			if(pen1->Pens.Color.color2>6 || pen1->Pens.Color.color2<1)
		        		  puts("������ ��� �����.\n���������� ��� ���:");
		    		  }
		    		while(pen1->Pens.Color.color2>6 || pen1->Pens.Color.color2<1);
		    		break;
	  }
  }
//--------------------------------------------------
//������� ������ ������ ��� ��������������
int controlEditing()
  {
  	int x;
  	do
  	  {
  	    puts("1 - ������������� �������� ������");
  	    puts("2 - ������������� ��������� ������");
  	    puts("3 - ��������� � ������� ����");
  	    puts("������� �����");
  	    scanf("%x", &x);
  	    fflush(stdin);
  	    if(x<0 || x>3)
  	      puts("������ ��� �����.\n���������� ��� ���");
  	  }
  	while(x<0 || x>3);
  	if(x==1 || x==2)
  	  return x;
  	else
  	  return 0;
  }
//***************************************************************************************************
//������ � ������
//***************************************************************************************************
//������� ������ � ����
int filing(LIST* pen1, const char *name, int *q)
  {
   system("cls");
   FILE* file;
   int z=0;
   if(file=fopen(name,"w"))
     {
      fprintf(file, "%d", 0);
      while(pen1)
       {
       	 fwrite(&(pen1->Pens),sizeof(pen1->Pens),1,file);
         pen1=pen1->next;
         z++;
       }
      rewind(file);
      fprintf(file, "%d", z);
      fclose(file);
      *q = z;
      return 1;
     }
   if(pen1==0)
     return 2;
   else
     return 3;
  }
//------------------------------------------------------------
//������� ������ �����
int readFile(LIST **pen1, const char *name, int q)
  {
   LIST* A=NULL, *M;
   FILE* file;
   system("cls");
   if((file=fopen(name,"r")))
     {
       *pen1 = NULL;
       fscanf(file, "%d", &q);
	   for(; q; q--)
	    {
	      A = (LIST*)malloc(sizeof(LIST));
	      fread(&(A->Pens),sizeof(A->Pens),1,file);

	      if(*pen1==NULL)
	        {
	        	inputNext(pen1, 0, A);
	        	M = *pen1;
	        }
  	      else
  	        inputNext(pen1, 1, A);
	    }
	   fclose(file);
	   *pen1 = M;
	   return 1;
     }
  else
    if(pen1==NULL)
      return 2;
    else
      return 3;
  }
//-----------------------------------------------------------
//������� ����� �������� �����
const char* fileName(int key)
{
    system("cls");
    char a[15], *name;
    if(key==1)
        puts("������� ��� �����.\n���� ������ ����� �� ����������, ���� ���������.\n���� ����������, ���� �������������.\n");
    else
      {
      	do
      	  {
	      	puts("1. ������ ��� �����");
	      	puts("2. ������� ���������������� ����");
	      	scanf("%d", &key);
	      	fflush(stdin);
	      	if(key<1 || key>2)
	      	  puts("������. ��������� ����");
	      }
	    while(key<1 || key>2);
      }
    if(key==1)
      {
	    puts("��� �����: ");
	    do
	     {
	      scanf("%s", &a);
	      fflush(stdin);
	      if(strlen(a)<1 || strlen(a)>15)
	      printf("������ ��� ����� (���-�� �������� �� ��������� 20)\n��������� ����: ");
	     }
	    while(strlen(a)<1 || strlen(a)>15);
	    name=(char*)malloc(strlen(a)*sizeof(char));
	    strcpy(name, a);
	  }
	else
	  {
	    name = name=(char*)malloc(strlen(a)*sizeof(char));
	    name = "demoFile";
	  }
	return name;
}
//----------------------------------------------------------------
//������� ������ ������ ��� ��������������
int controlFiling()
  {
  	int x;
  	do
  	  {
  	    puts("1 - �������� �������� ������");
  	    puts("2 - �������� ��������� ������");
  	    puts("3 - ��������� � ������� ����");
  	    puts("������� �����");
  	    scanf("%x", &x);
  	    fflush(stdin);
  	    if(x<0 || x>3)
  	      puts("������ ��� �����.\n���������� ��� ���");
  	  }
  	while(x<0 || x>3);
  	if(x==1 || x==2)
  	  return x;
  	else
  	  return 0;
  }
//----------------------------------------------------------
void info ()
    {
    	puts("��������� ������������� ��� ������ � ������� � ������.\n");
    	puts("��� ���������:\n1) ������ �������� ������ �� ���� ���������:");
    	puts("  �) ������� ���� �����\n  �)��� ����� (��������� ��� ��������)\n");
    	puts("2) ����������� ��������� ��� ��������� ������ �� ����������� �������� ������� ����.\n");
    	puts("3) ��������� �������� �� ����� ������� ������.\n");
    	puts("4) ������� �������� � ����� ������� ������.\n");
    	puts("5) ���������� �� � ���� � ����� ��������.\n");
    	puts("6) ��������� ���������, ���������� � �����.\n");
    	puts("7) �������������.\n");
    }
//----------------------------------------------------------------
