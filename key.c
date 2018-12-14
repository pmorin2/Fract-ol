#include "fract_ol.h"

int	keypress(int key, t_mlx *mlx)
{
  if (key == K_TAB)
    palette_switch(mlx);
  else if (key == K_ESC)
    //fonction de free et de quit
  else if (key == RIGHT_ARROW)
    mlx->move_x += 10;
  else if (key == LEFT_ARROW)
    mlx->move_x -= 10;
  else if (key == UP_ARROW)
    mlx->move_y -= 10;
  else if (key == DOWN_ARROW)
    mlx->move_y += 10;
  else if (key == K_PLUS)
    angle += 5;
  else if (key == K_MINUS)
    angle -= 5;
  return (0);
}
