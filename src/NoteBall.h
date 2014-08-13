//
//  NoteBall.h
//  ECHOSYSTEM
//
//  Created by Napangsiri Wanpen on 11/6/12.
//
//

#pragma once
#include "ofMain.h"

class NoteBall {
public:
    
    //--------------------------------------------------------------
    void starterBall(int _type, int _id)
    {
        id = _id;
        type = _type;
        
        if(type == 1)
        {
            sound.loadSound("noteC.wav");
        }
        if(type == 2)
        {
            sound.loadSound("noteD.wav");
        }
        if(type == 3)
        {
            sound.loadSound("noteE.wav");
        }
        if(type == 4)
        {
            sound.loadSound("noteF.wav");
        }
        if(type == 5)
        {
            sound.loadSound("noteG.wav");
        }
        if(type == 6)
        {
            sound.loadSound("noteA.wav");
        }
        if(type == 7)
        {
            sound.loadSound("noteB.wav");
        }
        
        sound.setLoop(true);
        sound.setVolume(1.0);
        
        radius = ofRandom(radiusMin, radiusMax);
        position.x = ofRandom((radius/1.5)+20, ofGetWidth()-((radius/1.5)+20));
        position.y = ofRandom((radius/1.5)+20, ofGetHeight()-((radius/1.5)+20));
        velocity.x = ofRandom(-1.5, 1.5);
        velocity.y = ofRandom(-1.5, 1.5);
    }
    
    //--------------------------------------------------------------
    void addNoteBall(int _type, int _id, float x, float y)
    {
        id = _id;
        type = _type;
        
        if(type == 1)
        {
            sound.loadSound("noteC.wav");
        }
        if(type == 2)
        {
            sound.loadSound("noteD.wav");
        }
        if(type == 3)
        {
            sound.loadSound("noteE.wav");
        }
        if(type == 4)
        {
            sound.loadSound("noteF.wav");
        }
        if(type == 5)
        {
            sound.loadSound("noteG.wav");
        }
        if(type == 6)
        {
            sound.loadSound("noteA.wav");
        }
        if(type == 7)
        {
            sound.loadSound("noteB.wav");
        }
        
        sound.setLoop(true);
        sound.setVolume(1.0);
        
        radius = ofRandom(radiusMin, radiusMax);
        position.x = x;
        position.y = y;
        velocity.x = ofRandom(-1.5, 1.5);
        velocity.y = ofRandom(-1.5, 1.5);
    }
    
    //--------------------------------------------------------------
    void linkBall(vector<NoteBall>& b)
    {
        position += velocity;
        
        for(int i=0; i<b.size(); i++)
        {
            //prevent a NoteBall from linking to itself
            if(b[i].id == id) continue;
            
            //link line distances
            float ballDist = position.distance(b[i].position);
            int linkDist = 150;
            
            //linking conditions
            bool isLinked = isLinkedTo(b[i]);
            
            if(isLinked && ballDist > linkDist)
            {
                unLink(b[i]);
            }
            if(!isLinked && ballDist < linkDist)
            {
                links.push_back(b[i].id);
            }
        }
        
        //play sound(s) when linked
        if(links.size() > 0 && !sound.getIsPlaying())
        {
            sound.play();
        }
        
        //stop sound(s) when unlinked
        if(links.size() == 0 && sound.getIsPlaying())
        {
            sound.stop();
        }
    }
    
    //--------------------------------------------------------------
    void unLink(NoteBall& other)
    {
        for(int i=0; i<links.size(); i++)
        {
            if(links[i] == other.id)
            {
                links.erase(links.begin()+i);
            }
        }
    }
    
    //--------------------------------------------------------------
    bool isLinkedTo(NoteBall& other)
    {
        for(int i=0; i<links.size(); i++)
        {
            if(links[i] == other.id) return true;
        }
        return false;
    }
    
    //--------------------------------------------------------------
    void bounceBack()
    {
        position += velocity;
        
        if(position.x <= 20+(radius-radius/3) || position.x >= ofGetWidth()-(20+(radius-radius/3)))
        {
            velocity.x = -velocity.x;
        }
        if(position.y <= 20+(radius-radius/3) || position.y >= ofGetHeight()-100)
        {
            velocity.y = -velocity.y;
        }
    }
    
    //--------------------------------------------------------------
    void draw(vector<NoteBall>& b)
    {
        //musical note [C]
        if(type == 1)
        {
            ofSetColor(0, 231, 1);
            ofNoFill();
            ofSetLineWidth(1);
            ofCircle(position, 0.5);
            ofCircle(position, radius-(radius/1.5));
            ofCircle(position, radius-(radius/2));
            ofCircle(position, radius-(radius/3));
        }
        //musical note [D]
        else if(type == 2)
        {
            ofSetColor(0, 108, 255);
            ofNoFill();
            ofSetLineWidth(1);
            ofCircle(position, 0.5);
            ofCircle(position, radius-(radius/1.5));
            ofCircle(position, radius-(radius/2));
            ofCircle(position, radius-(radius/3));
        }
        //musical note [E]
        else if(type == 3)
        {
            ofSetColor(129, 0, 206);
            ofNoFill();
            ofSetLineWidth(1);
            ofCircle(position, 0.5);
            ofCircle(position, radius-(radius/1.5));
            ofCircle(position, radius-(radius/2));
            ofCircle(position, radius-(radius/3));
        }
        //musical note [F]
        else if(type == 4)
        {
            ofSetColor(64, 0, 87);
            ofNoFill();
            ofSetLineWidth(1);
            ofCircle(position, 0.5);
            ofCircle(position, radius-(radius/1.5));
            ofCircle(position, radius-(radius/2));
            ofCircle(position, radius-(radius/3));
        }
        //musical note [G]
        else if(type == 5) {
            ofSetColor(255, 0, 0);
            ofNoFill();
            ofSetLineWidth(1);
            ofCircle(position, 0.5);
            ofCircle(position, radius-(radius/1.5));
            ofCircle(position, radius-(radius/2));
            ofCircle(position, radius-(radius/3));
        }
        //musical note [A]
        else if(type == 6)
        {
            ofSetColor(255, 136, 0);
            ofNoFill();
            ofSetLineWidth(1);
            ofCircle(position, 0.5);
            ofCircle(position, radius-(radius/1.5));
            ofCircle(position, radius-(radius/2));
            ofCircle(position, radius-(radius/3));
        }
        //musical note [B]
        else if(type == 7) {
            ofSetColor(154, 244, 0);
            ofNoFill();
            ofSetLineWidth(1);
            ofCircle(position, 0.5);
            ofCircle(position, radius-(radius/1.5));
            ofCircle(position, radius-(radius/2));
            ofCircle(position, radius-(radius/3));
        }
        
        //link line color
        ofSetColor(150, 98);
        
        //draw a link line
        for(int i=0; i<links.size(); i++)
        {
            int ball_id = links[i];
            
            for(int j=0; j<b.size(); j++)
            {
                if(b[j].id == ball_id)
                {
                    ofLine(position, b[j].position);
                }
            }
        }
    }
    
    //--------------------------------------------------------------
    ofPoint position;
    ofPoint velocity;
    ofColor color;
    
    vector<int> links;
    
    float radius;
    int radiusMin = 20;
    int radiusMax = 50;
    
    int id;
    int type;
    
    ofSoundPlayer sound;
};