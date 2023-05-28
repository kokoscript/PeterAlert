#include <stdint.h>

#include "libmenuet.h"
#include "peter.h"

void RedrawWindow();

void main() {
    RedrawWindow();

    while (true) {
        uint32_t event = WaitForEvent();
        switch (event) {
            case 1: {
                // redraw event
                RedrawWindow();
                break;
            }

            case 3: {
                // button event
                uint32_t button = GetButtonID() >> 8;
                switch (button) {
                    case 1:
                    case 2:
                        // button 1 is the window's close button
                        // button 2 is our "ok" button
                        EndApplication();
                        break;
                }
            }
        }
    }
}

void RedrawWindow() {
    BeginRedraw();
    DrawWindow(64, 64, 128, 128, 0x00FFFFFF, "PETER ALERT", NULL);
    DefineButton(56, 102, 16, 16, 2, 0x10000000, "ok");
    PutImage(32, 32, 64, 64, peter_image);
    EndRedraw();
}
