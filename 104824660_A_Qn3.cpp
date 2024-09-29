/*
Name: Hasindu
Student ID: 104824660
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "splashkit.h"
#define SIZE 800

struct sample
{
    int value;
    color clr;
};

//function prototypes
color get_color(int num);
void fill_array(struct sample array[]);
void draw_bar(struct sample array[]);
void sort1(struct sample array[], int size);
void sort2(struct sample array[], int size);


int main()
{
    struct sample data[SIZE];

    open_window("Array Rectangles", 800, 700);

    srand(time(NULL)); //seed to get random values
    clear_screen(COLOR_WHITE);
    fill_array(data);

    while(!quit_requested())
    {

        process_events();
        
        

        fill_rectangle(COLOR_DARK_GREEN, 0, 0, 100, 50);
        draw_text("Draw Bars", COLOR_WHITE, 5, 15);

        fill_rectangle(COLOR_RED, 0, 60, screen_width(), 10); //horizontal bar
        

        if(mouse_clicked(LEFT_BUTTON) && mouse_x() >= 0 && mouse_x() <= 100 && mouse_y() >= 0 && mouse_y() <= 50) //draw button
        {
            clear_screen(COLOR_WHITE);
            fill_array(data);
            draw_bar(data);
        }

        fill_rectangle(COLOR_DARK_GREEN, 400, 0, 100, 50);
        draw_text("Sort 1", COLOR_WHITE, 405, 15);

        if(mouse_clicked(LEFT_BUTTON) && mouse_x() >= 400 && mouse_x() <= 500 && mouse_y() >= 0 && mouse_y() <= 50) //sort 1 button
        {
            clear_screen(COLOR_WHITE);
            sort1(data, SIZE);
            draw_bar(data);
        }

        fill_rectangle(COLOR_DARK_GREEN, 550, 0, 100, 50);
        draw_text("Sort 2", COLOR_WHITE, 555, 15);

        if(mouse_clicked(LEFT_BUTTON) && mouse_x() >= 550 && mouse_x() <= 650 && mouse_y() >= 0 && mouse_y() <= 50)
        {
            clear_screen(COLOR_WHITE);
            sort2(data, SIZE);
            draw_bar(data);
        }
        


        refresh_screen(60);

    }
    return 0;
}

//function definitions are below

color get_color(int num)
{
    color clr;
    float hue;

    float numFloat = static_cast<float>(num);
    float screenHeight = static_cast<float>(screen_height());

    hue = numFloat/screenHeight;

    clr = hsb_color(hue, 0.7, 0.8);

    return clr;
}

void fill_array(struct sample array[])
{


    for(int i = 0; i < 800; i++)
    {
        array[i].value = rand() % (screen_height() - 100); 
        //gets random values assigned to the array from the range 0 to 599
        
        array[i].clr = get_color(array[i].value);
    }
}

void draw_bar(struct sample array[])
{
    float x, y, rect_width;
    rect_width = 1;

    for(int i = 0; i < 800; i++)
    {
        x = rect_width * i;
        y = screen_height() - array[i].value; //defines the starting coordinate y by subtracting the screen height with the array value

        fill_rectangle(array[i].clr, x, y, rect_width, array[i].value);

    }
}

//the first sort method i have used is Bubble sort
void sort1(struct sample array[], int size)
{
    int i, j, temp;
    for (i = 0; i < (size - 1); i++)
    {
        for (j = 0; j < size - 1 - i; j++)
        {
            if (array[j].value > array[j+1].value)
            {
                temp = array[j+1].value;
                array[j+1].value = array[j].value;
                array[j].value = temp;
            }
        }
    }
}

//the second sort method i have used is Selection sort
void sort2(struct sample array[], int size)
{

int i;
int j;
int min; //position (index) of the smallest value
int temp;

for(i=0;i<size-1;i++)
{

    min=i;

    for (j=i+1; j < size; j++)
    {
        if (array[j].value < array[min].value) //checks if the leftmost value of the array is the smallest and if not brings the smallest value to the front (left)
        {
            min = j;
        }        
    }

    temp=array[i].value; //swaps the 2 values
    array[i].value =array[min].value;
    array[min].value =temp;

}

}