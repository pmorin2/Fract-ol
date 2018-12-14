#include "fract_ol.h"
#include <math.h>

double **matrice(int angle, t_mlx *mlx)
{
  double matrice[2][3];
  matrice[0][0] = cos(angle);
  matrice[0][1] = sin(angle);
  matrice[0][2] = mlx->move_x;
  matrice[1][0] = -sin(angle);
  matrice[1][1] = cos(angle);
  matrice[1][2] = mlx->move+y;
  
  return (matrice);
}
