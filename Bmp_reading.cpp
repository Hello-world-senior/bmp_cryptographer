#include "Image.cpp"

#include <iostream>
#include <string>

using namespace std ;

int main(){   
    system("cls");
    const int width = 640 , height = 640 ;
    Image res(width , height);
    res.Read("Image.bmp");

      for(int y = 0 ; y < height ; y++)
    {
        for(int x = 0 ; x < width ; x++)
        {
           res.SetColor(Color(res.GetColor(x ,y).GetR()+x ,  res.GetColor(x ,y).GetG()+x , res.GetColor(x ,y).GetB()+x)  , x ,y); 
        }
    }
    res.Export("Result.bmp");

}