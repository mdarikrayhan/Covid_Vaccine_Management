#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>
//Menu
void menu();
//Test question and vaccine update
void takevaccine();
void firstdose(char cvname[20], char cnid[20]);
void secondose(char cnid[20]);
void deletevaccine(char cvname[20]);
//Citizen registration
void registration();
//Vaccine Update
void vaccineinfo();
void vaccineadd();
void vaccineshow();
void vaccineupdate();
void vaccinedelete();
//Viewing Citizen
void citizenlist();
void allcitizenlist();
void showfirstdose();
void showsecondose();
void sortbyage();
void updatecitizen();
void deletecitizen();
//Search
void search();
void searchbynid();
void searchbyphoneno();
//features
int agefromstring(char date[10]);
void gotoxy(int, int);
struct citizen
{
    char name[20];
    char gender[8];
    char dob[20];
    char upzila[15];
    char nid[20];
    char phoneno[15];
    char firstdose[20];//first dose date
    char secondose[20];//second dose date
    char vname[20];// Vaccine name
};
struct vaccine
{
    char name[20];
    int quantity;
};
int day = 0, month = 0, year = 0;
int main()
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    year = tm.tm_year + 1900, month = tm.tm_mon + 1, day = tm.tm_mday;
    menu();
    return 0;
}
void menu()
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int vtotal = 0;
    FILE *fp;
    struct vaccine vac;
    fp = fopen("vaccine.bin", "rb+");
    while (fread(&vac, sizeof(vac), 1, fp) == 1)
    {
        vtotal = vtotal + vac.quantity;
    }
    fclose(fp);
    system("cls");
    int choice;
    gotoxy(10, 3);
    printf("======================================================\n");
    gotoxy(10, 4);
    printf("*                 Vaccine Regulation                 *\n");
    gotoxy(10, 5);
    printf("*                                                    *\n");
    gotoxy(10, 6);
    printf("*      Time : %02d:%02d:%02d          Date:%02d-%02d-%d      *\n", tm.tm_hour, tm.tm_min, tm.tm_sec, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    gotoxy(10, 7);
    printf("*                                                    *\n");
    gotoxy(10, 8);
    printf("*           Total Vaccine Available : %-6d         *\n", vtotal);
    gotoxy(10, 9);
    printf("======================================================\n");
    gotoxy(10, 10);
    printf("*                                                    *\n");
    gotoxy(10, 11);
    printf("*                 1.Take Vaccine                     *\n");
    gotoxy(10, 12);
    printf("*                 2.Registration                     *\n");
    gotoxy(10, 13);
    printf("*                 3.Vaccine Information              *\n");
    gotoxy(10, 14);
    printf("*                 4.Citizen List                     *\n");
    gotoxy(10, 15);
    printf("*                 5.Search                           *\n");
    gotoxy(10, 16);
    printf("*                 6.Exit                             *\n");
    gotoxy(10, 17);
    printf("*                                                    *\n");
    gotoxy(10, 18);
    printf("======================================================\n");
    gotoxy(10, 20);
    printf("Enter appropriate number to perform following task : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        takevaccine();
        break;

    case 2:
        registration();
        break;

    case 3:
        vaccineinfo();
        break;

    case 4:
        citizenlist();
        break;
    case 5:
        search();
        break;
    case 6:
        exit(1);
        break;

    default:
        gotoxy(10, 22);
        printf("          Invalid Choice, Press any key to continue.");
        getch();
        menu();
    }
}
void takevaccine()
{
    system("cls");
    gotoxy(10, 5);
    printf("Enter your NID no : ");
    char cnid[20];
    fflush(stdin);
    gets(cnid);
    char notc[20] = "Not Completed";
    FILE *fp;
    struct citizen ctz;
    fp = fopen("record.bin", "rb+");
    if (fp == NULL)
    {
        gotoxy(10, 8);
        printf("No data found,Please Add Citizen information.");
        gotoxy(10, 11);
        printf("Press any key to continue.");
        getch();
        menu();
    }
    while (fread(&ctz, sizeof(ctz), 1, fp) == 1)
    {
        if (strcmp(cnid, ctz.nid) == 0 && strcmp(notc, ctz.firstdose) == 0)
        {
            int count = 0, check;
            system("cls");
            gotoxy(10, 3);
            printf("1.Do you have underlying medical conditions?");
            gotoxy(10, 4);
            printf("1.Yes");
            gotoxy(10, 5);
            printf("2.No");
            gotoxy(10, 6);
            printf("Enter 1 or 2 : ");
            scanf("%d", &check);
            if (check == 2)
            {
                count++;
            }
            system("cls");
            gotoxy(10, 3);
            printf("2.Do you have any allergies?");
            gotoxy(10, 4);
            printf("1.Yes");
            gotoxy(10, 5);
            printf("2.No");
            gotoxy(10, 6);
            printf("Enter 1 or 2 : ");
            scanf("%d", &check);
            if (check == 2)
            {
                count++;
            }
            system("cls");
            gotoxy(10, 3);
            printf("3.Are you are pregnant or breastfeeding?");
            gotoxy(10, 4);
            printf("1.Yes");
            gotoxy(10, 5);
            printf("2.No");
            gotoxy(10, 6);
            printf("Enter 1 or 2 : ");
            scanf("%d", &check);
            if (check == 2)
            {
                count++;
            }
            system("cls");
            gotoxy(10, 3);
            printf("4.Have you been tested corona positive in Past 28 Days?");
            gotoxy(10, 4);
            printf("1.Yes");
            gotoxy(10, 5);
            printf("2.No");
            gotoxy(10, 6);
            printf("Enter 1 or 2 : ");
            scanf("%d", &check);
            if (check == 2)
            {
                count++;
            }
            system("cls");
            gotoxy(10, 3);
            printf("5.Do you have fever?");
            gotoxy(10, 4);
            printf("1.Yes");
            gotoxy(10, 5);
            printf("2.No");
            gotoxy(10, 6);
            printf("Enter 1 or 2 : ");
            scanf("%d", &check);
            if (check == 2)
            {
                count++;
            }
            if (count == 5)
            {
                system("cls");
                gotoxy(10, 3);
                printf("Congratulatios you can take the first vaccine.");
                getch();
                FILE *fp1;
                int i = 1, j;
                struct vaccine vac;
                system("cls");
                gotoxy(10, 3);
                printf("<--: All available Vaccines:-->");
                gotoxy(10, 5);
                printf("No.  Name                Quantity");
                gotoxy(10, 6);
                printf("---------------------------------");
                fp1 = fopen("vaccine.bin", "rb+");
                if (fp1 == NULL)
                {
                    gotoxy(10, 8);
                    printf("No data found,Please Add Vaccine information.");
                    gotoxy(10, 11);
                    printf("Press any key to continue.");
                    getch();
                    menu();
                }
                j = 8;
                while (fread(&vac, sizeof(vac), 1, fp1) == 1)
                {
                    gotoxy(10, j);
                    printf("%-5d%-20s%-10d", i, vac.name, vac.quantity);
                    i++;
                    j++;
                }
                fclose(fp1);
                gotoxy(10, j + 2);
                printf("Which Vaccine Do you want to take : ");
                int p;
                scanf("%d", &p);
                gotoxy(10, j + 4);
                printf("You can take the next vaccine on : %02d-%02d-%04d", day, month + 1, year);
                getch();
                FILE *fpg;
                int x = 1;
                char cvname[20];
                struct vaccine vacg;
                fpg = fopen("vaccine.bin", "rb+");
                while (fread(&vacg, sizeof(vacg), 1, fpg) == 1)
                {
                    if (x == p)
                    {
                        for (int i = 0; i < 20; i++)
                        {
                            cvname[i] = vacg.name[i];
                        }
                    }
                    x++;
                }
                fclose(fpg);
                firstdose(cvname, cnid);
            }
        }
        else if (strcmp(cnid, ctz.nid) == 0 && strcmp(notc, ctz.firstdose) != 0 && strcmp(notc, ctz.secondose) == 0)
        {
            int count = 0, check;

            system("cls");
            gotoxy(10, 3);
            printf("1.Do you have underlying medical conditions?");
            gotoxy(10, 4);
            printf("1.Yes");
            gotoxy(10, 5);
            printf("2.No");
            gotoxy(10, 6);
            printf("Enter 1 or 2 : ");
            scanf("%d", &check);
            if (check == 2)
            {
                count++;
            }
            system("cls");
            gotoxy(10, 3);
            printf("2.Do you have any allergies?");
            gotoxy(10, 4);
            printf("1.Yes");
            gotoxy(10, 5);
            printf("2.No");
            gotoxy(10, 6);
            printf("Enter 1 or 2 : ");
            scanf("%d", &check);
            if (check == 2)
            {
                count++;
            }
            system("cls");
            gotoxy(10, 3);
            printf("3.Are you are pregnant or breastfeeding?");
            gotoxy(10, 4);
            printf("1.Yes");
            gotoxy(10, 5);
            printf("2.No");
            gotoxy(10, 6);
            printf("Enter 1 or 2 : ");
            scanf("%d", &check);
            if (check == 2)
            {
                count++;
            }
            system("cls");
            gotoxy(10, 3);
            printf("4.Have you been tested corona positive in Past 28 Days?");
            gotoxy(10, 4);
            printf("1.Yes");
            gotoxy(10, 5);
            printf("2.No");
            gotoxy(10, 6);
            printf("Enter 1 or 2 : ");
            scanf("%d", &check);
            if (check == 2)
            {
                count++;
            }
            system("cls");
            gotoxy(10, 3);
            printf("5.Do you have fever?");
            gotoxy(10, 4);
            printf("1.Yes");
            gotoxy(10, 5);
            printf("2.No");
            gotoxy(10, 6);
            printf("Enter 1 or 2 : ");
            scanf("%d", &check);
            if (check == 2)
            {
                count++;
            }
            if (count == 5)
            {
                FILE *fp;
                struct citizen ctz;
                fp = fopen("record.bin", "rb+");
                system("cls");
                gotoxy(10, 3);
                printf("Congratulatios you can take the Second Dose of vaccine.");
                while (fread(&ctz, sizeof(ctz), 1, fp) == 1)
                {
                    if (strcmp(cnid, ctz.nid) == 0)
                    {
                        gotoxy(10, 5);
                        printf("The vaccine you  need to take as your second dose is : %-20s .",ctz.vname);
                    }
                }
                fclose(fp);
                getch();
                secondose(cnid);
            }
        }
        else if (strcmp(cnid, ctz.nid) == 0 && strcmp(notc, ctz.firstdose) != 0 && strcmp(notc, ctz.secondose) != 0)
        {
            gotoxy(10, 7);
            printf("You have taken Both Dose of vaccine");
        }
        else
        {
            gotoxy(10, 8);
            printf("No data found,Please Complete registration first.");
        }
    }
    fclose(fp);
    gotoxy(10, 18);
    printf("Press any key to continue.");
    getch();
    menu();
}
void firstdose(char cvname[20], char cnid[20])
{
    char dnid[20], dvname[20];
    for (int i = 0; i < 20; i++)
    {
        dnid[i] = cnid[i];
    }
    for (int i = 0; i < 20; i++)
    {
        dvname[i] = cvname[i];
    }
    FILE *fp;
    struct citizen ctz;
    system("cls");
    fp = fopen("record.bin", "rb+");
    if (fp == NULL)
    {
        gotoxy(10, 8);
        printf("No data found,Please Add information.");
        gotoxy(10, 11);
        printf("Press any key to continue.");
        getch();
        menu();
    }
    rewind(fp);
    fflush(stdin);
    while (fread(&ctz, sizeof(ctz), 1, fp) == 1)
    {
        if (strcmp(dnid, ctz.nid) == 0)
        {
            for (int i = 0; i < 20; i++)
            {
                ctz.vname[i] = dvname[i];
            }
            fflush(stdin);
            int iyear = year, imonth = month, iday = day;
            char date[13];
            date[0] = iday / 10 + 48;
            date[1] = iday % 10 + 48;
            date[2] = '-';
            date[3] = imonth / 10 + 48;
            date[4] = imonth % 10 + 48;
            date[5] = '-';
            date[6] = iyear / 1000 + 48;
            date[7] = ((iyear / 100) % 10) + 48;
            date[8] = ((iyear / 10) % 100) + 48;
            date[9] = iyear % 10 + 48;
            date[10] = ' ';
            date[11] = ' ';
            date[12] = ' ';
            for (int i = 0; i < 13; i++)
            {
                ctz.firstdose[i] = date[i];
            }
            fflush(stdin);
            fseek(fp, -sizeof(ctz), SEEK_CUR);
            fwrite(&ctz, sizeof(ctz), 1, fp);
            break;
        }
    }
    fclose(fp);
    deletevaccine(dvname);
    gotoxy(10, 19);
    printf("Press any key to continue.");
    getch();
    menu();
}
void secondose(char cnid[])
{
    char dnid[20], dvname[20];
    for (int i = 0; i < 20; i++)
    {
        dnid[i] = cnid[i];
    }
    FILE *fp;
    struct citizen ctz;
    system("cls");
    fp = fopen("record.bin", "rb+");
    if (fp == NULL)
    {
        gotoxy(10, 8);
        printf("No data found,Please Add information.");
        gotoxy(10, 11);
        printf("Press any key to continue.");
        getch();
        menu();
    }
    rewind(fp);
    fflush(stdin);
    while (fread(&ctz, sizeof(ctz), 1, fp) == 1)
    {
        if (strcmp(dnid, ctz.nid) == 0)
        {
            for (int i = 0; i < 20; i++)
            {
                dvname[i] = ctz.vname[i];
            }
            fflush(stdin);
            int iyear = year, imonth = month, iday = day;
            char date[13];
            date[0] = iday / 10 + 48;
            date[1] = iday % 10 + 48;
            date[2] = '-';
            date[3] = imonth / 10 + 48;
            date[4] = imonth % 10 + 48;
            date[5] = '-';
            date[6] = iyear / 1000 + 48;
            date[7] = ((iyear / 100) % 10) + 48;
            date[8] = ((iyear / 10) % 100) + 48;
            date[9] = iyear % 10 + 48;
            date[10] = ' ';
            date[11] = ' ';
            date[12] = ' ';
            for (int i = 0; i < 13; i++)
            {
                ctz.secondose[i] = date[i];
            }
            fflush(stdin);
            fseek(fp, -sizeof(ctz), SEEK_CUR);
            fwrite(&ctz, sizeof(ctz), 1, fp);
            break;
        }
    }
    fclose(fp);
    deletevaccine(dvname);
    gotoxy(10, 19);
    printf("Press any key to continue.");
    getch();
    menu();
}
void deletevaccine(char cvname[20])
{
    char dvname[20];
    for (int i = 0; i < 20; i++)
    {
        dvname[i] = cvname[i];
    }
    FILE *fp;
    struct vaccine vac;
    system("cls");
    fp = fopen("vaccine.bin", "rb+");
    if (fp == NULL)
    {
        gotoxy(10, 8);
        printf("No data found,Please Add information.");
        gotoxy(10, 11);
        printf("Press any key to continue.");
        getch();
        menu();
    }
    rewind(fp);
    fflush(stdin);
    while (fread(&vac, sizeof(vac), 1, fp) == 1)
    {
        if (strcmp(dvname, vac.name) == 0)
        {
            vac.quantity = vac.quantity - 1;
            fflush(stdin);
            fseek(fp, -sizeof(vac), SEEK_CUR);
            fwrite(&vac, sizeof(vac), 1, fp);
            break;
        }
    }
    fclose(fp);
    gotoxy(10, 19);
    printf("Press any key to continue.");
    getch();
    menu();
}

void registration()
{
    FILE *fp;
    struct citizen ctz = {"", "", "", "", "", "", "Not Completed", "Not Completed"};
    char another = 'y';
    system("cls");
    fp = fopen("record.bin", "ab+");
    if (fp == NULL)
    {
        gotoxy(10, 5);
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while (another == 'y')
    {
        gotoxy(10, 3);
        printf("<--:ADD RECORD:-->");
        gotoxy(10, 5);
        printf("Enter details of Citizen.");
        gotoxy(10, 7);
        printf("Enter Name : ");
        gets(ctz.name);
        fflush(stdin);
        gotoxy(10, 8);
        printf("Enter Gender: ");
        gets(ctz.gender);
        gotoxy(10, 9);
        printf("Enter Date Of Birth : ");
        gets(ctz.dob);
        fflush(stdin);
        gotoxy(10, 10);
        printf("Enter Zipcode : ");
        gets(ctz.upzila);
        fflush(stdin);
        gotoxy(10, 11);
        printf("Enter NID no : ");
        gets(ctz.nid);
        fflush(stdin);
        gotoxy(10, 12);
        printf("Enter Phone No : ");
        gets(ctz.phoneno);
        fflush(stdin);
        fwrite(&ctz, sizeof(ctz), 1, fp);
        gotoxy(10, 16);
        printf("Want to add of another record? Then press 'y' else 'n'.");
        fflush(stdin);
        another = getch();
        fflush(stdin);
        system("cls");
    }
    fclose(fp);
    gotoxy(10, 18);
    printf("Press any key to continue.");
    getch();
    menu();
}

void vaccineinfo()
{
    int check;
    system("cls");
    gotoxy(10, 3);
    printf("<--:Vaccine Information:-->");
    gotoxy(10, 5);
    printf("1.Show available Vaccines");
    gotoxy(10, 6);
    printf("2.Update avaiable Vaccines");
    gotoxy(10, 7);
    printf("3.Add avaiable Vaccines");
    gotoxy(10, 8);
    printf("4.Delete a vaccine record");
    gotoxy(10, 10);
    printf("What you you want to do : ");
    scanf("%d", &check);
    if (check == 1)
    {
        vaccineshow();
    }
    else if (check == 2)
    {
        vaccineupdate();
    }
    else if (check == 3)
    {
        vaccineadd();
    }
    else if (check == 4)
    {
        vaccinedelete();
    }
    else
    {
        gotoxy(10, 12);
        printf("Invalid Option");
    }
    gotoxy(10, 13);
    printf("Press any key to continue..");
    getchar();
    menu();
}
void vaccineadd()
{
    FILE *fp;
    struct vaccine vac;
    char another = 'y';
    system("cls");
    fp = fopen("vaccine.bin", "ab+");
    if (fp == NULL)
    {
        gotoxy(10, 5);
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while (another == 'y')
    {
        gotoxy(10, 3);
        printf("<--:ADD RECORD:-->");
        gotoxy(10, 5);
        printf("Enter details of Vaccine.");
        gotoxy(10, 7);
        printf("Enter name of vaccine : ");
        gets(vac.name);
        fflush(stdin);
        gotoxy(10, 8);
        printf("Enter no Vaccine available : ");
        scanf("%d", &vac.quantity);
        fflush(stdin);
        fwrite(&vac, sizeof(vac), 1, fp);
        gotoxy(10, 10);
        printf("Want to add of another record? Then press 'y' else 'n'.");
        fflush(stdin);
        another = getch();
        fflush(stdin);
        system("cls");
    }
    fclose(fp);
    gotoxy(10, 12);
    printf("Press any key to continue.");
    getch();
}
void vaccineshow()
{

    FILE *fp;
    int i = 1, j;
    struct vaccine vac;
    system("cls");
    gotoxy(10, 3);
    printf("<--: All available Vaccines:-->");
    gotoxy(10, 5);
    printf("No.  Name                Quantity");
    gotoxy(10, 6);
    printf("---------------------------------");
    fp = fopen("vaccine.bin", "rb+");
    if (fp == NULL)
    {
        gotoxy(10, 8);
        printf("No data found,Please Add Vaccine information.");
        gotoxy(10, 11);
        printf("Press any key to continue.");
        getch();
        menu();
    }
    j = 8;
    while (fread(&vac, sizeof(vac), 1, fp) == 1)
    {
        gotoxy(10, j);
        printf("%-5d%-20s%-10d", i, vac.name, vac.quantity);
        i++;
        j++;
    }
    fclose(fp);
    gotoxy(10, j + 3);
    printf("Press any key to continue.");
    getch();
    menu();
}
void vaccineupdate()
{
    int i = 1;
    char name[20];
    FILE *fp;
    struct vaccine vac;
    system("cls");
    gotoxy(10, 3);
    printf("<--:Update Vaccine Information:-->");
    gotoxy(10, 5);
    printf("Enter name of Vaccine to update: ");
    fflush(stdin);
    gets(name);
    fp = fopen("vaccine.bin", "rb+");
    if (fp == NULL)
    {
        gotoxy(10, 8);
        printf("No data found,Please Add Vaccine information.");
        gotoxy(10, 11);
        printf("Press any key to continue.");
        getch();
        menu();
    }
    rewind(fp);
    fflush(stdin);
    while (fread(&vac, sizeof(vac), 1, fp) == 1)
    {
        if (strcmp(name, vac.name) == 0)
        {
            gotoxy(10, 7);
            printf("No.  Name                Quantity");
            gotoxy(10, 8);
            printf("---------------------------------");
            gotoxy(10, 9);
            printf("%-5d%-20s%-10d", i, vac.name, vac.quantity);
            gotoxy(10, 14);
            printf("Enter name of vaccine : ");
            gets(vac.name);
            fflush(stdin);
            gotoxy(10, 15);
            printf("Enter no Vaccine available : ");
            scanf("%d", &vac.quantity);
            fflush(stdin);
            fseek(fp, -sizeof(vac), SEEK_CUR);
            fwrite(&vac, sizeof(vac), 1, fp);
            break;
        }
    }
    fclose(fp);
    gotoxy(10, 19);
    printf("Press any key to continue.");
    getch();
    menu();
}

void vaccinedelete()
{
    char vname[20];
    FILE *fp, *ft;
    struct vaccine vac;
    system("cls");
    gotoxy(10, 3);
    printf("<--:Delete Vaccine records:-->");
    gotoxy(10, 5);
    printf("Enter Name of Vaccine to delete record : ");
    fflush(stdin);
    gets(vname);
    fp = fopen("vaccine.bin", "rb+");
    if (fp == NULL)
    {
        gotoxy(10, 6);
        printf("Error opening file");
        exit(1);
    }
    ft = fopen("temp.bin", "wb+");
    if (ft == NULL)
    {
        gotoxy(10, 6);
        printf("Error opening file");
        exit(1);
    }
    while (fread(&vac, sizeof(vac), 1, fp) == 1)
    {
        if (strcmp(vname, vac.name) != 0)
            fwrite(&vac, sizeof(vac), 1, ft);
    }
    fclose(fp);
    fclose(ft);
    remove("vaccine.bin");
    rename("temp.bin", "vaccine.bin");
    gotoxy(10, 10);
    printf("Press any key to continue.");
    getch();
    menu();
}
void citizenlist()
{
    system("cls");
    gotoxy(10, 3);
    printf("<--:View All Citizen:-->");
    gotoxy(10, 6);
    printf("1. All citizen List");
    gotoxy(10, 7);
    printf("2. First Dose Completed List");
    gotoxy(10, 8);
    printf("3. Second Dose Completed List");
    gotoxy(10, 9);
    printf("4. Sort by age");
    gotoxy(10, 10);
    printf("5. Update Citizen Information");
    gotoxy(10, 11);
    printf("6. Delete Citizen Record");
    gotoxy(10, 13);
    printf("What do you want to do : ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1)
    {
        allcitizenlist();
    }
    else if (choice == 2)
    {
        showfirstdose();
    }
    else if (choice == 3)
    {
        showsecondose();
    }
    else if (choice == 4)
    {
        sortbyage();
    }
    else if (choice == 5)
    {
        updatecitizen();
    }
    else if (choice == 6)
    {
        deletecitizen();
    }
    else
    {
        gotoxy(10, 14);
        printf("Invalid Choice");
    }
    gotoxy(10, 16);
    printf("Press any key to continue.");
    getch();
    menu();
}

void allcitizenlist()
{
    FILE *fp;
    int i = 1, j;
    struct citizen ctz;
    system("cls");
    gotoxy(3, 3);
    printf("<--:View all citizen records:-->");
    gotoxy(3, 5);
    printf("No.  Name                Gender  Birth-date  Zipcode  National-ID      Phone-Number  First-Dose    Second-Dose  ");
    gotoxy(3, 6);
    printf("----------------------------------------------------------------------------------------------------------------");
    fp = fopen("record.bin", "rb+");
    if (fp == NULL)
    {
        gotoxy(3, 8);
        printf("No data found,Please Add Citizen information.");
        gotoxy(3, 11);
        printf("Press any key to continue.");
        getch();
        menu();
    }
    j = 8;
    while (fread(&ctz, sizeof(ctz), 1, fp) == 1)
    {
        gotoxy(3, j);
        printf("%-5d%-20s%-8s%-12s%-9s%-17s%-14s%-14s%-14s", i, ctz.name, ctz.gender, ctz.dob, ctz.upzila, ctz.nid, ctz.phoneno, ctz.firstdose, ctz.secondose);
        i++;
        j++;
    }
    fclose(fp);
    gotoxy(3, j + 3);
    printf("Press any key to continue.");
    getch();
    menu();
}
void showfirstdose()
{
    char notc[20] = "Not Completed";
    FILE *fp;
    int i = 1, j;
    struct citizen ctz;
    system("cls");
    gotoxy(3, 3);
    printf("<--:Citizens who took first dose:-->");
    gotoxy(3, 5);
    printf("No.  Name                Gender  Birth-date  Zipcode  National-ID      Phone-Number  First-Dose    Second-Dose  ");
    gotoxy(3, 6);
    printf("----------------------------------------------------------------------------------------------------------------");
    fp = fopen("record.bin", "rb+");
    if (fp == NULL)
    {
        gotoxy(3, 8);
        printf("No data found,Please Add Citizen information.");
        gotoxy(3, 11);
        printf("Press any key to continue.");
        getch();
        menu();
    }
    j = 8;
    while (fread(&ctz, sizeof(ctz), 1, fp) == 1)
    {
        if (strcmp(notc, ctz.firstdose) != 0)
        {
            gotoxy(3, j);
            printf("%-5d%-20s%-8s%-12s%-9s%-17s%-14s%-14s%-14s", i, ctz.name, ctz.gender, ctz.dob, ctz.upzila, ctz.nid, ctz.phoneno, ctz.firstdose, ctz.secondose);
            i++;
            j++;
        }
    }
    fclose(fp);
    gotoxy(3, j + 3);
    printf("Press any key to continue.");
    getch();
    menu();
}
void showsecondose()
{

    char notc[20] = "Not Completed";
    FILE *fp;
    int i = 1, j;
    struct citizen ctz;
    system("cls");
    gotoxy(3, 3);
    printf("<--:Citizens who took second dose:-->");
    gotoxy(3, 5);
    printf("No.  Name                Gender  Birth-date  Zipcode  National-ID      Phone-Number  First-Dose    Second-Dose  ");
    gotoxy(3, 6);
    printf("----------------------------------------------------------------------------------------------------------------");
    fp = fopen("record.bin", "rb+");
    if (fp == NULL)
    {
        gotoxy(3, 8);
        printf("No data found,Please Add Citizen information.");
        gotoxy(3, 11);
        printf("Press any key to continue.");
        getch();
        menu();
    }
    j = 8;
    while (fread(&ctz, sizeof(ctz), 1, fp) == 1)
    {
        if (strcmp(notc, ctz.secondose) != 0)
        {
            gotoxy(3, j);
            printf("%-5d%-20s%-8s%-12s%-9s%-17s%-14s%-14s%-14s", i, ctz.name, ctz.gender, ctz.dob, ctz.upzila, ctz.nid, ctz.phoneno, ctz.firstdose, ctz.secondose);
            i++;
            j++;
        }
    }
    fclose(fp);
    gotoxy(3, j + 3);
    printf("Press any key to continue.");
    getch();
    menu();
}
void sortbyage()
{
    int age = 0;
    FILE *fp;
    int i = 1, j, x = 0;
    struct citizen ctz;
    system("cls");
    gotoxy(3, 3);
    printf("<--:View citizen by age group:-->");
    gotoxy(3, 5);
    printf("Enter which age of people you want to view : ");
    scanf("%d", &x);
    gotoxy(3, 7);
    printf("No.  Name                Gender  Birth-date  Zipcode  National-ID      Phone-Number  First-Dose    Second-Dose  ");
    gotoxy(3, 8);
    printf("----------------------------------------------------------------------------------------------------------------");
    fp = fopen("record.bin", "rb+");
    if (fp == NULL)
    {
        gotoxy(3, 10);
        printf("No data found,Please Add Citizen information.");
        gotoxy(3, 13);
        printf("Press any key to continue.");
        getch();
        menu();
    }
    j = 10;

    while (fread(&ctz, sizeof(ctz), 1, fp) == 1)
    {
        age = agefromstring(ctz.dob);
        if (age == x)
        {
            gotoxy(3, j);
            printf("%-5d%-20s%-8s%-12s%-9s%-17s%-14s%-14s%-14s", i, ctz.name, ctz.gender, ctz.dob, ctz.upzila, ctz.nid, ctz.phoneno, ctz.firstdose, ctz.secondose);
            i++;
            j++;
        }
    }

    fclose(fp);
    gotoxy(3, j + 3);
    printf("Press any key to continue.");
    getch();
    menu();
}

void updatecitizen()
{
    char nid[20];
    int age;
    FILE *fp;
    struct citizen ctz;
    char another = 'y';
    system("cls");
    gotoxy(10, 3);
    printf("<--:Update Citizen Details:-->");
    gotoxy(10, 5);
    printf("Enter National ID of Citizen : ");
    fflush(stdin);
    gets(nid);
    fp = fopen("record.bin", "rb+");
    if (fp == NULL)
    {
        gotoxy(10, 5);
        printf("Error opening file");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    while (fread(&ctz, sizeof(ctz), 1, fp) == 1)
    {
        if (strcmp(nid, ctz.nid) == 0)
        {
            age = agefromstring(ctz.dob);
            gotoxy(10, 7);
            printf("Name         : %s", ctz.name);
            gotoxy(10, 8);
            printf("Gender       : %s", ctz.gender);
            gotoxy(10, 9);
            printf("Birth-date   : %s", ctz.dob);
            gotoxy(10, 10);
            printf("Age          : %d", age);
            gotoxy(10, 11);
            printf("Zipcode      : %s", ctz.upzila);
            gotoxy(10, 12);
            printf("National-ID  : %s", ctz.nid);
            gotoxy(10, 13);
            printf("Phone-Number : %s", ctz.phoneno);
            gotoxy(10, 14);
            printf("Vaccine Name : %s", ctz.vname);
            gotoxy(10, 15);
            printf("First-Dose   : %s ", ctz.firstdose);
            gotoxy(10, 16);
            printf("Second-Dose  : %s", ctz.secondose);
            gotoxy(10, 19);
            printf("Press Any key to continue");
            getch();
            system("cls");
            gotoxy(10, 4);
            printf("<--:New Citizen Details:-->");
            gotoxy(10, 7);
            printf("Enter Name : ");
            gets(ctz.name);
            fflush(stdin);
            gotoxy(10, 8);
            printf("Enter Gender: ");
            gets(ctz.gender);
            gotoxy(10, 9);
            printf("Enter Date Of Birth : ");
            gets(ctz.dob);
            fflush(stdin);
            gotoxy(10, 10);
            printf("Enter Zipcode : ");
            gets(ctz.upzila);
            fflush(stdin);
            gotoxy(10, 11);
            printf("Enter NID no : ");
            gets(ctz.nid);
            fflush(stdin);
            gotoxy(10, 12);
            printf("Enter Phone No : ");
            gets(ctz.phoneno);
            fflush(stdin);
            fseek(fp, -sizeof(ctz), SEEK_CUR);
            fwrite(&ctz, sizeof(ctz), 1, fp);
            break;
        }
    }
    fclose(fp);
    gotoxy(10, 18);
    printf("Press any key to continue.");
    getch();
    menu();
}
void deletecitizen()
{
    char nid[10];
    FILE *fp, *ft;
    struct citizen ctz;
    system("cls");
    gotoxy(10, 3);
    printf("<--:Delete Citizen records:-->");
    gotoxy(10, 5);
    printf("Enter National ID of Citizen to delete record : ");
    fflush(stdin);
    gets(nid);
    fp = fopen("record.bin", "rb+");
    if (fp == NULL)
    {
        gotoxy(10, 6);
        printf("Error opening file");
        exit(1);
    }
    ft = fopen("temp.bin", "wb+");
    if (ft == NULL)
    {
        gotoxy(10, 6);
        printf("Error opening file");
        exit(1);
    }
    while (fread(&ctz, sizeof(ctz), 1, fp) == 1)
    {
        if (strcmp(nid, ctz.nid) != 0)
            fwrite(&ctz, sizeof(ctz), 1, ft);
    }
    fclose(fp);
    fclose(ft);
    remove("record.bin");
    rename("temp.bin", "record.bin");
    gotoxy(10, 10);
    printf("Record Deleted Successful.");
    gotoxy(10, 11);
    printf("Press any key to continue.");
    getch();
    menu();
}

void search()
{

    system("cls");
    gotoxy(10, 3);
    printf("1. Search By National ID");
    gotoxy(10, 4);
    printf("2. Search By Phone Number");
    gotoxy(10, 6);
    printf("What do you want to do : ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1)
    {
        searchbynid();
    }
    else if (choice == 2)
    {
        searchbyphoneno();
    }
    else
    {
        gotoxy(10, 7);
        printf("Invalid Choice");
    }
    gotoxy(10, 8);
    printf("Press any key to continue.");
    getch();
    menu();
}

void searchbynid()
{
    char nid[20];
    int age = 0;
    FILE *fp;
    struct citizen ctz;
    system("cls");
    gotoxy(10, 3);
    printf("<--:Search by National ID:-->");
    gotoxy(10, 5);
    printf("Enter NID no : ");
    fflush(stdin);
    gets(nid);
    fp = fopen("record.bin", "rb+");
    if (fp == NULL)
    {
        gotoxy(10, 7);
        printf("No data found,Please Add Citizen information.");
        gotoxy(10, 10);
        printf("Press any key to continue.");
        getch();
        menu();
    }
    while (fread(&ctz, sizeof(ctz), 1, fp) == 1)
    {
        if (strcmp(nid, ctz.nid) == 0)
        {
            age = agefromstring(ctz.dob);
            gotoxy(10, 7);
            printf("Name         : %s", ctz.name);
            gotoxy(10, 8);
            printf("Gender       : %s", ctz.gender);
            gotoxy(10, 9);
            printf("Birth-date   : %s", ctz.dob);
            gotoxy(10, 10);
            printf("Age          : %d", age);
            gotoxy(10, 11);
            printf("Zipcode      : %s", ctz.upzila);
            gotoxy(10, 12);
            printf("National-ID  : %s", ctz.nid);
            gotoxy(10, 13);
            printf("Phone-Number : %s", ctz.phoneno);
            gotoxy(10, 14);
            printf("Vaccine Name : %s", ctz.vname);
            gotoxy(10, 15);
            printf("First-Dose   : %s ", ctz.firstdose);
            gotoxy(10, 16);
            printf("Second-Dose  : %s", ctz.secondose);
        }
    }
    fclose(fp);
    gotoxy(10, 19);
    printf("Press any key to continue.");
    getch();
    menu();
}

void searchbyphoneno()
{
    char phoneno[20];
    int age = 0;
    FILE *fp;
    struct citizen ctz;
    system("cls");
    gotoxy(10, 3);
    printf("<--:Search by Phone Number:-->");
    gotoxy(10, 5);
    printf("Enter Phone no : ");
    fflush(stdin);
    gets(phoneno);
    fp = fopen("record.bin", "rb+");
    if (fp == NULL)
    {
        gotoxy(10, 7);
        printf("No data found,Please Add Citizen information.");
        gotoxy(10, 10);
        printf("Press any key to continue.");
        getch();
        menu();
    }
    while (fread(&ctz, sizeof(ctz), 1, fp) == 1)
    {
        if (strcmp(phoneno, ctz.phoneno) == 0)
        {
            age = agefromstring(ctz.dob);
            gotoxy(10, 7);
            printf("Name         : %s", ctz.name);
            gotoxy(10, 8);
            printf("Gender       : %s", ctz.gender);
            gotoxy(10, 9);
            printf("Birth-date   : %s", ctz.dob);
            gotoxy(10, 10);
            printf("Age          : %d", age);
            gotoxy(10, 11);
            printf("Zipcode      : %s", ctz.upzila);
            gotoxy(10, 12);
            printf("National-ID  : %s", ctz.nid);
            gotoxy(10, 13);
            printf("Phone-Number : %s", ctz.phoneno);
            gotoxy(10, 14);
            printf("Vaccine Name : %s", ctz.vname);
            gotoxy(10, 15);
            printf("First-Dose   : %s ", ctz.firstdose);
            gotoxy(10, 16);
            printf("Second-Dose  : %s", ctz.secondose);
        }
    }
    fclose(fp);
    gotoxy(10, 19);
    printf("Press any key to continue.");
    getch();
    menu();
}

int agefromstring(char date[10])
{
    char dayc[2];
    dayc[0] = date[0];
    dayc[1] = date[1];
    char monthc[2];
    monthc[0] = date[3];
    monthc[1] = date[4];
    char yearc[4];
    yearc[0] = date[6];
    yearc[1] = date[7];
    yearc[2] = date[8];
    yearc[3] = date[9];
    int iday;
    iday = (dayc[0] - 48) * 10 + (dayc[1] - 48);
    int imonth;
    imonth = (monthc[0] - 48) * 10 + (monthc[1] - 48);
    int iyear;
    iyear = (yearc[0] - 48) * 1000 + (yearc[1] - 48) * 100 + (yearc[2] - 48) * 10 + (yearc[3] - 48);
    int present_date = day, present_month = month, present_year = year, birth_date = iday, birth_month = imonth, birth_year = iyear;
    int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (birth_date > present_date)
    {
        present_date = present_date + month[birth_month - 1];
        present_month = present_month - 1;
    }
    if (birth_month > present_month)
    {
        present_year = present_year - 1;
        present_month = present_month + 12;
    }
    int final_date = present_date - birth_date;
    int final_month = present_month - birth_month;
    int final_year = present_year - birth_year;
    return final_year;
}

void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}