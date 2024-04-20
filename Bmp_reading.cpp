#include "Image.cpp"

using namespace std ;

int main()
{
    const int width = 640 , height = 640 ;
    float r  = 255,g = 0 ,b =0 ;
    Image image(width , height);
    float color = 20.0 ;
    for(int y = 0 ; y < height ; y++)
    {
        for(int x = 0 ; x < width ; x++)
        {
           image.SetColor(Color(255,255 ,rand()) , x ,y);
       
        }

    }

    image.Export("Export.bmp");

    Image copy(0 ,0) ;

    copy.Read("Export.bmp");

    copy.Export("copy.bmp");

    Image res(width , height);
      for(int y = 0 ; y < height ; y++)
    {
        for(int x = 0 ; x < width ; x++)
        {
           res.SetColor(Color(copy.GetColor(x ,y).GetR() * image.GetColor(x ,y).GetR(),copy.GetColor(x ,y).GetG() * image.GetColor(x ,y).GetG() ,copy.GetColor(x ,y).GetB() * image.GetColor(x ,y).GetB()) , x ,y);
       
        }

    }
    res.Export("res.bmp");

}