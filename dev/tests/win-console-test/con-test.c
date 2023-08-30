#include<windows.h>
#include<stdio.h>

struct {
    union{
        struct {
            short up;
            short down;
            short left;
            short right;
        } D;
        DWORD inp;
    } data;
    #define up_ data.D.up
    #define down_ data.D.down
    #define left_ data.D.left
    #define right_ data.D.right
} keyData;

short loadKeys(){
    // Windows tracks toggles for every key no matter what
    keyData.up_ = 0xFF00 & GetKeyState('W');
    keyData.down_ = 0xFF00 & GetKeyState('S');
    keyData.left_ = 0xFF00 & GetKeyState('A');
    keyData.right_ = 0xFF00 & GetKeyState('D');
    //printf("%hd %hd %hd %hd : %hd\n", keyData.up_, keyData.down_, keyData.left_, keyData.right_, GetKeyState(VK_ESCAPE));
    return !(0xFF00 & GetKeyState(VK_ESCAPE));
}

void main() {
    HANDLE con;

    con = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleMode(con, &keyData.data.inp);
    SetConsoleMode(con, keyData.data.inp | ENABLE_VIRTUAL_TERMINAL_PROCESSING);

    while(loadKeys()){

    }
}