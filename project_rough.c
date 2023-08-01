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
void my_information(int n)
{
    FILE *fp = fopen("student_info.txt", "r");
    struct student_info hp;
    printf("%d", n);
    while (fscanf(fp, "%d %s %s %d %s", &hp.id, hp.name, hp.dept, &hp.wallet, hp.pass))
    {
        if (fgetc(fp) == EOF)
            break;
        if (n == hp.id)
        {
            printf("...............your info is..............\n");
            printf("%-10s%-20s%-10s%-20s%-30s\n", "ID", "NAME", "DEPT", "WALLET", "PASSWORD");
            printf("%-10d%-20s%-10s%-20d%-30s\n", hp.id, hp.name, hp.dept, hp.wallet, hp.pass);
            printf("\n");
        }
    }
}
void add_money(int user_id)
{
    int carry;
    struct student_info h;
    FILE *file, *temp;
    file = fopen("student_info.txt", "r");
    temp = fopen("temp.txt", "w");
    while (fscanf(file, "%d %s %s %d %s", &h.id, h.name, h.dept, &h.wallet, h.pass))
    {
        if (fgetc(file) == EOF)
            break;
        if (h.id == user_id)
        {
            printf("\nEnter amount to add:\n");
            scanf("%d", &carry);
            h.wallet = h.wallet + carry;
        }
        fprintf(temp, "%d %s %s %d %s\n", h.id, h.name, h.dept, h.wallet, h.pass);
    }
    fclose(file);
    fclose(temp);
}
void change_file()
{
    struct student_info hp1;
    FILE *fp_again = fopen("student_info.txt", "w");
    FILE *fp_temp = fopen("temp.txt", "r");
    while (fscanf(fp_temp, "%d %s %s %d %s", &hp1.id, hp1.name, hp1.dept, &hp1.wallet, hp1.pass))
    {
        if (fgetc(fp_temp) == EOF)
            break;
        fprintf(fp_again, "%d %s %s %d %s\n", hp1.id, hp1.name, hp1.dept, hp1.wallet, hp1.pass);
    }
    fclose(fp_again);
    fclose(fp_temp);
}
int buy_items(int n, int index) // for user only
{
    int check_buy_index = 0, check_id = 0, can_buy = 0; // to check user inputs index are in file or not
    struct menu_info m;
    struct student_info hp;
    FILE *fp_menu = fopen("menu.txt", "r");
    FILE *fp = fopen("student_info.txt", "r");
    while (fscanf(fp, "%d %s %s %d %s", &hp.id, hp.name, hp.dept, &hp.wallet, hp.pass))
    {
        if (fgetc(fp) == EOF)
            break;
        if (hp.id == n)
        {
            check_id = 1;
            break;
        }
    }
    // int buy_index;
    while (fscanf(fp_menu, "%d %s %d", &m.index, m.item, &m.price))
    {
        if (fgetc(fp_menu) == EOF)
            break;
        if (index == m.index)
        {
            check_buy_index = 1;
            if (hp.wallet >= m.price)
            {
                can_buy = 1;
                printf("you are able to buy this.\n");
            }
            else
            {
                printf("you dont have enough money to buy it\n\nyou are returning again in home page\nplease log in again\n");
                for (int delay = 0; delay < 5; delay++)
                {
                    sleep(1);
                    printf("...");
                }
            }
        }
    }
    if ((check_buy_index != 1) || (check_id != 1))
    {
        printf("you have enter wrong index\n");
    }
    if (can_buy == 1)
    {
        return 1;
    }
    else
        return 0;
}
void remaining_money_of_user(int user_id, int item_index)
{
    struct student_info h;
    struct menu_info m;
    FILE *fp = fopen("student_info.txt", "r");
    FILE *fp_menu = fopen("menu.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    while (fscanf(fp, "%d %s %s %d %s", &h.id, h.name, h.dept, &h.wallet, h.pass))
    {
        if (fgetc(fp) == EOF)
            break;
        if (user_id == h.id)
        {
            while (fscanf(fp_menu, "%d %s %d", &m.index, m.item, &m.price))
            {
                if (fgetc(fp_menu) == EOF)
                    break;
                if (item_index == m.index)
                {
                    h.wallet = h.wallet - m.price;
                    printf("you have now %d tk\n", h.wallet);
                }
            }
            fprintf(temp, "%d %s %s %d %s\n", h.id, h.name, h.dept, h.wallet, h.pass);
        }
        else
            fprintf(temp, "%d %s %s %d %s\n", h.id, h.name, h.dept, h.wallet, h.pass);
    }
    // fprintf(temp, "%d %s %s %d %s\n", h.id, h.name, h.dept, h.wallet, h.pass);
    fclose(fp);
    fclose(temp);
    fclose(fp_menu);
}
void change_file_add_money(int user_id)
{
    struct student_info hp1;
    FILE *fp_again = fopen("student_info.txt", "w");
    FILE *fp_temp = fopen("temp_edit_s.txt.txt", "r");
    while (fscanf(fp_temp, "%d %s %s %d %s", &hp1.id, hp1.name, hp1.dept, &hp1.wallet, hp1.pass))
    {
        if (fgetc(fp_temp) == EOF)
            break;
        fprintf(fp_again, "%d %s %s %d %s\n", hp1.id, hp1.name, hp1.dept, hp1.wallet, hp1.pass);
    }
    fclose(fp_again);
    fclose(fp_temp);
}
int main()
{
    int n, i, sml = 1, n_admin, n_user, new_file_create = 0, new_add_money = 0;
    do
    {

    start:
        system("cls");
        system("COLOR F0");
    start_fromcredit:
        printf("############################ MESS MANAGEMENT ############################\n");
        printf("<><><><><><><><><><><><><><><><><><><><><><><><><>");
        printf("\n                         1.ADMIN                                       \n");
        printf("                         2.USER                                         \n");
        printf("                         3.CREDITS(for this system)                                    \n");
        printf("                         0.EXIT                                          \n");
        printf("choose  your number:");
        scanf("%d", &n);
        if (n == 1)
        {
            system("COLOR 52");
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
                    system("COLOR E4");
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
                    system("COLOR F0");
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
                    system("COLOR 90");
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
                    system("COLOR B4");
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
                    system("COLOR 74");
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
                    old_pass[i] = '\0';
                    fclose(fp_oldpass);
                    if (strcmp(old_pass, saved_pass) == 0)
                    {
                        printf("\nenter your new pass:(don't use space use underscore)\n");
                        i = 0;
                        while ((ch = _getch()) != 13) // as ch introduced in this block i can use it here
                        {
                            new_pass[i] = ch;
                            i++;
                            printf("*");
                        }
                        new_pass[i] = '\0';
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
            int user_id, check_pass = 0, check_id = 0;
            char user_pass[50];
            printf("\nyour user ID(Enter 0 to go home):");
            FILE *fp_user = fopen("student_info.txt", "r");

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
            // printf("\n%s", user_pass); // for debugging perpose;
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

                        check_pass = 1;
                        system("cls");
                        system("COLOR 20");
                        printf("***************Succesfully log in***********\n");
                    after_login:
                        printf("1.My information\n2.View Menu\n3.Buy items\n4.Add money\n0.Home\n");
                        printf("Enter your choice:\n");
                        int view_user;
                        scanf("%d", &view_user);
                        switch (view_user)
                        {
                        case 1:
                        {
                            new_add_money = 0;
                            new_file_create = 0;
                            system("cls");
                            system("COLOR E1");
                            my_information(user_id);
                            goto after_login;
                        }
                        break;
                        case 2:
                        {
                            new_add_money = 0;
                            new_file_create = 0;
                            system("cls");
                            system("COLOR 90");
                            display_menu();
                            goto after_login;
                        }
                        break;
                        case 3:
                        {
                            system("COLOR E0");
                            new_add_money = 0;
                            new_file_create = 0;
                            display_menu();
                            printf("which item you want to buy:\n");
                            int buy_index;
                            scanf("%d", &buy_index);
                            int b = buy_items(user_id, buy_index); // to check user id and buy index are inputted corrected or not
                            if (b == 1)                            // if return is 1 then goto file change
                            {
                                new_add_money = 0;
                                new_file_create = 1; // do we need new file create or not
                                remaining_money_of_user(user_id, buy_index);
                                break;
                            }
                        }
                        break;
                        case 4:
                        {
                            new_file_create = 0;
                            new_add_money = 1;
                            system("cls");
                            system("COLOR 74");
                            printf("\nyour current info is \n");
                            my_information(user_id);
                            /*add_money(user_id);
                            printf("your edited info is");
                            my_information(user_id);...
                            printf("you are returning into homepage.\nplease wait.");
                            for (int delay = 0; delay <= 15; delay++)
                            {
                                sleep(1);
                                printf("...");
                            }
                            printf("\n");*/
                            break;
                        }
                        break;
                        case 0:
                        {
                            new_add_money = 0;
                            new_file_create = 0;
                            goto start;
                        }
                        break;
                        }
                    }
                    else
                        new_file_create = 0;
                }
            }
            fclose(fp_user);
            if (new_file_create == 1)
            {
                change_file();
                printf("here is your info\n");
                my_information(user_id);
                printf("you are returning into homepage.\nplease wait.");
                for (int delay = 0; delay <= 7; delay++)
                {
                    sleep(1);
                    printf("...");
                }
                printf("\n");
            }
            if (new_add_money == 1)
            {
                add_money(user_id);
                change_file(user_id);
                printf("your info is\n");
                my_information(user_id);
                printf("you are returning into homepage.\nplease wait.");
                for (int delay = 0; delay <= 7; delay++)
                {
                    sleep(1);
                    printf("...");
                }
                printf("\n");
            }

            if ((check_id != 1) || (check_pass != 1))
            {
                system("cls");
                system("COLOR 04");

                printf("entered wrong id or pass\n");
                printf("you are returning in home page");
                for (int delay = 0; delay < 5; delay++)
                {
                    sleep(1);
                    printf("...");
                }
                goto start;
            }
            goto start;
        }
        else if (n == 3)
        {
            int nh;
            system("cls");
            system("COLOR 06");
            printf("\n<><><><><><><><><><><><><><><><><><><><><><><><><<><><><>><><><><><><><><><><><><><><><><>\n");
            printf("            DESIGNED by            *****************        SUPERVISED by\n");
            printf("            Md.Enayet Ullah Alvee                           Syed Muhammad Ibn Zulfiker\n");
            printf("            Student                                         Lecturer\n");
            printf("            CSE,BUET                                        CSE,BUET\n");
            printf("            ID:2105107                                      ID:1605110\n");
            printf("\n\n\n");
            goto start_fromcredit;
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
            printf("you have entered wrong input.please select 1,2 or 0\n");
        }
    } while (n);
}