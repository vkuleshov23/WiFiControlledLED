#ifndef _PIN_CONSTS_
#define _PIN_CONSTS_
    const int redLED = D3; //D3
    const int greenLED = D1; //D1
    const int blueLED = D2; //D2

    const int buttonPin = D4; //D4

    const int MAX = 255;

    void write(int r, int g, int b) { 
        analogWrite(redLED, MAX - r);
        analogWrite(greenLED, MAX - g);
        analogWrite(blueLED, MAX - b);
    }

    void setGREEN() {
        write(MAX, 0, 0);
    }

    void setRED() {
        write(0, MAX, 0);
    }

    void setBLUE() {
        write(0, 0, MAX);
    }

    void setPURPLE() {
        write(0, MAX, MAX);
    }

    void setYELLOW() {
        write(MAX, MAX, 0);
    }

    void setAQUA() {
        write(MAX, 0, MAX);
    }

    void setFrogFaints() {
        write(0x91, 0x7b, 0x7b);
    }

    void setVeryDeepPurpleRed() {
        write(0x00, 0xd7, 0x27);
    }

#endif