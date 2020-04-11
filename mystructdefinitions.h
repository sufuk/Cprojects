#include<math.h>

//////////////////

typedef struct threedimensionalpoint{

  double x;
  double y;
  double z;
}TDP_t;


double distancecalc(TDP_t p1, TDP_t p2){


  //((x0 - x1)^2 + (y0 - y1)^2 + (z0 - z1)^2)^(1/2)

  double resultx = pow((p1.x - p2.x), 2);
  double resulty = pow((p1.y - p2.y), 2);
  double resultz = pow((p1.z - p2.z), 2);
  double result  = sqrt(resultx + resulty + resultz);

return result;


}
///////////////////////////////////////////////////7

int isequal(  TDP_t p1, TDP_t  p2)
{
    if (p1.x == p2.x && p1.y == p2.y && p1.z == p2.z ){
      return 1;

    }
    else{
      return 0;
    }
}
////////////////////////////777



typedef struct complex_number {
    float real;
    float img;
} complex_n;



complex_n sum(complex_n num1, complex_n num2) {
    complex_n result;
    result.real = num1.real + num2.real;
    result.img = num1.img + num2.img;
    return (result);
}

////////////////////////////////////7

void movepoint(TDP_t *point1, double dx, double dy, double dz){

  (*point1).x += dx;
  (*point1).y += dy;
  (*point1).z += dz;


}