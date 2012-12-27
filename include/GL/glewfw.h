//
//  glewfw.h
//  glewfw
//
//  Created by Doug Binks on 10/29/12.
//  Copyright (c) 2012 Doug Binks. All rights reserved.
//

#pragma once
#ifndef glewfw_glewfw_h
#define glewfw_glewfw_h

// OGL 3.2 required, using core profile on mac os x
#ifndef __APPLE_CC__
    #include <GL/glew.h>
#else
    inline unsigned int glewInit()
    {
        return 0;
    }
#define GLFW_INCLUDE_GL3
#endif
#define GLFW_DLL
#define GLFW_NO_GLU
#include <GL/glfw.h>


// extensions to glfw
GLFWAPI void GLFWAPIENTRY  glewfwToggleFullscreen();

#endif
