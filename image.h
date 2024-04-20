#pragma once 

#include <vector>

using namespace std ;

struct Color
{
float r ,g ,b ; 
Color();
Color(float r , float g , float b);
~Color();
float GetR(){return r;}
float GetG(){return g;}
float GetB(){return b;}
};

class Image
{
public:
Image(int weight , int height);
~Image();

Color GetColor(int x , int y )const;
void SetColor(const Color& color , int x , int y);

void Read(const char * path);
void Export(const char* path)const;

private:
int m_width , m_height ; 
vector<Color> m_colors ;
};