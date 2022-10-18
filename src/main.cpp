#include<iostream> 
#include"matrix3f.hpp"
#include"matrix2f.hpp"
#include"matrix4f.hpp"

int main(void){ 
      float data3[3][3] = {
            {1.f, 2.f, 3.f},
            {3.f, 1.f, 2.f},
            {1.f, 3.f, 2.f},
      };
      float data2[2][2] = {
            {1.f, 2.f},
            {2.f, 1.f}
      };
      float data4[4][4] = {
            {100.f, 200.f, 3.f, 4.f},
            {3.f, 10.f, 2.f, 5.f},
            {1.f, 3.f, 2.f, 600.f},
            {3.f, 1.f, 200.f, 5.f},   
      };

      acm::matrix3f mat3(data3);
      acm::vector3f vec(1.f, 2.f, 3.f);
      acm::vector3f new_vec = mat3 * vec;
      acm::matrix2f mat2(data2);
      acm::matrix4f mat4(data4);
      mat3 = mat3 * 2;
      new_vec.print();
      mat3.print();
      mat2.print();
      mat4.print();
      std::cin.get(); 
} 
