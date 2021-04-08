#include <iostream>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <Windows.h>    
#include <iomanip>
#include <string>
#include <stdio.h>
#include <dos.h>

using namespace std;

const int SIZEf = 10;
int GameTable[SIZEf][SIZEf] = {};

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

void DrawWelcomeInGame()
{


    cout << "           ----------------------------------------------------------------" << endl;
    cout << "           |     *******      **      *********    *          ********      |" << endl;
    cout << "           |     *     *     *  *         *        *          *             |" << endl;
    cout << "           |     *******    ******        *        *          *******       |" << endl;
    cout << "           |     *     *   *      *       *        *          *             |" << endl;
    cout << "           |     *******  *        *      *        ******     ********      |" << endl;
    cout << "           ------------------------------------------------------------------" << endl;
    cout << "           |      *******    *    *        *        *******                 |" << endl;
    cout << "           |      *          *    *        *        *     *                 |" << endl;
    cout << "           |      *******    ******        *        *******                 |" << endl;
    cout << "           |            *    *    *        *        *                       |" << endl;
    cout << "           |      *******    *    *        *        *                       |" << endl;
    cout << "           |                                                                |" << endl;
    cout << "           |-----------------------------------------------------------------" << endl;


    string myName;


    cout << "What is your name?" << endl;
    cin >> myName;

    cout << "***************************************************" << endl;
    cout << " " << endl;
    cout << "                 Welcome, " << myName << "!" << endl;
    cout << " " << endl;
    cout << "***************************************************" << endl;



}



void GXY(int X, int Y)
{
    COORD coord = { X, Y };
    SetConsoleCursorPosition(hStdOut, coord);
}

void GameMenu()
{

    int f = 1, k, code;

    cout << "\n\n";


    GXY(27, 12);

    cout << "\t\t\t--> Yeni Oyun <--";
    GXY(30, 13);

    cout << "\t\t\t       Cxhish   ";

    cout << "\n\n\t\tGame Info:Oyun 2 neferlikdi:1 Player  1 Computer.Vuruslar Sira-Sira olur Eger Gemi Vurularsa Hemin Player Yene Atis edecek.Ilk Gemileri Bitiren Oyuncu Qabil Olacaq.UGurlar" << endl;
    cout << "\t\t\t\t-->Oyuna Bashlamaq Ucun Enter Click Edin!" << endl;
    do
    {
        k = 0;
        code = _getch();
        if (code == 224 || code == 0)
        {
            code = _getch();
        }

        if (code == 80)
        {
            f = f * (-1);
            if (f == 1)
            {
                GXY(27, 12);
                cout << "\t\t\t--> Yeni Oyun <--";
                GXY(30, 13);
                cout << "\t\t\t       Cxhish    ";
            }

            else
            {
                GXY(27, 12);
                cout << "\t\t\t    Yeni Oyun    ";
                GXY(30, 13);
                cout << "\t\t\t   --> Cxhish <--";
            }
        }
        else if (code == 72)
        {
            f = f * (-1);
            if (f == 1)
            {
                GXY(27, 12);
                cout << "\t\t\t--> Yeni Oyun <--";
                GXY(30, 13);
                cout << "\t\t\t       Cxhish   ";
            }

            else
            {
                GXY(27, 12);
                cout << "\t\t\t    Yeni oyun    ";
                GXY(30, 13);
                cout << "\t\t\t   --> Chixish <--";
            }
        }
        else if (code == 13)
        {
            k = 1;
        }
        cout << endl << endl << endl << endl << endl;
    }

    while (k == 0);
    {
        if (f != 1)
        {
            exit(0);
        }
    }
    system("cls");
    cout << endl << endl;
}

void InputScreen()
{
    system("cls");
    for (int x = 0; x < 15; x++)
    {
        for (int y = 0; y < 15; y++)
        {
            if (x == 0 || x == 15 - 1 || y == 0 || y == 15 - 1)
            {
                cout << "    \t* ";
            }
            else
            {
                cout << "    \t ";
            }
            if (x == 6)
            {
                cout << "      \t\t\t\t\t";
                char* h = new char[50]{ "Welcome My Battleship Game!" };
                for (int i = 0; i < strlen(h); i++)
                {
                    Sleep(60);
                    cout << h[i];
                }
                break;
            }
        }
        cout << endl;
    }
    Sleep(1500);
    cout << "\a";
}

void Warning()
{
    system("cls");


    cout << "\n\t\t\t\t";
    char  h[35] = "Please Wait Few Second";
    for (int i = 0; i < strlen(h); i++)
    {
        Sleep(50);
        cout << h[i];
    }
    cout << "\n\n";
    Sleep(1000);
    system("cls");
}




void tableShow()
{
    system("cls");
    cout << endl << endl << "\t\t\t\t";
    int counter = 0;
    for (int i = 0; i < SIZEf; i++)
    {
        counter++;
        cout << counter;
        cout << "\t";
    }
    cout << "\n\t\t\t\t--------------------------------------------------------------------------------------";

    counter = 0;

    cout << endl << endl << "\t\t";
    for (int i = 0; i < SIZEf; i++)
    {
        for (int j = 0; j < SIZEf; j++)
        {
            if (i >= 0 && j == 0)
            {
                counter++;
                cout << "\t" << counter << " ||";
            }
            cout << "\t" << GameTable[i][j];
        }
        cout << endl << endl << endl << "\t\t";
    }
}

void WinScreen()
{
    system("cls");
    for (int x = 0; x <= 1; x++)
    {
        if (x <= 1)
        {
            system("Color 05");
            Sleep(200);
            cout << "You Winner !" << endl;

        }






    }
}

void main()
{
    srand(unsigned(time(0)));


    system("Color 31");
    DrawWelcomeInGame();


    Sleep(5000);
    system("cls");
    GameMenu();

    system("color 41");
    InputScreen();
    system("color 79");
    Warning();
    system("color 66");
    int x, y;

    int enemyShipCounter = 0;
    while (true)
    {
        x = rand() % SIZEf;
        if (x <= 4)
        {
            y = rand() % SIZEf;
            GameTable[x][y] = 5;
            enemyShipCounter++;
            if (enemyShipCounter == 10)
            {
                break;
            }
        }
    }


    int myShipCounter = 0;
    while (true)
    {
        x = rand() % SIZEf;
        if (x >= 5)
        {
            y = rand() % SIZEf;
            GameTable[x][y] = 5;
            myShipCounter++;
            if (myShipCounter == 10)
            {
                break;
            }
        }
    }
    system("color 2");
    tableShow();

    bool MyRound = false;
    while (true)
    {
        cout << "\t\tKordinati secin: ";
        do
        {
            cin >> x;
            cin >> y;
            if (x >= 11 || x <= 0 || y <= 0)
            {

                cout << "\n\t\t\t\tGemileri Vurmaq Ucun Max 10 a kimi Daxil Etmelisiniz! , !\n\n";
                cout << "\t\t\t\t Kordinati Secin: ";
            }
        } while (x >= 11 || x <= 0 || y <= 0);
        {
            x--;
            y--;
        }

        if (GameTable[x][y] == 5)
        {
            cout << "\n\t\t\t\tComputerin Gemisini Vurdunuz!\a" << endl;
            GameTable[x][y] = 10;
            Sleep(3300);

            tableShow();

            GameTable[x][y] = 0;

            bool FindShip = false;
            for (int i = 0; i <= SIZEf; i++)
            {
                for (int j = 0; j <= SIZEf; j++)
                {
                    if (GameTable[i][j] == 5)
                    {
                        FindShip = true;
                        break;
                    }
                }
                if (FindShip == true)
                {
                    break;
                }
            }
            if (FindShip == false)
            {
                cout << "\t\tSSiz udduz Computerin butun Gemileri Partladi!" << endl;
                Sleep(4000);
                WinScreen();
                Sleep(2000);

                break;
            }
            MyRound = true;
        }
        else
        {
            cout << "\n\t\t\t\tSiz Vura Bilmediniz!" << endl;
            GameTable[x][y] = 0;
            MyRound = false;
            Sleep(3400);
            tableShow();
        }

        while (MyRound == false)
        {
            cout << "\t\tComputerin sirasi\n\n";
            x = rand() % 5 + 6;
            y = rand() % 10 + 1;
            cout << "\t\t\t\tComputer Koordinat secir " << x-- << y-- << "\n";

            if (GameTable[x][y] == 5)
            {
                cout << "\n\t\t\t\tComputer senin gemini vurdu!\a" << endl;
                GameTable[x][y] = 50;

                Sleep(5500);

                tableShow();

                GameTable[x][y] = 0;

                bool ship_detect = false;
                for (int i = 10; i < SIZEf; i++)
                {
                    for (int j = 0; j < SIZEf; j++)
                    {
                        if (GameTable[i][j] == 5)
                        {
                            ship_detect = true;
                            break;
                        }
                    }
                    if (ship_detect == true)
                    {
                        break;
                    }
                }
                if (ship_detect == false)
                {
                    cout << "\t\t\t\tComputer Uddu Senin Butun Gemilerin Partladi" << endl;
                    Sleep(5500);

                    break;
                }
            }
            else
            {
                cout << "\n\t\t\t\tComputer Vura Bilmedi!" << endl;
                MyRound = true;
                GameTable[x][y] = 0;
                Sleep(5500);
                tableShow();
            }
        }
    }

    cout << endl << endl << endl;

    system("pause");

}