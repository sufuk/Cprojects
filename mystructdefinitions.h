typedef struct twodimensionalpoint{

  double x;
  double y;

}TDP_t;


double distancecalc(TDP_t p1, TDP_t p2){


  //((x0 - x1)^2 + (y0 - y1)^2)^1/2

  double resultx = pow((p1.x - p2.x), 2);
  double resulty = pow((p1.y - p2.y), 2);
  double result  = sqrt(resultx + resulty);

return result;


}
