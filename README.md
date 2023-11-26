# X11 simple paint app

This C program is a simple graphical application using the X11 library, which is a standard for creating graphical user interfaces in Unix-like operating systems. Here's a breakdown of what each part of the code does:

1.  **Include X11 Library**:
    
    This line includes the X11 library header, which provides functions and definitions for interacting with the X Window System.
    
2.  **Define `main` Function**: The `main` function is the entry point of the program.
    
3.  **Variable Declarations**:
    
    *   `Display *dpy;` - A pointer to a `Display` structure, representing the connection to the X server.
    *   `Window root, win;` - Variables to store the root window and the application's window.
    *   `GC gc;` - A 'Graphics Context' used for drawing.
    *   `XEvent ev;` - A structure to hold X events.
    *   `int x_prev, y_prev; int x_cur, y_cur;` - Variables to track the previous and current mouse coordinates.
4.  **Initialize X11 Display**:
    
    *   `dpy = XOpenDisplay(NULL);` - Opens a connection to the X server.
    *   `root = DefaultRootWindow(dpy);` - Gets the root window of the screen.
5.  **Create a Window**:
    
    *   `win = XCreateSimpleWindow(...);` - Creates a simple window with specified dimensions and background color.
    *   `XSelectInput(...);` - Selects which events the program is interested in (exposure, button presses, motion, etc.).
    *   `XMapWindow(dpy, win);` - Makes the window visible on the screen.
6.  **Create Graphics Context**:
    
    *   `gc = XCreateGC(dpy, win, 0, NULL);` - Creates a graphics context for drawing in the window.
7.  **Event Loop**:
    
    *   The `while (1)` loop is an infinite loop that continually processes events.
    *   `XNextEvent(dpy, &ev);` - Waits for the next event.
    *   The `switch` statement handles different types of events:
        *   `Expose` event: When part of the window needs to be redrawn. It sets the foreground color and fills the rectangle (the window).
        *   `ButtonPress` event: Triggered when a mouse button is pressed. Records the mouse position.
        *   `MotionNotify` event: Triggered when the mouse moves. If the left mouse button is pressed (`Button1Mask`), it draws a line from the previous to the current position.
8.  **Cleanup**:
    
    *   `XFreeGC(dpy, gc);` - Frees the graphics context.
    *   `XDestroyWindow(dpy, win);` - Destroys the window.
    *   `XCloseDisplay(dpy);` - Closes the connection to the X server.

The program effectively creates a window where you can draw with the mouse. When you move the mouse with the button pressed, it draws lines following the mouse movement.

## Other versions

Project also includes c++, java and python code.

## How to compile?
Compile/build instructions are in the source file.

## Have fun!