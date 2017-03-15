#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(void) {
   Display *d;
   Window w;
   XEvent e;
   char *msg = "Hello, World!";
   int s;
	int screen_width, screen_height;
	unsigned long white_pixel, black_pixel; 

   d = XOpenDisplay(NULL);
   if (d == NULL) {
      fprintf(stderr, "Cannot open display\n");
      exit(1);
   }
 
   	s = DefaultScreen(d);
	
	{
		screen_width = DisplayWidth(d, s);
		screen_height = DisplayHeight(d, s);
		white_pixel = WhitePixel(d, s);
		black_pixel = BlackPixel(d, s);
		printf("width = %d, height = %d, white_pixel = %ld, black_pixel = %ld\n",
			screen_width, screen_height, white_pixel, black_pixel);
	}

	w = XCreateSimpleWindow(d, RootWindow(d, s), 
								0, 0, screen_width, screen_height, 2,
                           		black_pixel, white_pixel);
   	XSelectInput(d, w, ExposureMask | KeyPressMask);
   	XMapWindow(d, w);
 
	while (1) {
		XNextEvent(d, &e);
      	if (e.type == Expose) {
        	XFillRectangle(d, w, DefaultGC(d, s), 0, 0, 100, 100);
			XDrawString(d, w, DefaultGC(d, s), 120, 50, msg, strlen(msg));
      	}
      	if (e.type == KeyPress)
         	break;
   	}
 
   XCloseDisplay(d);
   return 0;
}
