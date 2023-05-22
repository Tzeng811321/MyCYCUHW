#include <iostream>
#include <raylib.h>

using namespace std;

class Ball{
public:
    float x, y;
    int speed_x, speed_y;
    int radius, Score_player1, Score_player2;

    void Draw(){
        DrawCircle(x,y,radius, WHITE);
    }

    void Update(){
        x=x+speed_x;
        y=y+speed_y;
        // if(x + radius >= GetScreenWidth() || x - radius <= 0){
        //     speed_x *= -1;
        // }
        if(y + radius >= GetScreenHeight()  || y - radius <= 0){
            speed_y *= -1;
        }
        if (x+radius >= GetScreenWidth())
        {
            Score_player1 += 10;
            Reset();
        }
        if (x - radius <= 0)
        {
            Score_player2 += 10;
            Reset();
        }
        
        
    }

    void Reset(){
        x = GetScreenWidth()/2;
        y = GetScreenHeight()/2;

        int speed_choice[2] = {-1,1};
        speed_x *= speed_choice(GetRandomValue(0,1));
        speed_y *= speed_choice(GetRandomValue(0,1));

    }
};

class Paddle{
    public:
    float x, y;
    float width, hight;
    int speed;
    char upkey, downkey;

    void Draw(){
        DrawRectangle(x, y, width, hight, GOLD);
    }

    void updata(){
        if(IsKeyDown(upkey))
        {
            if (y >=GetScreenHeight())
            {
                y=GetScreenHeight()-120;
            }
            else{
                y += speed; 
            }
            
        }
        if(IsKeyDown(downkey))
        {
            if (y <= 0)
            {
                y= hight/2;
            }
            else{
                y -= speed; 
            }
        }
    }
};



Ball ball1;
// Ball ball2;
Paddle player1;
Paddle player2;

int main () {

    const int screenWidth = 800;
    const int screenHeight = 600;
    ball1.x=screenWidth/2;
    ball1.y=screenHeight/2;
    ball1.speed_x=10;
    ball1.speed_y=10;
    ball1.radius=20;

    // ball2.x=screenWidth/2;
    // ball2.y=screenHeight/2;
    // ball2.speed_x=5;
    // ball2.speed_y=5;
    // ball2.radius=50;

    player1.x=10;
    player1.y=screenHeight/2-60;
    player1.width=25;
    player1.hight=120;
    player1.speed=7;
    player1.upkey= KEY_S;
    player1.downkey= KEY_W;

    player2.x=screenWidth-10-25;
    player2.y=screenHeight/2-60;
    player2.width=25;
    player2.hight=120;
    player2.speed=7;
    player2.upkey= KEY_L;
    player2.downkey= KEY_O;

    InitWindow(screenWidth, screenHeight, "My first RAYLIB program!");
    SetTargetFPS(60);
    while (WindowShouldClose()== false){
        BeginDrawing();
        ClearBackground(DARKBLUE);
        DrawText(TextFormat)
        // updata
        ball1.Update();
        // ball2.Update();
        player1.updata();
        player2.updata();
        // check collsion
        if (CheckCollisionCircleRec(Vector2{ball1.x, ball1.y}, ball1.radius, Rectangle{player1.x, player1.y, player1.width, player1.hight}))
        {
            ball1.speed_x *= -1;
        }
        if (CheckCollisionCircleRec(Vector2{ball1.x, ball1.y}, ball1.radius, Rectangle{player1.x, player1.y, player1.width, player1.hight}))
        {
            ball1.speed_y *= -1;
        }
        

        // Draw
        ball1.Draw();
        // ball2.Draw();
        player1.Draw();
        player2.Draw();
        DrawLine(screenWidth/2,0,screenWidth/2,screenHeight,WHITE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}