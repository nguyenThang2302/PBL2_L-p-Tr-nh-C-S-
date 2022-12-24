#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include "Introduce.h"

void Introduce::Run_Introduce(Introduce &intro)
{
    system("title Simple Order System");
    system("mode con: cols=88 lines=30");
    loadingbar();
    cls();
    pwellcome();
    Sleep(300);
    cls();
}

void Introduce::cls()
{

    system("cls");
}

void Introduce::echo(char print[])
{

    printf("%s", print);
}

void Introduce::br(int line)
{
    for (int i = 0; i < line; i++)
    {
        printf("\n");
    }
}

void Introduce::pre(int tab)
{

    for (int i = 0; i < tab; i++)
    {
        printf("\t");
    }
}

void Introduce::span(int space)
{

    for (int i = 0; i < space; i++)
    {
        printf(" ");
    }
}

void Introduce::ccolor(int clr)
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Introduce::pwellcome()
{
    ccolor(26);

    char welcome[50] = "WELCOME";
    char welcome2[50] = " TO";
    char welcome3[50] = " DELICIOUS FOOD";
    char welcome4[50] = " ORDER SYSTEM ITF";
    printf("\n\n\n\n\n\t\t\t");
    for (int wlc = 0; wlc < strlen(welcome); wlc++)
    {

        printf(" %c", welcome[wlc]);
        Sleep(100);
    }
    ccolor(26);
    printf("\n\n\t\t\t\t ");
    for (int wlc2 = 0; wlc2 < strlen(welcome2); wlc2++)
    {

        printf(" %c", welcome2[wlc2]);
        Sleep(100);
    }
    ccolor(26);
    printf("\n\n\n\t\t\t ");
    for (int wlc3 = 0; wlc3 < strlen(welcome3); wlc3++)
    {
        if (welcome3[wlc3] != 'D')
        {

            printf(" %c", welcome3[wlc3]);
        }
        else
        {

            printf(" %c", welcome3[wlc3]);
        }

        Sleep(100);
    }
    ccolor(26);
    printf("\n\n\n\t\t\t\t ");
    for (int wlc3 = 0; wlc3 < strlen(welcome4); wlc3++)
    {
        if (welcome4[wlc3] != 'A' && welcome4[wlc3] != 'E')
        {

            printf(" %c", welcome4[wlc3]);
        }
        else
        {

            printf(" %c", welcome4[wlc3]);
        }
        Sleep(100);
    }
    ccolor(26);
}
void Introduce::loadingbar(void)
{

    for (int i = 15; i <= 100; i += 5)
    {

        cls();

        printf("\n\n\n\n\n\n\n\t\t\t\t");
        printf("%d %% Loading...\n\n\t\t", i);

        printf("");

        for (int j = 0; j < i; j += 2)
        {

            ccolor(160 + j);
            printf(" ");
            ccolor(26);
        }
        Sleep(100);
        if (i == 90 || i == 50 || i == 96 || i == 83)
        {
            Sleep(100);
        }
    }
}
void Introduce::backuploader(void)
{

    for (int i = 15; i <= 100; i += 5)
    {

        cls();
        ccolor(26);

        printf("\n\n\n\n\n\n\n\t\t\t\t");
        printf("%d %% Backing UP DATA...\n\n\t\t", i);

        printf("");

        for (int j = 0; j < i; j += 2)
        {

            ccolor(120 + j);
            printf(" ");
            ccolor(26);
        }
        Sleep(50);
        if (i == 90 || i == 50 || i == 96 || i == 83)
        {
            Sleep(50);
        }
    }
}

void Introduce::middle1(void)
{

    printf("\n\n\n\n\n\n\n");
}

void Introduce::middtab1(void)
{
    printf("\t\t\t\t\t");
}