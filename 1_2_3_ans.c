#include<stdio.h>
#include<string.h>

struct student
{
    char name1[50];
    char name2[50];
    char roll[15];
    char contact[13];
    int sem;
    double gpa[10];
};
void showinfo()
{
    FILE * fp;
    struct student s[100];
    int i=0,ts,j;
    fp=fopen("studentdata.txt","r");
    if(!fp)
    {
        printf("File openning error\n Please try again\n\n");
        return;
    }
    while(fscanf(fp,"%s",s[i].name1)==1)
    {
        fscanf(fp,"%s%s%s",s[i].name2,s[i].roll,s[i].contact);
        fscanf(fp,"%d",&s[i].sem);
        for(j=0; j<s[i].sem; j++)
            fscanf(fp,"%lf",&s[i].gpa[j]);
        i++;
    }
    ts=i;
    for(i=0; i<ts; i++)
    {
        printf("First Name : %s\n",s[i].name1);
        printf("Last Name : %s\n",s[i].name2);
        printf("Matric ID : %s\n",s[i].roll);
        printf("Contact Number : %s\n",s[i].contact);
        printf("Number of completed semester : %d\n",s[i].sem);
        for(j=0; j<s[i].sem; j++)
            printf("%0.2lf ",s[i].gpa[j]);
        printf("\n\n");
    }
    printf("\n\n");
    fclose(fp);

}
void addinfo()
{
    int i;
    FILE *fp;
    struct student s;
    fp= fopen("studentdata.txt","a");
    if(!fp)
    {
        printf("File opening error\nPlease Try again\n");
        return;
    }

    printf("Enter Student Data:\n");
    scanf("%s",s.name1);
    scanf("%s",s.name2);
    scanf("%s",s.roll);
    scanf("%s",s.contact);
    scanf("%d",&s.sem);
    for(i=0; i<s.sem; i++)
        scanf("%lf",&s.gpa[i]);


    fprintf(fp,"%s\n",s.name1);
    fprintf(fp,"%s\n",s.name2);
    fprintf(fp,"%s\n",s.roll);
    fprintf(fp,"%s\n",s.contact);
    fprintf(fp,"%d\n",s.sem);
    for(i=0; i<s.sem; i++)
        fprintf(fp, "%.2lf ",s.gpa[i]);
    fprintf(fp,"\n");
    printf("Save Successfully\n");
    fclose(fp);
}
void deleteinfo()
{
    FILE * fp;
    struct student s[100];
    int i=0,ts,result,j;
    double sum_gpa=0.00,cgpa;
    char ID[10];
    fp=fopen("studentdata.txt","r");
    if(!fp)
    {
        printf("File openning error\n Please try again\n\n");
        return;
    }
    while(fscanf(fp,"%s",s[i].name1)==1)
    {
        fscanf(fp,"%s%s%s",s[i].name2,s[i].roll,s[i].contact);
        fscanf(fp,"%d",&s[i].sem);
        for(j=0; j<s[i].sem; j++)
            fscanf(fp,"%lf",&s[i].gpa[j]);
        i++;
    }
    ts=i;
    fclose(fp);

    printf("Enter the Delete Matric ID : ");
    scanf("%s",ID);

    fp = fopen("studentdata.txt","w");
    if(!fp)
    {
        printf("File openning error\n Please try again\n\n");
        return;
    }
    for(i=0; i<ts; i++)
    {
        result = strcmp(ID, s[i].roll);
        if(result!=0)
        {
            fprintf(fp,"%s\n",s[i].name1);
            fprintf(fp,"%s\n",s[i].name2);
            fprintf(fp,"%s\n",s[i].roll);
            fprintf(fp,"%s\n",s[i].contact);
            fprintf(fp,"%d\n",s[i].sem);
            for(j=0; j<s[i].sem; j++)
                fprintf(fp,"%.2lf ",s[i].gpa[j]);
            fprintf(fp,"\n");
            printf("\n\nDelete successful\n\n");
        }
        else
        {

            for(j=0; j<s[i].sem; j++)
            {
                sum_gpa+=s[i].gpa[j];
            }
            cgpa=sum_gpa/s[i].sem;
            printf("%s CGPA = %.2lf",s[i].roll,cgpa);
        }
    }
    fclose(fp);
}

void addgpa()
{
    FILE * fp;
    struct student s[100];
    int i=0,ts,result,j,k;
    char ID[10];
    double num;
    fp=fopen("studentdata.txt","r");
    if(!fp)
    {
        printf("File openning error\n Please try again\n\n");
        return;
    }
    while(fscanf(fp,"%s",s[i].name1)==1)
    {
        fscanf(fp,"%s%s%s",s[i].name2,s[i].roll,s[i].contact);
        fscanf(fp,"%d",&s[i].sem);
        for(j=0; j<s[i].sem; j++)
            fscanf(fp,"%lf",&s[i].gpa[j]);
        i++;
    }
    ts=i;
    fclose(fp);
    printf("Enter Matric ID : ");
    scanf("%s",ID);
    printf("Enter new sem GPA : ");
    scanf("%lf",&num);
    fp = fopen("studentdata.txt" ,"w");
    if(!fp)
    {
        printf("File openning error\n Please try again\n\n");
        return;
    }
    for(i=0; i<ts; i++)
    {
        result = strcmp(ID, s[i].roll);
        if(result==0)
        {
            k=s[i].sem;
            s[i].gpa[k]=num;
            s[i].sem++;
        }
    }
    for(i=0; i<ts; i++)
    {
        fprintf(fp,"%s\n",s[i].name1);
        fprintf(fp,"%s\n",s[i].name2);
        fprintf(fp,"%s\n",s[i].roll);
        fprintf(fp,"%s\n",s[i].contact);
        fprintf(fp,"%d\n",s[i].sem);
        for(j=0; j<s[i].sem; j++)
            fprintf(fp,"%.2lf ",s[i].gpa[j]);
        fprintf(fp,"\n");
    }
    printf("Add gpa successfully\n");
    fclose(fp);
}

void highcgpa()
{
    FILE * fp;
    struct student s[100];
    int i=0,ts,result,j,item,pos;
    char ID[10];
    double num,ave,max=0;
    fp=fopen("studentdata.txt" ,"r");
    if(!fp)
    {
        printf("File openning error\n Please try again\n\n");
        return;
    }
    while(fscanf(fp,"%s",s[i].name1)==1)
    {
        fscanf(fp,"%s%s%s",s[i].name2,s[i].roll,s[i].contact);
        fscanf(fp,"%d",&s[i].sem);
        for(j=0; j<s[i].sem; j++)
            fscanf(fp,"%lf",&s[i].gpa[j]);
        i++;
    }
    ts=i;
    for(i=0; i<ts; i++)
    {
        for(j=0,ave=0; j<s[i].sem; j++)
        {
            ave+=s[i].gpa[j];
        }
        if(ave/s[i].sem>max)
        {
            max=ave/s[i].sem;
            pos=i;
        }
    }
    printf("Highest CGPA : %.2lf\n",max);
    printf("His Name is  : %s %s\n",s[pos].name1,s[pos].name2);
}

void showpgcontact()
{
    FILE * fp;
    struct student s[100];
    int i=0,ts,result,j;
    char ID[10],str1[20]="+88";
    double ave;
    fp=fopen("studentdata.txt" ,"r");
    if(!fp)
    {
        printf("File openning error\n Please try again\n\n");
        return;
    }
    while(fscanf(fp,"%s",s[i].name1)==1)
    {
        fscanf(fp,"%s%s%s",s[i].name2,s[i].roll,s[i].contact);
        fscanf(fp,"%d",&s[i].sem);
        for(j=0; j<s[i].sem; j++)
            fscanf(fp,"%lf",&s[i].gpa[j]);
        i++;
    }
    ts=i;
    fclose(fp);
    printf("PG Number user student List :\n");
    for(i=0,j=1; i<ts; i++)
    {
        if((s[i].contact[0]=='0' && s[i].contact[1]=='1' && s[i].contact[2]=='3') || (s[i].contact[0]=='0' && s[i].contact[1]=='1' && s[i].contact[2]=='7'))
        {
            printf("%d.%s %s\n",j,s[i].name1,s[i].name2);
            j++;
            strcat(str1,s[i].contact);
            strcpy(s[i].contact,str1);
            printf("%s",str1);
        }
    }
    fp = fopen("studentdata.txt" ,"w");
    if(!fp)
    {
        printf("File openning error\n Please try again\n\n");
        return;
    }
    for(i=0; i<ts; i++)
    {
            fprintf(fp,"%s\n",s[i].name1);
            fprintf(fp,"%s\n",s[i].name2);
            fprintf(fp,"%s\n",s[i].roll);
            fprintf(fp,"%s\n",s[i].contact);
            fprintf(fp,"%d\n",s[i].sem);
            for(j=0; j<s[i].sem; j++)
                fprintf(fp,"%0.2lf ",s[i].gpa[j]);
            fprintf(fp,"\n");
    }
  printf("Save successfully");
  fclose(fp);
}

int menu()
{
    int choice;
    printf("\nSelect an option:\n");
    printf("\nMenu:\n");
    printf("1. Show info\n");
    printf("2. Add info\n");
    printf("3. delete info\n");
    printf("4. Add next semester GPA\n");
    printf("5. Highest CGPA\n");
    printf("6. Show Pg Contact\n");
    printf("7. Exit\n\n");

    scanf("%d",&choice);
    return choice;
}
int main()
{
    int choice;
    do
    {
        choice = menu();
        switch(choice)
        {
        case 1:
            showinfo();
            break;
        case 2:
            addinfo();
            break;
        case 3:
            deleteinfo();
            break;
        case 4:
            addgpa();
            break;
        case 5:
            highcgpa();
            break;
        case 6:
            showpgcontact();
            break;

        }
    }
    while(choice!= 7);
}
