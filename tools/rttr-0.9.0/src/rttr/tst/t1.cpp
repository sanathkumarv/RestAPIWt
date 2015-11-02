#include <rttr/reflect>
#include <iostream>
static void f() { std::cout << "Hello World" << std::endl; }
using namespace rttr;
RTTR_REGISTER
{
  method_("f", &f);
}
  
int main()
{
  type::invoke("f", {});
}
// outputs: "Hello World"

