// in theory, this uses a graphics layer to render to,
// but in this sample we are instead delegating to a std::cout

#pragma once
#include <iostream>


struct grass_overhead {
  int x;
  int y;
};


struct grass {
  unsigned int draw_loc = 0; 

  void Init() {
    if (draw_loc == 0) {

      std::cout << "grass init\n ";
      draw_loc = 1;

       // what you would really do:
       // code to upload your model details to graphics memory
    }
  }
  void DeInit() {
    if (draw_loc != 0) {


      std::cout << "grass deinit\n ";
      draw_loc = 0;

      // what you would really do:
      // code to remove from graphics memory
    }
  }
  void Draw(const grass_overhead& details) {
    std::cout << "grass at: " << details.x << ", " << details.y << '\n';

    // what you would really do in a render 
    // set shader with details
    // run draw to screen on the grass
  }
} grass_instant;

