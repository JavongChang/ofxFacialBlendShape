#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // set templete mesh
    ofMesh templete;
    ofxObjLoader::load("model/head-reference.obj", templete);
    fbs.setTempleteModel(templete);
    
    // set emotional face
    ofMesh model[9];
    ofxObjLoader::load("model/head-01-anger.obj", model[0]);
    ofxObjLoader::load("model/head-02-cry.obj", model[1]);
    ofxObjLoader::load("model/head-03-fury.obj", model[2]);
    ofxObjLoader::load("model/head-04-grin.obj", model[3]);
    ofxObjLoader::load("model/head-05-laugh.obj", model[4]);
    ofxObjLoader::load("model/head-06-rage.obj", model[5]);
    ofxObjLoader::load("model/head-07-sad.obj", model[6]);
    ofxObjLoader::load("model/head-08-smile.obj", model[7]);
    ofxObjLoader::load("model/head-09-surprise.obj", model[8]);
    
    for (int i=0; i<9; i++) {
        fbs.addModel(model[i]);
    }

    // set emotion parameter
    emotion = new ofParameter<float> [9];
    
    // GUI
    panel.setup("panel");
    panel.add(emotion[0].set("anger", 0, 0, 1.0));
    panel.add(emotion[1].set("cry", 0, 0, 1.0));
    panel.add(emotion[2].set("fury", 0, 0, 1.0));
    panel.add(emotion[3].set("grin", 0, 0, 1.0));
    panel.add(emotion[4].set("laugh", 0, 0, 1.0));
    panel.add(emotion[5].set("rage", 0, 0, 1.0));
    panel.add(emotion[6].set("sad", 0, 0, 1.0));
    panel.add(emotion[7].set("smile", 0, 0, 1.0));
    panel.add(emotion[8].set("surprise", 0, 0, 1.0));
    
    fbs.setEmotion(emotion);

    fbs.init();
}

//--------------------------------------------------------------
void ofApp::update(){
    fbs.update();
    
    float val1 = powf(1 - (sin(ofGetElapsedTimef()*10)*.5+.5),2);
    emotion[0].set(val1);
    
    float val2 = powf(1 - (cos(ofGetElapsedTimef()*10)*.5+.5),2);
    emotion[1].set(val2);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackgroundGradient(ofColor(64), ofColor(0));

    cam.begin();
    
    ofEnableDepthTest();
    ofEnableLighting();

    light.setPosition(cam.getPosition());
    light.enable();
    
    ofSetColor(150);
    fbs.draw();
    
    ofDisableDepthTest();
    ofDisableLighting();
    
    cam.end();
    
    panel.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    float length = 200;
    if( x > 0 && x < length )
        cam.disableMouseInput();
    else
        cam.enableMouseInput();
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
