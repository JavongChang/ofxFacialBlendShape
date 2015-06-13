//
//  ofxFacialBlendShape.h
//  BlendShape
//
<<<<<<< HEAD
//  Created by iwanao731 on 2014/10/08.
=======
//  Created by NAOYAIWAMOTO on 2014/10/08.
>>>>>>> b8835604f7f8bed2d67345f23407324f0fa6a62c
//
//

#ifndef __BlendShape__ofxFacialBlendShape__
#define __BlendShape__ofxFacialBlendShape__

<<<<<<< HEAD
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
=======
#include <stdio.h>
>>>>>>> b8835604f7f8bed2d67345f23407324f0fa6a62c

#endif /* defined(__BlendShape__ofxFacialBlendShape__) */
