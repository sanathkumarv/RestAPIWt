//#include "Vector3D.h"
#include <rttr/type>
struct Mesh
{
  Mesh(){}
  Mesh(const std::string& name){}
  int getPosition() const { return 0;}
  void setPosition(const int pos){}
	~Mesh(){}
/*
  enum E_TransformSpace
  {
    TS_LOCAL,
    TS_PARENT,
    TS_WORLD
  };
*/
  
  void setDirection(const int vec){}//, E_TransformSpace ts = TS_LOCAL);
  
  private:
    int _pos;
};

RTTR_DECLARE_STANDARD_TYPE_VARIANTS(Mesh) // to register the type

