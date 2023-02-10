/*******************************************************************************************
* Ten:             	Nhom 6                                                                 *
* Bai toan:      	Thuat toan ngau nhien tao ra mot me lo  (Maze)						   *
* Cau truc du lieu: Mang 2 chieu (double array), stack (ngan xep)						   *
* Giai thuat:       Tim kiem ngau nhien theo chieu sau (Randomized depth-first search) 	   *
*******************************************************************************************/
#include <iostream>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <stack>
#include <fstream>
using namespace std;
#define SIZE 11 //Kich thuoc me lo
// Cau truc o
struct Cell
{
	bool visited; 		// O toi (O duoc truy cap)
	bool top_wall;		// Tuong tren
	bool bot_wall;		// Tuong duoi
	bool left_wall;		// Tuong trai
	bool right_wall;	// Tuong phai
	char display;		// Hien thi
};
// Cac function
void Initialize(Cell Maze[][SIZE]); // Khoi tao me lo
void ClearScreen(); // Xoa man hinh
void Draw(Cell Maze[][SIZE]); // Ve me lo
void GenerateMaze(Cell Maze[][SIZE]); // Tao me lo
void SaveMaze(Cell Maze[][SIZE]); // Luu me lo
// Chuong trinh chinh
int main()
{
	Cell Maze[SIZE][SIZE];
	bool end_game = false;
	while(!end_game)
	{
		system("cls"); // Xoa man hinh
		Initialize(Maze); // Khoi tao
		Draw(Maze); // Ve
		GenerateMaze(Maze); // Tao me lo
		SaveMaze(Maze); // Luu me lo
		char input;
		cout << "Create a new Maze? (Y)/(N): ";
		cin >> input;
		if((input != 'n') && (input != 'N') && (input != 'y') && (input != 'Y'))
			cout << "Invalid option" << endl;
		else if((input == 'n') || (input == 'N'))
		{
			end_game = true;
			cout << "Good bye!" << endl;
		}
	}
	getch();
	return 0;
}
// Khoi tao me lo
void Initialize(Cell Maze[SIZE][SIZE])
{
	for(int i=0; i<SIZE; i++)
	{
		for(int j=0; j<SIZE; j++)
		{
			Maze[i][j].display = '*';
			Maze[i][j].visited = false;
			Maze[i][j].top_wall = true;
			Maze[i][j].bot_wall = true;
			Maze[i][j].left_wall = true;
			Maze[i][j].right_wall = true;
		}
	}
	for(int i=1; i<SIZE-1; i++)
	{
		for(int j=1; j<SIZE-1; j++)
		{
			// Cac cell o bien
			Maze[1][j].top_wall = false;
			Maze[SIZE-2][j].bot_wall = false;
			Maze[i][1].left_wall = false;
			Maze[i][SIZE-2].right_wall = false;
		}
	}
}
// Xoa man hinh
void ClearScreen()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
// Ve lai me lo
void Draw(Cell Maze[][SIZE])
{
	for(int i=0; i<SIZE; i++)
	{
		cout << endl;
		for(int j=0; j< SIZE; j++)
			cout << " " << Maze[i][j].display;
	}
}
// Tao me lo
void GenerateMaze(Cell Maze[][SIZE])
{
	srand((unsigned)time(NULL));				        					// Chon o ngau nhien de bat dau
	int randomX = ((2*rand())+1)%(SIZE-1);						    // Tao so le ngau nhien trong doan tu 1 den SIZE
	int randomY = ((2*rand())+1)%(SIZE-1);                          // Tao so le ngau nhien trong doan tu 1 den SIZE
	int posX = randomX;                       						// Luu vi tri khoi tao X
	int posY = randomY;                      						// Luu vi tri khoi tao Y
	int visitedCells = 1;
	int percent = 0;
	stack<int> back_trackX, back_trackY; 						// Ngan xep duoc su dung de truy vet duong di nguoc lai (quay lui)
	back_trackX.push(randomX); 			// Day X vao ngan xep
    back_trackY.push(randomY);			// Day Y vao ngan xep
	Maze[randomY][randomX].display = 'S';						// Dat S la o bat dau
	Maze[randomY][randomX].visited = true;						// Dat o bat dau la o duoc truy cap
	while(!back_trackX.empty())
	{
		if((Maze[randomY-2][randomX].visited == false && Maze[randomY][randomX].top_wall == true && Maze[randomY-2][randomX].bot_wall == true) ||
		   (Maze[randomY+2][randomX].visited == false && Maze[randomY][randomX].bot_wall == true && Maze[randomY+2][randomX].top_wall == true) ||
		   (Maze[randomY][randomX-2].visited == false && Maze[randomY][randomX].left_wall == true && Maze[randomY][randomX-2].right_wall == true) ||
		   (Maze[randomY][randomX+2].visited == false && Maze[randomY][randomX].right_wall == true && Maze[randomY][randomX+2].left_wall == true))
		{
			int random = rand() % 4 + 1;		// Chon ngau nhien tuong tu 1 den 4 de pha
			 // DI LEN
			if((random == 1) && (randomY > 1))
			{
				if(Maze[randomY-2][randomX].visited == false)  // Neu chua duoc truy cap
				{
					Maze[randomY-1][randomX].display = ' ';	// Xoa hien thi
					Maze[randomY-1][randomX].visited = true;	// Danh dau o duoc truy cap
					Maze[randomY][randomX].top_wall = false;	// Pha tuong

					back_trackX.push(randomX); 			// Day X vao ngan xep
					back_trackY.push(randomY);			// Day Y vao ngan xep
					randomY -= 2;								// Dich den o tiep theo
					Maze[randomY][randomX].visited = true;		// Danh dau o dich den la o duoc truy cap
					Maze[randomY][randomX].display = ' ';		// Cap nhat duong di
					Maze[randomY][randomX].bot_wall = false;	// Pha tuong
				}
				else
					continue;
			}
			// DI XUONG
			else if((random == 2) && (randomY < SIZE-2))
			{
				if(Maze[randomY+2][randomX].visited == false)  // Neu chua duoc truy cap
				{
					Maze[randomY+1][randomX].display = ' ';	// Xoa hien thi
					Maze[randomY+1][randomX].visited = true;	// Danh dau o duoc truy cap
					Maze[randomY][randomX].bot_wall = false;	// Pha tuong

					back_trackX.push(randomX); 			// Day X vao ngan xep
					back_trackY.push(randomY);			// Day Y vao ngan xep

					randomY += 2;								// Dich den o tiep theo
					Maze[randomY][randomX].visited = true;		// Danh dau o dich den la o duoc truy cap
					Maze[randomY][randomX].display = ' ';		// Cap nhat duong di
					Maze[randomY][randomX].top_wall = false;	// Pha tuong
				}
				else
					continue;
			}
			// SANG TRAI
			else if((random == 3) && (randomX > 1))
			{
				if(Maze[randomY][randomX-2].visited == false) // Neu chua duoc truy cap
				{
					Maze[randomY][randomX-1].display = ' ';	// Xoa hien thi
					Maze[randomY][randomX-1].visited = true;	// Danh dau o duoc truy cap
					Maze[randomY][randomX].left_wall = false;	// Pha tuong

					back_trackX.push(randomX); 			// Day X vao ngan xep
					back_trackY.push(randomY);			// Day Y vao ngan xep

					randomX -= 2;								// Dich den o tiep theo
					Maze[randomY][randomX].visited = true;		// Danh dau o dich den la o duoc truy cap
					Maze[randomY][randomX].display = ' ';		// Cap nhat duong di
					Maze[randomY][randomX].right_wall = false;	// Pha tuong

				}
				else
					continue;
			}
			// SANG PHAI
			else if((random == 4) && (randomX < SIZE-2))
			{
				if(Maze[randomY][randomX+2].visited == false) // Neu chua duoc truy cap
				{
					Maze[randomY][randomX+1].display = ' ';	// Xoa hien thi
					Maze[randomY][randomX+1].visited = true;	// Danh dau o duoc truy cap
					Maze[randomY][randomX].right_wall = false;	// Pha tuong

					back_trackX.push(randomX); 			// Day X vao ngan xep
					back_trackY.push(randomY);			// Day Y vao ngan xep

					randomX += 2;								// Dich den o tiep theo
					Maze[randomY][randomX].visited = true;		// Danh dau o dich den la o duoc truy cap
					Maze[randomY][randomX].display = ' ';		// Cap nhat duong di
					Maze[randomY][randomX].left_wall = false;	// Pha tuong

				}
				else
					continue;
			}
		}
		else
		{
			randomX = back_trackX.top();
			back_trackX.pop();

			randomY = back_trackY.top();
			back_trackY.pop();
		}
		ClearScreen();
		Draw(Maze);
	}
	system("cls");
	ClearScreen();
	Draw(Maze);
	cout << endl << "\a\t	Complete!" << endl;
}
// Luu me lo
void SaveMaze(Cell Maze[][SIZE])
{
	fstream output;
	char input;
	cout << endl << "Save Maze? (Y)/(N): ";
	cin >> input;
	if ((input == 'y') || (input == 'Y'))
	{
		output.open("Maze.txt");
		for (int i = 0; i < SIZE; i++)
		{
			output << endl;
			for (int j = 0; j < SIZE; j++)
			{
				output << Maze[i][j].display << " ";
			}
		}
		cout << "Maze has been saved to Maze.txt" <<endl;
		output.close();
	}
}
