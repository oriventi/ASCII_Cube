#include<iostream> 
#include"vector3f.hpp"

int main(void){ 
      acm::vector3f u(2,3,5);
      acm::vector3f v(2,0,9);
      double dist = v.distanceTo(u);
      u.print();
      v.print();
      std::cout << dist << std::endl;
      std::cin.get(); 
} 
