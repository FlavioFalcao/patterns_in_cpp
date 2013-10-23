//
//  Factory Adapter.
//
//

#include <iostream>

using namespace std;

class Bone{
public:
    virtual void draw()=0;
    Bone(){
        boneId = boneTotal++;
    }
protected:
    int boneId;
    static int boneTotal;
};

int Bone::boneTotal=0;


class Tibia:public Bone{
public:
    void draw(){
        cout << "Tibia bone" << endl;
    }
};

class fibia:public Bone{
public:
    void draw(){
        cout <<" fibia bone " << endl;

    }    
};

class femur:public Bone {
public:
    void draw(){
        cout << " femur draw " << endl;
    }
};

class Radius:public Bone{
public:
    void draw(){
        cout << "Radius bone" << endl;
    }
};


class Humerus:public Bone {
public:
    void draw(){
        cout << "Humerus bone " << endl;
    }
};


class Ulna:public Bone{
public:
    void draw(){
        cout << "Ulna bone " << endl;
    }
};


class FactoryForArms{
public:
    virtual Bone* createArmBigBone()=0;
    virtual Bone* createArmSmallBone1()=0;
    virtual Bone* createArmSmallBone2()=0;
 
};
class FactoryForLegs{
public:
    virtual Bone* createLegBigBone()=0;
    virtual Bone* createLegSmallBone1()=0;
    virtual Bone* createLegSmallBone2()=0;
};


class ArmFactory : public FactoryForArms {
public:
    Bone* createArmBigBone(){
        return new Humerus;
    }
    Bone* createArmSmallBone1(){
        return new Radius;
    }
    Bone* createArmSmallBone2(){
        return new Ulna;
    }
};


class LegFactory : public FactoryForLegs {
public:
    Bone* createLegBigBone(){
        return new femur;
    }
    Bone* createLegSmallBone1(){
        return new Tibia;
    }
    Bone* createLegSmallBone2(){
        return new fibia;
    }
};
class Arm  {
    enum{HUMERUS=0,RADIUS=1,ULNA=2};
   public:
    Arm(){
        FactoryForArms* BoneFactory = new ArmFactory;
        ArmBones[HUMERUS] =  BoneFactory->createArmBigBone(); 
        ArmBones[HUMERUS]->draw();
        ArmBones[RADIUS] = BoneFactory->createArmSmallBone1(); 
        ArmBones[RADIUS]->draw();
        ArmBones[ULNA] = BoneFactory->createArmSmallBone2(); 
        ArmBones[ULNA]->draw();
         }
protected:
    int size;
    Bone* ArmBones[3];
    
};
class Leg  {
    enum{FEMUR=0,TIBIA=1,FIBIA=2};
public:
    Leg(){
        FactoryForLegs* BoneFactory = new LegFactory;
        
        LegBones[FEMUR] =  BoneFactory->createLegBigBone(); 
        LegBones[FEMUR]->draw();
        LegBones[TIBIA] = BoneFactory->createLegSmallBone1(); 
        LegBones[TIBIA]->draw();
        LegBones[FIBIA] = BoneFactory->createLegSmallBone2(); 
        LegBones[FIBIA]->draw();
    }
protected:
    int size;
    Bone* LegBones[3];
    
};


int main (int argc, const char * argv[])
{

    Arm rightArm;
    Arm leftArm;
    Leg rightLeg;
    
    
    
    return 0;
}

