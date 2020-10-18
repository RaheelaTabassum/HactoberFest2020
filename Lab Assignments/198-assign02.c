#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <time.h>


#define FOR(i,a,b) for(int i=a ; i<b ; i++)
#define BFOR(i,a,b) for(int i=b ; i>=a ; i--)

void Add();						//To add The Student data in the Database
void Find_Roll();				//To Find The Student by its Roll Number
void Find_Course_id();			//To Find The Student by its Course ID
void Display_total();			//To Display The Total Number of Students with their Data
void Course_Summary();			//To Print The Course Summary i.e Number of Students Registered for Particular Course
void display(int i);			//To Dislpay The record by the Roll Number passed as a parameter

int n=0,z=1,alr=0;				//[n : To Count The Number of Record] [z : Used to Terminate The while loop] [alr : Used for alternate element] 

int poppulate(int n)
{
    if(n == 0)
        return 0;
    if((n == 1)||(n == 2))
        return 1;
    else
        return poppulate(n-1) + poppulate(n-3);
        
}

void Answer_1()
{
    printf("Answer number 1\n");
    int arr[30];
    memset(arr , 0 , sizeof(arr));
    printf("The Initial Array without populating the elements :\n");
    FOR(i,0,30)
        printf("%d ",arr[i]);
    printf("\n");
    FOR(i,0,30)
        arr[i] = poppulate(i);
    printf("After Poppulating the Array becomes :: \n");
    FOR(i,0,30)
        printf("%d ",arr[i]);
}

typedef struct DATA
{
    char name[30];
    float salary;
}Faculty;

void increment_salary(Faculty F[] , int N)
{
    FOR(i,0,N)
        F[i].salary += 0.2 * F[i].salary;
}
void Answer_4() 
{
    printf("\nAnswer number 4\n");
    int N;
    printf("Input The number of faculty data you want to store :: ");
    scanf("%d",&N);
    Faculty F[N];
    FOR(i,0,N)
    {
        printf("Input the faculty Name   :: ");
        scanf("%s" , F[i].name);
        printf("Input the Faculty Salary :: ");
        scanf("%f" , &F[i].salary);
        printf("\n");
    }
    printf("!!Record has been stored !!\n");
    printf("The Recorded Data is ::\n\n");
    FOR(i,0,N)
    {
        printf("Record Number %d :: \n",i+1);
        printf("Name   : %s\n",F[i].name);
        printf("Salary : %0.3f\n",F[i].salary);
        printf("\n");   
    }
    printf("The Salary After Incrementing is(20 Percent only)!!! \n");
    increment_salary(F , N);
    FOR(i,0,N)
    {
        printf("Record Number %d :: \n",i+1);
        printf("Name   : %s\n",F[i].name);
        printf("Salary : %0.3f\n",F[i].salary);
        printf("\n");   
    }
}

//Strucure Of the Student Database :-

typedef struct database
{
	char First_Name[20];		//Input the First Name of the Student
	char Last_Name[20];			//Input the Last Name of the Student
	int Roll_number;			//Input the Roll Number of the Student
	int course_id[5];			//Input The Course ID Offered To The Students

}data;

//Creating The Objects of The Structure (Max 100) :-

data record[100];				//Record as a Object of The Structure [DATABASE]

void Answer_5()						//Programming Starting Area
{
    printf("\nAnswer number 5\n");
	while(z){
		char ch;
		printf("\n_______________________________________________________________________");
		printf("\n|\t\t :: Welome to the Student Database ::                 |");
		printf("\n|                                                                     |");
		printf("\n|(Press respective alphabets(lowercase) to choose the desired Option) |");
		printf("\n|                                                                     |");
		printf("\n|\ta) Add The Database of the Students                           |");
		printf("\n|\tb) Find The Student by the Roll_number                        |");
		printf("\n|\tc) Find The Student by the Course-Id                          |");
		printf("\n|\td) Print the Course Summary                                   |");
		printf("\n|                                                                     |");
		printf("\n|\t\t :: Press (X/x) To Exit The Code ::                   |");
		printf("\n-----------------------------------------------------------------------");
		printf("\n\nNow Input Which Operation you Want to Perform :: ");
		scanf(" %c",&ch);					//Input Of the User Desired Choice
		switch(ch)							//Select the User Desired Choice
		{
			case 'a':	Add();
						break;
			case 'b':	Find_Roll();
						break;
			case 'c':	Find_Course_id();
						break;
			case 'd':	Course_Summary();
						break;
			case 'x':
			case 'X':	exit(0);
		}
		printf("\nDo U want to Continue Your Operation(s) On the SOFTWARE (y/n) :: ");	//Asking for the Continuation or Termination
		getchar();
		scanf("%c",&ch);
		alr = 0;
		if(ch == 'n')
        {
            printf("Thanks For Using our Software!!!\n");
			z = 0;
        }
	}	
	exit(0);		//Exits The Code
}

void Add()		
{
	char ch;
	int flag=0;
	if(alr == 0){
		printf("\nYou Have Chosen the Add Function from The given Option(s)");
		printf("\n\nIf Chosen By Mistake You Can revert back otherwise Continue ");
		printf("\nPress (Y/y) to Continue and (B/b) to go Back to Main Menue :: ");
		getchar();
		scanf("%c",&ch);
		if((ch=='B')||(ch=='b'))
			return ;
	}
	printf("\nInput The First Name of the Student  :: ");
	scanf(" %s",record[n].First_Name);
	printf("Input The Last Name of the Student   :: ");
	scanf(" %s",record[n].Last_Name);
	printf("Input the Roll Number of the Student :: ");
	scanf(" %d",&record[n].Roll_number);
	printf("Input the CGPA of the Student        :: ");
	printf("Input The Course ID of The Student    ");
	printf("\n\n\tCourses are as follows :");
	printf("\n1 :: Computer Science ");
	printf("\n2 :: Digital Logic Design ");
	printf("\n3 :: Discrete Mathematics and Probability ");
	printf("\n4 :: Communication Skills ");
	printf("\n5 :: Overwiew of Computers");
	printf("\n\n\t\t---NOTE--- ");
	printf("\nInput 'One' to Accept and 'Zero' to Reject The Course \n\n");
	for(int i=0 ; i<5 ; i++){
		printf("Do You Want to Accept The Course %d :: ",i+1);
		scanf(" %d",&record[n].course_id[i]);
	}
	if(n!=0){
		for(int i=n-1 ; i>=0 ; i--)
			if(record[n].Roll_number == record[i].Roll_number){
				printf("\n!! The Record Already Exists !!\n");
				flag = 1;
				alr = 1;
			}
	}
	if(flag == 1){
		printf("\nYou Have To Again Input The Record ");
		Add();
	}
	++n;
}

void Find_Roll()
{
	char ch;
	int roll , flag=0;
	if(alr == 0){
		printf("\nYou Have Chosen the Search by Roll Number Function from The given Option(s)");
		printf("\n\nIf Chosen By Mistake You Can revert back otherwise Continue ");
		printf("\nPress (Y/y) to Continue and (B/b) to go Back to Main Menue :: ");
		getchar();
		scanf("%c",&ch);
		if((ch=='B')||(ch=='b'))
			return ;
	}
	printf("\nInput The Roll_number to be Searched :: ");
	scanf("%d",&roll);
	for(int i=n-1 ; i>=0 ; i--){
		if(roll == record[i].Roll_number){
			display(i);
			flag=1;
			break;
		}
	}
	if(flag == 0)
		printf("\n\t!!! Roll Number Not Found !!!\n");
}

void Find_Course_id()
{
	char ch;
	int course , flag=0;
	if(alr == 0){
		printf("\nYou Have Chosen the Search by Course-Id Function from The given Option(s)");
		printf("\n\nIf Chosen By Mistake You Can revert back otherwise Continue ");
		printf("\nPress (Y/y) to Continue and (B/b) to go Back to Main Menue :: ");
		getchar();
		scanf("%c",&ch);
		if((ch=='B')||(ch=='b'))
			return ;
	}
	printf("\n1 :: Computer Science ");
	printf("\n2 :: Digital Logic Design ");
	printf("\n3 :: Discrete Mathematics and Probability ");
	printf("\n4 :: Communication Skills ");
	printf("\n5 :: Overwiew of Computers\n");
	printf("\nInput The Couse ID to be Searched :: ");
	scanf("%d",&course);
	for(int i=n-1 ; i>=0 ; i--){
		if(record[i].course_id[course-1] == 1){
			display(i);
			flag=1;
		}
	}
	if(flag == 0)
		printf("\n\t!!! No Such Course ID Registerd !!!\n");
}

void Display_total()
{
	char ch;
	if(alr == 0){
		printf("\nYou Have Chosen the Display Function from The given Option(s)");
		printf("\n\nIf Chosen By Mistake You Can revert back otherwise Continue ");
		printf("\nPress (Y/y) to Continue and (B/b) to go Back to Main Menue :: ");
		getchar();
		scanf("%c",&ch);
		if((ch=='B')||(ch=='b'))
			return ;
	}
	// Displaying Total Number Of Students With The Complete Details 
	int j=0;
	FOR(i,0,n)
		if(record[i].Roll_number != 0)
			j++;
	printf("\nThe Total Number Of Students Registerd in the Database are :: %d\n",j);
	printf("\nThe Total Database Of the Registerd Students are :- \n");
	for(int i=0,l=1 ; i<n ; i++){
		if(record[i].Roll_number != 0){
			printf("\nThe %d record is :- \n",l);
			display(i);
			l++;
		}
	}
}

void Course_Summary()
{
	char ch;
	if(alr == 0){
		printf("\nYou Have Chosen the Course Summary Function from The given Option(s)");
		printf("\n\nIf Chosen By Mistake You Can revert back otherwise Continue ");
		printf("\nPress (Y/y) to Continue and (B/b) to go Back to Main Menue :: ");
		getchar();
		scanf("%c",&ch);
		if((ch=='B')||(ch=='b'))
			return ;
	}
	printf("\nThe Number Of Students Registerd In Each Courses :- ");
	int j[5];
	FOR(i,0,5)
			j[i] = 0;
	FOR(i,0,n){
		if(record[i].Roll_number != 0){
			if(record[i].course_id[0] == 1)
				j[0]++;
			if(record[i].course_id[1] == 1)
				j[1]++;
			if(record[i].course_id[2] == 1)
				j[2]++;
			if(record[i].course_id[3] == 1)
				j[3]++;
			if(record[i].course_id[4] == 1)
				j[4]++;
		}
	}
	printf("\nThe Number Of Students Registerd in 1st Course (Computer Science) are                     :: %d",j[0]);
	printf("\nThe Number Of Students Registerd in 2nd Course (Digital Logic Design) are                 :: %d",j[1]);
	printf("\nThe Number Of Students Registerd in 3rd Course (Discrete Mathematics and Probability) are :: %d",j[2]);
	printf("\nThe Number Of Students Registerd in 4th Course (Communication Skills) are                 :: %d",j[3]);
	printf("\nThe Number Of Students Registerd in 5th Course (Overwiew of Computers) are                :: %d\n",j[4]);
}

void display(int i)
{
	int j=0;
	printf("\nThe First Name Of The Student is  :: %s",record[i].First_Name);
	printf("\nThe Last Name Of The Student is   :: %s",record[i].Last_Name);
	printf("\nThe Roll Number Of The Student is :: %d",record[i].Roll_number);
	FOR(k,0,5)
		if(record[i].course_id[k] == 1)
			j++;
	printf("\nThe Student Is Registerd is %d Course(s) \n\n",j);
}

void reverse(char *str , int N)
{
    FOR(i,0,N/2)
    {
        char temp = str[N-i-1];
        str[N-i-1] = str[i];
        str[i] = temp;
    }
}
void Answer_2()
{
    int N;
    printf("\n\nAnswer number 2\n");
    printf("Input the Length of String :: ");
    scanf("%d",&N);
    char *str = (char*)malloc((N+1)*sizeof(char));
    printf("Input The String           :: ");
    scanf("%s",str);
    reverse(str , N);
    printf("The Reversed String is     :: ");
    printf("%s\n" , str);
}

void swap(int *no1 , int *no2)
{
    *no1 = *no1 ^ *no2;
    *no2 = *no1 ^ *no2;
    *no1 = *no1 ^ *no2;
}
void Answer_3()
{
    printf("\nAnswer number 3\n");
    int *no1 , *no2;
    no1 = (int*)malloc(sizeof(int));
    no2 = (int*)malloc(sizeof(int));
    printf("Input The Two Number(s) :: ");
    scanf("%d %d",no1 , no2);
    printf("The value of the Numbers before swapping is :: \n");
    printf("a = %d and b = %d\n",*no1,*no2);
    swap(no1 , no2);
    printf("The value of the Numbers after swapping is :: \n");
    printf("a = %d and b = %d\n",*no1,*no2);
}
int main()
{
    Answer_1();
    Answer_2();
    Answer_3();
    Answer_4();
    Answer_5();
    return 0;
}