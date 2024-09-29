/*
Name: Hasindu
Student ID: 104824660
*/

#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;


enum genre {Pop, Rock, Rap};

//structure defnitions
struct album
{
    string name_album;
    genre type;
    int song_amount;
    string song_name[5];
    string file_location;
};




//function prototypes
enum genre read_genre();
struct album read_songs();
void add_album();
void print_all_album(struct album tempAlbum);
void select_track_to_play(struct album tempAlbum);

vector <struct album> album_details;


int main()
{
    int user_choice_album; //variable when user chooses album

    do
    {
        cout<<endl;

        cout<<"1. Add new album"<<endl;
        cout<<"2. Print all the existing albums "<<endl;
        cout<<"3. Select track to play"<<endl;
        cout<<"4. Quit"<<endl;
        
        int user_input;
        cout<<"Enter your choice: ";
        cin>>user_input;
        fflush(stdin);
        

    switch(user_input)
    {
        case 1:
            cout<<endl;
            add_album();
            break;

        case 2:

            for(int i = 0; i < album_details.size(); i++)
            {
                cout<<endl;
                print_all_album(album_details[i]);
                cout<<endl;
            }
            
            break;

        case 3:
            cout<<endl;
            cout << "Choose an album: "<< endl;

            for (int i = 0; i < album_details.size(); i++)
            {
                cout<< i + 1 <<" -> ";
                cout<< album_details[i].name_album << endl;
            }

            cout << "Enter the number of the album : ";
            cin >> user_choice_album;
            cin.ignore(); // clears the buffer
            cout<<endl;

            if (user_choice_album >= 1 && user_choice_album <= album_details.size())
            {

                select_track_to_play(album_details[user_choice_album - 1]);
                //album_details.[user_choice_album - 1];

            }
            else
            {
                cout << "Invalid choice." << endl;
            }

            break;

        case 4:
            exit(0);
    }

    }while(true);

    return 0;
}

//function definitions 
enum genre read_genre()
{
    int user_choice;

    do
    {
    cout<<"Enter the genre: "<<endl;
    cout<<"0 - Pop "<<endl<<"1 - Rock"<<endl<<"2 - Rap"<<endl;
 
    cin>>user_choice;

    if(user_choice < 0 && user_choice > 2)
    {
        cout<<"Invalid Input. Please enter in the range 0 - 2."<<endl;
    }

    }while(user_choice < 0 && user_choice > 2);

    enum genre type = static_cast<genre>(user_choice);
    return type;
}

struct album read_songs()
{
    struct album UserInput;
    cout<<"Enter name of the album: ";
    getline(cin, UserInput.name_album);
    
    
    UserInput.type = read_genre();
    cout<<endl;

    cout<<"Enter number of the songs (maximum 5): ";
    do{
    cin>>UserInput.song_amount;
    fflush(stdin);

    if(UserInput.song_amount > 5)
    {
        cout<<"Maximum number of songs allowed is 5"<<endl;
    }

    } while(UserInput.song_amount > 5);

    int size = UserInput.song_amount;

    cout<<endl;
    cout<<"Enter songs to the album "<<endl;

    for(int i = 0; i < size; i++)
    {
        cout<<"Enter song name (position "<<i + 1<< " ): ";
        getline(cin, UserInput.song_name[i]);   
        fflush(stdin);    
    }

    cout<<endl;
    cout<<"Enter file location of the songs: "<<endl;
    getline(cin, UserInput.file_location);

    return UserInput;
}

void add_album()
{
    struct album tempAlbum = read_songs();

    album_details.push_back(tempAlbum);
}

void print_all_album(struct album tempAlbum)
{
    const char* genreArray[] = {"Pop", "Rock", "Rap"};

    cout<<"Album Name: "<<tempAlbum.name_album<<endl;
    cout<<"Genre: "<< genreArray[tempAlbum.type] <<endl;
    cout<<"There are "<<tempAlbum.song_amount<<" songs in the album"<<endl<<endl;
    
    cout<<"Playlist: "<<endl;
    for(int i = 0; i < tempAlbum.song_amount; i++)
    {
        cout<< i + 1 <<". ";
        cout<<tempAlbum.song_name[i]<<endl;
        
    }
    cout<<endl;

    cout<<"Location: "<< tempAlbum.file_location <<endl;

}

void select_track_to_play(struct album tempAlbum)
{
    cout<<endl;
    cout << "Select a track to play from " << tempAlbum.name_album << ":" << endl;

    for (int i = 0; i < tempAlbum.song_amount; i++)
    {
        cout<< i + 1 <<". ";
        cout<< tempAlbum.song_name[i] << endl;
    }
    cout<<endl;

    int user_choice_song;
    cout << "Enter the track number of the song to play: ";
    cin >> user_choice_song;
    cin.ignore(); // clears the buffer
    cout<<endl;

    if (user_choice_song >= 1 && user_choice_song <= tempAlbum.song_amount)
    {

        cout<<"The track you selected "<<tempAlbum.song_name[user_choice_song - 1] << " from the album; "<< tempAlbum.name_album<< " is now playing from file location; "<< tempAlbum.file_location<<endl;
        cout<<endl<<endl;

        // Play functionality here

        //below code generates the file path using the file location of the songs and the song name
        string song_file_location =  "C:\\Users\\hasin\\Music\\" +  tempAlbum.file_location + "\\" + tempAlbum.song_name[user_choice_song - 1] + ".mp3"; 

        const char* file_path = song_file_location.c_str(); //converts the file path from string to const char*

        
        ShellExecute(NULL, "open", file_path, NULL, NULL, SW_SHOWMAXIMIZED); //opens music player to play song

    }
    else
    {
        cout << "Invalid track number." << endl;
    }
}