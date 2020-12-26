#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define N 20
#define M 40
int i,j,Field[N][M],x,y,Gy,Head,Tail,Game,Frog,a,b;

void snakeInitialization () {
    for (i=0;i<N;i++) {
        for(j=0;j<M;j++) {
            Field[i][j] = 0;
        }
    }

    x=N/2;
    y=M/2;
    Head=5;
    Tail=1;
    Gy=y;
    Game=0;
    Frog=0;

    for(i=0; i<Head; i++) {
        Gy++;
        Field[x][Gy-Head] = i+1;
    }


}

void print() {
    for(i=0; i<=M+1;i++) {
        if (i==0) {
            printf("%c", 201);
        } else if (i==M+1) {
            printf("%c", 187);
        } else {
        printf("%c", 205);
        }
    }

    printf("\n");

    for(i=0; i<N; i++) {
        printf("%c", 186);

        for(j=0; j<M; j++) {
            if(Field[i][j] == 0) printf(" ");
            if(Field[i][j] > 0 && Field[i][j]!= Head) printf("%c", 176);
            if(Field[i][j] == Head) printf("%c", 178);
            if(Field[i][j] == -1) printf("%c", 15);
            if(j==M-1) printf("%c\n", 186);
            }
        }


    for(i=0; i<=M+1;i++) {
        if(i==0) {
            printf("%c", 200);
        } else if ( i==M+1 ) {
            printf("%c", 188);
        } else {
            printf("%c", 205);
        }
    }
}

void ResetScreenPosition() {
    HANDLE hOut;
    COORD Position;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut, Position);
}

Random() {
    srand(time(0));
    a = 1+ rand() % 18;
    b = 1+ rand() % 38;

    if (Frog == 0 && Field[a][b]==0) {
        Field[a][b] = -1;
        Frog = 1;
    }
}

void main()
{
    snakeInitialization();
    while(Game==0) {
        print();
        ResetScreenPosition();
        Random();
    }
}
