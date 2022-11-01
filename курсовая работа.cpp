#include<stdlib.h>
#include<locale.h>
#include<windows.h>
#include<conio.h>
#include<stdio.h>

struct COLOR
  {
  	int color1;          //Цвет 1
  	int color2;          //Цвет 2
  };

struct PENS
  {
  	float feather;       //Толщина пера
  	int ink;             //Тип
  	int cap;             //Колпачок
  	COLOR Color;
  };

struct LIST
  {
  	PENS Pens;           //Структура ручек
  	struct LIST* next;   //Следующий элемент
  	struct LIST* prev;   //Предыдущий элемент
  };


//----------------------------------------------------------------------------------------------------------
  //Прототипы функций:
  int menu();                             //Прототип функции главного меню
  //---------------------Ввод; Добавление:-----------------------------------------------------
  LIST* input(LIST*);                     //Прототив Функции ввода
  LIST* inputField();                     //Прототип функции заполнения информационных полей
  void inputNext(LIST**, int, LIST*);     //Прототип функции добавления следующих элементов
  LIST* addition(LIST *pen1);             //Прототип функции добавления элементов
  //----------------------------Вывод:------------------------------------------------------
  void output (LIST*);                    //Прототип функции вывода
  int controlOutput();                    //Прототип функции выбора списка
  //---------------------------Поиск:------------------------------------------------------
  LIST* search (LIST*);                   //Прототип функции поиска элементов
  float feat();                           //Прототип функции ввода искомой толщины пера
  int menu2();                            //Прототип функции подменю
  int menu3();                            //Прототип функции подменю
  int controlSearch();                    //Прототип функции выбора списка
  //---------------Сортировка/Редактирование:---------------------------------------------------
  LIST* sort(LIST*);                      //Прототип функции сортировки
  LIST* sortFirst(LIST*);                 //Прототип функции сортировки первого элемента
  int controlSort();                      //Прототип функции выбора списка
  void editing(LIST*);                    //Прототип функции редактирования
  int controlEditing();                   //Прототип функции выбора списка для редактирования
  //----------------------------Удаление:--------------------------------------------------
  LIST* deletion(LIST*);                  //Прототип функции удаления
  LIST* deletionFirst(LIST*);             //Прототип функции удаления первого элемента
  void deletionNext(LIST*, int);          //Прототип функции удаления n-го элемента
  LIST* delitionAll (LIST*);              //Прототип функции удаления списка
  int controlDeletion();                  //Прототип функции выбора списка
  //-------------------------Работа с файлом:----------------------------------------------
  int filing(LIST*, const char*, int*);    //Прототип функции записи в файл
  const char* fileName(int);               //Прототип функции ввода имени файла
  int readFile(LIST**, const char*, int);  //Прототип функции считываения файла
  int controlFiling();                     //Прототип функции выбора списка для записи
  //-------------------------------Общие-----------------------------------------------------
  int amountElements(LIST*);               //Прототип функции определения количества элементов в списке
  void info ();                            //Прототип функции информации о программе
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
      	  				  puts("Данные не введены\nДля ввода данных выберете 1-ый пункт меню");
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
      	  				  	    puts("Поиск данных не выполнялся, или не дал результатов\nДля поиска выберете пункт меню 8");
      	  				  }
      	  				else
      	  				  puts("Данные не введены\nДля ввода данных выберете 1-ый пункт меню");
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
      	  				          puts("Поиск данных не выполнялся, или не дал результатов\nДля поиска выберете пункт меню 8");
      	  				    }
      	  				   else
      	  				     puts("Данные не введены\nДля ввода данных выберите 1-ый пункт меню");
      	  				system("pause");
      	  				break;
      	  	case 5:
      	  				if(pen1)
      	  				  {
      	  				  	x = controlEditing();
      	  				  	  if(x==1)
      	  				  	    {
      	  				  	      editing(pen1);
      	  				  	      puts("Данные изменены успешно");
      	  				  	    }
      	  				  	  else
      	  				  	    if(pen2 && x==2)
      	  				  	      {
      	  				  	        editing(pen2);
      	  				  	        puts("Данные изменены успешно");
      	  				  	      }
      	  				  	    else
      	  				  	      if(x!=0)
      	  				  	      puts("Поиск данных не выполнялся, или не дал результатов\nДля поиска выберете пункт меню 8");
      	  				  }
      	  				  else
      	  				     puts("Данные не введены\nДля ввода данных выберите 1-ый пункт меню");
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
      	  				      puts("Запись в файл успешно завершена");
      	  				    else
      	  				      if(x==2)
      	  				        puts("Создан пустой файл");
      	  				      else
      	  				        puts("Запись в файл не удалась");
      	  				  }
      	  				else
      	  				  puts("Данные не введены\nДля ввода данных выберете 1-ый пункт меню");
      	  				system("pause");
      	  				break;

      	  	case 7:
      	  				system("cls");
      	  				  name = fileName(2);
      	  				  x = readFile(&pen1, name, q);
      	  				  if(x==1)
      	  				    puts("Данные считаны");
      	  				  if(x==2)
      	  				    puts("Файл пуст");
      	  				  if(x==3)
      	  				    puts("Данные не считаны");
      	  				system("pause");
      	  				break;
      	  	case 8:
      	  				if(pen1)
      	  				  {
      	  				  	if (amountElements(pen1)+1>1)
      	  				  	  pen2=search(pen1);
      	  				  	else
      	  				  	  puts("Для поиска нужны как минимум два элемента\nДля добавления элементов выберите пунтк меню 2).");
      	  				  }
      	  				else
      	  				  puts("Данные не введены\nДля ввода данных выберите 1-ый пункт меню");
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
      	  				  	    puts("Для сортировки нужны как минимум два элемента\nДля добавления элементов выберите пунтк меню 2).");
      	  				  	else
      	  				  	  if(pen2 && x==2)
      	  				  	    if (amountElements(pen2)+1>1)
      	  				  	      pen2 = sort(pen2);
      	  				  	    else
      	  				  	      puts("Для сортировки нужны как минимум два элемента\nДля добавления элементов выберите пунтк меню 2");
      	  				  	  else
      	  				  	    if(x!=0)
      	  				  	    puts("Поиск данных не выполнялся, или не дал результатов\nДля поиска выберите пункт меню 8");
      	  				  }
      	  				else
      	  				  puts("Данные не введены\nДля ввода данных выберите 1-ый пункт меню");
      	  				system("pause");
      	  				break;
      	  				break;
      	  	case 10:
      	  				system("cls");
	  	  				info();
	  	  				system("pause");
	  	  				break;

      	  	case 0:
      	  				puts("Пока!");
	  	  				break;
      	  	default:
      	  				puts("Такого пункта не существует");
      	  				system("pause");
      	  }
      }
	while(c!=0);
	return 0;
  }
//----------------------------------------------------------------------------------
//Функция меню
int menu()
  {
    int c;
    system("cls");
   	puts ("Главное меню:");
   	puts ("1. Ввести новые данные");
   	puts ("2. Добавить элемент на выбранное место");
   	puts ("3. Удалить элемент списка");
    puts ("4. Посмотреть данные");
    puts ("5. Редактировать данные");
    puts ("6. Записать список в файл");
    puts ("7. Считать список из файла");
   	puts ("8. Найти элементы списка");
   	puts ("9. Отсортировать список");
   	puts ("10. Информация о программе");
   	puts ("0. Выход");
    puts ("Введите номер пункта:  ");
   	scanf("%d", &c);
   	fflush(stdin);
   	return c;
  }
//#######################################################################################
//Ввод и добавление элементов
//#######################################################################################
//Функция ввода данных в поля
LIST* inputField()
    {
     	LIST* pen1 = NULL;

    	  	pen1 = (LIST*)malloc(sizeof(LIST));
     	    system("cls");
	  	  	do
	  	  	  {
	  	  	  	puts("Введите толщину пера\nОт 0,1 до 3");
    		    scanf("%f", &pen1->Pens.feather);
    		    fflush(stdin);
    		    if(pen1->Pens.feather<0.1 || pen1->Pens.feather>3.0)
    		      puts("Ошибка при вводе.\nПопробуйте ещё раз.");
	  	  	  }
	  	  	while(pen1->Pens.feather<0.1 || pen1->Pens.feather>3.0);

    		do
    		  {
    		  	puts ("Тип ручки\n1)Шариковая\n2)Гелиевая\nВведите число:");
    		  	scanf("%d", &pen1->Pens.ink);
        		fflush(stdin);
        		if(pen1->Pens.ink>2 || pen1->Pens.ink<1)
        		  puts("Ошибка при вводе.\nПопробуйте ещё раз.");
    		  }
    		while(pen1->Pens.ink>2 || pen1->Pens.ink<1);

    		do
    		  {
    		  	puts ("Колпачок:\n1) Есть\n2) Нет\nВведите чило");
    		  	scanf("%d", &pen1->Pens.cap);
    			fflush(stdin);
    			if(pen1->Pens.cap>2 || pen1->Pens.cap<1)
        		  puts("Ошибка при вводе.\nПопробуйте ещё раз.");
    		  }
    		while(pen1->Pens.cap>2 || pen1->Pens.cap<1);

    		puts ("Введите первый цвет ручки");
    		puts ("1) Синий     4)Зеленый");
    		puts ("2) Черный    5)Желтый");
    		puts ("3) Красный   6)Фиолетовый");
    		do
    	      {
    		  	scanf("%d", &pen1->Pens.Color.color1);
    			fflush(stdin);
    			if(pen1->Pens.Color.color1>6 || pen1->Pens.Color.color1<1)
        		  puts("Ошибка при вводе.\nПопробуйте ещё раз:");
    		  }
    		while(pen1->Pens.Color.color1>6 || pen1->Pens.Color.color1<1);

    		puts ("Введите второй цвет ручки");
    		puts ("1) Синий     4)Зеленый");
    		puts ("2) Черный    5)Желтый");
    		puts ("3) Красный   6)Фиолетовый");
    		do
    	      {
    		  	scanf("%d", &pen1->Pens.Color.color2);
    			fflush(stdin);
    			if(pen1->Pens.Color.color2>6 || pen1->Pens.Color.color2<1)
        		  puts("Ошибка при вводе.\nПопробуйте ещё раз:");
    		  }
    		while(pen1->Pens.Color.color2>6 || pen1->Pens.Color.color2<1);
    	return pen1;
    }
//----------------------------------------------------------------
//Фунция ввода элементов
LIST* input (LIST *pen1)
  {
    int z;
  	do
      {
      	if(pen1==NULL)
      	  inputNext(&pen1, 0, NULL);
  	    else
  	      inputNext(&pen1, 1, NULL);
  	    puts("Продолжить?\n1)Да\n2)Нет\nВведите число:");
  	    scanf("%d", &z);
  	    fflush(stdin);
  	  }
  	while(z==1);
  	for(; pen1->prev; pen1 = pen1->prev);
  	return pen1;
  }
//----------------------------------------------------------------
//Функция ввода n-го элемента
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
//Функция добавления элементов
LIST* addition(LIST *pen1)
  {
  	  int n;
  	  do
  	    {
  	      puts("На какое место добавить элемент?\nВведите число:");
  	      scanf("%d", &n);
  	      if(n<1 || n>amountElements(pen1)+2)
  	        printf("Ошибка при вводе. Число болжно быть меньше или равно %d\nПопробуйте ещё раз\n", amountElements(pen1)+2);
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
//Функция счёта количества элементов
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
//Вывод данных
//#######################################################################################
//Функция вывода данных
  void output (LIST* pen1)
    {
      const char *ink, *cap[5], *color1[11], *color2[11];
      int q=1;

      puts("|__________________________________________________________________|");
      puts("|  №  |      |            |            |           Цвет            |");
      puts("|     | Перо |    Тип     |  Колпачок  |___________________________|");
      puts("|     |      |            |            |      1      |      2      |");
      puts("|_____|______|____________|____________|_____________|_____________|");
      while(pen1)
    	  {
    	  	printf("| %3d |", q);
    	  	q++;
    	  	printf(" %4.1f |", pen1->Pens.feather);

    	  	if(pen1->Pens.ink==1)
    	  	  {
    	  	  	ink = "Шариковая";
    	  	  	printf(" %10s |", ink);
    	  	  }
    	  	else
    	  	  {
    	  	  	ink = "Гелиевая";
    	  	  	printf(" %10s |", ink);
    	  	  }
    	  	//-------------------------------
    	  	if(pen1->Pens.cap==1)
    	  	  {
    	  	  	*cap = "Есть";
    	  	  	printf(" %10s |", *cap);
    	  	  }
    	  	else
    	  	  {
    	  	  	*cap = "Нет";
    	  	  	printf(" %10s |", *cap);
    	  	  }
    	  	 //-----------------------------
    	  	if(pen1->Pens.Color.color1==1)
    	  	  {
    	  	  	*color1 = "Синий";
    	  	  	printf(" %11s |", *color1);
    	  	  }
    	  	else
    	  	  if(pen1->Pens.Color.color1==2)
    	  	    {
    	  	  	  *color1 = "Черный";
    	  	  	  printf(" %11s |", *color1);
    	  	    }
    	  	  else
    	  	    if(pen1->Pens.Color.color1==3)
    	  	      {
    	  	  	    *color1 = "Красный";
    	  	  	    printf(" %11s |", *color1);
    	  	      }
    	  	    else
    	  	      if(pen1->Pens.Color.color1==4)
    	  	        {
    	  	  	      *color1 = "Зеленый";
    	  	  	      printf(" %11s |", *color1);
    	  	        }
    	  	      else
    	  	        if(pen1->Pens.Color.color1==5)
    	  	          {
    	  	  	        *color1 = "Желтый";
    	  	  	        printf(" %11s |", *color1);
    	  	          }
    	  	        else
    	  	          if(pen1->Pens.Color.color1==6)
    	  	            {
    	  	  	          *color1 = "Фиолетовый";
    	  	  	          printf(" %11s |", *color1);
    	  	            }
    	    //-----------------------------
    	    if(pen1->Pens.Color.color2==1)
    	  	  {
    	  	  	*color2 = "Синий";
    	  	  	printf(" %11s |\n", *color2);
    	  	  }
    	  	else
    	  	  if(pen1->Pens.Color.color2==2)
    	  	    {
    	  	  	  *color2 = "Черный";
    	  	  	  printf(" %11s |\n", *color2);
    	  	    }
    	  	  else
    	  	    if(pen1->Pens.Color.color2==3)
    	  	      {
    	  	  	    *color2 = "Красный";
    	  	  	    printf(" %11s |\n", *color2);
    	  	      }
    	  	    else
    	  	      if(pen1->Pens.Color.color2==4)
    	  	        {
    	  	  	      *color2 = "Зеленый";
    	  	  	      printf(" %11s |\n", *color2);
    	  	        }
    	  	      else
    	  	        if(pen1->Pens.Color.color2==5)
    	  	          {
    	  	  	        *color2 = "Желтый";
    	  	  	        printf(" %11s |\n", *color2);
    	  	          }
    	  	        else
    	  	          if(pen1->Pens.Color.color2==6)
    	  	            {
    	  	  	          *color2 = "Фиолетовый";
    	  	  	          printf(" %11s |\n", *color2);
    	  	  	        }
    	    puts("|_____|______|____________|____________|_____________|_____________|");
    	   pen1 = pen1->next;
    	  }
    	 system("pause");
    }
//------------------------------------------------------------------
//Функция контроля
int controlOutput()
  {
  	int x;
  	do
  	  {
  	    puts("1 - Посмотреть исходные данные");
  	    puts("2 - Посмотреть найденные данные");
  	    puts("3 - Вернкться в главное меню");
  	    puts("Введите число");
  	    scanf("%x", &x);
  	    if(x<0 || x>3)
  	      puts("Ошибка при вводе.\nПопробуйте ещё раз");
  	  }
  	while(x<0 || x>3);
  	if(x==1 || x==2)
  	  return x;
  	else
  	  return 0;
  }
//###############################################################################################
//Поиск элементов
//###############################################################################################
//Функция поиска элементов
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
      	  puts("Поиск не дал результатов.");
      	else
      	  puts("Поиск выполнен успешно.");
      	return pen2;
      }
//----------------------------------------------------------------------
//Функция контроля
int controlSearch()
  {
  	int x;
  	do
  	  {
  	  	puts("1 - Искать в исходных данных");
  	  	puts("2 - Искать в найденных данных");
  	  	puts("3 - Вернкться в главное меню");
  	  	puts("Введите число");
  	  	scanf("%d", &x);
  	  	if(x<1 || x>3)
  	  	  puts("Ошибка при вводе\nПопробуйте ещё раз");
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
        puts("По какому критерию искать ручки?");
        puts("1 - Толщина пера");
        puts("2 - Тип");
        puts("введите число:");
        scanf("%d", &c);
        fflush(stdin);
        if(c<1 || c>2)
          puts("Ошибка при вводе\nПопробуйте ещё раз");
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
          puts("Выберите тип");
          puts("1 - Шариковые");
          puts("2 - Гелиевые");
          puts("Введите число:");
          scanf("%d", &z);
          fflush(stdin);
          if(z<1 || z>2)
            puts("Ошибка при вводе\nПопробуйте ещё раз");
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
          puts("До какой толщины пера выводить ручки?\n");
	      scanf("%f", &a);
	      fflush(stdin);
	      if(a<0.1 || a>3)
	       puts("Ошибка при вводе\nТолщина пера от 0,1 до 3\nПопробуйте ещё раз");
	   }
	  while(a<0.1 || a>3);
	   return a;
    }
//##################################################################################################
//Удаление элементов
//##################################################################################################
//Функция удаления элементов
LIST* deletion(LIST *pen1)
  {
  	int n;
  	  do
  	    {
  	      puts("С какого места удалить элемент?\nВведите число:");
  	      scanf("%d", &n);
  	      if(n<1 || n>amountElements(pen1)+1)
  	        printf("Ошибка при вводе. Число должно быть меньше %d\nПопробуйте ещё раз\n", amountElements(pen1)+1);
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
  	    puts("1 - Удалить из исходных данных");
  	    puts("2 - Удалить из найденых данных");
  	    puts("3 - Вернкться в главное меню");
  	    puts("Введите число");
  	    scanf("%x", &x);
  	    if(x<0 || x>3)
  	      puts("Ошибка при вводе.\nПопробуйте ещё раз");
  	  }
  	while(x<0 || x>3);
  	if(x==1 || x==2)
  	  return x;
  	else
  	  return 0;
  }
//-----------------------------------------------------------------
//Функция удаления первого элемента
LIST* deletionFirst(LIST *pen1)
  {
    LIST *A = pen1;
    pen1 = pen1->next;
    free(A);
    //pen1->prev = NULL;
    return pen1;
  }
//---------------------------------------------------------------
//Функция удаления n-го элемента
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
//Функция очистки памяти
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
//Сортировка и Редактирование элементов
//##########################################################################################
//Функция сортировки
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
        puts("Сортировка не выполнялась. Элементы уже стоят по возрастанию.");
      else
        puts("Сортировка выполнена успешно");
  	return C;
  }
//----------------------------------------------------------------
//Функция сортировки первого элемента
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
//Функция выбора списка для сортировки
int controlSort()
  {
  	int x;
  	do
  	  {
  	    puts("1 - Сортировать исходные данные");
  	    puts("2 - Сортировать найденные данные");
  	    puts("3 - Вернкться в главное меню");
  	    puts("Введите число");
  	    scanf("%x", &x);
  	    fflush(stdin);
  	    if(x<0 || x>3)
  	      puts("Ошибка при вводе.\nПопробуйте ещё раз");
  	  }
  	while(x<0 || x>3);
  	if(x==1 || x==2)
  	  return x;
  	else
  	  return 0;
  }
//------------------------------------------------------------------
//Функция редактирования
void editing(LIST *pen1)
  {
  	int n, i;
  	do
  	  {
	  	puts("Вывести данные на экран?");
	  	puts("1. Да\n2. Нет");
	  	scanf("%d", &i);
	  	fflush(stdin);
	  	if(i<1 || i>2);
	  	  puts("Ошибка. Попробуйте ещё раз.");
	  }
	while(i<1 || i>2);
	if(i==1)
	  output(pen1);
  	do
  	  {
  	    puts("Введите номер элемента, который хотите изменить:");
  	    scanf("%d", &n);
  	    fflush(stdin);
  	    if(n<0 || n>(amountElements(pen1)+1))
  	      puts("Ошибка. Введен неверный номер.");
  	  }
  	while(n<0 || n>(amountElements(pen1)+1));
  	for(i=1; i<n; i++)
  	  pen1 = pen1->next;
  	do
  	  {
	  	puts("1. Изменить толщину пера");
	  	puts("2. Изменить тип ручки");
	  	puts("3. Изменить наличие колпачка");
	  	puts("4. Изменить первый цвет ручки");
	  	puts("5. Изменить второй цвет ручки");
	  	puts("Введите число:");
	  	scanf("%d", &n);
	  	fflush(stdin);
	  	  if(n<0 || n>5)
	  	    puts("Ошибка. Введен неверный номер.");
	  }
	while(n<0 || n>5);
	switch(n)
	  {
	  	case 1:
	  				do
			  	  	  {
			  	  	  	puts("Введите толщину пера\nОт 0,1 до 3");
		    		    scanf("%f", &pen1->Pens.feather);
		    		    fflush(stdin);
		    		    if(pen1->Pens.feather<0.1 || pen1->Pens.feather>3.0)
		    		      puts("Ошибка при вводе.\nПопробуйте ещё раз.");
			  	  	  }
			  	  	while(pen1->Pens.feather<0.1 || pen1->Pens.feather>3.0);
			  	  	break;
		case 2:
					do
		    		  {
		    		  	puts ("Тип ручки\n1)Шариковая\n2)Гелиевая\nВведите число:");
		    		  	scanf("%d", &pen1->Pens.ink);
		        		fflush(stdin);
		        		if(pen1->Pens.ink>2 || pen1->Pens.ink<1)
		        		  puts("Ошибка при вводе.\nПопробуйте ещё раз.");
		    		  }
		    		while(pen1->Pens.ink>2 || pen1->Pens.ink<1);
		    		break;
		case 3:
					do
		    		  {
		    		  	puts ("Колпачок:\n1) Есть\n2) Нет\nВведите чило");
		    		  	scanf("%d", &pen1->Pens.cap);
		    			fflush(stdin);
		    			if(pen1->Pens.cap>2 || pen1->Pens.cap<1)
		        		  puts("Ошибка при вводе.\nПопробуйте ещё раз.");
		    		  }
		    		while(pen1->Pens.cap>2 || pen1->Pens.cap<1);
		    		break;
		case 4:
					puts ("Введите первый цвет ручки");
		    		puts ("1) Синий     4)Зеленый");
		    		puts ("2) Черный    5)Желтый");
		    		puts ("3) Красный   6)Фиолетовый");
		    		do
		    	      {
		    		  	scanf("%d", &pen1->Pens.Color.color1);
		    			fflush(stdin);
		    			if(pen1->Pens.Color.color1>6 || pen1->Pens.Color.color1<1)
		        		  puts("Ошибка при вводе.\nПопробуйте ещё раз:");
		    		  }
		    		while(pen1->Pens.Color.color1>6 || pen1->Pens.Color.color1<1);
		    		break;
		case 5:
					puts ("Введите второй цвет ручки");
		    		puts ("1) Синий     4)Зеленый");
		    		puts ("2) Черный    5)Желтый");
		    		puts ("3) Красный   6)Фиолетовый");
		    		do
		    	      {
		    		  	scanf("%d", &pen1->Pens.Color.color2);
		    			fflush(stdin);
		    			if(pen1->Pens.Color.color2>6 || pen1->Pens.Color.color2<1)
		        		  puts("Ошибка при вводе.\nПопробуйте ещё раз:");
		    		  }
		    		while(pen1->Pens.Color.color2>6 || pen1->Pens.Color.color2<1);
		    		break;
	  }
  }
//--------------------------------------------------
//Функция выбора списка для редактирования
int controlEditing()
  {
  	int x;
  	do
  	  {
  	    puts("1 - Редактировать исходные данные");
  	    puts("2 - Редактировать найденные данные");
  	    puts("3 - Вернуться в главное меню");
  	    puts("Введите число");
  	    scanf("%x", &x);
  	    fflush(stdin);
  	    if(x<0 || x>3)
  	      puts("Ошибка при вводе.\nПопробуйте ещё раз");
  	  }
  	while(x<0 || x>3);
  	if(x==1 || x==2)
  	  return x;
  	else
  	  return 0;
  }
//***************************************************************************************************
//Работа с файлом
//***************************************************************************************************
//Функция записи в файл
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
//Функция чтения файла
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
//Функция ввода названия файла
const char* fileName(int key)
{
    system("cls");
    char a[15], *name;
    if(key==1)
        puts("Введите имя файла.\nЕсли такого файла не существует, файл создастся.\nЕсли существует, файл перезапишется.\n");
    else
      {
      	do
      	  {
	      	puts("1. Ввести имя файла");
	      	puts("2. Считать демонстрационный файл");
	      	scanf("%d", &key);
	      	fflush(stdin);
	      	if(key<1 || key>2)
	      	  puts("Ошибка. Повторите ввод");
	      }
	    while(key<1 || key>2);
      }
    if(key==1)
      {
	    puts("Имя файла: ");
	    do
	     {
	      scanf("%s", &a);
	      fflush(stdin);
	      if(strlen(a)<1 || strlen(a)>15)
	      printf("Ошибка при вводе (кол-во символов не превышает 20)\nПовторите ввод: ");
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
//Функция выбора списка для редактирования
int controlFiling()
  {
  	int x;
  	do
  	  {
  	    puts("1 - Записать исходные данные");
  	    puts("2 - Записать найденные данные");
  	    puts("3 - Вернуться в главное меню");
  	    puts("Введите число");
  	    scanf("%x", &x);
  	    fflush(stdin);
  	    if(x<0 || x>3)
  	      puts("Ошибка при вводе.\nПопробуйте ещё раз");
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
    	puts("Программа предназначена для работы с данными о ручках.\n");
    	puts("Она позволяет:\n1) Искать введённые данные по двум критериям:");
    	puts("  а) Толщина пера ручки\n  б)Тип ручки (шариковая или гелиевая)\n");
    	puts("2) Сортировать введенные или найденные данные по возрастанию значения толщины пера.\n");
    	puts("3) Добавлять элементы на любую позицию списка.\n");
    	puts("4) Удалять элементы с любой позиции списка.\n");
    	puts("5) Записывать их в файл с целью хранения.\n");
    	puts("6) Считывать структуры, хранящиеся в файле.\n");
    	puts("7) Редактировать.\n");
    }
//----------------------------------------------------------------
