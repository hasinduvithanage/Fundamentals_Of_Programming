/*
Name: Hasindu
Student ID: 104824660
*/

#include <iostream>
#include <string>
using namespace std;


//function prototypes
void swap(int *i, int *j);
void extra_protection_swap(int arr[], int size);
void decode(int arr[], int size, string user_input);


int main()
{
    int SIZE = 0;
    int counter = 0;
    int x;
    int x_copy;
    string extra_prot; //input from user regarding extra protectiong for 8 digits    

    cout<<endl;
    do
    {
    
        cout<<"Enter an integer: ";
        cin>>x;

        x_copy = x;

        do
        {
            x_copy = x_copy/10; //finds the number of digits
            counter++;

        }while(x_copy>0);
        
        SIZE = counter; //SIZE of array is determined

        if(SIZE < 2 || SIZE > 8)
        {
            cout<<"You have entered an invalid code!"<<endl<<endl;
            counter = 0;
        }

    }while(SIZE < 2 || SIZE > 8);

    int integer[SIZE]; //declaring ARRAY
    
    cout << endl;
    cout<<"Integer contains "<<SIZE<<" digits. "<<endl;

    //ARRAY - data entering to the array
    x_copy = x;
    for(int i = (SIZE - 1); i>=0; i--)
    {
        integer[i] = x_copy % 10; //gets the last digit of the integer
        x_copy = x_copy / 10; //gets rid of the last integer
    }



    if(SIZE == 2)
    {
        swap(&integer[0], &integer[1]);
    }

    if(SIZE == 3)
    {
        swap(&integer[0], &integer[2]);
    }

    if(SIZE >= 4)
    {
        for(int i = 0; i<SIZE; i++)
        {

        int cal = (integer[SIZE - (i + 1)] + (i + 1)) % 10; //starting from the rightmost digit, add integer, nth position number, divide by 10 and get the remainder
        integer[SIZE - (i + 1)] = cal; //the remainder gotten above should replace the value of the array
        
        }
    }

    if(SIZE == 8)
    {
        cout<<endl;
        cout<<"Do you want to do second level of encryption? Enter Yes or No."<<endl;
        //cout<<"If no extra protection needed; Enter -1."<<endl;

        int valid;//a variable to make sure to keep running the loop if the user enters an invalid input
        do
        {
            valid = 0; 
            cin>>extra_prot;

            if(extra_prot == "yes" || extra_prot == "Yes" || extra_prot == "YES")
            {
                extra_protection_swap(integer, SIZE); //reverses the order
            }
            else if(extra_prot == "no" || extra_prot == "No" || extra_prot == "NO")
            {
                break;
            }
            else
            {
                valid = 1; //makes sure the loop is running if invalid input entered
                cout << "Invalid input. Please enter 'Yes' or 'No'." << endl;
            }

        }while(valid == 1);
    }
    
    cout << endl;

    //display output
    cout<<"The encoded number is ";
    for (int i = 0; i < SIZE; i++)
    {
        cout << integer[i] << "";
    }
    cout <<endl<<endl;

    //DECODING
    decode(integer, SIZE, extra_prot);

    cout<<"The decoded number is ";
    for (int i = 0; i < SIZE; i++)
    {
        cout << integer[i] << "";
    }
    cout << endl;

    return 0;
}


//function definitons

void swap(int *i, int *j) //swaps positions indicated by i and j
{
    int temp;
    temp = *i;
    *i = *j;
    *j = temp;
}

void extra_protection_swap(int arr[], int size)
{
    for(int i = 0; i<(size/2); i++)
    {
        int temp;
        temp = arr[i]; //gets the leftmost unused data value of the array
        arr[i] = arr[(size - (i + 1))]; //gets the rightmost unused data value of the array
        arr[(size - (i + 1))] = temp;
    }
}

void decode(int arr[], int size, string user_input)
{
    if(size == 2)
    {
        swap(&arr[0], &arr[1]); //simple swap
    }

    if(size == 3)
    {
        swap(&arr[0], &arr[2]); //simple swap
    }

    if(size >= 4)
    {
        if(size == 8)
        {

    if((user_input == "yes" || user_input == "Yes" || user_input == "YES"))
    {
        extra_protection_swap(arr, size); //reverses additional protection

        for(int i = 0; i<size; i++)
        {
            if(arr[size - (i + 1)] > i)
            {
                arr[size - (i + 1)] = arr[size - (i + 1)] - (i + 1);
            }
            else
            {
                arr[size - (i + 1)] = arr[size - (i + 1)] + (9 - i);
            }
        }

    }

    else if((user_input == "no" || user_input == "No" || user_input == "NO"))
    {
        for(int i = 0; i<size; i++)
        {
            if(arr[size - (i + 1)] > i)
            {
                arr[size - (i + 1)] = arr[size - (i + 1)] - (i + 1);
            }
            else
            {
                arr[size - (i + 1)] = arr[size - (i + 1)] + (9 - i);
            }
        }
    }


        }
        else //for integers >=4 and <8
        {
            for(int i = 0; i<size; i++)
            {
                if(arr[size - (i + 1)] > i)
                {
                    arr[size - (i + 1)] = arr[size - (i + 1)] - (i + 1); 
                }
                else
                {
                    arr[size - (i + 1)] = arr[size - (i + 1)] + (9 - i);
                }
            }
        }

    }

}

/*
decoding logic of the first 3 digits starting from the rightmost:

d1 -> 1st digit

if(d1 > 0)
{
    d1 = d1 - 1;
}
else
{
    d1 = d1 + 9;
}

d2 -> 2nd digit

if(d2 > 1)
{
    d2 = d2 - 2;
}
else
{
    d2 = d2 + 8;
}

d3 -> 3rd digit

if(d3 > 2)
{
    d3 = d3 - 3;
}
else
{
    d3 = d3 + 7;
}

etc....................

As there is a pattern, we can use a loop to simplify this; 
this is what i have done in the decode function


*/