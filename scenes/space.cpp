#include "space.h"

#include "CameraManager.h"
#include "objekt.h"
#include <vector>
#include "math.h"
#include <iostream>

Spacescene::Spacescene(){
    return;
}

Spacescene::fn(){
    float DeltaTime = GetFrameTime();
    Vector2 worldMousePos = mainCamera.ConvertToWorldPos(GetMousePosition());
    time += DeltaTime;



    /*if(time > 0.1){
        cirklar.push_back(Circle(RED,10,rand()%700,rand()%700,0,0,0.95));
        time -= 0.1;
    }*/
    if (IsMouseButtonPressed(1)){
        cirklar.push_back(Circle(RED,10,worldMousePos.x, worldMousePos.y,0,0,0.95));
    }

    for(int i = cirklar.size()-1; i>0;i--){
        for(int j = 0; j<i;j++){
            Gravity(cirklar[i],cirklar[j],G);

        }
    }

    for(int i = cirklar.size()-1; i>0;i--){
        for(int j = 0; j<i;j++){
            Collision(cirklar[i],cirklar[j]);
        }
    }

    //check_nans(cirklar);

    for(int i = 0; i<cirklar.size(); i++){
        cirklar[i].update(DeltaTime);
    }

    BeginDrawing();
        ClearBackground(BLACK);
        BeginMode2D(mainCamera.GetCamera());
        for(int i = 0; i<cirklar.size(); i++){
            cirklar[i].draw();
        }
        EndMode2D();
    EndDrawing();

    return 0;
}