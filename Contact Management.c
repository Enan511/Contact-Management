#include<stdio.h>

#include<conio.h>

#include<string.h>

#include<process.h>

#include<stdlib.h>

#include<dos.h>

struct contact

{

    //long ph;

    char name[20],add[20],email[30], ph[15];

} list;

char query[20],name[20];

char n_name[20], n_ph[15], n_add[20], n_email[30], ch3;

FILE *fp, *ft, *fp1, *fp2;

int i,n,ch,ch2,l,found,flag=0;

int main()

{

main:

    system("cls");    /* ************Main menu ***********************  */

    printf("\n\t **** Welcome to Contact Management System ****");

    printf("\n\n\n\t\t\tMAIN MENU\n\t\t=====================\n\t\t[1] Add a new Contact\n\t\t[2] List all Contacts\n\t\t[3] Search for contact\n\t\t[4] Edit a Contact\n\t\t[5] Delete a Contact\n\t\t[0] Exit\n\t\t=================\n\t\t");

    printf("Enter the choice:");

    scanf("%d",&ch);

    switch(ch)

    {

    case 0:

        printf("\n\n\t\tAre you sure you want to exit?");

        break;

        /* Adding new contacts*/

    case 1:

        system("cls");

        fp=fopen("contact.txt","a");

        for (;;)

        {
            fflush(stdin);

            printf("To exit enter blank space in the name input\nName (Use identical):");

            scanf("%[^\n]",&list.name);

            if(stricmp(list.name,"")==0 || stricmp(list.name," ")==0)

                break;

            fflush(stdin);

            printf("Phone:");

            scanf("%[^\n]",&list.ph);

            fflush(stdin);

            printf("address:");

            scanf("%[^\n]",&list.add);

            fflush(stdin);

            printf("email address:");

            gets(list.email);

            printf("\n");

            fwrite(&list,sizeof(list),1,fp);

        }

        fclose(fp);

        break;

        /* list of contacts  */

    case 2:

        system("cls");

        printf("\n\t\t================================\n\t\t\tLIST OF CONTACTS\n\t\t================================\n\nName\t\tPhone No\t    Address\t\tE-mail ad.\n=================================================================\n\n");

        for(i=97; i<=122; i=i+1)

        {

            fp=fopen("contact.txt","r");

            fflush(stdin);

            found=0;

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                if(list.name[0]==i || list.name[0]==i-32)

                {

                    printf("\nName\t: %s\nPhone\t: %s\nAddress\t: %s\nEmail\t: %s\n",list.name,

                           list.ph,list.add,list.email);

                    found++;

                }

            }

            if(found!=0)

            {
                printf("=========================================================== [%c]-(%d)\n\n",i-32,found);

                getch();
            }

            fclose(fp);

        }

        break;

        /* searching for contacts  */

    case 3:

        system("cls");

        do

        {

            found=0;

            printf("\n\n\t..::CONTACT SEARCH\n\t===========================\n\t..::Name of contact to search: ");

            fflush(stdin);

            scanf("%[^\n]",&query);

            l=strlen(query);

            fp=fopen("contact.txt","r");

            system("cls");

            printf("\n\n..::Search result for '%s' \n===================================================\n",query);

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                for(i=0; i<=l; i++)

                    name[i]=list.name[i];

                name[l]='\0';

                if(stricmp(name,query)==0)

                {

                    printf("\n..::Name\t: %s\n..::Phone\t: %s\n..::Address\t: %s\n..::Email\t: %s\n",list.name,list.ph,list.add,list.email);

                    found++;

                    if (found%4==0)

                    {

                        printf("..::Press any key to continue...");

                        getch();

                    }

                }

            }

            if(found==0)

                printf("\n..::No match found!");

            else

                printf("\n..::%d match(s) found!",found);

            fclose(fp);

            printf("\n ..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t");

            scanf("%d",&ch);

        }
        while(ch==1);

        break;


        /* updating contacts*/

    case 4:

        system("cls");

        fp=fopen("contact.txt","r");
        fflush(stdin);
        printf("..::Edit contact\n===============================\n\n\t..::Enter the name of contact to edit:");
        scanf("%[^\n]",name);

        while(fread(&list,sizeof(list),1,fp)==1)
        {
            if(stricmp(name,list.name)==0)
            {
                flag = 1;
                printf("\n..::Name\t: %s\n..::Phone\t: %s\n..::Address\t: %s\n..::Email\t: %s\n\n",list.name,list.ph,list.add,list.email);

                printf("What is it, you want to change?\n\n");
                printf("Please enter:\n 1 for changing Name\n 2 for changing Phone Number\n 3 for changing Address\n 4 for changing Email\n 5 for changing everything\n\n");
                printf("Please enter your choice: ");
                scanf("%d", &ch2);

                switch (ch2)
                    {
                    case 1:

                        fp2=fopen("contact3.txt","w");
                        fflush(stdin);
                        printf("\n\n..::Editing Name '%s'\n\n",name);
                        printf("..::Name(Use identical): ");
                        scanf("%[^\n]",&n_name);
                        strcpy( list.name, n_name);
                        fwrite(&list,sizeof(list),1,fp2);
                        fclose(fp2);
                        break;

                    case 2:

                        fp2=fopen("contact3.txt","w");
                        fflush(stdin);
                        printf("\n\n..::Editing Phone '%s'\n\n",list.ph);
                        printf("..::Phone: ");
                        scanf("%[^\n]",&n_ph);
                        strcpy( list.ph, n_ph);
                        fwrite(&list,sizeof(list),1,fp2);
                        fclose(fp2);
                        break;

                    case 3:

                        fp2=fopen("contact3.txt","w");
                        fflush(stdin);
                        printf("\n\n..::Editing Address'%s'\n\n",list.add);
                        printf("..::Address: ");
                        scanf("%[^\n]",&n_add);
                        strcpy( list.add, n_add);
                        fwrite(&list,sizeof(list),1,fp2);
                        fclose(fp2);
                        break;

                    case 4:

                        fp2=fopen("contact3.txt","w");
                        fflush(stdin);
                        printf("\n\n..::Editing Email '%s'\n\n",list.email);
                        printf("..::Email: ");
                        scanf("%[^\n]",&n_email);
                        strcpy( list.email, n_email);
                        fwrite(&list,sizeof(list),1,fp2);
                        fclose(fp2);
                        break;

                    case 5:

                        fp2=fopen("contact3.txt","w");

                        fflush(stdin);
                        printf("\n\n..::Editing Name '%s'\n\n",name);
                        printf("..::Name(Use identical): ");
                        scanf("%[^\n]",&n_name);

                        fflush(stdin);
                        printf("\n\n..::Editing Phone '%s'\n\n",list.ph);
                        printf("..::Phone: ");
                        scanf("%[^\n]",&n_ph);

                        fflush(stdin);
                        printf("\n\n..::Editing Address'%s'\n\n",list.add);
                        printf("..::Address: ");
                        scanf("%[^\n]",&n_add);

                        fflush(stdin);
                        printf("\n\n..::Editing Email '%s'\n\n",list.email);
                        printf("..::Email: ");
                        scanf("%[^\n]",&n_email);

                        strcpy( list.name, n_name);
                        strcpy( list.ph, n_ph);
                        strcpy( list.add, n_add);
                        strcpy( list.email, n_email);

                        fwrite(&list,sizeof(list),1,fp2);
                        fclose(fp2);
                        break;

                    default:
                        break;
                    }
            }
        }

        fclose(fp);
        fp=fopen("contact.txt","r");
        ft=fopen("temp.dat","w");

        while(fread(&list,sizeof(list),1,fp)!=0)
        {
            if (stricmp(name,list.name)!=0)
            {
                fwrite(&list,sizeof(list),1,ft);
            }
        }

        fclose(fp);
        fclose(ft);

        rename("temp.dat","contact2.txt");

        if (flag==1)
        {
            remove("contact.txt");
            fp1=fopen("contact2.txt","r");
            fp2=fopen("contact3.txt","r");
            fp=fopen("contact.txt","w");

            while ((ch3 = fgetc(fp1)) != EOF)
            {
                fputc(ch3, fp);
            }

            while ((ch3 = fgetc(fp2)) != EOF)
            {
                fputc(ch3, fp);
            }

            fclose(fp1);
            fclose(fp2);
            fclose(fp);

        }

        else
        {
            printf("There is no contact number with this name. Please add a contact before updating it.\n\n");
        }

        remove("contact2.txt");
        remove("contact3.txt");

        break;

        /* deleting contacts*/

    case 5:

        system("cls");

        fflush(stdin);

        printf("\n\n\t..::DELETE A CONTACT\n\t==========================\n\t..::Enter the name of contact to delete:");

        scanf("%[^\n]",&name);

        fp=fopen("contact.txt","r");

        ft=fopen("temp.dat","w");

        while(fread(&list,sizeof(list),1,fp)!=0)

            if (stricmp(name,list.name)!=0)

                fwrite(&list,sizeof(list),1,ft);

        fclose(fp);

        fclose(ft);

        remove("contact.txt");

        rename("temp.dat","contact.txt");

        break;

    default:

        printf("Invalid choice");

        break;

    }

    printf("\n\n\n..::Enter the Choice:\n\n\t[1] Main Menu\t\t[0] Exit\n");

    scanf("%d",&ch);

    switch (ch)

    {

    case 1:

        goto main;

    case 0:

        break;

    default:

        printf("Invalid choice");

        break;

    }
    //choice menu

    return 0;

}
