#ifndef SCREEN_BACKEND_H
#define SCREEN_BACKEND_H

namespace Screen {
    class Backend {
    public:
        virtual int backlight() = 0;
        virtual void backlight(int backlight) = 0;
        virtual bool isWorking() = 0;
        virtual int weight() = 0;
    };
}

#endif
