#pragma once

#include "raylib.h"

class CameraManager
{
    public:
    CameraManager();
    Camera2D GetCamera();
    Vector2 ConvertToWorldPos(Vector2 Mousepos);

    private:
    Camera2D camera = { 0 };

    //>1 is zoom in  <1 is zoom out
    float scaleFactor = 1;
    float maxZoomOut = 0.125f;
    float maxZoomIn = 64.0f;
};