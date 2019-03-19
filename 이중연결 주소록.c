//<<이중연결리스트 주소록>>
//explore 


#pragma warning(disable:4996) //scanf오류뜨는거
#include <stdio.h> //전처리기
#include <string.h>   //strcmp,strcpy
#include <windows.h> //system("cls")
#include <stdlib.h> //malloc, free 쓸때

typedef struct people {         
	char name[50];   //50이름   //구조체(struct)와 다른점? typedef는 
	int age;      //4나이		//구조체를 사용하려면 변수를 선언해야되는데 ...구조체 별칭을 선언했음으로 
	char phonenumber[15];//번호		//struct와 달리 struct키워드를 생략하고 구조체 별칭으로 바로 변수선언하면됨
	//54+15 +8 77이상 64bit /32bit 
	struct people* prev; //이전노드
	struct people* next;	//다음노드

}people;   //별칭



int num; //num은 1번2번 뭐그런거
people * head;		//구조체 별칭으로 바로 변수선언함.
people * tail;
people * temp;
people * newnode;

void initnode(); //함수선언
void insert();
void show();
void search();
void removin();
void explore();

int main() //main함수
{
	int choice; //메뉴 선택
	initnode();		//초기노드설정하는 함수선언
	while (1)		//while문으로 메뉴 계속받게했음
	{
		printf("원하는 메뉴를 선택해주세요\n");		//launcher
		printf("1.입력 2.출력 3.검색 4.삭제 5.탐색 6.종료\n");
		printf("=======================================");
		printf("\n선택: ");
		scanf("%d", &choice);      //스위치 메뉴 선택

		switch (choice)		//choice값으로 돌아가는 switch문
		{
		case(1): //입력      
			insert();
			break;
		case(2): //출력         
			show();
			break;
		case(3): //검색
			search();
			break;
		case(4): //삭제         
			removin();
			break;
		case(5)://탐색         
			explore();
			break;
		case(6)://종료
			return 0;

		default:   //다른거 입력했을때      
			printf("1-5사이로 다시 입력해주세요.");
			break;
		}
		system("pause");		//다음입력받을때까지 일시정지 
		system("cls");		//화면지우기
	}
	return 0;
}
//메모리구조 3개 (heap:동적할당할때 data:스태틱변수전역변수 stack: 지역변수,매개변수)  lifo data: 구조. 
void initnode() //노드초기설정함수
{
	num = 0;//malloc을 이용하여 메모리공간을 할당하고 구조체형변수를 생성
	head = (people *)malloc(sizeof(people)); //head노드생성
	tail = (people *)malloc(sizeof(people)); //tail노드생성
	head->prev = NULL;	// [null]=[head]=[tail]=[null]
	head->next = tail;
	tail->prev = head;
	tail->next = NULL;

}
void insert() //삽입함수
{
	
	//people *newnode;//
	people *newnode = (people *)malloc(sizeof(people));   //malloc은 버퍼값의 첫주소
	people *temp;
	temp = head;

	printf("이름: ");
	scanf("%s", newnode->name);
	printf("나이: ");
	scanf("%d", &newnode->age);
	printf("번호: ");
	scanf("%s", newnode->phonenumber);//
	//[head] <-> [newnode] <->[tail] 상태?

	if (head->next == tail) //값이 하나도없을때
	{
		tail->prev = newnode;
		newnode->prev = head;
		head->next = newnode;
		newnode->next = tail;
	}
	else //값이있을때.
	{

		newnode->next = tail;
		newnode->prev = tail->prev;
		tail->prev = newnode;
		while (temp->next != tail) //템프의 넥스트가 테일이 아닐때 실행
		{
			temp = temp->next;
		}
		temp->next = newnode;

	}
	num++;

}
void show()
{
	temp = head;
	int count = 1;
	if (num == 0)  //nonumber
	{
		printf("출력할것이 없음");
	}
	else
	{
		while (temp->next != tail)
		{
			temp = temp->next;
			printf("%d번 이름:%s 나이:%d 번호:%s \n", count, temp->name, temp->age, temp->phonenumber);

			count++;
		}
	}
}

void search()
{
	int count = 1;
	int yesno = 0; //일치하는 이름 있을때 없을때
	char find[50]; //검색할이름

	if (num == 0) //주소록 비어있을경우
	{
		printf("검색할 이름이 없음");
	}
	else //주소록 안비어있을경우
	{
		printf("검색할 이름을 입력해주세요: ");
		scanf("%s", &find);
		temp = head;
		while (temp->next != tail)
		{
			temp = temp->next;
			if (strcmp(find, temp->name) == 0) //strcmp
			{
				yesno = 1;

				printf("%d번: 이름: %s 나이:%d 번호:%s \n\n", count, temp->name, temp->age, temp->phonenumber);
				count++;
			}
		}\
		if (yesno == 0)
		{
			printf("--------------<<일치하는 이름 없어요>>--------------\n");
		}

	}

}
void removin()//
{ 
	int yesno = 0;
	int count = 0;
	int key;
	char find[50];
	if (num == 0) //주소록 없을경우
	{
		printf("검색할 이름이 없음");
	}
	else//있을때
	{

		printf("검색할 이름을 입력해주세요: ");
		scanf("%s", &find);
		temp = head;
		while (temp->next != tail) //같은거 있는지 보고
		{
			temp = temp->next;
			if (strcmp(find, temp->name) == 0)//같다
			{
				yesno = 1;
				count++;//카운트되고

				printf("count:%d , 이름: %s 나이:%d 번호:%s \n\n\n", count, temp->name, temp->age, temp->phonenumber);//출력///***두번쨰노드안넘어감
				printf("삭제하시겠습니까?(1.y/2.n)");
				scanf("%d", &key); //y/n
			}

			if (yesno)
			{
				break;
			}
					   
		}

		switch (key)
		{

		case(1):
			
			temp->next->prev = temp->prev;
			temp->prev->next = temp->next;
			free(temp);
			printf("\n\n<<-----삭제완료----->>\n\n");
			break;

		case(2):
			break;

		default:
			printf("1혹은 2를 입력해주세요.\n");
			break;

		}


	}

}
void explore()//
{
	people * temp2;
	temp2 = head->next;

	char AorD;   //왼쪽으로갈껀지 오른쪽으로 갈껀지
	if (num == 0)//만약에 주소록이 없으면 실행
	{
		printf("<<-----탐색할 이름이 없음----->>");
		
	}
	printf("<<------현재의 탐색결과----->>\n");
	printf("이름: %s 나이:%d 번호:%s \n\n\n", temp2->name, temp2->age, temp2->phonenumber);
	while (1)//종료누를떄까지 일단 계속돌
	{
		
		printf(">>왼쪽 또는 오른쪽으로 이동하세요(A:왼쪽/ D:오른쪽/ Q:종료)\n");

		while (getchar() != '\n');
		scanf("%c", &AorD);

		switch (AorD)
		{
		case('a')://왼쪽으로 이동
		case('A'):
			if (temp2->prev != head)
			{
				temp2 = temp2->prev;
				printf("이름: %s 나이:%d 번호:%s \n\n\n", temp2->name, temp2->age, temp2->phonenumber);
			}
			else
			{
				printf("더이상 왼쪽으로 갈 수 없음\n");
			}
			break;




		case('d')://오른쪽으로 이동
		case('D'):
			if (temp2->next != tail)
			{
				temp2 = temp2->next;
				printf("이름: %s 나이:%d 번호:%s \n\n\n", temp2->name, temp2->age, temp2->phonenumber);
			}
			else
			{
				printf("이름: %s 나이:%d 번호:%s \n\n\n", temp2->name, temp2->age, temp2->phonenumber);
				printf("더이상 오른쪽으로 갈 수 없음\n");
			}
			break;

		case('q'):
		case('Q'):

			return;

		default:
			printf("a와 d만 입력해주세요.");
			break;
		}

	
	}
}



