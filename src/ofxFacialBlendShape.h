//
//  ofxFacialBlendShape.h
//  BlendShape
//

#ifndef __BlendShape__ofxFacialBlendShape__
#define __BlendShape__ofxFacialBlendShape__

#include "ofMain.h"

class ofxFacialBlendShape{

private:
    int vnum;
    ofVec3f **Diff;
    ofParameter<float> *emotion;
    
    ofMesh templeteMesh;
    ofMesh blendShape;
    vector<ofMesh> _model;

    void linearCombination();

public:
    ofxFacialBlendShape(){};
    ~ofxFacialBlendShape(){};
    void init();
    void update();
    void draw();

    void setTempleteModel(ofMesh mesh);
    void addModel(ofMesh mesh);
    void setEmotion(ofParameter<float> *emotion);
};

#endif /* defined(__BlendShape__ofxFacialBlendShape__) */
