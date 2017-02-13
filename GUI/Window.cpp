#include <stdio.h>

#include "Window.h"

Window::Window(){
    this->pos = Vec2(0, 0);
    this->size = Vec2(100, 100);
    this->setBGColor(1.0, 1.0, 1.0);
}

Window::render() {

}

Window::setSize(int x, int y) {
    if (x < 0 || y < 0) {
        printf("Window coordinates %d, %d can't be negative.\n", x, y);
        return;
    }
}
