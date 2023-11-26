"""
sudo apt install python3-pip
pip install python-xlib
python3 app.py
"""

from Xlib import X, display

def main():
    d = display.Display()
    screen = d.screen()
    window = screen.root.create_window(
        x=0, y=0, width=640, height=480,
        border_width=0, depth=screen.root_depth,
        event_mask=(X.ExposureMask | X.ButtonPressMask | X.ButtonReleaseMask | X.PointerMotionMask),
        colormap=X.CopyFromParent
    )

    window.map()

    # Create GC with the foreground color set
    gc = window.create_gc(foreground=screen.black_pixel)

    x_prev, y_prev = None, None

    while True:
        e = d.next_event()

        if e.type == X.Expose and e.count == 0:
            window.fill_rectangle(gc, 0, 0, 640, 480)

        elif e.type == X.ButtonPress:
            x_prev, y_prev = e.event_x, e.event_y

        elif e.type == X.MotionNotify:
            x_cur, y_cur = e.event_x, e.event_y

            if x_prev is not None and y_prev is not None and e.state & X.Button1Mask:
                window.line(gc, x_prev, y_prev, x_cur, y_cur)

            x_prev, y_prev = x_cur, y_cur

if __name__ == '__main__':
    main()


