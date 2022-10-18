#include<iostream> 
#include"matrix3f.hpp"

int main(void){ 
      float data[3][3] = {
            {1.f, 2.f, 3.f},
            {3.f, 1.f, 2.f},
            {1.f, 3.f, 2.f},
      };
      acm::matrix3f test(data);
      acm::vector3f vec(1.f, 2.f, 3.f);
      acm::vector3f new_vec = test * vec;
      test = test * 2;
      new_vec.print();
      test.print();
      std::cin.get(); 
} 
