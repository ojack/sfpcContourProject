#include "ofApp.h"
#include "trailsScene.h"
#include "emptyScene.h"
#include "geometryScene.h"
#include "offsetScene.h"
#include "velocityScene.h"


//--------------------------------------------------------------
void ofApp::setup(){

    player.load("input.mov");
    player.play();
    
    
    SM.scenes.push_back(new velocityScene());
    SM.scenes.push_back(new offsetScene());
    SM.scenes.push_back(new geometryScene());
    SM.scenes.push_back(new trailsScene());
    SM.scenes.push_back(new emptyScene());
    
    // share a pointer to the CT object 
    for (int i = 0; i < SM.scenes.size(); i++){
        SM.scenes[i]->CT = &CT;
    }
    
    SM.setup();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    player.update();

    
    finder.setThreshold(127);
    finder.findContours(player);
    
    if (finder.size() > 0){
        
        ofPolyline tempLine = finder.getPolyline(0);
        for (int i = 0; i < tempLine.size(); i++){
            tempLine[i] *= 3;
        }
        CT.analyze(tempLine);
    }
    
    SM.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0,0,0);
    

    
    SM.draw();
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == OF_KEY_RIGHT){
        SM.nextScene();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}