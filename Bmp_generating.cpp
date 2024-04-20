#include "Image.cpp"

#include <iostream>
#include <string>

using namespace std ;

int main(){   
    system("cls");
    cout << "Parametrs :" << endl << "R:    G:    B:" << endl ;
    float r, g , b ;
    cin >> r >> g >> b ;
    system("cls");
    cout << "SEED :" << endl ;
    float seed ;
    cin >> seed ;
    system("cls");
    const int width = 640 , height = 640 ;
    Image image(width , height);
    for(int y = 0 ; y < height ; y++)
    {
        for(int x = 0 ; x < width ; x++)
        {
           image.SetColor(Color(r * seed + (y - x), (g+1) - (seed+1) + (y + x)  ,b + seed + (y - x))  , x ,y);
       
        }

    }
    image.Export("FIRST_PIC.bmp");
    Image copy(0 ,0) ;
    copy.Read("FIRST_PIC.bmp");
    cout << "copy.bmp Successfully copied " << endl << endl;
    copy.Export("copy.bmp");
    cout << "result"<< endl ;
    Image res(width , height);
      for(int y = 0 ; y < height ; y++)
    {
        for(int x = 0 ; x < width ; x++)
        {
         res.SetColor(Color(((copy.GetColor(x ,y).GetR() * image.GetColor(x ,y).GetR())+1)/(r+1),((copy.GetColor(x ,y).GetG() * image.GetColor(x ,y).GetG())+1)/(seed + 2 ) ,((copy.GetColor(x ,y).GetB() + image.GetColor(x ,y).GetB())+1)*(seed + 2 * b) ), x ,y);
       
        }
    }
    res.Export("Result.bmp");

}