#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    model = new ofMesh [10];
    emotion = new ofParameter<float> [9];

	ofxObjLoader::load("model/head-reference.obj", model[0]);
	ofxObjLoader::load("model/head-01-anger.obj", model[1]);
	ofxObjLoader::load("model/head-02-cry.obj", model[2]);
	ofxObjLoader::load("model/head-03-fury.obj", model[3]);
	ofxObjLoader::load("model/head-04-grin.obj", model[4]);
	ofxObjLoader::load("model/head-05-laugh.obj", model[5]);
	ofxObjLoader::load("model/head-06-rage.obj", model[6]);
	ofxObjLoader::load("model/head-07-sad.obj", model[7]);
	ofxObjLoader::load("model/head-08-smile.obj", model[8]);
	ofxObjLoader::load("model/head-09-surprise.obj", model[9]);
    
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
    
    vnum = model[0].getNumVertices();
    temp = model[0];
    
	Diff =  new ofVec3f *[10];
	for(int i=0; i<10; i++){
		Diff[i] = new ofVec3f [vnum];
	}
    
	for(int i=0; i<10; i++){
		for(int j=0; j<vnum; j++){
			Diff[i][j] = model[i].getVertex(j) - model[0].getVertex(j);
		}
	}
}

//--------------------------------------------------------------
void testApp::update(){
    LinearCombination();
}

//--------------------------------------------------------------
void testApp::draw(){

    ofBackgroundGradient(ofColor(64), ofColor(0));

    panel.draw();

    cam.begin();
    
//    ofSetColor(255);
//    temp.draw();
    
    ofSetColor(255);
    temp.drawWireframe();
    
    cam.end();

}

//--------------------------------------------------------------
void testApp::LinearCombination()
{
	temp = model[0];
	for(int i=0; i<9; i++){
		for(int j=0; j<vnum; j++){
            temp.setVertex(j, temp.getVertex(j) + emotion[i].get()*Diff[i][j]);
        }
	}
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    float length = 200;
    
	if( x > 0 && x < length )
		cam.disableMouseInput();
	else
		cam.enableMouseInput();
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
