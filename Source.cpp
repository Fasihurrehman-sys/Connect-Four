#include<iostream>
#include<string>
using namespace std;
int position;
int position2 = 0;
int charPosition = 0;
bool gameEnd = false;
void display();
bool check(int a, int b);
int drop(int b, char player);
void start();
int mainMenu();
int mode;
void header();
void space();
string playerName[2];
string input;
char place[6][7];
void instructions();
int main()
{
    mainMenu();
    start();
    system("pause");
    return 0;
}
void space()
{
    for (int a = 0; a <= 5; a++) {

        for (int b = 0; b <= 6; b++)

            place[a][b] = ' ';

    }
}
void display() {

    cout << " 1   2   3   4   5   6   7\n";

    for (int a = 0; a <= 5; a++)

    {

        for (int b = 0; b <= 6; b++)
            cout << char(218) << char(196) << char(191) << " ";

        cout << '\n';

        for (int b = 0; b <= 6; b++) cout << char(179) << place[a][b] << char(179) << " ";

        cout << '\n';

        for (int b = 0; b <= 6; b++) cout << char(192) << char(196) << char(217) << " ";

        cout << '\n';

    }

}

bool check(int a, int b) {

    int vertical = 1;//(|)

    int horizontal = 1;//(-)


    char player = place[a][b];

    int i;//vertical

    int j;//horizontal

    //check for vertical(|)

    for (i = a + 1; place[i][b] == player && i <= 5; i++, vertical++);//Check down

    for (i = a - 1; place[i][b] == player && i >= 0; i--, vertical++);//Check up

    if (vertical >= 4)return true;

    //check for horizontal(-)

    for (j = b - 1; place[a][j] == player && j >= 0; j--, horizontal++);//Check left

    for (j = b + 1; place[a][j] == player && j <= 6; j++, horizontal++);//Check right

    if (horizontal >= 4)

        return true;

    else

        return false;

}
int drop(int b, char player) {

    if (b >= 0 && b <= 6)

    {

        if (place[0][b] == ' ')
        {

            int i;

            for (i = 0; place[i][b] == ' '; i++)

                if (i == 5) {
                    place[i][b] = player;
                    return i;
                }

            i--;

            place[i][b] = player;

            return i;

        }

        else {

            return -1;

        }

    }

    else {

        return -1;

    }

}
void header() {
    cout << " ============================================ " << endl;
    cout << "|         /|   ___              _____          |" << endl;;
    cout << "|        / |  |   -      --       |            |" << endl;
    cout << "|       /  |  |     -  -    -     |            |" << endl;
    cout << "|      /   |  |     -  -    -     |            |" << endl;
    cout << "|     /____|_ |___ -      -       |            |" << endl;
    cout << "|          |                                   |" << endl;
    cout << " ================ v1.0.0 =====================" << endl;
    cout << endl << endl;
    return;
}
void getName() {

    system("CLS");
    header();

    for (int i = 0; i < 2; i++) {
        cout << "ENTER PLAYER " << i + 1 << " NAME = ";
        cin >> playerName[i];
    }
    return;
}
void instructions() {

    system("CLS");
    header();

    cout << "We have and 1,2,3,4,5,6,7 for Columns." << endl;
    cout << "Use Must Select Column To Enter A Dot." << endl;
    cout << "Error You Cannot Select Colum Less Than 0 and Greater Than 7." << endl << endl;

    system("pause>0");
    system("CLS");
    mainMenu();

    return;
}
void start() {

    getName();
    space();
    display();//Displays for first time so players can see the board

    int turn = 1;;//start as player 2 will change back 2 player 1
    char player = '15';
    while (!gameEnd) {//will stop when game is won, ! means NOT makes the oppisite be checked
//check if there was a error in the last drop

        if (turn % 2 != 0) {//if player 2 lasted dropped a piece so its player 1s turn

            cout << "player 1 drop where=?";

            player = '254';//char of players piece
            turn++;
        }

        else {

            cout << "player 2 drop where=?";

            player = '15';//char of player piece
            turn++;
        }



        while (true) {//will run untill 'break;'

            if (charPosition == 42) break;//if draw

            cin >> position;//get user input

            position--;//take off 1 to account for arrays starting at 0 not 1

            if (position <= 6 && position >= 0) break;//if within valid range stop loop

            else cout << "\nplease enter a value between 1 and 7 :";//ask for input and loop again

            if (cin.fail()) //catch a non number

            {

                cin.clear();        //Stops cin trying to put its value in to hold

                char c;         //Try entering a non number without this

                cin >> c;

            }

        }

        if (charPosition == 42) break;//if draw

        position2 = drop(position, player);//drop the player store the row in hold2

        if (position2 == -1) cout << "Colom is full\nPlease enter anothor number between 1 and 7:";//if error -1 row is full

        else {

            gameEnd = check(position2, position);//check if game is run

            charPosition++;//another character has been succesfully placed

            system("cls");//This clears the screen works with windows, not nesscery to run game

            display();//displayed updated board

        }

    }

    system("cls");//this clears the screen

    if (charPosition == 42) {//if draw

        cout << "No winner, Game was draw\n";
        mainMenu();
        system("pause");

        return;

    }

    if (turn % 2 == 0)//if won by player  1

        cout << "gamewon by : player 1\n";

    else
        cout << "gamewon by : player 2\n";//Else won by player 2


    system("pause");
    mainMenu();
}
int mainMenu() {

    system("CLS");
    int option;

    header();

    cout << "\t" << "[1] PLAY GAME" << endl;
    cout << "\t" << "[2] HOW TO PLAY?" << endl;
    cout << "\t" << "[3] QUIT" << endl << endl;

    cout << "\t" << "ENTER OPTION = ";
    cin >> option;

    switch (option) {

    case 1:
        mode = 1;
        start();
        break;
    case 2:
        instructions();
        break;
    case 3:
        return 0;
    default:
        mainMenu();
    }
}