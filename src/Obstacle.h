//
//  Obstacle.h
//  ECHOSYSTEM
//
//  Created by Napangsiri Wanpen on 11/6/12.
//
//

#pragma once
#include "ofMain.h"

class Obstacle {
public:
    
    //--------------------------------------------------------------
    void designObstacle()
    {
        radius = 10;
        position.x = ofRandom(20, ofGetWidth()-20);
        position.y = ofRandom(20, ofGetHeight()-100);
        velocity.x = ofRandom(-1.5, 1.5);
        velocity.y = ofRandom(-1.5, 1.5);
        color.r = 0;
        color.g = 0;
        color.b = 0;
    }
    
    //--------------------------------------------------------------
    void drawObstacle()
    {
        ofSetColor(100);
        ofNoFill();
        ofSetLineWidth(1);
        ofCircle(position, radius);
        ofFill();
        ofCircle(position, radius-5);
    }
    
    //--------------------------------------------------------------
    void bounceObstacle()
    {
        position += velocity;
        
        if(position.x <= 20+radius || position.x >= ofGetWidth()-(20+radius))
        {
            velocity.x = -velocity.x;
        }
        if(position.y <= 20+radius || position.y >= ofGetHeight()-(100-radius))
        {
            velocity.y = -velocity.y;
        }
    }
    
    //--------------------------------------------------------------
    void killerObstacle(vector<NoteBall>& b)
    {
        //kill NoteBalls
        for(int i=0; i<b.size(); i++)
        {
            float killDist = ofDist(b[i].position.x, b[i].position.y, position.x, position.y);
            
            if(killDist < radius+15)
            {
                b.erase(b.begin()+i);
            }
        }
    }
    
    //--------------------------------------------------------------
    ofPoint velocity;
    ofPoint position;
    ofColor color;
    float radius;
    
};