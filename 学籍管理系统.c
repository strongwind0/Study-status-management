#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN sizeof(struct SSI)
struct SSI                          //student status information 缩写 
{
	char no[20];              //学号
	char name[20];            //名字 
	char sex[4];              //性别 
	char age[4];              //年龄 
	char area[50];            //籍贯 
	char academy[50];         //院系
	char professional[50];    //专业 
	char clas[20];            //班级 
	char state[20];           //学籍状态
	struct SSI *next; 
};

int SAVEnew(struct SSI *p)          //将新信息存入文件中 
{
	FILE *fp,*f_p;
	if((fp=fopen("信息管理.txt","a"))==NULL)
	{
		printf("文件打开失败!\n");
		return-1;
	}
	char password[20]={'1','2','3','4','5','6'};
	fprintf(fp,"%s %s %s %s %s %s %s %s %s\n",p->no,p->name,p->sex,p->age,p->area,p->academy,p->professional,p->clas,p->state);
	//此处存入的换行符对后续代码编写有一定影响
	//具体表现为在将信息生成链表时会多申请一个乱码节点 
	//但为了在文件中查看显得美观，故仍保留此格式存入 
	fclose(fp);
	printf("信息保存成功\n");
	return 1; 
}

struct SSI *creat(void)             //链表创建（新信息录入） 
{
	int choice;
	struct SSI *head,*p1,*p2; 
	int i=1;
	while(1)
	{	
	    system("cls");
	    printf("备注：1.性别一栏为男或女\n");
	    printf("      2.学籍状态分为：入学，在读，转专业，退学，降级，休学，毕业\n");
	    printf("      3.学号，姓名，班级学籍状态长度限制均为20字符；性别，年龄长度限制为4个字符；籍贯，学院专业藏毒限制为50字符\n");
	    p1=(struct SSI*)malloc(LEN);
		printf("请输入学生学号：");
		scanf("%s",&p1->no);
		printf("请输入学生姓名：");
		scanf("%s",&p1->name);
		printf("请输入学生性别：");
		scanf("%s",&p1->sex);
		printf("请输入学生年龄：");
		scanf("%s",&p1->age);
		printf("请输入学生籍贯：");
		scanf("%s",&p1->area);
		printf("请输入学生院系：");
		scanf("%s",&p1->academy);
		printf("请输入学生专业：");
		scanf("%s",&p1->professional);
		printf("请输入学生班级：");
		scanf("%s",&p1->clas);
		printf("请输入学籍状态：");
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
		printf("结束录入请按0，继续录入请按其他数字：");  
		scanf("%d",&choice);
		if(choice==0)
		{
			p1->next=NULL;
			return head;
		} 
	}
 } 
 
void Fre(struct SSI *head)          //释放原链表所占内存 
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
 
struct SSI *chain()                 //将全部信息读取生成链表 
{
	FILE *fp;
	fp=fopen("信息管理.txt","r");
	struct SSI *head,*p1,*p2;
	 int i=1;
	 while(!feof(fp))                     //未遇到文件结束，继续执行循环 
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
  
void Printdata()                    //信息查看 
{
	system("cls");
	struct SSI *head,*p;
	head=chain();
	p=head;
	if(head->next!=NULL)
	{
		printf("       学  号              姓  名         性别    年龄           籍   贯                  学   院                  专   业              班 级     学籍状态\n\n");
		do
		{
			printf("%-20s%-20s%-8s",p->no,p->name,p->sex);
			printf("%-8s%-25s%-25s",p->age,p->area,p->academy); 
			printf("%-25s%-15s%-25s\n",p->professional,p->clas,p->state);
			printf("\n");
			p=p->next;
		}while(p->next!=NULL);                                                 //数据读取时多申请了一个节点 
	 }else
	 {
	 	printf("\n\n\n\n\n\n\n\n");
	 	printf("                   数据为空,请先录入信息");
	 	sleep(3);
	 	return;
	 }
	Fre(head);
	int choice2;
	printf("返回主菜单请按任意数字键\n");
	scanf("%d",&choice2);
	return ; 
}

void Wrongscanf()                   //错误输入提醒函数 
{
   printf("      输入错误\n");
   sleep(3);                  
   return ; 
}

int SAVE(struct SSI *head)          //信息操作后重新存入 
{
	system("cls");
	struct SSI *p;
	FILE *fp;
	if((fp=fopen("信息管理.txt","w"))==NULL)
	{
		printf("文件打开失败!\n");
		return -1;
	}
	p=head;
	printf("       学  号              姓  名         性别    年龄           籍   贯                  学   院                  专   业              班 级     学籍状态\n\n");
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
	printf("      新信息已保存\n");
	sleep(3); 
	return;
}

void Delete()                       //信息删除 
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
	 	printf("                   数据为空,请先录入信息");
		sleep(3);
		return ;
	}
	while(1)
	{
		printf("请输入删除对象学号：");
		scanf("%s",&no3);
		printf("\n");
		while(p1->next!=NULL&&strcmp(p1->no,no3)!=0)
		{
		   
		    p2=p1;
		    p1=p1->next;
		}
		if(strcmp(p1->no,no3)==0)
		{
			printf("       学  号              姓  名         性别    年龄           籍   贯                  学   院                  专   业              班 级     学籍状态\n\n");
			printf("%-20s%-20s%-8s",p1->no,p1->name,p1->sex);
			printf("%-8s%-25s%-25s",p1->age,p1->area,p1->academy); 
			printf("%-25s%-15s%-25s\n",p1->professional,p1->clas,p1->state);
			printf("\n");
			while(1)
			{
			    printf("确认删除请按1，取消请按0:");
			    scanf("%d",&choice3_1);
			    printf("\n");
			    if(choice3_1==0)
			    {
			        printf("取消删除\n");
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
		printf("未找到删除对象\n");
	}
	printf("结束删除返回主菜单请按3,继续删除请按其他键:");
	scanf("%d",&choice3);
	if(choice3==3)
	{
		SAVE(head);
		Fre(head);
		return;
	} 
	}
}

void Lookup()                       //信息查找 
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
	 	printf("                   数据为空,请先录入信息");
		sleep(3);
		return ;
	}
	while(1)
	{
		printf("请输入查找对象学号：");
		scanf("%s",&no3);
		printf("\n");
		while(p1->next!=NULL&&strcmp(p1->no,no3)!=0)
		{
		   
		    p2=p1;
		    p1=p1->next;
		}
		if(strcmp(p1->no,no3)==0)
		{
			printf("       学  号              姓  名         性别    年龄           籍   贯                  学   院                  专   业              班 级     学籍状态\n\n");
			printf("%-20s%-20s%-8s",p1->no,p1->name,p1->sex);
			printf("%-8s%-25s%-25s",p1->age,p1->area,p1->academy); 
			printf("%-25s%-15s%-25s\n",p1->professional,p1->clas,p1->state);
			printf("\n");
			
		}else
		{
			printf("查无此人\n");
		 } 
	printf("返回主菜单请按4,继续查找请按其他键:");
	scanf("%d",&choice4);
	printf("\n");
	if(choice4==4)
	{
		Fre(head);
		return;
	} 
	}
}

void Modify()                       //信息修改 
{
	system("cls");
	struct SSI *head,*p1,*p2;
	char result5_1[20],result5_2[4],result5_3[50];//暂时存放修改后信息 
	head=chain();
	p1=head;
	char no5[20];
	int choice5,choice5_1,choice5_2,choice5_3;
	if(p1->next==NULL)
	{
		printf("\n\n\n\n\n\n\n\n");
	 	printf("                   数据为空,请先录入信息");
		sleep(3);
		return ;
	}
	while(1)
	{
		system("cls");
		printf("请输入修改对象学号：");
		scanf("%s",&no5);
		printf("\n");
		printf("查找中。。。");
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
		        printf("       学  号              姓  名         性别    年龄           籍   贯                  学   院                  专   业              班 级     学籍状态\n\n");
			    printf("%-20s%-20s%-8s",p1->no,p1->name,p1->sex);
			    printf("%-8s%-25s%-25s",p1->age,p1->area,p1->academy); 
			    printf("%-25s%-15s%-25s\n",p1->professional,p1->clas,p1->state);
		        printf("\n\n");
		        printf("                           修改菜单\n");
	            printf("      ******************************************************\n");
	            printf("      *                                                    *\n");
	            printf("      *     1.姓名修改                2.性别修改           *\n");
	            printf("      *     3.年龄修改                4.籍贯修改           *\n");
	            printf("      *     5.院系修改                6.专业修改           *\n");
	            printf("      *     7.班级修改                8.学籍状态修改       *\n");
	            printf("      *     0.结束修改                                     *\n");
	            printf("      *                                                    *\n");
	            printf("      ******************************************************\n");
	        	printf("      请输入你的选择(0~8)\n");
	        	printf("      ");
	            scanf("%d",&choice5_1);
	            if(choice5_1==0)
	            {
	            	break;
				}
	            switch(choice5_1)
	            {
	            	case 1:{
	            		    printf("      修改前姓名：%s\n",p1->name);
	            		    printf("      修改后姓名：");
	            		    scanf("%s",&result5_1);
						    while(1)
						    {
						    	printf("      是否确认修改（0放弃，1确认)\n      ");
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
	            		    printf("      修改前性别：%s\n",p1->sex);
	            		    printf("      修改后性别：");
	            		    scanf("%s",&result5_2);
						    while(1)
						    {
						    	printf("      是否确认修改（0放弃，1确认)\n      ");
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
	            		    printf("      修改前年龄：%s\n",p1->age);
	            		    printf("      修改后年龄：");
	            		    scanf("%s",&result5_2);
						    while(1)
						    {
						    	printf("      是否确认修改（0放弃，1确认)\n      ");
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
	            		    printf("      修改前籍贯：%s\n",p1->area);
	            		    printf("      修改后籍贯：");
	            		    scanf("%s",&result5_3);
						    while(1)
						    {
						    	printf("      是否确认修改（0放弃，1确认)\n      ");
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
	            		    printf("      修改前院系：%s\n",p1->academy);
	            		    printf("      修改后院系：");
	            		    scanf("%s",&result5_3);
						    while(1)
						    {
						    	printf("      是否确认修改（0放弃，1确认)\n      ");
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
	            		    printf("      修改前专业：%s\n",p1->professional);
	            		    printf("      修改后专业：");
	            		    scanf("%s",&result5_3);
						    while(1)
						    {
						    	printf("      是否确认修改（0放弃，1确认)\n      ");
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
	            		    printf("      修改前班级：%s\n",p1->clas);
	            		    printf("      修改后班级：");
	            		    scanf("%s",&result5_1);
						    while(1)
						    {
						    	printf("      是否确认修改（0放弃，1确认)\n      ");
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
	            		    printf("      修改前学籍状态：%s\n",p1->state);
	            		    printf("      修改后学籍状态：");
	            		    scanf("%s",&result5_1);
						    while(1)
						    {
						    	printf("      是否确认修改（0放弃，1确认)\n      ");
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
				printf("      是否继续修改（0取消，1确认）\n      ");
				scanf("%d",&choice5_3);
				while(choice5_3!=1&&choice5_3!=0)
				{
					Wrongscanf();
					printf("      是否继续修改（0取消，1确认）\n      ");
				    scanf("%d",&choice5_3);
				}
				if(choice5_3==0)
				{
					break;
				 } 
		  } 
		}else
		{
			printf("      查无此人\n");
			sleep(3);
		 } 
    printf("\n");
    SAVE(head);
	Fre(head);
	printf("      返回主菜单请按5,继续修改其他数据请按任意数字键:");
	scanf("%d",&choice5);
	printf("\n");
	if(choice5==5)
	{
		return;
	} 
	}
}

void State()                        //学籍变化查询 
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
	 	printf("                   数据为空,请先录入信息");
		sleep(3);
		return ;
	}
	while(1)
	{
		system("cls");
	    printf("学籍状态包括：入学，在读，转专业，退学，降级，休学，毕业\n"); 
	    printf("请输入学籍变化:");
	    scanf("%s",state6);
	    printf("       学  号              姓  名         性别    年龄           籍   贯                  学   院                  专   业              班 级     学籍状态\n\n");
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
	    printf("返回主菜单请按6,继续查询请按其他键:");
	    scanf("%d",&choice6);
	    if(choice6==6)
	    {
		    Fre(head);
		    return ;
	    }
	}
 } 

void NativePlace()                  //籍贯输出
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
	 	printf("                   数据为空,请先录入信息");
		sleep(3);
		return ;
	}
	while(1)
	{
		system("cls");
		printf("请选择输出方式（1.学号，2.专业）\n");
	    scanf("%d",&choice7);
	    p1=head;
	    p_0=p1->next;
	    if(choice7==1)
	    {
	    	printf("       学  号              姓  名         性别    年龄           籍   贯                  学   院                  专   业              班 级     学籍状态\n\n");
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
			printf("       学  号              姓  名         性别    年龄           籍   贯                  学   院                  专   业              班 级     学籍状态\n\n");
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
		printf("按7退出，继续查看请按其他数字键\n");
		scanf("%d",&choice7);
		if(choice7==7)
		{
			Fre(head);
			break;
		}
	}
	return ;
}

void mainmenu()                     //主菜单 
{
	system("cls");
	printf("\n\n\n\n");
	printf("                             菜单\n");
	printf("      ******************************************************\n");
	printf("      *                                                    *\n");
	printf("      *     1.学籍登记                2.学籍查看           *\n");
	printf("      *     3.学籍删除                4.学籍查找           *\n");
	printf("      *     5.学籍信息修改            6.学籍变化查询       *\n");
	printf("      *     7.籍贯表输出              0.退出               *\n");
	printf("      *                                                    *\n");
	printf("      ******************************************************\n");
	printf("\n      提醒：信息录入过程中不要退出程序，否则容易造成信息混乱，后果自负\n\n");
	printf("      请输入你的选择(0~6)\n");
	return ;
} 
 
void Studentmanagement()
{
	struct SSI *head,*p;
	int choice0;                              //菜单选择
	while(1){                                 //修改学生信息 
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
	printf("                       程序关闭中。。。\n                       谢谢使用\n");
	sleep(3);
	system("cls");
	printf("\n\n\n\n\n\n\n\n");
	printf("                      程序已关闭\n\n\n\n\n\n");	
	exit(0);
}

void LandingSystem()    //登陆系统(注明：账号：0，密码：0)
{
	system("color 06");
	char Username[20];
	char Password[20];
	printf("\n\n\n\n\n"); 
	printf("              用户名：");
	scanf("%s",&Username);
	printf("\n\n");
	printf("                密码：");
	scanf("%s",&Password); 
	char highist[20]={'0'};
	system("cls");
	printf("\n\n\n\n\n\n\n\n");
	printf("                         登陆中。。。");
	sleep(3);
	if(strcmp(Username,highist)==0&&strcmp(Password,highist)==0)
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n");
		printf("                       登陆成功");
		sleep(3);
		return ;
	}
	system("cls");
	printf("\n\n\n\n\n\n\n\n");
	printf("                       登陆失败,请重新打开\n");
	sleep(3);
	exit(0);
}
 
int main()
{
	LandingSystem();
	Studentmanagement();	
 } 
 
