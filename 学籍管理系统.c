#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN sizeof(struct SSI)
struct SSI                          //student status information ��д 
{
	char no[20];              //ѧ��
	char name[20];            //���� 
	char sex[4];              //�Ա� 
	char age[4];              //���� 
	char area[50];            //���� 
	char academy[50];         //Ժϵ
	char professional[50];    //רҵ 
	char clas[20];            //�༶ 
	char state[20];           //ѧ��״̬
	struct SSI *next; 
};

int SAVEnew(struct SSI *p)          //������Ϣ�����ļ��� 
{
	FILE *fp,*f_p;
	if((fp=fopen("��Ϣ����.txt","a"))==NULL)
	{
		printf("�ļ���ʧ��!\n");
		return-1;
	}
	char password[20]={'1','2','3','4','5','6'};
	fprintf(fp,"%s %s %s %s %s %s %s %s %s\n",p->no,p->name,p->sex,p->age,p->area,p->academy,p->professional,p->clas,p->state);
	//�˴�����Ļ��з��Ժ��������д��һ��Ӱ��
	//�������Ϊ�ڽ���Ϣ��������ʱ�������һ������ڵ� 
	//��Ϊ�����ļ��в鿴�Ե����ۣ����Ա����˸�ʽ���� 
	fclose(fp);
	printf("��Ϣ����ɹ�\n");
	return 1; 
}

struct SSI *creat(void)             //������������Ϣ¼�룩 
{
	int choice;
	struct SSI *head,*p1,*p2; 
	int i=1;
	while(1)
	{	
	    system("cls");
	    printf("��ע��1.�Ա�һ��Ϊ�л�Ů\n");
	    printf("      2.ѧ��״̬��Ϊ����ѧ���ڶ���תרҵ����ѧ����������ѧ����ҵ\n");
	    printf("      3.ѧ�ţ��������༶ѧ��״̬�������ƾ�Ϊ20�ַ����Ա����䳤������Ϊ4���ַ������ᣬѧԺרҵ�ض�����Ϊ50�ַ�\n");
	    p1=(struct SSI*)malloc(LEN);
		printf("������ѧ��ѧ�ţ�");
		scanf("%s",&p1->no);
		printf("������ѧ��������");
		scanf("%s",&p1->name);
		printf("������ѧ���Ա�");
		scanf("%s",&p1->sex);
		printf("������ѧ�����䣺");
		scanf("%s",&p1->age);
		printf("������ѧ�����᣺");
		scanf("%s",&p1->area);
		printf("������ѧ��Ժϵ��");
		scanf("%s",&p1->academy);
		printf("������ѧ��רҵ��");
		scanf("%s",&p1->professional);
		printf("������ѧ���༶��");
		scanf("%s",&p1->clas);
		printf("������ѧ��״̬��");
		scanf("%s",&p1->state);
		SAVEnew(p1);
		if(i==1)
		{
			head=p1;
		}else
		{
			p2->next=p1;
		}
		p2=p1;
		i++;
		printf("����¼���밴0������¼���밴�������֣�");  
		scanf("%d",&choice);
		if(choice==0)
		{
			p1->next=NULL;
			return head;
		} 
	}
 } 
 
void Fre(struct SSI *head)          //�ͷ�ԭ������ռ�ڴ� 
{
	struct SSI *p1,*p2;
	p1=head;
	while(p1->next!=NULL)
	{
		p2=p1->next;
		free(p1);
		p1=p2;
	}
	free(p1);
 } 
 
struct SSI *chain()                 //��ȫ����Ϣ��ȡ�������� 
{
	FILE *fp;
	fp=fopen("��Ϣ����.txt","r");
	struct SSI *head,*p1,*p2;
	 int i=1;
	 while(!feof(fp))                     //δ�����ļ�����������ִ��ѭ�� 
	 {
	 	p1=(struct SSI*)malloc(LEN);
	 	fscanf(fp,"%s",p1->no);
	 	fscanf(fp,"%s",p1->name);
	 	fscanf(fp,"%s",p1->sex);
	 	fscanf(fp,"%s",p1->age);
	 	fscanf(fp,"%s",p1->area);
	 	fscanf(fp,"%s",p1->academy);
	 	fscanf(fp,"%s",p1->professional);
	 	fscanf(fp,"%s",p1->clas);
	 	fscanf(fp,"%s",p1->state);
	 	if(i==1)
		{
			head=p1;
		}else
		{
			p2->next=p1;
		}
		p2=p1;
		i++;
	 }
	 p1->next=NULL;
     return head;
}
  
void Printdata()                    //��Ϣ�鿴 
{
	system("cls");
	struct SSI *head,*p;
	head=chain();
	p=head;
	if(head->next!=NULL)
	{
		printf("       ѧ  ��              ��  ��         �Ա�    ����           ��   ��                  ѧ   Ժ                  ר   ҵ              �� ��     ѧ��״̬\n\n");
		do
		{
			printf("%-20s%-20s%-8s",p->no,p->name,p->sex);
			printf("%-8s%-25s%-25s",p->age,p->area,p->academy); 
			printf("%-25s%-15s%-25s\n",p->professional,p->clas,p->state);
			printf("\n");
			p=p->next;
		}while(p->next!=NULL);                                                 //���ݶ�ȡʱ��������һ���ڵ� 
	 }else
	 {
	 	printf("\n\n\n\n\n\n\n\n");
	 	printf("                   ����Ϊ��,����¼����Ϣ");
	 	sleep(3);
	 	return;
	 }
	Fre(head);
	int choice2;
	printf("�������˵��밴�������ּ�\n");
	scanf("%d",&choice2);
	return ; 
}

void Wrongscanf()                   //�����������Ѻ��� 
{
   printf("      �������\n");
   sleep(3);                  
   return ; 
}

int SAVE(struct SSI *head)          //��Ϣ���������´��� 
{
	system("cls");
	struct SSI *p;
	FILE *fp;
	if((fp=fopen("��Ϣ����.txt","w"))==NULL)
	{
		printf("�ļ���ʧ��!\n");
		return -1;
	}
	p=head;
	printf("       ѧ  ��              ��  ��         �Ա�    ����           ��   ��                  ѧ   Ժ                  ר   ҵ              �� ��     ѧ��״̬\n\n");
	while(p->next!=NULL)
	{
		fprintf(fp,"%s %s %s %s %s %s %s %s %s\n",p->no,p->name,p->sex,p->age,p->area,p->academy,p->professional,p->clas,p->state);
		printf("%-20s%-20s%-8s",p->no,p->name,p->sex);
		printf("%-8s%-25s%-25s",p->age,p->area,p->academy); 
		printf("%-25s%-15s%-25s\n",p->professional,p->clas,p->state);
		printf("\n");
		p=p->next;
	}
	fclose(fp);
	printf("      ����Ϣ�ѱ���\n");
	sleep(3); 
	return;
}

void Delete()                       //��Ϣɾ�� 
{
	system("cls");
	struct SSI *head,*p1,*p2;
	head=chain();
	p1=head;
	char no3[20];
	int choice3,choice3_1;
	if(p1->next==NULL)
	{
		printf("\n\n\n\n\n\n\n\n");
	 	printf("                   ����Ϊ��,����¼����Ϣ");
		sleep(3);
		return ;
	}
	while(1)
	{
		printf("������ɾ������ѧ�ţ�");
		scanf("%s",&no3);
		printf("\n");
		while(p1->next!=NULL&&strcmp(p1->no,no3)!=0)
		{
		   
		    p2=p1;
		    p1=p1->next;
		}
		if(strcmp(p1->no,no3)==0)
		{
			printf("       ѧ  ��              ��  ��         �Ա�    ����           ��   ��                  ѧ   Ժ                  ר   ҵ              �� ��     ѧ��״̬\n\n");
			printf("%-20s%-20s%-8s",p1->no,p1->name,p1->sex);
			printf("%-8s%-25s%-25s",p1->age,p1->area,p1->academy); 
			printf("%-25s%-15s%-25s\n",p1->professional,p1->clas,p1->state);
			printf("\n");
			while(1)
			{
			    printf("ȷ��ɾ���밴1��ȡ���밴0:");
			    scanf("%d",&choice3_1);
			    printf("\n");
			    if(choice3_1==0)
			    {
			        printf("ȡ��ɾ��\n");
			        sleep(2);
			        break;
				}else if(choice3_1==1)
				{
					if(p1==head)
					{
						head=p1->next;
					}else
					{
						p2->next=p1->next;
					}
					free(p1);
					break;
				}else
				{
					Wrongscanf();	
				}
			}
	}else
	{
		printf("δ�ҵ�ɾ������\n");
	}
	printf("����ɾ���������˵��밴3,����ɾ���밴������:");
	scanf("%d",&choice3);
	if(choice3==3)
	{
		SAVE(head);
		Fre(head);
		return;
	} 
	}
}

void Lookup()                       //��Ϣ���� 
{
	system("cls");
	struct SSI *head,*p1,*p2;
	head=chain();
	p1=head;
	char no3[20];
	int choice4;
	if(p1->next==NULL)
	{
		printf("\n\n\n\n\n\n\n\n");
	 	printf("                   ����Ϊ��,����¼����Ϣ");
		sleep(3);
		return ;
	}
	while(1)
	{
		printf("��������Ҷ���ѧ�ţ�");
		scanf("%s",&no3);
		printf("\n");
		while(p1->next!=NULL&&strcmp(p1->no,no3)!=0)
		{
		   
		    p2=p1;
		    p1=p1->next;
		}
		if(strcmp(p1->no,no3)==0)
		{
			printf("       ѧ  ��              ��  ��         �Ա�    ����           ��   ��                  ѧ   Ժ                  ר   ҵ              �� ��     ѧ��״̬\n\n");
			printf("%-20s%-20s%-8s",p1->no,p1->name,p1->sex);
			printf("%-8s%-25s%-25s",p1->age,p1->area,p1->academy); 
			printf("%-25s%-15s%-25s\n",p1->professional,p1->clas,p1->state);
			printf("\n");
			
		}else
		{
			printf("���޴���\n");
		 } 
	printf("�������˵��밴4,���������밴������:");
	scanf("%d",&choice4);
	printf("\n");
	if(choice4==4)
	{
		Fre(head);
		return;
	} 
	}
}

void Modify()                       //��Ϣ�޸� 
{
	system("cls");
	struct SSI *head,*p1,*p2;
	char result5_1[20],result5_2[4],result5_3[50];//��ʱ����޸ĺ���Ϣ 
	head=chain();
	p1=head;
	char no5[20];
	int choice5,choice5_1,choice5_2,choice5_3;
	if(p1->next==NULL)
	{
		printf("\n\n\n\n\n\n\n\n");
	 	printf("                   ����Ϊ��,����¼����Ϣ");
		sleep(3);
		return ;
	}
	while(1)
	{
		system("cls");
		printf("�������޸Ķ���ѧ�ţ�");
		scanf("%s",&no5);
		printf("\n");
		printf("�����С�����");
		sleep(3); 
		system("cls");
		while(p1->next!=NULL&&strcmp(p1->no,no5)!=0)
		{
		    p2=p1;
		    p1=p1->next;
		}
		if(strcmp(p1->no,no5)==0)
		{
		    
	        while(1)
	        {
	        	system("cls");
		        printf("       ѧ  ��              ��  ��         �Ա�    ����           ��   ��                  ѧ   Ժ                  ר   ҵ              �� ��     ѧ��״̬\n\n");
			    printf("%-20s%-20s%-8s",p1->no,p1->name,p1->sex);
			    printf("%-8s%-25s%-25s",p1->age,p1->area,p1->academy); 
			    printf("%-25s%-15s%-25s\n",p1->professional,p1->clas,p1->state);
		        printf("\n\n");
		        printf("                           �޸Ĳ˵�\n");
	            printf("      ******************************************************\n");
	            printf("      *                                                    *\n");
	            printf("      *     1.�����޸�                2.�Ա��޸�           *\n");
	            printf("      *     3.�����޸�                4.�����޸�           *\n");
	            printf("      *     5.Ժϵ�޸�                6.רҵ�޸�           *\n");
	            printf("      *     7.�༶�޸�                8.ѧ��״̬�޸�       *\n");
	            printf("      *     0.�����޸�                                     *\n");
	            printf("      *                                                    *\n");
	            printf("      ******************************************************\n");
	        	printf("      ���������ѡ��(0~8)\n");
	        	printf("      ");
	            scanf("%d",&choice5_1);
	            if(choice5_1==0)
	            {
	            	break;
				}
	            switch(choice5_1)
	            {
	            	case 1:{
	            		    printf("      �޸�ǰ������%s\n",p1->name);
	            		    printf("      �޸ĺ�������");
	            		    scanf("%s",&result5_1);
						    while(1)
						    {
						    	printf("      �Ƿ�ȷ���޸ģ�0������1ȷ��)\n      ");
							    scanf("%d",&choice5_2);
						        if(choice5_2==1)
						        {
							        strcpy(p1->name,result5_1);
							        break;
						        }else if(choice5_2==0)
						        {
						 	         break;
						        } 
						         Wrongscanf();
						    }
					         break;
					        } 
	            	case 2:{
	            		    printf("      �޸�ǰ�Ա�%s\n",p1->sex);
	            		    printf("      �޸ĺ��Ա�");
	            		    scanf("%s",&result5_2);
						    while(1)
						    {
						    	printf("      �Ƿ�ȷ���޸ģ�0������1ȷ��)\n      ");
							    scanf("%d",&choice5_2);
						        if(choice5_2==1)
						        {
							        strcpy(p1->sex,result5_2);
							        break;
						        }else if(choice5_2==0)
						        {
						 	         break;
						        } 
						         Wrongscanf();
						    }
					 	     break;
					       }
	            	case 3:{
	            		    printf("      �޸�ǰ���䣺%s\n",p1->age);
	            		    printf("      �޸ĺ����䣺");
	            		    scanf("%s",&result5_2);
						    while(1)
						    {
						    	printf("      �Ƿ�ȷ���޸ģ�0������1ȷ��)\n      ");
							    scanf("%d",&choice5_2);
						        if(choice5_2==1)
						        {
							        strcpy(p1->age,result5_2);
							        break;
						        }else if(choice5_2==0)
						        {
						 	         break;
						        } 
						         Wrongscanf();
						    }
						    break;
					       }
	            	case 4:{
	            		    printf("      �޸�ǰ���᣺%s\n",p1->area);
	            		    printf("      �޸ĺ󼮹᣺");
	            		    scanf("%s",&result5_3);
						    while(1)
						    {
						    	printf("      �Ƿ�ȷ���޸ģ�0������1ȷ��)\n      ");
							    scanf("%d",&choice5_2);
						        if(choice5_2==1)
						        {
							        strcpy(p1->area,result5_3);
							        break;
						        }else if(choice5_2==0)
						        {
						 	         break;
						        } 
						         Wrongscanf();
						    }
						    break;
					       }
	            	case 5:{
	            		    printf("      �޸�ǰԺϵ��%s\n",p1->academy);
	            		    printf("      �޸ĺ�Ժϵ��");
	            		    scanf("%s",&result5_3);
						    while(1)
						    {
						    	printf("      �Ƿ�ȷ���޸ģ�0������1ȷ��)\n      ");
							    scanf("%d",&choice5_2);
						        if(choice5_2==1)
						        {
							        strcpy(p1->academy,result5_3);
							        break;
						        }else if(choice5_2==0)
						        {
						 	         break;
						        } 
						         Wrongscanf();
						    }
						    break;
					       }
	            	case 6:{
	            		    printf("      �޸�ǰרҵ��%s\n",p1->professional);
	            		    printf("      �޸ĺ�רҵ��");
	            		    scanf("%s",&result5_3);
						    while(1)
						    {
						    	printf("      �Ƿ�ȷ���޸ģ�0������1ȷ��)\n      ");
							    scanf("%d",&choice5_2);
						        if(choice5_2==1)
						        {
							        strcpy(p1->professional,result5_3);
							        break;
						        }else if(choice5_2==0)
						        {
						 	         break;
						        } 
						         Wrongscanf();
						    }
						    break;
					       }
	            	case 7:{
	            		    printf("      �޸�ǰ�༶��%s\n",p1->clas);
	            		    printf("      �޸ĺ�༶��");
	            		    scanf("%s",&result5_1);
						    while(1)
						    {
						    	printf("      �Ƿ�ȷ���޸ģ�0������1ȷ��)\n      ");
							    scanf("%d",&choice5_2);
						        if(choice5_2==1)
						        {
							        strcpy(p1->clas,result5_1);
							        break;
						        }else if(choice5_2==0)
						        {
						 	         break;
						        } 
						         Wrongscanf();
						    }
						    break;
					       }
	            	case 8:{
	            		    printf("      �޸�ǰѧ��״̬��%s\n",p1->state);
	            		    printf("      �޸ĺ�ѧ��״̬��");
	            		    scanf("%s",&result5_1);
						    while(1)
						    {
						    	printf("      �Ƿ�ȷ���޸ģ�0������1ȷ��)\n      ");
							    scanf("%d",&choice5_2);
						        if(choice5_2==1)
						        {
							        strcpy(p1->state,result5_1);
							        break;
						        }else if(choice5_2==0)
						        {
						 	         break;
						        } 
						         Wrongscanf();
						    }
						    break;
					       }
					default:{
						     Wrongscanf();
					        }
				}
				printf("      �Ƿ�����޸ģ�0ȡ����1ȷ�ϣ�\n      ");
				scanf("%d",&choice5_3);
				while(choice5_3!=1&&choice5_3!=0)
				{
					Wrongscanf();
					printf("      �Ƿ�����޸ģ�0ȡ����1ȷ�ϣ�\n      ");
				    scanf("%d",&choice5_3);
				}
				if(choice5_3==0)
				{
					break;
				 } 
		  } 
		}else
		{
			printf("      ���޴���\n");
			sleep(3);
		 } 
    printf("\n");
    SAVE(head);
	Fre(head);
	printf("      �������˵��밴5,�����޸����������밴�������ּ�:");
	scanf("%d",&choice5);
	printf("\n");
	if(choice5==5)
	{
		return;
	} 
	}
}

void State()                        //ѧ���仯��ѯ 
{ 
	system("cls");
	struct SSI *head,*p;
	char state6[20];
	int choice6;
	head=chain();
	p=head; 
	if(p->next==NULL)
	{
		printf("\n\n\n\n\n\n\n\n");
	 	printf("                   ����Ϊ��,����¼����Ϣ");
		sleep(3);
		return ;
	}
	while(1)
	{
		system("cls");
	    printf("ѧ��״̬��������ѧ���ڶ���תרҵ����ѧ����������ѧ����ҵ\n"); 
	    printf("������ѧ���仯:");
	    scanf("%s",state6);
	    printf("       ѧ  ��              ��  ��         �Ա�    ����           ��   ��                  ѧ   Ժ                  ר   ҵ              �� ��     ѧ��״̬\n\n");
	    while(p->next!=NULL)
	    {
		    if(strcmp(p->state,state6)==0)
		    {
			    printf("%-20s%-20s%-8s",p->no,p->name,p->sex);
			    printf("%-8s%-25s%-25s",p->age,p->area,p->academy); 
			    printf("%-25s%-15s%-25s\n",p->professional,p->clas,p->state);
			    printf("\n");
		    }
		    p=p->next;
	    }
	    printf("�������˵��밴6,������ѯ�밴������:");
	    scanf("%d",&choice6);
	    if(choice6==6)
	    {
		    Fre(head);
		    return ;
	    }
	}
 } 

void NativePlace()                  //�������
{
	system("cls"); 
	struct SSI *head,*p1,*p2,*p,*p_0,*p0;
	int choice7;
	char no7[20],name7[20],sex7[4],age7[4],area7[50],academy7[50],professional7[50],clas7[20],state7[20];
	head=chain();
	p1=head;
	if(p1->next==NULL)
	{
		printf("\n\n\n\n\n\n\n\n");
	 	printf("                   ����Ϊ��,����¼����Ϣ");
		sleep(3);
		return ;
	}
	while(1)
	{
		system("cls");
		printf("��ѡ�������ʽ��1.ѧ�ţ�2.רҵ��\n");
	    scanf("%d",&choice7);
	    p1=head;
	    p_0=p1->next;
	    if(choice7==1)
	    {
	    	printf("       ѧ  ��              ��  ��         �Ա�    ����           ��   ��                  ѧ   Ժ                  ר   ҵ              �� ��     ѧ��״̬\n\n");
	    	if(p_0->next==NULL)
	    	{
			    printf("%-20s%-20s%-8s",p1->no,p1->name,p1->sex);
			    printf("%-8s%-25s%-25s",p1->age,p1->area,p1->academy); 
			    printf("%-25s%-15s%-25s\n",p1->professional,p1->clas,p1->state);
			    printf("\n");
			}else
			{
			    while(p1->next!=NULL)
	            {
		            p2=p1->next;
		            p=p1;
		            while(p2->next!=NULL)
		            {
			            if(strcmp(p->no,p2->no)>0)
			            {
			            	p=p2;	
			            }
			            p2=p2->next;
		            }
		            strcpy(no7,p->no);
		            strcpy(name7,p->name);
		            strcpy(sex7,p->sex);
		            strcpy(age7,p->age);
		            strcpy(area7,p->area);
		            strcpy(academy7,p->academy);
		            strcpy(professional7,p->professional);
		            strcpy(clas7,p->clas);
		            strcpy(state7,p->state);
		            strcpy(p->no,p1->no);
		            strcpy(p->name,p1->name);
		            strcpy(p->sex,p1->sex);
		            strcpy(p->age,p1->age);
		            strcpy(p->area,p1->area);
		            strcpy(p->academy,p1->academy);
		            strcpy(p->professional,p1->professional);
		            strcpy(p->clas,p1->clas);
		            strcpy(p->state,p1->state);
		            strcpy(p1->no,no7);
		            strcpy(p1->name,name7);
		            strcpy(p1->sex,sex7);
		            strcpy(p1->age,age7);
		            strcpy(p1->area,area7);
		            strcpy(p1->academy,academy7);
		            strcpy(p1->professional,professional7);
		            strcpy(p1->clas,clas7);
		            strcpy(p1->state,state7);
		            p1=p1->next;
	            }
	            p0=head;
	            do
		        {
			        printf("%-20s%-20s%-8s",p0->no,p0->name,p0->sex);
			        printf("%-8s%-25s%-25s",p0->age,p0->area,p0->academy); 
			        printf("%-25s%-15s%-25s\n",p0->professional,p0->clas,p0->state);
			        printf("\n");
			        p0=p0->next;
		        }while(p0->next!=NULL);
			}
		}
		else if(choice7==2)
		{
			printf("       ѧ  ��              ��  ��         �Ա�    ����           ��   ��                  ѧ   Ժ                  ר   ҵ              �� ��     ѧ��״̬\n\n");
	    	if(p_0->next==NULL)
	    	{
			    printf("%-20s%-20s%-8s",p1->no,p1->name,p1->sex);
			    printf("%-8s%-25s%-25s",p1->age,p1->area,p1->academy); 
			    printf("%-25s%-15s%-25s\n",p1->professional,p1->clas,p1->state);
			    printf("\n");
			}else
			{
			    while(p1->next!=NULL)
	            {
		            p2=p1->next;
		            p=p1;
		            while(p2->next!=NULL)
		            {
			            if(strcmp(p->academy,p2->academy)>0) 
			            {
			            	if(strcmp(p->professional,p2->professional)>0)
			            	{
			            		p=p2;
							}
				            
			            }
			            p2=p2->next;
		            }
		            strcpy(no7,p->no);
		            strcpy(name7,p->name);
		            strcpy(sex7,p->sex);
		            strcpy(age7,p->age);
		            strcpy(area7,p->area);
		            strcpy(academy7,p->academy);
		            strcpy(professional7,p->professional);
		            strcpy(clas7,p->clas);
		            strcpy(state7,p->state);
		            strcpy(p->no,p1->no);
		            strcpy(p->name,p1->name);
		            strcpy(p->sex,p1->sex);
		            strcpy(p->age,p1->age);
		            strcpy(p->area,p1->area);
		            strcpy(p->academy,p1->academy);
		            strcpy(p->professional,p1->professional);
		            strcpy(p->clas,p1->clas);
		            strcpy(p->state,p1->state);
		            strcpy(p1->no,no7);
		            strcpy(p1->name,name7);
		            strcpy(p1->sex,sex7);
		            strcpy(p1->age,age7);
		            strcpy(p1->area,area7);
		            strcpy(p1->academy,academy7);
		            strcpy(p1->professional,professional7);
		            strcpy(p1->clas,clas7);
		            strcpy(p1->state,state7);
		            p1=p1->next;
	            }
	            p0=head;
	            do
		        {
			        printf("%-20s%-20s%-8s",p0->no,p0->name,p0->sex);
			        printf("%-8s%-25s%-25s",p0->age,p0->area,p0->academy); 
			        printf("%-25s%-15s%-25s\n",p0->professional,p0->clas,p0->state);
			        printf("\n");
			        p0=p0->next;
		        }while(p0->next!=NULL);
			}
		}
		printf("��7�˳��������鿴�밴�������ּ�\n");
		scanf("%d",&choice7);
		if(choice7==7)
		{
			Fre(head);
			break;
		}
	}
	return ;
}

void mainmenu()                     //���˵� 
{
	system("cls");
	printf("\n\n\n\n");
	printf("                             �˵�\n");
	printf("      ******************************************************\n");
	printf("      *                                                    *\n");
	printf("      *     1.ѧ���Ǽ�                2.ѧ���鿴           *\n");
	printf("      *     3.ѧ��ɾ��                4.ѧ������           *\n");
	printf("      *     5.ѧ����Ϣ�޸�            6.ѧ���仯��ѯ       *\n");
	printf("      *     7.��������              0.�˳�               *\n");
	printf("      *                                                    *\n");
	printf("      ******************************************************\n");
	printf("\n      ���ѣ���Ϣ¼������в�Ҫ�˳����򣬷������������Ϣ���ң�����Ը�\n\n");
	printf("      ���������ѡ��(0~6)\n");
	return ;
} 
 
void Studentmanagement()
{
	struct SSI *head,*p;
	int choice0;                              //�˵�ѡ��
	while(1){                                 //�޸�ѧ����Ϣ 
	mainmenu();
	printf("      ");
	scanf("%d",&choice0);
	switch(choice0)
	{
		case 0:{
			    Close();
			    break;
		       } 
		case 1:{
			   head=creat();
			   Fre(head); 
			   break;
		       }
		case 2:{
			   Printdata(); 
			   break;
		       }
		case 3:{
			   Delete();
			   break;
		       }
		case 4:{
			   Lookup();
			   break;
		       }
		case 5:{
			   Modify();
			   break;
		       }
		case 6:{
			   State();
			   break;
		       }
		case 7:{
			   NativePlace();
			   break;
		       } 
		default: {
			     Wrongscanf();
			     break;
		         }
	}
	}
 } 
 
int Close()
{
	system("cls"); 
	printf("\n\n\n\n\n\n\n\n");
	printf("                       ����ر��С�����\n                       ллʹ��\n");
	sleep(3);
	system("cls");
	printf("\n\n\n\n\n\n\n\n");
	printf("                      �����ѹر�\n\n\n\n\n\n");	
	exit(0);
}

void LandingSystem()    //��½ϵͳ(ע�����˺ţ�0�����룺0)
{
	system("color 06");
	char Username[20];
	char Password[20];
	printf("\n\n\n\n\n"); 
	printf("              �û�����");
	scanf("%s",&Username);
	printf("\n\n");
	printf("                ���룺");
	scanf("%s",&Password); 
	char highist[20]={'0'};
	system("cls");
	printf("\n\n\n\n\n\n\n\n");
	printf("                         ��½�С�����");
	sleep(3);
	if(strcmp(Username,highist)==0&&strcmp(Password,highist)==0)
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n");
		printf("                       ��½�ɹ�");
		sleep(3);
		return ;
	}
	system("cls");
	printf("\n\n\n\n\n\n\n\n");
	printf("                       ��½ʧ��,�����´�\n");
	sleep(3);
	exit(0);
}
 
int main()
{
	LandingSystem();
	Studentmanagement();	
 } 
 
