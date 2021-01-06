#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <stdlib.h>
#include <stdio.h>

Display *disp;
int screen;
Window win;
GC gc;
XSizeHints sizeHints = *XAllocSizeHints();

#define WIN_WIDTH 180
#define WIN_HEIGHT 120

void init_x() {
	unsigned long black, white;

	disp = XOpenDisplay(NULL);
	if (disp == NULL) {
	    fprintf(stderr, "Cannot open display\n");
	    exit(1);
	}
   	screen = DefaultScreen(disp);

   	win = XCreateSimpleWindow(disp, DefaultRootWindow(disp), 0, 0, WIN_WIDTH, WIN_HEIGHT, 5, BlackPixel(disp, screen), WhitePixel(disp, screen));

	XSetStandardProperties(disp, win, "Peter Alert", "Peter Alert", None, NULL, 0, NULL);
	sizeHints.flags = PMinSize | PMaxSize | PSize;
	sizeHints.min_width = WIN_WIDTH;
	sizeHints.min_height = WIN_HEIGHT;
	sizeHints.max_width = WIN_WIDTH;
	sizeHints.max_height = WIN_HEIGHT;
	XSetWMNormalHints(disp, win, &sizeHints);

	XSelectInput(disp, win, ExposureMask | ButtonPress | PointerMotionMask);

    gc = XCreateGC(disp, win, 0,0);        

	XClearWindow(disp, win);
	XMapRaised(disp, win);

	Pixmap bitmap;
	unsigned int bmpWidth, bmpHeight;
	XReadBitmapFile(disp, win, "peter.xbm", &bmpWidth, &bmpHeight, &bitmap, NULL, NULL);
	const char* btnText = "Ok";
	
	// Check for window close/button events
	Atom WM_DELETE_WINDOW = XInternAtom(disp, "WM_DELETE_WINDOW", False); 
	XSetWMProtocols(disp, win, &WM_DELETE_WINDOW, 1);
	XEvent evt;
	while (true) {
		XNextEvent(disp, &evt);
		if (evt.type == MotionNotify) {
			// Redraw events (button hover)
			if ((evt.xbutton.x > 58 && evt.xbutton.x < 122) && (evt.xbutton.y > 75 && evt.xbutton.y < 99)) {
				XSetForeground(disp, gc, BlackPixel(disp, screen));
				XFillRectangle(disp, win, gc, 60, 77, 62, 22);
				XSetForeground(disp, gc, WhitePixel(disp, screen));
				XDrawString(disp, win, gc, 85, 92, btnText, strlen(btnText));
			} else {
				XSetForeground(disp, gc, WhitePixel(disp, screen));
				XFillRectangle(disp, win, gc, 60, 77, 62, 22);
				XSetForeground(disp, gc, BlackPixel(disp, screen));
				XDrawString(disp, win, gc, 85, 92, btnText, strlen(btnText));
			}
		}
		if (evt.type == Expose) {
			// Draw button
			XSetForeground(disp, gc, BlackPixel(disp, screen));
			XSetBackground(disp, gc, WhitePixel(disp, screen));
			XDrawRectangle(disp, win, gc, 58, 75, 65, 25);
			XDrawString(disp, win, gc, 85, 92, btnText, strlen(btnText));
			// draw Him
			XCopyPlane(disp, bitmap, win, gc, 0, 0, bmpWidth, bmpHeight, 74, 24, 1);
		}
		if (evt.type == ButtonPress) {
			if((evt.xbutton.x > 58 && evt.xbutton.x < 122) && (evt.xbutton.y > 75 && evt.xbutton.y < 99)) {
				break;
			}
		}
		if ((evt.type == ClientMessage) && (static_cast<unsigned int>(evt.xclient.data.l[0]) == WM_DELETE_WINDOW)) {
	    		break;
	    }
	}
}

void close_x() {
	XFreeGC(disp, gc);
	XDestroyWindow(disp, win);
	XCloseDisplay(disp);
	printf("Nyeheheh hey Lois remember that time I was on X11? Frickin' schweet.\n");
	exit(0);				
}

int main() {
	init_x();
	close_x();
	return 0;
}

