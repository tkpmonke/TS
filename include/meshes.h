#pragma once

float square_vertices[] = {
          /*VERTICES*/   0.5f,  0.5f, 0.0f,      /*TEXCOORDS*/   1.0f, 1.0f,
          /*VERTICES*/   0.5f, -0.5f, 0.0f,      /*TEXCOORDS*/   1.0f, 0.0f,
          /*VERTICES*/  -0.5f, -0.5f, 0.0f,      /*TEXCOORDS*/   0.0f, 0.0f,
          /*VERTICES*/  -0.5f,  0.5f, 0.0f,      /*TEXCOORDS*/   0.0f, 1.0f 
};
unsigned int square_faces[] = {  // note that we start from 0!
    0, 1, 3,  // first Triangle
    1, 2, 3   // second Triangle
};