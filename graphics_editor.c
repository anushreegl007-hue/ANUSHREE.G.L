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
    int choice;

    initializeCanvas();

    do
    {
        printf("\n===== 2D Graphics Editor =====\n");
        printf("1. Draw Rectangle\n");
        printf("2. Draw Line\n");
        printf("3. Draw Triangle\n");
        printf("4. Draw Circle\n");
        printf("5. Delete Area\n");
        printf("6. Modify Rectangle\n");
        printf("7. Display Canvas\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                int row, col, height, width;
                printf("Enter row col height width: ");
                scanf("%d %d %d %d", &row, &col, &height, &width);
                drawRectangle(row, col, height, width);
                break;
            }

            case 2:
            {
                int row, startCol, endCol;
                printf("Enter row startCol endCol: ");
                scanf("%d %d %d", &row, &startCol, &endCol);
                drawLine(row, startCol, endCol);
                break;
            }

            case 3:
            {
                int row, col, height;
                printf("Enter row col height: ");
                scanf("%d %d %d", &row, &col, &height);
                drawTriangle(row, col, height);
                break;
            }

            case 4:
            {
                int centerRow, centerCol, radius;
                printf("Enter centerRow centerCol radius: ");
                scanf("%d %d %d", &centerRow, &centerCol, &radius);
                drawCircle(centerRow, centerCol, radius);
                break;
            }

            case 5:
            {
                int row, col, height, width;
                printf("Enter row col height width to delete: ");
                scanf("%d %d %d %d", &row, &col, &height, &width);
                deleteArea(row, col, height, width);
                break;
            }

            case 6:
            {
                int oldRow, oldCol, oldHeight, oldWidth;
                int newRow, newCol, newHeight, newWidth;

                printf("Enter old row col height width: ");
                scanf("%d %d %d %d",
                      &oldRow, &oldCol,
                      &oldHeight, &oldWidth);

                printf("Enter new row col height width: ");
                scanf("%d %d %d %d",
                      &newRow, &newCol,
                      &newHeight, &newWidth);

                modifyRectangle(oldRow, oldCol, oldHeight, oldWidth,
                                newRow, newCol, newHeight, newWidth);
                break;
            }

            case 7:
                displayCanvas();
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 0);

    return 0;
}


