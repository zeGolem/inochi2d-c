/*
    Copyright © 2022, Inochi2D Project
    Distributed under the 2-Clause BSD License, see LICENSE file.
    
    Authors: Luna Nielsen
*/
#include <stddef.h>
#include <stdint.h>

#ifndef H_INOCHI2D
#define H_INOCHI2D

    struct InPuppet;
    struct InCamera;
    struct InRenderable;

    // Inochi2D runtime functionality
    void inInit(double (*timingFunc)());
    void inCleanup();
    #ifdef INOCHI2D_GLYES
        void inSceneBegin();
        void inSceneEnd();
        void inSceneDraw(float x, float y, float width, float height);
    #endif

    // Inochi2D Cameras
    InCamera* inCameraGetCurrent();
    void inCameraDestroy(InCamera* camera);
    void inCameraGetPosition(InCamera* camera, float* x, float* y);
    void inCameraSetPosition(InCamera* camera, float x, float y);
    void inCameraGetZoom(InCamera* camera, float* zoom);
    void inCameraSetZoom(InCamera* camera, float zoom);

    // Inochi2D Puppets
    InPuppet* inPuppetLoad(const char *path);
    InPuppet* inPuppetLoadEx(const char *path, size_t length);
    InPuppet* inPuppetLoadFromMemory(uint8_t* data, size_t length);
    void inPuppetDestroy(InPuppet*);
    void inPuppetUpdate(InPuppet*);
    #ifdef INOCHI2D_GLYES
        void inPuppetDraw(InPuppet*);
    #endif



#endif