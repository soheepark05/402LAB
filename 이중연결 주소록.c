//<<���߿��Ḯ��Ʈ �ּҷ�>>
//explore 


#pragma warning(disable:4996) //scanf�����ߴ°�
#include <stdio.h> //��ó����
#include <string.h>   //strcmp,strcpy
#include <windows.h> //system("cls")
#include <stdlib.h> //malloc, free ����

typedef struct people {         
	char name[50];   //50�̸�   //����ü(struct)�� �ٸ���? typedef�� 
	int age;      //4����		//����ü�� ����Ϸ��� ������ �����ؾߵǴµ� ...����ü ��Ī�� ������������ 
	char phonenumber[15];//��ȣ		//struct�� �޸� structŰ���带 �����ϰ� ����ü ��Ī���� �ٷ� ���������ϸ��
	//54+15 +8 77�̻� 64bit /32bit 
	struct people* prev; //�������
	struct people* next;	//�������

}people;   //��Ī



int num; //num�� 1��2�� ���׷���
people * head;		//����ü ��Ī���� �ٷ� ����������.
people * tail;
people * temp;
people * newnode;

void initnode(); //�Լ�����
void insert();
void show();
void search();
void removin();
void explore();

int main() //main�Լ�
{
	int choice; //�޴� ����
	initnode();		//�ʱ��弳���ϴ� �Լ�����
	while (1)		//while������ �޴� ��ӹް�����
	{
		printf("���ϴ� �޴��� �������ּ���\n");		//launcher
		printf("1.�Է� 2.��� 3.�˻� 4.���� 5.Ž�� 6.����\n");
		printf("=======================================");
		printf("\n����: ");
		scanf("%d", &choice);      //����ġ �޴� ����

		switch (choice)		//choice������ ���ư��� switch��
		{
		case(1): //�Է�      
			insert();
			break;
		case(2): //���         
			show();
			break;
		case(3): //�˻�
			search();
			break;
		case(4): //����         
			removin();
			break;
		case(5)://Ž��         
			explore();
			break;
		case(6)://����
			return 0;

		default:   //�ٸ��� �Է�������      
			printf("1-5���̷� �ٽ� �Է����ּ���.");
			break;
		}
		system("pause");		//�����Է¹��������� �Ͻ����� 
		system("cls");		//ȭ�������
	}
	return 0;
}
//�޸𸮱��� 3�� (heap:�����Ҵ��Ҷ� data:����ƽ������������ stack: ��������,�Ű�����)  lifo data: ����. 
void initnode() //����ʱ⼳���Լ�
{
	num = 0;//malloc�� �̿��Ͽ� �޸𸮰����� �Ҵ��ϰ� ����ü�������� ����
	head = (people *)malloc(sizeof(people)); //head������
	tail = (people *)malloc(sizeof(people)); //tail������
	head->prev = NULL;	// [null]=[head]=[tail]=[null]
	head->next = tail;
	tail->prev = head;
	tail->next = NULL;

}
void insert() //�����Լ�
{
	
	//people *newnode;//
	people *newnode = (people *)malloc(sizeof(people));   //malloc�� ���۰��� ù�ּ�
	people *temp;
	temp = head;

	printf("�̸�: ");
	scanf("%s", newnode->name);
	printf("����: ");
	scanf("%d", &newnode->age);
	printf("��ȣ: ");
	scanf("%s", newnode->phonenumber);//
	//[head] <-> [newnode] <->[tail] ����?

	if (head->next == tail) //���� �ϳ���������
	{
		tail->prev = newnode;
		newnode->prev = head;
		head->next = newnode;
		newnode->next = tail;
	}
	else //����������.
	{

		newnode->next = tail;
		newnode->prev = tail->prev;
		tail->prev = newnode;
		while (temp->next != tail) //������ �ؽ�Ʈ�� ������ �ƴҶ� ����
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
		printf("����Ұ��� ����");
	}
	else
	{
		while (temp->next != tail)
		{
			temp = temp->next;
			printf("%d�� �̸�:%s ����:%d ��ȣ:%s \n", count, temp->name, temp->age, temp->phonenumber);

			count++;
		}
	}
}

void search()
{
	int count = 1;
	int yesno = 0; //��ġ�ϴ� �̸� ������ ������
	char find[50]; //�˻����̸�

	if (num == 0) //�ּҷ� ����������
	{
		printf("�˻��� �̸��� ����");
	}
	else //�ּҷ� �Ⱥ���������
	{
		printf("�˻��� �̸��� �Է����ּ���: ");
		scanf("%s", &find);
		temp = head;
		while (temp->next != tail)
		{
			temp = temp->next;
			if (strcmp(find, temp->name) == 0) //strcmp
			{
				yesno = 1;

				printf("%d��: �̸�: %s ����:%d ��ȣ:%s \n\n", count, temp->name, temp->age, temp->phonenumber);
				count++;
			}
		}\
		if (yesno == 0)
		{
			printf("--------------<<��ġ�ϴ� �̸� �����>>--------------\n");
		}

	}

}
void removin()//
{ 
	int yesno = 0;
	int count = 0;
	int key;
	char find[50];
	if (num == 0) //�ּҷ� �������
	{
		printf("�˻��� �̸��� ����");
	}
	else//������
	{

		printf("�˻��� �̸��� �Է����ּ���: ");
		scanf("%s", &find);
		temp = head;
		while (temp->next != tail) //������ �ִ��� ����
		{
			temp = temp->next;
			if (strcmp(find, temp->name) == 0)//����
			{
				yesno = 1;
				count++;//ī��Ʈ�ǰ�

				printf("count:%d , �̸�: %s ����:%d ��ȣ:%s \n\n\n", count, temp->name, temp->age, temp->phonenumber);//���///***�ι������ȳѾ
				printf("�����Ͻðڽ��ϱ�?(1.y/2.n)");
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
			printf("\n\n<<-----�����Ϸ�----->>\n\n");
			break;

		case(2):
			break;

		default:
			printf("1Ȥ�� 2�� �Է����ּ���.\n");
			break;

		}


	}

}
void explore()//
{
	people * temp2;
	temp2 = head->next;

	char AorD;   //�������ΰ����� ���������� ������
	if (num == 0)//���࿡ �ּҷ��� ������ ����
	{
		printf("<<-----Ž���� �̸��� ����----->>");
		
	}
	printf("<<------������ Ž�����----->>\n");
	printf("�̸�: %s ����:%d ��ȣ:%s \n\n\n", temp2->name, temp2->age, temp2->phonenumber);
	while (1)//���ᴩ�������� �ϴ� ��ӵ�
	{
		
		printf(">>���� �Ǵ� ���������� �̵��ϼ���(A:����/ D:������/ Q:����)\n");

		while (getchar() != '\n');
		scanf("%c", &AorD);

		switch (AorD)
		{
		case('a')://�������� �̵�
		case('A'):
			if (temp2->prev != head)
			{
				temp2 = temp2->prev;
				printf("�̸�: %s ����:%d ��ȣ:%s \n\n\n", temp2->name, temp2->age, temp2->phonenumber);
			}
			else
			{
				printf("���̻� �������� �� �� ����\n");
			}
			break;




		case('d')://���������� �̵�
		case('D'):
			if (temp2->next != tail)
			{
				temp2 = temp2->next;
				printf("�̸�: %s ����:%d ��ȣ:%s \n\n\n", temp2->name, temp2->age, temp2->phonenumber);
			}
			else
			{
				printf("�̸�: %s ����:%d ��ȣ:%s \n\n\n", temp2->name, temp2->age, temp2->phonenumber);
				printf("���̻� ���������� �� �� ����\n");
			}
			break;

		case('q'):
		case('Q'):

			return;

		default:
			printf("a�� d�� �Է����ּ���.");
			break;
		}

	
	}
}



