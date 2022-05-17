// mlx_new_image
//
// by Ol
//


#import <Cocoa/Cocoa.h>
#import <OpenGL/gl3.h>

#include "mlx_int.h"
#include "mlx_new_window.h"



void    *mlx_new_image(mlx_ptr_t *mlx_ptr, int width, int height)
{
  mlx_move_list_t        *newmove;

  //  if (mlx_ptr->win_list == NULL)
  //    return (NULL);  // need at leat one window created to have openGL context and create texture
  if ((newmove = malloc(sizeof(*newmove))) == NULL)
    return ((void *)0);
  newmove->next = mlx_ptr->move_list;
  mlx_ptr->move_list = newmove;
  newmove->width = width;
  newmove->height = height;
  newmove->vertexes[0] = 0.0;  newmove->vertexes[1] = 0.0;
  newmove->vertexes[2] = width;  newmove->vertexes[3] = 0.0;
  newmove->vertexes[4] = width;  newmove->vertexes[5] = -height;
  newmove->vertexes[6] = 0.0;  newmove->vertexes[7] = -height;
  newmove->buffer = malloc(UNIQ_BPP*width*height);
  bzero(newmove->buffer, UNIQ_BPP*width*height);

  return (newmove);
}

mlx_move_ctx_t	*add_move_to_ctx(mlx_move_list_t *move, mlx_win_list_t *win)
{
  mlx_move_ctx_t	*movectx;

  movectx = win->move_list;
  while (movectx)
    {
      if (movectx->move == move)
	return (movectx);
      movectx = movectx->next;
    }

  movectx = malloc(sizeof(*movectx));
  movectx->move = move;
  movectx->next = win->move_list;
  win->move_list = movectx;

  glGenTextures(1, &(movectx->texture));
  glBindTexture(GL_TEXTURE_2D, movectx->texture);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,     GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,     GL_CLAMP_TO_EDGE);
  glTexImage2D(
	       GL_TEXTURE_2D, 0,           /* target, level of detail */
	       GL_RGBA8,                    /* internal format */
	       move->width, move->height, 0,           /* width, height, border */
	       GL_BGRA, GL_UNSIGNED_BYTE,   /* external format, type */
	       move->buffer               /* pixels */
	       );

  glGenBuffers(1, &(movectx->vbuffer));
  glBindBuffer(GL_ARRAY_BUFFER, movectx->vbuffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(move->vertexes), move->vertexes, GL_DYNAMIC_DRAW); // 4 points buff

  return (movectx);
}


void    mlx_put_image_to_window(mlx_ptr_t *mlx_ptr, mlx_win_list_t *win_ptr, mlx_move_list_t *move_ptr, int x, int y)
{
  mlx_move_ctx_t	*movectx;

  if (!win_ptr->pixmgt)
    return ;

  [(id)(win_ptr->winid) selectGLContext];
  movectx = add_move_to_ctx(move_ptr, win_ptr);

  // update texture
  glBindTexture(GL_TEXTURE_2D, movectx->texture);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, move_ptr->width, move_ptr->height, 0,
	       GL_BGRA, GL_UNSIGNED_BYTE, move_ptr->buffer);

  [(id)(win_ptr->winid) mlx_gl_draw_move:move_ptr andCtx:movectx andX:x andY:y];

  win_ptr->nb_flush ++;
}

// assume here 32bpp little endian

char    *mlx_get_data_addr(mlx_move_list_t *move_ptr, int *bits_per_pixel, int *size_line, int *endian)
{
  *bits_per_pixel = UNIQ_BPP*8;
  *size_line = move_ptr->width*UNIQ_BPP;
  *endian = 0; // little endian for now on mac-intel
  return (move_ptr->buffer);
}

unsigned int    mlx_get_color_value(mlx_ptr_t *mlx_ptr, int color)
{
  return (color);
}

int mlx_string_put(mlx_ptr_t *mlx_ptr, mlx_win_list_t *win_ptr, int x, int y, int color, unsigned char *string)
{
  mlx_move_ctx_t	*movectx;
  int		gX;
  int		gY;

  if (!win_ptr->pixmgt)
    return(0);

#ifdef STRINGPUTX11
  y -= (FONT_HEIGHT * 2)/3;
#endif

  [(id)(win_ptr->winid) selectGLContext];

  movectx = add_move_to_ctx(mlx_ptr->font, win_ptr);

  while (*string)
    {
      if (*string >= 32 && *string <= 127)
	{
	  gX = (FONT_WIDTH+2)*(*string-32);
	  gY = 0;
	  //      printf("put char %c pos %d %d\n", *string, gX, gY);
	  [(id)(win_ptr->winid) mlx_gl_draw_font:mlx_ptr->font andCtx:movectx andX:x andY:y andColor:color glyphX:gX glyphY:gY];
#ifdef STRINGPUTX11
	  x += FONT_WIDTH/1.4;
#else
	  x += FONT_WIDTH;
#endif
	}
      string ++;
    }

  win_ptr->nb_flush ++;
  
  return (0);
}

int     mlx_destroy_image(mlx_ptr_t *mlx_ptr, mlx_move_list_t *move_todel)
{
  mlx_move_ctx_t	ctx_first;
  mlx_move_ctx_t	*ctx;
  mlx_move_ctx_t	*ctx_to_del;
  mlx_move_list_t move_first;
  mlx_move_list_t *move;
  mlx_win_list_t *win;

  move_first.next = mlx_ptr->move_list;
  move = &move_first;
  while (move && move->next)
    {
      if (move->next == move_todel)
	move->next = move->next->next;
      move = move->next;
    }
  mlx_ptr->move_list = move_first.next;


  win = mlx_ptr->win_list;
  while (win)
    {
      ctx_first.next = win->move_list;
      ctx = &ctx_first;
      while (ctx && ctx->next)
	{
	  if (ctx->next->move == move_todel)
	    {
	      [(id)(win->winid) selectGLContext];
	      glDeleteBuffers(1, &(ctx->next->vbuffer));
	      glDeleteTextures(1, &(ctx->next->texture));
	      ctx_to_del = ctx->next;
	      ctx->next = ctx->next->next;
	      free(ctx_to_del);
	    }
	  ctx = ctx->next;
	}
      win->move_list = ctx_first.next;
      win = win->next;
    }


  free(move_todel->buffer);
  free(move_todel);

  //  printf("destroy image done.\n");
  return (0);
}
