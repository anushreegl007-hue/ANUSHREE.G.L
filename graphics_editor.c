#include <stdio.h>

#define ROWS 20
#define COLS 40

char canvas[ROWS][COLS];

void initializeCanvas()
{
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            canvas[i][j] = '_';
        }
    }
}

void displayCanvas()
{
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}

void drawRectangle(int row, int col, int height, int width)
{
    for(int i=row; i<row+height; i++)
    {
        for(int j=col; j<col+width; j++)
        {
            if(i<ROWS && j<COLS)
            {
                canvas[i][j] = '*';
            }
        }
    }
}

void drawLine(int row, int startCol, int endCol)
{
    for(int i=startCol; i<=endCol; i++)
    {
        if(row<ROWS && i<COLS)
        {
            canvas[row][i] = '*';
        }
    }
}

int main()
{
    initializeCanvas();

    drawRectangle(5, 10, 4, 8);
    drawLine(2, 5, 25);

    displayCanvas();

    return 0;
}
