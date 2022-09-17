#include <stdio.h> // para função srand() e system()
#include <stdlib.h> // para função SetConsoleCursorPosition()
#include <windows.h> // para função getch() e kbhit()
#include <conio.h> // para função getch() e kbhit()
#include <time.h> // para fundão rand()

int c[300][2], score = 1, cx = 2, cy = 2;
int food[2], velo = 150;

void gotoxy(int x, int y) {
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD) {x, y});
}

void draw() {
  int i;
  for(i = 0; i < score; i++) {
    gotoxy(c[i][0], c[i][1]);
    printf("%c", 219);
  }
}

int update() {
  int i;
  gotoxy(c[score][0], c[score][1]);
  printf(" ");
  for(i = score; i >= 0; i--) {
    c[i + 1][0] = c[i][0];
    c[i + 1][1] = c[i][1];
  }
}

int toAnalize() {
  int i, retorno = 0;
  for(i = 1; i < score; i++) {
    if(cx == c[i][0] && cy == c[i][1]) {
      retorno = 1;
    }
  }
  return retorno;
}

void generateFood() {
  gotoxy(food[0], food[1]);
  printf(" ");
  srand(time(NULL));
  food[0] = (rand() % 48) +1;
  food[1] = (rand() % 18) +1;
  gotoxy(food[0], food[1]);
  printf("%c", 4);
}

int main() {
  int i, gameover = 0;
  int key;

  for(i = 0; i < 50; i++) {
    gotoxy(i, 0);
    printf("%c", 219);
    Sleep(5);
  }

  for(i = 0; i < 20; i++) {
    gotoxy(50, i);
    printf("%c", 219);
    Sleep(5);
  }

  for(i = 50; i > 0; i--) {
    gotoxy(i, 20);
    printf("%c", 219);
    Sleep(05);
  }

  for(i = 20; i > 0; i--) {
    gotoxy(0, i);
    printf("%c", 219);
    Sleep(5);
  }

  generateFood();
  draw();
  key = 'd';
  while(gameover == 0) {
    gotoxy(52, 2);
    printf("score: %d\t", score);
    gotoxy(52, 4);
    printf("Velocidade: %.2f caracteres/s", 1000/velo);
    c[0][0] = cx;
    c[0][1] = cy;
    if(kbhit())
      key = getch();

    if(key == 'w' || key == 'W' || key == 72) {
      cy--;
      if(cy == 0) break;
    }
    if(key = 'a' || key == 'A' || key == 75) {
      cx--;
      if(cx == 0) break;
    }

    if(key == 's' || key == 'S' || key == 80) {
      cy++;
      if(cy == 20) break;
    }

    if(key == 'd' || key == 'D' || key == 77) {
      cx++;
      if(cx >= 50) break;

      if(cx == food[0] && cy == food[1]) {
        score++;
        if(velo > 50) velo -= 10;
        generateFood();
      }

      gameover = toAnalize();
      update();
      draw();
      gotoxy(50, 20);
      Sleep(velo);
    }

    system("cls");
    printf("Você perdeu| Fez %d pontos. \n", score);
    system("pause");
  }
  
}








-