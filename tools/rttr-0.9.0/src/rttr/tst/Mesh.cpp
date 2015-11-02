#include <rttr/reflect>
#include "Mesh.h"
#include <iostream>
using namespace rttr;

// register the class Mesh before main is called
RTTR_REGISTER
{
  class_<Mesh>()
    .constructor<>()
    .constructor<const std::string&>()
/*    .enumeration<E_TransformSpace>({{"TS_LOCAL", TS_LOCAL},
                                    {"TS_PARENT", TS_PARENT},
                                    {"TS_WORLD", TS_WORLD}})
*/
    .property("pos", &Mesh::getPosition, &Mesh::setPosition)
    .method("setDirection", &Mesh::setDirection);
}

int main()
{
  Mesh obj;
  const type mesh_type = type::get(obj);
  std::cout << mesh_type.get_name() << std::endl;     // prints "Mesh"
  
  // sets/gets a property
  property pos = mesh_type.get_property("pos");
  pos.set_value(obj, 1);                // here we set the value
  variant var_pos = pos.get_value(obj);               // here we get the value
  
  int vec = var_pos.get_value<int>();      // vec == Vector3d(1,2,3)
  
  // invoke a method
  method meth_dir = mesh_type.get_method("setDirection");
  meth_dir.invoke(obj, 1);//, Mesh::TS_WORLD);
  
  // retrieve all properties
  for (const auto& prop : mesh_type.get_properties())
  {
      std::cout << prop.get_name(); // prints all property names of the type Mesh
  }
  
  for (const auto& meth : mesh_type.get_methods())
  {
      std::cout << meth.get_name(); //  prints all method names of the type Mesh
  }
  
  return 0;
}

