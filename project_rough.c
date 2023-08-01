#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <dos.h>
typedef struct student_info
{
    int id;
    char name[30];
    char dept[10];
    int wallet;
    char pass[30];
};
typedef struct menu_info
{
    int index;
    char item[100];
    int price;
};

void add_student()
{
    struct student_info h;
    FILE *fp = fopen("student_info.txt", "a+");
    printf("Enter id:");
    scanf("%d", &h.id);
    printf("\nEnter name:");
    scanf("%s", h.name);
    printf("\nEnter dept:");
    scanf("%s", h.dept);
    printf("\nEnter wallet initial balance: ");
    scanf("%d", &h.wallet);
    printf("\nGive a password:");
    scanf("%s", h.pass);
    fprintf(fp, "%d %s %s %d %s\n", h.id, h.name, h.dept, h.wallet, h.pass);
    fclose(fp);
}
void remove_student(int n_id)
{
    struct student_info h;
    FILE *file, *temp;
    file = fopen("student_info.txt", "r");
    temp = fopen("temp_remove_s.txt", "w");

    while (fscanf(file, "%d %s %s %d %s", &h.id, h.name, h.dept, &h.wallet, h.pass))
    {
        if (fgetc(file) == EOF)
            break;
        if (n_id == h.id)
            continue;
        fprintf(temp, "%d %s %s %d %s\n", h.id, h.name, h.dept, h.wallet, h.pass);
    }
    // fprintf(temp, "%d %s %s %d %s\n", h.id, h.name, h.dept, h.wallet, h.pass);
    fclose(file);
    fclose(temp);
    remove("student_info.txt");
    rename("temp_remove_s.txt", "student_info.txt");
}
void edit_student(int n_id)
{
    struct student_info h;
    FILE *file, *temp;
    file = fopen("student_info.txt", "r");
    temp = fopen("temp_edit_s.txt", "w");
    while (fscanf(file, "%d %s %s %d %s", &h.id, h.name, h.dept, &h.wallet, h.pass))
    {
        if (fgetc(file) == EOF)
            break;
        if (h.id == n_id)
        {
            printf("\nEnter id:");
            scanf("%d", &h.id);
            printf("\nEnter name:");
            scanf("%s", h.name);
            printf("\nEnter dept:");
            scanf("%s", h.dept);
            printf("\nEnter wallet initial balance: ");
            scanf("%d", &h.wallet);
            printf("\nGive a password:");
            scanf("%s", h.pass);
        }
        fprintf(temp, "%d %s %s %d %s\n", h.id, h.name, h.dept, h.wallet, h.pass);
    }
    fclose(file);
    fclose(temp);
    remove("student_info.txt");
    rename("temp_edit_s.txt", "student_info.txt");
}
void display_student_info() // FOR ADMIN USE
{
    struct student_info h;
    FILE *file = fopen("student_info.txt", "r");
    printf("-----------------------------------------------------------------------\n");
    printf("%-10s%-20s%-10s%-20s%-30s\n", "ID", "NAME", "DEPT", "WALLET", "PASSWORD");
    printf("-----------------------------------------------------------------------\n");
    while (fscanf(file, "%d %s %s %d %s", &h.id, h.name, h.dept, &h.wallet, h.pass))
    {
        if (fgetc(file) == EOF)
            break;
        printf("%-10d%-20s%-10s%-20d%-30s\n", h.id, h.name, h.dept, h.wallet, h.pass);
    }
    fclose(file);
}
void add_menu_item()
{
    struct menu_info h;
    FILE *file = fopen("menu.txt", "a+");
    printf("\nEnter item index:");
    scanf("%d", &h.index);
    printf("Enter item name(dont use space use underscore):");
    scanf("%s", h.item);
    printf("\nEnter item price:");
    scanf("%d", &h.price);
    fprintf(file, "%d %s %d\n", h.index, h.item, h.price);
    fclose(file);
}
void remove_menu(int n_index)
{
    struct menu_info h;
    FILE *file, *temp;
    file = fopen("menu.txt", "r");
    temp = fopen("temp_remove_s.txt", "w");

    while (fscanf(file, "%d %s %d", &h.index, h.item, &h.price))
    {
        if (fgetc(file) == EOF)
            break;
        if (n_index == h.index)
            continue;
        fprintf(temp, "%d %s %d\n", h.index, h.item, h.price);
    }
    // fprintf(temp, "%d %s %d\n", h.index, h.item, h.price);
    fclose(file);
    fclose(temp);
    remove("menu.txt");
    rename("temp_remove_s.txt", "menu.txt");
}
void edit_menu(int n_index)
{
    struct menu_info h;
    FILE *file, *temp;
    file = fopen("menu.txt", "r");
    temp = fopen("temp_remove_s.txt", "w");

    while (fscanf(file, "%d %s %d", &h.index, h.item, &h.price))
    {
        if (fgetc(file) == EOF)
            break;
        if (n_index == h.index)
        {
            printf("\nEnter item index:");
            scanf("%d", &h.index);
            printf("Enter item name(dont use space use underscore)\n");
            scanf("%s", h.item);
            printf("Enter item price:");
            scanf("%d", &h.price);
        }
        fprintf(temp, "%d %s %d\n", h.index, h.item, h.price);
    }
    //  fprintf(temp, "%d %s %d\n", h.index, h.item, h.price);
    fclose(file);
    fclose(temp);
    remove("menu.txt");
    rename("temp_remove_s.txt", "menu.txt");
}
void display_menu()
{
    struct menu_info h;
    FILE *file = fopen("menu.txt", "r");
    printf("-------------------------------------------------------\n");
    printf("%-20s%-30s%-10s\n", "ITEM_index", "ITEM", "PRICE");
    printf("--------------------------------------------------------\n");
    while (fscanf(file, "%d %s %d", &h.index, h.item, &h.price))
    {
        if (fgetc(file) == EOF)
            break;
        printf("%-20d%-30s%-10d\n", h.index, h.item, h.price);
    }
    // printf("%-20d%-30s%-10d\n", h.index, h.item, h.price);
    fclose(file);
}
int main()
{
    int n, i, sml = 1, n_admin, n_user;
    do
    {

    start:
        system("cls");
        system("COLOR 61");
        printf("############################ MESS MANAGEMENT ############################\n");
        printf("<><><><><><><><><><><><><><><><><><><><><><><><><>");
        printf("\n                         1.ADMIN                                       \n");
        printf("                         2.USER                                         \n");
        printf("                         0.EXIT                                          \n");
        printf("choose  your number:");
        scanf("%d", &n);
        if (n == 1)
        {
            system("COLOR 65");
            char ch, pwd[30]; // printf("ok\n"); // admin panel
            // char admin_pass[30] = "admin"; // will do this by file reading
            printf("enter your administration password: ");
            i = 0;
            while ((ch = _getch()) != 13)
            {
                pwd[i] = ch;
                i++;
                printf("*");
            }
            pwd[i] = '\0';
            printf("\nloading:");
            for (int ji = 0; ji < 2; ji++)
            {
                sleep(1);
                printf("---");
            }
            printf("\n");
            FILE *fp_old = fopen("password.txt", "r");
            char check_pass[50];
            fscanf(fp_old, "%s", check_pass);
            fclose(fp_old);
            if (strcmp(pwd, check_pass) == 0) // if (strcmp(admin_pass, pwd) == 0)
            {
                system("cls");
                system("COLOR B4");
                printf("\npassword matched\n");
                printf("\n<<<<<<<<<<<<<<<<<<<<<<< ADMIN PANEL >>>>>>>>>>>>>>>>>>>>>>>>>\n");
            start_admin:
                printf("\n1.Add student\n");
                printf("2.Remove student\n");
                printf("3.Edit student info\n");
                printf("4.Display student info\n");
                printf("5.Add Item\n");
                printf("6.Remove Item\n");
                printf("7.Edit menu\n");
                printf("8.Display menu\n");
                printf("9.Change Admin password\n");
               // printf("10.Add money to mess(Gift from alumni):\n");
               // printf("11.Display mess totall money:\n");
                printf("0.Home\n");
                printf("choose your choice: ");
                scanf("%d", &n_admin);
                int n_edit; // n_s_remove, n_s_edit, n_edit_menu, n_remove_item;
                switch (n_admin)
                {
                case 1:
                {
                    system("cls");
                    system("COLOR A4");
                    printf("\nhere is the previous data\n");
                    display_student_info();
                    printf("Enter new data\n");
                    add_student();
                    printf("\n********Edited list:********\n");
                    display_student_info();
                }
                break;
                case 2:
                {
                    system("cls");
                    system("COLOR A4");
                    display_student_info();
                    printf("\nEnter the id you want to remove:\n");
                    scanf("%d", &n_edit);
                    remove_student(n_edit);
                    printf("\n********Edited list:********\n");
                    display_student_info();
                }
                break;
                case 3:
                {
                    system("cls");
                    system("COLOR A4");
                    display_student_info();
                    printf("\nEnter the id you want to edit:\n");
                    scanf("%d", &n_edit);
                    edit_student(n_edit);
                    printf("\n********Edited list:********\n");
                    display_student_info();
                }
                break;
                case 4:
                {
                    system("cls");
                    system("COLOR A4");

                    display_student_info(); // void func
                }
                break;
                case 5:
                {
                    system("cls");
                    system("COLOR A4");
                    printf("\nHere is the previous menu\n");
                    display_menu();
                    printf("Enter new menu item\n");
                    add_menu_item();
                    printf("\n********Edited list:********\n");
                    display_menu();
                }
                break;
                case 6:
                {
                    system("cls");
                    system("COLOR A4");
                    display_menu();
                    printf("Enter which element you want to remove:\n");
                    scanf("%d", &n_edit);
                    remove_menu(n_edit);
                    printf("\n********Edited list:********\n");
                    display_menu();
                }
                break;
                case 7:
                {
                    system("cls");
                    system("COLOR A4");
                    display_menu();
                    printf("Enter which element you want to edit:\n");
                    scanf("%d", &n_edit);
                    edit_menu(n_edit);
                    printf("\n********Edited list:********\n");
                    display_menu();
                }
                break;
                case 8:
                {
                    system("cls");
                    system("COLOR A4");
                    display_menu();
                }
                break;
                case 9:
                {
                    system("cls");
                    system("COLOR 06");
                    char new_pass[50], old_pass[50], saved_pass[50];
                    FILE *fp_oldpass = fopen("password.txt", "r");
                    fscanf(fp_oldpass, "%s", saved_pass);
                    printf("enter your previous password\n");
                    i = 0;
                    while ((ch = _getch()) != 13) // as ch introduced in this block i can use it here
                    {
                        old_pass[i] = ch;
                        i++;
                        printf("*");
                    }
                    old_pass[i]='\0';
                    fclose(fp_oldpass);
                    if (strcmp(old_pass, saved_pass) == 0)
                    {
                        printf("\nenter your new pass:(don't use space use underscore)\n");
                        i=0;
                        while ((ch = _getch()) != 13) // as ch introduced in this block i can use it here
                        {
                            new_pass[i] = ch;
                            i++;
                            printf("*");
                        }
                        new_pass[i]='\0';
                        FILE *fp_newpass = fopen("password.txt", "w");
                        fprintf(fp_newpass, "%s", new_pass);
                        fclose(fp_newpass);
                        system("cls");
                        printf("password succesfully changed\n");
                        system("COLOR 02");
                    }
                    else
                    {
                        system("cls");
                        system("COLOR C0");
                        printf("you have entered wrong password\nyou are returning in home page.\n");

                        for (int ji = 0; ji < 2; ji++)
                        {
                            sleep(1);
                            printf("---");
                        }
                        goto start;
                    }
                }
                break;
                case 0:
                {
                    system("cls");
                    system("COLOR A4");
                    goto start;
                    break;
                }
                default:
                {
                    system("cls");
                    system("COLOR A4");
                    printf("Invalid choice\n");
                    goto start_admin;
                }
                break;
                }
                goto start_admin;
            }
            else
            {
                system("COLOR 04");
                printf("\nyou have entered wrong password %c\n", sml);

                for (int ji = 0; ji < 3; ji++)
                {
                    sleep(1);
                    printf("wrong password %c\n", sml);
                }
                goto start;
            }
        }

        else if (n == 2)
        {
            system("cls");
            system("COLOR E4");

        user_log_in:
            struct student_info hp;
            int user_id, check = 0, check_id = 0;
            char user_pass[50];
            printf("\nyour user ID(Enter 0 to go home):");
            FILE *fp_user = fopen("student_info.txt", "r");
            FILE *temp = fopen("temp1.txt", "w");
            scanf("%d", &user_id);
            if (user_id == 0)
                goto start;
            printf("\nenter your pass:\n");
            int i_pass = 0;
            char ch;
            while ((ch = _getch()) != 13)
            {
                user_pass[i_pass] = ch;
                i_pass++;
                printf("*");
            }
            user_pass[i_pass] = '\0';
            printf("\n%s",user_pass);  //for debugging perpose;
            printf("\nloading\n");
            for (int ji = 0; ji < 2; ji++)
            {
                sleep(1);
                printf("---");
            }
            printf("\n");
            while (fscanf(fp_user, "%d %s %s %d %s", &hp.id, hp.name, hp.dept, &hp.wallet, hp.pass))
            {
                if (fgetc(fp_user) == EOF)
                    break;
                if (user_id == hp.id)
                {
                    check_id = 1;
                    if (strcmp(user_pass, hp.pass) == 0)
                    {
                        system("cls");
                        system("COLOR A1");
                        check = 1;
                        printf("\n***********Successfully log in***********\n");
                        int view_user;
                    after_user_log_in:
                        printf("1.My information\n");
                        printf("2.Buy items\n");
                        printf("0.Home_page\n");
                        printf("Enter your choice:");
                        scanf("%d", &view_user);
                        if (view_user == 0)
                        {
                            // fprintf(temp, "%d %s %s %d %s\n", hp.id, hp.name, hp.dept, hp.wallet, hp.pass);
                            goto start;
                        }
                        else if (view_user == 1)
                        {
                            // fprintf(temp, "%d %s %s %d %s\n", hp.id, hp.name, hp.dept, hp.wallet, hp.pass);
                            system("cls");
                            system("COLOR 90");
                            printf("...............your info is................\n");
                            printf("%-10s%-20s%-10s%-20s%-30s\n", "ID", "NAME", "DEPT", "WALLET", "PASSWORD");
                            printf("%-10d%-20s%-10s%-20d%-30s\n", hp.id, hp.name, hp.dept, hp.wallet, hp.pass);
                            printf("\n");
                            goto after_user_log_in;
                        }
                        else if (view_user == 2)
                        {
                            system("cls");
                            system("COLOR F4");
                            int check_buy_index = 0; // to check user inputs index are in file or not
                            struct menu_info m;
                            FILE *fp_menu = fopen("menu.txt", "r");
                            int buy_index;
                            display_menu();
                            printf("select the index to buy\n");
                            scanf("%d", &buy_index);
                            while (fscanf(fp_menu, "%d %s %d", &m.index, m.item, &m.price))
                            {
                                if (fgetc(fp_menu) == EOF)
                                    break;
                                if (buy_index == m.index)
                                {
                                    check_buy_index = 1;
                                    if (hp.wallet >= m.price)
                                    {
                                        // system("cls");
                                        system("COLOR B2");
                                        printf("\nyou have bought item %d.%s\n", m.index, m.item);
                                        hp.wallet = (hp.wallet - m.price); // present money
                                        printf("you have now %d taka\n\n", hp.wallet);
                                        // hp.wallet = c;
                                        printf("Thank you Please visit again\n");
                                        fprintf(temp, "%d %s %s %d %s\n", hp.id, hp.name, hp.dept, hp.wallet, hp.pass);
                                        for (int ji = 0; ji < 4; ji++)
                                        {
                                            sleep(1);
                                            printf("---");
                                        }
                                    }
                                    else
                                    {
                                        // fprintf(temp, "%d %s %s %d %s\n", hp.id, hp.name, hp.dept, hp.wallet, hp.pass);
                                        printf("\nyou dont have enough amount to buy it\n");
                                        goto after_user_log_in;
                                    }
                                }
                            }
                            if (check_buy_index != 1)
                            {
                                fprintf(temp, "%d %s %s %d %s\n", hp.id, hp.name, hp.dept, hp.wallet, hp.pass);
                                printf("please enter right index\n");
                                goto after_user_log_in;
                            }
                        }
                        else
                        {
                            fprintf(temp, "%d %s %s %d %s\n", hp.id, hp.name, hp.dept, hp.wallet, hp.pass);
                            system("cls");
                            system("COLOR F4");
                            printf("Enter correct input:\n");
                            goto after_user_log_in;
                        }
                    }
                    else
                    {
                        fprintf(temp, "%d %s %s %d %s\n", hp.id, hp.name, hp.dept, hp.wallet, hp.pass);
                        system("cls");
                        system("COLOR 04");
                        printf("\nwrong password.Enter correct password:\n");
                        goto user_log_in;
                    }
                }
                else
                    fprintf(temp, "%d %s %s %d %s\n", hp.id, hp.name, hp.dept, hp.wallet, hp.pass);
            }
            fclose(fp_user);
            fclose(temp);
            remove("student_info.txt");
            rename("temp1.txt", "student_info.txt");
            if ((check != 1) || (check_id != 1))
            {
                // fprintf(temp, "%d %s %s %d %s\n", hp.id, hp.name, hp.dept, hp.wallet, hp.pass);
                system("cls");
                system("COLOR 04");
                printf("\nEnter corrct id and password\n");
                goto user_log_in;
            }
        }

        else if (n == 0)
        {
            system("cls");
            system("COLOR B0");
            printf("\nThank you !");
            return 0;
        }
        else
        {
            system("cls");
            system("COLOR 03");
            printf("you have entered wrong number.\n");
        }
    } while (n);
}