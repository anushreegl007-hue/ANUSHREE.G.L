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
void drawTriangle(int row, int col, int height)
{
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<=i; j++)
        {
            if(row+i < ROWS && col+j < COLS)
            {
                canvas[row+i][col+j] = '*';
            }
        }
    }
}
void drawCircle(int centerRow, int centerCol, int radius)
{
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            int dx = i - centerRow;
            int dy = j - centerCol;

            if(dx*dx + dy*dy <= radius*radius)
            {
                canvas[i][j] = '*';
            }
        }
    }
}
void deleteArea(int row, int col, int height, int width)
{
    for(int i=row; i<row+height; i++)
    {
        for(int j=col; j<col+width; j++)
        {
            if(i < ROWS && j < COLS)
            {
                canvas[i][j] = '_';
            }
        }
    }
}
void modifyRectangle(int oldRow, int oldCol, int oldHeight, int oldWidth,
                     int newRow, int newCol, int newHeight, int newWidth)
{
    deleteArea(oldRow, oldCol, oldHeight, oldWidth);

    drawRectangle(newRow, newCol, newHeight, newWidth);
}


int main()
{
    initializeCanvas();

    drawRectangle(5, 10, 4, 8);
    drawLine(2, 5, 25);
    drawTriangle(10, 5, 5);
    drawCircle(12, 30, 3);
    
    deleteArea(6, 12, 2, 3);
    modifyRectangle(5, 10, 4, 8,
                1, 20, 3, 6);
    
    

    displayCanvas();

    return 0;
}
