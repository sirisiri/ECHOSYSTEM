//
//  testApp.cpp
//  ECHOSYSTEM
//
//  Created by Napangsiri Wanpen on 11/6/12.
//
//

#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
    ofBackground(255);
    ofSetFrameRate(24);
    ofEnableSmoothing();
    
    //load interface
    interface.loadImage("interface.jpg");
    
    //assign values to variables
    nextId = 0;
    maxObstacle = 7;
    
    //set up Obstacles
    for(int j=0; j<maxObstacle; j++)
    {
        Obstacle obbie;
        obbie.designObstacle();
        ob.push_back(obbie);
    }
}

//--------------------------------------------------------------
void testApp::update()
{
    for(int i=0; i<b.size(); i++)
    {
        //bounce NoteBalls
        b[i].bounceBack();
        
        //link NoteBalls
        b[i].linkBall(b);
    }
    
    for(int j=0; j<maxObstacle; j++)
    {
        //bounce Obstacles
        ob[j].bounceObstacle();
        
        //assign Obstacles to erase NoteBalls
        ob[j].killerObstacle(b);
    }
}

//--------------------------------------------------------------
void testApp::draw()
{
    //draw interface
    ofSetColor(255);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    interface.draw(0, 0);
    
    //draw NoteBalls
    for(int i=0; i<b.size(); i++)
    {
        b[i].draw(b);
    }
    
    //draw Obstacles
    for(int j=0; j<maxObstacle; j++)
    {
        ob[j].drawObstacle();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
    //musical note [C] = green
    if(key == 'C')
    {
        colorBallC = true;
    }
    else
    {
        colorBallC = false;
    }
    
    //musical note [D] = blue
    if(key == 'D')
    {
        colorBallD = true;
    }
    else
    {
        colorBallD = false;
    }
    
    //musical note [E] = purple
    if(key == 'E')
    {
        colorBallE = true;
    }
    else
    {
        colorBallE = false;
    }
    
    //musical note [F] = dark purple
    if(key == 'F')
    {
        colorBallF = true;
    }
    else
    {
        colorBallF = false;
    }
    
    //musical note [G] = red
    if(key == 'G')
    {
        colorBallG = true;
    }
    else
    {
        colorBallG = false;
    }
    
    //musical note [A] = orange
    if(key == 'A')
    {
        colorBallA = true;
    }
    else
    {
        colorBallA = false;
    }
    
    //musical note [B] = lime
    if(key == 'B')
    {
        colorBallB = true;
    }
    else
    {
        colorBallB = false;
    }
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button)
{
    //musical note [C] = green
    if(colorBallC == true && x >= 20 && x <= ofGetWidth()-20 && y>= 20 && y <= ofGetHeight()-100)
    {
        NoteBall bC;
        bC.addNoteBall(1, nextId, x, y);
        b.push_back(bC);
        nextId++;
    }
    
    //musical note [D] = blue
    if(colorBallD == true && x >= 20 && x <= ofGetWidth()-20 && y>= 20 && y <= ofGetHeight()-100)
    {
        NoteBall bD;
        bD.addNoteBall(2, nextId, x, y);
        b.push_back(bD);
        nextId++;
    }
    
    //musical note [E] = purple
    if(colorBallE == true && x >= 20 && x <= ofGetWidth()-20 && y>= 20 && y <= ofGetHeight()-100)
    {
        NoteBall bE;
        bE.addNoteBall(3, nextId, x, y);
        b.push_back(bE);
        nextId++;
    }
    
    //musical note [F] = dark purple
    if(colorBallF == true && x >= 20 && x <= ofGetWidth()-20 && y>= 20 && y <= ofGetHeight()-100)
    {
        NoteBall bF;
        bF.addNoteBall(4, nextId, x, y);
        b.push_back(bF);
        nextId++;
    }
    
    //musical note [G] = red
    if(colorBallG == true && x >= 20 && x <= ofGetWidth()-20 && y>= 20 && y <= ofGetHeight()-100)
    {
        NoteBall bG;
        bG.addNoteBall(5, nextId, x, y);
        b.push_back(bG);
        nextId++;
    }
    
    //musical note [A] = orange
    if(colorBallA == true && x >= 20 && x <= ofGetWidth()-20 && y>= 20 && y <= ofGetHeight()-100)
    {
        NoteBall bA;
        bA.addNoteBall(6, nextId, x, y);
        b.push_back(bA);
        nextId++;
    }
    
    //musical note [B] = lime
    if(colorBallB == true && x >= 20 && x <= ofGetWidth()-20 && y>= 20 && y <= ofGetHeight()-100)
    {
        NoteBall bB;
        bB.addNoteBall(7, nextId, x, y);
        b.push_back(bB);
        nextId++;
    }
}