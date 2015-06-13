//
//  ofxFacialBlendShape.cpp
//  BlendShape
//

#include "ofxFacialBlendShape.h"

void ofxFacialBlendShape::init(){
    
    vnum = templeteMesh.getNumVertices();
    
    Diff =  new ofVec3f *[_model.size()];
    for(int i=0; i<_model.size(); i++){
        Diff[i] = new ofVec3f [vnum];
    }
    
    for(int i=0; i<_model.size(); i++){
        for(int j=0; j<vnum; j++){
            Diff[i][j] = _model[i].getVertex(j) - templeteMesh.getVertex(j);
        }
    }
}

void ofxFacialBlendShape::update()
{
    blendShape = templeteMesh;
    for(int i=0; i<_model.size(); i++){
        for(int j=0; j<vnum; j++){
            blendShape.setVertex(j, blendShape.getVertex(j) + emotion[i].get()*Diff[i][j]);
        }
    }
}

void ofxFacialBlendShape::draw()
{
    blendShape.draw();
}

void ofxFacialBlendShape::setEmotion(ofParameter<float> *_emotion)
{
    emotion = _emotion;
}

void ofxFacialBlendShape::setTempleteModel(ofMesh mesh)
{
    templeteMesh = mesh;
    blendShape = mesh;
}

void ofxFacialBlendShape::addModel(ofMesh mesh)
{
    _model.push_back(mesh);
}