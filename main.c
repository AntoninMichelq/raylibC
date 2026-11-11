#include <stdio.h>
#include <raylib.h>

int main(int argc, char* argv[]) {
  
  InitWindow(800, 800, "MotionLineControllableSimulation");

  DisableCursor();

  Camera3D camera = { 0 };
  camera.position = (Vector3){6, 6, 6};
  camera.target = (Vector3) {0, 0, 0};
  camera.up = (Vector3) {0, 1, 0};
  camera.fovy = 45.0f;
  camera.projection = CAMERA_PERSPECTIVE;
  Vector3 cubePosition;

  cubePosition.x = -2;
  cubePosition.y = 0.5f;
  cubePosition.z = 0;

  SetTargetFPS(60);
  float rotation = 2.0f;
  float vitesse = 0.1f;
  while(!WindowShouldClose()) {
    float deltaTime = GetFrameTime();
    UpdateCameraPro(&camera,
        (Vector3){
            (IsKeyDown(KEY_W) - IsKeyDown(KEY_S)) * vitesse,
            (IsKeyDown(KEY_D) - IsKeyDown(KEY_A)) * vitesse,
            (IsKeyDown(KEY_SPACE) - IsKeyDown(KEY_LEFT_SHIFT)) * vitesse
        },
        (Vector3){
            (IsKeyDown(KEY_RIGHT) - IsKeyDown(KEY_LEFT)) * rotation,
            (IsKeyDown(KEY_DOWN)  - IsKeyDown(KEY_UP))   * rotation,
            0.0f
        },
        0.0f);

    BeginDrawing();
      ClearBackground(RAYWHITE);
      BeginMode3D(camera);
        DrawGrid(10, 1);
          
        //line
        DrawCube((Vector3) { cubePosition.x-0.5f, cubePosition.y, cubePosition.z}, 0.5, 0.01, 0.01, BLACK);
        //dessiner un nouveau point a chaque fois que le cube bouge (ligne de mouvement test) 
        //object cube
        DrawCube(cubePosition, 1, 1, 1, RED);
      EndMode3D(); 
      DrawFPS(10,10);
    EndDrawing();

    cubePosition.x += 1 * deltaTime; 
    //generer des mouvements de cube suivi de sa motion line
  }
  CloseWindow();
  return 0;
}
