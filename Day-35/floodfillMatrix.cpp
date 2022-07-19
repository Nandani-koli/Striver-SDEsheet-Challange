/*
Ninja has found his new passion for photography. He has clicked some really good photos but in one of his images, he doesn’t like the color of a particular region. So, he decides to change the color of that region. Can you help him with this task?
The image is represented in the form of a 2D array of size M * N. Each pixel in the image is a positive integer. Ninja has given you the coordinates (row and column) of a certain pixel and the new color value. You need to replace the color of the given pixel and all adjacent same-colored pixels with the new color.
Note:

Two pixels are adjacent if they are connected to each other in any of the four directions: up, down, left, or right.

Diagonal pixels are not considered adjacent.
*/

#include<iostream>
#include<vector>
using namespace std;

bool isvalid(vector<vector<int>> &image, int i, int j,int row,int col, int color)
{
    if(i >= 0 && i<row && j >= 0 && j < col && image[i][j] == color)
        return true;
    
    return false;
}

void floorfillrec(vector<vector<int>> &image, int i, int j,int row,int col, int color,int newcolor)
{
    image[i][j] = newcolor;
    
    if(isvalid(image,i+1,j,row,col,color))            //up
        floorfillrec(image,i+1,j,row,col,color,newcolor);
    
    if(isvalid(image,i-1,j,row,col,color))            //down
        floorfillrec(image,i-1,j,row,col,color,newcolor);
    
    if(isvalid(image,i,j+1,row,col,color))            //right
        floorfillrec(image,i,j+1,row,col,color,newcolor);
    
    if(isvalid(image,i,j-1,row,col,color))            //left
        floorfillrec(image,i,j-1,row,col,color,newcolor);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    // Write your code here.
    if(image[x][y] == newColor)
        return image;
    
    int row = image.size();
    int col = image[0].size();
    int color = image[x][y];
    
    floorfillrec(image,x,y,row,col,color,newColor);
    
    return image;
}