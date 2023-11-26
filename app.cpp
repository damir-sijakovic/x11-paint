/*

sudo apt update
sudo apt install g++
sudo apt install libx11-dev

g++ -o app_cpp app.cpp -lX11

*/


#include <X11/Xlib.h>

int main() {
    Display* dpy;
    Window root, win;
    GC gc;
    XEvent ev;

    int x_prev = 0, y_prev = 0;
    int x_cur, y_cur;

    dpy = XOpenDisplay(nullptr);
    root = DefaultRootWindow(dpy);

    win = XCreateSimpleWindow(dpy, root, 0, 0, 640, 480, 0, 0, WhitePixel(dpy, 0));
    XSelectInput(dpy, win, ExposureMask | ButtonPressMask | ButtonReleaseMask | PointerMotionMask);
    XMapWindow(dpy, win);

    gc = XCreateGC(dpy, win, 0, nullptr);

    while (true) {
        XNextEvent(dpy, &ev);

        switch (ev.type) {
            case Expose:
                XSetForeground(dpy, gc, WhitePixel(dpy, 0));
                XFillRectangle(dpy, win, gc, 0, 0, 640, 480);
                XSetForeground(dpy, gc, BlackPixel(dpy, 0));
                break;
            case ButtonPress:
                x_prev = ev.xbutton.x;
                y_prev = ev.xbutton.y;
                break;
            case MotionNotify:
                x_cur = ev.xmotion.x;
                y_cur = ev.xmotion.y;

                if (ev.xmotion.state & Button1Mask) {
                    XDrawLine(dpy, win, gc, x_prev, y_prev, x_cur, y_cur);
                }

                x_prev = x_cur;
                y_prev = y_cur;
                break;
        }
    }

    XFreeGC(dpy, gc);
    XDestroyWindow(dpy, win);
    XCloseDisplay(dpy);

    return 0;
}
