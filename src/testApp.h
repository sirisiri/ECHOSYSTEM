//
//  testApp.h
//  ECHOSYSTEM
//
//  Created by Napangsiri Wanpen on 11/6/12.
//
//

#pragma once

#include "ofMain.h"
#include "NoteBall.h"
#include "Obstacle.h"

class testApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed  (int key);
    void mouseReleased(int x, int y, int button);
    
    vector<NoteBall> b;
    vector<Obstacle> ob;
    
    int maxObstacle;
    int nextId;
    
    bool colorBallC;
    bool colorBallD;
    bool colorBallE;
    bool colorBallF;
    bool colorBallG;
    bool colorBallA;
    bool colorBallB;
    
    ofImage interface;
    
};
